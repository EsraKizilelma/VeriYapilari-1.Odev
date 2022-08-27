/** 
* @file ArrayList.hpp
* @description ArrayList header dosyası
* @course 1.Ögretim A
* @assignment 1.Odev
* @date 02.08.2022
* @author Esra KIZILELMA
*/
#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

class ArrayList{
   // private:     
    public:
        int capacity;
        void reverse(int);//yeni alan olusturur
        int *items;
    //public:
     
        int length;
        ArrayList();
        void add(int item);//dizinin sonuna eleman ekler
        void insert(int i, int item);//dizin istelilen indisine eleman ekler
        int size() const;//dizini boyutunu verir
        bool isEmpty() const;//diziyi bos mu diye kontrol eder
        int elementAt(int i) ;//belirtilen indisteki elemani verir
        void removeAt(int i);//belirtilen indisteki elemani siler 
        void clear();//diziyi sifirlar
        void set(int i, int item);//belirtilen indisteki elemani degistirir
        int last()const ;
        int first()const;
        int* reverseArray();//diziyi tersine cevirir
        void putAt(int i, int item);
        ~ArrayList();  
};
#endif 

