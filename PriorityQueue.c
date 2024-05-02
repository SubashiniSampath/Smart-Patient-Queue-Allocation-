
// triage in Hospital room...
#include<stdio.h>
#include<stdlib.h>
struct Patient
{
	char name[20];
	int age;
	int severity;
	int id;
};
int f=0,r=0,capacity = 20;
struct Patient patients[20];

void i_sort()
{
	struct Patient temp;
	int j=r-1;
	while(j>0)
	{
 		if(patients[j].severity > patients[j-1].severity)
		{
			temp= patients[j];
			patients[j]=patients[j-1];
			patients[j-1]=temp;
			j--;
		}
  	    else
	      	break;
    }    
}


void enqueue()
{
	//getting the details..
	if(r >= capacity)
	{
		//overflow error...
		printf("\n Patients slots filled");
	}
	else
	{
		printf("enter the name of the patient:\n");
		scanf("%s",patients[r].name);
		printf("enter the age of the patient:\n");
		scanf("%d",&(patients[r].age));
		printf("enter the severity of the patient:\n");
		scanf("%d",&(patients[r].severity));
		printf("Patient id is %d",r);
		patients[r].id=r;
        r++;
        i_sort();
	}
}	


void dequeue()
{
	if(f == r)
	{
		//underflow error...
		printf("\n No bookings yet...");
	}
	else
	{
		printf("first patient :\n");
		printf("Patient Name:%s\n",patients[f].name);
		printf("patient Age:%d\n",patients[f].age);
		printf("Patient ID:%d\n",patients[f].id);
		printf("Patient Severity:%d\n",patients[f].severity);

		// shifting left..
		for(int k = 1;k < r;k++)
			patients[k-1]=patients[k];
		r--;
	}
}

void search()
{
	if(f == r)
	{
		printf("\n No bookings yet...");
	}
	else
	{
		int id1,k=0;
		printf("\n enter your id :");
		scanf("%d",&id1);
		for(k=f;k<r;k++)
		{
			if(id1==patients[k].id)
			{
				printf("\n you are patient %d based on your severity",k+1);
			}
			else
				printf("your details is not filled yet ...")
		}
	}	
}

void main()
{
	int choice=0,p,a=1;
	while(a==1)
	{
		printf("\n enter your choice:\n 1.book your slot \n 2.next patient in queue\n 3.know your slot number\n 4. exit.");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				search();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\n wrong choice...");
			
		}
		printf("\n Enter 1 to continue..(0/1)");
		scanf("%d",&a);
	}	

}

