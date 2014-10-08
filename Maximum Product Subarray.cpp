class Solution {
public:
    int maxProduct(int A[], int n) {

        int largestproduct = INT_MIN;
        int maxi=1,mini=1;

        for(int i=0;i<n;++i){
            int oldmaxi = max(maxi,1);

            if(A[i]>0){
                maxi = oldmaxi * A[i];
                mini *= A[i];
            }else{
                maxi = mini*A[i];
                mini = oldmaxi*A[i];
            }

            largestproduct = max(largestproduct,maxi);
        }
        return largestproduct;
    }
};