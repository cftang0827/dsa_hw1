#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}

int GCD_BY_REVERSE_SEARCH(int a, int b, int& c)
{
	for (int i=min(a,b) ; i>=1 ; i--)
	{
		c = c+1;
		if ((a%i==0) && (b%i==0) )
		{
			return i;
		}
	}

}


int min(int a,int b)
{
	if (a>=b)
	return b;
	else 
	return a;
	
}

int max(int a,int b)
{
	if(a>=b)
	return a;
	else
	return b;
}

int GCD_BY_FILTER(int a,int b,int& c)
{
	
	
	for (int i=2 ; i<=min(a,b); i++)
	{
		c = c +1;
		if ((a%i==0)&&(b%i==0))
		{
			return i*GCD_BY_FILTER(a/i,b/i,c);
		}
		
	}

	return 1;	
	
}


int GCD_BY_FILTER_FASTER_INTERNAL(int a,int b,int s,int& c)
{
	for(int i = s;i<=min(a,b);i++)
	{
		c=c+1;
		if ((a%i==0)&&(b%i==0))
		{
			return i*GCD_BY_FILTER_FASTER_INTERNAL(a/i,b/i,i,c);
		}
	
	}

	return 1;
}

int GCD_BY_FILTER_FASTER(int a,int b,int&c )
{
	return GCD_BY_FILTER_FASTER_INTERNAL(a,b,2,c);	
}

int GCD_BY_BINARY(int a,int b, int& c)
{
	int n = min(a,b);
	int m = max(a,b);
	int ans = 1;
	while(n!=0 && m!=0)
	{
		c = c+1;
		if (n%2==0 && m%2==0)
		{
			ans = ans*2;
			n = n/2;
			m = m/2;
		}
		else if (n%2==0 && m%2!=0)
		{
			n = n/2;
		}
		else if (n%2!=0 && m%2==0)
		{
			m = m/2;
		}
		if (n>m)
		{
			swap(n,m);
		}
		m = m-n;
		
	}
	return n*ans;
}

int GCD_BY_EUCLID(int a, int b, int& c)
{
	
	int n = min(a,b);
	int m = max(a,b);
	while(m%n != 0)
	{
		c = c + 1;
		int temp = n;
		n = m%n;
		m = temp;
	}
	return n;

}




int main()
{	
	int a;
	int b;
	while(cin>>a)
	{
		if (a == 0){break;}
		
		while(cin>>b)
		{
			int iter = 0;
			int iter1 = 0;
			int iter2 = 0;
			int iter3 = 0;
			int iter4 = 0;
			
		
		
			cout<<"Case ("<<a<<", "<<b<<"): "<<"GCD-By-Reverse-Search = "<<GCD_BY_REVERSE_SEARCH(a,b,iter2);
			cout<<", taking "<<iter2<<" iterations "<<endl;
		
		
			cout<<"Case ("<<a<<", "<<b<<"): "<<"GCD-By-Filter = "<<GCD_BY_FILTER(a,b,iter);
			cout<<", taking "<<iter<<" iterations "<<endl;
	
			cout<<"Case ("<<a<<", "<<b<<"): "<<"GCD-By-Filter-Faster = "<<GCD_BY_FILTER_FASTER(a,b,iter1);
			cout<<", taking "<<iter1<<" iterations "<<endl;
		
		
			cout<<"Case ("<<a<<", "<<b<<"): "<<"GCD-By-Binary = "<<GCD_BY_BINARY(a,b,iter3);
			cout<<", taking "<<iter3<<" iterations "<<endl;
			
			cout<<"Case ("<<a<<", "<<b<<"): "<<"GCD-By-Euclid = "<<GCD_BY_EUCLID(a,b,iter4);
			cout<<", taking "<<iter4<<" iterations "<<endl;
		
			break;
		}
	}
	
}
