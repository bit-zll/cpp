#define _CRT_SECURE_NO_WARNINGS

//�����е�K�����Ԫ��

//class Solution
//{
//public:
//	int findKthLargest(vector<int>& nums, int k)
//	{
//		//�������е�Ԫ���ȷ������ȼ�������
//		priority_queue<int> p(nums.begin(), num.end());
//
//		//�����ȼ�������ǰk-1��Ԫ��ɾ����
//		for (int i = 0; i < k - 1; ++i)
//		{
//			p.pop();
//		}
//
//		return p.top();
//	}
//};

//�ö���ʵ��ջ
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
//			//��q1��ǰn-1��Ԫ�ص��뵽q2��
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
//			//��q2��ǰn-1��Ԫ�ص��뵽q1��
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



//��ջʵ�ֶ���
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

//�沨�����ʽ��ֵ
class Solution
{
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> s;
		for (size_t i = 0; i < tokens.size(); ++i)
		{
			string& str = tokens[i];

			//strΪ����
			if (!("+" == str || "-" == str || "*" == str || "/" == str))
			{
				s.push(atoi(str.c_str()));
			}
			else
			{
				//strΪ������
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

//ջ�ĵ���ѹ������
//class Solution
//{
//public:
//	bool IsPopOrder(vetor<int> pushV, vector<int> popV)
//	{
//		//��ջ�ͳ�ջ��Ԫ�ظ���������ͬ
//		if (pushV.size() != popV.size())
//			return false;
//
//		//��s��ģ����ջ���ջ�Ĺ���
//		int outIdx = 0;
//		int inIdx = 0;
//		stack<int> s;
//
//		while (outIdx < popV.size())
//		{
//			//���s�ǿգ�����ջ��Ԫ�����ջ��Ԫ�ز���ȣ�����ջ
//			while (s.empty() || s.top() != popV[outIdx])
//			{
//				if (inIdx < pushV.size())
//					s.push(pushV[inIdx++]);
//				else
//					return false;
//			}
//
//			//ջ��Ԫ�����ջ��Ԫ����ȣ���ջ
//			s.pop();
//			outIdx++;
//		}
//		return true;
//	}
//};

//��Сջ
class MinStack
{
public:
	void push(int x)
	{
		//ֻҪ��ѹջ���Ƚ�Ԫ�ر��浽_elem��
		_elem.push(x);

		//���xС��_min��ջ����Ԫ�أ���x��ѹ��_min��
		if (_min.empty() || x <= _min.top())
			_min.push(x);
	}

	void pop()
	{
		//���_minջ����Ԫ�صĵ��ڳ�ջ��Ԫ�أ�_min����Ԫ��Ҫ�Ƴ�
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
	//����ջ�е�Ԫ��
	std::stack<int> _elem;

	//����ջ����Сֵ
	std::stack<int> _min;
};