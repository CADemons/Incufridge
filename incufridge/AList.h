/** The AList is intended to provide a basic list for any class types.
*@author Marco Bertschi
*
* The AList is needed to ensure that the List behavior stays the same on
* an Arduino Board as it would be on a Computer.
*
* Usage
* ====================
* The AList class may be used as every other List class known from the .Net framework. A short example - To create a List of integers, define a variable of the type AList<int>:

      AList<int> aList;

* Elements can be added to the list by calling AList<ListItem>::Add:

      aList.Add(120);
      aList.Add(121);
      aList.Add(122);

* You can also get an element of the List by calling AList<ListItem>::GetAt. 
* A Random integer value is returned when the parameter passed to this method is greater than the value returned by AList<ListItem>::Count.

      int a = aList.GetAt(0);
      int b = aList.GetAt(1);

* **Note**: If the List is empty, this Method will return random values or throw a memory Exception. 
* It is therefore strongly recommended to get the number of elements in the list by calling AList<ListItem>::Count - If AList<ListItem>::Count returns a value below zero the list is empty (the counter is zero-based).

      int count = aList.Count();  //Return the zero based count of objects in the list

* In order to clear the List you can call

      aList.Clr();  //Clear the list

*/

#ifndef ALIST_H
#define ALIST_H

template <typename ListItem>
class AList{

private:
	/** Intended for private representation of a ListItem within the AList class - Internal use only!
	@author Marco Bertschi
	*/
	struct PrivateListItem{
		PrivateListItem* prv;
		PrivateListItem* nxt;
		ListItem crnt;
	};
	
	PrivateListItem* last;		//!< The last item of the list.
	PrivateListItem* first;		//!< The first item of the list.
	int count;					//!< Zero-based count of items within the list.

public:
	AList();
	~AList();
	ListItem First();
	ListItem Last();
	
	int Count();
	void Add(ListItem listItem);
	void RemAt(int index);
	ListItem GetAt(int index);
	void Clr();
};

#endif //ALIST_H

//! Instantiates a new instance of an AList.
/*!
\return		AList<ListItem>		A new instance of an AList.
*/
template <typename ListItem>
AList<ListItem>::AList(){
	count = -1;
}
//! Destroys the instance of AList<ListItem>.
/*!
The AList<ListItem>::Clr() is called in order to free memory which
was previously occupied by the dynamically allocated list items.
\sa Clr();
*/
template <typename ListItem>
AList<ListItem>::~AList(){
	if (count > -1){
		Clr(); //Clear the List in order to free memory
	}
}
//! Adds an Item of the type ListItem to the AList.
/*!
\param		li		[ListItem]		The ListItem which is added to the AList.
\return		void	[void]		
*/
template <typename ListItem>
void AList<ListItem>::Add(ListItem li){
	PrivateListItem* pLItem = new PrivateListItem;
	pLItem->crnt = li;

	if (count > -1){
		pLItem->nxt = first;
		pLItem->prv = last;
		last->nxt = pLItem;
		last = pLItem;
		count++;
	}
	else if (count == -1){
		first = pLItem;
		first->nxt = pLItem;
		first->prv = pLItem;
		last = pLItem;
		last->nxt = pLItem;
		last->prv = pLItem;
		count = 0;
	}
}
//! Removes a ListItem from a given index position in the AList.
/*!
In case that there is no ListItem stored at the given index of the List 
no operation will be done and the list remains unchanged.

\param		index	[int]	The Index at which the ListItem gets removed.
\return		void	[void]
*/
template <typename ListItem>
void AList<ListItem>::RemAt(int index){
	if (index < count){
		PrivateListItem* pLItem = last;
		for (int i = 0; i <= index; i++){
			pLItem = pLItem->nxt;
		}
		pLItem->prv->nxt = pLItem->nxt;
		pLItem->nxt->prv = pLItem->prv;
		delete pLItem;
		count--;
	}
}
//! Gets a ListItem from a given index position in the AList.
/*!
In case that there is no ListItem stored at the given index of the List
this method will return a random value, or may lead to a Memory read exception.
This also applies if no item at all is stored in the list.

\param		index		[int]		The Index at which the ListItem gets removed.
\return		ListItem	[ListItem]	The ListItem at the position `index` in the list.
\sa Count()
*/
template <typename ListItem>
ListItem AList<ListItem>::GetAt(int index){
	PrivateListItem* pLItem = first;
	if (index <= count && index > -1){
		int i = 0;
		while(i < index){
			pLItem = pLItem->nxt;
			i++;
		}
	}
	
	return pLItem->crnt;
}
//! Gets the first ListItem which is stored in the list.
/*!
A random value will be returned if no items are stored in the list.

\return		ListItem	[ListItem]    The first ListItem in the list.
\sa Last(), Count()
*/
template <typename ListItem>
ListItem AList<ListItem>::First(){
	return first->crnt;
}
//! Gets the last ListItem which is stored in the list.
/*!
A random value will be returned if no items are stored in the list.
If there is only one Item stored in the list this method returns the same value as AList<ListItem>::First().

\return		ListItem    [ListItem]	The first ListItem in the list.
\sa First(), Count()
*/
template <typename ListItem>
ListItem AList<ListItem>::Last(){
	return last->crnt;
}
//! Gets the number of ListItems in the List.
/*!
The number is zero-based - A return value `0` means that there is one item stored in the list.
Please remember that a return value of `-1` means that there are no items stored in the list.

\return		int		[int]		Zero-based number of Items in the List.
*/
template <typename ListItem>
int AList<ListItem>::Count(){
	return count;
}

//! Clears the content of the List.
/*!

\return		void	[void]
*/
template <typename ListItem>
void AList<ListItem>::Clr(){
	PrivateListItem* pLItem = first;
	while(count > -1){
		PrivateListItem* tbdListItem = pLItem;
		pLItem = pLItem->nxt;
		delete tbdListItem;
		count--;
	}
}
