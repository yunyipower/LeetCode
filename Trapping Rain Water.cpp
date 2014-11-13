class Solution {
public:
    int trap(int A[], int n) {
        int iret=0;
        int *pleftcolumn = new int[n];
        int *prightcolumn = new int[n];

        int statenum = 0;
        for(int i=0;i<n;++i){
            pleftcolumn[i] = statenum;
            statenum = statenum<A[i]?A[i]:statenum;
        }
        statenum = 0;
        for(int i=n-1;i>=0;--i){
            prightcolumn[i] = statenum;

            if(A[i]<prightcolumn[i] && A[i]<pleftcolumn[i]){
                iret += min(prightcolumn[i],pleftcolumn[i])-A[i];
            }
            statenum = statenum<A[i]?A[i]:statenum;
        }

        delete []pleftcolumn;
        delete []prightcolumn;

        return iret;
    }
};