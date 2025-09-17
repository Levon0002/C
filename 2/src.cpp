#include <iostream>
#include <vector>
#include <random>
#include <algorithm>



void  generateArray(std::vector<int>& arr, int numDuplicates = 10, int minVal = 1, int maxVal = 100) {
    arr.clear();
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(minVal, maxVal);

    
    for(int i = 0; i < numDuplicates; ++i) {
        int val = dist(rng);
        arr.push_back(val);
        arr.push_back(val); 
    }

    
    int unique1 = dist(rng);
    int unique2 = dist(rng);
    while(unique2 == unique1) {
        unique2 = dist(rng);
    }

    arr.push_back(unique1);
    arr.push_back(unique2);

    
    std::shuffle(arr.begin(), arr.end(), rng);
    
}
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}



void printTwoUnique(const std::vector<int>& arr) {
    int xorAll = 0;
    for (int num : arr) {
        xorAll ^= num;  
    }

    
    int setBit = xorAll & -xorAll;

    int x = 0, y = 0;
    for (int num : arr) {
        if (num & setBit)
            x ^= num;   
        else
            y ^= num;  
    }

    std::cout << "The two unique elements are: " << x << " and " << y << std::endl;
}


void test(const std::vector<int>& arr){
	std::cout << "Your array ----> " ;
	printArray(arr);
	printTwoUnique(arr);
}


int main(){
	std::vector<int> vec; 
       	generateArray(vec);
	test(vec);

	return 0;

}
