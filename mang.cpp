#include <iostream>

using namespace std;

int max(int a[], int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max) max = a[i];
	};
	return max;
};

int min(int a[], int n)
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min) min = a[i];
	};
	return min;
};

int sapxep(int a[], int l, int r)
{
	int i, j, x, tg;
	x = a[(l + r) / 2];
	i = l;
	j = r;
	while (i <= j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			tg = a[i];
			a[i] = a[j];
			a[j] = tg;
			i++; j--;
		};
	};
	if (i < r) sapxep(a, i, r);
	if (l < j) sapxep(a, l, j);
	return 0;
};

int tongchan(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
		if ((a[i] % 2) == 0) tong += a[i];
	return tong;
};

int tongle(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
		if ((a[i] % 2) != 0) tong += a[i];
	return tong;
};

int main()
{
	int a[1000], n, tong = 0;
	cout << "Nhap so phan tu cua mang :";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << " : ";
		cin >> a[i];
		tong += a[i];
	};
	sapxep(a, 0, n - 1);
	cout << "Tong cua day la : " << tong << endl;
	cout << "Tong chan cua day la : " << tongchan(a,n) << endl;
	cout << "Tong le cua day la : " << tongle(a,n) << endl;
	cout << "Gia tri lon nhat cua day la : " << max(a, n) << endl;
	cout << "Gia tri lon nhat cua day la : " << min(a, n) << endl;
	cout << "Mang da sap xep : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << " " << a[i];
	};

}