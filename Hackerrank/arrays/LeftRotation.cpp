vector<int> rotLeft(vector<int> a, int d) {
    const int size = a.size();
    vector<int> result(size); 
    while(d > size){
        d = d - size;
    }
    for(size_t i = 0; i < size; ++i){
        if(d > i){
            result[size - d + i] = a[i];
        }else {
            result[i - d] = a[i];
        }
    }
    return result;
}
