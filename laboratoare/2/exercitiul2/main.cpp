#include "Student.h"
#include "global.h"
#include <iostream>
using namespace std;

int main()
{
    Student X1,X2;
    char x1nume[100],x2nume[100];
    strcpy(x1nume,"rebeca");
    strcpy(x2nume,"hannah");
    X1.setName(x1nume);
    X2.setName(x2nume);
    cout<<X1.getName()<<endl;
    cout<<X2.getName()<<endl;
    X1.setGradeMath(10);
    X2.setGradeMath(9);
    cout<<X1.getGradeMath()<<endl;
    cout<<X2.getGradeMath()<<endl;
    X1.setGradeEng(10);
    X2.setGradeEng(8);
    cout<<X1.getGradeEng()<<endl;
    cout<<X2.getGradeEng()<<endl;
    X1.setGradeHistory(7);
    X2.setGradeHistory(8);
    cout<<X1.getGradeHistory()<<endl;
    cout<<X2.getGradeHistory()<<endl;
    cout<<X1.averageGrade()<<endl;
    cout<<X2.averageGrade()<<endl;
    cout<<compareName(X1.Nume,X2.Nume)<<endl;
    cout<<compareGrade(X1.notaMath, X2.notaMath)<<endl;
    cout<<compareAverage(X2.averageGrade(),X2.averageGrade())<<endl;
    return 0;
}