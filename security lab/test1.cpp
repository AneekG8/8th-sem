#include<bits/stdc++.h>
using namespace std;

void add(set<string>& words,string word)
{
    words.insert(word);
}

int count(set<string> words,string partialWord)
{
    int c = 0;

    for(auto word : words)
    {
        string part = word.substr(0,partialWord.size());

        if(part == partialWord)
            c++;

        else if (part > partialWord)
            break;
    }

    return c;
}


int main()
{
    int t;
    
    cin>>t;

    set<string> dict;

    while(t--)
    {
        string command;
        cin>>command;

        string word;
        cin>>word;

        if(command == "add")
            add(dict,word);

        else
        {
            int c = count(dict,word);
            cout<<c<<endl;
        }
    }
}