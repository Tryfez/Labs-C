#include <iostream>
int f(void);
using namespace std;
int main(int argc, char *argv[]) {
int i = (argc > 1) ? atoi(argv[1]) : 0;
int c = 1;
while (i != 0) {
cout << c << ' ';
f();
cout << endl; i--; c++;
}
return 0;
}
