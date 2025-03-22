#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<conio.h>
int main()
{
	int i,u,v,idt,ibd,yrs,mon,dys,month,date,yr,itm,Days;
	double hr,min,sec;
	char dt[12],bd[12],tm[10];
//	printf("Today:%s\n",__DATE__);
//	printf("%s\n",__TIME__);
	strcpy(dt,__DATE__);
//	puts(tm);
//	idt[3]=1;idt[4]=2;
	for(i=0;i==0;i++)
	{
	if(dt[i]=='S'){	dt[i+2]='0';dt[i+3]='9';}	
	if(dt[i]=='O'){	dt[i+2]='1';dt[i+3]='0';}
	if(dt[i]=='N'){	dt[i+2]='1';dt[i+3]='1';}
	if(dt[i]=='D'){	dt[i+2]='1';dt[i+3]='2';}
	if(dt[i]=='F'){	dt[i+2]='0';dt[i+3]='2';}
	if(dt[i]=='M'&& dt[i+1]=='a' && dt[i+2]=='r'){	dt[i+2]='0';dt[i+3]='3';}
	if(dt[i]=='M'&& dt[i+1]=='a' && dt[i+2]=='y'){	dt[i+2]='0';dt[i+3]='5';}
	if(dt[i]=='J'&& dt[i+1]=='a' && dt[i+2]=='n'){	dt[i+2]='0';dt[i+3]='1';}
	if(dt[i]=='J'&& dt[i+1]=='u' && dt[i+2]=='n'){	dt[i+2]='0';dt[i+3]='6';}
	if(dt[i]=='J'&& dt[i+1]=='u' && dt[i+2]=='l'){	dt[i+2]='0';dt[i+3]='7';}
	if(dt[i]=='A'&& dt[i+1]=='p' && dt[i+2]=='r'){  dt[i+2]='0';dt[i+3]='4';}
	if(dt[i]=='A'&& dt[i+1]=='u' && dt[i+2]=='g'){	dt[i+2]='0';dt[i+3]='8';}
	}
	for(i=6;i<10;i++) dt[i]=dt[i+1];
	for(i=0;i<2;i++)  dt[i]=dt[i+4];	// to replace date and month
	for(i=4;i<9;i++)  dt[i]=dt[i+1];
	for(i=4;i<8;i++)  dt[i]=dt[i+1];
	dt[8]='\0';
//	for(i=0;i<8;i++) printf("%c",dt[i]);	// present date
	printf("\nEnter your Date of Birth:");
	gets(bd);
	for(i=2;i<9;i++) bd[i]=bd[i+1];		//to remove special characters
	for(i=4;i<8;i++) bd[i]=bd[i+1];
	bd[8]='\0';
//	for(i=0;i<8;i++) printf("%c",bd[i]);	// birthday 
	idt=atoi(dt);
	ibd=atoi(bd);
//	printf("%d\t%d",idt,ibd);
	yr=idt%10000;
	yrs=(idt%10000-ibd%10000);
//	printf("%d",yrs);
	u=idt/10000;u=u%100;
	v=ibd/10000;v=v%100;month=v;
//	printf("%d\t%d",u,v);
	mon=(u-v);
	if(mon<=0)
	{
		yrs=yrs-1;
		mon=12+mon;
	}
	u=idt/1000000; 
	v=ibd/1000000; date=v;
	dys=(u-v);
	if(dys<=0)
	{
		mon=mon-1;
		dys=30+dys;
	}
	printf("\nYour AGE is:\n\n%d Years\t%d Months\t%d Days\n",yrs,mon,dys);
	printf("\nTOTALLY..\n\n%d Months\t",(yrs*12)+mon);
 //	printf("%d\t%d",month,date);
	int days[24]={1,-2,1,0,1,0,1,1,0,1,0,1,1,-2,1,0,1,0,1,1,0,1,0,1},sum=0,c=0;
	for(i=0;i<(yrs%4);i++) { if((yr-i)%4==0) c++;}		//	printf("%d",c);
	for(i=month;i<mon+month;i++) sum=sum+days[i-1];
	sum=sum+(mon*30);
	Days=c+(yrs/4)+(yrs*365)+sum+dys;
	printf("%d Weeks\t",(Days/7));
	printf("%d Days\n",Days);
//	time_t tim;
//	time(&tim);
//	printf("\n%s",ctime(&tim));	
	strcpy(tm,__TIME__);
//	puts(tm);
	for(i=2;i<7;i++) tm[i]=tm[i+1];		//to remove special characters
	for(i=4;i<6;i++) tm[i]=tm[i+1];
	tm[6]='\0';
//	puts(tm);
	itm=atoi(tm);
//	printf("\n%d",itm);
	printf("\nAPPROXIMATELY..\n");
	hr=(Days*24)+(itm/10000)-12;
	u=itm/100; u=u%100;
	min=(hr*60)+u;
	sec=(min*60)+(itm%100);
	printf("\n%.0lf Hours\t%.0lf Minutes\t\t%.0lf Seconds",hr,min,sec);
	int d,mc,yc,y,ly,cen,Sum,dayy;
	int monthcode[]={0,3,3,6,1,4,6,2,5,0,3,5};
	int cencode[]={6,4,2,0};
	d=ibd/1000000;
	u=ibd/10000; v=u%100;
	mc=monthcode[v-1];
//	printf("%d\n",mc);
	y=ibd%100;
	ly=y/4;
	u=ibd%10000; v=u/100;
	cen=v+1;				// century
	i=(cen%4)-1;
	yc=cencode[i];
	Sum=d+mc+yc+y+ly;		// SUM= date+monthcode+centurycode+last 2 digits of year+no.of leap years(y/4);
//	printf("%d\n",Sum);
	dayy=Sum%7;
	printf("\n\nYou were born on: ");
	if(dayy==0) printf("SUNDAY");
	if(dayy==1) printf("MONDAY");
	if(dayy==2) printf("TUESDAY");
	if(dayy==3) printf("WEDNESDAY");
	if(dayy==4) printf("THURSDAY");
	if(dayy==5) printf("FRIDAY");
	if(dayy==6) printf("SATURDAY"); 
	return 0;
}