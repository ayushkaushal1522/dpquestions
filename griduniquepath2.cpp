// a space optimised code will work on the codestudio platform.
// which is this given below the only shuttle change is that we can not move to the cell containing -1 just 
// return from there only.


int uniquePaths(int m, int n ,vector< vector< int> > &mat) {
	// Write your code here.
        int mod = 1e9+7;
	    vector<int> prev(m,0);
	    prev[0]=1;
        for (int i = 0; i < n; i++) {
          vector<int> curr(m,0);
          for (int j = 0; j < m; j++) {
            if(mat[i][j]==-1) curr[j]=0;
			else if(i==0 && j==0) curr[j]=1;
            else{
				int left=0;
				int up=0;
				if(j>0) left = curr[j-1];
				if(i>0) up= prev[j];
				curr[j] = (left+up)%mod;
            }
          }
          prev=curr;
        }
		return prev[m-1];
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    return uniquePaths(m ,n ,mat);
}


