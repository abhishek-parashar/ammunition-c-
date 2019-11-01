//////////////////////////////////////////////////////////////////////////////
//
#include<dos.h>
#include<math.h>
#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<ctype.h>
#include<string.h>
#include<graphics.h>

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// class used for binary file
class record
{	char name[40];
	char add[50];
	char mn[10];
	char bank[20];
	char email[30];
	char accno[12];
	int lno;
  public: void enter();
	  void display();
	  void calc_lno()
	  {randomize();
	  lno=random(1000);
	  }
	  int ret_lno()
	  {return lno;}
  }   ;
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// class functions
void record::enter()
{
cout<<"Enter Name\n";
  gets(name);

  cout<<"\nEnter mobile number\n";
  for(int i=0;i<10;i++)
  {mn[i]=getch();
  cout<<mn[i];
  }
   cout<<"\nEnter address\n";
  gets(add);


  cout<<"\nEnter email ID\n";
  gets(email);

  cout<<"\n********************************************************************************\n" ;
  cout<<"	      \t			ACCOUNT DETAILS\n"   ;

  cout<<"Enter name of the bank\n";
  gets(bank);

  cout<<"\nEnter Account number (12-digit)\n";
  for( i=0;i<12;i++)
  {accno[i]=getch();
  cout<<accno[i];
  }

}

void record::display()
{cout<<"\nLicence Details:\n";
cout<<"Licence number :   "<<lno<<endl<<"Name :  "<<name<<endl<<"Mobile number :   " ;
for(int i=0;i<10;i++)
cout<<mn[i];

cout<<endl<<"Address :   "<<add<<endl<<"Email :   "<<email<<endl<<"Name of Bank :   "<<bank<<endl<<"Account number :   ";
for( i=0;i<12;i++)
cout<<accno[i];


}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//			   function declaration
// menu functions
void l_menu();
void ps_menu();
void p_menu();
void s_menu();
// sub menu functions
void ver_licence();
void new_licence();
void update_licence();
// weapon functions
void s_rifle();
void a_rifle();
void pistol();
void shotgun();
void muzzle();
void scope();
void clip();
void ammo();
// other functions
void welcome();

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/////////////////  		functions
/////			 licence related functions
//New licence
void new_licence()
{clrscr();
  record r1;
  ofstream o1("licence.dat",ios::binary|ios::app);
  cout<<"\n\tYou have applied for a new licence!!!\n\tStart by entering details\n\t(All fields are Mandatory) ";
  cout<<"\n********************************************************************************\n";
  r1.calc_lno();
  r1.ret_lno()    ;
  r1.enter();
  o1.write((char*)&r1,sizeof(r1));
  o1.close();
  cout<<"\n********************************************************************************\n" ;
  cout<<"       \t		CONGRATULATIONS!!! \n";
  cout<<"    	    \t	New Licence Issued!!!\n";
  cout<<"Licence number\t"<<r1.ret_lno()<<endl;

  system("pause");
  l_menu();

  }
//update licence
 void update()
{clrscr();
int i,y,z,lno,flag=0,pos;
record r1;
fstream i1("licence.dat",ios::binary|ios::in|ios::out)   ;
cout<<"\n\n********************************************************************************\n" ;
cout<<" Please Enter your Licence number  \n"   ;

cin>>lno;
cout<<"\nScanning for records........please wait";
// dot loop
for(i=0;i<3;i++)
{gotoxy(40,8);
 for(y=0;y<4;y++)
	{cout<<".";
	 delay(300);
	}
  gotoxy(40,8);
  for(z=0;z<4;z++)
	{cout<<" ";
	 delay(300);
	}
 }

cout<<"\nscanning complete!!!";
cout<<"\n********************************************************************************\n" ;
while(i1.read((char*)&r1,sizeof(r1)))
	{
		if(r1.ret_lno()==lno)
		{	cout<<"Match found!!!\n";
			r1.display();
			cout<<"\n\nEnter new values\n\n";
			pos = i1.tellg()-sizeof(r1);
			i1.seekp(pos,ios::beg);
			r1.enter();
			i1.write((char*)&r1,sizeof(r1));
			flag=1;
			break;
		}
	 }
if(flag!=1)
	cout<<"No record found\n";
else
	cout<<"\nModification successful\n";
   system("pause");
 i1.close();
 l_menu();
}





//verify licence
void ver_licence()
{clrscr();
int lno,i,y,z,flag=0;
record r1;
ifstream i1("licence.dat",ios::binary|ios::in)   ;
cout<<"\n********************************************************************************\n" ;
cout<<" \nPlease Enter your Licence number  \n"   ;

cin>>lno;
cout<<"\nScanning for records........please wait";
// dot loop
for(i=0;i<3;i++)
{gotoxy(40,8);
 for(y=0;y<4;y++)
	{cout<<".";
	 delay(300);
	}
  gotoxy(40,8);
  for(z=0;z<4;z++)
	{cout<<" ";
	 delay(300);
	}
 }

cout<<"\nscanning complete!!!";
cout<<"\n********************************************************************************\n" ;
while(i1.read((char*)&r1,sizeof(r1)))
{
	if(r1.ret_lno()==lno)
	{	cout<<"Match found!!!\n";
		r1.display(); cout<<"\n"; flag=1;
	 }


 }
if(flag!=1)
	cout<<"No record found\n";
   system("pause");
 i1.close();
 if(flag==1)
 p_menu();
 else
 l_menu();
}


/////////////////////////////////////////////////////////////////////////////
  // menu functions
//  licence menu
void l_menu()
{ clrscr();
  int n=0;
  cout<<"\n\n ********************  Welcome To Ammu-Nation ******************** \n";
  cout<<" Let's Begin by Verifying Your Licence !!!\n";
  while(n!=5)
  { cout<<"1.Verify Licence\n";
    cout<<"2.New Licence\n";
    cout<<"3.Update Licence\n";
    cout<<"4.Exit Shop";
    cout<<"\nEnter Choice(1-4)\n";
    cin>>n;
    switch(n)
    { case 1: ver_licence();
	      break;
      case 2: new_licence();
	      break;
      case 3:   update();
	      break;
      case 4: exit(0);
	      break;
     default: cout<<"\n Invalid choice\n\n";
    }
   }

}



void p_menu()
{clrscr(); int n;
 cout<<"\n\n\t\tWelcome to the ARSENAL\n";

 while(n!=10)
  { cout<<"Weapons:\n\t";
    cout<<"1.Sniper Rifles\n\t";
    cout<<"2.Assault Rifles\n\t";
    cout<<"3.Shotguns\n\t";
    cout<<"4.Pistols\n";
    cout<<"Accessories:\n\t";
    cout<<"5.Muzzle\n\t";
    cout<<"6.Ammo\n\t";
    cout<<"7.Scope\n\t";
    cout<<"8.Clip\n";
    cout<<"Press 9 to Exit";
    cout<<"\nEnter Choice(1-9)\n";
    cin>>n;
    switch(n)
    { case 1:s_rifle();
	      break;
      case 2:a_rifle();
	      break;
      case 3:shotgun();
	      break;
      case 4:pistol();
	      break;
      case 5:muzzle();
	      break;
      case 6:ammo();
	      break;
      case 7:scope();
	      break;
      case 8:clip();
	      break;
      case 9: exit(0);
	      break;
     default: cout<<"\n Invalid choice\n\n";
    }
   }
}
//////////////////////////////////////////////////////////////////////////////

///transations
void purchase(int price)
{clrscr();
char n[12], p[4];
int i,y,z;
cout<<"********************************************************************************\n"     ;
cout<<"Enter your account number\n";
gets(n);
cout<<"Enter your 4-digit pin\n";

for(i=0;i<4;i++)
{p[i]=getch();
 cout<<p[i];
}
gotoxy(1,6);
for(i=0;i<4;i++)
{
 p[i]='*';
 cout<<p[i];
 delay(500);
 }


gotoxy(1,7);
cout<<"Please wait while transaction is in process";
for(i=0;i<3;i++)
{gotoxy(44,7);
 for(y=0;y<4;y++)
	{cout<<".";
	 delay(300);
	}
  gotoxy(44,7);
  for(z=0;z<4;z++)
	{cout<<" ";
	 delay(300);
	}
 }
cout<<endl;
cout<<"Transaction successful !!!\n$  ";
cout<<price<<" will be deducted from your account\nYour equipment will be delivered shortly !!!\n\nNice doing business with you ;)\n";
system("pause");
p_menu();
}

void trans(int cost)
{ long q,c;  char t;

cout<<"\n\nEnter Quantity:\n";
cin>>q;
c=cost*q ;
cout<<"________________________________________________________________________________\n"     ;
cout<<"Total Cost :\t$ "<<c<<endl;
cout<<"________________________________________________________________________________\n"      ;
cout<<"Do you want to confirm your order? (Y/N)\n";
cin>>t;
if(t=='y'||t=='Y')
	purchase(c);
else
	p_menu();

}
////////////////////sniper rifle
void s_rifle()
{clrscr();
 cout<<" ***************************************************************** \n\n";
 cout<<" Select your sniper rifle\n";

//code for table
    int i,y,n;
  for(i=0;i<70;i++)
  {
  gotoxy(i,4);
  cout<<"_";
   gotoxy(i,6);
  cout<<"_";
  gotoxy(i,16)    ;
  cout<<"_";
  }
  for(i=5;i<17;i++)
  {gotoxy(1,i) ;
  cout<<"|";
  gotoxy(6,i);
  cout<<"|";
  gotoxy(50,i);
  cout<<"|";
  gotoxy(70,i);
  cout<<"|";
  }
  y=1;
  gotoxy(2,5);
    cout<<"Sno.";
  gotoxy(20,5)  ;
  cout<<"Rifle name";
  gotoxy(58,5);
    cout<<"Cost";

  for(i=7;i<16;i=i+2)
  { for(;y<6;)
    {gotoxy(2,i);
    cout<<y<<".";
    y++;
    break;
    }
   }
 //        name
   gotoxy(7,7);
    cout<<"M 82 Barret .50 cal";
   gotoxy(7,9)            ;
    cout<<"Mosin-Nagant" ;
    gotoxy(7,11) ;
    cout<<"Dragunov SVD";
    gotoxy(7,13)            ;
    cout<<"L 42 Enfield";
    gotoxy(7,15)            ;
    cout<<"L 115 A3 AWM";

 //   cost

   gotoxy(51,7);
    cout<<"$ 8999";
   gotoxy(51,9)            ;
    cout<<"$ 439" ;
    gotoxy(51,11) ;
    cout<<"$ 5999";
    gotoxy(51,13)            ;
    cout<<"$ 550";
    gotoxy(51,15)            ;
    cout<<"$ 34999";
   //
 gotoxy(1,17)  ;
 cout<<"\nPress 6 to go back to previous menu\n";
 cout<<"Press 7 to exit shop\n";
 while(n!=8)
  { cout<<"\nEnter choice\n";
    cin>>n;
    switch(n)
    { case 1: trans(8999);
	      break;
      case 2: trans(439);
	      break;
      case 3: trans(5999);
	      break;
      case 4: trans(550);
	      break;
      case 5: trans(34999);
	      break;
      case 6: p_menu();
	      break;
      case 7: exit(0);
	      break;
     default: cout<<"\n Invalid choice\n\n";
    }
   }
}

////////////////assault rifle
void a_rifle()
{clrscr();
 cout<<" ***************************************************************** \n\n";
 cout<<" Select your assault sniper rifle\n";

//code for table
    int i,y,n;
  for(i=0;i<70;i++)
  {
  gotoxy(i,4);
  cout<<"_";
   gotoxy(i,6);
  cout<<"_";
  gotoxy(i,16)    ;
  cout<<"_";
  }
  for(i=5;i<17;i++)
  {gotoxy(1,i) ;
  cout<<"|";
  gotoxy(6,i);
  cout<<"|";
  gotoxy(50,i);
  cout<<"|";
  gotoxy(70,i);
  cout<<"|";
  }
  y=1;
  gotoxy(2,5);
    cout<<"Sno.";
  gotoxy(20,5)  ;
  cout<<"Rifle name";
  gotoxy(58,5);
    cout<<"Cost";

  for(i=7;i<16;i=i+2)
  { for(;y<6;)
    {gotoxy(2,i);
    cout<<y<<".";
    y++;
    break;
    }
   }
 //        name
   gotoxy(7,7);
    cout<<"AK-47";
   gotoxy(7,9)            ;
    cout<<"M4 A1" ;
    gotoxy(7,11) ;
    cout<<"Steyr AUG";
    gotoxy(7,13)            ;
    cout<<"FN scar";
    gotoxy(7,15)            ;
    cout<<"Famas";

 //   cost

   gotoxy(51,7);
    cout<<"$ 3399";
   gotoxy(51,9)            ;
    cout<<"$ 2199" ;
    gotoxy(51,11) ;
    cout<<"$ 1799";
    gotoxy(51,13)            ;
    cout<<"$ 2899";
    gotoxy(51,15)            ;
    cout<<"$ 2250";
   //
 gotoxy(1,17)  ;
 cout<<"\nPress 6 to go back to previous menu\n";
 cout<<"Press 7 to exit shop\n";
 while(n!=8)
  { cout<<"\nEnter choice\n";
    cin>>n;
    switch(n)
    { case 1: trans(3399);
	      break;
      case 2: trans(2199);
	      break;
      case 3: trans(1799);
	      break;
      case 4: trans(2899);
	      break;
      case 5: trans(2250);
	      break;
      case 6: p_menu();
	      break;
      case 7: exit(0);
	      break;
     default: cout<<"\n Invalid choice\n\n";
    }
   }
}
////////////////////Pistol
void pistol()
{clrscr();
 cout<<" ***************************************************************** \n\n";
 cout<<" Select your pistol\n";

//code for table
    int i,y,n;
  for(i=0;i<70;i++)
  {
  gotoxy(i,4);
  cout<<"_";
   gotoxy(i,6);
  cout<<"_";
  gotoxy(i,16)    ;
  cout<<"_";
  }
  for(i=5;i<17;i++)
  {gotoxy(1,i) ;
  cout<<"|";
  gotoxy(6,i);
  cout<<"|";
  gotoxy(50,i);
  cout<<"|";
  gotoxy(70,i);
  cout<<"|";
  }
  y=1;
  gotoxy(2,5);
    cout<<"Sno.";
  gotoxy(20,5)  ;
  cout<<"Pistol name";
  gotoxy(58,5);
    cout<<"Cost";

  for(i=7;i<16;i=i+2)
  { for(;y<6;)
    {gotoxy(2,i);
    cout<<y<<".";
    y++;
    break;
    }
   }
 //        name
   gotoxy(7,7);
    cout<<"CZ 75 SP-01";
   gotoxy(7,9)            ;
    cout<<"Walther PPQ" ;
    gotoxy(7,11) ;
    cout<<"Beretta 92FS";
    gotoxy(7,13)            ;
    cout<<"Taurus PT 92";
    gotoxy(7,15)            ;
    cout<<"Glock 17 Gen 4";

 //   cost

   gotoxy(51,7);
    cout<<"$ 599";
   gotoxy(51,9)            ;
    cout<<"$ 549" ;
    gotoxy(51,11) ;
    cout<<"$ 599";
    gotoxy(51,13)            ;
    cout<<"$ 499";
    gotoxy(51,15)            ;
    cout<<"$ 569";
   //
 gotoxy(1,17)  ;
 cout<<"\nPress 6 to go back to previous menu\n";
 cout<<"Press 7 to exit shop\n";
 while(n!=8)
  { cout<<"\nEnter choice\n";
    cin>>n;
    switch(n)
    { case 1: trans(599);
	      break;
      case 2: trans(549);
	      break;
      case 3: trans(599);
	      break;
      case 4: trans(499);
	      break;
      case 5: trans(569);
	      break;
      case 6: p_menu();
	      break;
      case 7: exit(0);
	      break;
     default: cout<<"\n Invalid choice\n\n";
    }
   }
}
/////////////shotguns
void shotgun()
{clrscr();
 cout<<" ***************************************************************** \n\n";
 cout<<" Select your shotgun\n";

//code for table
    int i,y,n;
  for(i=0;i<70;i++)
  {
  gotoxy(i,4);
  cout<<"_";
   gotoxy(i,6);
  cout<<"_";
  gotoxy(i,16)    ;
  cout<<"_";
  }
  for(i=5;i<17;i++)
  {gotoxy(1,i) ;
  cout<<"|";
  gotoxy(6,i);
  cout<<"|";
  gotoxy(50,i);
  cout<<"|";
  gotoxy(70,i);
  cout<<"|";
  }
  y=1;
  gotoxy(2,5);
    cout<<"Sno.";
  gotoxy(20,5)  ;
  cout<<"Shotgun name";
  gotoxy(58,5);
    cout<<"Cost";

  for(i=7;i<16;i=i+2)
  { for(;y<6;)
    {gotoxy(2,i);
    cout<<y<<".";
    y++;
    break;
    }
   }
 //        name
   gotoxy(7,7);
    cout<<"Remington 870";
   gotoxy(7,9)            ;
    cout<<"Browning BPS" ;
    gotoxy(7,11) ;
    cout<<"Perazzi MX8";
    gotoxy(7,13)            ;
    cout<<"Beretta DT 11";
    gotoxy(7,15)            ;
    cout<<"Blaser F3";

 //   cost

   gotoxy(51,7);
    cout<<"$ 411";
   gotoxy(51,9)            ;
    cout<<"$ 569" ;
    gotoxy(51,11) ;
    cout<<"$ 9861";
    gotoxy(51,13)            ;
    cout<<"$ 8050";
    gotoxy(51,15)            ;
    cout<<"$ 7250";
   //
 gotoxy(1,17)  ;
 cout<<"\nPress 6 to go back to previous menu\n";
 cout<<"Press 7 to exit shop\n";
 while(n!=8)
  { cout<<"\nEnter choice\n";
    cin>>n;
    switch(n)
    { case 1: trans(8999);
	      break;
      case 2: trans(439);
	      break;
      case 3: trans(5999);
	      break;
      case 4: trans(550);
	      break;
      case 5: trans(34999);
	      break;
      case 6: p_menu();
	      break;
      case 7: exit(0);
	      break;
     default: cout<<"\n Invalid choice\n\n";
    }
   }
}
///////////////////Muzzle
void muzzle()
{clrscr();
 cout<<" ***************************************************************** \n\n";
 cout<<" Select your muzzle type\n";

//code for table
    int i,y,n;
  for(i=0;i<70;i++)
  {
  gotoxy(i,4);
  cout<<"_";
   gotoxy(i,6);
  cout<<"_";
  gotoxy(i,14)    ;
  cout<<"_";
  }
  for(i=5;i<15;i++)
  {gotoxy(1,i) ;
  cout<<"|";
  gotoxy(6,i);
  cout<<"|";
  gotoxy(50,i);
  cout<<"|";
  gotoxy(70,i);
  cout<<"|";
  }
  y=1;
  gotoxy(2,5);
    cout<<"Sno.";
  gotoxy(20,5)  ;
  cout<<" type";
  gotoxy(58,5);
    cout<<"Cost";

  for(i=7;i<16;i=i+2)
  { for(;y<5;)
    {gotoxy(2,i);
    cout<<y<<".";
    y++;
    break;
    }
   }
 //        name
   gotoxy(7,7);
    cout<<"Sniper rifle muzzle ";
   gotoxy(7,9)            ;
    cout<<"Assault rifle muzzle";
    gotoxy(7,11) ;
    cout<<"Pistol muzzle";
    gotoxy(7,13)            ;
    cout<<"Shotgun muzzle";


 //   cost

   gotoxy(51,7);
    cout<<"$ 400";
   gotoxy(51,9)            ;
    cout<<"$ 350" ;
    gotoxy(51,11) ;
    cout<<"$ 149";
    gotoxy(51,13)            ;
    cout<<"$ 225";

   //
 gotoxy(1,17)  ;
 cout<<"\nPress 6 to go back to previous menu\n";
 cout<<"Press 7 to exit shop\n";
 while(n!=8)
  { cout<<"\nEnter choice\n";
    cin>>n;
    switch(n)
    { case 1: trans(400);
	      break;
      case 2: trans(350);
	      break;
      case 3: trans(149);
	      break;
      case 4: trans(225);
	      break;
      case 6: p_menu();
	      break;
      case 7: exit(0);
	      break;
     default: cout<<"\n Invalid choice\n\n";
    }
   }
}
//////////////////scope
void scope()
{clrscr();
 cout<<" ***************************************************************** \n\n";
 cout<<" Select your scope type\n";

//code for table
    int i,y,n;
  for(i=0;i<70;i++)
  {
  gotoxy(i,4);
  cout<<"_";
   gotoxy(i,6);
  cout<<"_";
  gotoxy(i,14)    ;
  cout<<"_";
  }
  for(i=5;i<15;i++)
  {gotoxy(1,i) ;
  cout<<"|";
  gotoxy(6,i);
  cout<<"|";
  gotoxy(50,i);
  cout<<"|";
  gotoxy(70,i);
  cout<<"|";
  }
  y=1;
  gotoxy(2,5);
    cout<<"Sno.";
  gotoxy(20,5)  ;
  cout<<" type";
  gotoxy(58,5);
    cout<<"Cost";

  for(i=7;i<16;i=i+2)
  { for(;y<5;)
    {gotoxy(2,i);
    cout<<y<<".";
    y++;
    break;
    }
   }
 //        name
   gotoxy(7,7);
    cout<<"Sniper rifle scope";
   gotoxy(7,9)            ;
    cout<<"Assault rifle scope";
    gotoxy(7,11) ;
    cout<<"Pistol scope";
    gotoxy(7,13)            ;
    cout<<"Shotgun scope";


 //   cost

   gotoxy(51,7);
    cout<<"$ 250";
   gotoxy(51,9)            ;
    cout<<"$ 200" ;
    gotoxy(51,11) ;
    cout<<"$ 125";
    gotoxy(51,13)            ;
    cout<<"$ 180";

   //
 gotoxy(1,17)  ;
 cout<<"\nPress 6 to go back to previous menu\n";
 cout<<"Press 7 to exit shop\n";
 while(n!=8)
  { cout<<"\nEnter choice\n";
    cin>>n;
    switch(n)
    { case 1: trans(250);
	      break;
      case 2: trans(200);
	      break;
      case 3: trans(125);
	      break;
      case 4: trans(180);
	      break;
      case 6: p_menu();
	      break;
      case 7: exit(0);
	      break;
     default: cout<<"\n Invalid choice\n\n";
    }
   }
}
//////////////////ammo
void ammo()
{clrscr();
 cout<<" ***************************************************************** \n\n";
 cout<<" Select your ammo type\n";

//code for table
    int i,y,n;
  for(i=0;i<70;i++)
  {
  gotoxy(i,4);
  cout<<"_";
   gotoxy(i,6);
  cout<<"_";
  gotoxy(i,14)    ;
  cout<<"_";
  }
  for(i=5;i<15;i++)
  {gotoxy(1,i) ;
  cout<<"|";
  gotoxy(6,i);
  cout<<"|";
  gotoxy(50,i);
  cout<<"|";
  gotoxy(70,i);
  cout<<"|";
  }
  y=1;
  gotoxy(2,5);
    cout<<"Sno.";
  gotoxy(20,5)  ;
  cout<<" type";
  gotoxy(58,5);
    cout<<"Cost";

  for(i=7;i<16;i=i+2)
  { for(;y<5;)
    {gotoxy(2,i);
    cout<<y<<".";
    y++;
    break;
    }
   }
 //        name
   gotoxy(7,7);
    cout<<"Sniper rifle ammo";
   gotoxy(7,9)            ;
    cout<<"Assault rifle ammo";
    gotoxy(7,11) ;
    cout<<"Pistol ammo";
    gotoxy(7,13)            ;
    cout<<"Shotgun ammo";


 //   cost

   gotoxy(51,7);
    cout<<"$ 125";
   gotoxy(51,9)            ;
    cout<<"$ 100" ;
    gotoxy(51,11) ;
    cout<<"$ 50";
    gotoxy(51,13)            ;
    cout<<"$ 75";

   //
 gotoxy(1,17)  ;
 cout<<"\nPress 6 to go back to previous menu\n";
 cout<<"Press 7 to exit shop\n";
 while(n!=8)
  { cout<<"\nEnter choice\n";
    cin>>n;
    switch(n)
    { case 1: trans(125);
	      break;
      case 2: trans(100);
	      break;
      case 3: trans(50);
	      break;
      case 4: trans(75);
	      break;
      case 6: p_menu();
	      break;
      case 7: exit(0);
	      break;
     default: cout<<"\n Invalid choice\n\n";
    }
   }
}
////////////////////////////////// clip
void clip()
{clrscr();
 cout<<" ***************************************************************** \n\n";
 cout<<" Select your clip type\n";

//code for table
    int i,y,n;
  for(i=0;i<70;i++)
  {
  gotoxy(i,4);
  cout<<"_";
   gotoxy(i,6);
  cout<<"_";
  gotoxy(i,14)    ;
  cout<<"_";
  }
  for(i=5;i<15;i++)
  {gotoxy(1,i) ;
  cout<<"|";
  gotoxy(6,i);
  cout<<"|";
  gotoxy(50,i);
  cout<<"|";
  gotoxy(70,i);
  cout<<"|";
  }
  y=1;
  gotoxy(2,5);
    cout<<"Sno.";
  gotoxy(20,5)  ;
  cout<<" type";
  gotoxy(58,5);
    cout<<"Cost";

  for(i=7;i<16;i=i+2)
  { for(;y<5;)
    {gotoxy(2,i);
    cout<<y<<".";
    y++;
    break;
    }
   }
 //        name
   gotoxy(7,7);
    cout<<"Sniper rifle clip";
   gotoxy(7,9)            ;
    cout<<"Assault rifle clip";
    gotoxy(7,11) ;
    cout<<"Pistol clip";
    gotoxy(7,13)            ;
    cout<<"Shotgun clip";


 //   cost

   gotoxy(51,7);
    cout<<"$ 75";
   gotoxy(51,9)            ;
    cout<<"$ 50" ;
    gotoxy(51,11) ;
    cout<<"$ 40";
    gotoxy(51,13)            ;
    cout<<"$ 30";

   //
 gotoxy(1,17)  ;
 cout<<"\nPress 6 to go back to previous menu\n";
 cout<<"Press 7 to exit shop\n";
 while(n!=8)
  { cout<<"\nEnter choice\n";
    cin>>n;
    switch(n)
    { case 1: trans(75);
	      break;
      case 2: trans(50);
	      break;
      case 3: trans(40);
	      break;
      case 4: trans(30);
	      break;
      case 6: p_menu();
	      break;
      case 7: exit(0);
	      break;
     default: cout<<"\n Invalid choice\n\n";
    }
   }
}
void welcome()
{int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\turboc3\\bgi");

{setbkcolor(BLACK);
 settextstyle(2,0,9) ;
setcolor(WHITE);
outtextxy(40,100,"WELCOME TO...");
settextstyle(4,0,7);


setcolor(GREEN);
outtextxy(30,150,"A");
outtextxy(475,150,"N");
delay(300);
outtextxy(80,150,"M");
outtextxy(440,150,"O");
delay(300);
outtextxy(130,150,"M");
outtextxy(405,150,"I");
delay(300);
outtextxy(180,150,"U");
outtextxy(370,150,"T");
delay(300);
outtextxy(230,150,"-");
outtextxy(325,150,"A");
delay(300);
outtextxy(280,150,"N");


settextstyle(6,0,4);
outtextxy(10,275,"BUY THEM CHEAP....BURY THEM DEEP");
settextstyle(7,0,4);
setcolor(WHITE);
outtextxy(30,350,"OUT OF AMMO ??? VISIT US");
outtextxy(100,400,"CONTACT::011-2337823");

}
getch();
closegraph();

}


 void main()
 {clrscr();
 welcome();
l_menu();
 }
