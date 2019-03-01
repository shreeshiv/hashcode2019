#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
struct node{
	char ori;
	int in;
	int m;
	std::vector<int> v;
};
int strToInt(string s ){
	int n=s.length();
	int ans=0;
	for(int i=0;i<n;i++){
		ans=ans*10;
		ans+=(s[i])%10;
	}


	if(ans<0)ans=0;


	return ans;
}
int fun(std::vector<int> a,vector<int>b){
	int ans=0;

	int i=0;
	int j=0;
	int n=a.size();
	int m=b.size();

	while(i<n&&j<m){
		if(a[i]==b[j]){
			ans++;
			i++;
			j++;
		}
		else if(a[i]>b[j]){
			j++;
		}
		else{
			i++;
		}
	}
	j=min(n-ans,m-ans);
	return min(ans,j);
}
int main(){	
	ifstream in;
	ofstream out;
	in.open("ein.txt");
	out.open("eout.txt");
	int n;
	in>>n;
	int nH=0;
	int nV=0;
	char ch;
	string s;
	int t1,t2;
	int m;
	struct node arr[n];
	std::vector<int> vHH;
	std::vector<int> vVV;
	for(int i=0;i<n;i++){
			in>>ch;
			if(ch=='H'){nH++;vHH.pb(i);}
			else {nV++;vVV.pb(i);}

			in>>m;
			
			std::vector<int> vv;
			for(int j=0;j<m;j++){
				in>>s;
				t1=strToInt(s);
				vv.pb(t1);
			}
			sort(vv.begin(),vv.end());
			arr[i]=(node){ch,i,m,vv};
	}
	struct node arrV[nV];
	struct node arrH[nH];
	for(int i=0;i<nH;i++){
		arrH[i]=arr[vHH[i]];
	}
		for(int i=0;i<nV;i++){
		arrV[i]=arr[vVV[i]];
	}


	for(int i=0;i<nH-1;i++){
		struct node temp;
		int r1,r2;
		std::vector<int> v12=arrH[i].v;
		int min=0;
		int ind=i;
		for(int j=i+1;j<nH&&j<i+100;j++){
			r1=fun(v12,arrH[j].v);
			if(r1>min){
				min=r1;
				ind=i;
			}
		}
		temp=arrH[i+1];
		arrH[i+1]=arrH[ind];
		arrH[ind]=temp;

	}
		int ans=nH+nV/2;

out<<ans<<"\n";
for(int i=0;i<nH;i++)out<<arrH[i].in<<"\n";

	for(int i=0;i+1<nV;i+=2){
		out<<arrV[i].in<<' '<<arrV[i+1].in<<"\n";
	}
	

in.close();
out.close();

	return 0;
}