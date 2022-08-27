/** 
* @file Factorial.hpp
* @description Factorial header dosyası
* @course 1.Ögretim A
* @assignment 1.Odev
* @date 02.08.2022
* @author Esra KIZILELMA
*/
#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP
#include "Arraylist.hpp"

class Factorial{
    private:
        int result;

    public:
        ArrayList* calculateFact(int);
        ArrayList* multiply(ArrayList*, ArrayList*);
        void printArrayList(ArrayList*);
          
};
#endif 

