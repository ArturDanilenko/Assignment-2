#include<iostream>
#include<string>

using namespace std;
struct Item {
	int partNumber;
	int quantity;
	int cost;
public:
	Item(int a, int b, int c) {
		partNumber = a;
		quantity = b;
		cost = c;
	}
	Item() {
		partNumber = 0;
		quantity = 0;
		cost = 0;
	}
};
struct labourItem {
	int object;
	int cost;
public:
	labourItem(int a, int b) {
		object = a;
		cost = b;
	}
	labourItem() {
		object = 0;
		cost = 0;
	}
};
struct Tires {
	int condition;
	string make;
	int size;
	int quantity;
public:
	Tires(int a, string b, int c, int d) {
		condition = a;
		make = b;
		size = c;
		quantity = d;
	}
	Tires() {
		condition = 100;
		make = "REG";
		size = 10;
		quantity = 4;
	}
};
struct Oil {
	string type;
	int quantity;
public:
	Oil(string a, int b) {
		type = a;
		quantity = b;
	}
	Oil() {
		type = "EXTRAGOOD";
		quantity = 0;
	}
};
struct Car {
	Tires tires;
	Oil oil;
	bool oilfilter;
	bool airfilter;
	int regNum;
public:
	Car(Tires param1, Oil param2, bool a, bool b){
		tires = param1;
		oil = param2;
		oilfilter = a;
		airfilter = b;
	}
	Car() {
		tires = Tires();
		oil = Oil();
		oilfilter = 0;
		airfilter = 0;
		regNum = 0;
	}
};
struct Invoice {
	int number;
public:
	Invoice(int a) {
		number = a;
	}
	Invoice() {
		number = 0;
	}
};
struct ServiceRecords {
	string info;
public:
	ServiceRecords(string a){
		info = a;
	}
	ServiceRecords() {
		info = "QWERTYUIOP";
	}
};
class Customer {
	Car car;
	Invoice invoice;
	ServiceRecords records;
public:
	Customer(Car a, Invoice b, ServiceRecords c) {
		car = a;
		invoice = b;
		records = c;
	}
};
class jobSheet {
	Item items[30];
	labourItem labouritems[30];
	int itemscounter;
	int litemscounter;
public:
	jobSheet() {
		itemscounter = 0;
		litemscounter = 0;
	}
	void addItem(Item item) {
		items[itemscounter] = item;
		itemscounter++;
	}
	void addItem(labourItem item) {
		labouritems[litemscounter] = item;
		litemscounter++;
	}
};
class Receptionist {
public:
	Car car;
	jobSheet sheet;
	ServiceRecords records;
	Invoice invoice;
};
class stores {
public:
	Oil getNewOil(string a, int b) {
		return Oil(a, b);
	}
	bool getNewOilFilter() {
		return 1;
	}
	bool getNewAirFilter() {
		return 1;
	}
	Tires getNewTires(string make, int size, int quantity) {
		return Tires(100, make, size, quantity);
	}
};
class Garbage {
public:
	bool disposeOilFilter(bool oilfilter) {
		oilfilter = 0;
		return oilfilter;
	}
	bool disposeAirFilter(bool airfilter) {
		airfilter = 0;
		return airfilter;
	}
};
class Recycling {
public:
	Oil recycleOil(Oil oil) {
		oil.quantity = 0;
		return oil;
	}
	Tires recycleTires(Tires tires) {
		tires.quantity = 0;
		return tires;
	}
};
class Technician {
	Oil oldoil;
	Oil newoil;
	bool oilfilter;
	bool airfilter;
	Tires oldtires;
	Tires newtires;
	jobSheet sheet;
	stores store;
	Car car;
	Recycling recycle;
	Garbage trash;
	Item item;
	labourItem litem;
public:
	Technician() {
		return;
	}
	void getOldOil() {
		oldoil = car.oil;
		return;
	}
	void getOldOilFilter() {
		oilfilter = car.oilfilter;
		return;
	}
	void getOldAirFilter() {
		airfilter = car.airfilter;
		return;
	}
	void getOldTires() {
		oldtires = car.tires;
		return;
	}
	void getOil(string type, int quantity) {
		newoil = store.getNewOil(type, quantity);
		return;
	}
	void getAirFilter() {
		airfilter = store.getNewAirFilter();
		return;
	}
	void getOilFilter() {
		oilfilter = store.getNewOilFilter();
		return;
	}
	void getTires(string make, int size, int quantity) {
		newtires = store.getNewTires(make, size, quantity);
	}
	Car ServiceCar(Car car) {

		getOil("Extra Good", 100);
		item.cost = 777;
		item.partNumber = 1;
		item.quantity = 1;
		sheet.addItem(item);
		cout << "Got new oil\n";

		getAirFilter();
		item.partNumber = 2;
		item.quantity = 1;
		sheet.addItem(item);
		cout << "Got new Airfilter\n";

		getOilFilter();
		item.partNumber = 3;
		item.quantity = 1;
		sheet.addItem(item);
		car.oil = newoil;
		cout << "Got new oil filter\n";

		getOldOil();
		oldoil = recycle.recycleOil(oldoil);
		litem.cost = 20;
		litem.object = 6;
		sheet.addItem(litem);
		cout << "Recycled old oil\n";

		getOldAirFilter();
		trash.disposeAirFilter(airfilter);
		litem.cost = 10;
		litem.object = 1;
		sheet.addItem(litem);
		car.airfilter = airfilter;
		cout << "recycled old airfilter\n";
		
		getOldOilFilter();
		trash.disposeOilFilter(oilfilter);
		litem.cost = 1;
		litem.object = 4;
		sheet.addItem(litem);
		car.oilfilter = oilfilter;
		cout << "recycled old oilfilter\n";

		if (car.tires.condition < 50) {
			getTires("qwert", 7, 4);
			item.partNumber = 5;
			item.quantity = 4;
			sheet.addItem(item);

			getOldTires();
			oldtires = recycle.recycleTires(oldtires);
			litem.cost = 7;
			litem.object = 3;
			sheet.addItem(litem);

			cout << "Replaced tires\n";
		}
		else {
			cout << "Rotating tires lmao\n";
			litem.cost = 1;
			litem.object = 1;
			sheet.addItem(litem);
		}
		cout << "DONE\n";
		return car;
	}
};


int main() {
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

	cout << "Customer Pays\n";
	cout << "Service starts\n";

	Technician tech;
	car = tech.ServiceCar(car);
	cout << "DONE FOR ALL\n";
}