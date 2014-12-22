class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int curMinPrice=0,curMaxPrice=0,iMaxProfit=0;
        for(int i=0;i<prices.size();++i){
            if(i==0) curMinPrice=prices[i];
            else{
                if(prices[i]>curMinPrice&&prices[i]>curMaxPrice)
                    curMaxPrice=prices[i];
                else{
                    iMaxProfit += max(curMaxPrice-curMinPrice,0);
                    curMinPrice = prices[i];
                    curMaxPrice = prices[i];
                }
            }
        }
        iMaxProfit += max(curMaxPrice-curMinPrice,0);
        return iMaxProfit;
    }
};
