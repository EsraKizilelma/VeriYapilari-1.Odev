/** 
* @file ArrayList.cpp
* @description ArrayList
* @course 1.Ögretim A
* @assignment 1.Odev
* @date 02.08.2022
* @author Esra KIZILELMA
*/
#include "ArrayList.hpp"
#include <iostream>

ArrayList::ArrayList() {
    length = 0;
    capacity = 0;
    items = 0;
}

void ArrayList::reverse(int newCapacity) {
    if (capacity >= newCapacity) return; //yeni kapasite eskisinden kucukse hicbirsey yapmaz
    int *tmp = new int[newCapacity]; //tmp degiskenine daha buyuk kapasiteli dizi olusturulur
    
    for (int i = 0; i < length; i++) { //items 'in icindeki veri tmp dizisine kopyalanir
        tmp[i] = items[i];
    }
    
    if (items != 0) { //items dizisi degil ise silinir heap bellekte cop olusmamasi icin
        delete[] items;
    }
    
    items = tmp; //gecici dizinin adresi items degikenine atanir
    capacity = newCapacity; //kapasite bilgisi yenilenir
}

void ArrayList::add(int item) { 
    insert(length, item);
}

void ArrayList::insert(int i, int item) {
    if (i < 0 || i > length) throw "HATA";
    
    if (length >= capacity)
        if (capacity){
            reverse(2 * capacity);
        } else {
            reverse(1);     //capacity sifirsa 1 yap yapılan fokteriyel işlemin sonucu arrayList'in ilk indisine konulun fazladan yer ayırmaya gerek yok
        }
    for (int j = length - 1; j >= i; j--) {
        items[j + 1] = items[j]; //dizi i den itibaren bir saga kaydirilir
    }
    items[i] = item;
    length++;
}

int ArrayList::size() const 
{//dizini boyutunu verir
    return length;
}

bool ArrayList::isEmpty() const 
{//dizi bos mu diye kontorl eder
    return size() == 0;
}

int ArrayList::elementAt(int i) 
{//istenilen indisteki elemani getirir
    if (i < 0 || i >= length) throw "HATA";
    return items[i];
}

void ArrayList::removeAt(int i) 
{//belirtilen indisteki elemani siler
    if (i < 0 || i >= length) throw "HATA";
    for (int j = i + 1; j < length; j++) items[j - 1] = items[j];
    length--;
}

void ArrayList::clear()
 {//diziyi sifirlar
    length = 0;
}

int* ArrayList::reverseArray() 
{//diziyi tersine cevirir
    int temp;
    for (int i = 0; i < length / 2; i++) {
        temp = items[i];
        items[i] = items[length - i - 1];
        items[length - i - 1] = temp;
    }
    return items;
}
void ArrayList::putAt(int i, int item)
{//dizinin istenilen indisine eleman ekler
    if (!(items == NULL || i < 0 || i > length)) throw "hata";
    items[i] = item;
}

void ArrayList::set(int i, int item)
{//belirtilen indisteki elemani degistirir
    if (i < 0 || i >= length) throw "HATA";
    items[i] = item;
}

int ArrayList::first() const
{//ilk eleman
	if(length == 0) throw "HATA"; 
	return items[0];
}
int ArrayList::last()const 
{//son elelman
	if(length == 0) throw "HATA";
	return items[length-1];
}

ArrayList::~ArrayList() {
    if (items != NULL) delete[] items;
}
