struct RMQ{
	int mxn,K,N;
	vector<int>log;
	vector<vector<int>>st;
	RMQ(int n):mxn(n+5),K(25),N(n){
		log.resize(mxn);
		st.resize(mxn,vector<int>(K));
	};
	void build(){
		log[1] = 0;
		for (int i = 2; i <= mxn; i++)
	    log[i] = log[i/2] + 1;
		
		for (int i = 0; i < N; i++)
	    	st[i][0] = a[i];

		for (int j = 1; j <= K; j++)
	    	for (int i = 0; i + (1 << j) <= N; i++)
	        	st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
	}
	int query(int L,int R){
		int j = log[R - L + 1];
		return min(st[L][j], st[R - (1 << j) + 1][j]);
	}
};
