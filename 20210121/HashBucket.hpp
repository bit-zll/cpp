#pragma once

#include <vector>

#include "Common.h"

template<class T>
struct HashNode
{
	// T()---> Ĭ��ֵ��
	// ���T���������ͣ����磺T��int   int()  Ĭ��ֵ����0
	// ���T���Զ������ͣ����磺T��Date  Date() : ����Ĭ�ϵĹ��캯������һ�������Ķ���
	//                       Date����Ҫ�ṩһ���޲εĹ��캯��������ʹ��Date��ʵ����HashNode��ģ��ʱ��
	//                       ������ʧ��
	HashNode(const T& x = T())
		:next(nullptr)
		, data(x)
	{}

	HashNode<T>* next;
	T data;
};


// T �����int����ϵ��
template<class T>
class DToIntDef
{
public:
	const T& operator()(const T& data)const
	{
		return data;
	}
};

// ��ô���ַ���ת��Ϊ�������͵����ݣ�
// 1. atoi������---ȱ�ݣ�ֻ��ת�������͵��ַ���  ��1234"--->1234   ��hello������ת
// 2. ���ַ�����ÿ���ַ���ASCII�����---���ԣ�"1234"����"hello"������ת---"abcd"  "adcb"  "abdc"...
// 3. ֮ǰͬѧ��"1234"--->string---> ����Ӧ���ַ�����string�б����ʱ��ײ�ռ���׵�ַ  (int)c_str()--->������
//         �Ѿ��ڹ�ϣ���б��棺"hello"   ����Ҫ��"hello"

// 4. ����ַ�����ֻ����Сд��ĸ�����Խ���ЩСд��ĸ������26���Ƶ�����---->ת��Ϊ��10����   ȱ�ݣ��������
// 5. �Ҷ���--
class StrToInt
{
public:
	size_t operator()(const string& data)const
	{
		return BKDRHash(data.c_str());
	}

	size_t BKDRHash(const char *str)const
	{
		size_t seed = 131; // 31 131 1313 13131 131313 etc..
		size_t hash = 0;

		while (*str)
		{
			hash = hash * seed + (*str++);
		}

		return (hash & 0x7FFFFFFF);
	}
};


// ǰ������
template<class T, class KOFV, class DToInt = StrToInt>//DToIntDef<T>>
class HashBucket;


template<class T, class KOFV, class DToInt>
struct HashBucketItertor
{
	typedef HashNode<T> Node;
	typedef HashBucketItertor<T, KOFV, DToInt> Self;

	HashBucketItertor(Node* pNode = nullptr, HashBucket<T, KOFV, DToInt>* ht = nullptr)
		: _pNode(pNode)
		, _ht(ht)
	{}

	// ����ָ�����ƵĲ���
	T& operator*()
	{
		return _pNode->data;
	}

	T* operator->()
	{
		return &(operator*());
	}

	// �������ܹ��ƶ�
	Self& operator++()
	{
		Next();
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		Next();
		return temp;
	}

	// ע�⣺��ϣͰ�ĵ�����û��--��������Ϊ��ײ�ʹ�õ��ǵ�����
	bool operator!=(const Self& s)
	{
		return !(*this == s);
	}

	bool operator==(const Self& s)
	{
		return _pNode == s._pNode && _ht == s._ht;
	}

	// �ҵ�ǰ����������һ��λ��
	void Next()
	{
		// 1. pNode֮���нڵ�
		if (_pNode->next)
		{
			_pNode = _pNode->next;
		}
		else
		{
			// 2. pNode�ǵ�ǰͰ�е����һ���ڵ�---��Ҫ����һ���ǿ�Ͱ
			// a. ��Ҫ֪����ǰ���������ڵ�Ͱ��--��ϣ���� b. ��Ҫ�õ����е�Ͱ   table
			size_t bucketCount = _ht->BucketCount();
			size_t bucketNo = _ht->HashFunc(_pNode->data, bucketCount) + 1;
			for (; bucketNo < bucketCount; ++bucketNo)
			{
				if (_ht->table[bucketNo])
				{
					_pNode = _ht->table[bucketNo];
					return;
				}
			}

			_pNode = nullptr;
		}
	}

	Node* _pNode;
	HashBucket<T, KOFV, DToInt>* _ht;
};

// ��ϣͰ---->
// T���洢Ԫ�ص�����
// DToInt: ��Tת��Ϊ��������--->��ϣ�������񣺳���������
template<class T, class KOFV, class DToInt>
class HashBucket
{
	friend HashBucketItertor<T, KOFV, DToInt>;

	typedef HashNode<T> Node;

public:
	typedef HashBucketItertor<T, KOFV, DToInt> iterator;

public:
	HashBucket(size_t capacity = 10)
		: table(10/*GetNextPrime(capacity)*/)
		, _size(0)
	{}

	~HashBucket()
	{
		clear();
	}

	iterator begin()
	{
		// �ҷǿ�Ͱ
		for (size_t bucket = 0; bucket < table.capacity(); ++bucket)
		{
			if (table[bucket])
			{
				return iterator(table[bucket], this);
			}
		}

		return end();
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	// ���ϣͰ�в���Ԫ��---��֤Ԫ����Ψһ��
	pair<iterator, bool> InsertUnique(const T& data)
	{
		_CheckCapacity();
		// 1. ͨ����ϣ��������Ͱ��
		size_t bucketNo = HashFunc(data, table.capacity());

		// 2. ���data�Ƿ���bucketNoͰ�д���
		Node* cur = table[bucketNo];
		while (cur)
		{
			if (KOFV()(data) == KOFV()(cur->data))
			{
				return make_pair(iterator(cur, this), false);
			}

			cur = cur->next;
		}

		// 3. ����Ԫ��---ͷ�巨
		cur = new Node(data);
		cur->next = table[bucketNo];
		table[bucketNo] = cur;
		_size++;

		return make_pair(iterator(cur, this), true);
	}

	// ���ϣͰ�в���Ԫ��---Ԫ�ؿ����ظ�---�Լ�����
	bool InsertEqual(const T& data)
	{
		// 1. ͨ����ϣ��������Ͱ��
		size_t bucketNo = HashFunc(data, table.capacity());

		// 2. ����Ԫ��
		Node* cur = new Node(data);
		cur->next = table[bucketNo];
		table[bucketNo] = cur;
		_size++;
		return true;
	}

	// Ԫ����Ψһ���ҵ�һ��ɾ������
	size_t EraseUnique(const T& data)
	{
		// 1. ͨ����ϣ��������Ԫ�����ڵ�Ͱ��
		size_t bucketNo = HashFunc(data, table.capacity());

		// 2. �ڸ�Ͱ����ֵΪdata�Ľڵ㲢����ɾ����
		Node* cur = table[bucketNo];
		Node* prev = nullptr;
		while (cur)
		{
			if (KOFV()(cur->data) == KOFV()(data))
			{
				// ɾ���ýڵ�
				// ע�⣺�ýڵ�����������еĵ�һ���ڵ� Ҳ�����Ƿǵ�һ���ڵ�
				if (nullptr == prev)
				{
					table[bucketNo] = cur->next;
				}
				else
				{
					prev->next = cur->next;
				}
				delete cur;
				_size--;
				return 1;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}

		return 0;
	}

	// ����ϣͰ��ֵΪdata�����нڵ�ȫ��ɾ����
	size_t EraseEquel(const T& data)
	{
		return 0;
	}

	iterator Find(const T& data)
	{
		// 1. ͨ����ϣ���������Ӧ��Ͱ��
		size_t bucketNo = HashFunc(data, table.capacity());

		// 2. ��bucketNo��Ӧ����������ֵΪdata�Ľڵ�
		Node* cur = table[bucketNo];
		while (cur)
		{
			if (KOFV()(data) == KOFV(cur->data))
				return iterator(cur, this);

			cur = cur->next;
		}

		return end();
	}

	size_t size()const
	{
		return _size;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	// ����Ͱ�ı�Ŵ�С����������������д�ӡ
	void PrintHashBucket()
	{
		for (size_t i = 0; i < table.capacity(); ++i)
		{
			cout << "[" << i << "]:";

			// ��ӡ��Ͱ�е����нڵ�
			Node* cur = table[i];
			while (cur)
			{
				cout << cur->data << "--->";
				cur = cur->next;
			}

			cout << "NULL" << endl;
		}

		cout << "================================================" << endl;
	}

	void Swap(HashBucket<T, KOFV, DToInt>& ht)
	{
		table.swap(ht.table);
		std::swap(_size, ht._size);
	}

	void clear()
	{
		// ������Ͱ�еĽڵ�ȫ��ɾ����
		for (size_t i = 0; i < table.capacity(); ++i)
		{
			// ����ͷɾ����ɾ�������е����нڵ�
			Node* cur = table[i];
			while (cur)
			{
				table[i] = cur->next;
				delete cur;
				cur = table[i];
			}
		}

		_size = 0;
	}

	/////////////////////////////////////////////////
	// Ͱ��صĲ���
	// ��ȡͰ���ܸ���
	size_t BucketCount()const
	{
		return table.capacity();
	}

	// ��ȡbucketNoͰ�нڵ�ĸ���
	size_t BucketSize(size_t bucketNo)const
	{
		if (bucketNo >= BucketCount())
			return 0;

		Node* cur = table[bucketNo];
		size_t count = 0;
		while (cur)
		{
			count++;
			cur = cur->next;
		}

		return count;
	}

	// ����data���ڵ�Ͱ��
	size_t Bucket(const T& data)
	{
		return HashFunc(data, BucketCount());
	}

private:
	// ����������
	size_t HashFunc(const T& data, size_t capacity)
	{
		//DToInt dtoi;
		//return dtoi(data) % capacity;
		return DToInt()(KOFV()(data)) % capacity;
	}

	void _CheckCapacity()
	{
		if (_size == table.capacity())
		{
			vector<Node*> bucket(GetNextPrime(table.capacity()));

			// ����Ͱ��ÿ�������еĽڵ�����ƶ�����Ͱ��
			for (size_t i = 0; i < table.capacity(); ++i)
			{
				Node* cur = table[i];
				while (cur)
				{
					// 1. ��Ҫ���ýڵ�Ӿ������в�����---ͷɾ��
					table[i] = cur->next;


					// 2. ��cur���뵽��Ͱ��
					// a. ����ýڵ����¹�ϣͰ���Ǹ�Ͱ��
					//HashFunc(cur->data);  �ɹ�ϣͰ��Ӧ�Ĺ�ϣ����
					size_t bucketNo = HashFunc(cur->data, bucket.capacity());

					// b. ���ýڵ���뵽��Ͱ��---ͷ��
					cur->next = bucket[bucketNo];
					bucket[bucketNo] = cur;

					// 3. ȡ��Ͱ�е���һ���ڵ�
					cur = table[i];
				}
			}

			// �ɹ�ϣͰ�е�Ԫ���Ѿ�ȫ���ƶ�����Ͱ�е�
			table.swap(bucket);
		}
#if 0
		if (_size == table.capacity())
		{
			HashBucket<T> newHt(table.capacity() * 2);

			// ���ɹ�ϣͰ�е�Ԫ������Ĳ��뵽�¹�ϣͰ��
			for (size_t i = 0; i < table.capacity(); ++i)
			{
				// ��һ��Ͱ�е�Ԫ�ز��뵽�¹�ϣͰ��
				Node* cur = table[i];
				while (cur)
				{
					newHt.InsertUnique(cur->data);
					cur = cur->next;
				}
			}

			this->Swap(newHt);
		}
#endif
	}
private:
	std::vector<Node*> table;
	size_t _size;   // ��ʾ��ϣͰ����ЧԪ�صĸ���
};

#include <iostream>
using namespace std;

class KOFV
{
public:
	int operator()(int data)const
	{
		return data;
	}
};

void TestHashBucket1()
{
	HashBucket<int, KOFV, DToIntDef<int>> ht;

	int array[] = { 1, 4, 5, 6, 7, 9, 3, 2, 8, 0 };

	for (auto e : array)
	{
		ht.InsertUnique(e);
	}



	cout << ht.size() << endl;
	ht.PrintHashBucket();


	ht.InsertUnique(44);
	ht.PrintHashBucket();

	auto it = ht.begin();
	while (it != ht.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
