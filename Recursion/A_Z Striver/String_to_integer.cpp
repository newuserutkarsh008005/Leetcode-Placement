#include <iostream>
using namespace std;
int strtoat(string s){
    int i=0;
    int n=s.size()-1;
    while(i<=n && s[i]== ' '){
        i++;
    }
    int sign =1;
    while(i<=n && (s[i]=='+' || s[i]=='-')){
        if(s[i]=='-'){
            sign*=-1;
        }
        i++;
    }
    long long ans=0;
    while(i<=n && isdigit(s[i])){
        ans*=10;
        ans+=s[i]-'0';
        i++;
        if(ans>=INT32_MAX) return INT32_MAX;
        if(ans<=INT32_MIN) return INT32_MIN;
    }
    return ans*sign;


}
int main(){
    string s;
    cin>>s;
    int n=strtoat(s);
    cout<<n;
    return 0;
}