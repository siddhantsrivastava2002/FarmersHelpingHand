#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
#include<fstream.h>
#include<graphics.h>
#include<dos.h>
 void loading();
 void login() ;
 void signup();
 void fwindow();
 void flogin();
 void mwindow();
 void sell();
intgetfid();
 void bill();
 void disptfarmer();
 void addcrop();
 void delcrop();
 void showcrop();
 void modinfo();

 void stdd();
 void offmwindow();
 void showfarmer();
 void exadv();
class farmer
{
   char name[50];
   char city[20];
int pass;
   char cname[10];
int crate;
    long intadn;
   long intpno;
   public:
                farmer()
	{
	strcpy(name,"NOT ENTERED");
	strcpy(city,"NOT ENTERED");
	     pass=0;
	adn=0;
	pno=0;
	}
	void enter()
	{cout<<"\n\t\tEnter the Name           :";
                     gets(name);
	cout<<"\n\t\tEnter the City           :";
	     gets(city);
	cout<<"\n\t\tEnter your Aadhar Number :";
	cin>>adn;
	cout<<"\n\t\tEnter the Phone NO       :";
	cin>>pno;
	cout<<"\n\t\tEnter the Password       :";
	cin>>pass;
	 }
	 void entercrop()
	 {
	cout<<"\n\t\t Enter crop name             :";
	  gets(cname);
	cout<<"\n\t\t Enter the  crop rate        :";
	cin>>crate;
	  }
                   void showofarmer()
	  {
	cout<<"\n\t\t"<<name<<"\t\t\t"<<city;
	  }
                  void showtfarmer()
	  {
	cout<<"\n\t\t"<<name<<"\t\t\t"<<crate<<"\t\t"<<cname;
	  }
                  char* getname()
	 {
	   return name;
	 }
	 char* getcrop()
	 {
	  return cname;
	  }
	intgetprice(char ip[])
	  {
	int c;
	  if(strcmp(cname,ip)==0)
	  {
	   c=crate;
	  }
	   return c;
	  }
	intgetno(char fp[])
	  {
	   long int k;
	  if(strcmp(name,fp)==0)
	  {
	   k=pno;
	  }
	  return k;
	  }
	intgetan( char sp[])
	  {
	   long int j;
	  if(strcmp(name,sp)==0)
	  {
	  j=adn;
	  }
	  return j;
	  }
	intgetpass()
	 {
	  return pass;
	 }
   }f;
   void disptfarmer()
   {
cout<<"\n\t\t NAME\t\t\t Price\t\tCROP";
ifstreami("prices.dat",ios::binary);
i.seekg(0);
    while(i.read((char*)&f,sizeof(f)))
    {
f.showtfarmer();
    }
i.close();
   }

   void showfarmer()
   {
clrscr();
cout<<"\n\t\t*************************************************";
cout<<"\n\t\t\t        LIST OF ENROLLED FARMERS";
cout<<"\n\t\t*************************************************";
cout<<"\n\t\tNAME\t\t\t CITY";
ifstreami("farmers.dat",ios::binary);
i.seekg(0);
    while(i.read((char*)&f,sizeof(f)))
    {
f.showofarmer();
    }
i.close();
   }
   void fawindow()
  {
int ch,ch1;
    do{
clrscr();
cout<<"\n\t\t*************************************************";
cout<<"\n\t\t\t\t   FARMERS WINDOW";
cout<<"\n\t\t*************************************************";
cout<<"\n\t\t\t\t1.CURRENT PRICES ";
cout<<"\n\t\t\t\t2.EXPERT ADVICE ";
cout<<"\n\t\t\t\t3.SELL TO TRADERS";
cout<<"\n\t\t\t\t4.EXIT";
cout<<"\n\t\t*************************************************";
cout<<"\n\t\t\t     Enter your choice:";
cin>>ch;
    if(ch==1)
    {
showcrop();
    }
    if(ch==2)
    {
exadv();
    }
    if(ch==3)
    {
    sell();
    }
    if(ch==4)
    {
      exit(0);
    }
cout<<"\n\t\t*************************************************";
cout<<"\n\t\t\t1.Go to main menu";
cout<<"\n\t\t\t2.Go to farmers menu";
cout<<"\n\t\t*************************************************";
cout<<"\n\t\t          Enter your choice:";
cin>>ch1;
    if(ch1==1)
    {
mwindow();
    }
 }while(ch1==2);
 }
void login()
 {
clrscr();
intpss,x=0,ch1;
  char name[20];
  do
  {
cout<<"\n\t\tEnter your username:";
  gets(name);
cout<<"\n\t\tEnter the Password :";
cin>>pss;
ifstream j;
j.open("farmers.dat",ios::binary);
j.seekg(0);
  while(!j.eof())
  {
j.read((char*)&f,sizeof(f));
    if(strcmp(f.getname(),name)==0)
    {

    if(f.getpass()==pss)
    {
fawindow();
    x++;
    }
     }
  }
j.close();
  if(x==0)
  {
cout<<"\n\t\t*************************************************";
cout<<"\n\t\t Sorry Wrong ID or Password Entered!!";
cout<<"\n\t\t Please Enter the valid one!";
cout<<"\n\t\t*************************************************";
cout<<"\n\t\t 1.Enter once again";
cout<<"\n\t\t 2.Go to main menu";
cout<<"\n\t\t*************************************************";
cout<<"\n\t\t         Enter you choice:";
cin>>ch1;
  if(ch1==2)
  {
flogin();
  }
  }
  }while(ch1==1);

}
 void signup()
{
ofstream o("farmers.dat",ios::binary|ios::app);
ofstream j("prices.dat",ios::binary|ios::app);
f.enter();
o.write((char*)&f,sizeof(f));
j.write((char*)&f,sizeof(f));
o.close();
j.close();
flogin();
}
void flogin()
  {
intch;
clrscr();
cout<<"\n\t\t*************************************************";
cout<<"\n\t\t\t\tFARMER LOGIN";
cout<<"\n\t\t*************************************************";
cout<<"\n\t\t1.EXISTING MEMBER";
cout<<"\n\t\t2.NEW MEMBER";
cout<<"\n\t\t3.BACK TO MAIN WINDOW";
cout<<"\n\t\t*************************************************";
cout<<"\n\t\t\t  Enter your choice:";
cin>>ch;
  if(ch==1)
  {
    login();
  }
  if(ch==2)
  {
    signup();
  }
  if(ch==3)
  {
mwindow();
  }
}
void mwindow()
{
intch;
clrscr();
cout<<"\n\t\t*************************************************";
cout<<"\n\t\t\t    FARMER'S   HELPING  HAND";
cout<<"\n\t\t*************************************************";
cout<<"\n\t\t                 1.FARMER";
cout<<"\n\t\t                 2.TRADER";
cout<<"\n\t\t                 3.OFFICIAL";
cout<<"\n\t\t                 4.EXIT";
cout<<"\n\t\t*************************************************";
cout<<"\n\t\t            Enter your choice:";
cin>>ch;
  if(ch==1)
  {
clrscr();
flogin() ;
  }
  if(ch==2)
  {
clrscr();
      bill();
  }
  if(ch==3)
  {
clrscr();
offmwindow();
  }
  if(ch==4)
  {
     exit(0);
  }
}
void sell()
{
ofstream o("prices.dat",ios::binary|ios::app);
int c;
cout<<"\n\t\t Enter the no of crops for sale :";
cin>>c;
  for(inti=0;i<c;i++)
  {
f.entercrop();
o.write((char*)&f,sizeof(f));
  }
o.close();
}
  void bill()
{
 char name[50],ccname[10],tname[30];
intq,ch,cno,cvv,ced,addn,rate=0,amt=0;long intno,adn;
disptfarmer();
 cout<<"\n\n\t***************************************************************";
cout<<"\n\t Enter the name of the farmer      : ";
 gets(name);
cout<<"\n\t Enter the name of the crop        : ";
 gets(ccname);
cout<<"\n\t Enter the quantity (per quintal)  : ";
cin>>q;
ifstreami("prices.dat",ios::binary);
i.seekg(0);
 while(i.read((char*)&f,sizeof(f)))
 {
 if(strcmp(f.getname(),name)==0)
 {
	   rate=f.getprice(ccname);
  }
  }
i.close();
amt=rate*q;
clrscr();
  cout<<"\n\n\n\n\t***************************************************************";
cout<<"\n\t\t              Enter your name :";
  gets(tname);
  cout<<"\n\t****************************************************************";
cout<<"\n\t\t                 PAYMENT MODES";
  cout<<"\n\t****************************************************************";
cout<<"\n\t\t               1.CREDIT/DEBIT CARD";
cout<<"\n\t\t               2.Cash on delivery";
  cout<<"\n\t****************************************************************";
cout<<"\n\t\t               Enter your choice : ";
cin>>ch;
  cout<<"\n\t****************************************************************";
  if(ch==1)
  {
clrscr();
   cout<<"\n\t*************************************************************";
cout<<"\n\n\t               PAYMENT BY CARD";
   cout<<"\n\n\t***********************************************************";
cout<<"\n\n\t             TOTAL AMOUNT    : "<<amt;
   cout<<"\n\n\t***********************************************************";
cout<<"\n\t              Enter the card number :";
cin>>cno;
cout<<"\n\t              Enter the expiry date :";
cin>>ced;
cout<<"\n\t              Enter the cvv         :";
cin>>cvv;
   cout<<"\n\t\t*************************************************************";
   }
  if(ch==2)
  {
cout<<"\n\t            Enter your aadhar number   :";
cin>>addn;
  }
  cout<<"\n\t**************************************************************";
cout<<"\n\t\t\t            BILL        ";
  cout<<"\n\t***************************************************************";
cout<<"\n\n\t\t       Name of buyer :"<<tname;
cout<<"\n\t\t         Name of seller:"<<name;
cout<<"\n\t\t         Name of crop  :"<<ccname;
  cout<<"\n\t**************************************************************";
cout<<"\n\t\t         Total amount  :"<<amt;
  if(ch==1)
  {
cout<<"\n\t\t     STATUS : TRANSACTION COMPLETED";
  }
  if(ch==2)
  {
cout<<"\n\t\t    STATUS : TRANSACTION PENDING";
  }
ifstream k("prices.dat",ios::binary);
  while(k.read((char*)&f,sizeof(f)))
  {
  if(strcmp(name,f.getname())==0)
  {
  no=f.getno(name);
adn=f.getan(name);
  }
  }
  cout<<"\n\t************************************************************";
cout<<"\n\t\t Phone no of farmer :"<<no;
cout<<"\n\t\t Aadhar no of farmer:"<<adn;
  cout<<"\n\t*************************************************************";
cout<<"\n\t Please take a screenshot of this bill for future use ";
  cout<<"\n\t*************************************************************";
k.close();
  }


class official
{
int date;
  char day;
int price;
  char crop[20];
  char fertile[20];
int temper;
  char info[60];
  public:
  void enter()
  {
cout<<"\n\t\t Enter the name of crop     :";
cin>>crop;
cout<<"\n\t\t Enter the price of the crop:";
cin>>price;
   }
   void show()
   {
cout<<"\n\t\t\t         "<<crop<<"        "<<price;
  }
    char* getcrop()
   { return crop;}
intgetprice()
   { return price;
   }

}of;
   void addcrop()
   {
ofstream o("sprices.dat",ios::binary|ios::app);
of.enter();
o.write((char*)&of,sizeof(of));
o.close();
   }
 void showcrop()
    {
clrscr();
ifstreami("sprices.dat",ios::binary);
    cout<<"\n\t\t**************************************************";
cout<<"\n\t\t\t\t"<<"CROP NAME"<<"   "<<"PRICE";
    cout<<"\n\t\t**************************************************";
cout<<"\n";
i.seekg(0);
    while(i.read((char*)&of,sizeof(of)))
    {
of.show();
    }
i.close();
    }
void delcrop()
     {
clrscr() ;
cout<<"\n\t\t*************************************************************";
cout<<"\n\t\t\t\t  DELETING THE RECORDS";
int x=0;
char crop[80];
ifstreami("sprices.dat",ios::in|ios::binary);
ofstream o("temp.dat",ios::out|ios::binary);
cout<<"\n\t\t***********************************************************";
cout<<"\n\t     Enter the crop name for deletion:";
      gets(crop);
       i.seekg(0);
       while(!i.eof())
       {
	i.read((char*)&of,sizeof(of));
	 if(i.eof())
	 break;
                  if(strcmpi(of.getcrop(),crop)==0)
	{
	cout<<"\n\t\t*************************************************";
	cout<<"\n\t\t\t\t  DELETING RECORDS";
	cout<<"\n\t\t*************************************************";
	of.show();
	 x++;
                }
              else
	{
	o.write((char*)&of,sizeof(of));
                 }
}
i.close();
o.close();
             if(x!=0)
	{
	cout<<"\n\t\t\t\t  RECORD DELETED!!!";
	  remove("sprices.dat");
	  rename("temp.dat","sprices.dat");
                  }else
	{ cout<<"\n\t\tRECORD NOT FOUND!!";
	} }
       void modinfo()
     {           clrscr();
	cout<<"\n\t\t*************************************************";
	cout<<"\n\t\t\t\t  UPDATING THE PRICES";
	cout<<"\n\t\t*************************************************";
                    int x=0;
	char crops[15];
	fstream f("sprices.dat",ios::binary|ios::in|ios::out);
	cout<<"\n\t\t Enter the name of the crop:";
	gets(crops);
	while(!f.eof())
	{ double pos=f.tellg();
	f.read((char*)&of,sizeof(of));
	if(strcmp(of.getcrop(),crops)==0)
	{cout<<"\n";
	cout<<"\n\t\t*************************************************";
	cout<<"\n\t\t\t\t   MODIFYING RECORD";
	cout<<"\n\t\t*************************************************";
	of.show();
	cout<<"\n\t\t*************************************************";
                of.enter();
	f.seekp(pos);
             f.write((char*)&of,sizeof(of));
	    x++;
	  }
	}
                 if(x==0)
	{
             cout<<"\n\t\t\t\tNO RECORD FOUND!!!";
	}
	else{
	cout<<"\n\t\t\t\t  RECORD MODIFIED";
	}
               f.close();
             }
      void offmwindow()
     {
	intch,id;
	 char ch1,ch2,pss[87];
	clrscr();
	 cout<<"\n\t\t**************************************************";
	cout<<"\n\t\t                OFFICIAL LOGIN";
	 cout<<"\n\t\t**************************************************";
	cout<<"\n\n\t\t           Enter the official id     :";
	cin>>id;
	cout<<"\n\t\t         Enter the official password :";
	 gets(pss);
	 cout<<"\n\t\t**************************************************";
	 if(strcmpi("iamofficialallowme",pss)==0)
	 {
	clrscr();
	 do{
                 cout<<"\n\t\t***************************************************";
	cout<<"\n\t\t\t         FOR ADMIN USE ONLY";
	 cout<<"\n\t\t***************************************************";
	cout<<"\n\t\t             1.ENTER THE CROP";
	cout<<"\n\t\t             2.UPDATE THE PRICES";
	cout<<"\n\t\t             3.DELETE SOME CROPS";
	cout<<"\n\t\t             4.LIST OF FARMERS";
	cout<<"\n\t\t             5.SHOW CROPS";
	cout<<"\n\t\t             6.EXIT";
	 cout<<"\n\t\t***************************************************";
	cout<<"\n\n\t\t         Enter your choice:";
	cin>>ch;
	 if(ch==1)
                       {
	    do{
	addcrop();
	cout<<"\n\t\tDo you want to enter more prices(y/n):";
	cin>>ch2;
	    }while(ch2=='y'||ch2=='Y');
                      }
                   if(ch==2)
	 {
	modinfo();
	 }
                   if(ch==3)
	 {
	delcrop();
	 }
	 if(ch==4)
	 {
	showfarmer();
	  }
                   if(ch==5)
	 {
	showcrop();
	 }
                    if(ch==6)
	 {
	   exit(0);
	 } }while(1);
	 }else{
	cout<<"\n\n\t\t\tWRONG OFFICAL ID AND PASSWORD ENTERED!!";
	mwindow();
	 }}
       void exadv()
       {  char crop[30];
	int ch,ch1;
	 do {
                  cout<<"\n\t***************************************************";
	cout<<"\n\n\t          EXPERT ADVICE FOR CROPS ";
	cout<<"\n\t***************************************************";
                  cout<<"\n\t***************************************************";
	cout<<"\n\t           SELECT THE APPROPRIATE OPTION";
	cout<<"\n\t***************************************************";
	cout<<"\n\t           1. KILL Pest ";
	cout<<"\n\t           2. Improve  quality ";
	cout<<"\n\t           3. Increase the fertility ";
	cout<<"\n\t           4. GO to main menu";
	cout<<"\n\t***************************************************";
	cout<<"\n\n\t      ENTER YOUR CHOICE(1-4) :: ";
                   cin>>ch;
                   if(ch==1)
	 {
                  cout<<"\n\t***************************************************";
	cout<<"\n\n\t   Enter the name of crop :";
	  gets(crop);
	cout<<"\n\t***************************************************";
	  if(strcmpi("rice",crop)==0)
	  { clrscr();
	cout<<"\n\t***************************************************";
	cout<<"\n\t      Pesticide to be used : A-50 CARBARYL ";
	cout<<"\n\t***************************************************";
	cout<<"\n\t             SUGGESTED SITES    ";
	cout<<"\n\t***************************************************";
	cout<<"\n\t           1.http://indian.gov.in";
	cout<<"\n\t           2.http://agribegri.com";
	cout<<"\n\t           3.http://bigbasket.com";
	cout<<"\n\t***************************************************";
cout<<"\n\tGET 30 % DISCOUNT ON agribegri.com by using code FARMHELP30"  ;
	cout<<"\n\t***************************************************";
	   }
                    if(strcmpi("wheat",crop)==0)
	  {
	cout<<"\n\t***************************************************";
	cout<<"\n\t      Pesticide to be used : A-30 XENO";
	cout<<"\n\t***************************************************";
	cout<<"\n\t             SUGGESTED SITES    ";
	cout<<"\n\t***************************************************";
	cout<<"\n\t           1.http://indian.gov.in";
	cout<<"\n\t           2.http://agribegri.com";
	cout<<"\n\t           3.http://bigbasket.com";
	cout<<"\n\t***************************************************";
cout<<"\n\tGET 30 % DISCOUNT ON agribegri.com by using code FARMHELP30"  ;
	cout<<"\n\t***************************************************";
	   }
                    if(strcmpi("jaw",crop)==0)
	  {
	cout<<"\n\t***************************************************";
	cout<<"\n\t      Pesticide to be used : A-45 LAWFER";
	cout<<"\n\t***************************************************";
	cout<<"\n\t             SUGGESTED SITES    ";
	cout<<"\n\t***************************************************";
	cout<<"\n\t           1.http://indian.gov.in";
	cout<<"\n\t           2.http://agribegri.com";
	cout<<"\n\t           3.http://bigbasket.com";
	cout<<"\n\t***************************************************";
cout<<"\n\tGET 30 % DISCOUNT ON agribegri.com by using code FARMHELP30"  ;
	cout<<"\n\t***************************************************";
	   }
	  }
	  if(ch==2)
	  {
	cout<<"\n\t***************************************************";
	cout<<"\n\t         CARE TO BE TAKEN FOR CROPS";
	cout<<"\n\t***************************************************";
	cout<<"\n\t           1. FOR RICE-->DO not over fertilise ";
	cout<<"\n		       DO not overwater      ";
	cout<<"\n			       Take proper care      ";
	cout<<"\n		               Do not delay harvesting   ";
	cout<<"\n\t           2.FOR WHEAT-->  DO not overweed";
	  }
	  if(ch==3)
                 {
	cout<<"\n\t***************************************************";
	cout<<"\n\t      SOME EXCELLENT FERTILISERS";
	cout<<"\n\t***************************************************";
	cout<<"\n             1.AMMONIUM NITRATE 33 00  ";
	cout<<"\n             2.Di-ammonium phosphate(DAP)";
	cout<<"\n             3.Mono-ammonium phosphate(MAP)";
	cout<<"\n             4.POTASSIUM CHLORIDE";
	cout<<"\n\t***************************************************";
	cout<<"\n\t             SUGGESTED SITES    ";
	cout<<"\n\t***************************************************";
	cout<<"\n\t           1.http://indian.gov.in";
	cout<<"\n\t           2.http://agribegri.com";
	cout<<"\n\t           3.http://bigbasket.com";
	cout<<"\n\t           4.http://getfertilizers.com";
	cout<<"\n\t***************************************************";
	cout<<"\n\tGET 30 % DISCOUNT ON getfertilizers.com by using code FARMHELP30"  ;
	cout<<"\n\t***************************************************";
	  }
                    if(ch==4)
	  {
	mwindow();
	  }
                    }while(1);
	  } }
void main()
{
clrscr();
mwindow();
getch();
}




