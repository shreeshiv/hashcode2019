#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back

/*
author@ the Tufan 
Patel shreeshiv
*/
struct pic {
  int in;
	char ori;
	int m;
	std::vector<string> v;
};
bool com(struct pic a,struct pic b){
  std::vector<string> v1=a.v;
  std::vector<string> v2=b.v;
  int n=v1.size();
  int m=v2.size();
  sort(v1.begin(),v1.end());
   sort(v2.begin(),v2.end());
  int sim=0;
  int i=0;
  int j=0;

  while(i<n&&j<m){
    if(v1[i]==v2[j]){
      sim++;
      i++;
      j++;
    }
    else if(v1[i]>v2[j])j++;
    else i++;
  }


  if(sim>4)return true;
  else return false;

}
int fun(vector<string> a,vector<string >b){
  int i=0;
  int j=0;
  int n=a.size();
  int m=b.size();
  int ans=0;
  while(i<n&&j<m){
    if(a[i]==b[j]){
      ans++;
      i++;
      j++;
    }
    else if(a[i]>b[j]){
      j++;
    }
    else i++;
  }


return ans;
}
bool comNum(struct pic a, struct pic b){
      if(a.v.size()>b.v.size())return true;
      else return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream in; 
    ofstream out;
    in.open("cin.txt");
    out.open("cout.txt");

   	int n;
   	in>>n;
   	string s;
   	struct pic arr[n];

   	int m;
   	char ch;
   	std::vector<int> slideH;
   	std::vector<int> slideV;

   	for(int i=0;i<n;i++){
   		in>>ch;
   		if(ch=='H')slideH.pb(i);
   		else slideV.pb(i);
   		in>>m;
   		std::vector<string> vec;
   		for(int j=0;j<m;j++){
   			in>>s;vec.pb(s);
   		}
      sort(vec.begin(),vec.end());
   		arr[i]=(pic){i,ch,m,vec};
   	}

   	int ans=slideH.size()+slideV.size()/2;
    struct pic arrH[slideH.size()];
    int count=0;

      struct pic arrV[slideV.size()];
    for(int i=0;i<slideH.size();i++){
        arrH[i]=arr[slideH[i]];
       // sort(arrH[i].v.begin(),arrH[i].v.end());
    } 

     for(int i=0;i<slideV.size();i++){
        arrV[i]=arr[slideV[i]];
       // sort(arrV[i].v.begin(),arrV[i].v.end());
    } 
    int nH=slideH.size();
    int nV=slideV.size();



  //  sort(arrH,arrH+nH,comNum);
     //   sort(arrV,arrV+nV,comNum);

    
struct pic temp;
    for(int i=0;i<nH;i++){
      int min=i+1;
      int count=0;
      std::vector<string> vv=arrH[i].v;
      int t1;
        for(int j=i+1;j<nH;j++){
          t1=fun(vv,arrH[j].v);
          if(t1>=count){
            min=j;
            count=min;
          }
        }
        temp=arrH[i+1];
        arrH[i+1]=arrH[min];
        arrH[min]=temp;

    }

   	out<<ans<<"\n";
        for(int i=0;i<nH;i++)out<<arrH[i].in<<"\n";

        for(int i=0;i+1<nV;i=i+2)out<<arrV[i].in<<" "<<arrV[i+1].in<<"\n";


in.close();
out.close();

    return 0;
}