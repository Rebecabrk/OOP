#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

struct alfabetic{
    char word[100];
    int lenght;
};

char str[255],*p;
int i;
int main()
{
    alfabetic sentence[50];
    printf("Type a sentence: ");
    scanf("%[^\n]s",str);
    p=strtok(str," ");
    while(p)
    {
        i++;
        strcpy(sentence[i].word,p);
        sentence[i].lenght=strlen(p);
        p=strtok(NULL," ");
    }
    for(int j=1;j<=i;j++)
        for(int k=j+1;k<i;k++)
        if(sentence[k].lenght<sentence[j].lenght)
            swap(sentence[k],sentence[j]);
    for(;i>0;i--)
        printf("%s\n",sentence[i].word);
    return 0;
}