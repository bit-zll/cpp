#define _CRT_SECURE_NO_WARNINGS

//数组中第K个大的元素

//class Solution
//{
//public:
//	int findKthLargest(vector<int>& nums, int k)
//	{
//		//将数组中的元素先放入优先级队列中
//		priority_queue<int> p(nums.begin(), num.end());
//
//		//将优先级队列中前k-1个元素删除掉
//		for (int i = 0; i < k - 1; ++i)
//		{
//			p.pop();
//		}
//
//		return p.top();
//	}
//};

//用队列实现栈
//class MyStack
//{
//	MyStack()
//	{}
//
//	void push(int x)
//	{
//		if (!q1.empty())
//			q1.push(x);
//		else
//			q2.push(x);
//	}
//
//	int pop()
//	{
//		int ret;
//		if (!q1.empty())
//		{
//			//将q1中前n-1个元素导入到q2中
//			while (q1.size() > 1)
//			{
//				q2.push(q1.front());
//				q1.pop();
//			}
//			ret = q1.front();
//			q1.pop();
//		}
//		else
//		{
//			//将q2中前n-1个元素导入到q1中
//			while (q2.size() > 1)
//			{
//				q1.push(q2.front());
//				q2.pop();
//			}
//			ret = q2.front();
//			q2.pop();
//		}
//		return ret;
//	}
//
//	int top()
//	{
//		if (!q1.empty())
//			return q1.back();
//		else
//			return q2.back();
//	}
//
//	bool empty()
//	{
//		return q1.empty() && q2.empty();
//	}
//
//private:
//	queue<int> q1;
//	queue<int> q2;
//};



//用栈实现队列
//class MyQueue
//{
//public:
//	MyQueue()
//	{}
//
//	void push(int x)
//	{
//		s1.push(x);
//	}
//
//	int pop()
//	{
//		if (s2.empty())
//		{
//			while (!s1.empty())
//			{
//				s2.push(s1.top());
//				s1.pop();
//			}
//		}
//		int ret = s2.top();
//		s2.pop();
//		return ret;
//	}
//
//	int peek()
//	{
//		if (s2.empty())
//		{
//			while (!s1.empty())
//			{
//				s2.push(s1.top());
//				s1.pop();
//			}
//		}
//
//		return s2.top();
//	}
//
//	bool empty()
//	{
//		return s1.empty() && s2.empty();
//	}
//
//private:
//	stack<int> s1;
//	stack<int> s2;
//};

//逆波兰表达式求值
class Solution
{
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> s;
		for (size_t i = 0; i < tokens.size(); ++i)
		{
			string& str = tokens[i];

			//str为数字
			if (!("+" == str || "-" == str || "*" == str || "/" == str))
			{
				s.push(atoi(str.c_str()));
			}
			else
			{
				//str为操作符
				int right = s.top();
				s.pop();

				int left = s.top();
				s.pop();

				switch (str[0])
				{
				case '+':
					s.push(left + right);
					break;
				case '-':
					s.push(left - right);
					break;
				case '*':
					s.psuh(left*right);
					break;
				case '/':
					s.push(left / right);
					break;
				}
			}
		}
		return s.top();
	}
};

//栈的弹出压入序列
//class Solution
//{
//public:
//	bool IsPopOrder(vetor<int> pushV, vector<int> popV)
//	{
//		//入栈和出栈的元素个数必须相同
//		if (pushV.size() != popV.size())
//			return false;
//
//		//用s来模拟入栈与出栈的过程
//		int outIdx = 0;
//		int inIdx = 0;
//		stack<int> s;
//
//		while (outIdx < popV.size())
//		{
//			//如果s是空，或者栈顶元素与出栈的元素不相等，就入栈
//			while (s.empty() || s.top() != popV[outIdx])
//			{
//				if (inIdx < pushV.size())
//					s.push(pushV[inIdx++]);
//				else
//					return false;
//			}
//
//			//栈顶元素与出栈是元素相等，出栈
//			s.pop();
//			outIdx++;
//		}
//		return true;
//	}
//};

//最小栈
class MinStack
{
public:
	void push(int x)
	{
		//只要是压栈，先将元素保存到_elem中
		_elem.push(x);

		//如果x小于_min中栈顶的元素，将x再压入_min中
		if (_min.empty() || x <= _min.top())
			_min.push(x);
	}

	void pop()
	{
		//如果_min栈顶的元素的等于出栈的元素，_min顶的元素要移除
		if (_min.top() == _elem.top())
			_min.pop();

		_elem.pop();
	}

	int top()
	{
		return _elem.top();
	}

	int getMin()
	{
		return _min.top();
	}

private:
	//保存栈中的元素
	std::stack<int> _elem;

	//保存栈中最小值
	std::stack<int> _min;
};