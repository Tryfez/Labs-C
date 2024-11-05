#include <iostream>
int f(void) {
short var1;
long var2;
std::cout << "Input var1 & var2:";
std::cin >> var1 >> var2;
std::cout << var1 + var2 << std::endl; 
return 0;
}
