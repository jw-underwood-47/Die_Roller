int char_in_string(char c, char* str){
    int ans = 0;
    while(str[ans] != '\0' && str[ans] != c) ans++;
    return (str[ans] == c) ? ans : 0;
}
