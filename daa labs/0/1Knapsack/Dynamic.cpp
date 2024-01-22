
#include<iostream>
#include<math.h>
using namespace std;
class Bag     //class of Object which has all parameters
{
	public:
	int id;         //id to recognize the object
	double w;
	double p,r;
	double fraction;
	double Ratio()    //function to calculate the ratio
	{   
		return r=p/w;
	}
	void Sort(Bag A[],int n);
	void Sack(Bag A[],int n,double capacity);
};
void Bag::Sack(Bag A[],int n,double capacity)     //actual logic of function
{
	double TW=0,TP=0;        //TP=total profit     TW=total weight
	int i=0;
	while(1)                 //loop to traverse through each object in bag
	{
		if(TW<capacity)          
		{ 
			if(A[i].w<=(capacity-TW))    //if capacity is not full and whole object can be fitted in it
			{
				A[i].fraction=1;
				TW+=A[i].w;
				TP+=A[i].p;
			}
			else if(A[i].w>(capacity-TW))       //if capacity is not enough to fit whole object
			{
				A[i].fraction=((capacity-TW)/A[i].w);    //calculating fraction 
				TW+=A[i].w*(A[i].fraction);
				TP+=A[i].fraction*A[i].p;
			}
		}
		else
		{
			break;   //if capacity is full break the loop
		}
		i++;
	}
	cout<<"Total Profit is:"<<TP;  //returning total profit as an output
}
void Bag::Sort(Bag A[],int n)     //function to sort the objects in bag according to ratio
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(A[j].r<A[j+1].r)
			{
				Bag temp=A[j+1];
				A[j+1]=A[j];
				A[j]=temp;
			}
		}
	}
}

int main()
{
	double capacity;
	int n;
	cout<<"Enter the Capacity:";
	cin>>capacity;
	cout<<"Enter No of objects:";
	cin>>n;
	Bag b;
	Bag obj[n];
	for(int i=0;i<n;i++)    //taking input of weight and profit
	{
		obj[i].id=i+1;
		cout<<"Enter Weight of object "<<i+1;
		cin>>obj[i].w;
		cout<<"Enter Profit of object "<<i+1;
		cin>>obj[i].p;
		obj[i].Ratio();
	}
	cout<<"\nID\t"<<"Weight\t"<<"Profit\t"<<"Ratio\t"<<"Fraction\n";
	for(int i=0;i<n;i++)        //displaying all quantities of object
	{
		cout<<obj[i].id<<"\t";
		cout<<obj[i].w<<"\t";
		cout<<obj[i].p<<"\t";
		cout<<obj[i].r<<"\t";
		cout<<obj[i].fraction<<"\n";
	}
	cout<<"\nAfter Sorting\n";
	b.Sort(obj,n);         //sorting the objects in bag
	cout<<"\nID\t"<<"Weight\t"<<"Profit\t"<<"Ratio\t"<<"Fraction\n";
	for(int i=0;i<n;i++)    //displaying all quantities of object in sorted order
	{
		cout<<obj[i].id<<"\t";
		cout<<obj[i].w<<"\t";
		cout<<obj[i].p<<"\t";
		cout<<obj[i].r<<"\t";
		cout<<obj[i].fraction<<"\n";
	}
	b.Sack(obj,n,capacity);  //calling function with actual knapsack logic
	return 0;
}

