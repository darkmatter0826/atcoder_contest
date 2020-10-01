#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>


/* 
*    coder :: ATUL_PANDEY_2608
*        >>> INDIA <<<
*/	
using namespace std;
using namespace __gnu_pbds;

// #define  part ..
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end() 
#define mod 1000000007
//#define maxx 200006
#define ll long long 
#define quick    ios_base::sync_with_stdio(NULL),cin.tie(0);
#define listll vector< long long > 
#define listi vector< int> 
#define pii   pair<int , int> 
#define pll pair<long long , long long > 
#define minheap priority_queue<long long , vector< long long >, greater<long long > >
#define rep(i,a,b) for(int i=a;i<b;i++)

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

ll power( ll a, ll n, ll m= 1000000007){
  ll ans = 1;
  while(n){
  if(n&1)
  {
  ans *= a;
  ans%=m;
  }
  a*=a;
  a%=m;
  n/=2;
  }
  return ans ;
} 


vector< int > prm ;
vector < bool > vsp ;

void prime ( int nn = 100000 ) {
	vsp = vector < bool > ( nn+1, 0 );
	int size_prime = nn;
	for( ll i =2; i*i < size_prime ; i++){
		
		if( vsp[i] == 1)
		continue;
		for(ll j = i*i; j < size_prime ;j+=i){
			
			vsp[j] =1;
			
		}
		
		
	}
	
	for( int i= 2; i < size_prime ; i++)
	if (vsp[i] == 0)
	prm.pb(i);
	
	
}


template < class T > using oset = tree< T , null_type, less  < T  > , rb_tree_tag , tree_order_statistics_node_update > ;


// end of #define 

// define globals ...
const int maxx = 2e5+26;

//write function from here ...
// never forget  to recheck your predefined function in template .. 
// already defined ::  prime , power , gcd : ( ll ).. 








int Main(){
   int n ,m;
   cin>>n>>m;
   set < int > arr ;
   multiset < int > dif ;

   

   // add diff if left and right exist 
  //  remove diff if 
   
   auto  addNew = [&]( int u ){
	  auto itr = arr.insert(u );
	   assert( itr .second);
	   auto it  = itr.first ;
	   
      if( arr.begin() != it && arr.end() != next(it ) ){
		  int di = *next(it) - *prev( it ) ;
		   
		  dif .erase (dif.find(di ) ) ;
		   
	  } 
	  
	
	if( next(it) != arr.end()){
		int temp = *next( it) - u ;
		dif.insert(temp );
		
	}
	
	if( it!= arr.begin() ){
		int temp  = u - *prev( it);
		dif.insert( temp );
	}
	
	
	
	
	   
   };
   auto removeOne = [&]( int u){
	   auto fd = arr.find(u);
	   assert(fd!=arr.end());
	   if( next(fd)  != arr.end() ){
		   
		   int temp = *next(fd)- *fd ;
		   dif.erase( dif.find( temp)) ;
		   
	   }
	   if( fd!= arr.begin()){
		   int temp = *fd - * prev(fd);
		   dif.erase( dif.find( temp)); 
	   }
	   
	   if( fd != arr.begin() && next(fd ) != arr.end()){
		   int temp = *next( fd ) - *prev(fd ); 
		   dif.insert( temp ) ;
	   }
	   arr.erase( fd);
	   
	   
   };
   
   
      for(int i =0 ; i < n ; i ++)
   {
	   int a;
	   cin>>a;
	   addNew(a);	   
   }
   
   while(m>=0){
	   int a;
	   if( dif.empty()){
		   cout<<0<<endl;
	   }
	   else
	   {
	   auto anss= arr.end();
	   auto diff = dif.end();
	   cout<<(  *prev(anss)- *arr.begin()  - *prev(diff)) <<endl;;
       }
	   
	   
	   if(m==0)
	   break; 
	   cin>>a;
	   if(a== 1){
		   
		   int b;
		   cin>>b;
		   addNew(b);
		   
		   
	   }else{
		   
		   int b;
		   cin>>b;
		   
		   removeOne( b);
		   
		   
	   }
	   
	   
	   
	   
	  m--;
   }
  
  
return 0;

}






int main(){
 quick;
int t =1; 
//cin>>t;
while(t-- )
 Main();

 return 0;
}


  



