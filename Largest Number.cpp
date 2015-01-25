class Solution {
public:
    bool needSwap(int a,int b){
        stringstream strStream1,strStream2;      
        strStream1<<a<<b;
	strStream2<<b<<a;
        string strab=strStream1.str();
	string strba=strStream2.str();

        if (strab.compare(strba)>=0) return false;
        else return true;
    }

    string largestNumber(vector<int> &num) {
        int iSize=num.size();
        if(iSize==0) return "";
        string strRet;
        
        for(int i=1;i<iSize;++i){
            int j=i;
            while(j-1>=0&&needSwap(num[j-1],num[j])){
                swap(num[j],num[j-1]);
		--j;
	    }
        }
	
	if(num[0]==0) return "0";        
	
	string str;
        for(int i=0;i<iSize;++i){
            stringstream strStream;  
   	    strStream<<num[i];  
            string str=strStream.str(); 
            strRet+=str;
        }
            
        return strRet;
    }
};
