#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <type_traits> 

template <typename T>
std::remove_reference_t<T>&& coreMove(T&& universArg) noexcept {
    return static_cast<std::remove_reference_t<T>&&>(universArg);
}

template <typename ContainerFirst, typename ContainerSecond>
void moveVectors(ContainerFirst& conFirst, ContainerSecond& conSec) {
    for (auto it = conFirst.begin(); it != conFirst.end(); ++it) {
        conSec.insert(conSec.end(),coreMove(*it));
    }
    conFirst.clear();
}


int main() {
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    moveVectors(one,two);
    return 0;
}

