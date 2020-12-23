#include <iostream>

long long pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long fibonacci_sum( long long n ) { 
    long long pisano = pisano_period( 10 );
    long long remainder = n % pisano;
    long long first = 0;
    long long second = 1;
    long long res = remainder, sum = first + second;

    if ( remainder == 0 )
        return 0;
    else {
        for (int i = 1; i < remainder; i++){
            res = ( first + second ) % 10;
            first = second;
            second = res;
            sum = ( sum + second ) % 10;
        }
        return sum;
    }
}

int main() {
    long long n;
    std::cin >> n;
    if( n == 0 )
        std::cout << 0;
    else
        std::cout << fibonacci_sum( n );
    return 0;
}
