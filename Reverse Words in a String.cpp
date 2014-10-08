class Solution {
public:
    void reverseWord(string &s,int i,int j){
        while(i<j){
            swap(s[i++],s[j--]);
        }
    }

    void reverseWords(string &s) {
        if(s.length()==0) return;
        for(int i=0;i<s.length();){
            int j=i+1;
            while(j<s.length()&&s[j]!=' '){
                ++j;
            }
            reverseWord(s,i,j-1);
            i = j+1;
        }
        reverseWord(s,0,s.length()-1);
        
        int i=0,j=0;bool spaceduplicates = true;
        for(;i<s.length();){
            if(spaceduplicates&&s[i]==' '){
                ++i;continue;
            }
            
            if(s[i]==' ') spaceduplicates = true;
            else spaceduplicates = false;
            
            s[j++] = s[i++];
        }
        s.resize(j==0?j:((s[j-1]==' ')?j-1:j));
    }
};