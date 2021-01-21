#pragma once

#include "HashBucket.hpp"

namespace bite
{
	// �ײ����ݽṹ�ǹ�ϣͰ
	template<class K>
	class unordered_set
	{
		typedef K ValueType;
		struct KOFV
		{
			const K& operator()(const ValueType& data)
			{
				return data;
			}
		};

		typedef HashBucket<ValueType, KOFV>  HTB;

	public:
		// typename���ã����߱�������iterator��HTB�е��ڲ����ͣ����Ǿ�̬��Ա����
		typename typedef HTB::iterator iterator;

	public:
		unordered_set()
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
		// find
		iterator find(const K& key)
		{
			return _ht.Find(key);
		}

		//////////////////////////////////////////////////////
		// modify
		pair<iterator, bool> insert(const ValueType& data)
		{
			return _ht.InsertUnique(data);
		}

		size_t erase(const K& key)
		{
			return _ht.EraseUnique(key);
		}

		void clear()
		{
			_ht.clear();
		}

		void swap(unordered_set<K>& m)
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
			return _ht.Bucket(key);
		}
	private:
		HTB _ht;
	};
}