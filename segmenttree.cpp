template<typename T>
struct segtree {
	const int n;
    vector<T> stree;
    segtree(int n) : n(n), stree(4*n) {}
    void build(int id,int l,int r){//build segment tree
		if(r-l<2){
			stree[id]=a[l];
			return;
		}
		int mid=(l+r)/2;
		build(2*id,l,mid);
		build(2*id+1,mid,r);
		stree[id]=stree[2*id]^stree[2*id+1];
	}
	void modify(int p,T x,int id,int l,int r){//here we change pth position to x(0-based)
		stree[id]^=x;
		if(r-l<2){
			a[p]=x;
			return;
		}
		int mid=(l+r)/2;
		if(mid>p)
		return modify(p,x,2*id,l,mid);
		else
		return modify(p,x,2*id+1,mid,r);
	}
	T query(int x,int y,int id,int l,int r){//sum from x to y
		if(x >= r or l >= y)	return 0;
		if(x <= l && r <= y)	return stree[id];
		int mid = (l+r)/2;
		return query(x, y, id * 2, l, mid)^query(x, y, id * 2 + 1, mid, r);
	}
};
