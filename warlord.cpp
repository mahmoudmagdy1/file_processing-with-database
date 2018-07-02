/////////////////////////// thank you to all member in our team////////////////////////////////
///////mostafa ramdan & mohamed allaa & mohamed eshawy & mahmoud abo elela & mahmoud atito/////
//////////////////////////////////mahmoud magdy & hamoo////////////////////////////////////////
///////////////////////////All rights reserved to the warlord /////////////////////////////////
#include<iostream>
#include<fstream>
using namespace std;
const float NG_P=1.5;
const float NG_E=3;
const float SO_P=0.75;
const float SO_E=1;
const float PE_P=1.75;
const float PE_E=2.5;
class payment{
	public:
		payment();//constractor
		void read();//read
		void update();//update
		void write();//write
        int  put_id();//to make id
        int quantity(int ty);//to acount quantity
        float earn();//to acount earns
        float pay();//to acount payments
	private:
		int id;
		int type;
		float quant;
		float price;
		char pay_earn;
};
void turn(int type);//to turn type to string
float putPrice(int ty,char pe,float qu);//to acount price to all product
void statics();//make statics
void worker();//function to deal with worker
void owner();//function to deal with owner
////////////////////////////MAIN////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int main(){
payment x;
string name;
int password;
cout<<"---------------------Welcome------------------------\n";
cout<<"Enter your name : ";
cin>>name;
cout<<"Enter password : ";
cin>>password;
if(name=="worker"&&password==1111)
{
cout<<"----------------------Hallo----------------------------\n";
	worker();
}
else if(name=="owner"&&password==2222)
{
cout<<"----------------------Hallo----------------------------\n";
	owner();
}
else {
	cout<<"Error try again........Thank you";
	return 0;
}


	
}
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
payment::payment(){
	id=0;
}
////////////////////////////owner/////////////////////////////////////////////////
void owner(){
	int ch;
	payment p;
cout<<"Enter   1   for read all operations\n";
cout<<"Enter   2   for statistics about all project\n";
cout<<"Enter   0   for close this program \n";
cout<<" : ";
cin>>ch;	
	if(ch==1){
		p.read();
	}
	else if(ch==2){
		statics();
	}else if(ch==0){
		return;
	}else{
	cout<<"try again \n";
		owner();
	}
		
}
///////////////////////////worker/////////////////////////////////////////////////
void worker(){
	int ch;
	payment p;
cout<<"Enter   1   for write an operation\n";
cout<<"Enter   2   for update an operation\n";
cout<<"Enter   0   for close this program \n";
cout<<" : ";
cin>>ch;	
	if(ch==1){
		p.write();
	}
	else if(ch==2){
		p.update();
	}else if(ch==0){
		return;
	}else{
	cout<<"try again \n";
		worker();
	}
	
}
void payment::write(){

    
    int ch;
    	do{
    		
        fstream f;
        payment p;
    	cout<<"--------------------------------------------------------------------------------";
    	cout<<"\t\t 1 --->If you want to mark Natural Gas \n";
    	cout<<"\t\t 2 --->If you want to mark Petrol \n";
    	cout<<"\t\t 3 --->If you want to mark Solar \n";
    	cout<<"\t\t 4 --->If you want to mark service \n";
    	cout<<"\t\t 5 --->If you want to mark salary of employee \n";
 		cout<<"\t\t 6 --->to return to main minu \n"; 
 		cout<<"\t\t 0 --->to close this program \n";
		cout<<"--------------------------------------------------------------------------------";  
		cout<<"enter the type : ";
		cin>>p.type;
		////////////////////////////Natural gas//////////////////////////////////
			if(p.type==1)
			{
				cout<<"\nEnter ---(E)---If the process is earning\n";
				cout<<"Enter ---(P)---If the process is payment\t";
				cin>>p.pay_earn;
				cout<<"\nEnter quantity: ";
				cin>>p.quant;
				if(p.pay_earn=='E')
				{
					p.price=putPrice(p.type,p.pay_earn,p.quant);
				}
				else
				{
					p.price=putPrice(p.type,p.pay_earn,p.quant);
				}
				
				 	p.id=put_id();
					
					f.open("payment.txt",ios::out|ios::app);
					f.write((char *) &p, sizeof(p));
			
			}
///////////////////////////////////petrol/////////////////////////////////////
			else if(p.type==2)
			{
				cout<<"\Eenter ---(E)---If the process is earning\n";
				cout<<"Enter ---(P)---If the process is payment\t";
				cin>>p.pay_earn;
				cout<<"\nEnter quantity: ";
				cin>>p.quant;
				if(p.pay_earn=='E')
				{
				    p.price=putPrice(p.type,p.pay_earn,p.quant);
				}
				else
				{
					p.price=putPrice(p.type,p.pay_earn,p.quant);
				}
					p.id=put_id();
					f.open("payment.txt",ios::out|ios::app);
					f.write((char *) &p, sizeof(p));
				
				}
/////////////////////////////////////solar//////////////////////////////////////
			else if(p.type==3)
			{	
				cout<<"\nEnter ---(E)---If the process is earning\n";
				cout<<"Enter ---(P)---If the process is payment\t";
				cin>>p.pay_earn;
				cout<<"\nEnter quantity: ";
				cin>>p.quant;
				if(p.pay_earn=='E')
				{
					p.price=putPrice(p.type,p.pay_earn,p.quant);
				}
				else
				{
					p.price=putPrice(p.type,p.pay_earn,p.quant);
				}
					p.id=put_id();
					f.open("payment.txt",ios::out|ios::app);
					f.write((char *) &p, sizeof(p));
				
			}
////////////////////////Service////////////////////////////////////////////////////
		
			else if(p.type==4)
			{
				cout<<"\nEnter ---(E)---If the process is earning\n";
				cout<<"Enter ---(P)---If the process is payment\t";
				cin>>p.pay_earn;
				p.quant=0;
				cout<<"Enter the price: ";
				cin>>p.price;
				p.id=put_id();
				f.open("payment.txt",ios::out|ios::app);
				f.write((char *) &p, sizeof(p));
			
			}
/////////////////////////salary/////////////////////////////////////////////////
			else if(p.type==5)
			{
				
				p.pay_earn='P';
				p.quant=0;
				cout<<"\nEnter the price: ";
				cin>>p.price;
				p.id=put_id();
				f.open("payment.txt",ios::out|ios::app);
				f.write((char *) &p, sizeof(p));
				
	//////////////////////////////////////////////////////////////////
			}
			else if(p.type==6)
			{
				
				worker();
				
			}
			else if(p.type==0){
				return;
			}
			else{
				cout<<"try again";
				write();
			}
			
		
		}while(ch!=1||ch!=2||ch!=3||ch!=4||ch!=5||ch!=0||ch!=6);		
	


}
///////////////////////////////////////////////////////////////////////////////////////////

void payment::update(){
	fstream f;
	payment s;	
	int ids;
	cout<<"Enter Id wanted to modify:  ";
	cin>>ids;
	f.open("payment.txt",ios::in|ios::out);
	while(!f.eof()){
		f.read((char*)&s,sizeof(s));
		if(s.id==ids){
			int k=f.tellg();
			int l=sizeof(s);
			f.seekp(k-l,ios::beg);
			int ch;
      		cout<<"--------------------------------------------------------------------------------\n";		
			cout<<"Enter  0 -->for delete\n";
			cout<<"Enter  1 -->for type \n";
			cout<<"Enter  2 -->for quant\n";
			cout<<"Enter  3 -->for pay_earn\n";
			cout<<"Enter  4 -->for return to the main minu\n";
			cout<<"Enter  5 -->for close the program\n";
			cout<<"--------------------------------------------------------------------------------\n";
			cout<<"Enter your choose : ";
			cin>>ch;
			if(ch==0)
			{
				
				s.id=s.id*-1;
				f.write((char *)&s,sizeof(s));
			}
			else if(ch==1)
			{
				cout<<"enter new type \n";
				cin>>s.type;
				s.price=putPrice(s.type,s.pay_earn,s.quant);
				f.write((char *)&s,sizeof(s));
			}
			else if(ch==2)
			{
				cout<<"enter new quant\n";
				cin>>s.quant;
				s.price=putPrice(s.type,s.pay_earn,s.quant);
				f.write((char *)&s,sizeof(s));
			}
			else if(ch==3)
			{
				
				cout<<"enter new pay_earn\n";
				cin>>s.pay_earn;
				f.write((char *)&s,sizeof(s));
			}
			else if(ch==4)
			{
				worker();
			}
			else if(ch==5)
			{
				return ;
				
			}
			else
			{
				update();	
			}
			
			
		}
		
	}
	
	
}
void payment::read(){


	payment p;
	fstream f;
	int x;
	
	cout<<"ID\t"<<"pay/earn\t"<<"Type\t"<<"Name\t\t"<<"Quantity\t"<<"Price\n";
	
	f.open("payment.txt",ios::in);
	while(!f.eof())
	{

		f.read((char *) &p,sizeof(p));

		if(p.id>0)
		{
			if(p.id==x)
			{
				int ch;
				cout<<"--------------------------------------------------------------------------------\n";
				cout<<"Enter 0 --> to close the program \n";
				cout<<"Enter 1 --> to go to statistics    :";	
				cin>>ch;
				cout<<"--------------------------------------------------------------------------------\n";
				if(ch==0)
				{
					return;
				}
				else
				{
					statics();
				}
			
				
				
				
			}
				cout<<p.id<<"\t";
				x=p.id;
				cout<<p.pay_earn<<"\t\t";
				cout<<p.type<<"\t";
				turn(p.type);
				cout<<"\t"<<p.quant<<"\t\t";
				cout<<p.price<<"\n";
	
		}	
	
	}
}

void statics(){
	payment p;
cout<<"---------------------this is a statistics for Gas Station----------------------\n\n";
cout<<"the reminder quantity of (Natural Gas) is ("<< p.quantity(1)<<") littres \n";
cout<<"the reminder quantity of (   Petrol  ) is ("<< p.quantity(2)<<") littres \n";
cout<<"the reminder quantity of (    Solar  ) is ("<< p.quantity(3)<<") littres \n\n";
cout<<"the payments now is ("<<p.pay()<<") $\n";
cout<<"the earnings now is ("<<p.earn()<<")$\n\n";
cout<<"the net benefits is ("<<p.earn()-p.pay()<<")$\n\n";
int ch;
cout<<"--------------------------------------------------------------------------------\n";
cout<<"Enter 0 --> to close the program \n";
cout<<"Enter 1 --> to go to statistics    :";	
cin>>ch;
cout<<"--------------------------------------------------------------------------------\n";
if(ch==0)
{
	return;
}
else
{
	p.read();
}
			
				
	
}
int payment::quantity(int ty){
	
	payment p;
	fstream f;
	int x;
	int pq=0;
	int pe=0;
	f.open("payment.txt",ios::in);
	while(!f.eof()){

	f.read((char *) &p,sizeof(p));
	if(p.id==x)
	{
		
		return pq-pe;
	}
	if(p.type==ty&&p.pay_earn=='P'){
		pq=pq+p.quant;
	
	}
	if(p.type==ty&&p.pay_earn=='E'){
		pe=pe+p.quant;
	}
	
	
	x=p.id;
	
	}
	
	
}
float payment::earn(){
	
payment p;
	fstream f;
	int x;
	int E=0;
	f.open("payment.txt",ios::in);
	while(!f.eof()){

	f.read((char *) &p,sizeof(p));
	if(p.id==x)
	{
		
		return E;
	}
	if(p.pay_earn=='E'){
		E=E+p.price;
	
	}
	
	x=p.id;
	
	}
		
}
///////////////////////////////////////////////////////
float payment::pay(){
	payment p;
	fstream f;
	int x;
	int Pa=0;
	f.open("payment.txt",ios::in);
	while(!f.eof()){

	f.read((char *) &p,sizeof(p));
	if(p.id==x)
	{
		
		return Pa;
	}
	if(p.pay_earn=='P'){
		Pa=Pa+p.price;
	
	}
	
	x=p.id;
	
	}
	
}
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
int payment::put_id(){
	fstream f;
	payment p;
	int x=0;
		f.open("payment.txt",ios::in);
		
		
		
		while(!f.eof()){
			f.read((char *)&p,sizeof(p));
			
			if(p.id==0){
			return 1;
		     }
			else if(p.id==x){
				
				return x+1;
				
			}
			x=p.id;
	
		}
        
		
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

float putPrice(int ty,char pe,float qu){
	
	if(ty==1&&pe=='E'){
		return qu*NG_E;
	}
	else if(ty==1&&pe=='P'){
		return qu*NG_P;
	}
	else if(ty==2&&pe=='E'){
		return qu*PE_E;
	}
	else if(ty==2&&pe=='P'){
		return qu*PE_P;
	}
	else if(ty==3&&pe=='E'){
		return qu*SO_E;
	}
	else if(ty==3&&pe=='P'){
		return qu*SO_P;
	}
/*const float NG_P=1.5;
const float NG_E=3;
const float SO_P=0.75;
const float SO_E=1;
const float PE_P=1.75;
const float PE_E=2.5;*/	
	
	
}
//////////////////////////////////////////////////////////////////////////////////
void turn(int type)
{
	
	if(type==1){
		cout<<"N-Gas\t";
	}
	else if(type==2){
		cout<<"Petrol\t";
	}
	else if(type==3){
		cout<<"Soler\t";
	}
	else if(type==4){
		cout<<"service\t";
	}
	else {
		cout<<"Emp-Sal\t";
	}

}
///////////////////////thanks/////////////////////////////////////////////
