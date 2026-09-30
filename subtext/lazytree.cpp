#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
long long tree[4 * MAX], lazy[4 * MAX];
int a[MAX];
void biuld(int id, int l, int r){
	if (l == r){
		tree[id] = a[l];
		return ;
	}
	int mid = (l+r) / 2;
	biuld(id*2, l, mid);
	biuld(id*2 +1, mid+1, r);
	tree[id] = tree[id*2] + tree[id*2 +1 ];
}
void push(int id, int l, int r){
	if (lazy[id] == 0 || l == r){
		return;
	}
	int mid = (l+r) /2;
	long long x = lazy[id];

	tree[id*2] += x * (mid - l +1);
	lazy[id*2] += x;

	tree[id*2 +1] += x * (r - mid);
	lazy[id*2 +1] += x;

	lazy[id] = 0;
}
void update(int id, int l, int r, int u, int v, long long val){
	if (u > r || v < l){
		return;
	}
	if (l >= u && r <= v){
		tree[id] += val* (r-l +1);
		lazy[id] += val;
		return;
	}
	push(id,l,r);
	int mid = (l + r ) /2;
	update(id*2, l, mid, u, v, val);
	update(id*2+1, mid+1, r, u, v, val);
	tree[id] = tree[id*2] + tree[id*2+1];
}
long long query(int id, int l, int r, int u, int v){
	if (u > r || v < l){
		return 0;
	}
	if (l >= u && r <= v){
		return tree[id];
	}
	push(id,l,r);
	int mid = (l + r) /2;
	return query(id*2, l, mid, u,v )+ query(id*2 +1, mid+1, r, u,v);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
  	while(t--){
    int n, q;
    cin >>n>>q; 
    biuld(1,1,n);
        for(int i = 1; i <= q ; i++){
        	int type, l, r;
        	cin >>type >> l >> r;
       		if (type == 0) {
       			int val;
       			cin >> val;
       			update(1, 1, n, l,r, val);
       		}
       			else{
       				cout << query(1, 1,n,l,r) <<'\n';
       			}
        }
    }

    return 0;
}