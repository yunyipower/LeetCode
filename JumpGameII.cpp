class Solution{
public: 
    int jump(int A[], int n){
	int minSteps=0,i=n-1,minIndexCur=n-1;
	for(;i>0;){
	    for(int j=i-1;j>=0;--j)
		if(A[j]>=i-j) minIndexCur=j;
	    ++minSteps;
	    i=minIndexCur;
	}
    	return minSteps;
    }
};
