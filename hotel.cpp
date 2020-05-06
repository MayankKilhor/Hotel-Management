void screen()
{
cout<<"\n\t\t\t	GALLIFREY HOTEL\n";
cout<<"\n	7,Civil lines,New Delhi(110012)\n";

cout<<" 	
\n";
cout<<"   Phone no-> 0124-4020189	email id-> gallifreyhotel_delhi@gmail.com\n";

cout<<"\n 	
    \n"; cout<<"\n";
}


int calc_dates(int a,int b,int c)
{ int d,no_leap=0,z=0;//a->no of dates from new year int y;

if(b>2)
{ y=c;} else if(b<=2)
{y=c-1;}
no_leap=y/4 - y/100 + y/400;


switch(b)
{ case 3 : z=59;
break; case 4 : z=90;
break; case 5 : z=120;
break; case 6 : z=151;
break; case 7 : z=181;
break; case 8 : z=212;
break; case 9 : z=243;
break; case 10 : z=273;
break; case 11 : z=304;
break; case 12:  z=334;
break;

}




d=c*365+a+z+no_leap;
return d;
}


int check_dates(int a,int b,int c) //a->date,b->month,c->year
{
if((b==2) && (a>29))
{

return 0;
}

else
if((b>12)||(a>31))
{

return 0;
}

else
if((b==4||b==6||b==9||b==11) && (a>30))
{

return 0;
}

else
if((c%4)!=0 && (b==2) && (a>28))
{
return 0;
}
else
{return 1;}
}


class room
{ int roomno;
char roomtype[20];
int vacancy; public:
void create_room(); void show_room(); void modify_room();
void list_rooms(char []); int retroom()
{ return roomno; } int retvac()
{ return vacancy; } void setvac(int a)
{ vacancy=a; } void setroom(int b)
{ roomno=b; } char *rettype()
{ return roomtype; }
};
room r;


void room::create_room()
{ cout<<"\n Enter The Room Number :- "; cin>>roomno;
cout<<"\n Enter Room Type :- "; gets(roomtype);
vacancy=1;

}


void room::modify_room()
{

cout<<"\n Modified Room Number :- "; cin>>roomno;
cout<<"\n Modified Room Type :- "; gets(roomtype);
}

void room::list_rooms(char a[])
{ fstream f("room.dat",ios::in|ios::out|ios::binary|ios::app); cout<<"\n List Of Available Room Of Type ";
puts(a);
cout<<" Are:- \n";
cout<<" Room Number"<<setw(20)<<"Room Type"<<endl; while(f.read((char*)&r,sizeof(room)))
{

if(r.retvac()==1&&!(strcmpi(a,r.rettype())))
cout<<" "<< r.roomno<<setw(20)<<r.roomtype<<endl;


}
getch();
f.close();
}


void delete_room()
{ clrscr();
screen();
fstream f("room.dat",ios::in|ios::out|ios::app|ios::binary); fstream f2("temp.dat",ios::in|ios::binary|ios::app);
int a,found=0;
cout<<"\n Enter The Room Number You Want To Delete :- "; cin>>a;
while(f.read((char*)&r,sizeof(room)))
{ if(r.retroom()!=a) f2.write((char*)&r,sizeof(room));
else
if(r.retroom()==a&&r.retvac()==0) found=2;
else found=1;
}

f2.close();
f.close(); remove("customer.dat");
rename("temp.dat","customer.dat"); if(found==0)
{ cout<<"\n Enter Right Room Number";


}
else if(found==2)
cout<<"\n Record Can Not Be Deleted As Entered Room Number Is Not Vacant "; getch();
}


void modify_room_record()
{ clrscr();
fstream f("room.dat",ios::in|ios::out|ios::app|ios::binary); int a,found=0,pos=0;
cout<<"\n Enter Old Room Number :-"; cin>>a; while(f.read((char*)&r,sizeof(room)))
{ if(a==r.retroom()&&r.retvac()==1)
{r.modify_room(); found=1;
pos=-1*sizeof(room); f.seekp(pos,ios::cur);
f.write((char*)&r,sizeof(room)); break;
}

else if(a==r.retroom()&&r.retvac()==0) found=2;
}

if(found==0)
cout<<"\n Room Not Found!! "; if(found==1)
cout<<"\n Record Modified!!"; if(found==2)
cout<<"\n Record Can Not Be Modify As Entered Room Number Is Not Vacant "; f.close();
}


class customer
{ public:
char customername[25]; char phone[11];
char per_address[100]; int age;
int checkin_year; int checkin_month; int checkin_date; int checkout_year;
int checkout_month; int checkout_date; char croomtype[20];
long room_charge;//total charges of room long food;
long croomno;
long other_charges; int no_days;
long subtotal; long bill; float tax;
int retcroom()
{ return croomno; } char *retctype()
{ return croomtype; } void setcroom(int a)
{ croomno=a; }
void setctype(char b[])
{ strcpy(croomtype,b); } char *retname()
{ return customername; }


customer()
{room_charge=0; no_days=0; subtotal=0; tax=0;
bill=0; checkin_year=0; checkin_month=0; checkin_date=0; checkout_year=0; checkout_month=0; checkout_date=0;
}
void generate_bill();
int compare_room(int); void putcustomer(); void getcustomer(int);
};
customer c;
void customer::generate_bill()
{

cout<<"\n Enter the bill amount of restaurant:- "; cin>>food;
cout<<"\n Enter other charges:- "; cin>>other_charges; subtotal=room_charge+food+other_charges; tax=0.18*subtotal;
bill=subtotal+tax; getch();
}


void display_customer_name()
{ clrscr();
screen();
cout<<endl<<" Enter Name of the customer whose details you want to search:- "; char a[30];
int found=0; gets(a);
clrscr();
fstream f("Customer.dat",ios::app|ios::in|ios::out|ios::binary); while(f.read((char*)&c,sizeof(customer)))
{
if(!(strcmpi(a,c.retname())))
{ c.putcustomer(); found=1;
break;
}
}

if(found==0)
cout<<"\n There Are No Details Of Person With Above Name"; f.close();
}


void customer::putcustomer()
{	clrscr();
cout<<"\n Name of Customer:- "; puts(customername);
cout<<"\n Room Number of Customer:- "; cout<<croomno;
cout<<"\n Phone No. of Customer:- "; cout<<phone;
cout<<"\n Permanent Address of Customer:- "; puts(per_address);
cout<<"\n Age of Customer:- "; cout<<age;
cout<<"\n Room type:- "; puts(croomtype);
cout<<"\n Checkin date :-"<<checkin_date<<"/"<<checkin_month<<"/"<<checkin_year; cout<<"\n Checkout date :-"<<checkout_date<<"/"<<checkout_month<<"/"<<checkout_year; cout<<"\n Room charge:- ";
cout<<room_charge<<endl; getch();
}




void customer::getcustomer(int m)
{ int flag_date1,flag_date2;
cout<<"\n Enter Customer Name:- "; gets(customername);
cout<<"\n Enter Customer Phone no. :- "; gets(phone);
cout<<"\n Enter Customer Permanent Address :- "; gets(per_address);
cout<<"\n Enter Customer Age:- "; cin>>age;
START2:
clrscr();
screen();
cout<<"\n Enter Check in Year:- "; cin>>checkin_year;
cout<<"\n Enter Check in Month:-"; cin>>checkin_month;
cout<<"\n Enter Check in date:-"; cin>>checkin_date;
flag_date1=check_dates(checkin_date,checkin_month,checkin_year); if(!flag_date1)
{ cout<<"\n Enter valid checkin Date\n\n"; goto START2;}
START3:
cout<<"\n Enter Check out Year:-"; cin>>checkout_year;
cout<<"\n Enter Check out Month:-"; cin>>checkout_month;
cout<<"\n Enter Check out Date:-"; cin>>checkout_date;
flag_date2=check_dates(checkout_date,checkout_month,checkout_year); if(!flag_date2)
{ cout<<"\n Enter valid checkout Date"; goto START3;}
int d1,d2; d1=calc_dates(checkin_date,checkin_month,checkin_year); d2=calc_dates(checkout_date,checkout_month,checkout_year); no_days=d2-d1;
if(no_days<=0)
{ cout<<"\n Checkout Date has to be after checkin Date"; goto START2;}
room_charge=no_days*m;




}
void modify_customer_record()
{

clrscr();
screen();
int a,pos=0,found=0; customer c1;
cout<<"\n Enter The Room Number :- "; cin>>a;
fstream f("customer.dat",ios::in|ios::out|ios::app|ios::binary); while(f.read((char*)&c,sizeof(customer)))
{ if(c.retcroom()==a)
{cout<<"\n Re-enter The Customer Details :- "; c1.getcustomer(c.room_charge/c.no_days); pos=-1*sizeof(customer);
f.seekp(pos,ios::cur); c1.setcroom(c.retcroom()); c1.setctype(c.retctype()); f.write((char*)&c1,sizeof(customer));
found=1; break;
}
}

if(found==0)
cout<<"\n Entered Room Number Doesn't Exist"; else
cout<<"\n Record Modified"; f.close();
getch();
}


void display_customer_roomno()
{

clrscr();
screen();
cout<<endl<<" Enter Room Number Of The Customer Whose Details You Want To Search:- "; int a;
cin>>a;
int found=0; clrscr();
fstream f("Customer.dat",ios::app|ios::in|ios::out|ios::binary); while(f.read((char*)&c,sizeof(customer)))
{
if(c.retcroom()==a)
{ c.putcustomer(); found=1;
}

}
if(found==0)
cout<<" There Are No Details Of This Room Number";
getch();
f.close();
}

void checkout()
{

clrscr();
screen();
int a,found=0,pos=0; cout<<"\n\n\t\tCHECK OUT\n\n"; START1:
cout<<"\n Enter Room Number :- "; cin>>a;

fstream f("customer.dat",ios::in|ios::out|ios::app|ios::binary); fstream f2("temp.dat",ios::out|ios::app);
f.seekg(0,ios::beg); while(f.read((char*)&c,sizeof(customer)))
{ if(c.croomno!=a) f2.write((char*)&c,sizeof(customer));
else if(c.retcroom()==a)
{ c.putcustomer(); c.generate_bill();
cout<<"\n Subtotal amount:- "<<c.subtotal; cout<<"\n Tax:- "<<c.tax;
cout<<"\n Total bill amount:- "<<c.bill; found=1;
}
}

f2.close();
f.close();
remove("customer.dat"); rename("temp.dat","customer.dat"); if(found==0)
{
cout<<"\n Room Number Not Found!!"; cout<<"\n Re-enter The Room Number"; goto START1;
}
fstream f1("room.dat",ios::in|ios::app|ios::binary|ios::out); while(f1.read((char*)&r,sizeof(room)))
{ if(c.retcroom()==r.retroom())
{ pos=-1*sizeof(room); r.setvac(1); f.seekp(pos,ios::cur); f.write((char*)&r,sizeof(room)); break;}
}
f1.close();
}


int check_room(int a,char b[])
{ int buf;
fstream f("room.dat",ios::in|ios::out|ios::app|ios::binary); while(f.read((char*)&r,sizeof(room)))
{ if(r.retroom()==a&&strcmpi(r.rettype(),b)==0&&r.retvac()==1)
{ buf=1; break;}
else if(r.retroom()==a&&strcmpi(r.rettype(),b)!=0&&r.retvac()==1)
{ buf=2; break;}
else if(r.retroom()==a&&r.retvac()!=1)
{ buf=3; break;} else
if(r.retroom()!=a)
{ buf=0; break;
}
}

f.close(); return buf;
}

void checkin()
{

clrscr();
screen(); cout<<"\n\n\t\tCHECK IN\n\n"; int n1,a,pos=0,flag_room,m; char b[20];
fstream f("customer.dat",ios::app|ios::in|ios::out|ios::binary); cout<<"\n Select room type\n";
cout<<"\n 1. Single(AC)"
<<"\n 2. Single(Non AC)"
<<"\n 3. Double(AC)"
<<"\n 4. Double(Non AC)"
<<"\n 5. Junior Suite"
<<"\n 6. Family Suite"
<<"\n 7. presidential Suite"; cout<<"\n Select your Option:- "; cin>>n1;
switch(n1)
{ case 1 : strcpy(b,"Single(AC)"); m=1500;
break;
case 2 : strcpy(b,"Single(Non AC)"); m=1000;
break;
case 3 : strcpy(b,"Double(AC)"); m=3700;
break;
case 4 : strcpy(b,"Double(Non AC)"); m=3000;
break;
case 5 : strcpy(b,"Junior Suite"); m=9000;
break;
case 6 : strcpy(b,"Family Suite"); m=16000;
break;
case 7 : strcpy(b,"Presidential Suite"); m=20000;
break;
deafult: cout<<"\n Enter Valid Choice "; break;
}
r.list_rooms(b); START1:
cout<<"\n Enter Your Room Number:- "; cin>>a;
flag_room=check_room(a,b); if(flag_room==1)
{ c.getcustomer(m); c.setcroom(a); c.setctype(b);
}
if(flag_room==2)
{ cout<<"\n The Room Number You Entered Is Not Of Your Required Room Type "; cout<<"\n Re-enter The Room Number";
goto START1;

}
if(flag_room==3)
{ cout<<"\n The Room Number You Entered Is Not Vacant "; cout<<"\n Re-enter The Room Number";
goto START1;

}
if(flag_room==0)
{ cout<<"\n The Room Number You Entered Doesn't Exist"; cout<<"\n Re-enter The Room Number";
goto START1;

}
f.write((char*)&c,sizeof(customer));
fstream f1("room.dat",ios::in|ios::out|ios::app|ios::binary); while(f1.read((char*)&r,sizeof(room)))
{ if(a==r.retroom())
{ pos=-1*sizeof(room); r.setvac(0); f1.seekp(pos,ios::cur);
f1.write((char*)&r,sizeof(room)); break;}
}
f1.close();
f.close();
}


void write_room()
{ clrscr();
screen();
fstream f("room.dat",ios::in|ios::out|ios::app|ios::binary); r.create_room();
f.write((char*)&r,sizeof(room)); f.close();
}


void setting()
{ int a; clrscr();

screen();
cout<<"\n\t\t SETTING	\n"
<<" 1. Display Customer Details By Name\n"
<<" 2. Display Customer Details By Room Number\n"
<<" 3. Add Room \n"
<<" 4. Delete Room \n"
<<" 5. Modify Room Details \n"
<<" 6. Modify Customer Details \n"
<<" 7. Back To Main Menu \n"; cout<<"\n Enter your choice:- "; cin>>a;
switch(a)
{ case 1: display_customer_name(); break;
case 2: display_customer_roomno();
break;
case 3: write_room();
break; case 4: delete_room();
break;
case 5: modify_room_record(); break;
case 6: modify_customer_record();
break; case 7: return;
default: cout<<"\n Enter valid choice";
}
getch();
}




void main()
{
clrscr();
cout<< endl << endl << endl<< endl; textmode(C80); textbackground(WHITE); textcolor(BLUE);
cout<<"\t\t\t****************************\n"; cout<<"\t\t\t* HOTEL MANAGEMENT PROGRAM *\n"; cout<<"\t\t\t****************************\n"; cout<<"\n\n\n\n\t\t MADE BY:-";
sleep(1);
cout<<"\n\n\t\t\t	MAYANK KILHOR(18BCI0136)"
<<"\n\t\t\t	VIKAS MISHRA(18BCE2391)"
<<"\n\t\t\t	SHUBHAM SAREEN(18BCI0162)"
<<"\n\t\t\t	RTVIK KATARYA(18BCE0837)"
<<"\n\t\t\t	RISHABH PANCHAL(18BCE2275)\n\n\n"; sleep(1);
cout<<"	Press Enter to continue	" << endl << endl << endl << endl;
getch();




clrscr();
screen(); customer c1; int a,o;
int ctr1=0,ctr2=0,ch1,ch2;
char username[30]="",password[30]=""; cout<<"\n\t\t USERNAME:- ";
for(int i=0;i<7&&(o=getch())!=13;i++)
{ username[i]=o; putch(o);
}
ctr1=strcmpi(username,"admin"); if(ctr1==0)
{ cout<<"\n\n\n\t\t PASSWORD:- "; for(int j=0;j<7&&(o=getch())!=13;j++)
{password[j]=o; putch('*');
}
ctr2=strcmpi(password,"dsa"); if(ctr2==0)
{
do{ clrscr();
screen();
cout<<"\n\t\t MAIN MENU	\n"
<<" 1. Checkin Customer \n"
<<" 2. Checkout Customer \n"
<<" 3. Setting \n"
<<" 4. Exit \n";
cout<<"\n Enter your choice:- "; cin>>a;
switch(a)
{ case 1: checkin();
break; case 2: checkout();
break; case 3: setting();
break; case 4: exit(0);
break;
default: cout<<"\n Enter valid choice";
break;

}
}while(a!=4);
}
else
cout<<"\n\n\n\t\t WRONG PASSWORD!!!!!";
}
else
cout<<"\n\n\t\t WRONG USERNAME!!!!!"; getch();
}