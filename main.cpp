#include <iostream>
#include "base_container.h"
#include "sequence_container.cpp"
#include "list_container.cpp"
#include "list_container_oneDir.cpp"

template <typename T>
void run_test(  T & contName ) {
    size_t valNum=0;
    while (valNum != 10 ) {
        contName.push_back(valNum);
        valNum++;
    }
    //вывод содержимого на экран
    contName.show();
    //вывод размера на экран
    std::cout << "Size: " << contName.size() << std::endl;
    //удаление 3го по счёту элемента (счёт начинается с нуля)
    contName.erase(3);
    //удаление 5го элемента
    contName.erase(4);
    //удаление 7го элемента
    contName.erase(5);
    //вывод содержимого на экран
    contName.show();
    //добавление 10 в начало контейнера
    contName.insert(0, 10);
    //вывод содержимого на экран
    contName.show();
    //добавление 20 в середину контейнера
    contName.insert(4, 20);
    //вывод содержимого на экран
    contName.show();
    //добавление 30 в конец контейнера
    contName.insert(9, 30);
    //вывод содержимого на экран
    contName.show();

    std::cout << "Element 1: " << contName[0] << std::endl;
    std::cout << "Element 4: " << contName[3] << std::endl;
    std::cout << "Element 9: " << contName[8] << std::endl;
}


int main() {
    std::cout << "Sequence container" << std::endl;
    Sequence_Container <int> con1;
    run_test(con1);

    //семантика перемещения для класса  List_Container
     Sequence_Container <int> moveCont3 = std::move(con1);
     std::cout << "\n\nMove semantic for Sequence_Container" << std::endl;
     for (size_t i=0; i < moveCont3.size(); ++i) {
         std::cout << moveCont3[i] << " ";
     }
//==================================================================
    std::cout << "\n\nList container" << std::endl;
    List_Container <int> con2;
    run_test(con2);

    std::cout << "\n\nIterators1" << std::endl;
    List_Container<int>::iterator itr;
    for ( itr = con2.begin(); itr != con2.end(); ++itr ) {
        std::cout << *itr << " " ;
    }
    std::cout << std::endl;
    std::cout << "\n\nIterators2" << std::endl;

    for ( itr = con2.begin(); itr != con2.end(); ++itr) {
        std::cout << itr.get() << " ";
    }
    std::cout << std::endl;
    //семантика перемещения для класса  List_Container
    std::cout << "\n\nMove semantic for List_container" << std::endl;
    List_Container <int> moveCont2 = std::move(con2);
    for (size_t i=0; i < moveCont2.size(); ++i) {
         std::cout << moveCont2[i] << " ";
     }

//==================================================================
    std::cout << "\n\nList container (one dir)" << std::endl;
    List_Container_oneDir <int> con3;
    run_test(con3);

   //семантика перемещения для класса  List_Container_oneDir
    std::cout << "\n\nMove semantic for List_Container_oneDir" << std::endl;
    List_Container_oneDir <int> moveCont = std::move(con3);
    for (size_t i=0; i < moveCont.size(); ++i) {
        std::cout << moveCont[i] << " ";
    }

    return 0;
}



