#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int size) {
    if ( size == 1 ) {
        return 0;
    }

    if ( size == 2 ) {
        return 1;
    }

    else {
        int array[size+1];

        //  Initialize first array entries
        array[0] = 0;
        array[1] = 1;
        for ( int i = 2; i <= size; ++i ) {
            array[i] = (array[i-1] + array[i-2]) % 10;
        }
        return array[size];
    }
}

int main() {
    int n;
    std::cin >> n;
    std::cout << get_fibonacci_last_digit_fast( n );
    return 0;
}