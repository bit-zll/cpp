#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#if 0
#include <map>
#include <string>

int main()
{
	map<string, string> m1;

	m1.insert(pair<string, string>("orange", "����"));
	m1.insert(pair<string, string>("apple", "ƻ��"));
	m1.insert(pair<string, string>("banana", "�㽶"));
	m1.insert(make_pair("peach", "����"));
	m1.insert(make_pair("watermelon", "����"));

	//��������Χfor
	for (auto& e : m1)
	{
		cout << "<" << e.first << "," << e.second << ">" << endl;
	}

	cout << "---------------------------------------" << endl;

	//ͨ��key��ȡ��key��Ӧ��value
	cout << m1["peach"] << endl;
	cout << m1["pear"] << endl;

	m1["pear"] = "��";
	cout << m1["pear"] << endl;

	auto ret = m1.insert(make_pair("orange", "����"));

	cout << m1.size() << endl;
	auto it = m1.begin();
	while (it != m1.end())
	{
		cout << "<" << it->first << "," << (*it).second << ">" << endl;
		++it;
	}

	//C++11
	map<string, string> m2{ { "orange", "����" }, { "apple", "ƻ��" }, { "banana", "�㽶" } };
	auto rit = m2.rbegin();
	while (rit != m2.rend())
	{
		cout << "<" << rit->first << "," << (*rit).second << ">" << endl;
		++rit;
	}

	m1.erase("orange");//ɾ��ָ����key;

	auto pos = m1.find("orange");
	if (pos != m1.end())
	{
		m1.erase(pos);
	}

	m1.erase(m1.begin(), m1.end());
	return 0;
}
#endif

#if 0
#include <map>
#include <string>
#include <queue>
#include <set>

class Compare
{
public:
	bool operator()(const pair<string, size_t>& left, const pair<string, size_t>& right)
	{
		return left.second < right.second;
	}
};

int main()
{
	// ������ˮ��������Ա����ϲ���Ե�����ˮ��---CVTE������
	string fruits[] = { "apple", "apple", "apple", "apple", "apple", "orange", "orange", "banana", "apple", "orange", "banana", "peach", "banana", "watermelon", "banana", "banana" };

	// 1. ͳ��ÿ��ˮ�����ֵĴ���
	// <ˮ��������>
	map<string, size_t> m;
	for (auto& e : fruits)
		m[e]++;// <e, 0>��map�в���--->���e�����ڷ���0  ���e���ڷ���ֵe��Ӧ�Ĵ���

	// 2. �ҳ�Ա����ϲ���Ե�K��ˮ��----TOP-K---priority_queue
	// ʹ��map�е�Ԫ�ع���һ�����---->���ռ�ֵ���еĴ������бȽ�
	priority_queue<pair<string, size_t>, vector<pair<string, size_t>>, Compare> q(m.begin(), m.end());


	// ȡ��Ա����ϲ���Ե�����ˮ��
	vector<string> favourite;
	for (size_t i = 0; i < 3; ++i)
	{
		favourite.push_back(q.top().first);
		q.pop();
	}

	// ˮ��--->�����ֵ䷽ʽ����
	sort(favourite.begin(), favourite.end());
	return 0;
}


	set<string> s;
	for (size_t i = 0; i < 3; ++i)
	{
		s.insert(q.top().first);
		q.pop();
	}
	return 0;
}
#endif

#if 0
#include <set>
#include <string>

//ȥ��+����
int main()
{
	string fruits[] = { "apple", "apple", "apple", "apple", "apple", "orange", "orange", "banana", "apple", "orange", "banana", "peach", "banana", "watermelon", "banana", "banana" };
	set<string> s(fruits, fruits + sizeof(fruits) / sizeof(fruits[0]));

	s.insert("grape");

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
#endif

#if 0
#include <map>

int main()
{
	multimap<string, string> m;
	m.insert(pair<string, string>("orange", "����"));
	m.insert(pair<string, string>("apple", "ƻ��"));
	m.insert(pair<string, string>("banana", "�㽶"));
	m.insert(make_pair("peach", "����"));
	m.insert(make_pair("watermelon", "����"));
	m.insert(make_pair("orange", "����"));

	m.erase("orange");
	return 0;
}
#endif

#include <set>
#include <string>
#include <functional>

int main()
{
	string fruits[] = { "apple", "apple", "apple", "apple", "apple", "orange", "orange", "banana", "apple", "orange", "banana", "peach", "banana", "watermelon", "banana", "banana" };
	multiset<string, greater<string>> s;

	for (auto& e : fruits)
		cout << e << " ";
	cout << endl;

	s.insert(fruits, fruits + sizeof(fruits) / sizeof(fruits[0]));

	cout << s.count("apple") << endl;

	for (auto& e : s)
		cout << e << " ";
	cout << endl;

	return 0;
}