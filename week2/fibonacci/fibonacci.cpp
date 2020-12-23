#include <iostream>


int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long fibonacci_fast(int size) {

    if ( size < 1 ) {
        return 0;
    }

    if ( size == 1 ) {
        return 1;
    }

    else {
        long long array[size+1];

        //  Initialize first array entries
        array[0] = 0;
        array[1] = 1;
        for ( int i = 2; i <= size; ++i ) {
            if (i == size)
                return array[i-1] + array[i-2];
            else 
                array[i] = array[i-1] + array[i-2];
        }
    }
}

void test() {
    while (true) {
        int n = 0;
        if ( fibonacci_fast(n) == fibonacci_naive(n) ) {
            std::cout << "Similar for both" << std::endl;
        } else {
           std::cout << "Fail for size n = " << n << std::endl;
           break;
        }
        n+=1;
    }
}

int main() {
    int size;
    //test();

    std::cin >> size;
    std::cout << fibonacci_fast(size);
    return 0;
}
