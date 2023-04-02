#include <iostream>
#include "Circuit.h"
#include "Car.h"
#include "Weather.h"
using namespace std;

Circuit::Circuit()
{
    cars= new Car* [10];
    times= new float[10];
    ithCar=0;
    weather=Weather::Sunny;
}
Circuit::~Circuit()
{
    if (cars!=nullptr)
    delete[] cars;
    if(times!=nullptr)
    delete[] times;
}

void Circuit::SetLength(int x)
{
    this->length=x;
}
void Circuit::SetWeather(Weather x)
{
    this->weather=x;
}
void Circuit::AddCar(Car* car)
{
    cars[ithCar]= car;
    ithCar++;
}
void Circuit::SortTimes()
{
    for (int i=0; i< ithCar-1; i++)
        for(int j=i+1; j< ithCar; j++)
            if(times[i]>times[j]){
                swap(times[i],times[j]);
                swap(cars[i],cars[j]);
            }
}
void Circuit::Race()
{
    int totalFuel,consumption,speed,numberOfWinners=0;
    //who won?
    for (int i=0; i<ithCar; i++)
        {
            totalFuel=cars[i]->GetTotalFuel();
            consumption=cars[i]->GetFuelConsumption();
            if(totalFuel-(consumption*this->length)>=0)
                {
                    speed=cars[i]->GetSpeed(weather);
                    times[i]=this->length/speed;
                }
            else 
                {
                    times[i]=-1;
                }
        }
        SortTimes();
        for(int i=0;i<ithCar;i++)
            if(times[i]!=-1)
            {
                numberOfWinners=1;
                for(int j=i+1;j<ithCar;j++)
                    if(times[j]==times[i])
                        numberOfWinners++;
                    else break;
                if(numberOfWinners==1)
                    {
                        cout<<"Exista un singur castigator!"<<endl;
                        cout<<cars[i]->nume()<<endl;
                        break;
                    }
                else {
                    //sunt numberOfWinners castigatori
                    for (int k=i; k<=i+numberOfWinners-1; k++)
                    {
                        cout<<"Exista mai multi castigatori!"<<endl;
                        cout<<cars[k]->nume()<<endl;
                        break;
                    }
                } 
            }
        if(numberOfWinners==0)
        {
            cout<<"Nu exista castigatori!"<<endl;
        }   
}
void Circuit::ShowFinalRanks()
{
    int loc=1;
    cout<<"RANKS:"<<endl;
    for(int i=0;i<ithCar;i++)
        if(times[i]!=-1)
            {
                cout<<loc<<"-> "<<cars[i]->nume()<<" a terminat in: "<<times[i]<<" milisecunde."<<endl;
                loc++;
            }
}
void Circuit::ShowWhoDidNotFinish()
{
    int a=0;
    if(ithCar==0)
        cout<<"There is no car in the race!"<<endl;
    else
    {
    cout<<"The following cars did not finish the race:"<<endl;
    for(int i=0;i<ithCar;i++)
        if(times[i]==-1)
        {
            cout<<cars[i]->nume()<<endl;
            a++;
        }
        else break;
    }
    if(a==0) cout<<"All the cars finished the race!"<<endl;
}
void Circuit::PrintLenght()
{
    printf("This circuit's length is %d\n",this->length);
}
void Circuit::PrintWeather()
{
    printf("Today's weather is %d\n",this->weather);
}

