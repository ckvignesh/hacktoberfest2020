#include <bits/stdc++.h>
typedef long long int lli;
typedef long double ldb;
 
#define endl '\n'
#define loop(i, m, n) for (lli i = m; i < n; i++)
#define loope(i, m, n) for (lli i = m; i <= n; i++)
#define epool(i, m, n) for (lli i = m; i >= n; i--)
#define pool(i,m,n) for(lli i=m; i>n; i++)
#define maxe *max_element
#define mine *min_element
#define plli pair<lli, lli>
#define mod 1000000007
#define mod2 998244353
#define vt vector<lli>
#define fi first
#define se second
#define pb push_back
#define umap unordered_map
#define mmap multimap
#define mp make_pair
#define inp1(a) cin >> a
#define inp2(a, b) cin >> a >> b
#define inp3(a, b, c) cin >> a >> b >> c
#define inp4(a, b, c, d) cin >> a >> b >> c >> d
#define inp5(a, b, c, d, e) cin >> a >> b >> c >> d >> e
#define inp6(a, b, c, d, e, f) cin >> a >> b >> c >> d >> e >> f
#define pr0() cout << " "
#define pr1(a) cout << a << " "
#define pr2(a, b) cout << a << " " << b << " "
#define pr3(a, b, c) cout << a << " " << b << " " << c << " "
#define pr4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << " "
#define emp emplace //used to push a pair etc..
#define empf emplace_front
#define empb emplace_back
#define ret(x) return cout << x, 0;
#define all(v) v.begin(),v.end()
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//especially for deque both sides dynamic
#define pf push_front
//list doubly linked lists can insert at mid. splice fn can be used
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
 
lli gcd(lli a, lli b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
lli lcm(lli a, lli b){
    return (a * b) / gcd(a, b);
}
 
lli modi( lli n, lli m=mod ){ 
    n%=m;
    n+=m;
    n%=m;
    return n;
}
 
lli fib(lli n){ 
  double phi = (1+sqrt(5))/2; 
  return round(pow(phi,n)/sqrt(5)); 
} 
 
lli fibn(lli n){
    if (n == 0 || n == 1)
        return 1;
    else{
        lli arr[n + 1];
        arr[0] = 0;
        arr[1] = 1;
        for (lli i = 2; i <= n; i++){
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
    }
}
 
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){ 
    return (a.second < b.second); 
}
 
bool sortinrev(const pair<int,int> &a, const pair<int,int> &b){ 
       return (a.first > b.first); 
}
 
bool sortbysecdesc(const pair<int,int> &a,const pair<int,int> &b){ 
       return a.second>b.second; 
}
 
lli mpow(lli base, lli exp){
    base %= mod2;
    lli result = 1;
    while (exp > 0){
        if (exp & 1)
            result = ((lli)result * base) % mod2;
        base = ((lli)base * base) % mod2;
        exp >>= 1;
    }
    return result;
}
 
lli modInverse(lli n) { 
    return mpow(n, mod2-2); 
}
 
lli nCr(lli n, lli r){ 
   if (r==0) 
      return 1; 
    lli fac[n+1]; 
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%mod2; 
    return (fac[n]* modInverse(fac[r]) % mod2 * 
            modInverse(fac[n-r]) % mod2) % mod2; 
}
 
lli is_prime(lli a){
    lli i;
    if (a == 2 || a == 3)
        return 1;
    else
        for (i = 2; i * i <= a; i++){
            if (a % i == 0)
                return 0;
        }
    return 1;
}
 
lli digsum(lli n){
    return floor(log10(n)) + 1;
}
 
#define MAX 500 
  
lli multiply(lli x,lli res[],lli res_size); 
 
lli factorial(lli n) { 
    lli res[MAX]; 
    res[0] = 1; 
    lli res_size = 1; 
    for(lli x=2; x<=n; x++) 
        res_size = multiply(x, res, res_size); 
    for (lli i=res_size-1; i>=0; i--) 
        cout << res[i]; 
} 
 
lli multiply(lli x,lli res[],lli res_size) { 
    lli carry = 0;   
    for (lli i=0; i<res_size; i++) { 
        lli prod = res[i] * x + carry;   
        res[i] = prod % 10;   
        carry  = prod/10;     
    } 
    while (carry) { 
        res[res_size] = carry%10; 
        carry = carry/10; 
        res_size++; 
    } 
    return res_size; 
}
 
lli binsearch(lli arr[], lli l, lli r, lli no){
    while (l <= r){
        lli mid = (l + r) / 2;
        if (arr[mid] == no)
            return mid;
        else if (arr[mid] < no)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
 
string sortString(string &str){
    lli i = 0, j = 0, k = 0;
    lli charCount[26] = {0};
    loop(i, 0, str.length())
        charCount[str[i] - 'a']++;
    loop(i, 0, 26){
        loop(j, 0, charCount[i]){
            str[k++] = char('a' + i);
        }
    }
    return str;
}
 
const lli N=2e5+5;
bool vis[N];
vt adj[N];
lli lev[N];
 
vt primesv(lli n){
    vt v;
    lli x=n;
    loope(i,2,sqrt(n)+1){
        if(x%i==0){
            x=x/i;
            v.pb(i);
        }
    }
    return v;
}

void init(lli arr[], lli size[], lli n){
    loope(i,1,n){
        arr[i]=i;
        size[i]=1;
    }
}

// bool find(lli arr[], lli a, lli b){
//     if(arr[a]==arr[b]) return true;
//     else return false;
// }

// void union(lli arr[], lli n, llia, lli b){
//     lli temp=arr[a];
//     loop(i,0,n){
//         if(arr[i]==temp) arr[i]=arr[b];
//     }
// }

lli root(lli arr[], lli s){
    while(arr[arr[s]]!=s){
        s=arr[arr[s]];
    }
    return s;
}

// void union1(lli arr[], lli a,lli b){
//     lli roota=root(arr,a);
//     lli rootb=root(arr,b);
//     arr[roota]=rootb;
// }

// bool find(lli a, lli b){
//     if(root(arr,a)==root(arr,b)) return true;
//     else return false;
// }

void weighted_union(lli* arr,lli* size, lli a, lli b){
    lli roota=root(arr,a);
    lli rootb=root(arr,b);
    //cout << size[roota] << " " << size[rootb] << endl;
    if(size[roota]<size[rootb]){
        arr[roota]=arr[rootb];
        size[rootb]+=size[roota];
    //    size[roota]=1;
    }
    else{
        arr[rootb]=arr[roota];
        size[roota]+=size[rootb];
    //    size[rootb]=1;
    }
}

void bfs(lli s){
    queue<lli> q;
    q.push(s);
    lev[s]=0;
    vis[s]=1;
    while(!q.empty()){
        lli cur=q.front();
        q.pop();
        loop(i,0,v[cur].size()){
            if(vis[v[cur][i]]==0){
                lev[v[cur][i]]=lev[cur]+1;
                q.push(v[cur][i]);
                vis[v[cur][i]]=1;
            }
        }
    }
}

int32_t main(){
    fast_io
    lli i = 0,j = 0;
//   freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
    
}
