template<typename T>
struct segtree {
	const int n,no_op=INT_MAX;
    vector<T> operations;
    segtree(int n) : n(n), operations(4*n,0) {}
	void propagate(int x,int l,int r){
		if(operations[x]==no_op||r-l<2)return;

		operations[2*x]=operations[x];
		operations[2*x+1]=operations[x];
		operations[x]=no_op;
	}

	void change(int x,int y,int v,int id,int l,int r){//add from x to y
		
		if(x >= r or l >= y)	return ;
		if(x <= l && r <= y){
			operations[id]=v;
			return;
		}
		propagate(id,l,r);
		
		int mid = (l+r)/2;
		
		change(x, y,v, id * 2, l, mid);
		
		change(x, y, v,id * 2 + 1, mid, r);
	}


	T get(int i,int id,int l,int r){//sum from x to y
		
		if(r-l<2)	return operations[id];
		
		int mid = (l+r)/2;

		T mx;
		propagate(id,l,r);

		if(i<mid)
		mx =get(i, id * 2, l, mid);
		else
		mx=get(i, id * 2 + 1, mid, r);
		
		return mx;


	}
};
