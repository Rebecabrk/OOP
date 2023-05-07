#include<iostream>
using namespace std;

template<typename K, typename V>
struct Map
{
    struct Element {
        K key;
        V value;
        int index=0;
    };
    Element* data;
    int size,capacity;

    Map()
    {
        data = new Element[1];
        size = 0;
        capacity=1;
    }
    ~Map() 
    {
        delete[] data;
    }

    bool Get(const K& key, V& value)
    {
        for(int i=0;i<size;i++)
        {
            if(data[i].key==key)
            {
                value=data[i].value;
                return true;
            }
        }
        return false;
    }

    void Set(K x)
    {
        if(size==capacity)
        {
            capacity*=2;
            Element* datanew=new Element[capacity];
            for(int i=0;i<size;i++)
            {
                datanew[i]=data[i];
            }
            delete[] data;
            data=datanew;

        }
        data[size].key=x;
        data[size].value=0;
        if(size!=0)
        data[size].index=data[size-1].index+1;
        size++;
    }

    V& operator[](K x)
    {
        for(int i=0;i<size;i++)
        {
            if(data[i].key==x)
            {
                return data[i].value;
            }
        }
        Set(x);
        return data[size-1].value;
    }

    int Count()
    {
        return size;
    }

    void Clear()
    {
        delete[] data;
        data = new Element[1];
        size = 0;
        capacity=1;
    }

    bool Delete(const K& key)
    {
        for(int i=0;i<size;i++)
        {
            if(data[i].key==key)
            {
                for(int j=i+1;j<size;j++)
                {
                    data[j-1]=data[j];
                }
                size--;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K,V>& map)
    {
        bool ok[map->size];
        for(int i=0;i<map->size;i++)
        {
            ok[i]=0;
        }
        for(int i=0;i<map->size;i++)
        {
            for(int j=0;j<this->size;j++)
            {
                if(data[j].key==map[i].key)
                {
                    ok[i]=1;
                }
            }
        }
        for(int i=0;i<map->size;i++)
        {
            if(ok[i]==0)
                return false;
        }
        return true;
    }

    struct iterator {
        Element* ptr;

        iterator(Element* ptr) : ptr(ptr) {}
        bool operator!=(iterator i) {
            return ptr != i.ptr;
        }
        void operator++() {
            ++ptr;
        }
        Element operator*() {
            return *ptr;
        }
    };
    iterator begin() {
        return iterator(&data[0]);
    }

    iterator end() {
        return iterator(&data[size]);
    }
};

int main()
{
    Map<int, const char *> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    const char* p;
    return 0;
}