#pragma once

template <typename contentType>
class KosList
{
public:
	KosList();
	void addline(contentType);
	contentType line(int);
private:
	class node
	{
	public:
		node(contentType,int);
		node* nextNode;
		contentType line(int);

	private:
		contentType data;
		int index;
	};
	int nodesAmought;
	node* startNode;
	node* lastNode;
};


template<typename contentType>
KosList<contentType>::KosList() : nodesAmought(0)
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
		lastNode->nextNode = new node(inpdata, nodesAmought++);
		lastNode = lastNode->nextNode;
	}
	else
	{
		startNode = new node(inpdata, nodesAmought++);
		lastNode = startNode;
	}
	
}

template <typename contentType>
contentType KosList<contentType>::line(int nodeIndex)
{
	return startNode->line(nodeIndex);
}

template <typename contentType>
contentType KosList<contentType>::node::line(int nodeIndex)
{
	if (nodeIndex == index) return data;
	else nextNode->line(nodeIndex);
}

template<typename contentType>
KosList<contentType>::node::node(contentType initContent, int nodeIndex)
{
	index = nodeIndex;
	nextNode = nullptr;
	data = initContent;
}

