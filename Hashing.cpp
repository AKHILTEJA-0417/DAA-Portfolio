#include <iostream>

using namespace std;

const int TABLE_SIZE = 10;

struct Node
 {
    int key;
    int value;
    Node* next;

    Node(int k, int v)
     {
        key = k;
        value = v;
        next = NULL;
    }
};

class HashTable
 {
private:
    Node* table[TABLE_SIZE];

    int hashFunction(int key)
     {
        return key % TABLE_SIZE;
    }

public:
    HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = NULL;
    }

    void insert(int key, int value)
     {
        int hashKey = hashFunction(key);
        Node* newNode = new Node(key, value);
        if (table[hashKey] == NULL)
        {
            table[hashKey] = newNode;
        }
        else
            {
            Node* temp = table[hashKey];
            while (temp->next != NULL)
             {
                if (temp->key == key)
                {
                    temp->value = value;
                    delete newNode;
                    return;
                }
                temp = temp->next;
            }
            if (temp->key == key)
            {
                temp->value = value;
                delete newNode;
                return;
            }
            temp->next = newNode;
        }
    }

    void search(int key)
     {
        int hashKey = hashFunction(key);
        Node* temp = table[hashKey];
        while (temp != NULL)
            {
            if (temp->key == key)
             {
                cout << "Value: " << temp->value << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Key " << key << " not found in hash table" << endl;
    }

    void remove(int key)
    {
        int hashKey = hashFunction(key);
        Node* temp = table[hashKey];
        Node* prev = NULL;
        while (temp != NULL && temp->key != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Key " << key << " not found in hash table" << endl;
            return;
        }
        if (prev == NULL)
        {
            table[hashKey] = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }
        delete temp;
    }
};

int main()
{
    HashTable hashTable;
    int choice, key, value;

    do {
        cout << "\n1. Insert\n2. Search\n3. Remove\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                hashTable.insert(key, value);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                hashTable.search(key);
                break;

            case 3:
                cout << "Enter key to remove: ";
                cin >> key;
                hashTable.remove(key);
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
