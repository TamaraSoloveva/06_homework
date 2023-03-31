#include <iostream>
#include "base_container.h"
#include "sequence_container.cpp"
#include "list_container.cpp"

template <typename T>
void run_test(T contName ) {
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
    contName.erase(2);
    //удаление 5го элемента
    contName.erase(3);
    //удаление 7го элемента
    contName.erase(4);
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
}



int main() {
    std::cout << "Sequence container" << std::endl;
  //  Sequence_Container <int> con1;
  //  run_test(con1);

    std::cout << "\n\nList container" << std::endl;
    List_Container <int> con2;
    run_test(con2);

    return 0;
}
