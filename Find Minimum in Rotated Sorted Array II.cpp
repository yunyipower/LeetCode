class Solution {
public:
    int GetPriNum(vector<int> &vi,int index_bound,int index)
    {
        int i = index -1,data = vi[index];
        while(i>=index_bound){
            if(vi[i]==data) --i;
            else return vi[i];
        }
        return vi[i+1];
    }

    int GetNextNum(vector<int> &vi,int index_bound,int index)
    {
        int i = index +1,data = vi[index];
        while(i<=index_bound){
            if(vi[i]==data) ++i;
            else return vi[i];
        }
        return vi[i-1];
    }

    int Find_Min_Recursion(vector<int> &vi,int index_left,int index_right){
        if(index_left>index_right){
            return INT_MAX;
        }else if(index_left==index_right){
            return vi[index_left];
        }

        int vi_index_mid = index_left + ((index_right-index_left)>>1);
        if(vi_index_mid==index_left) return min(vi[index_left],vi[index_right]);

        if(GetPriNum(vi,index_left,vi_index_mid) > vi[vi_index_mid]){
            return vi[vi_index_mid];
        }else if(GetPriNum(vi,index_left,vi_index_mid) == vi[vi_index_mid]){
            Find_Min_Recursion(vi,vi_index_mid,index_right);
        }else if(vi[vi_index_mid] > GetNextNum(vi,index_right,vi_index_mid)){
            return GetNextNum(vi,index_right,vi_index_mid);
        }else if(vi[vi_index_mid] == GetNextNum(vi,index_right,vi_index_mid)){
            Find_Min_Recursion(vi,index_left,vi_index_mid);
        }else if(vi[index_right] < vi[vi_index_mid]){
            return Find_Min_Recursion(vi,vi_index_mid+1,index_right);
        }else{
            return Find_Min_Recursion(vi,index_left,vi_index_mid);
        }
    }

    int findMin(vector<int> &num) {
        Find_Min_Recursion(num,0,num.size()-1);
    }
};