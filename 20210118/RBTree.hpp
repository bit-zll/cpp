#pragma once


#include <iostream>
using namespace std;



enum Color{ RED, BLACK };


template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& x = T(), Color c = RED)
		: left(nullptr)
		, right(nullptr)
		, parent(nullptr)
		, data(x)
		, color(c)
	{}

	RBTreeNode<T>* left;
	RBTreeNode<T>* right;
	RBTreeNode<T>* parent;
	T data;
	Color color;
};

#if 0
template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		head = new Node();
		head->left = head;
		head->right = head;
	}

	~RBTree()
	{
		_Destroy(head->parent);
	}

	bool Insert(const T& data)
	{
		// �����Ҳ�Ƕ���������
		// 1. ���ն����������Ĺ�������½ڵ�
		Node*& root = GetRoot();
		if (nullptr == root)
		{
			root = new Node(data, BLACK);
			head->left = root;
			head->right = root;
			root->parent = head;
			return true;
		}

		// �Ҵ�����ڵ��ڶ�������������λ�ã����ұ�����˫��
		Node* cur = root;
		Node* parent = head;
		while (cur)
		{
			parent = cur;
			if (data < cur->data)
				cur = cur->left;
			else if (data > cur->data)
				cur = cur->right;
			else
				return false;
		}

		// �����½ڵ�
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;
		cur->parent = parent;


		// �½ڵ����ɹ��󣬺����������3���ܻ��⵽�ƻ�
		// ��Ϊcur�½ڵ��Ĭ����ɫ�Ǻ�ɫ��
		// ���parent�ڵ����ɫ�Ǻ�ɫ�ģ�û��Υ���κ�����
		// ���parent�ڵ����ɫ�Ǻ�ɫ�ģ�Υ����������,������е���
		while (parent != head && RED == parent->color)
		{
			// parent != head : ����������ȷ��parentһ����������Ч�Ľڵ�
			// parent->color == RED: ���������Ա�֤parentһ�����Ǹ��ڵ�
			Node* grandFather = parent->parent;
			if (parent == grandFather->left)
			{
				// �μ��и������һ����
				Node* uncle = grandFather->right;
				if (uncle && uncle->color == RED)
				{
					// ���һ
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;

					// ���ԭ��grandFather��˫�ף���Ҫ�������ϸ���
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					// ������������
					if (cur == parent->right)
					{
						// �����
						RotateLeft(parent);
						swap(parent, cur);
					}

					// �����
					parent->color = BLACK;
					grandFather->color = RED;
					RotateRight(grandFather);
				}
			}
			else
			{
				// �μ��и������һ�����ķ����
				Node* uncle = grandFather->left;
				if (uncle && RED == uncle->color)
				{
					// ���һ�����
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;

					// ��Ҫ�������ϸ���
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					// �������������ķ����
					if (cur == parent->left)
					{
						//������ķ����
						RotateRight(parent);
						swap(parent, cur);
					}

					// ������ķ����
					parent->color = BLACK;
					grandFather->color = RED;
					RotateLeft(grandFather);
				}
			}
		}

		root->color = BLACK;
		head->left = LeftMost();
		head->right = RightMost();
		return true;
	}

	void InOrder()
	{
		_InOrder(head->parent);
		cout << endl;
	}

	bool IsValidRBTree()
	{
		Node* root = GetRoot();
		// 1. ����
		if (nullptr == root)
			return true;

		// 2. �ǿ�----���պ���������������м��
		if (BLACK != root->color)
		{
			cout << "Υ����������ʶ������ڵ㲻�Ǻ�ɫ��!!!" << endl;
			return false;
		}

		// ��֤��������������
		// ������֤�����ģ�ÿ��·���к�ɫ�ڵ������ͬ---�����ҵ�ÿ��·���к�ɫ�ڵ����Ȼ��Ա�
		// �ҵ�һ��·���к�ɫ�ڵ�ĸ���---ͳ�������·���к�ɫ�ڵ����
		size_t blockCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (BLACK == cur->color)
				blockCount++;

			cur = cur->left;
		}

		// �������·���к�ɫ�ڵ�ĸ�ʽ�������·���к�ɫ�ڵ�����Ƿ���ͬ
		size_t pathCount = 0;
		return _IsValidRBTree(root, blockCount, pathCount);
	}

private:
	bool _IsValidRBTree(Node* root, size_t blockCount, size_t pathCount)
	{
		if (nullptr == root)
		{
			return true;
		}

		if (BLACK == root->color)
		{
			pathCount++;
		}

		Node* parent = root->parent;
		if (parent != head && RED == parent->color && RED == root->color)
		{
			cout << "Υ������3��������һ��ĺ�ɫ�ڵ�!!!" << endl;
			return false;
		}

		// ���root������Ҷ�ӽڵ�---˵��һ��·���ߵ���
		if (nullptr == root->left && nullptr == root->right)
		{
			if (pathCount != blockCount)
			{
				cout << "Υ������4��·���к�ɫ�ڵ�ĸ�����һ��!!!" << endl;
				return false;
			}
		}

		return _IsValidRBTree(root->left, blockCount, pathCount) &&
			_IsValidRBTree(root->right, blockCount, pathCount);
	}

	Node* LeftMost()
	{
		Node* cur = GetRoot();
		if (nullptr == cur)
			return head;

		while (cur->left)
			cur = cur->left;

		return cur;
	}

	Node* RightMost()
	{
		Node* cur = GetRoot();
		if (nullptr == cur)
			return head;

		while (cur->right)
			cur = cur->right;

		return cur;
	}

	// ����
	void RotateLeft(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;

		parent->right = subRL;
		if (subRL)
			subRL->parent = parent;

		subR->left = parent;

		Node* pparent = parent->parent;

		// ����subR�Լ�parent��˫��
		parent->parent = subR;
		subR->parent = pparent;

		// ������ת֮ǰparent˫�׵��󺢺���ָ����
		if (pparent == head)
		{
			// ˵����ת֮ǰparent���Ǹ��ڵ㣬��ת���֮���µĸ��ڵ�Ӧ��ΪsubR
			head->parent = subR;
		}
		else
		{
			// ��ת֮ǰparent�ĸ��ڵ��Ǵ��ڵ�
			if (parent == pparent->left)
			{
				pparent->left = subR;
			}
			else
			{
				pparent->right = subR;
			}
		}
	}

	// �ҵ���
	void RotateRight(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;

		parent->left = subLR;
		if (subLR)
			subLR->parent = parent;

		subL->right = parent;

		// ����parent��subL��˫��
		Node* pparent = parent->parent;
		parent->parent = subL;
		subL->parent = pparent;

		// ��Ҫ����pparent��ָ�����
		if (pparent == head)
		{
			head->parent = subL;
		}
		else
		{
			if (parent == pparent->left)
			{
				pparent->left = subL;
			}
			else
			{
				pparent->right = subL;
			}
		}
	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->left);
			cout << root->data << " ";
			_InOrder(root->right);
		}
	}

	void _Destroy(Node*& root)
	{
		if (root)
		{
			_Destroy(root->left);
			_Destroy(root->right);
			delete root;
			root = nullptr;
		}
	}

	Node*& GetRoot()
	{
		return head->parent;
	}

private:
	Node* head;
};
#endif

// ����������ӵ�������
template<class T>
struct RBtreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBtreeIterator<T> Self;

	RBtreeIterator(Node* node = nullptr)
		: pNode(node)
	{}

	// ����ָ�����Ƶķ���
	T& operator*()
	{
		return pNode->data;
	}

	T* operator->()
	{
		// return &(pNode->data);
		return &(operator*());
	}

	// �����ƶ�
	Self& operator++()
	{
		Increament();
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		Increament();
		return temp;
	}

	Self& operator--()
	{
		Decreament();
		return *this;
	}

	Self operator--(int)
	{
		Self temp(*this);
		Decreament();
		return temp;
	}

	// �ܹ����бȽ�
	bool operator==(const Self& s)const
	{
		return pNode == s.pNode;
	}

	bool operator!=(const Self& s)const
	{
		return pNode != s.pNode;
	}

private:
	void Increament()
	{
		// ǰ��++�ͺ���++��Ҫ����--->�ұȵ�ǰ�ڵ��Ľڵ���ֵ����С��
		if (pNode->right)
		{
			// ��pNode�����������������ڵ�(��С�Ľڵ�)
			pNode = pNode->right;
			while (pNode->left)
				pNode = pNode->left;
		}
		else
		{
			// pNodeû����������ֻ����pNode��˫���н��в���
			Node* parent = pNode->parent;
			while (parent->right == pNode)
			{
				pNode = parent;
				parent = pNode->parent;
			}

			// ������������ڵ�û���Һ��ӳ���
			if (pNode->right != parent)
				pNode = parent;
		}
	}

	void Decreament()
	{
		// �ұȵ�ǰ�ڵ�С�����нڵ���ֵ���Ľڵ�
		// �������������ڵ�  Ҳ��������˫������
		if (pNode->parent->parent == pNode && RED == pNode->color)
		{
			// pNode�Ѿ���end��λ��
			pNode = pNode->right;
		}
		else if (pNode->left)
		{
			// ����������
			pNode = pNode->left;
			while (pNode->right)
				pNode = pNode->right;
		}
		else
		{
			// �����������ڣ�ֻ������˫���н��в���
			Node* parent = pNode->parent;
			while (pNode == parent->left)
			{
				pNode = parent;
				parent = pNode->parent;
			}

			pNode = parent;
		}
	}

	Node* pNode;
};

// T ��ʾ������д��Ԫ�ص�����
// KOFV: ��ʾ��ȡԪ����key�ķ�ʽ
template<class T, class KOFV>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBtreeIterator<T> iterator;
public:
	RBTree()
	{
		head = new Node();
		head->left = head;
		head->right = head;
		_size = 0;
	}

	~RBTree()
	{
		_Destroy(head->parent);
	}

	///////////////////////////////////
	// iterator
	iterator begin()
	{
		return iterator(head->left);
	}

	iterator end()
	{
		return iterator(head);
	}

	///////////////////////////////////
	// capacity
	bool empty()const
	{
		return nullptr == head->parent;
	}

	size_t size()const
	{
		return _size;
	}

	/////////////////////////////////////////
	// acess


	pair<iterator, bool> Insert(const T& data)
	{
		// �����Ҳ�Ƕ���������
		// 1. ���ն����������Ĺ�������½ڵ�
		Node*& root = GetRoot();
		if (nullptr == root)
		{
			root = new Node(data, BLACK);
			head->left = root;
			head->right = root;
			root->parent = head;
			_size = 1;
			return make_pair(iterator(root), true);
		}

		// �Ҵ�����ڵ��ڶ�������������λ�ã����ұ�����˫��
		Node* cur = root;
		Node* parent = head;
		KOFV kofv;   // ��data�л�ȡkey�ķº�������
		while (cur)
		{
			parent = cur;
			if (kofv(data) < kofv(cur->data))
				cur = cur->left;
			else if (kofv(data) > kofv(cur->data))
				cur = cur->right;
			else
				return make_pair(iterator(cur), false);
		}

		// �����½ڵ�
		cur = new Node(data);
		Node* pNewNode = cur;
		if (kofv(data) < kofv(parent->data))
			parent->left = cur;
		else
			parent->right = cur;
		cur->parent = parent;


		// �½ڵ����ɹ��󣬺����������3���ܻ��⵽�ƻ�
		// ��Ϊcur�½ڵ��Ĭ����ɫ�Ǻ�ɫ��
		// ���parent�ڵ����ɫ�Ǻ�ɫ�ģ�û��Υ���κ�����
		// ���parent�ڵ����ɫ�Ǻ�ɫ�ģ�Υ����������,������е���
		while (parent != head && RED == parent->color)
		{
			// parent != head : ����������ȷ��parentһ����������Ч�Ľڵ�
			// parent->color == RED: ���������Ա�֤parentһ�����Ǹ��ڵ�
			Node* grandFather = parent->parent;
			if (parent == grandFather->left)
			{
				// �μ��и������һ����
				Node* uncle = grandFather->right;
				if (uncle && uncle->color == RED)
				{
					// ���һ
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;

					// ���ԭ��grandFather��˫�ף���Ҫ�������ϸ���
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					// ������������
					if (cur == parent->right)
					{
						// �����
						RotateLeft(parent);
						std::swap(parent, cur);
					}

					// �����
					parent->color = BLACK;
					grandFather->color = RED;
					RotateRight(grandFather);
				}
			}
			else
			{
				// �μ��и������һ�����ķ����
				Node* uncle = grandFather->left;
				if (uncle && RED == uncle->color)
				{
					// ���һ�����
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;

					// ��Ҫ�������ϸ���
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					// �������������ķ����
					if (cur == parent->left)
					{
						//������ķ����
						RotateRight(parent);
						std::swap(parent, cur);
					}

					// ������ķ����
					parent->color = BLACK;
					grandFather->color = RED;
					RotateLeft(grandFather);
				}
			}
		}

		root->color = BLACK;
		head->left = LeftMost();
		head->right = RightMost();
		_size++;
		return make_pair(iterator(pNewNode), true);
	}

	void swap(RBTree<T, KOFV>& t)
	{
		std::swap(head, t.head);
	}

	void clear()
	{
		_Destroy(head->parent);
		_size = 0;
		head->left = head;
		head->right = head;
	}

	iterator find(const T& data)
	{
		KOFV kofv;
		Node* cur = GetRoot();
		while (cur)
		{
			if (kofv(data) == kofv(cur->data))
				return iterator(cur);
			else if (kofv(data) < kofv(cur->data))
				cur = cur->left;
			else
				cur = cur->right;
		}

		return iterator(head);
	}

	void InOrder()
	{
		_InOrder(head->parent);
		cout << endl;
	}

	bool IsValidRBTree()
	{
		Node* root = GetRoot();
		// 1. ����
		if (nullptr == root)
			return true;

		// 2. �ǿ�----���պ���������������м��
		if (BLACK != root->color)
		{
			cout << "Υ����������ʶ������ڵ㲻�Ǻ�ɫ��!!!" << endl;
			return false;
		}

		// ��֤��������������
		// ������֤�����ģ�ÿ��·���к�ɫ�ڵ������ͬ---�����ҵ�ÿ��·���к�ɫ�ڵ����Ȼ��Ա�
		// �ҵ�һ��·���к�ɫ�ڵ�ĸ���---ͳ�������·���к�ɫ�ڵ����
		size_t blockCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (BLACK == cur->color)
				blockCount++;

			cur = cur->left;
		}

		// �������·���к�ɫ�ڵ�ĸ�ʽ�������·���к�ɫ�ڵ�����Ƿ���ͬ
		size_t pathCount = 0;
		return _IsValidRBTree(root, blockCount, pathCount);
	}

private:
	bool _IsValidRBTree(Node* root, size_t blockCount, size_t pathCount)
	{
		if (nullptr == root)
		{
			return true;
		}

		if (BLACK == root->color)
		{
			pathCount++;
		}

		Node* parent = root->parent;
		if (parent != head && RED == parent->color && RED == root->color)
		{
			cout << "Υ������3��������һ��ĺ�ɫ�ڵ�!!!" << endl;
			return false;
		}

		// ���root������Ҷ�ӽڵ�---˵��һ��·���ߵ���
		if (nullptr == root->left && nullptr == root->right)
		{
			if (pathCount != blockCount)
			{
				cout << "Υ������4��·���к�ɫ�ڵ�ĸ�����һ��!!!" << endl;
				return false;
			}
		}

		return _IsValidRBTree(root->left, blockCount, pathCount) &&
			_IsValidRBTree(root->right, blockCount, pathCount);
	}

	Node* LeftMost()
	{
		Node* cur = GetRoot();
		if (nullptr == cur)
			return head;

		while (cur->left)
			cur = cur->left;

		return cur;
	}

	Node* RightMost()
	{
		Node* cur = GetRoot();
		if (nullptr == cur)
			return head;

		while (cur->right)
			cur = cur->right;

		return cur;
	}

	// ����
	void RotateLeft(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;

		parent->right = subRL;
		if (subRL)
			subRL->parent = parent;

		subR->left = parent;

		Node* pparent = parent->parent;

		// ����subR�Լ�parent��˫��
		parent->parent = subR;
		subR->parent = pparent;

		// ������ת֮ǰparent˫�׵��󺢺���ָ����
		if (pparent == head)
		{
			// ˵����ת֮ǰparent���Ǹ��ڵ㣬��ת���֮���µĸ��ڵ�Ӧ��ΪsubR
			head->parent = subR;
		}
		else
		{
			// ��ת֮ǰparent�ĸ��ڵ��Ǵ��ڵ�
			if (parent == pparent->left)
			{
				pparent->left = subR;
			}
			else
			{
				pparent->right = subR;
			}
		}
	}

	// �ҵ���
	void RotateRight(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;

		parent->left = subLR;
		if (subLR)
			subLR->parent = parent;

		subL->right = parent;

		// ����parent��subL��˫��
		Node* pparent = parent->parent;
		parent->parent = subL;
		subL->parent = pparent;

		// ��Ҫ����pparent��ָ�����
		if (pparent == head)
		{
			head->parent = subL;
		}
		else
		{
			if (parent == pparent->left)
			{
				pparent->left = subL;
			}
			else
			{
				pparent->right = subL;
			}
		}
	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->left);
			cout << root->data << " ";
			_InOrder(root->right);
		}
	}

	void _Destroy(Node*& root)
	{
		if (root)
		{
			_Destroy(root->left);
			_Destroy(root->right);
			delete root;
			root = nullptr;
			_size = 0;
		}
	}

	Node*& GetRoot()
	{
		return head->parent;
	}

private:
	Node* head;
	size_t _size;   // ��ʾ������ЧԪ�صĸ���
};



class KOFV
{
public:
	int operator()(int key)
	{
		return key;
	}
};

void TestRBTree()
{
	// 0. ���������
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int, KOFV> t;

	for (auto e : a)
	{
		t.Insert(e);
	}

	// 1. ��֤�Ƿ�Ϊ����������
	t.InOrder();

	// 2. ��֤�Ƿ���������������
	if (t.IsValidRBTree())
	{
		cout << "�����ok" << endl;
	}
	else
	{
		cout << "�����error!!!" << endl;
	}

	RBTree<int, KOFV>::iterator it = t.begin();
	while (it != t.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// �����Զ���ṹ���������begin��end�ķ���֮�� �Ϳ���ʹ��for�����б�����
	for (auto e : t)
	{
		cout << e << " ";
	}
	cout << endl;
}
