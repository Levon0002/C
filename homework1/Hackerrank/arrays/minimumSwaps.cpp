int minimumSwaps(vector<int> arr) {
    int swap = 0;
     for(int i = 0; i < arr.size(); ++i){
        int j = i;
        while(arr[j] != i + 1 ){
            j++;
        }
        if(i != j){
            int tmp = arr[j];
            arr[j] =  arr[i];
            arr[i]  = tmp;
            swap++;
        }
     }
     return swap;

}