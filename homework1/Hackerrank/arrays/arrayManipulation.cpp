long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 1, 0);

for (auto q : queries) {
    int a = q[0];
    int b = q[1];
    int k = q[2];

    arr[a - 1] += k;
    if (b < n) arr[b] -= k;
}

long maxVal = 0, current = 0;
for (int i = 0; i < n; i++) {
    current += arr[i];
    maxVal = max(maxVal, current);
}
return  maxVal;
}