string isValid(string s) {
    unordered_map<char, int> freq;

    
    for (char c : s) {
        freq[c]++;
    }

    
    unordered_map<int, int> countFreq;
    for (auto &p : freq) {
        countFreq[p.second]++;
    }

    
    if (countFreq.size() == 1) {
        return "YES";
    }

    
    if (countFreq.size() == 2) {
        auto it = countFreq.begin();
        int f1 = it->first;
        int c1 = it->second;
        ++it;
        int f2 = it->first;
        int c2 = it->second;

    
        if (f1 > f2) {
            swap(f1, f2);
            swap(c1, c2);
        }

    
        if (f1 == 1 && c1 == 1) {
            return "YES";
        }

    
        if (f2 == f1 + 1 && c2 == 1) {
            return "YES";
        }
    }

    return "NO";

}
