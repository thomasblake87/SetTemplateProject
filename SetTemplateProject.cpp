#include <iostream>
#include "UnorderedSet.h"

using namespace std;

int main() {
	//Create an array of integers and an array of strings
	int intArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	string strArray[] = {"red", "green", "blue", "purple", "orange", "yellow"};

	unorderedSet<int> intSet;
	unorderedSet<string> strSet;

	int arraySize = sizeof(intArray) / sizeof(int);
	int strArraySize = sizeof(strArray) / sizeof(string);

	for (int i = 0; i < arraySize; ++i) {
		intSet.insertEnd(intArray[i]);
	}
	for (int i = 0; i < strArraySize; ++i) {
		strSet.insertEnd(strArray[i]);
	}

	//Print the sets

	cout << "Int set after insertEnd:" << endl;
	intSet.print();
	cout << endl;
	cout << "String set after insertEnd:" << endl;
	strSet.print();
	cout << endl;

	//Insert ints and strings into each set

	cout << "Inserting 50 into int set at index 5..." << endl;
	intSet.insertAt(5, 50);
	intSet.print();
	cout << endl;

	cout << "Inserting \"black\" into the string set at index 3..." << endl;
	strSet.insertAt(3, "black");
	strSet.print();
	cout << endl;

	cout << "Inserting 2 into int set at index 5..." << endl;
	intSet.insertAt(5, 2);
	intSet.print();
	cout << "2 was not printed since 2 is already present in the set" << endl;
	cout << endl;

	//Replace existing parts of an int or string

	cout << "Replacing the number at index 5 with 30..." << endl;
	intSet.replaceAt(5, 30);
	intSet.print();
	cout << endl;

	cout << "Replacing the color at index 3 with \"white\"" << endl;
	strSet.replaceAt(3, "white");
	strSet.print();
	cout << endl;

	cout << "Trying to replace index 5 with the number 9 won't work" << endl;
	intSet.replaceAt(5, 9);
	intSet.print();
	cout << endl;

	//Union and intersection for int

	int intSet1Array[] = {1, 2, 3};
	int intSet2Array[] = {3, 4, 5};

	unorderedSet<int> intSet1, intSet2, intUnion, intIntersection;

	int intArraySize1 = sizeof(intSet1Array) / sizeof(int);
	int intArraySize2 = sizeof(intSet2Array) / sizeof(int);

	for (int i = 0; i < intArraySize1; ++i) {
		intSet1.insertEnd(intSet1Array[i]);
	}
	for (int i = 0; i < intArraySize2; ++i) {
		intSet2.insertEnd(intSet2Array[i]);
	}

	intUnion = intSet1 + intSet2;
	intIntersection = intSet1 - intSet2;

	cout << "Int set 1 contains the numbers:" << endl;
	intSet1.print();
	cout << "Int set 2 contains the numbers:" << endl;
	intSet2.print();
	cout << endl;

	cout << "The union of the 2 int sets is:" << endl;
	intUnion.print();
	cout << "The intersection of the 2 int sets is:" << endl;
	intIntersection.print();

	//Union and intersection for strings

	string strSet1Array[] = { "blue", "yellow", "red"};
	string strSet2Array[] = { "orange", "green", "red" };

	unorderedSet<string> strSet1, strSet2, strUnion, strIntersection;

	int strArraySize1 = sizeof(strSet1Array) / sizeof(string);
	int strArraySize2 = sizeof(strSet2Array) / sizeof(string);

	for (int i = 0; i < strArraySize1; ++i) {
		strSet1.insertEnd(strSet1Array[i]);
	}
	for (int i = 0; i < strArraySize2; ++i) {
		strSet2.insertEnd(strSet2Array[i]);
	}
	
	strUnion = strSet1 + strSet2;
	strIntersection = strSet1 - strSet2;

	cout << "String set 1 contains the colors:" << endl;
	strSet1.print();
	cout << "String set 2 contains the colors:" << endl;
	strSet2.print();
	cout << endl;

	cout << "The union of the 2 string sets is:" << endl;
	strUnion.print();
	cout << "The intersection of the 2 string sets is:" << endl;
	strIntersection.print();
}