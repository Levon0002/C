long substrCount(int n, string s) {
    long result = 0;

    
    vector<pair<char, int>> runs; 
    

    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && s[j] == s[i]) j++;
        runs.push_back({s[i], j - i});
        i = j;
    }

    
    for (auto &p : runs) {
        long len = p.second;
        result += len * (len + 1) / 2;
    }

    
    for (int i = 1; i + 1 < (int)runs.size(); i++) {
    
        if (runs[i].second == 1 && runs[i - 1].first == runs[i + 1].first) {
            result += min(runs[i - 1].second, runs[i + 1].second);
        }
    }

    return result;
}
