#include <iostream>
#include "base_container.h"
#include "sequence_container.cpp"
#include "list_container.cpp"

int main()
{
    size_t valNum=0;
    std::cout << "Sequence container" << std::endl;
    //создание контейнера con1 для элементов типа int
    Sequence_Container <int> con1;
    //добавление в контейнер 10 элементов 0...9
    while (valNum != 10 ) {
        con1.push_back(valNum);
        valNum++;
    }
    //вывод содержимого на экран
    con1.show();
    //вывод размера на экран
    std::cout << "Size: " << con1.size() << std::endl;
    //удаление 3го по счёту элемента (счёт начинается с нуля)
    con1.erase(2);
    //удаление 5го элемента
    con1.erase(3);
    //удаление 7го элемента
    con1.erase(4);
    //вывод содержимого на экран
    con1.show();
    //добавление 10 в начало контейнера
    con1.insert(0, 10);
    //вывод содержимого на экран
    con1.show();
    //добавление 20 в середину контейнера
    con1.insert(4, 20);
    //вывод содержимого на экран
    con1.show();
    //добавление 30 в конец контейнера
    con1.insert(9, 30);
    //вывод содержимого на экран
    con1.show();
    std::cout << "Element 1: " << con1[0] << std::endl;
    std::cout << "Element 4: " << con1[3] << std::endl;
    std::cout << "Element 9: " << con1[8] << std::endl;


    std::cout << "\n\nList container" << std::endl;
    valNum = 0;
    List_Container <int> con2;
    while (valNum != 10 ) {
        con2.push_back(valNum);
        valNum++;
    }
    //вывод содержимого на экран
    con2.show();
    //вывод размера на экран
    std::cout << "Size: " << con2.size() << std::endl;
    //удаление 3го по счёту элемента (счёт начинается с нуля)
    con2.erase(2);
    //удаление 5го элемента
    con2.erase(3);
    //удаление 7го элемента
    con2.erase(4);
    //вывод содержимого на экран
    con2.show();







    return 0;
}
