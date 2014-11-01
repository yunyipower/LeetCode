class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size()==0) return;

        int visize = num.size();
        int cutindex = -1,minnum = INT_MIN,minindex = -1;

        for(int i=visize-2;i>=0;--i){
            if(num[i]<num[i+1]){
                cutindex = i;break;
            }
        }

        if(cutindex>-1){
            for(int i=cutindex+1;i<visize;++i){
                if(num[i]>num[cutindex]) continue;
                else{
                    minindex=i-1;
                    break;
                }
            }

            minindex = minindex==-1?(visize-1):minindex;
            minnum = num[minindex];
            swap(num[cutindex],num[minindex]);
            sort(num.begin()+cutindex+1,num.end());

        }else{
            sort(num.begin(),num.end());
        }
    }
};