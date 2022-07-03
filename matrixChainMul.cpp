#include<bits/stdc++.h>
using namespace std;
#define inf 9999
int matrix(int a[], int n)
{
	int p[n][n];
	int i, j, k, l, q;
	for (i = 1; i < n; i++)
		p[i][i] = 0;
	for (l = 2; l < n; l++)
	{
		for (i = 1; i < n - l + 1; i++)
		{
			j = i + l - 1;
			p[i][j] = inf;
			for (k = i; k <= j - 1; k++)
			{
			       q = p[i][k] + p[k + 1][j]
					+ a[i - 1] * a[k] * a[j];
				if (q < p[i][j])
					p[i][j] = q;
			}
		}
	}
	return p[1][n - 1];
}

int main()
{
  int n;
  cout<<"Enter the size of the array\n";
  cin>>n;
  int a[n];
  cout<<"Enter the array\n";
  for(int i=0;i<n;i++){
  cin>>a[i];
}
  cout<<"The Minimum number of matrix multiplications is: "<<matrixc(a, n);
	return 0;
}
