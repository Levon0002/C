int makeAnagram(string a, string b) {
    std::array<int, 26> letters {0};
    int result = 0;
    for(auto c : a){
        if ('a' <= c && c <= 'z')
            letters[c - 'a']++;
    }
    for(auto c : b){
        if ('a' <= c && c <= 'z')
            letters[c - 'a']--;
    }
    for(auto i : letters){
        result += std::abs(i);    
    }
    return result;
}
