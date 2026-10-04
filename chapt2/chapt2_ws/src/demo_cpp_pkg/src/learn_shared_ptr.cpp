#include "iostream"
#include "memory"

int main()
{
    auto p1 = std::make_shared<std::string>("this is a shared pointer");
    std::cout << "p1的引用次数:" << p1.use_count() << "指向内存地址:" << p1.get() << std::endl;

    auto p2 = p1;
    std::cout << "p1的引用次数:" << p1.use_count() << "指向内存地址:" << p1.get() << std::endl;
    std::cout << "p2的引用次数:" << p2.use_count() << "指向内存地址:" << p2.get() << std::endl;

    p1.reset();  //释放
    std::cout << "p1的引用次数:" << p1.use_count() << "指向内存地址:" << p1.get() << std::endl;
    std::cout << "p2的引用次数:" << p2.use_count() << "指向内存地址:" << p2.get() << std::endl;

    std::cout << "p2指向的内存地址的值:" << p2->c_str() << std::endl;
    return 0;
}