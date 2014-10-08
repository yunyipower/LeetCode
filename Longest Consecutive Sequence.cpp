class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int,bool> hashmap;
        int maxlength = 0;
        int curlength = 0;
        
        for(vector<int>::iterator iter = num.begin();iter!=num.end();++iter){
            hashmap.insert(pair<int,bool>(*iter,true));
        }
        
        for(vector<int>::iterator iter = num.begin();iter!=num.end();++iter){
            int num = *iter;
            curlength = 0;
            while(hashmap.find(num) != hashmap.end()){
                ++curlength;
                hashmap.erase(num);
                ++num;
            }
            
            num = *iter-1;
            while(hashmap.find(num) != hashmap.end()){
                ++curlength;
                hashmap.erase(num);
                --num;
            }
            
            maxlength = maxlength<curlength?curlength:maxlength;
        }
        return maxlength;
    }
};