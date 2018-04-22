#include <iostream>
#include <vector>
using namespace std;

typedef struct Item
{
	int start;
	int end;
	int cnt;
}Item;

bool isValid(int x)
{
	if(x % 9 == 0)
		return false;
	while(x > 0)
	{
		if(x % 10 == 9)
			return false;
		x /= 10;
	}
	return true;
}

int Count(int F, int L)
{
	if(L < F)
		return 0;
	if(F <= 0 || L <= 0)
		return 0;
	int cnt = 0;
	for(int i=F; i <= L; i++)
	{
		if(isValid(i))
			cnt++;
	}
	return cnt;
}

void InsertVector(vector<Item> &temp, vector<Item> &v)
{
	vector<Item>::iterator it = v.begin();
	size_t i=0;
	while(it != v.end() && i < temp.size())
	{
		if((*it).start > temp[i].start)
		{
			v.insert(it, temp[i]);
			i++;
		}
		++it;
	}
	while(i < temp.size())
	{
		v.push_back(temp[i]);
		i++;
	}
}

int CheckVector(int F, int L, vector<Item> &v)
{
	
	vector<Item> temp;
	int cnt = 0;
	for(size_t i=0; i < v.size(); i++)
	{
		if(F > L)
			break;
		if(v[i].start > L)
			break;
		if(v[i].start >= F && v[i].end <= L)
		{
			int k = Count(F, v[i].start-1);
			Item item;
			item.start = F;
			item.end = v[i].start-1;
			item.cnt = k;
			temp.push_back(item);
			cnt += k + v[i].cnt;
			F = v[i].end + 1;
		}
	}
	
	int k = Count(F, L);
	cnt += k;
	/*Item it;
	it.start = F;
	it.end = L;
	it.cnt = k;
	temp.push_back(it);*/
	InsertVector(temp, v);
	/*Item item;
			item.start = F;
			item.end = L;
			item.cnt = k;
	cnt += k;
	temp.push_back(item);*/
	
	return cnt;
}

int main()
{
	int T;
	cin >> T;
	vector<Item> v;
	for(int i=0; i < T; i++)
	{
		int F, L;
		cin >> F >> L;
		int k = CheckVector(F, L, v);
		cout << "Case #" << (i+1) << ": " << k << endl;

	}
	return 0;
}