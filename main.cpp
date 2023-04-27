#include <iostream>
#include "base_container.h"
#include "sequence_container.cpp"
#include "list_container.cpp"
#include "list_container_oneDir.cpp"

template <typename T>
void run_test(T&  contName ) {
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
/*  std::cout << "Sequence container" << std::endl;
    Sequence_Container <int> con1;
    run_test(con1);


    std::cout << "\n\nList container" << std::endl;
    List_Container <int> con2;
    run_test(con2);*/

    std::cout << "\n\nList container (one dir)" << std::endl;
    List_Container_oneDir <int> con3;
    run_test(con3);

 //   List_Container_oneDir<int>::iterator itr = con3.begin();
 /*   while (itr != con3.end()) {
        std::cout << itr.iNode->data << " ";
        ++itr;

    }
    std::cout << "\n";*/



    return 0;
}
