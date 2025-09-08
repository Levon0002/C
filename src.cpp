#include <iostream>

int main(){
	
	const int size = 7;
	int array[size] = {1, 2, 0, 3, 1, 2, 0};
	int result[size/2  + 1] = {0};
	for(int i = 0; i < size; ++i){
		result[array[i]]++;
	}
	for(int i = 0; i < (size/2  + 1) ; ++i ){
		if(result[i] == 1){
			std::cout << "------>" << i << std::endl;
		}
	}
	return 0;
}
