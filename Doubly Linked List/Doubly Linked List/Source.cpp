using namespace std;
#include<iostream>
class DoublyLL
{
private:
	struct node
	{
		int item;
		node* next;
		node* prev;
	};
	node* head;
	node* rear;
	node* temp;
	int count;
public:
	DoublyLL()
	{
		head = rear = temp = NULL;
		count = 0;
	}
	bool isEmpty()
	{
		return count == 0;
	}
	void add_L(int item)
	{
		node* newnode = new node;
		newnode->item = item;
		if (count == 0)
		{
			newnode->next = NULL;
			newnode->prev = NULL;
			head = rear = newnode;
			count++;
		}
		else
		{
			newnode->next = NULL;
			newnode->prev = rear;
			rear->next = newnode;
			rear = newnode;
			count++;
		}
	}
	void add_F(int item)
	{
		node* newnode = new node;
		newnode->item = item;
		if (count == 0)
		{
			newnode->next = NULL;
			newnode->prev = NULL;
			head = rear = newnode;
			count++;
		}
		else
		{
			newnode->next = head;
			newnode->prev = NULL;
			head->prev = newnode;
			head = newnode;
			count++;
		}
	}
	void add_Pos(int pos, int item)
	{
		node* newnode = new node;
		newnode->item = item;
		if (pos < 0 || pos > count) cout << "Oops!...out of range\n";
		else
		{
			if (pos == 0)
			{
				add_F(item);
			}
			else if (pos == count)
			{
				add_L(item);
			}
			else
			{
				temp = head;
				for (int i = 1; i < pos ; i++)
				{
					temp = temp->next;
				}
				newnode->next = temp->next;
				newnode->prev = temp;
				temp->next->prev = newnode;
				temp->next = newnode;
				count++;
			}
		}
	}
	void remove_f()
	{
		if (isEmpty())cout << "Oops Empty List\n";
		else if (count == 1)
		{
			temp = head;
			head = rear = NULL;
			delete temp;
			count--;
		}
		else
		{
			temp = head;
			head = head->next;
			head->prev = NULL;
			delete temp;
			count--;
		}
	}
	void remove_l()
	{
		if (isEmpty())cout << "Oops Empty List\n";
		else if (count == 1)
		{
			temp = rear;
			head = rear = NULL;
			delete temp;
			count--;
		}
		else
		{
			temp = rear;
			rear = rear->prev;
			rear->next = NULL;
			delete temp;
			count--;
		}
	}
	void remove_pos(int pos)
	{
		if (isEmpty())cout << "Oops Empty List\n";
		else if (pos < 0 || pos >= count) cout << "out of range\n";
		else if (count == 1)
		{
			temp = head;
			head = head->next;
			head->prev = NULL;
			delete temp;
			count--;
		}
		else if (pos == 0)
		{
			remove_f();
		}
		else if (pos == count - 1)
		{
			remove_l();
		}
		else
		{
			temp = head;
			for (int i = 1; i <= pos; i++)
			{
				temp = temp->next;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			count--;
		}
	}
	void remove_item(int item)
	{
		if (isEmpty())cout << "Oops Empty List\n";
		else if (head->item = item && count == 1 )
		{
			temp = head;
			head = head->next;
			head->prev = NULL;
			delete temp;
			count--;
		}
		else if (item == head->item)
		{
			remove_f();
		}
		else if (item == rear->item)
		{
			remove_l();
		}
		else
		{
			temp = head->next;
			while (temp != rear)
			{
				if (temp->item == item)
					break;
				else
					temp = temp->next;
			}
			if (temp == rear)cout << "Item is not exist\n";
			else
			{
				
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				delete temp;
				count--;
			}
		}
	}
	void Dispaly()
	{
		temp = head;
		cout << "[ ";
		while (temp != NULL)
		{
			cout << temp->item << " ";
			temp = temp->next;
		}
		cout << "]\n";
	}
	void Dispaly_Rev()
	{
		temp = rear;
		cout << "Reversed \n[ ";
		while (temp != NULL)
		{
			cout << temp->item << " ";
			temp = temp->prev;
		}
		cout << "]\n";
	}
};
int main()
{
	DoublyLL d;
	d.add_F(10);
	d.add_F(0);
	d.add_L(20);
	d.add_Pos(2, 15);
	//d.remove_item(200);
	//d.remove_pos(3);
	d.Dispaly();
	//d.Dispaly_Rev();
	return 0;
}