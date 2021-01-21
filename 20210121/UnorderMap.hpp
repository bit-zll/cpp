#pragma once

#include "HashBucket.hpp"

namespace bite
{
	// �ײ����ݽṹ�ǹ�ϣͰ
	template<class K, class V>
	class unordered_map
	{
		typedef pair<K, V> ValueType;
		struct KOFV
		{
			const K& operator()(const ValueType& data)
			{
				return data.first;
			}
		};

		typedef HashBucket<ValueType, KOFV>  HTB;

	public:
		// typename���ã����߱�������iterator��HTB�е��ڲ����ͣ����Ǿ�̬��Ա����
		typename typedef HTB::iterator iterator;

	public:
		unordered_map()
			: _ht()
		{}

		//////////////////////////////////////////////////
		// iterator
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		/////////////////////////////////////////////////
		// capacity
		bool empty()const
		{
			return _ht.Empty();
		}

		size_t size()const
		{
			return _ht.size();
		}

		//////////////////////////////////////////////////
		// acess
		V& operator[](const K& key)
		{
			return (*(_ht.InsertUnique(make_pair(key, V()))).first).second;
		}


		//////////////////////////////////////////////////
		// find
		iterator find(const K& key)
		{
			return _ht.Find(make_pair(key, V()));
		}

		//////////////////////////////////////////////////////
		// modify
		pair<iterator, bool> insert(const ValueType& data)
		{
			return _ht.InsertUnique(data);
		}

		size_t erase(const K& key)
		{
			return _ht.EraseUnique(make_pair(key, V()));
		}

		void clear()
		{
			_ht.clear();
		}

		void swap(unordered_map<K, V>& m)
		{
			_ht.Swap(m._ht);
		}

		/////////////////////////////////////////////////////
		// Ͱ���������Ĳ���
		size_t bucket_count()const
		{
			return _ht.BucketCount();
		}

		size_t bucket_size(size_t n)const
		{
			return _ht.BucketSize(n);
		}

		size_t bucket(const K& key)
		{
			return _ht.Bucket(make_pair(key, V()));
		}
	private:
		HTB _ht;
	};
}


#include <iostream>
using namespace std;

#include <string>


void TestUnorderMap()
{
	bite::unordered_map<string, string> m;
	m.insert(make_pair("apple", "ƻ��"));
	m.insert(pair<string, string>("orange", "����"));
	m.insert(make_pair("peach", "����"));

	cout << m.size() << endl;

	cout << m["peach"] << endl;
	cout << m["banana"] << endl;

	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "--->" << it->second << endl;
		++it;
	}

	m.erase("banana");

	for (auto e : m)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	cout << endl;
}

#include <unordered_map>
void Testunordered_map()
{
	unordered_map<string, string> m;
	m.insert(make_pair("apple", "ƻ��"));
	m.insert(pair<string, string>("orange", "����"));
	m.insert(make_pair("peach", "����"));

	cout << m.size() << endl;

	cout << m["peach"] << endl;
	cout << m["banana"] << endl;

	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "--->" << it->second << endl;
		++it;
	}

	m.erase("banana");

	for (auto e : m)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	cout << endl;
}