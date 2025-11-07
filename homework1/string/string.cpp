#include "iostream"
#include"string"
int get_string_size(const char* str);

class string{
    private:
        int size=0;
        int capacity;
        char* data;
    public:
        string(const char* value ){
            size = get_string_size(value);

            if(size <  (2 * sizeof(int) + sizeof(value)  )){
                *(reinterpret_cast<unsigned char*>(this)) |= 1;
                char* storage = (reinterpret_cast<char*>(this) + 1);
                int index = 0;
                while(value[index] != '\0'){
                    storage[index] = value[index];
                    ++index;
                }
                storage[index] = '\0';

            }else{
                capacity = size;
                data = new char[size + 1];
                int index = 0;
                while(value[index] != '\0'){
                    data[index] = value[index];
                    ++index;
                }
                data[index] = '\0';
                *(reinterpret_cast<unsigned char*>(this)) &= ~1;

            }
        }
        char& operator[](int index){
            if(*(reinterpret_cast<char*>(this)) & 1 ){
                char* storage =  (reinterpret_cast<char*>(this) + 1);
                return storage[index];
            }else{
                return data[index];
            }
        }
        char* append(const char* value){
                char* storage;
            if(*(reinterpret_cast<char*>(this)) & 1 ){
                    storage =  (reinterpret_cast<char*>(this) + 1);
                }else{
                    storage = data;
                }
                int size1 = get_string_size(value);
                int index=0;
                while(storage[index] != '\0'){
                    ++size1;
                    ++index;
                }
                if(size1 > (2 * sizeof(int) + sizeof(value) )){
                    char* tmp  = new char[size1 + 1];
                    index = 0;
                    while(storage[index] != '\0'){
                        tmp[index] = storage[index];
                        ++index;
                    }
                    while(*value != '\0'){
                        tmp[index] = *value;
                        value++;
                        ++index;
                    }
                    tmp[index] = '\0';
                    data = tmp;
                    capacity = size1;
                    *(reinterpret_cast<char*>(&size) + 1 ) = (char) (size1);
                    return data;

                }else{
                    for( index = index -1 ; *value != '\0'; value++){
                        storage[index] = *value;
                        index++;
                    }
                    storage[index] = '\0';
                    return storage;
                }



        }
        ~string(){
            if(! (*(reinterpret_cast<char*>(this)) & 1) ){
                delete[] data;
            }
        }
        int get_size() const { return size; }
        int get_capacity() const { return capacity; }
    
         void debug() const {
            std::cout << "Size: " << size << ", Capacity: " << capacity << std::endl;
        }
};


int get_string_size(const char* str) {
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length * sizeof(char);  
}
int main(){
    
    string s1 = "hello";
    
    // Test operator[]
    std::cout << "s1[0] = '" << s1[0] << "'" << std::endl;
    s1[0] = 'H';  // Modify
    
    // Test append
    s1.append(" World");
    
    std::cout << "\n=== Testing Large String ===" << std::endl;
    string s2 = "this is a very long string that should use heap allocation";
    s2.debug();
    
    // Test operator[] on large string
    std::cout << "s2[10] = '" << s2[10] << "'" << std::endl;
    s2[0] = 'T';
    // Test append on large string
    s2.append(" - appended text");
    s2.debug();
    
    std::cout << "\n=== Testing SSO to Heap Conversion ===" << std::endl;
    string s3 = "short";
    std::cout << "--------------------" << std::endl;
    s3.debug();
    std::cout << "--------------------" << std::endl;

    s3.append(" this will make it very long and force heap allocation");
    s3.debug();
    
    return 0;
}