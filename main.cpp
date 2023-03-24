#include <iostream>
#include "base_container.h"
#include "sequence_container.cpp"
#include "list_container.cpp"
using namespace std;

int main()
{
    cout << "Sequence container" << endl;
    Sequence_Container <int> con1;
    int val=0;
    size_t valNum=0;

    while (valNum != 4) {
        std::cin >> val;
        con1.push_back(val);
        valNum++;
    }

    con1.show();
    cout << "Size1: " << con1.size() << endl;

    con1.erase(4);
    con1.show();
    cout << "Size2: " << con1.size() << endl;

    con1.insert(2, 10);
    con1.show();
    cout << "Size3: " << con1.size() << endl;

    return 0;
}
