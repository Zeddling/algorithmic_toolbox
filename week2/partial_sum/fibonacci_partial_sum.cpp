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

int naive( int n, int m ) {
    int first = 0;
    int second = 1;
    int sum = first + second;
    int temp = 0;
    for (int i = 1; i < m; ++i) {
        if ( i >= n ) {
            std::cout << "At i = " << i << " before sum: f[before] = " << first << ", f[current] = "  << second << ", sum = " << sum << std::endl;
            temp = first + second;
            sum += second;
            first = second;
            second = temp;
            std::cout << "At i = " << i << " after" << " sum = " << sum << "\n\n";
        } else {
            temp = first + second;
            sum += second;
            first = second;
            second = temp;            
        }
    }
    return sum;
}

long long fibonacci_partial_sum( long long n, long long m ) { 
    long long pisano = pisano_period( 10 );
    long long n_remainder = n % pisano;
    long long m_remainder = m % pisano;
    long long first = 0;
    long long second = 1;
    long long sum = 0;
    long long temp = 0;    

    if ( n_remainder > m_remainder ) {
        m_remainder = m_remainder + n_remainder + 1;
    }
 
     for (int i = 1; i < (m_remainder + 1); ++i) {
        if ( i > n_remainder ) {
            //std::cout << "At i = " << i << " before sum: f[before] = " << first << ", f[current] = "  << second << ", sum = ";
            temp = (first + second) % 10;
            sum = (sum + second) % 10;
            first = second;
            second = temp;
            //std::cout << sum << "\n\n";
        } else if ( i == n_remainder ) {
            //std::cout << "At i = " << i << " before sum: f[before] = " << first << ", f[current] = "  << second << ", sum = ";
            sum = second;
            temp = ( first + second ) % 10;
            first = second;
            second = temp;
            //std::cout << sum << "\n\n";
        } else {
            temp = (first + second) % 10;
            sum = (sum + second) % 10;
            first = second;
            second = temp;            
        }
    }
    return sum;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << fibonacci_partial_sum( n, m );
    return 0;
}