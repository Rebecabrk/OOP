#include<iostream>
using namespace std;

template <typename T>
class MyVector
{
    T* vector;
    int size,capacity;
    public:
    MyVector();
    ~MyVector();
    void add(const T& elem);
    void remove(T index);
    int Size();
    T& operator[](int index);
    bool operator==(MyVector<T>& otherVect);
    void sort();
};

template<typename T>
MyVector<T>::MyVector()
{
    capacity=1;
    vector=new T [capacity];
    size=0;
}
template<typename T>
MyVector<T>::~MyVector()
{
    delete[] vector;
}
template<typename T>
void MyVector<T>::add(const T& elem)
{
    if(size>=capacity)
    {
        capacity*=2;
        T* nou= new T[capacity];
        for(int i=0; i<this->size; i++)
            nou[i]=vector[i];
        delete[] vector;
        vector=nou;
    }
    vector[size++]=elem;
}
template<typename T>
void MyVector<T>::remove(T index)
{
    try
    {
        if(index>size || index<0)
            throw "index out of range";
    }
    catch(const char* c)
    {
        printf("exception: index of of range");
    }
    for(int i=index;i<size-1;i++)
    {
        vector[i]=vector[i+1];
    }
}
template<typename T>
int MyVector<T>::Size()
{
    return size;
}

template<typename T>
T& MyVector<T>::operator[](int index)
{
    try
    {
        if(index>size || index<0)
            throw "index out of range";
    }
    catch(const char* c)
    {
        printf("exception: index of of range");
    }
    return vector[index];
}
template<typename T>
bool MyVector<T>::operator==(MyVector<T>& otherVect)
{
    if(size!=otherVect.size)
        return 0;
    for(int i=0;i<size;i++)
    {
        if(vector[i]!=otherVect.vector[i])
            return 0;
    }
    return 1;
}
template<typename T>
void MyVector<T>::sort()
{
    for(int i=0;i<size-1;i++)
        for(int j=i+1;j<size;j++)
            if(vector[i]>vector[j])
                swap(vector[i],vector[j]);
}
