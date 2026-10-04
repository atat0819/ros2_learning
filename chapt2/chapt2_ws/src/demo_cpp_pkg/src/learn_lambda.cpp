#include "iostream"
#include "algorithm"

int main()
{
auto add = [](int a, int b) ->int 
 { return a + b; };
 auto result = add(3, 5);
 auto print_sum = [&]() -> void
 {
    std::cout << result << std::endl;
 };
 print_sum();
}
