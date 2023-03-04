#pragma once 
class Student{
public:
    char Nume[256];
    float notaMath,notaEng,notaHistory;
    void setName(char string[]);
    char* getName();
    void setGradeMath(int grade);
    float getGradeMath();
    void setGradeEng(int grade);
    float getGradeEng();
    void setGradeHistory(int grade);
    float getGradeHistory();
    float averageGrade();
};