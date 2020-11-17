#pragma once

#include <deque>

namespace bite
{
	template<class T,class Con=std::deque<T>>
	class stack
	{
	public:
		stack()
		{}

		void push(const T& data)
		{
			_con.push_back(data);
		}

		void pop()
		{
			if (empty()) return;
			_con.pop_back();
		}

		size_t size()const
		{
			return _con.size();
		}

		bool empty()const
		{
			return _con.empty();
		}

		T& top()
		{
			return _con.back();
		}

		const T& top()const
		{
			return _con, back();
		}

	private:
		Con _con;
	};
}