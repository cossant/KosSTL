#pragma once

template <typename contentType>
class KosList
{
public:
	KosList();
	void addline(contentType);
	contentType line(int);
	void deletenode(int);
private:
	class node
	{
	public:
		node(contentType);
		node* nextNode;
		contentType line(int);
		node* linePtr(int lineIndex)
		{
			if (lineIndex == 0)	return this;
			else nextNode->linePtr(lineIndex - 1);
		}
	private:
		contentType data;
	};
	node* startNode;
	node* lastNode;
	node* linePtr(int index)
	{
		return startNode->linePtr(index);
	}
};


template<typename contentType>
KosList<contentType>::KosList()
{
	startNode = nullptr;
	lastNode = startNode;
}

template<typename contentType>
void KosList<contentType>::addline(contentType inpdata)
{
	int* a = nullptr;
	if (startNode != nullptr)
	{
		lastNode->nextNode = new node(inpdata);
		lastNode = lastNode->nextNode;
	}
	else
	{
		startNode = new node(inpdata);
		lastNode = startNode;
	}
	
}

template <typename contentType>
contentType KosList<contentType>::line(int nodeIndex)
{
	return startNode->line(--nodeIndex);
}

template <typename contentType>
contentType KosList<contentType>::node::line(int nodeIndex)
{
	if (nodeIndex == -1) return data;
	else nextNode->line(--nodeIndex);
}


template<typename contentType>
KosList<contentType>::node::node(contentType initContent)
{
	nextNode = nullptr;
	data = initContent;
}



template <typename contentType>
void KosList<contentType>::deletenode(int index)
{
	node* nodeA = (index > 0) ? linePtr(index - 1) : startNode;
	node * nodeToDelete = linePtr(index);
	node * nodeB = (lastNode == linePtr(index)) ? nullptr : linePtr(index + 1);	
	if (index > 0)
		nodeA->nextNode = nodeB;
	else
		startNode = nodeB;
	delete nodeToDelete;
}


