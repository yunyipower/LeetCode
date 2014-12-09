class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int iSize=gas.size(),iRet=-1,iGasLeft=0;
        
        for(int i=0;i<iSize;++i)
            iGasLeft+=gas[i]-cost[i];
        
        if(iGasLeft<0) return iRet;
        else{
            iGasLeft=0;
            iRet=0;
        } 
        
        for(int i=0;i<iSize;++i){
            iGasLeft+=gas[i]-cost[i];
            if(iGasLeft<0){
                iGasLeft=0;
                iRet=i+1;
            }
        }
        return iRet;
    }
};
