#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<string> dates = {"01-Jan-2020",
                            "04-Mar-2020",
                            "09-Feb-1999",
                            "07-Apr-2008",
                            "17-Oct-2001",
                            "05-Jan-2020"};
    vector<vector<string>> datestring;
    vector<string> d;
    for(auto s: dates){
        string word;
        stringstream ss {s};
        while(getline(ss,word,'-'))
            d.push_back(word);
        datestring.push_back(d);
        d.clear();
    }
    for(auto i:datestring)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    map<string,int> months;
    months["Jan"] = 1;
    months["Feb"] = 2;
    months["Mar"] = 3;
    months["Apr"] = 4;
    months["May"] = 5;
    months["Jun"] = 6;
    months["Jul"] = 7;
    months["Aug"] = 8;
    months["Sep"] = 9;
    months["Oct"] = 10;
    months["Nov"] = 11;
    months["Dec"] = 12;
    
    sort(datestring.begin(),datestring.end(),[](vector<string> d1, vector<string> d2){
            map<string,int> months;
    months["Jan"] = 1;
    months["Feb"] = 2;
    months["Mar"] = 3;
    months["Apr"] = 4;
    months["May"] = 5;
    months["Jun"] = 6;
    months["Jul"] = 7;
    months["Aug"] = 8;
    months["Sep"] = 9;
    months["Oct"] = 10;
    months["Nov"] = 11;
    months["Dec"] = 12;
        if( stoi(d1[2]) < stoi(d2[2]) )
            return true;
        else if(stoi(d1[2]) == stoi(d2[2]) && months[d1[1]] < months[d2[1]])
            return true;
        else if(stoi(d1[2]) == stoi(d2[2]) && months[d1[1]] == months[d2[1]] &&  stoi(d1[0]) < stoi(d2[0]))
            return true;
        return false;
    });
    for(auto i:datestring)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}