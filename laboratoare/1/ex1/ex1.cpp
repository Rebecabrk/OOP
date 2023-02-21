/*#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("in.txt");
FILE* f;
int a1,sum;
int main(){
    f=fopen("in.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%d",&a1);
        sum+=a1;
    }
    cout<<sum<<endl;
    fclose(f);
    return 0;
}*/

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("in.txt");
FILE* f;
char str[10];
int nr,sum,last,curent;
int convert(char *string, int last, int curent)
{
    int number=0;
    if(curent==last)
        for(int i=0; i<strlen(string); i++)
            number=number*10+(string[i]-48);
    else
        for(int i=0; i<strlen(string)-1; i++)
            number=number*10+(string[i]-48);
    return number;
}
int main()
{
    f=fopen("in.txt","r");
    while (!feof(f))
    {
        fgets(str,9,f);
        last++;
    }
    fclose(f);
    f=fopen("in.txt","r");
    while (!feof(f))
    {
        fgets(str,9,f);
        curent++;
        nr=convert(str,last,curent);
        sum+=nr;
    }
    cout<<sum;
    fclose(f);
    return 0;
}