#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct patient
{
        long long mob_no;
	string firstname;
	string lastname;
	int age;
	char blood_grp[6];
	char gender;
        patient*next;
};
class hospital_management
{
	patient *front,*rear;
	int fee,med_fee;
	public:
hospital_management	() //constructor
	{
		front=NULL;
		rear=NULL;
	}
    patient input();
    void insertatend();
    void insertatbeg();
    void getpatientout();
    void displaypatients();
    int search(int);
    char deptname[50];
    void total_bill();
   friend void total_exp(hospital_management);
};

int hospital_management :: search(int item)
{
	 if(front==NULL)
     return false;
     else
     {
     int flag=0;
     patient*p=new patient();
     p=front;
     while( p->next!=NULL && p->mob_no!=item )
     {
        p=p->next;
     }
     if(p->mob_no==item)
     {
	 	flag=1;
	 	return true;
     }
     if(flag==0)
     return false;
     }
}

int convertnumber()
{
   char b[20];
   cin.getline(b, sizeof(b));
   return atoi(b);
}

patient hospital_management :: input()
{
    int flag=0;
   patient *p=new patient();
   cout << "\n\tPlease enter data for patient\n";
   cout<<"\n\tFirst name     : ";
   getline(cin,p->firstname);
   cout << "\tLast name      : ";
   getline(cin,p->lastname);
   again :
   cout << "\tBlood Group    : ";
   cin>>p->blood_grp;
   if((strcmp(p->blood_grp,"A+")==0)||(strcmp(p->blood_grp,"a+")==0)||(strcmp(p->blood_grp,"A-")==0)||(strcmp(p->blood_grp,"a-")==0)||
      (strcmp(p->blood_grp,"B+")==0)||(strcmp(p->blood_grp,"b+")==0)||(strcmp(p->blood_grp,"B-")==0)||(strcmp(p->blood_grp,"b-")==0)||
      (strcmp(p->blood_grp,"O+")==0)||(strcmp(p->blood_grp,"o+")==0)||(strcmp(p->blood_grp,"O-")==0)||(strcmp(p->blood_grp,"o-")==0)||
      (strcmp(p->blood_grp,"AB+")==0)||(strcmp(p->blood_grp,"ab+")==0)||(strcmp(p->blood_grp,"AB-")==0)||(strcmp(p->blood_grp,"ab-")==0))
             flag=1;
    if(flag==0)
    {
        cout<<"\nWrong Entry...Enter a valid Blood Group..Try Again..";
        goto again;

    }
   cout<<"\tGender           : (m/f)";
   cin>>p->gender;
   cout<<"\tAge              : ";
   cin>>p->age;
   cout<<"\tMobile number    : ";
   cin>>p->mob_no;
         if(search(p->mob_no))
	{
		p->mob_no=0;
		cout << "\n\tData not valid. Operation cancelled.";
	}
	return *p;
}

void output(patient *p)
{
	cout<<"\n************";
	cout<<"\n\nPatient data:";
	cout<<"\n\nFirst Name       : "<<p->firstname;
	cout<<"\nLast Name          : "<<p->lastname;
	cout<<"\nGender             : "<<p->gender;
	cout<<"\nAge                : "<<p->age;
	cout<<"\nBlood Group        : "<<p->blood_grp;
	cout<<"\nMobile Number      : "<<p->mob_no;
	cout<<"\n\n************";
}
void hospital_management :: insertatbeg()
{
     patient*p=new patient();
     *p=input();
     if(p->mob_no==0)
     return;

     if(front==NULL)

     {
         front=p;
         rear=p;
         p->next=NULL;
     }
     else
     {
        p->next=front;
        front=p;
     }
     system("cls");
     cout << "\n\tPatient added:";
     output(p);
}
void hospital_management:: insertatend()
{
     patient*p=new patient();
     *p=input();
     if(p->mob_no==0)
     return;

     if(front==NULL)
     {
     	front=p;
        rear=p;
        p->next=NULL;
     }
     else
     {
     	p->next=NULL;
        rear->next=p;
        rear=p;
     }
     system("cls");
     cout << "\n\tPatient added:";
     output(p);
}
void hospital_management :: getpatientout()
{
     system("cls");
     if(front==NULL)
     {
     	cout<<"\n\tNo Patient to operate";
     }
     else
     {
     	patient*p=new patient();
     	p=front;
     	front=front->next;
 	    cout << "\n\tPatient to operate:";
        output(p);
     }
}

void hospital_management:: displaypatients()
{
     if(front==NULL)
     {
     	cout<<"\n\tNo patient";
     }
     patient*p=new patient;
     p=front;
     while(p!=NULL)
     {
     	output(p);
        p=p->next;
     }
     cout<<"\n";
}


void deptmenu (hospital_management * q)
{
    int choice = 0, success;
    patient p;
    while (choice != 5)
	{
    system("cls");
	cout<<"\n\n\tWelcome To depts : " << q->deptname;
	cout<<"\n\t\t[1] Add normal patient\n";
	cout<<"\t\t[2] Add critically ill patient\n";
	cout<<"\t\t[3] Take patient to Doctor\n";
	cout<<"\t\t[4] Display list\n";
	cout<<"\t\t[5] Change depts or exit\n";
	cout<<"\n\tPlease enter your choice : ";
	choice=convertnumber();

    switch (choice)
	{
	  case 1:	q->insertatend();
			cout << "\n\tPress any key";
	    		getch();
			break;

          case 2:	q->insertatbeg();
	    		cout << "\n\tPress any key";
	    		getch();
			break;

          case 3:	q->getpatientout();
			cout<<"\n\tPress any key";
     			getch();
	      		break;

          case 4:	system("cls");
			q->displaypatients();
			cout<<"\n\tPress any key";
			getch();
			break;
	 }
    }
}
void hospital_management::total_bill()
{
	cout<<"        docter fees: ";
	cin>>fee;
	cout<<"        medicine bill: ";
        cin>>med_fee;
}
void total_exp(hospital_management obj)
{
 int total;
 total=obj.fee+obj.med_fee;
 cout<<"      total bill: ";
 cout<<total;
 	
}
int main ()
{
    int i, choice = 0;
    hospital_management depts[4];
    hospital_management p1;
    
	while(choice!=5)
	{
		strcpy(depts[0].deptname,"General Clinic\n");
		strcpy(depts[1].deptname,"Heart Clinic\n");
		strcpy(depts[2].deptname,"Lung Clinic\n");
		strcpy(depts[3].deptname,"Plastic Surgery\n");
		system("cls");
		cout<<"\n\t>>>>>>>>>>>>>>>>>>>>>>>>>>";
		cout<<"\n\tHOSPITAL MANAGEMENT SYSTEM\t";
		cout<<"\n\t<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
		for (i = 0; i < 4; i++)
		{
			cout<<"\t"<<(i+1)<<": "<<depts[i].deptname;
		}
		cout<<"\t5: Exit";
		cout<<"\n\n\tPlease enter your choice : ";
		choice=convertnumber();
		if(choice>=1 && choice<=4)
		{
			deptmenu(&depts[choice-1]);
		}

	}
	p1.total_bill();
	total_exp(p1);
	if(choice==5)
	cout<<"\n\n\tTHANK YOU FOR VISITING! \n";
	exit(0);
}
