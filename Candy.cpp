class Solution {
public:
    int candy(vector<int> &ratings) {
        int mincandies = 0;
        int *pcandies = new int[ratings.size()];
        for(int i=0;i<ratings.size();++i){
            pcandies[i]=0;
        }

        int i=0;
        while(i<ratings.size()){
            for(int k=i;k<ratings.size();++k){
                if((k+1)<ratings.size() && ratings[k]>ratings[k+1]) continue;
                else{
                    pcandies[k]=1;
                    for(int j=k-1;j>=i;--j){
                        if(ratings[j]>ratings[j+1]) pcandies[j]=pcandies[j+1]+1;
                        else pcandies[j]=pcandies[j+1];
                    }

                    if(i-1>=0 && pcandies[i]<=pcandies[i-1]){
                        if(ratings[i]>ratings[i-1]) pcandies[i]=pcandies[i-1]+1;
                         
                        for(int j=i+1;j<=k;++j){
                            if(ratings[j]>ratings[j-1]) pcandies[j]=pcandies[j-1]+1;
                        }
                    }

                    i=k+1;
                }
            }
        }

        for(int i=0;i<ratings.size();++i){
            mincandies += pcandies[i];
        }
        delete []pcandies;

        return mincandies;
    }
};