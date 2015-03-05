class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int i, j, n = strlen(haystack), m = strlen(needle);
        if(!m) return 0;
        int *next = new int[m+1];
        //getNext
        i = 0; next[0] = j = -1;
        while(i<m){
            while(j>=0 && needle[i] != needle[j]) j = next[j];
            next[++i] = ++j;
        }
        
        //strStr
        i = 0; j = 0;
        while(i<n){
            while(j>=0 && haystack[i] != needle[j]) j = next[j];
            i++; 
            j++;
            if(j==m){
                return i - m;
            }
        }
        return -1;
    }
};