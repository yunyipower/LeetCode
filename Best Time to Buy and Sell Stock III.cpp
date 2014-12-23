class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int days=prices.size();
        int LeftMaxPrices[days];
        int RightMaxPrices[days];
        
        int curMinPrice=INT_MAX,curMaxProfit=0;
        for(int i=0;i<days;++i){
            if(prices[i]<curMinPrice)
                curMinPrice=prices[i];
            else curMaxProfit=max(curMaxProfit,prices[i]-curMinPrice);

            LeftMaxPrices[i]=curMaxProfit;
        }

        int curMaxPrice=INT_MIN;curMaxProfit=0;
        for(int i=days-1;i>=0;--i){
            if(prices[i]>curMaxPrice)
                curMaxPrice=prices[i];
            else curMaxProfit=max(curMaxProfit,curMaxPrice-prices[i]);
            
            RightMaxPrices[i]=curMaxProfit;
        }

        for(int i=0;i<days;++i)
            curMaxProfit=max(curMaxProfit,LeftMaxPrices[i]+RightMaxPrices[i]);

        return curMaxProfit;
    }
};
