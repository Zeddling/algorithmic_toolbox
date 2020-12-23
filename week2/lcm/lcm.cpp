#include <iostream>

long long gcd( int a, int b) {
   while (b != 0) {
       long long temp = b;
       b = a % b;
       a = temp;
   }
    return a;
}

long long lcm( long long a, long long b ) {
    return (a * b) / gcd( a, b );
}

void test() {
    while (true) {
        int i = 0; 
    }
}

int main() {
    int a, b;
    std::cin >> a;
    std::cin >> b;
    std::cout << lcm( a, b );

    return 0;
}