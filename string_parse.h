/* return index of first occurence of c in str, or 0 if c not in str */
int char_in_string(char c, char* str){
    int ans = 0;
    while(str[ans] != '\0' && str[ans] != c) ans++;
    return (str[ans] == c) ? ans : 0;
}
