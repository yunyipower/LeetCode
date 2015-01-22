class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
	int rownum=dungeon.size(),colnum=rownum>0?dungeon[0].size():0;
	if(rownum==0||colnum==0) return 0;

	vector<vector<int> > health_grid(rownum, vector<int>(colnum,0));

	health_grid[rownum-1][colnum-1]=1-min(dungeon[rownum-1][colnum-1],0);

	for(int i=rownum-2;i>=0;--i)
	    health_grid[i][colnum-1]=max(1,health_grid[i+1][colnum-1]-dungeon[i][colnum-1]);

	for(int j=colnum-2;j>=0;--j)
	    health_grid[rownum-1][j]=max(1,health_grid[rownum-1][j+1]-dungeon[rownum-1][j]);

	for(int i=rownum-2;i>=0;--i)
	    for(int j=colnum-2;j>=0;--j)
		health_grid[i][j]=max(1,min(health_grid[i+1][j],health_grid[i][j+1])-dungeon[i][j]);
	
	return health_grid[0][0];
    }
};
