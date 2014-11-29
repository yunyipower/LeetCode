class Solution{
public:    
    bool canJump(int A[], int n){
	int maxPosCur=0;
	for(int i=0;i<=maxPosCur;++i){
	    if(i+A[i]>=maxPosCur){
		maxPosCur=i+A[i];
		if(maxPosCur>=n-1) return true;
	    }	    
	}
	return false;
    }
};
