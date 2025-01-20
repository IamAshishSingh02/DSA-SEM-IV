#include<iostream>
using namespace std;
void insert(int ar[10][2],int key){
    int m=key%10;
    if(ar[m][0]==-1){
        ar[m][0]=key;
    }
    else if(ar[m][1]==-1){
        int yu=m+1;
        while(ar[yu][0]!=-1){
            yu=(yu+1)%10;
        }
        ar[m][1]=yu;
        ar[yu][0]=key;
    }
    else if(ar[m][1]!=-1&&ar[m][0]%10==m){
        int uy=ar[m][1];
        int se;
        int q;
        while(uy!=-1){
            se=ar[uy][0];
            q=uy;
            uy=ar[uy][1];
        }
        while(ar[se][0]!=-1){
            se=(se+1)%10;
        }
        ar[se][0]=key;
        ar[q][1]=se;
    }
    else if (ar[m][0]%10!=m){
        int ru=ar[m][0];
        int gh=m;
        while(ar[gh][0]!=-1){
            gh=(gh+1)%10;
        }
        int fg=ar[m][1];
        for(int i=0;i<10;i++){
            if(ar[i][1]==m){
                ar[i][1]=gh;
            }
        }
        ar[gh][0]=ru;
        ar[gh][1]=fg;
        ar[m][0]=key;
        ar[m][1]=-1;
    }
}
 
void display(int arr[10][2]){
    for(int i=0;i<10;i++){
        cout<<"("<<arr[i][0]<<","<<arr[i][1]<<")"<<" ";
    }
    cout<<endl;
}
 
int main(){
    int arr[10][2];
    for (int i=0;i<10;i++){
        arr[i][0]=-1;
        arr[i][1]=-1;
    }
    while(true){
        display(arr);
        cout<<"Enter key : ";
        int e;
        cin>>e;
        insert(arr,e);
    }
}