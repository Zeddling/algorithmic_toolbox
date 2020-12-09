#include <algorithm>
#include <iostream>
#include <vector>

//  long long to avoid integer 
long long max( int array[], int n ) {

    int maxNum = array[0];

    for (int i = 1; i < n; i++) {
        if ( array[i] > maxNum )
            maxNum = array[i];
    }
    return maxNum;
}

int getIndex(int element, int array[], int size) {
    for(int i = 0; i < size; i++) {
        if ( array[i] == element )
            return array[i];
    }
}

long long MaxPairWiseProduct( int array[], int size ) {
    long long highestNum = max(array, size);
    int newArray[size-1];
    int newI=0;
    for(int i = 0; i < size; i++) {
        if(array[i] != highestNum) {
            newArray[newI] = array[i];
            newI++;
        }
    }

    long long secondHighestNum = max(newArray, size-1);
    return highestNum * secondHighestNum;
}

int main() {
    int size;
    std::cin >> size;

    int array[size];

    for(int i = 0; i < size; i++){
        std::cin >> array[i];
    }

    std::cout << MaxPairWiseProduct( array, size );
    return 0;
}