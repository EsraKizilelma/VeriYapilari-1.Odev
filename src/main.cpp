/** 
* @file main.cpp
* @description main
* @course 1.Ögretim A
* @assignment 1.Odev
* @date 06.08.2022
* @author Esra KIZILELMA
*/
#include "Factorial.hpp"
#include "ArrayList.hpp"

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "Please enter the number you want to take the factorial of: ";
    int num;
    cin >> num;
    Factorial factorial;
    ArrayList *result = factorial.calculateFact(num);
    factorial.printArrayList(result);
    delete result;
    return 0;
}

