#include <iostream>

int main(){
	
	const int size = 7;
	int array[size] = {1, 2, 0, 3, 1, 2, 0};
	int result = 0;
	for(int i = 0; i < size; ++i){
		result = result ^ array[i];
	}
	std::cout << "Your number------>" << result << std::endl; 
	
	return 0;
}
