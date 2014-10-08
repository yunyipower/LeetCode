class Solution {
public:
    int reverse(int x){
    bool ispositive = x>=0?true:false;
    int data_ret = 0;

    while(x){
		data_ret *= 10;
		int add = x % 10;

		if((ispositive&&(INT_MAX -data_ret)>=add) ||
			(!ispositive&&(INT_MIN -data_ret)<=add))
			data_ret += add;
        	else return -1;//overflow happens
        	x /= 10;
    	}

    	return data_ret;
	}
};