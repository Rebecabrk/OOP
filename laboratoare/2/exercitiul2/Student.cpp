#include "Student.h"
#include <cstring>
using namespace std;

void Student::setName(char newName[])
{
    strcpy(Nume,newName);
}
char* Student::getName()
{
    return Nume;
}
void Student::setGradeMath(int grade)
{
    notaMath=grade;
}
float Student::getGradeMath()
{
    return notaMath;
}
void Student::setGradeEng(int grade)
{
    notaEng=grade;
}
float Student::getGradeEng()
{
    return notaEng;
}
void Student::setGradeHistory(int grade)
{
    notaHistory=grade;
}
float Student::getGradeHistory()
{
    return notaHistory;
}
float Student::averageGrade()
{
    return (notaMath+notaEng+notaHistory)/3;
}