#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>
class video
{
 int vid,vprice;
 char vsinger[50];
 char vactor[50];
 char vname[50];
 char vdirector[50];
 float vdiscount;
 public:
 void enter_record();
 void search_video_id();
 void search_video_name();
 void search_video_singer();
 void modify();
void viewallrecords();
 void delete_record();
 void output();
}s;
void video::enter_record()
{
cout<<"\nEnter the Detail of Video\n\nID: ";
cin>>vid;
cout<<"\nName of video: ";
gets(vname);
cout<<"\nName of singer: ";
gets(vsinger);
cout<<"\nName of actor: ";
gets(vactor);
cout<<"\nName of director: ";
gets(vdirector);
cout<<"\nPrice: ";
cin>>vprice;
}
void video::output()
{
cout<<"\nDetail of Video\n\nID: ";
cout<<vid;
cout<<"\nName of video: ";
puts(vname);
cout<<"\nName of singer: ";
puts(vsinger);
cout<<"\nName of actor: ";
puts(vactor);
cout<<"\nName of director: ";
puts(vdirector);
cout<<"\nPrice: ";
cout<<vprice;
}
void video::search_video_id()
{
int n,f=0;
fstream a;
video v;
a.open("video.dat",ios::in|ios::binary);
cout<<"Enter id to be searched";
cin>>n;
while(!a.eof())
{
a.read((char*)&s,sizeof (s));
if(s.vid==n)
{
s.output();
f=1;

break;
}
}
if(f==0)
cout<<"\n No such record found";
}
void video::search_video_name()
{
int f=0;
char c[50];
fstream a;
video v;
a.open("video.dat",ios::in|ios::binary);
cout<<"Enter name of the video to be searched";
gets(c);
while(!a.eof())
{
a.read((char*)&s,sizeof (s));
if(strcmpi(s.vname,c)==0)
{
s.output();
f=1;
}
}
if(f==0)
cout<<"\n No such record found";
}
void video::search_video_singer()
{
int f=0;
char c[50];
fstream a;
video v;
a.open("video.dat",ios::in|ios::binary);
cout<<"Enter the singer name to be searched";
gets(c);
while(!a.eof())
{
a.read((char*)&s,sizeof (s));
if(strcmpi(s.vsinger,c)==0)
{
f=1;
s.output();
}
}
if(f==0)
cout<<"\nNo such record Found";
}
void video::modify()
{
fstream f;
int n;
int r=0;
cout<<"\n Enter id to be modified";
cin>>n;
f.open("video.dat",ios::in|ios::app|ios::binary);
while(f.read((char*)&s,sizeof (s)))
{
if(s.vid==n)
{
cout<<"Enter new detail";
s.enter_record();
f.seekp((-1)*sizeof(s));
f.write((char*)&s,sizeof (s));
r=1;
break;
}
}
f.close();
if(r==0)
cout<<"\n no such record found";
};
void video::delete_record()
{
fstream f,o;
f.open("video.dat",ios::in|ios::binary);
o.open("temp.dat",ios::out|ios::binary);
int n,flag=0;
cout<<"\nEnter the Record ID to be deleted";
cin>>n;
video v;
while(f.read((char*)&v,sizeof(v)))
{
if(v.vid!=n)
o.write((char*)&v,sizeof(v));
else
flag=1;
}
f.close();
o.close();
if(flag==1)
{
remove("video.dat");
rename("temp.dat","video.dat");
cout<<"\nRecord Deleted";
}
else
cout<<"\n\aWrong ID";
getch();
}
void video::viewallrecords()
{
fstream b;
video v;
int c=0;
b.open("video.dat",ios::in|ios::binary);
if(!b)
{
cout<<"Cannot open file";
return;
}
while(b.read((char*)&v,sizeof(v)))
{
v.output();
c++;
}
if(c==0)
cout<<"\nNo Video in Stock this time";
getch();
}
void intro()
{
	clrscr();
	gotoxy(20,7);
	char str[]="      VIDEO MANAGEMENT SYSTEM      ";
	for (int count=0;str[count]!='\0';count++)
	{
	cout<<str[count];
	delay(100);
	}
	cout<<"\n\n\n\n\n\n\t\t\t";
	char str2[]="Developed By: KABEER SINGH";
	for (count=0;str2[count]!='\0';count++)
	{
	cout<<str2[count];
	delay(100);
	}
	gotoxy(20,15);
	//cout<<"\n\n\t\t";
	char str3[]="School: Kendriya Vidyalaya Aliganj";
	for (count=0;str3[count]!='\0';count++)
	{
	cout<<str3[count];
	delay(100);
	}
	getch();
}
void credits()
{
	clrscr();
	cout<<"\n\n\t\t\tCREDITS\n\n\n";
	cout<<"\t\tDeveloper-\tKabeer Singh";
	delay(2000);
	cout<<"\n\n\t\tFor more details and suggestions.....\n\t\tContact-kabeer17singh@gmail.com\n\n";
	delay(2000);
	cout<<"\n\t\t\tInspirations-\n\n\t\t\tMr Paritosh Srivastava\n\t\t\tPGT Computer Science";
	delay(2000);
	getch();
	clrscr();
	cout<<"\n\n\n\n\n\n\t\t\tThank you . . . .";
	getch();
}
void main()
{

int ch;
char c;
intro();
video v;
do
{
clrscr();
cout<<"\n\t\t\******  Menu  ******\n"
<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
<<"\n\n\t\t1.add a record \n\n\t\t2.search a record \n\n"
<<"\t\t3.modify a record \n\n\t\t4.delete a record\n\n\t\t5.view all records \n\n\t\t6.exit"
<<"\n\n\t\tEnter your choice\n\n\n\t\t";
cin>>ch;
switch(ch)
{
case 1:
	clrscr();
	v.enter_record();
	fstream f;
	f.open("video.dat",ios::app|ios::binary);
	f.write((char*)&v,sizeof(v));
	f.close();
	break;
case 2:
	int l;
	cout<<"\nWant to search by\n1.Id number\n2.Video name\n3.Singer name";
	cin>>l;
	if(l==1)
	v.search_video_id();
	else if(l==2)
	v.search_video_name();
	else if(l==3)
	v.search_video_singer();
	else
	cout<<"\n Wrong choice";
	break;
case 3:
	v.modify();
	break;
case 4:
	v.delete_record();
	break;
case 5: clrscr();
	v.viewallrecords();
	break;
case 6:
	credits();
	exit(0);
	break;
default:cout<<"Wrong Choice entered";
}
cout<<"\nWant to go bank to menu(y/n)";
cin>>c;
}while(c=='y'||c=='Y');
getch();
}

