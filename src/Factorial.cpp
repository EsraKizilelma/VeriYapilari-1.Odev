/** 
* @file Factorial.cpp
* @description Factorial islemleri yapar
* @course 1.Ögretim A
* @assignment 1.Odev
* @date 06.08.2022
* @author Esra KIZILELMA
*/
#include "Factorial.hpp"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void Factorial::printArrayList(ArrayList* arr){
    //Dosyaya yazma işlemi yapar

    ofstream outfile("Sonuc.txt");
    for(int i=0;  i < arr->size() ; i++){
        //cout << arr->elementAt(i);
        outfile << arr->elementAt(i);
    }
}

ArrayList* Factorial::multiply(ArrayList *num1, ArrayList *num2) { 
    //

    int carry = 0; 

    num1->reverseArray();
    num2->reverseArray();    
    
    ArrayList *toplam = new ArrayList();

    for (int i = 0 ; i < num2->size() ; i++)
    {   
        ArrayList *carpmaSonuc = new ArrayList(); 
        int multResult = 0; 
        for (int j = 0 ; j < num1->size() ; j++)
        {
            multResult = (num2->elementAt(i) * num1->elementAt(j)) + carry;
            carry = multResult / 10;
            carpmaSonuc->add(multResult % 10);           
        }
      
        if (carry > 0)
        {
            carpmaSonuc->add(carry);
            carry = 0;
        }         

        int innerCarry = 0 ;
        if (toplam->isEmpty() == true)
        {   
            toplam->capacity = carpmaSonuc->capacity;     
            toplam->length = carpmaSonuc->length; 
            toplam->items = carpmaSonuc->items;
            carpmaSonuc->items = NULL;    
        }
        else
        {   
            int sizeDiff = toplam->size() > carpmaSonuc->size() ? toplam->size() - carpmaSonuc->size() : carpmaSonuc->size() - toplam->size();
            
            if (carpmaSonuc->size() < toplam->size())
            {
                for (int k = 0 ; k < sizeDiff ; k++)
                {
                    carpmaSonuc->add(0);
                }
            }
            else
            {
                for (int k = 0 ; k < sizeDiff ; k++)
                {
                    toplam->add(0);
                }
            }

            int i;
            for (i = 0 ; i < toplam->size() ; i++)
            {                   
                if (i < carpmaSonuc->size())
                {
                    int sum = (toplam->elementAt(i) + carpmaSonuc->elementAt(i) + innerCarry) % 10;
                    innerCarry = (toplam->elementAt(i) + carpmaSonuc->elementAt(i) + innerCarry) / 10;
                    toplam->set(i, sum);
                }
                else if (toplam->size() > carpmaSonuc->size())
                {
                    int sum = (toplam->elementAt(i) + innerCarry) % 10;
                    innerCarry = (toplam->elementAt(i) + innerCarry) / 10;
                    toplam->set(i, sum);
                }
                else
                {
                    int sum = (carpmaSonuc->elementAt(i) + innerCarry) % 10;
                    innerCarry = (carpmaSonuc->elementAt(i) + innerCarry) / 10;
                    toplam->add(sum);
                }                
            }

            if (innerCarry > 0)
            {
                toplam->add(innerCarry);
                innerCarry = 0;
            }
         
            
        }  
        delete carpmaSonuc;
    }
    delete num1;
    toplam->reverseArray();

    return toplam;
}   

ArrayList *convertToArrayList(int number)
{//girilen sayiyi arrayliste çevirir
    ArrayList *arr = new ArrayList();
    while(number > 0)
    {
        arr->add(number % 10);
        number /= 10;
    }
    return arr;
}

ArrayList* Factorial::calculateFact(int number) { 
    //faktöriyel hesaplar ve faktoriyel hesaplamadaki kontrolleri saglar

    ArrayList *factorial = new ArrayList();
    int start = 1;

    if (number == 0 || number == 1)
    {
        factorial->add(1);
    }

    if (number < 0)
    {
        cout << "Invalid input" << endl;
        exit(0);
    }

    //1'den baslayip istedigimiz sayiya kadar çarpma islemi yapar
    while (start <= number)
    {
        ArrayList *arrNum = convertToArrayList(start);
        arrNum->reverseArray();
       
        if (factorial->isEmpty())
        {
            ArrayList *numBefore =  convertToArrayList(start+1);
            numBefore->reverseArray();
            factorial = multiply(arrNum, numBefore);   
            start += 2;
            delete numBefore;
        }
        else
        {
            factorial = multiply(factorial, arrNum);    
            start++;  
        }
        delete arrNum;
    }
    return factorial;
}