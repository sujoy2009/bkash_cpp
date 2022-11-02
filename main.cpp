
#include <bits/stdc++.h>

using namespace std;
class base{
    public:

    int blnc;

    base(int b){
    blnc=b;
    }
};
class vat
{
    protected:
    float coamount;

    float charge;
public:
    vat(float v)
    {
        coamount=v;
    }

     float vatgenerator(){
    charge=coamount*(.02);
    return charge;
    }



};

class operation:public base,public vat
{
    int bal;
public:
     operation(int a,int b): base(a),vat(b){
            bal=a;
     }
     setbal(){
     ofstream off("balance.txt");
           off<<bal;
           off.close();
     }

       void sendmoney()
       {

           int num,amount;
           string pin;

           cout<<"Enter receiver number:"<<endl;
           getchar();
           cin>>num;
           cout<<"Enter ammount:"<<endl;
           cin>>amount;
           cout<<"Enter your pinnumber:"<<endl;
           cin>>pin;
           int ntk;

           string passward;
           ifstream ifp("pasward.txt");
           ifp>>passward;
           ifp.close();
           ifstream ifff("balance.txt");
                ifff>>ntk;
           if(passward==pin){

                if(amount<=ntk){

                 ntk=ntk-amount;
                 ofstream off("balance.txt");
                 off<<ntk;

                 cout<<"your send money to"<<num<<"of"<<amount<<"tk is successfull.your new balance is"<<ntk<<endl;
                 off.close();

                }
                else{
                    cout<<"low balance"<<endl;
                }
           }
           else{
            cout<<"wrong passward"<<endl;
           }
       }
       void topup(){

           int num,amount;
           string pin;

           cout<<"Enter receiver number:"<<endl;
           getchar();
           cin>>num;
           cout<<"Enter ammount:"<<endl;
           cin>>amount;
           cout<<"Enter your pinnumber:"<<endl;
           cin>>pin;
           int ntk;

           string passward;
           ifstream ifp("pasward.txt");
           ifp>>passward;
           ifp.close();
           ifstream ifff("balance.txt");
                ifff>>ntk;
           if(passward==pin){

                if(amount<=ntk){

                 ntk=ntk-amount;
                 ofstream off("balance.txt");
                 off<<ntk;

                 cout<<"your topup to"<<num<<"of"<<amount<<"tk is successfull.your new balance is"<<ntk<<endl;
                 off.close();

                }
                else{
                    cout<<"low balance"<<endl;
                }
           }
           else{
            cout<<"wrong passward"<<endl;
           }
       }


       void cashout()
       {
           int num,amount,vat;
           string pin;

           cout<<"Enter receiver number:"<<endl;
           getchar();
           cin>>num;

           cout<<"Enter your pinnumber:"<<endl;
           cin>>pin;
           cout<<"enter ammount again for surity please"<<endl;
           cin>>amount;
           int ntk;

           string passward;
           ifstream ifp("pasward.txt");
           ifp>>passward;
           ifp.close();

           ifstream ifff("balance.txt");
                ifff>>ntk;
           if(passward==pin){
                vat=vatgenerator();

                if((amount+vat)<=ntk){

                 ntk=ntk-amount-vat;
                 ofstream off("balance.txt");
                 off<<ntk;

                 cout<<"your send money to"<<num<<"of"<<amount<<"tk is successfull.your new balance is"<<ntk<<endl;
                 off.close();

                }
                else{
                    cout<<"low balance"<<endl;
                }
           }
           else{
            cout<<"wrong passward"<<endl;
           }
       }
          void changepassward()
       {
           string prepas,checkpas,newpas;
           ifstream ifch("pasward.txt");
           ifch>>prepas;
             ifch.close();



           cout<<"enter ur previous pasward"<<endl;
           cin>>checkpas;
           if(checkpas==prepas){
            cout<<"enter your new passward"<<endl;
            cin>>newpas;

            ofstream of5("pasward.txt");
            of5<<newpas;
            of5.close();
           }
           else{
            cout<<"sorry.wrong";
           }


       }
       void showbalance(){
           int balanc;
           ifstream if44("balance.txt");
           if44>>balanc;
           cout<<"ur balance is :"<<balanc;

       }

};



int main()
{




  /* operation op(2000,100);

    op.setbal();
    vat vatt();



    op.cashout();


   */char ch;

        cout<<" s  for send money:"<<endl;
    cout<<"c for casout"<<endl;
    cout<<"t for topup"<<endl;
    cout<<"p for passward cng"<<endl;

    cout<<"b for bal show"<<endl;
    cout<<"t for exit"<<endl;

    cin>>ch;
  if(ch!='c'){
        operation op(2000,0);
        op.setbal();
     if(ch=='b'){

        op.showbalance();
     }
     else if(ch=='s'){
         op.sendmoney();
    }
     else if(ch=='t')
     {
         op.topup();
      }
      else if(ch=='p'){
         op.changepassward();
      }




       else{
        cout<<"wrong choice"<<endl;
       }
   }
   else{
       int am;

 cout<<"enter ammount";
   cin>>am;

     operation op(2000,am);

     op.setbal();



    vat vatt();
    op.cashout();
     op.showbalance();
   }




}
