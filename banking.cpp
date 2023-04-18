# include<iostream.h>
# include<stdlib.h>
# include<fstream.h>
# include<graphics.h>
# include<string.h>
# include<stdio.h>
# include<process.h>
# include<conio.h>
# include<dos.h>
#include <stdio.h>
#include <time.h>


class locker
{
	int locno;
	char pass[20];
	public:
	int get(int);
	int open_loc();
	void open_newloc();
	void close_loc();
}l;




class atm
{
	int atm_no;
	public:
	int get_data(int);
	void open_atm();
	void new_atmacc();
	void close_atm();
}at_mac;



class bank
{
	int accno;
	int locnum;
	int atmnum;
	char password[10];
	char name[20];
	char sex;
	int age;
	char address[20];
	long int bal;
	char particulars[20];
	long int chequeno;
	struct date d;
	int mm,dd,yy;
	public:
	void getdata();
void disp(int);
	void display(int,int,int);
	void list_accno();
	void locker();
	void modify_accno();
	void credit_accno();
	void debit_accno();
	void close_accno();
	void edit_account();
	void daily_trans();
	void detail_accno();
	friend locker::open_newloc();
	friend int locker::open_loc();
	friend locker::close_loc();
	friend atm::new_atmacc();
	friend atm::open_atm();
	friend atm::close_atm();

}b;

int n=sizeof(b);
char *wday[] = {"Sunday", "Monday", "Tuesday", "Wednesday",
 "Thursday", "Friday", "Saturday", "Unknown"};



int locker::get(int i)
{
	fstream file2;
	int loc,g=-1;
	int w=sizeof(l);
	file2.open("locker",ios::in|ios::out|ios::app|ios::binary);
	file2.seekg(-w,ios::end);
	file2.read((char*)&l,sizeof(l));
	loc=locno;
	++loc;
	gotoxy(10,++i);
	cout<<"Your Locker No.:";
	gotoxy(50,i);
	cout<<":";
	cout<<loc;
	locno=loc;
	char Ch,p1[20],p2[20];
	do
	{
		gotoxy(10,++i);
		cout<<"Enter Password For Locker";
		gotoxy(50,i);
		cout<<":";
		do
		{
		++g;
		Ch=getch();
		p1[g]=char(Ch);
		cout<<"*";
		}
while(Ch!=13);
		p1[++g]='\0';
		g=-1;
		gotoxy(10,++i);
		cout<<"Confirm Password";
		gotoxy(50,i);
		cout<<":";
		do
		{
		++g;
		Ch=getch();
		p2[g]=char(Ch);
		cout<<"*";
		}
		while(Ch!=13);
		p2[++g]='\0';
	}
	while(strcmp(p1,p2)!=0);
	strcpy(pass,p1);
	cin>>pass;
	if(file2.eof())
	file2.clear();
	file2.write((char*)&l,sizeof(l));
	file2.close();
	return(loc);
}


void bank::getdata()
{
	int gd=DETECT,gm,loan_ch;
	initgraph(&gd,&gm,"d:\\tc\\bgi");
	setbkcolor(9);
	setcolor(WHITE);
	char ch,choice,loc_ch;
	fstream file,file2;
	file.open("current",ios::in|ios::out|ios::binary);
	int a=0,q=0,i=6,c=0;
	static int ac;
	while(file.read((char *)&b,sizeof(b)))
	ac=accno;
	++ac;
	file.seekp(0,ios::end);
	if(file.eof())
	file.clear();
	getdate(&d);
	mm=d.da_mon;
	dd=d.da_day;
	yy=d.da_year;
	gotoxy(10,3);
	cout<<"DATE: "<<mm<<"-"<<dd<<"-"<<yy;
	gotoxy(10,5);
	cout<<"YOUR ACCOUNT NO.";
	cout<<":";
	gotoxy(10,++i);
	cout<<"ENTER DETAILS:=";
gotoxy(50,5);
	cout<<ac;
	accno=ac;
	int g=-1;
	char Ch,p1[20],p2[20];
	do
	{
		gotoxy(10,++i);
		cout<<"PASSWORD";
		gotoxy(50,i);
		cout<<":";
		do
		{
		++g;
		Ch=getch();
		p1[g]=char(Ch);
		cout<<"*";
		}
		while(Ch!=13);
		p1[++g]='\0';
		g=-1;
		gotoxy(10,++i);
		cout<<"CONFIRM PASSWORD";
		gotoxy(50,i);
		cout<<":";
		do
		{
		++g;
		Ch=getch();
		p2[g]=char(Ch);
		cout<<"*";
		}
		while(Ch!=13);
		p2[++g]='\0';
	}
	while(strcmp(p1,p2)!=0);
	strcpy(password,p1);
	gotoxy(10,++i);
	cout<<"NAME";
	gotoxy(50,i);
	cout<<":";
	cin>>name;
	gotoxy(10,++i);
	cout<<"SEX<m/f>";
	gotoxy(50,i);
	cout<<":";
	cin>>sex;
	gotoxy(10,++i);
	cout<<"AGE";
	gotoxy(50,i);
	cout<<":";
	cin>>age;
	gotoxy(10,++i);
	cout<<"ENTER ADDRESS";
	gotoxy(50,i);
	cout<<":";
cin>>address;
	do
	{
		gotoxy(10,++i);
		cout<<"OPENING AMOUNT";
		gotoxy(50,i);
		cout<<":";
		cin>>bal;
		if(bal<500)
		{
			gotoxy(10,++i);
			cout<<"MIN. BALANCE=Rs.500";
		}
	}
	while(bal<500);
	do
	{
		gotoxy(10,++i);
		cout<<"ENTER 1 FOR CASH AND 2 FOR CHEQUE";
		gotoxy(50,i);
		cout<<":";
		cin>>c;
		if(c!=1)
		{
			if(c!=2)
			{
				gotoxy(10,++i);
				cout<<"WRONG CHOICE ENTER AGAIN....";
			}
			else
			{
				strcpy(particulars,"By cheque");
				gotoxy(10,++i);
				cout<<"ENTER CHEQUE NO.";
				gotoxy(50,i);
				cout<<":";
				cin>>chequeno;
			}
		}
		else
		{
			strcpy(particulars,"By cash");
			chequeno=0;
		}
	}
	while(c<1||c>2);
	gotoxy(10,++i);
	cout<<"DO YOU WANT LOCKER FACILITY?";
	gotoxy(50,i);
	cin>>loc_ch;
	if((loc_ch=='Y')||(loc_ch=='y'))
	{
		int loc=l.get(i);
		locnum=loc;
	}
	else
	locnum=0;
	i=i+5;
	gotoxy(10,++i);
	cout<<"Do you want to save the account<y/n>";

	ch=getche();
	if((ch=='y')||(ch=='Y'))
		file.write((char*)&b,sizeof(b));
	file.close();
	closegraph();
}





void atm::new_atmacc()
{
	cleardevice();
	int i=3,n,flag=0,lc,fla=0,e=0;
	fstream file1,file2;
	file1.open("current",ios::in|ios::binary|ios::out);
	file2.open("atm",ios::app|ios::binary|ios::in);
	gotoxy(10,++i);
	cout<<"Enter account no    :";
	cin>>n;
	int g=-1;
	char Ch,p1[20],p2[20];
	do
	{
		gotoxy(10,++i);
		cout<<"PASSWORD";
		gotoxy(50,i);
		cout<<":";
		do
		{
		++g;
		Ch=getch();
		p1[g]=char(Ch);
		cout<<"*";
		}
		while(Ch!=13);
		p1[++g]='\0';
		g=-1;
		gotoxy(10,++i);
		cout<<"CONFIRM PASSWORD";
		gotoxy(50,i);
		cout<<":";
		do
		{
		++g;
		Ch=getch();
		p2[g]=char(Ch);
		cout<<"*";
		}
		while(Ch!=13);
p2[++g]='\0';
	}
	while(strcmp(p1,p2)!=0);
	while(file1.read((char*)&b,sizeof(b)))
	{	
		++e;
		if((b.accno==n)&&(strcmpi(b.password,p1)==0))
		{
			flag=1;
			if(b.atmnum==0)
			{
				fla=1;
				break;
			}
		}
	}
	if((flag==1)&&(fla==1))
	{
		int l;
		int w=sizeof(at_mac);
		file2.seekg(-w,ios::end);
		file2.read((char*)&at_mac,w);
		l=atm_no;
		++l;
		gotoxy(10,++i);
		cout<<"Your ATM Credit Card No.:";
		cout<<l;
		atm_no=l;
		b.atmnum=l;
		if(file2.eof())
			file2.clear();
		file2.seekp(0,ios::end);
		file2.write((char*)&at_mac,sizeof(at_mac));
		if(file1.eof())
			file1.clear();
		b.atmnum=l;
		file1.seekp(sizeof(b)*(e-1),ios::beg);
		file1.write((char*)&b,sizeof(b));
	}
	if(flag==0)
	{
		gotoxy(10,++i);
		cout<<"NOT FOUND";
	}
	if((flag==1)&&(fla==0))
	{
		gotoxy(10,++i);
		cout<<"ATM CARD ALREADY ALLOTED";
	}
	file1.close();
	file2.close();
	getch();
}


void atm::close_atm()
{
	cleardevice();
	int n,i=3,flag=0,e=0;
	fstream file1,file2,file3;
	file1.open("atm",ios::out|ios::in|ios::binary);
	file2.open("temp",ios::app|ios::binary);
	file3.open("current",ios::out|ios::in|ios::binary|ios::ate);
	gotoxy(10,++i);
	cout<<"Enter ATM Card no  :";
	cin>>n;
	while(file1.read((char*)&at_mac,sizeof(at_mac)))
	{
		if(atm_no==n)
		{
			flag=1;
			continue;
		}
		file2.write((char*)&at_mac,sizeof(at_mac));
	}
		file3.seekg(0,ios::beg);
	while(!file3.eof())
	{
		file3.read((char*)&b,sizeof(b));
		e+=1;
		if(b.locnum==n)
		{
			b.locnum=0;
			break;
		}
	}
	int x=sizeof(b);
	file3.seekp(x*(e-1),ios::beg);
	file3.write((char*)&b,sizeof(b));
	if(flag==0)
	cout<<"NOT FOUND";
	else
	cout<<"ATM Card Deleted";
	getch();
	file1.close();
	file2.close();
	file3.close();
	remove("atm");
	rename("temp","atm");
}



int atm_ch()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"d:\\tc\\bgi");
	int ch;
	do
	{
		cleardevice();
		setbkcolor(9);
		setcolor(WHITE);
		rectangle(150,110,470,350);
		rectangle(170,160,450,330);
		settextstyle(1,0,3);
		highvideo();
		outtextxy(200,120,"ATM TRANSACTION");
		settextstyle(2,0,6);
		outtextxy(210,200,"1.DEBIT ");
		outtextxy(210,230,"2.CREDIT");
		outtextxy(210,260,"3.EXIT TO ATM MENU");
		outtextxy(200,300,"ENTER YOUR CHOICE(1-3)");
		settextstyle(4,0,4);
		while(!kbhit())
		{
		for(int  i=150;i<460;i=i+20)
		{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(i,85,"*");
			delay(100);
			setcolor(9);
			outtextxy(i,85,"*");
			delay(10);
			if(kbhit())
			break;
		}
		for(i=85;i<325;i=i+20)
		{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(465,i,"*");
			delay(100);
			setcolor(9);
			outtextxy(465,i,"*");
			delay(10);
			if(kbhit())
			break;
		}
		for(i=460;i>150;i=i-20)
		{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(i,325,"*");
			delay(100);
			setcolor(9);
			outtextxy(i,325,"*");
			delay(10);
	if(kbhit())
			break;
		}
		for(i=325;i>85;i=i-20)
		{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(145,i,"*");
			delay(100);
			setcolor(9);
			outtextxy(145,i,"*");
			delay(10);
			if(kbhit())
			break;
		}
		}
		gotoxy(53,20);
		cin>>ch;
		return(ch);
		}
		while(ch!=3);
		closegraph();
}

void atm::open_atm()
{
	int l,i=3,flag=0;
	fstream file,file1,file2;
	file.open("atm",ios::in|ios::binary);
	file1.open("current",ios::in|ios::out|ios::binary);
	file2.open("bank",ios::app);
	gotoxy(10,++i);
	cout<<"Enter ATM Card No  :";
	cin>>l;
	while(file.read((char *)&at_mac,sizeof(at_mac)))
	{
		if(atm_no==l)
		{
			while(file1.read((char *)&b,sizeof(b)))
			{
				if(b.atmnum==l)
				{
				if(file2.eof())
					file2.clear();
				file2.write((char *)&b,sizeof(b));
				int mon,ch;
				ch=atm_ch();
				if(ch==1)
				{
					gotoxy(10,++i);
	cleardevice();
					cout<<"Enter money to be withdrawn  :";
					cin>>mon;
					if(b.bal-mon<0)
					{
						gotoxy(10,++i);
						cout<<"Cannot withdraw";
						gotoxy(10,++i);
						cout<<"BALANCE="<<b.bal;
						break;
					}
					else
					{
						b.bal=b.bal-mon;
						strcpy(b.particulars,"By ATM");
					}
				}
				if(ch==2)
				{
					gotoxy(10,++i);
					cleardevice();
					cout<<"Enter money to be deposited  :";
					cin>>mon;
					b.bal=b.bal+mon;
					strcpy(b.particulars,"To ATM");

				}
				file1.seekp(-n,ios::cur);
				struct date d;
				getdate(&d);
				b.mm=d.da_mon;
				b.dd=d.da_day;
				b.yy=d.da_year;
				if(file1.eof())
					file1.clear();
				file1.write((char *)&b,sizeof(b));
				}
			}
			delay(1000);
			flag=1;
			break;
		}
	}
	file.close();
	file1.close();
	file2.close();
}




void atm()
{
	int gd=DETECT,gm,atm_ch,i,x;
	initgraph(&gd,&gm,"d:\\tc\\bgi");
	setbkcolor(9);
	setcolor(WHITE);
	do
	{
	cleardevice();
	for(i=0;i<100;i=i+10)
	{
		setbkcolor(9);
		setcolor(WHITE);
		rectangle(i,i,640-i,480-i);
		line(0,0,i,i);
		line(640,0,640-i,i);
		line(0,480,i,480-i);
		line(640,480,640-i,480-i);
		sound(1000);
		delay(100);
		nosound();
		delay(400);
		nosound();
	}
	rectangle(110,150,530,370);
	char ch[5];
	settextstyle(10,0,4);
	highvideo();
	outtextxy(250,85,"A.T.M");
	settextstyle(1,0,2);
	outtextxy(210,180,"1.NEW ATM CARD");
	outtextxy(210,210,"2.ACCESS ATM");
	outtextxy(210,240,"3.CLOSE ATM ACCOUNT");
	outtextxy(210,270,"4.EXIT TO MAIN MENU");
	outtextxy(200,320,"ENTER YOUR CHOICE(1-4):");
	settextstyle(4,0,4);
	while(!kbhit())
	{
		for(i=85;i<550;i=i+20)
		{
			setcolor(15);
			rectangle(90,90,550,390);
			outtextxy(i,65,"*");
			sound(10000);
			delay(100);
			nosound();
			setcolor(9);
			outtextxy(i,65,"*");
			delay(10);
			if(kbhit())
			break;
		}
		for(i=90;i<370;i=i+20)
		{
			setcolor(15);
			rectangle(90,90,550,390);
			outtextxy(545,i,"*");
			sound(10000);
			delay(100);
			nosound();
			setcolor(9);
outtextxy(545,i,"*");
			delay(10);
			if(kbhit())
			break;
		}
		for(i=540;i>85;i=i-20)
		{
			setcolor(15);
			rectangle(90,90,550,390);
			outtextxy(i,365,"*");
			sound(10000);
			delay(100);
			nosound();
			setcolor(9);
			outtextxy(i,365,"*");
			delay(10);
			if(kbhit())
			break;
		}
		for(i=360;i>90;i=i-20)
		{
			setcolor(15);
			rectangle(90,90,550,390);
			outtextxy(85,i,"*");
			sound(10000);
			delay(100);
			nosound();
			setcolor(9);
			outtextxy(85,i,"*");
			delay(10);
			if(kbhit())
			break;
		}
	}
	setcolor(15);
	settextstyle(1,0,2);
	x=getch();
	x=x-48;
	atm_ch=x;
	itoa(x,ch,10);
	outtextxy(470,320,ch);
	switch(atm_ch)
		{
			case 1:at_mac.new_atmacc();
			       break;
			case 2:at_mac.open_atm();
			       break;
			case 3:at_mac.close_atm();
			       break;
		}
	}
	while(atm_ch!=4);

}



int locker::open_loc()
{
	int loc,i=3,flag=0;
	fstream file,file1,file2;
	file.open("locker",ios::in|ios::binary);
	file1.open("current",ios::in|ios::out|ios::binary);
	file2.open("bank",ios::app);
	gotoxy(10,++i);
	cout<<"Enter locker no   ";
	cin>>loc;
	char p[20];
	gotoxy(10,++i);
	cout<<"Enter Passwod";
	cin>>p;
	while(file.read((char *)&l,sizeof(l)))
	{
		if((locno==loc)&&(strcmpi(pass,p)==0))
		{
			while(file1.read((char *)&b,sizeof(b)))
			{
				if(b.locnum==loc)
				{
				if(file2.eof())
					file2.clear();
				file2.write((char *)&b,sizeof(b));
				file1.seekp(-n,ios::cur);
				b.bal=b.bal-30;
				strcpy(b.particulars,"To locker");
				struct date d;
				getdate(&d);
				b.mm=d.da_mon;
				b.dd=d.da_day;
				b.yy=d.da_year;
				if(file1.eof())
					file1.clear();
				file1.write((char *)&b,sizeof(b));
				}
			}
			gotoxy(10,++i);
			cout<<"OPENING LOCKER........ ";
			delay(1000);
			flag=1;
			break;
		}
	}
	file.close();
	file1.close();
	file2.close();
	if(flag==1)
	return(1);
	else
	return(0);
}

void opening_loc()
{
	int xmax,ymax;
	xmax = getmaxx();
	ymax = getmaxy();
	settextstyle(3,0,5);
	cleardevice();
	outtextxy(xmax/2-80,0,"LOCKER");
	int f=xmax-320;
	rectangle(129,49,xmax-130,ymax-9);
	for(int i=xmax-320;i>130;i--)
	{
		setcolor(WHITE);
		rectangle(129,49,xmax-130,ymax-9);
		line(129,ymax-9,237,157);
		line(xmax-130,ymax-9,382,157);
		line(237,157,237,49);
		line(382,157,382,49);
		line(237,157,382,157);
		line(237,152,382,152);
		setfillstyle(1,15);
		bar(362,50,370,85);
		circle(366,95,4);
		circle(332,67,5);
		bar(330,72,334,85);
		line(335,61,344,52);
		line(337,65,346,56);
		line(344,52,346,56);
		floodfill(340,60,15);
		line(329,61,320,52);
		line(327,65,318,56);
		line(320,52,318,56);
		floodfill(325,60,15);
		setfillstyle(8,15);
		bar(130,50,i,ymax-10);
		setlinestyle(0,1,3);
		line(i+1,50,i+1,ymax-10);
		setlinestyle(0,1,1);
		delay(10);
		setcolor(BLACK);
		setfillstyle(8,0);
		bar(130,50,i,ymax-10);
		setlinestyle(0,1,3);
		line(i+1,50,i+1,ymax-10);
		setlinestyle(0,1,1);
	for(int y=f;y<xmax-131;y++)
		{
			setcolor(WHITE);
			setfillstyle(8,15);
			bar(y,50,xmax-131,ymax-10);
			setlinestyle(0,1,3);
			line(y-1,50,y-1,ymax-10);
			setlinestyle(0,1,1);
			delay(10);
			setcolor(BLACK);
			setlinestyle(0,1,3);
			line(y-1,50,y-1,ymax-10);
			setlinestyle(0,1,1);
			setfillstyle(8,0);
			bar(y,50,xmax-131,ymax-10);
			break;
		}
	f++;
	}
	setcolor(WHITE);
	setlinestyle(0,1,3);
	line(xmax-132,50,xmax-132,ymax-10);
	setlinestyle(0,1,3);
	line(i+1,50,i+1,ymax-10);
	setlinestyle(0,1,1);
	bar(362,50,370,85);
	circle(366,95,4);
	circle(332,67,5);
	for( i=0;i<6;++i)
	{
		if(i%2==0)
		{
			cleardevice();
			settextstyle(3,0,4);
			outtextxy(xmax/2-80,0,"LOCKER");
			setlinestyle(SOLID_LINE, 2, 2);
			rectangle(129,40,xmax-130,ymax-9);
			setlinestyle(SOLID_LINE, 2, 1);
			line(129,ymax-9,237,157);
			line(xmax-130,ymax-9,382,157);
			line(237,157,237,40);
			line(382,157,382,40);
			line(237,157,382,157);
			line(237,152,382,152);
			setfillstyle(1,15);
			bar(362,50,370,85);
			circle(366,95,4);
			bar(362,50,370,85);
			circle(366,95,4);
			circle(332,67,5);
			bar(330,72,334,85);
			bar(330,62,334,49);
			bar(314,65,327,69);
			bar(337,65,350,69);
			delay(1000);
		}
	else
		{
			cleardevice();
			setlinestyle(SOLID_LINE, 2, 2);
			rectangle(129,40,xmax-130,ymax-9);
			setlinestyle(SOLID_LINE, 2, 1);
			line(129,ymax-9,237,157);
			line(xmax-130,ymax-9,382,157);
			line(237,157,237,40);
			line(382,157,382,40);
			line(237,157,382,157);
			line(237,152,382,152);
			setfillstyle(1,15);
			bar(362,50,370,85);
			circle(366,95,4);
			bar(362,50,370,85);
			circle(366,95,4);
			circle(332,67,5);
			line(337,69,346,78);
			line(335,73,344,82);
			line(346,78,344,82);
			floodfill(338,72,15);
			line(329,73,320,82);
			line(327,69,318,78);
			line(320,82,318,78);
			floodfill(320,80,15);
			line(329,61,320,52);
			line(327,65,318,56);
			line(320,52,318,56);
			floodfill(325,60,15);
			line(335,61,344,52);
			line(337,65,346,56);
			line(344,52,346,56);
			floodfill(340,60,15);
			delay(1000);
		}
	}
	cleardevice();
	rectangle(220,100,420,350);
	line(0,100,640,100);
	line(220,0,220,480);
	line(420,0,420,500);
	line(0,350,640,350);
	line(20,0,20,480);
	line(620,0,620,480);
	bar(190,200,198,235);
	circle(194,245,4);
	bar(590,200,598,235);
	circle(594,245,4);
	delay(3000);
	for(i=420;i>120;i=i-10)
	{
		rectangle(220,100,420,350);
		setlinestyle(0,1,1);
		line(420,0,420,500);
		setlinestyle(0,1,3);
	line(220,100,i,170);
		line(220,180,420,180);
		line(220,270,420,270);
		line(i,170,i,420);
		setlinestyle(0,1,1);
		line(i,420,220,350);
		setcolor(0);
		if(i==200)
		{
			setfillstyle(0,0);
			bar(190,200,198,235);
			circle(194,245,4);
		}
		line(220,350,i-7,350);
		setlinestyle(0,1, 3);
		if(i>220)
		{
			line(220,180,i,180);
			line(220,350,i,350);
			line(220,270,i,270);
		}
		delay(400);
		line(220,100,i,170);
		line(i,170,i,420);
		line(i,420,220,350);
		setcolor(15);
		if(i==220)
		{
			setlinestyle(0,1,1);
			line(220,0,220,480);
		}
	}
	setcolor(15);
	line(220,100,i,170);
	line(i,170,i,420);
	line(i,420,220,350);
}

void closing_loc()
{
	settextstyle(10,0,1);
	outtextxy(90,400,"Press Any Key To Close Locker");
	getch();
	cleardevice();
	setfillstyle(1,15);
	setlinestyle(0,1,1);
	rectangle(220,100,420,350);
	line(0,100,640,100);
	line(220,0,220,480);
	line(420,0,420,500);
	line(0,350,640,350);
	line(20,0,20,480);
	line(620,0,620,480);
	bar(590,200,598,235);
	circle(594,245,4);
	setlinestyle(0,1,3);
	line(220,100,120,170);
	line(120,170,120,420);
	line(120,420,220,350);
	line(220,180,420,180);
	line(220,270,420,270);
	rectangle(220,100,420,350);
	setcolor(0);
	line(120,350,220,350);
	for(int i=120;i<420;i=i+10)
	{
		setcolor(15);
		rectangle(220,100,420,350);
		setlinestyle(0,1,1);
		line(420,0,420,500);
		setlinestyle(0,1,3);
		line(220,100,i,170);
		line(220,180,420,180);
		line(220,270,420,270);
		line(i,170,i,420);
		setlinestyle(0,1,1);
		line(i,420,220,350);
		if(i<=230)
		{
			line(220,0,220,320);
			line(0,350,i,350);
		}
		if(i>=198)
		{
			bar(190,200,198,235);
			circle(194,245,4);
		}
		setcolor(0);
		line(220,350,i-7,350);
		setlinestyle(0,1, 3);
		if(i>220)
		{
			line(220,180,i,180);
			line(220,350,i,350);
			line(220,270,i,270);
		}
		delay(400);
		line(220,100,i,170);
		line(i,170,i,420);
		line(i,420,220,350);
		setcolor(15);
		if(i==220)
		{
			setlinestyle(0,1,1);
			line(220,0,220,480);
		}
	}
setlinestyle(0,1,3);
	line(220,350,420,350);
	setcolor(0);
	line(220,180,420,180);
	line(220,270,420,270);
	setcolor(15);
	setlinestyle(0,1,1);
	bar(390,200,398,235);
	circle(394,245,4);
	getch();
}

void open_locker()
{
	int gdriver = DETECT, gmode, errorcode,a;
	int xmax, ymax,i=7;
	initgraph(&gdriver, &gmode, "d:\\tc\\bgi");
	a=l.open_loc();
	if(a==1)
	{
		opening_loc();
		closing_loc();
	}
	else
	gotoxy(10,++i);
	cout<<"LOCKER DO NOT EXIST";
	getch();
}

void locker::open_newloc()
{
	cleardevice();
	int i=3,n,flag=0,lc,fla=0,e=0;
	char p[20];
	fstream file1,file2;
	file1.open("current",ios::in|ios::binary|ios::out);
	file2.open("locker",ios::app|ios::binary|ios::in);
	gotoxy(10,++i);
	cout<<"Enter account no  :";
	cin>>n;
	int g=-1;
	char Ch,p1[20],p2[20];
	gotoxy(10,++i);
	cout<<"PASSWORD";
	gotoxy(50,i);
	cout<<":";
	do
	{
	++g;
	Ch=getch();
	p1[g]=char(Ch);
	cout<<"*";
	}
	while(Ch!=13);
	p1[++g]='\0';
	while(file1.read((char*)&b,sizeof(b)))
	{
		++e;
		if((b.accno==n)&&(strcmpi(b.password,p1)==0))
		{
			flag=1;
			if(b.locnum==0)
			{
				fla=1;
				break;
			}
		}
	}
	if((flag==1)&&(fla==1))
	{
		int loc;
		int w=sizeof(l);
		file2.seekg(-w,ios::end);
		file2.read((char*)&l,sizeof(l));
		loc=locno;
		++loc;
		gotoxy(10,++i);
		cout<<"Your Locker No.:";
		cout<<loc;
		locno=loc;
		b.locnum=loc;
		g=-1;
		do
		{
		gotoxy(10,++i);
		cout<<"ENTER PASSWORD FOR LOCKER";
		gotoxy(50,i);
		cout<<":";
		do
		{
		++g;
		Ch=getch();
		pass[g]=char(Ch);
		cout<<"*";
	}
		while(Ch!=13);
		pass[++g]='\0';
		g=-1;
		gotoxy(10,++i);
		cout<<"CONFIRM PASSWORD";
		gotoxy(50,i);
		cout<<":";
		do
		{
		++g;
		Ch=getch();
		p2[g]=char(Ch);
		cout<<"*";
		}
		while(Ch!=13);
		p2[++g]='\0';
		}
		while(strcmp(pass,p2)!=0);
		if(file2.eof())
			file2.clear();
		file2.seekp(0,ios::end);
		file2.write((char*)&l,sizeof(l));
		if(file1.eof())
			file1.clear();
		b.locnum=loc;
		file1.seekp(sizeof(b)*(e-1),ios::beg);
		file1.write((char*)&b,sizeof(b));
		gotoxy(10,++i);
		cout<<"OPENED LOCKER";
	}
	if(flag==0)
	{
		gotoxy(10,++i);
		cout<<"NOT FOUND";
	}
	if((flag==1)&&(fla==0))
	{
		gotoxy(10,++i);
		cout<<"LOCKER ALREADY ALLOTED";
	}
	file1.close();
	file2.close();
	getch();
}

void locker::close_loc()
{
	cleardevice();
int n,i=3,flag=0,e=0;
	char p[20];
	bank a;
	fstream file1,file2,file3;
	file1.open("locker",ios::out|ios::in|ios::binary);
	file2.open("temp",ios::app|ios::binary);
	file3.open("current",ios::out|ios::in|ios::binary|ios::ate);
	gotoxy(10,++i);
	cout<<"Enter locker no  :";
	cin>>n;
	gotoxy(10,++i);
	cout<<"Enter password   :";
	cin>>p;
	while(file1.read((char*)&l,sizeof(l)))
	{
		if((locno==n)&&(strcmpi(pass,p)==0))
		{
			flag=1;
			continue;
		}
		file2.write((char*)&l,sizeof(l));
	}
	file3.seekg(0,ios::beg);
	while(!file3.eof())
	{
		file3.read((char*)&a,sizeof(a));
		e+=1;
		if(a.locnum==n)
		{
			a.locnum=0;
			break;
		}
	}
	int x=sizeof(a);
	file3.seekp(x*(e-1),ios::beg);
	file3.write((char*)&a,sizeof(a));
	gotoxy(10,++i);
	if(flag==0)
		cout<<"NOT FOUND";
	else
	cout<<"Locker Sucessfully Deleted";
	getch();
	file1.close();
	file2.close();
	file3.close();
	remove("locker");
	rename("temp","locker");
}



void bank::locker()
{
	int gd=DETECT,gm,locker_ch,i;
	initgraph(&gd,&gm,"d:\\tc\\bgi");
	do
	{
		cleardevice();
		setbkcolor(9);
		setcolor(WHITE);
		rectangle(150,110,470,350);
		rectangle(170,160,450,330);
		settextstyle(1,0,3);
		highvideo();
		outtextxy(230,120,"LOCKER");
		settextstyle(2,0,6);
		outtextxy(210,180,"1.OPEN NEW LOCKER");
		outtextxy(210,205,"2.ACCESS LOCKER");
		outtextxy(210,230,"3.CLOSE LOCKER");
		outtextxy(210,255,"4.EXIT TO MAIN MENU");
		outtextxy(200,300,"ENTER YOUR CHOICE(1-4)");
		gotoxy(53,20);
		settextstyle(4,0,4);
		while(!kbhit())
		{
		for(i=150;i<460;i=i+20)
		{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(i,85,"*");
			delay(100);
			setcolor(9);
			outtextxy(i,85,"*");
			delay(10);
			if(kbhit())
			break;
		}
		for(i=85;i<325;i=i+20)
		{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(465,i,"*");
			delay(100);
			setcolor(9);
			outtextxy(465,i,"*");
			delay(10);
			if(kbhit())
			break;
		}
		for(i=460;i>150;i=i-20)
{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(i,325,"*");
			delay(100);
			setcolor(9);
			outtextxy(i,325,"*");
			delay(10);
			if(kbhit())
			break;
		}
		for(i=325;i>85;i=i-20)
		{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(145,i,"*");
			delay(100);
			setcolor(9);
			outtextxy(145,i,"*");
			delay(10);
			if(kbhit())
			break;
		}
		}
		cin>>locker_ch;
		switch(locker_ch)
		{
			case 1:l.open_newloc();
			       break;
			case 2:open_locker();
			       break;
			case 3:l.close_loc();
			       break;
		}
	}
	while(locker_ch!=4);
	closegraph();
}
void bank::disp(int pos)
{
	gotoxy(1,pos);
	cout<<accno;
	gotoxy(12,pos);
	cout<<name;
	gotoxy(25,pos);
	cout<<address;
	gotoxy(45,pos);
	cout<<mm<<"-"<<dd<<"-"<<yy;
	gotoxy(65,pos);
	cout<<bal;
}
void bank::list_accno()
{
	int pos=7;
	clrscr();
	gotoxy(25,2);
	cout<<"ACCOUNTS LIST IN BANK";
	gotoxy(25,3);
	cout<<"=====================";
	gotoxy(1,4);
	cout<<"================================================================================";
	gotoxy(1,5);
	cout<<"Accno#";
	gotoxy(12,5);
	cout<<"Name";
	gotoxy(25,5);
	cout<<"Address";
	gotoxy(45,5);
	cout<<"Opened On";
	gotoxy(65,5);
	cout<<"Balance";
	gotoxy(1,6);
	cout<<"================================================================================";
	fstream f;
	f.open("current",ios::in|ios::binary);
	while(f.read((char *)&b,sizeof(b)))
	{
		b.disp(pos);
		++pos;
	}
	f.close();
	getch();
}
void bank::credit_accno()
{
	int a,flag=0,amount,c=0,i=3;
	cleardevice();
	fstream file1,file2;
	file1.open("current",ios::in|ios::out|ios::binary);
	file2.open("bank",ios::app|ios::binary);
	gotoxy(10,++i);
	cout<<"ENTER ACOUNT NO.  :";
	cin>>a;
gotoxy(10,++i);
	int g=-1;
	char Ch,p1[20],p2[20];
	gotoxy(10,++i);
	cout<<"PASSWORD";
	gotoxy(50,i);
	cout<<":";
	do
	{
	++g;
	Ch=getch();
	p1[g]=char(Ch);
	cout<<"*";
	}
	while(Ch!=13);
	p1[++g]='\0';
	while(file1.read( (char*)&b,sizeof(b)))
	{
		if((accno==a)&&(strcmpi(password,p1)==0))
		{
			file2.write((char*)&b,sizeof(b));
			gotoxy(10,++i);
			cout<<"ENTER AMOUNT TO BE DEPOSITED  :";
			cin>>amount;
			do
			{
				gotoxy(10,++i);
				cout<<"ENTER 1 FOR CASH AND 2 FOR CHEQUE";
				cin>>c;
				if(c!=1)
				{
					if(c!=2)
					{
						gotoxy(10,++i);
						cout<<"WRONG CHOICE ENTER AGAIN\n";
					}
					else
					{
						gotoxy(10,++i);
						cout<<"ENTER CHEQUE NO.";
						cin>>chequeno;
						strcpy(particulars,"By cheque");
					 }
				}
				else
				{
					strcpy(particulars,"By cash");
					chequeno=0;
				}
			}
			while(c<1&&c>2);
			bal=bal+amount;
			gotoxy(10,++i);
			cout<<"BALANCE= "<<bal;
			flag=1;
			if(file1.eof())
	file1.clear();
			file1.seekp(-n,ios::cur);
			getdate(&d);
			b.mm=d.da_mon;
			b.dd=d.da_day;
			b.yy=d.da_year;
			file1.write((char*)&b,sizeof(b));
		}
	}
	file1.close();
	file2.close();
	if(flag==0)
	cout<<"Account not found";
	getch();
}

void bank::debit_accno()
{
	int a,f=0,flag=0,amount,c=0,i=3;
	fstream file1,file2;
	file1.open("current",ios::in|ios::out|ios::binary);
	file2.open("bank",ios::app|ios::binary);
	cleardevice();
	gotoxy(10,++i);
	cout<<"ENTER ACOUNT NO.";
	cin>>a;
	int g=-1;
	char Ch,p[20];
	gotoxy(10,++i);
	cout<<"PASSWORD";
	gotoxy(50,i);
	cout<<":";
	do
	{
	++g;
	Ch=getch();
	p[g]=char(Ch);
	cout<<"*";
	}
	while(Ch!=13);
	p[++g]='\0';
	while(file1.read((char*)&b,sizeof(b)))
	{
		if((b.accno==a)&&(strcmpi(b.password,p)==0))
		{
			f=1;
			gotoxy(10,++i);
			cout<<"ENTER AMOUNT TO BE WITHDRAWN";
			cin>>amount;
			do
{
				gotoxy(10,++i);
				cout<<"ENTER 1 FOR CASH AND 2 FOR CHEQUE";
				cin>>c;
				if(c!=1)
				{
					if(c!=2)
					{
						gotoxy(10,++i);
						cout<<"WRONG CHOICE ENTER AGAIN\n";
					}
					else
					{
						gotoxy(10,++i);
						cout<<"ENTER CHEQUE NO.\n";
						cin>>chequeno;
						strcpy(particulars,"To cheque");
					}
				}
				else
				{
					strcpy(particulars,"To cash");
					chequeno=0;
				}
			}
			while(c<1||c>2);
			if(bal-amount<0)
			{
				gotoxy(10,++i);
				cout<<"You cannot withdraw money";
				gotoxy(10,++i);
				cout<<"Your balance Rs."<<bal;
				break;
			}
			else
			{
				file2.write((char*)&b,sizeof(b));
				bal=bal-amount;
				gotoxy(10,++i);
				cout<<"BALANCE= "<<bal;
				flag=1;
				if(file1.eof())
				file1.clear();
				file1.seekp(-n,ios::cur);
				getdate(&d);
				b.mm=d.da_mon;
				b.dd=d.da_day;
				b.yy=d.da_year;
				file1.write((char*)&b,sizeof(b));
			}
		}
	}
	if(f==0)
	gotoxy(10,++i);
	cout<<"Account not found";
	getch();
	file1.close();
	file2.close();
}

void bank :: daily_trans()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"d:\\tc\\bgi");
	int daily_trans_ch;
	do
	{
		cleardevice();
		setbkcolor(9);
		setcolor(WHITE);
		rectangle(150,110,470,350);
		rectangle(170,160,450,330);
		settextstyle(1,0,3);
		highvideo();
		outtextxy(200,120,"DAILY TRANSACTION");
		settextstyle(2,0,6);
		outtextxy(210,200,"1.DEBIT ACCOUNT");
		outtextxy(210,230,"2.CREDIT ACCOUNT");
		outtextxy(210,260,"3.EXIT TO MAIN MENU");
		outtextxy(200,300,"ENTER YOUR CHOICE(1-3)");
		settextstyle(4,0,4);
		while(!kbhit())
		{
		for(int  i=150;i<460;i=i+20)
		{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(i,85,"*");
			delay(100);
			setcolor(9);
			outtextxy(i,85,"*");
			delay(10);
			if(kbhit())
			break;
		}
		for(i=85;i<325;i=i+20)
		{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(465,i,"*");
			delay(100);
			setcolor(9);
			outtextxy(465,i,"*");
			delay(10);
			if(kbhit())
			break;
		}
		for(i=460;i>150;i=i-20)
	{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(i,325,"*");
			delay(100);
			setcolor(9);
			outtextxy(i,325,"*");
			delay(10);
			if(kbhit())
			break;
		}
		for(i=325;i>85;i=i-20)
		{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(145,i,"*");
			delay(100);
			setcolor(9);
			outtextxy(145,i,"*");
			delay(10);
			if(kbhit())
			break;
		}
		}
		gotoxy(53,20);
		cin>>daily_trans_ch;
		switch(daily_trans_ch)
		{
			case 1:debit_accno();
			       break;
			case 2:credit_accno();
			       break;
		}
	}
	while(daily_trans_ch!=3);
	closegraph();
}

void bank::close_accno()
{
	int ac,f=0,flag=0,i=3;
	setcolor(13);
	cleardevice();
	gotoxy(10,++i);
	cout<<"ENTER ACOUNT NO.";
	cin>>ac;
	gotoxy(10,++i);
	int g=-1;
	char Ch,p[20];
	gotoxy(10,++i);
	cout<<"ENTER PASSWORD";
	gotoxy(50,i);
	cout<<":";
	do
	{
	++g;
	Ch=getch();
	p[g]=char(Ch);
	cout<<"*";
	}
	while(Ch!=13);
	p[++g]='\0';
	fstream file2,file3;
	file2.open("current",ios::in|ios::out|ios::binary);
	file3.open("temp1",ios::app|ios::binary);
	while(file2.read((char*)&b,sizeof(b)))
	{
		if((accno==ac)&&(strcmpi(p,password)==0))
		{
			f=1;
			if(bal!=0)
			{
				gotoxy(10,++i);
				cout<<"first withdraw Rs."<<bal<<" in your account";
				getch();
				flag=1;
				break;
			}
		}
	}
	if(file2.eof())
	file2.clear();
	file2.seekg(0,ios::beg);
	if(f==1)
	{
		while(file2.read((char*)&b,sizeof(b)))
		{
			if((accno==ac)&&(strcmpi(p,password)==0)&&(flag==0))
			continue;
			file3.write((char *)&b,sizeof(b));
		}
	}
	file3.close();
	file2.close();
	remove("current");
	rename("temp1","current");
	gotoxy(10,++i);
	if(f==0)
cout<<"ACCOUNT NOT FOUND";
	getch();
}

void bank::modify_accno()
{
	int ac,flag=0,i=3;
	char Ch,p1[20],p2[20],na[20],a[20],pp[20];
	cleardevice();
	gotoxy(10,++i);
	cout<<"ENTER ACOUNT NO.";
	cin>>ac;
	gotoxy(10,++i);
	int g=-1;
	gotoxy(10,++i);
	cout<<"ENTER PASSWORD";
	gotoxy(50,i);
	cout<<":";
	do
	{
	++g;
	Ch=getch();
	pp[g]=char(Ch);
	cout<<"*";
	}
	while(Ch!=13);
	pp[++g]='\0';
	delete &Ch;
	fstream file1,file2;
	file1.open("bank",ios::in|ios::out|ios::binary);
	file2.open("current",ios::in|ios::out|ios::binary);
	while(file2.read((char*)&b,sizeof(b)))
	{
		if((b.accno==ac)&&(strcmpi(pp,b.password)==0))
		{
			int n;
			n=sizeof(b);
			flag=1;
			gotoxy(10,++i);
			cout<<"Enter new name";
			cin>>b.name;
			strcpy(na,b.name);
			gotoxy(10,++i);
			cout<<"Enter new address";
			cin>>b.address;
			strcpy(a,b.address);
			b.bal=bal;
			gotoxy(10,++i);
			int g=-1;
			char Ch,p1[20],p2[20];
			do
			{
				gotoxy(10,++i);
				cout<<"Enter New Password :";
				gotoxy(50,i);
				cout<<":";
				do
				{
					++g;
					Ch=getch();
					p1[g]=char(Ch);
					cout<<"*";
				}
				while(Ch!=13);
				p1[++g]='\0';
				g=-1;
				gotoxy(10,++i);
				cout<<"Confirm Password  :";
				gotoxy(50,i);
				cout<<":";
				do
				{
					++g;
					Ch=getch();
					p2[g]=char(Ch);
					cout<<"*";
				}
				while(Ch!=13);
				p2[++g]='\0';
			}
			while(strcmp(p1,p2)!=0);
			strcpy(b.password,p1);
			strcpy(p2,b.name);
			if(file2.eof())
			file2.clear();
			file2.seekp(-n,ios::cur);
			file2.write((char *)&b,sizeof(b));
			break;
		}
	}
	while(file1.read((char*)&b,sizeof(b)))
	{
		if((b.accno==ac)&&(strcmpi(pp,b.password)==0))
		{
			if(file1.eof())
			file1.clear();
			file1.seekp(-n,ios::cur);
			strcpy(b.name,na);
			strcpy(b.address,a);
			strcpy(b.name,p2);
			file1.write((char *)&b,sizeof(b));
		}
	}
	file1.close();
	file2.close();

	gotoxy(10,++i);
	if(flag==0)
	cout<<"ACCOUNT NOT FOUND";
	getch();
}
void edit_help()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "d:\\tc\\bgi");
	setbkcolor(9);
	setcolor(7);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(30,20,"Help To Edit Menu");
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(40,100, "-With this option you can edit your account.");
	delay(1000);
	outtextxy(40,140, "-In the first option you can modify your account.");
	delay(1000);
	outtextxy(40,180, "-In the second option you can close your account.");
	delay(1000);
	outtextxy(40,220, "-You will first have to withdraw all your money if you");
	delay(1000);
	outtextxy(40,260,"want to close your account.");
	delay(1000);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(80,420,"Press any key to continue...");
	delay(1000);
	getch();
}

void bank :: edit_account()
{
	int gd=DETECT,gm,main_ch;
	initgraph(&gd,&gm,"d:\\tc\\bgi");
	edit_help();
	int edit_ch;
	do
	{
		cleardevice();
		setbkcolor(9);
		setcolor(WHITE);
		rectangle(150,110,470,350);
		rectangle(170,160,450,330);
		settextstyle(1,0,3);
		highvideo();
		outtextxy(235,120,"EDIT-ACCOUNT");
settextstyle(2,0,6);
		outtextxy(210,200,"1.MODIFY ACCOUNT");
		outtextxy(210,230,"2.CLOSE ACCOUNT");
		outtextxy(210,260,"3.EXIT TO MAIN MENU");
		outtextxy(200,300,"ENTER YOUR CHOICE(1-3)");
		settextstyle(4,0,4);
		while(!kbhit())
		{
		for(int  i=150;i<460;i=i+20)
		{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(i,85,"*");
			delay(100);
			setcolor(9);
			outtextxy(i,85,"*");
			delay(10);
			if(kbhit())
			break;
		}
		for(i=85;i<325;i=i+20)
		{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(465,i,"*");
			delay(100);
			setcolor(9);
			outtextxy(465,i,"*");
			delay(10);
			if(kbhit())
			break;
		}
		for(i=460;i>150;i=i-20)
		{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(i,325,"*");
			delay(100);
			setcolor(9);
			outtextxy(i,325,"*");
			delay(10);
			if(kbhit())
			break;
		}
		for(i=325;i>85;i=i-20)
		{
			setcolor(15);
			rectangle(150,110,470,350);
			outtextxy(145,i,"*");
			delay(100);
			setcolor(9);
			outtextxy(145,i,"*");
			delay(10);
			if(kbhit())
			break;
		}
}
		gotoxy(53,20);
		cin>>edit_ch;
		switch(edit_ch)
		{
			case 1:modify_accno();
			       break;
			case 2:close_accno();
			       break;
		}
	}
	while(edit_ch!=3);
	closegraph();
}

void bank::display(int p,int q,int d)
{
	int n=1;
	gotoxy(1,p);
	cout<<q;
	gotoxy(12,p);
	cout<<particulars;
	gotoxy(29,p);
	cout<<chequeno;
	gotoxy(41,p);
	cout<<mm<<"-"<<dd<<"-"<<yy;
	if(d>0)
	{
		gotoxy(62,p);
		cout<<d;
	}
	else
	{
		gotoxy(52,p);
		cout<<-d;
	}
	gotoxy(72,p);
	cout<<bal;
	++q;
}

void bank::detail_accno()
{
	int gd=DETECT,gm,main_ch;
	initgraph(&gd,&gm,"d:\\tc\\bgi");
	setbkcolor(9);
	setcolor(WHITE);
	int pos=7,ac,flag=0,s=1,i=6;
	int a=0,d=0;
	char p[20],Ch;
	gotoxy(10,5);
	cout<<"Enter account no.  :";
	cin>>ac;
	int g=-1;
	gotoxy(10,++i);
	cout<<"Enter Password";
	gotoxy(50,i);
	cout<<":";
	do
	{
	++g;
	Ch=getch();
	p[g]=char(Ch);
	cout<<"*";
	}
	while(Ch!=13);
	p[++g]='\0';
	cleardevice();
	fstream f1,f2;
	f1.open("current",ios::in|ios::binary);
	f2.open("bank",ios::in|ios::binary);
	while(f1.read((char *)&b,sizeof(b)))
	{
		if((accno==ac)&&(strcmpi(p,password)==0))
		{
			flag=1;
			char ch1[5],ch2[5];
			itoa(accno,ch1, 10);
			itoa(age,ch2, 10);
			settextstyle(10,HORIZ_DIR,3);
			outtextxy(200,20,"PASSBOOK");
			outtextxy(200,50,"--------");
			settextstyle(10,HORIZ_DIR,1);
			outtextxy(100,100,"Name       :");
			outtextxy(300,100,name);
			outtextxy(100,150,"Address    :");
			outtextxy(300,150,address);
			outtextxy(100,200,"Account no:");
			outtextxy(300,200,ch1);
			outtextxy(100,250,"Age         :");
			outtextxy(300,250,ch2);
			settextstyle(10,HORIZ_DIR,3);
			while(!kbhit())
			{
				setcolor(15);
				outtextxy(80,420,"Press any key to continue...");
				delay(1000);
				setcolor(9);
               outtextxy(80,420,"Press any key to continue...");
				delay(1000);
			}
			setcolor(15);
			cleardevice();
			gotoxy(31,1);
			cout<<"PASSBOOK";
			gotoxy(30,2);
			cout<<"==========";
			gotoxy(1,4);
			cout<<"================================================================================";
			gotoxy(1,5);
			cout<<"S NO.";
			gotoxy(12,5);
			cout<<"PARTICULARS";
			gotoxy(26,5);
			cout<<"Cheque no.";
			gotoxy(43,5);
			cout<<"Date";
			gotoxy(52,5);
			cout<<"DEBIT";
			gotoxy(62,5);
			cout<<"CREDIT";
			gotoxy(72,5);
			cout<<"BALANCE";
			gotoxy(1,6);
			cout<<"================================================================================";
			break;
		}
	}
	while(f2.read((char *)&b,sizeof(b)))
	{
		if((accno==ac)&&(strcmpi(p,password)==0))
		{
			d=bal-a;
			b.display(pos,s,d);
			++s;
			++pos;
			a=bal;
		}
	}
	if(f1.eof())
	f1.clear();
	f1.seekg(0,ios::beg);
	while(f1.read((char *)&b,sizeof(b)))
	{
		if((accno==ac)&&(strcmpi(p,password)==0))
		{
			d=bal-a;
			b.display(pos,s,d);
			++s;
			++pos;
             a=bal;
			break;
		}
	}
	getch();
	getch();
	f1.close();
	f2.close();
	gotoxy(10,++i);
	if(flag==0)
	cout<<"Account not found";
	getch();
	closegraph();
}
int main_choice()
{
	int gd=DETECT,gm,main_ch,i;
	initgraph(&gd,&gm,"d:\\tc\\bgi");
	struct time t;
	setbkcolor(9);
	setcolor(WHITE);
	rectangle(150,80,470,410);
	rectangle(170,130,450,390);
	settextstyle(1,0,3);
	highvideo();
	fflush(stdin);
	outtextxy(260,90,"BANKING");
	settextstyle(2,0,6);
	outtextxy(210,170,"1.OPEN NEW ACCOUNT");
	outtextxy(210,190,"2.EDIT ACCOUNT");
	outtextxy(210,210,"3.DEPOSITE/WITHDRAW");
	outtextxy(210,230,"4.LIST OF ACCOUNTS");
	outtextxy(210,250,"5.PASSBOOK");
	outtextxy(210,270,"6.LOCKER");
	outtextxy(210,290,"7.ATM");
	outtextxy(210,310,"8.EXIT");
	outtextxy(205,364,"ENTER YOUR CHOICE(1-8):");
	gotoxy(54,24);
	settextstyle(4,0,4);
	!kbhit();
	while(!kbhit())
	{
	for(i=150;i<460;i=i+20)
{
	setcolor(15);
	gettime(&t);
	settextstyle(7,HORIZ_DIR,1);
	outtextxy(350,25,"TIME:");
	gotoxy(53,3);
	cout<<int(t.ti_hour)<<":"<<int(t.ti_min)<<":"<<int(t.ti_sec);
	settextstyle(4,0,4);
	rectangle(150,80,470,410);
	outtextxy(i,55,"*");
	delay(100);
	setcolor(9);
	outtextxy(i,55,"*");
	delay(10);
	if(kbhit())
	break;
	}
	for(i=55;i<380;i=i+20)
	{
	gettime(&t);
	setcolor(15);
	settextstyle(7,HORIZ_DIR,1);
	outtextxy(350,25,"TIME:");
	gotoxy(53,3);
	cout<<int(t.ti_hour)<<":"<<int(t.ti_min)<<":"<<int(t.ti_sec);
	rectangle(150,80,470,410);
	settextstyle(4,0,4);
	outtextxy(465,i,"*");
	delay(100);
	setcolor(9);
	outtextxy(465,i,"*");
	delay(10);
	if(kbhit())
	break;
	}
	for(i=460;i>150;i=i-20)
	{
	gettime(&t);
	setcolor(15);
	settextstyle(7,HORIZ_DIR,1);
	outtextxy(350,25,"TIME:");
	gotoxy(53,3);
	cout<<int(t.ti_hour)<<":"<<int(t.ti_min)<<":"<<int(t.ti_sec);
	rectangle(150,80,470,410);
	settextstyle(4,0,4);
	outtextxy(i,385,"*");
	delay(100);
	setcolor(9);
	outtextxy(i,385,"*");
	delay(10);
	if(kbhit())
	break;
	}
	for(i=380;i>55;i=i-20)
	{
	gettime(&t);
setcolor(15);
	settextstyle(7,HORIZ_DIR,1);
	outtextxy(350,25,"TIME:");
	gotoxy(53,3);
	cout<<int(t.ti_hour)<<":"<<int(t.ti_min)<<":"<<int(t.ti_sec);
	rectangle(150,80,470,410);
	settextstyle(4,0,4);
	outtextxy(145,i,"*");
	delay(100);
	setcolor(9);
	outtextxy(145,i,"*");
	delay(10);
	if(kbhit())
	break;
	}
	}
	gotoxy(54,24);
	cin>>main_ch;
	closegraph();
	return(main_ch);
}
void load()
{
	int gd=DETECT,gm,area,x=20,y=20,ch,xdirn=1,ydirn=1,i=10,sum=0;
	int maxx,maxy;
	initgraph(&gd,&gm,"d:\\tc\\bgi");
	setbkcolor(9);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,YELLOW);
	maxx=getmaxx();
	maxy=getmaxy();
	rectangle(0,0,maxx,maxy);
	rectangle(10,10,maxx-10,maxy-70);
	settextstyle(1,0,4);
	outtextxy(maxx-400,maxy-55,"Loading....");
	while(sum!=100)
	{
		settextstyle(1,0,5);
		setcolor(WHITE);
		outtextxy(x,y,"PROJECT");
		delay(i);
		setcolor(9);
		outtextxy(x,y,"PROJECT");
x=x+(xdirn*6);
		y=y+(ydirn*4);
		if(x+185>maxx||x<20)
		{
			sound(500);
			delay(i);
			sum=sum+i;
			nosound();
			xdirn*=-1;
		}
		if(y+120>maxy||y<20)
		{
			sound(500);
			delay(i);
			sum=sum+i;
			nosound();
			ydirn*=-1;
		}
	}
	closegraph();
	restorecrtmode();
}
void graphics_screen()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "d:\\tc\\bgi"); // Initialize the graphics system
	rectangle(22, 7, 630, 450);      // Draw a rectangle
	rectangle(32, 17, 620, 440);
	int x = 1,p, h = 0, r, fla;
	int q=370;
	while ((x != 143) && (!kbhit()))
	{
		h = 0;
		p=0;
		q=370;
		const char far *t[] = {"A","B","H","I","S","H","E","K"," ","A","B","H","I","N","A","V"," ","N","I","T","I","N"};
		while ((h <=21) && (!kbhit()))
		{
			setbkcolor(12);
			setcolor(x+h);
			highvideo();
			settextstyle(4, HORIZ_DIR, 9);
			outtextxy(87, 20, "BANKING");
			outtextxy(97, 190, "SYSTEM");
			settextstyle(1, HORIZ_DIR, 3);
			if ((h % 2) == 0)
fla = 15;
			else
				fla = 12;
			setcolor(fla);
			outtextxy(215, 450, "Press any key to start.....");
			settextstyle(1, HORIZ_DIR, 3);
			if(x%2!=0)
			{
				setcolor(x+2);
			}
			else
			setcolor(12);
			outtextxy(320, 340, "BY:-");
			if(*t[h]==' ')
			{
				q=q+20;
				p=0;
			}
			outtextxy(340+p, q, t[h]);
			delay(500);
			p=p+15;
			++h;
		}
		x++;
	}
	closegraph();
}
void exit_bank()
{
	int gd=DETECT,gm,area,x1=0,y1=0,x2=50,y2=50,yy=1,xx=1,ch,xdirn=1,ydirn=1,i;
	int maxx,maxy;
	initgraph(&gd,&gm,"d:\\tc\\bgi");
	setbkcolor(BLACK);
	setcolor(RED);
	setfillstyle(SOLID_FILL,YELLOW);
	maxx=getmaxx();
	maxy=getmaxy();
	rectangle(0,0,maxx,maxy);
	settextstyle(1,0,4);
	while(!kbhit())
	{
		setcolor(3);
		rectangle(0,0,maxx,maxy);
		outtextxy(maxx/2-180,maxy/2-120,"THANKS FOR VISITING");
outtextxy(maxx/2-130,maxy/2-70,"THE PROJECT");
		outtextxy(maxx/2+40,maxy/2+80,"COMPILED BY:-");
		outtextxy(maxx/2+80,maxy/2+130,"ABHISHEK AG");
		outtextxy(maxx/2+80,maxy/2+160,"ABHINAV");
		outtextxy(maxx/2+80,maxy/2+190,"NITIN");
		setcolor(4);
		line(x1,y1,x2,y2);
		x1=x1+(xdirn*2);
		y1=y1+(ydirn*6);
		x2=x2+(xx*4);
		y2=y2+(yy*2);
		line(x1,y1+5,x2,y2+5);
		x1=x1+(xdirn*2);
		y1=y1+(ydirn*6);
		x2=x2+(xx*4);
		y2=y2+(yy*2);
		line(x1,y1+25,x2,y2+25);
		x1=x1+(xdirn*2);
		y1=y1+(ydirn*6);
		x2=x2+(xx*4);
		y2=y2+(yy*2);
		line(x1,y1+15,x2,y2+15);
		x1=x1+(xdirn*2);
		y1=y1+(ydirn*6);
		x2=x2+(xx*4);
		y2=y2+(yy*2);
		line(x1,y1+35,x2,y2+35);
		x1=x1+(xdirn*2);
		y1=y1+(ydirn*6);
		x2=x2+(xx*4);
		y2=y2+(yy*2);
		line(x1,y1+65,x2,y2+65);
		x1=x1+(xdirn*2);
		y1=y1+(ydirn*6);
		x2=x2+(xx*4);
		y2=y2+(yy*2);
		line(x1,y1+45,x2,y2+45);
		x1=x1+(xdirn*2);
		y1=y1+(ydirn*6);
		x2=x2+(xx*4);
		y2=y2+(yy*2);
		line(x1,y1+55,x2,y2+55);
		delay(290);
		cleardevice();
		if(kbhit())
		{
			if(ch==27)
				break;
		}
		x1=x1+(xdirn*2);
		y1=y1+(ydirn*4);
		if(x1>maxx||x1<0)
		{
			xdirn*=-1;
		}
		if(y1>maxy||y1<0)
{
			ydirn*=-1;
		}
		x2=x2+(xx*6);
		y2=y2+(yy*4);
		if(x2>maxx||x2<0)
		{
			xx*=-1;
		}
		if(y2>maxy||y2<0)
		{
			yy*=-1;
		}
	}
	getch();
	closegraph();
	restorecrtmode();
}
void front_page()
{
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	int stangle = 0, endangle = 360;
	int xradius = 100, yradius = 50;
	initgraph(&gdriver, &gmode, "d:\\tc\\bgi");
	int x,y,i,j,k,l;
	setbkcolor(1);
	setcolor(2);
	for(i=0;i<=150;++i)
	{
		x = getmaxx()/2 ;
		y = getmaxx()/2-85 ;
		circle(x,y,i);
	}
	setbkcolor(4);
	setcolor(14);
	for(j=300;j>=250;j--)
	{
		x = getmaxx()/2 ;
		y = getmaxx()/2-85 ;
		circle(x,y,j);
	}
	setbkcolor(9);
	setcolor(5);
	for(k=150;k<=250;k++)
	{
		x = getmaxx()/2 ;
		y = getmaxx()/2-85 ;
ellipse(x, y, 0, 360,20,k);
	}
	setcolor(5);
	for(k=150;k<=250;k++)
	{
		x = getmaxx()/2 ;
		y = getmaxx()/2-85 ;
		ellipse(x, y, 0, 360,k,20);
	}
	setcolor(14);
	for(j=50;j>=20;j--)
	{
		x = getmaxx()/2 ;
		y = getmaxx()/2-85 ;
		circle(x,y,j);
	}
	setcolor(11);
	for(j=20;j>=0;j--)
	{
		x = getmaxx()/2 ;
		y = getmaxx()/2-85 ;
		circle(x,y,j);
	}
	setbkcolor(9);
	setcolor(9);
	setcolor(13);
	setfillstyle(3,15);
	settextstyle(4,0,6);
	setcolor(13);
	outtextxy(30,0, "kv");
	outtextxy(175,80,"BAREILLY");
	setcolor(1);
	settextstyle(7,0,5);
	outtextxy(150,200,"Session 2008-09");
	settextstyle(1,0,5);
	outtextxy(30,350,"Guided By:");
	setcolor(4);
	settextstyle(3,0,2);
	outtextxy(35,405,"yz");
	setcolor(1);
	settextstyle(1,0,5);
	outtextxy(340,350,"Submitted By:");
	setcolor(4);
	settextstyle(3,0,2);
	outtextxy(385,405," n ");
	delay(5000);
	closegraph();
	initgraph(&gdriver, &gmode, "d:\\tc\\bgi");
	setbkcolor(20);
	setcolor(14);
	for(l=0;l<=300;l++)
	{
	x = getmaxx()/2 ;
	y = getmaxx()/2-80 ;
	ellipse(x,y,450,90,l,235);
	}
setbkcolor(20);
	setcolor(6);
	for(l=0;l<=75;l++)
	{
		x = getmaxx()/2 ;
		y = getmaxx()/2-80 ;
		circle(x,y,l);
	}
	setcolor(9);
	settextstyle(8,0,9);
	outtextxy(293,0,"A");
	settextstyle(8,0,6);
	outtextxy(70,120,"PROJECT REPORT");
	settextstyle(8,0,6);
	outtextxy(276,200,"ON");
	settextstyle(8,0,6);
	outtextxy(70,300,"BANKING SYSTEM");
	settextstyle(3,0,2);
	delay(5000);
	closegraph();
}
void help()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "d:\\tc\\bgi");
	setbkcolor(9);
	setcolor(7);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(30,20,"Welcome to Banking Project");
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(40,100, "This project your can keep record of daily banking transaction");
	delay(1000);
	outtextxy(40,130, "This program is capable of holding any no. of account.");
	delay(1000);
	outtextxy(40,160, "-In first option you can open new account");
	delay(1000);
	outtextxy(40,190, "-In second option you can edit your account");
	delay(1000);
	outtextxy(40,220,"-In third option you can deposite or withdraw from your account");
	delay(1000);
	outtextxy(40,250, "-In fourth option you can see list of all the accounts");
	delay(1000);
	outtextxy(40,280, "-In fifth option you can see your passbook");
	delay(1000);
	outtextxy(40,310, "-In sixth option you can take loan");
	delay(1000);
	outtextxy(40,340,"-In seventh option you can access your locker if you have opted for it");
	delay(1000);
	outtextxy(40,370, "-In eighth option you can access ATM machine");
	delay(1000);
	outtextxy(40,400, "-And last option is Quit (Exit to Window)");
settextstyle(10,HORIZ_DIR,3);
	outtextxy(80,420,"Press any key to continue...");
	delay(1000);
	getch();
	cleardevice();
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(30,20,"Continued.....");
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(40,130, "-The bank opens at 9 A.M and closes at 10 P.M");
	delay(1000);
	outtextxy(40,160, "-Lunch break is from 2 P.M to 3 P.M");
	delay(1000);
	outtextxy(40,190, "-No trasactions will be done during lunch break.");
	delay(1000);
	outtextxy(40,220,"-ATM machine can be used any time.");
	delay(1000);
	settextstyle(10,HORIZ_DIR,3);
	while(!kbhit())
	{
		setcolor(7);
		outtextxy(80,420,"Press any key to continue...");
		delay(1000);
		setcolor(9);
		outtextxy(80,420,"Press any key to continue...");
		delay(1000);
	}
	setcolor(7);
	closegraph();
}
void open_acc_help()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "d:\\tc\\bgi");
	setbkcolor(9);
	setcolor(7);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(30,20,"Help To Open Account");
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(40,100, "With this option you can open new account.");
	delay(1000);
	outtextxy(40,140, "Opening balance should not be less than Rs.500");
	delay(1000);
	outtextxy(40,180, "You can protect your account with the help of a password.");
	delay(1000);
	outtextxy(40,220, "You can access your account with the password only");
	delay(1000);
	outtextxy(40,260,"In case you forget your password you cannot your account.");
	delay(1000);
	outtextxy(40,300, "So give a password you cannot forget.");
delay(1000);
	outtextxy(40,340, "You can also opt for locker facility.");
	delay(1000);
	outtextxy(40,380, "Bank will not be responsible for any misfortune.");
	delay(1000);
	settextstyle(10,HORIZ_DIR,3);
	while(!kbhit())
	{
	setcolor(7);
	outtextxy(80,420,"Press any key to continue...");
	delay(1000);
	setcolor(9);
	outtextxy(80,420,"Press any key to continue...");
	delay(1000);
	}
	getch();
	closegraph();
}
void bank_close()
{
	struct  time t;
	gettime(&t);
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "d:\\tc\\bgi");
	setbkcolor(9);
	while(!kbhit())
	{
		gettime(&t);
		setcolor(7);
		settextstyle(7,HORIZ_DIR,1);
		outtextxy(350,25,"TIME:");
		gotoxy(53,3);
		cout<<int(t.ti_hour)<<":"<<int(t.ti_min)<<":"<<int(t.ti_sec);
		settextstyle(10,HORIZ_DIR,5);
		outtextxy(30,100,"BANK");
		outtextxy(210,200,"IS");
		outtextxy(300,300,"CLOSED..");
		delay(1000);
		setcolor(9);
		settextstyle(10,HORIZ_DIR,5);
		outtextxy(30,100,"BANK");
		outtextxy(210,200,"IS");
		outtextxy(300,300,"CLOSED..");
		delay(700);
	}
	getch();
	closegraph();
}
void bank_lunch()
{
	struct  time t;
	gettime(&t);
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "d:\\tc\\bgi");
	setbkcolor(9);
	getch();
	!kbhit();
	while(!kbhit())
	{
		gettime(&t);
		setcolor(7);
		settextstyle(7,HORIZ_DIR,1);
		outtextxy(350,25,"TIME:");
		gotoxy(53,3);
		cout<<int(t.ti_hour)<<":"<<int(t.ti_min)<<":"<<int(t.ti_sec);
		settextstyle(10,HORIZ_DIR,6);
		outtextxy(100,100,"LUNCH");
		outtextxy(300,250,"BREAK");
		delay(1000);
		setcolor(9);
		settextstyle(10,HORIZ_DIR,6);
		outtextxy(100,100,"LUNCH");
		outtextxy(300,250,"BREAK");
		delay(700);
	}
	getch();
	closegraph();
}
void sunday_close()
{
	struct  time t;
	gettime(&t);
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "d:\\tc\\bgi");
	setbkcolor(9);
	getch();
	while(!kbhit())
	{
gettime(&t);
		setcolor(7);
		settextstyle(7,HORIZ_DIR,1);
		outtextxy(350,25,"TIME:");
		gotoxy(53,3);
		cout<<int(t.ti_hour)<<":"<<int(t.ti_min)<<":"<<int(t.ti_sec);
		settextstyle(10,HORIZ_DIR,6);
		outtextxy(100,100,"SUNDAY");
		outtextxy(300,250,"CLOSE");
		delay(1000);
		setcolor(9);
		settextstyle(10,HORIZ_DIR,6);
		outtextxy(100,100,"SUNDAY");
		outtextxy(300,250,"CLOSE");
		delay(700);
	}
	getch();
	closegraph();
}
void bank_str()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "d:\\tc\\bgi");
	int maxx=getmaxx();
	int maxy=getmaxy();
	rectangle(0,0,maxx,maxy);
	ellipse(320,300,122,76,319,200);
	ellipse(370,350,0,360,60,50);
	ellipse(370,350,0,360,25,20);
	setcolor(0);
	ellipse(370,350,210,260,60,50);
	ellipse(370,350,330,380,60,50);
	setcolor(15);
	line(317,375,178,480);
	line(360,400,260,480);
	line(425,332,632,340);
	line(420,375,612,380);
	line(250,50,250,300);
	line(250,50,400,10);
	line(400,10,400,260);
	line(400,260,250,300);
	line(250,50,150,20);
	line(150,20,150,270);
	line(150,270,250,300);
	line(150,20,240,0);
	line(150,30,250,60);
	line(250,60,400,20);
	line(164,25,275,0);
	line(400,10,330,0);
	line(380,15,275,0);
line(250,80,400,40);
	line(250,110,400,70);
	line(250,140,400,100);
	line(250,170,400,130);
	line(250,200,400,160);
	line(250,230,400,190);
	line(150,50,250,80);
	line(150,80,250,110);
	line(150,110,250,140);
	line(150,140,250,170);
	line(150,170,250,200);
	line(150,200,250,230);
	setfillstyle(1,2);
	floodfill(370,350,15);
	floodfill(150,350,15);
	floodfill(370,450,15);
	setfillstyle(1,9);
	floodfill(100,50,15);
	floodfill(450,10,15);
	setfillstyle(1,5);
	floodfill(170,30,15);
	floodfill(170,50,15);
	floodfill(170,70,15);
	floodfill(170,100,15);
	floodfill(170,120,15);
	floodfill(170,150,15);
	floodfill(170,180,15);
	floodfill(170,210,15);
	floodfill(255,50,15);
	floodfill(255,70,15);
	floodfill(255,100,15);
	floodfill(255,130,15);
	floodfill(255,160,15);
	floodfill(255,190,15);
	floodfill(255,220,15);
	floodfill(255,250,15);
	setfillstyle(1,13);
	floodfill(250,20,15);
	setfillstyle(1,7);
	floodfill(10,450,15);
	floodfill(600,450,15);
	floodfill(400,350,15);
	settextstyle(10,0,1);
	setcolor(0);
	outtextxy(130,420,"Press Any Key To Continue");
	settextstyle(4,0,3);
	getch();
	while(!kbhit())
	{
	setcolor(0);
	outtextxy(280,190,"B");
	outtextxy(300,185,"A");
	outtextxy(320,180,"N");
	outtextxy(340,175,"K");
	delay(1000);
	setcolor(5);
outtextxy(280,190,"B");
	outtextxy(300,185,"A");
	outtextxy(320,180,"N");
	outtextxy(340,175,"K");
	delay(700);
	}

	ellipse(320,300,122,76,319,200);
	getch();
	closegraph();
}
void main()
{
	int main_ch;
	load();
	front_page();
	graphics_screen();
	bank_str();
	help();
	struct  time t;
	gettime(&t);
	struct tm time_check;
	int year, month, day;
	struct date d;
	getdate(&d);
	month=d.da_mon;
	day=d.da_day;
	year=d.da_year;
	time_check.tm_year = year - 1900;
	time_check.tm_mon  = month - 1;
	time_check.tm_mday = day;
	time_check.tm_hour = 0;
	time_check.tm_min  = 0;
	time_check.tm_sec  = 1;
	time_check.tm_isdst = -1;
	if (mktime(&time_check) == -1)
	time_check.tm_wday = 7;
	wday[time_check.tm_wday];
	if(strcmpi((wday[time_check.tm_wday]),"Sunday")==0)
	{
		sunday_close();
		exit(0);
	}

	if((t.ti_hour<9)||(t.ti_hour>20))
	{
//		bank_close();
  //		exit(0);
	}
	if(t.ti_hour==14)
	{
		bank_lunch();
		exit(0);
	}
	do
	{
		fflush(stdin);
		main_ch=main_choice();
		switch(main_ch)
		{
			case 1:open_acc_help();
			       b.getdata();
			       break;
			case 2:b.edit_account();
			       break;
			case 3:b.daily_trans();
			       break;
			case 4:b.list_accno();
			       break;
			case 5:b.detail_accno();
			       break;
			case 6:b.locker();
			       break;
			case 7:atm();
			       break;
			case 8:exit_bank();
			       break;
		}
		clrscr();
	}
	while(main_ch!=8);
}


