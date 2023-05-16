#include "tester.cpp"
#include "MyVector.cpp"
#include<iostream>
using namespace std;

int main() {
    Tester t;

    t.add([]() {
        MyVector<int> x;
        x.add(5);
        return x[0] == 5;
    }, "Insert test");

    t.add(
        []() {
            MyVector<int> x;
            x.add(5);
            x.add(10);
            x.remove(0);

            return x[0] == 10;
        },
        "Remove test");

    t.add(
        []() {
            MyVector<int> x;

            for (int i = 0; i < 5; ++i) {
                x.add(i);
            }

            return x.Size() == 5;
        },
        "Size test");

    t.add(
        []() {
            MyVector<int> x;
            MyVector<int> y;

            for (int i = 0; i < 5; ++i) {
                x.add(i);
                y.add(i);
            }
            return x == y;
        },
        "Equal test");

    t.add(
        []() {
            MyVector<int> x;
            x.add(4);
            x.add(2);
            x.add(3);
            x.add(0);
            x.add(1);

            x.sort();

            for (int i = 0; i < 5; ++i) {
                if (x[i] != i) {
                    return false;
                }
            }

            return true;
        },
        "Sort test");

    t.add([]() -> bool { throw std::runtime_error("Fail"); }, "Fail on purpose");

    t.run();
}
