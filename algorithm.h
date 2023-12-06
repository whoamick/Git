#include "list.h"
template <class T>
class Algorithm {
public:
	Algorithm();
	~Algorithm();
	void Sort(List<T>& list);
};

template <class T>
Algorithm<T>::Algorithm()
{
}

template <class T>
Algorithm<T>::~Algorithm()
{
}

//template <typename T>
//void Algorithm<T>::Sort(List<T>& list) {
//	Node<T>* tmp = new Node<T>;
//	Iterator<T> it_1 = list.Begin();
//	Iterator<T> it_2 = list.Begin()->next;
//	while (it_1 != NULL)
//	{
//		it_2 = it_1;
//		++it_2;
//		while (it_2 != NULL)
//		{
//			if ((*it_1) > (*it_2))
//			{
//				tmp->data = *it_1;
//				*it_1 = *it_2;
//				*it_2 = tmp->data;
//			}
//			++it_2;
//		}
//		++it_1;
//	}
//}