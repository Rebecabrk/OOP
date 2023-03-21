class Sort
{
    int *vector, min, max, size;
public:
    Sort(int number, int minimum, int maximum);
    //Sort(std::initializer_list<int> list);
    Sort(int *Vector, int size);
    Sort(int number, ...);
    Sort(char *string);
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
    ~Sort();
};