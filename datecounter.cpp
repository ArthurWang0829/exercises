#include <iostream>
using namespace std;
// int datecounter(int a,int b)
// {
// 	if(a==b)
// 		return 1;
// 		int y1,y2,m1,m2,d1,d2;
// 		y1 = a/10000;
// 		y2 = b/10000;
// 		m1 = (a/100)%100;
// 		m2 = (b/100)%100;
// 		d1 = a%100;
// 		d2 = b%100;
// }
template <class T> int len(T& array)
{
	return (sizeof(array)/sizeof(array[0]));
}
void selectsort(int a[])
{
	int i,j,temp;
	int n = len(a);
	cout<<n<<endl;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<=n+1;j++)
		{
			if(a[i]>=a[j])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}

int main()
{
	int a[] = {3,2,54,12,65,78,5,9,6,8};
	for(int i=0;i<10;i++)
	{
		cout<<a[i]<<"\t";
	}
	
	selectsort(a);
	cout<<endl<<"After sorting:\n";
	for(int i=0;i<10;i++)
	{
		cout<<a[i]<<"\t";
	}
	return 0;
}