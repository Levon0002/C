#include<iostream>



class vector{
	public:
		vector(size_t size__ = 0){
			size = size__;
			if(size > 0){
				capacity = size;
				pointer = new int[capacity];
			}
		}
		bool push_back(int value){
			if(size == 0){
				capacity = 1;
				pointer = new int[capacity];
			}
			if(size == capacity){
				capacity = capacity  *  2;
				int* tmp  = new int[capacity];
				for(int i = 0; i < size; ++i){
					*(tmp + i) = *(pointer + i);
				}
				pointer = tmp;
			}
			
			*(pointer + size) = value;
			++size;
			return 1;

		}
		bool pop_back(){
			return *(pointer + (size--));
		}
		int operator[ ](int index) {
			return *(pointer + index);
		}
		void print_vec(){
			
			
			for(size_t i = 0; i < size; ++i){
				std::cout << "-----------" << std::endl;

				std::cout << *(pointer + i) << "---" << std::endl;
			}
		}
	private:
		size_t size;
		size_t capacity;
		int* pointer;

};



int main(){
	vector  a;
	
	bool result = a.push_back(5);
	a.push_back(6);
	a.push_back(8);
	a.pop_back();
	a.print_vec();
	std::cout << a[1];

}
