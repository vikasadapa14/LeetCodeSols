class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int profit=0;
     int mini=prices[0];
     int maxprofit=0;
     for(int i=0;i<prices.size();i++){
        mini=min(mini,prices[i]);
        profit=prices[i]-mini;
        maxprofit=max(maxprofit,profit);
     }
     return maxprofit;
    }
};