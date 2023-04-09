#include <iostream>
using namespace std;

template <typename T>
class Vector{
    int size,capacity;
    T* v;
    public:
    Vector()
    {
        size=0;
        capacity=1;
        v=new T[capacity];
    }
    ~Vector()
    {
        delete[] v;
    }

    T operator[](int index)
    {
        return v[index];
    }

    Vector (Vector& w)
    {
        size=w.size;
        capacity=w.capacity;
        v=new T[capacity];
        for(int i=0; i<size; i++)
            v[i]=w[i];
    }

    void insert(int index, T element)
    {
        if(size==capacity)
        {
            capacity++;
            T* temp=new T[capacity];
            for(int i=0; i<size; i++)
                temp[i]=v[i];
            delete[] v;
            v=temp;    
        }
        //inseram
            v[index]=element;
            //facem un loc nou pentru viitorul element
            size++;
    }
    void remove(int index)
    {
        for(int i=index; i<size-1; i++)
            v[i]=v[i+1];
        size--;
    }
    void sort()
    {
        for(int i=0; i<size; i++)
            for(int j=i+1; j<size-1; j++)
                if(v[i]>v[j])
                    swap(v[i],v[j]);
    }
    void sort(int (*cmp)(T,T))
    {

        for(i=0; i<size; i++)
            for(j=i+1; j<size-1; j++)
                if(cmp(v[i],v[j]) == 1)
                    swap(v[i],v[j]);
    }
    void print()
    {
        for (int i=0; i<size; i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
};
