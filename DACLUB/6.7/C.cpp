#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(const int& a, const int&b){
    return a<b;
}
int binary_search(vector<int> d,int target){
    int left=0,right=d.size();
    int mid;
    while(left<right){
        mid=(left+right)/2;
        if(d[mid]==target) return mid;
        else if (d[mid]<target) left=mid+1;
        else right=mid;
    }
    if(d[mid]==target) return mid;
    else return -1;
}
int main(){
    vector <int> d;
    int k;
    cin>>k;
    while(k>0){
        d.clear();
        int n;
        cin>>n;
        int a[n+1],b[n+1];
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        vector<int> c;
        for(int i = 1; i <= n; i++){
            cin>>b[i];
            c.emplace_back(b[i]);
        }
        sort(c.begin(),c.end(), compare);
        int m;
        cin>>m;
        for(int i=1;i<=m;i++){
            int x;
            cin>>x;
            d.emplace_back(x);
        }
        int f= true;
        sort(d.begin(),d.end(), compare);
//        for(int i=0;i<d.size();i++) cout<<d[i]<<' ';
        for(int i=1;i<=n;i++) {
            if (a[i]!=b[i]){
                int mid = binary_search(d, b[i] );
                cout<<mid<<endl;
                if ( mid != -1) {
                    for (int j = mid; j < d.size() - 1; j++) { d[j] = d[j + 1]; }
                    d.pop_back();
                } else {
                    f = false;
                    break;
                }
            }
        }
//        for(int i=0;i<d.size();i++){
//            if(binary_search(c,d[i])==-1) {
//                f=false;
//                cout<<d[i];
//            }
//        }
        if(f) { cout << "YES" << endl; }
        else cout<<"NO"<<endl;
        k--;
    }
    return 0;
}