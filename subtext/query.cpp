#include <bits/stdc++.h>
using namespace std;
const int MAX = 200005;
long long a[MAX], tree[4*MAX];

void biuld(int id, int l, int r){
	if (l == r)
		{
		tree[id] = a[l];
		return;
		}
	int mid = (l+r) /2;
	biuld(id * 2, l, mid );
	biuld(id * 2 +1, mid +1, r);
	tree[id] = min(tree[id*2] , tree[id*2+1]);
}
void update(int id, int l , int r, int pos, long long val){
	if (l == r){
		tree[id] = val;
		return;
	}
	int mid = (l+r) /2;
	if ( pos <= mid)
	{
		update(id*2, l, mid, pos, val);
	}
	else 
		update(id*2+1, mid+1, r, pos, val);
	tree[id] = min(tree[id*2] , tree[id*2+1]);
}
long long query(int id, int l , int r, int u, int v){
	if (u > r || v < l){
		return 1e10+1;
	}
	if (l >= u && r <= v){
		return tree[id];
	}
	int mid = (l+r) /2;
	return min(query(id *2 ,l, mid, u,v ),query(id*2+1, mid+1, r, u,v));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , q ;
    cin >> n>> q;
    for(int i = 1; i <= n ; i++){
    	cin >> a[i];
    }
    biuld(1, 1, n);
    for(int i = 1 ; i <= q; i++){
    	int x, l, r;
    	cin >> x >> l >> r;
    	if (x == 2)
    		cout	<< query(1, 1, n, l, r)<<'\n';
    	else 
    		update(1, 1, n, l, r);
    }


    return 0;
}