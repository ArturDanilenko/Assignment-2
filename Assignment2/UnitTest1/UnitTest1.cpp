#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include<iostream>
#include "C:/Users/danar/Desktop/UBC/CPEN_333/Assignment 2/Assignment2/Assignment2/ass2.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Tires tires(49, "yui", 1, 1);
			Oil oil("GOOD", 8);
			Invoice invoice(1);
			ServiceRecords records("123");
			Car car(tires, oil, 1, 1);
			Customer cust(car, invoice, records);

			Receptionist bob;
			jobSheet sheet;
			bob.car = car;
			bob.invoice = invoice;
			bob.records = records;
			bob.sheet = sheet;
			Assert::AreEqual(bob.car.oil.type, (string)"GOOD");

			

			//cout << "Customer Pays\n";
			//cout << "Service starts\n";

			Technician tech;
			car = tech.ServiceCar(car);

			Assert::AreEqual(car.oil.type, (string)"Extra Good");
			//cout << "DONE FOR ALL\n";
		}
	};
}
