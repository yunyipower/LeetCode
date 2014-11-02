class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int iret = 1;
        for(int i=0;i<n;++i){
            while(A[i]>0&&A[i]<=n&&A[i]!=i+1){
                if(A[i] != A[A[i]-1]) swap(A[i],A[A[i]-1]);
                else break;
            }
        }
        
        for(int i=0;i<n;++i){
            if(A[i]!=i+1){
                iret = i+1;
                break;
            }else iret = A[i]+1;
        }
        return iret;
    }
};