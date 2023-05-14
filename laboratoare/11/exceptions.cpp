#include "exceptions.h"

template <typename T>
Array<T>::~Array()
{
    delete[] List;
}
template <typename T>
Array<T>::Array()
{
    List=nullptr;
    Size=0;
    Capacity=1;
}
template <typename T>
Array<T>::Array(int capacity)
{
    try{
        if(capacity<0)
            throw "capacity must be a positive number";
    } catch(const char * c)
    {
        printf("exception: capacity must be a positive number");
    }
    Size=0;
    Capacity=capacity;
    List= new T [Capacity];
}
template<typename T>
Array<T>::Array(const Array<T> &otherArray)
{
    otherArray.Size=Size;
    otherArray.Capacity=Capacity;
    for(int i=0;i<this->Size;i++)
    {
        otherArray.List[i]=List[i];
    }
}
template<typename T>
T& Array<T>::operator[](int index)
{
    try
    {
        if(index>Size || index<0)
            throw "index out of range";
    }
    catch(const char* c)
    {
        printf("exception: index of of range");
    }
    return List[index];
}
template<typename T>
const Array<T>& Array<T>::operator+=(const T &newElem)
{
    Size++;
    if(Size==Capacity)
        {
            Capacity*=2;
            T** newList=new T* [Capacity];
            for(int i=0;i<Size-1;i++)
            {
                newList[i]=List[i];
            }
            delete[] List;
            List=newList;
        }
    List[Size]=newElem;
    return (*this);
}
template<typename T>
const Array<T>& Array<T>::Insert(int index, const T &newElem)
{
    try
    {
        if(index>Size || index<0)
            throw "index out of range";
    }
    catch(const char* c)
    {
        printf("exception: index of of range");
    }
    Size++;
    if(Size==Capacity)
        {
            Capacity*=2;
            T** newList=new T* [Capacity];
            for(int i=0;i<Size-1;i++)
            {
                newList[i]=List[i];
            }
            delete[] List;
            List=newList;
        }
    List[Size]=newElem;
    return (*this);
}
template<typename T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{   try
    {
        if(index>Size || index<0)
            throw "index out of range";
    }
    catch(const char* c)
    {
        printf("exception: index of of range");
    }
    for(int i=0;i<otherArray.Size;i++)
    {
        Size++;
        if(Size==Capacity)
        {
            Capacity*=2;
            T** newList=new T* [Capacity];
            for(int i=0;i<Size-1;i++)
            {
                newList[i]=List[i];
            }
            delete[] List;
            List=newList;
        }
        List[Size]=otherArray.List[i];
    }
    return (*this);
}
template<typename T>
const Array<T>& Array<T>::Delete(int index)
{
    try
    {
        if(index>Size || index<0)
            throw "index out of range";
    }
    catch(const char* c)
    {
        printf("exception: index of of range");
    }
    for(int i=index;i<Size-1;i++)
    {
        List[i]=List[i+1];
    }
    return (*this);
}

template<typename T>
bool Array<T>::operator=(const Array<T> &otherArray)
{
    if(Size!=otherArray.Size)
        return 0;
    for(int i=0;i<Size;i++)
    {
        if(List[i]!=otherArray.List[i])
            return 0;
    }
    return 1;
}
template<typename T>
//daca T este int
void Array<T>::Sort()
{
    for(int i=0;i<Size-1;i++)
        for(int j=i+1;j<Size;j++)
            if(List[i]>List[j])
                swap(List[i],List[j]);
}

int CompareInts(int x, int y)
{
    if(x<y)
        return 1;
    if(x==y)
        return 0;
    return -1;
}
template<typename T>
void Array<T>::Sort(int(*compare)(const T&, const T&))
{
    for(int i=0;i<Size-1;i++)
        for(int j=i+1;j<Size;j++)
            if(compare(List[i],List[j])<0)
                swap(List[i],List[j]);
}
template<typename T>
int Array<T>::CompareElements(void* e1, void* e2)
{
    if(e1<e2)
        return 1;
    if(e1==e2)
        return 0;
    return -1;
}

template<typename T>
void Array<T>::Sort(Compare *comparator)
{
    for(int i=0;i<Size-1;i++)
        for(int j=i+1;j<Size;j++)
            if(comparator(List[i],List[j])<0)
                swap(List[i],List[j]);
}
template<typename T>
int Array<T>::Find(const T& elem)
{
    for(int i=0;i<Size;i++)
    {
        if(List[i]==elem)
            return i;
    }
    return -1;
}
template<typename T>
int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&))
{
    for(int i=0;i<Size;i++)
    {
        if(compare(List[i],elem)==0)
            return i;
    }
    return -1;
}

template<typename T>
int Array<T>::Find(const T& elem, Compare *comparator)
{
    for(int i=0;i<Size;i++)
    {
        if(comparator(List[i],elem)==0)
            return i;
    }
    return -1;
}

template<typename T>
int Array<T>::GetSize()
{
    return Size;
} 
template<typename T>
int Array<T>::GetCapacity()
{
    return Capacity;
}
template<typename T>
int Array<T>::BinarySearch(const T& x)
{
    Sort();
    T low=List[0];
    T high=List[Size];
    while (low <= high) {
    int mid = low + (high - low) / 2;
    if (List[mid] == x)
      return mid;
    if (List[mid] < x)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
template<typename T>
int Array<T>::BinarySearch(const T& x, int(*compare)(const T&, const T&))
{
    Sort();
    T low=List[0];
    T high=List[Size];
    while (low <= high) {
    int mid = low + (high - low) / 2;
    if (compare(List[mid],x)==0)
      return mid;
    if (compare(List[mid],x)==1)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
template<typename T>
int Array<T>::BinarySearch(const T& x, Compare *comparator)
{
    Sort();
    T low=List[0];
    T high=List[Size];
    while (low <= high) {
    int mid = low + (high - low) / 2;
    if (comparator(List[mid],x)==0)
      return mid;
    if (comparator(List[mid],x)==1)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

template<typename T>
ArrayIterator<T>& ArrayIterator<T>::operator++()
{
    Current++;
    return ++ptr;
}
template<typename T>
ArrayIterator<T>& ArrayIterator<T>::operator--()
{
    Current--;
    return --ptr;
}
template<typename T>
bool ArrayIterator<T>::operator= (ArrayIterator<T> & x)
{
    return ptr==x.ptr;
}
template<typename T>
bool ArrayIterator<T>::operator!= (ArrayIterator<T> & x)
{
    return ptr!=x.ptr;
}
template<typename T>
T* ArrayIterator<T>::GetElement()
{
    return *ptr[Current];
}