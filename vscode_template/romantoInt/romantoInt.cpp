#include<iostream>
#include<math.h>
#include<string>
#include<assert.h>


using namespace std;class Solution {
public:
    int romanToInt(string s) {
        int data[256]={0};
        int sum=0;
        int length=s.size();
        if(length<1)
            return 0;
        else if(length==1)
            return s[0];
        
        data['I']=1;data['V']=5;data['X']=10;data['L']=50;data['C']=100;data['D']=500;data['M']=1000;
        int i=0;
        for(;i<length-1;i++){
            cout<<i<<" times :"<<endl;
            cout<<"         data"<<"["<<s[i]<<"="<<data[s[i]]<<endl;
            cout<<"         data"<<"["<<s[i+1]<<"="<<data[s[i]]<<endl;
            if(data[s[i]]<data[s[i+1]]){
                sum-=data[s[i]];
            }
           sum+=data[s[i]];
        }
        return sum+data[s[i]];
            
        }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        //string s = stringToString(line);
        
        int ret = Solution().romanToInt(line);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}