class Solution {
private:
    int rownumber_,colnumber_;

public:
    bool coreExist(vector<vector<char> >&board,string &word,int i,int j,int stri){
	if(board[i][j]==word[stri]){
	    board[i][j]-=26;
	    if(stri==word.length()-1) return true;
	    else if(j+1<colnumber_&&coreExist(board,word,i,j+1,stri+1))
		return true;
	    else if(i+1<rownumber_&&coreExist(board,word,i+1,j,stri+1))
		return true;
	    else if(j-1>=0&&coreExist(board,word,i,j-1,stri+1))
		return true;
	    else if(i-1>=0&&coreExist(board,word,i-1,j,stri+1))
		return true;
	    else board[i][j]+=26;
	    return false;
	}else return false;
    }

    bool exist(vector<vector<char> > &board, string word) {
	rownumber_= board.size();
	colnumber_= rownumber_>0?board[0].size():0;
	if(rownumber_==0||colnumber_==0) return false;
	
	for(int i=0;i<rownumber_;++i){
	    for(int j=0;j<colnumber_;++j){
		if(coreExist(board,word,i,j,0)) return true;
	    }
	}
	return false;
    }
};
