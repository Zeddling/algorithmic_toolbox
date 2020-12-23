#include <iostream>
#include <cmath>

int pisano_period(int n) {
    int a = 0, b = 1, c = a + b;
    for (int i = 0; i < n * n; i++) {
        c = (a + b) % n;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

int naive( int n ) {
    int first = 0;
    int second = 1;
    int first_square = first * first, second_square = second * second;
    int temp = first + second, sum = 0;
    std::cout << "Index = 0; " << "first = " << first << ", second = " << second << ", sum: " << first_square <<
        " + " << second_square << " = " << sum << std::endl;

    for (int i = 1; i <= n; ++i) {
        second_square = ( second * second ) ;
        temp = ( first + second ) ;
        first = second;
        second = temp;
        std::cout << "Index = " << i <<  "; " << "first = " << first << ", second = " << second << ", sum: " << sum <<
        " + " << second_square << " = ";
        sum = ( sum + second_square );
        std::cout << sum << std::endl;
    }
    return sum;
}

long long fast( long long n ) {
    long long remainder = n % pisano_period( 10 );    
    long long first = 0;
    long long second = 1;
    long long res = remainder;

    for (int i = 1; i < remainder; i++) {
        res = ( first + second ) % 10;
        first = second;
        second = res; 
    }
    
    return res % 10;
}

int main() {
    long long n; 
    std::cin >> n;
    std::cout << (fast( n ) * fast( n + 1 ) % 10); 
    return 0;
}