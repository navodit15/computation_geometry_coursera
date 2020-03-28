#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i = a ; i <= b ; ++i)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define fst first
#define snd second
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}
typedef long long ll;typedef pair<int, int> pii;typedef vector<int> vi;typedef long double ld;
template<class T> ostream& operator<<(ostream &os, vector<T> V) {os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class T> ostream& operator<<(ostream &os, set<T> S){os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {os << "{ "; for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") "; return os<<"}";}
namespace fio{
	template <typename T> void scan(T &x) { cin >> x ;}
	template<class T> void scan(vector<T>& a);
	template<class T> void scan(vector<T>& a) { rep(i,0,sz(a)) scan(a[i]); }
	template<class T, class... Ts> void scan(T& t, Ts&... ts) { scan(t); scan(ts...);}
	template <typename T> void print(T x) { cout << x << endl;}
	template<class T, class... Ts> void print(const T& t, const Ts&... ts) { print(t); print(ts...); }
} 
using namespace fio; 
   
#ifdef np
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>void __f(const char *name, Arg1 &&arg1) { cout<<name<<" : "<<arg1<<endl;}
template<typename Arg1, typename ... Args>void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    const char *comma=strchr(names+1,','); cout.write(names,comma-names)<<" : "<<arg1<<" | ";
    __f(comma+1,args...);
}
#else
#define trace(...)
#define endl '\n'
#endif


double INF = 1e100;
double EPS = 1e-12;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}
 
bool LinesCollinear(PT a, PT b, PT c, PT d) { 
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}
 
// position of point P wrt line a----b 
double Pos_wrt_line(PT a , PT b , PT p){
	ld res = ((p.x-a.x)*(b.y-a.y))-((p.y-a.y)*(b.x-a.x));
	return res;
}
ld dist(PT a , PT b){
	int d = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) ;
	return sqrt(d);
}
bool online(PT a , PT b , PT c){
	if(dist(a,c) + dist(c,b) == dist(a,b)) return true;
	return false;
}

bool onseg(PT A, PT B, PT C) {
   if (A.x == C.x) return B.x == C.x;
   if (A.y == C.y) return B.y == C.y;
   return (A.x - C.x)*(A.y - C.y) == (C.x - B.x)*(C.y - B.y);
}

PT a,b;


signed main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
	
//https://math.stackexchange.com/questions/274712/calculate-on-which-side-of-a-straight-line-is-a-given-point-located
	
	scan(a.x , a.y , b.x , b.y);
	int m ; scan(m) ; while(m--){	
		PT p ;
		scan(p.x , p.y);
		ld cr = Pos_wrt_line(a,b,p) ;
		if(cr > 0) print("RIGHT");
		if(cr < 0) print("LEFT");
		if(cr == 0 and ceil(dist(a,b)) == ceil(dist(a,p)+dist(p,b)) ){ print("ON_SEGMENT") ; continue;}
		if(cr ==0 and dist(a,b) != (dist(a,p)+dist(p,b))) {print("ON_LINE"); continue;}

	}






#ifdef np
    cerr <<endl<<endl<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif  
 return 0; 
 }
