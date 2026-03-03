#include<bits/stdc++.h>
using namespace std;
string uname,upassword;
class Payment{
    public:
        string username,date,fineType;
        double amount,pamount=0;
};
class UserData{
    public:
        string username,password,role="student";
        UserData(){
            ;
        }
};
vector<UserData*> users;
vector<Payment*> payments;
void add_payment(){
    Payment* n=new Payment();
    cout<<"Username:";
    cin>>n->username;
    cout<<"Date(dd/mm/yyyy):";
    cin>>n->date;
    cout<<"Fine Type:";
    cin>>n->fineType;
    cout<<"Amount:";
    cin>>n->amount;
    int flag=0;
    for(auto i:users){
        if( i->username == n->username ){
            payments.push_back(n);
            flag=1;
            cout<<"Payment Added Successfully\n";
            break;
        }
    }
    if(flag == 0)
        cout<<"No User Found\n";
}
void update_payment(){
    string cuname,cufine;
    double amount;
    cout<<"Username:";
    cin>>cuname;
    cout<<"Fine Type:";
    cin>>cufine;
    cout<<"Amount:";
    cin>>amount;
    int flag=0;
    for(auto i:payments){
        if(i->username == cuname && i->fineType == cufine){
            flag=1;
            i->pamount=amount;
            cout<<"Updated Successfully\n";
            break;
        }
    }
    if(flag == 0)
        cout<<"No Pending Payments for the Username "<<cuname<<" with the Fine Type "<<cufine<<endl;
}
void delete_payment(){
    string cuname,cufine;
    double amount;
    cout<<"Username:";
    cin>>cuname;
    cout<<"Fine Type:";
    cin>>cufine;
    int flag=0;
    for(auto i:payments){
        if(i->username == cuname && i->fineType == cufine){
            payments.erase(remove(payments.begin(),payments.end(),i),payments.end());
            flag=1;
            cout<<"Deleted Successfully\n";
            break;
        }
    }
    if(flag == 0)
        cout<<"No Pending Payments for the Username "<<cuname<<" with the Fine Type "<<cufine<<endl;
}
void view_payment(){
    for(auto i:payments){
        cout<<"Username: "<<i->username<<" Date: "<<i->date<<" Fine Type: "<<i->fineType<<" Amount: "<<i->amount<<" Paid Amount: "<<i->pamount<<endl;
    }
}
void FilterFineType(){
    string ft;
    cout<<"Fine Type:";
    cin>>ft;
    for(auto i:payments){
        if(i->fineType == ft)
            cout<<"Username: "<<i->username<<" Date: "<<i->date<<" Fine Type: "<<i->fineType<<" Amount: "<<i->amount<<" Paid Amount: "<<i->pamount<<endl;
    }
}
void FilterStudent(){
    string ft;
    cout<<"Student(Username):";
    cin>>ft;
    for(auto i:payments){
        if(i->username == ft)
            cout<<"Username: "<<i->username<<" Date: "<<i->date<<" Fine Type: "<<i->fineType<<" Amount: "<<i->amount<<" Paid Amount: "<<i->pamount<<endl;
    }
}
void FilterDate(){
    string ft;
    cout<<"Date:";
    cin>>ft;
    for(auto i:payments){
        if(i->date == ft)
            cout<<"Username: "<<i->username<<" Date: "<<i->date<<" Fine Type: "<<i->fineType<<" Amount: "<<i->amount<<" Paid Amount: "<<i->pamount<<endl;
    }
}
void FilterDateRange(){
    string st,ed,cd;
    cout<<"Starting Date:";
    cin>>st;
    cout<<"Ending Date:";
    cin>>ed;
    int flag=0,cdd,cm,cy,std=(st[0]-'0')*10+(st[1]-'0'),stm=(st[3]-'0')*10+(st[4]-'0'),sty=(st[6]-'0')*1000+(st[7]-'0')*100+(st[8]-'0')*10+(st[9]-'0'),edd=(ed[0]-'0')*10+(ed[1]-'0'),edm=(ed[3]-'0')*10+(ed[4]-'0'),edy=(ed[6]-'0')*1000+(ed[7]-'0')*100+(ed[8]-'0')*10+(ed[9]-'0');
    for(auto i:payments){
        flag=0;
        cd=i->date;
        cdd=(cd[0]-'0')*10+(cd[1]-'0');
        cm=(cd[3]-'0')*10+(cd[4]-'0');
        cy=(cd[6]-'0')*1000+(cd[7]-'0')*100+(cd[8]-'0')*10+(cd[9]-'0');
        if(sty <= cy && edy >= cy  && stm <= cm && edm >= cm){
            if(sty == cy && stm == cm){
                if(std > cdd )
                    flag = 1;
            }else if( edy == cy && edm == cm){
                if( edd < cdd)
                    flag =1;
            }
            if(flag == 0)
                cout<<"Username: "<<i->username<<" Date: "<<i->date<<" Fine Type: "<<i->fineType<<" Amount: "<<i->amount<<" Paid Amount: "<<i->pamount<<endl;
        }
    }
}
void admin(){
    int f=1;
    while(f){
        int c;
        cout<<"1.View All Payments\n2.Filter By Fine Type\n3.Filter By Student\n4.Filter By Date\n5.Filter By Date Range\n6.Add Payment \n7.Update Payment\n8.Delete Payment\n";
        cin>>c;
        switch( c ){
            case 1:
                view_payment();
                break;
            case 2:
                FilterFineType();
                break;
            case 3:
                FilterStudent();
                break;
            case 4:
                FilterDate();
                break;
            case 5:
                FilterDateRange();
                break;
            case 6:
                add_payment();
                break;
            case 7:
                update_payment();
                break;
            case 8:
                delete_payment();
                break;
            default:
                cout<<"Logout Successfully\n";
                f=0;
                break;
        }
    }
}
void cashier(){
    int f=1;
    while(f){
        int c;
        cout<<"1.Add Payment \n2.Update Payment\n3.Delete Payment\n";
        cin>>c;
        switch( c ){
            case 1:
                add_payment();
                break;
            case 2:
                update_payment();
                break;
            case 3:
                delete_payment();
                break;
            default:
                cout<<"Logout Successfully\n";
                f=0;
                break;
        }
    }
}
void cview(){
    cout<<"Username:"<<uname<<"\nPassWord:"<<upassword<<endl;
}
void cedit(){
    string cuname,cupass;
    cout<<"Username:";
    cin>>cuname;
    cout<<"password:";
    cin>>cupass;
    for(auto i:users){
        if(i->username == uname){
            i->username=cuname;
            i->password=cupass;
            uname=cuname;
	        upassword=cupass;
            cout<<"Edited Successfully\n";
            break;
        }
    }
}
void student(){
    int f=1;
    while(f){
        int c;
        cout<<"1.View Profile \n2.Edit Profile\n";
        cin>>c;
        switch( c ){
            case 1:
                cview();
                break;
            case 2:
                cedit();
                break;
            default:
                cout<<"Logout Successfully\n";
                f=0;
                break;
        }
    }
}
void login(){
    int f=0;
    cout<<"Username:";
    cin>>uname;
    cout<<"password:";
    cin>>upassword;
    for(auto i:users){
        if( i->username==uname ){
            if( i->password == upassword){
                cout<<"Login Successfully\n";
                f=1;
                if( i->role == "student")
                    student();
                else if( i->role == "admin")
                    admin();
                else if( i->role == "cashier")    
                    cashier();
                break;
            }else{
                cout<<"Username and password missmatch\n";
                f=1;
                break;
            }
        }
    }
    if( f == 0) cout<<"Username Not Found\n";
}
void reg() {
    UserData* n=new UserData();
    cout<<"Username:";
    cin>>n->username;
    cout<<"password:";
    cin>>n->password;
    users.push_back(n);
}
int main(){
    UserData* n=new UserData();
    n->username="Admin";
    n->password="1234";
    n->role="admin";
    users.push_back(n);
    UserData* n1=new UserData();
    n1->username="Cashier";
    n1->password="1234";
    n1->role="cashier";
    users.push_back(n1);
    while(1){
        int c;
        cout<<"1.Registration \n2.Login \n";
        cin>>c;
        if(c == 1)
            reg();
        else if(c == 2)
            login();
        else
            break;
    }
    return 0;

}
