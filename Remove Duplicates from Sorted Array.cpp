class Solution {
public:
    int removeDuplicates(int A[], int n) {
	if(n<=0) return 0;
        int i=0,j=0;
        while(++j<n)
            if(A[j]!=A[i]) A[++i]=A[j];
        return i+1;
    }
};
