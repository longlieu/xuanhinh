#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;

class Car;

class Person
{
	private:
		char name[20];
		int age;
	public:
		void init(char[], int);
		int permission(Car);
};

class Car
{
	private:
		int speed;
		char mark[20];
		float price;
	public:
		void init(int ,char[], float);
		friend int Person::permission(Car);
};

void Person::init(char iName[], int iAge)
{
	strcpy(name,iName);
	age = iAge;
	return;
}

void Car::init(int iSpeed, char iMark[], float iPrice)
{
	speed = iSpeed;
	strcpy(mark, iMark);
	price = iPrice;
}

int Person::permission(Car car)
{
	if(age<18)
		return 0;
	if(age<21&&car.speed>150)
		return 0;
	return 1;
}

int main()
{
	Car car;
	Person person;
	car.init(100, "Ford", 3000);
	person.init("Vinh", 20);
	
	if(person.permission(car))
		cout<<"Co quyen dieu khien xe\n";
	else
		cout<<"Khong co quyen dieu khien xe\n";
	return 0;
}