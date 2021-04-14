#include <iostream>
#include "Logger.hpp"

class Test : public Logger {
public:
    void run1() {
        open("./", "test11");
        write("test11") << "Test 11" << std::endl;
        write("test12") << "Test 12" << std::endl;
        write() << "write() -> should be file 11" << std::endl;
        close();
    }

    void run2() {
        open("./", "test21");
        write("test21") << "Test 21" << std::endl;
        write("test22") << "Test 22" << std::endl;
        write() << "write() -> should be file 21" << std::endl;
        close();
    }

    void run3() {
        setPath("./log/");
        open("test3");
        write("test3") << "Test 31" << std::endl;
        close();
    }
};

int main() {
    Test test;

    test.run1();
    test.run2();
    test.run3();

    return 0;
}
