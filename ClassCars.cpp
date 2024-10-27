#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>

using namespace std;

class Car
{
	private:
		int speed;
		char mark[20];
		float price;
	public:
		void setSpeed(int);
		int getSpeed();
		void setMark(char[]);
		char getMark();
		void setPrice(float);
		float getPrice();
		Car(int iSpeed=0, char iMark[]="", float iPrice=0);
		void show();
};

Car::Car(int iSpeed, char iMark[], float iPrice)
{
	speed = iSpeed;
	strcpy(mark, iMark);
	price = iPrice;
}

void Car::setSpeed(int iSpeed)
{
	speed = iSpeed;
}
int Car::getSpeed()
{
	return speed;
}

void Car::setMark(char iMark[])
{
	strcpy(mark, iMark);
}
char Car::getMark()
{
	return *mark;
}

void Car::setPrice(float iPrice)
{
	price = iPrice;
}
float Car::getPrice()
{
	return price;
}

void Car::show()
{
	cout<<"Car with speed "<<speed<<" mark "<<mark<<" and price "<<price<<endl;
}
int main()
{
	Car mycar;
	Car mycars();
	int index=0, length;
	float maxprice=0;
	cout<<"Enter length of class Car: ";
	cin>>length;
	Car *cars;
	cars = new Car[length];
	for(int i=0;i<length;i++)
	{
		int speed;
		char mark[20];
		float price;
		cout<<"Car "<<i+1<<" with speed: ";
		cin>>speed;
		cars[i].setSpeed(speed);
		cout<<" mark: ";
		cin>>mark;
		cars[i].setMark(mark);
		cout<<" price: ";
		cin>>price;
		cars[i].setPrice(price);
		
		if(maxprice<price)
		{
			maxprice = price;
			index = i;
		}
	}
	for(int i=0;i<length;i++)
	{
		if(i==index)
		cars[i].show();
	}
	delete [] cars;
	return 0;
}