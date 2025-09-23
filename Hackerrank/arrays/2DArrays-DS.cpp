int hourglassSum(vector<vector<int>> arr) {
    int max = -100;
    int sum = 0;
    for(size_t i = 0; i < 4; ++i){
        for(size_t j = 0; j < 4; ++j){
            sum += arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
            sum += arr[i+1][j+1];
            sum += arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j + 2];
            if(sum > max){
                max = sum;
            }
            sum = 0;
        }
    }
    return max;
}
