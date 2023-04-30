#include<iostream>
#include<map>
#include<queue>
#include<fstream>
using namespace std;
ifstream fin("Phrase.txt");

struct A{   
    string cuvant;
    int nr;
};

struct Comparer{
    bool operator()(A left, A right)
    {
        if(left.nr < right.nr)
            return 1;
        if(left.nr > right.nr)
            return 0;
        int i=0,ascii1,ascii2;
        while(i<left.cuvant.length() && i<right.cuvant.length())
        {
            ascii1=left.cuvant[i];
            ascii2=right.cuvant[i];
            if(ascii1 < ascii2)
                return 0;
            if(ascii1 > ascii2)
                return 1;
            if(ascii1 == ascii2)
                i++;
        }
        if(left.cuvant.length() < right.cuvant.length()) return 1;
        if(left.cuvant.length() > right.cuvant.length()) return 0;
    }
};

void Print(priority_queue<A, vector<A>, Comparer> x)
{
    while(!x.empty())
    {
        cout<<x.top().cuvant<<" => "<<x.top().nr<<endl;
        x.pop();
    }
}

int main()
{
    string s,word;
    map<string, int> m;
    getline(fin,s);
    for(int i=0; i<s.length();i++)
    {
        int ascii=s[i];
        if(ascii>=65 && ascii<=90)
        s[i]=tolower(s[i]);
    }
    int index1,index2;
    index1=0;
    while(true)
    {
        index2=s.find_first_of(" ,?!.",index1);
        if(index2-index1!=0 && index2!=-1)
        {
            word=s.substr(index1,index2-index1);
            m[word]++;
        }
        index1=index2+1;
        if(index2==string::npos) break; 
    }
   priority_queue<A, vector<A>, Comparer> q;
   for(auto& [key, value] : m)
    {
        A variabila;
        variabila.cuvant=key;
        variabila.nr=value;
        q.push(variabila);
    }
    Print(q);
}