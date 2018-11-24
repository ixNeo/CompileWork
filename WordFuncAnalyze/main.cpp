#include <iostream>
#include <vector>
#include <map>
using namespace std;

/* 词法分析器
 * in: string
 * out: list of words and its frequency
*/

// 结果数据结构： map
map<string,int> res;

// 状态转换矩阵
int nextState[3][3] = {{0,1,2}
                  ,{1,1,2}
                  ,{2,2,2}};

// 得到某个正则表达式的动作编号，便于矩阵求值
int getId(char c){
    if((c<='Z' && c>='A')
            || (c<='z' && c>='a')){
        return 1;
    }else{
        return 2;
    }
}

// 执行函数，执行某一状态下对应的操作；一般为返回值给语法分析器
string func(int curState,string curStr,char c){
    if(curState==1){
        curStr += c;
        return curStr;
    }else{
        return curStr;
    }
}

// out
void showMap(map<string,int> mapIns){
    for(auto it=mapIns.begin();it!=mapIns.end();it++){
        cout << it->first << ": " << it->second << endl;
    }
}
int main()
{
    string str;
    cout << "please input a stirng: " << endl;
    getline(cin,str);

    // resp表示动作对应的编号
    int i =0,state,resp;
    char c;
    int len = str.size();
    string curStr;
    while(i<len){
        state = 0; curStr="";
        while(state!=2 && (c=str[i++])){
            resp = getId(c);
            state = nextState[state][resp];
            curStr = func(state,curStr,c);
        }
        if(curStr!=""){
            if(res.count(curStr)){
                res[curStr]++;
            }else{
                res[curStr] = 1;
            }

        }
    }
    cout << "***********\nbelow are results:" << endl;
    showMap(res);
    return 0;
}
