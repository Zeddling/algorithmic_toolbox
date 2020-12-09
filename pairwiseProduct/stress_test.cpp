#include <cstdlib>
#include <iostream>
#include <vector>

//  long long to avoid integer 
int max( int array[], int n ) {

    int maxNum = array[0];
    int maxIndex = 0;

    for (int i = 1; i < n; ++i) {
        if ( array[i] > maxNum ) {
            maxIndex = i;
        }
            
    }
    return maxIndex;
}

int getIndex(int element, int array[], int size) {
    for(int i = 0; i < size; ++i) {
        if ( array[i] == element )
            return array[i];
    }
}

long long MaxPairWiseProduct( int array[], int size ) {
    long long max_product = 0;
    for(int first = 0; first < size; ++first) {
        for( int second = first + 1; second < size; ++second) {
            if(((long long)array[first] * array[second]) > max_product)
                max_product = (long long) array[first] * array[second];
        }
    }
    return max_product;
}

long long MaxPairWiseProductFast( int array[], int size ) {

    int max_index_1 = -1;
    for(int i = 0; i < size; ++i) 
        if((max_index_1 == -1 ) || (array[i] > array[max_index_1]) )
            max_index_1 = i;
    
    int max_index_2 = -1;
    for(int j = 0; j < size; ++j)
        if((j != max_index_1) && ((max_index_2 == -1) || (array[j] > array[max_index_2])))
            max_index_2 = j;
    //std::cout << max_index_1 << ", " << max_index_2 << "\n";
    return ((long long) (array[max_index_1])) * array[max_index_2];
}

void test() {
    while (true) {
        int n = rand() % 1000 + 2;
        std::cout << n << "\n";
        int array[n];
        for(int i = 0; i < n; ++i) {
            array[i] = rand() % 100000;
        }
        for(int i = 0; i < n; ++i) {
            std::cout << array[i] << ' ';
        }
        std::cout << "\n";
        long long result_1 = MaxPairWiseProduct( array, n );
        long long result_2 = MaxPairWiseProductFast( array, n );
        if(result_1 != result_2) {
            std::cout << "Wrong answer: " << result_1 << ", " << result_2;
            break;
        } else {
            std::cout << "OK\n";
        }
    }
    
}

int main() {

    //  Test algorithm
    //test();

    int size;
    std::cin >> size;

    int array[size];

    for(int i = 0; i < size; ++i){
        std::cin >> array[i];
    }

    std::cout << MaxPairWiseProductFast( array, size );
    return 0;
}