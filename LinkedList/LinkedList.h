#include <cstddef>
#include <iostream>

struct Node
{
    size_t m_key;
    size_t m_value;
    Node *m_next;

    Node()
        : m_key{0}
        , m_value{0}
        , m_next{nullptr}
    {}
    Node(size_t key, size_t value)
        : m_key{key}
        , m_value{value}
        , m_next{nullptr}
    {}
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList()
        : head{nullptr}
    {}
    SinglyLinkedList(Node *newNode)
        : head{newNode}
    {}
    SinglyLinkedList(size_t value)
        : SinglyLinkedList(new Node(1, value))
    {}

    Node *nodeExists(size_t key)
    {
        Node *temp{nullptr};

        Node *ptr = head;

        while (ptr != nullptr) {
            if (ptr->m_key == key) {
                temp = ptr;
                break;
            }
            ptr = ptr->m_next;
        }

        return temp;
    }

    void appendNode(Node *newNode)
    {
        if (nodeExists(newNode->m_key) != nullptr) {
            std::cout << "Node with Key " << newNode->m_key << "already exists\n";
            return;
        }

        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->m_next != nullptr) {
                temp = temp->m_next;
            }
            temp->m_next = newNode;
        }
    }

    void prependNode(Node *newNode)
    {
        if (nodeExists(newNode->m_key) != nullptr) {
            std::cout << "Node with Key " << newNode->m_key << "already exists\n";
            delete newNode;
            return;
        }
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->m_next = head;
            head = newNode;
        }
    }

    void insertNodeAfter(size_t key, Node *newNode)
    {
        Node *node = nodeExists(key);

        if (node == nullptr) {
            std::cout << "Node with Key " << node->m_key << "doesn't exists\n";
            delete newNode;
            return;
        }

        if (nodeExists(newNode->m_key) != nullptr) {
            std::cout << "Node with Key " << newNode->m_key << "already exists\n";
            delete newNode;
            return;
        }

        newNode->m_next = node->m_next;
        node->m_next = newNode;
        std::cout << "Node with Key " << newNode->m_key << " inserted \n";
    }

    void deleteNode(size_t key)
    {
        if (head == nullptr)
            return;

        if (nodeExists(key) == nullptr) {
            std::cout << "Node with Key " << key << "doesn't exists\n";
            return;
        }

        if (head != nullptr && head->m_key == key) {
            auto temp = head;
            head = head->m_next;
            delete temp;
            return;
        }

        Node *prevPtr = head;
        Node *curentPtr = head->m_next;

        while (curentPtr != nullptr) {
            if (curentPtr->m_key == key) {
                prevPtr->m_next = curentPtr->m_next;
                delete curentPtr;
                break;
            } else {
                prevPtr = prevPtr->m_next;
                curentPtr = curentPtr->m_next;
            }
        }
    }

    void updateNode(size_t key, size_t value)
    {
        Node *node = nodeExists(key);

        if (node == nullptr) {
            std::cout << "Node with Key " << node->m_key << "doesn't exists\n";
            return;
        }

        node->m_value = value;
    }

    void printLinkedList()
    {
        if (head == nullptr) {
            std::cout << "Empty Linked List\n";
        }

        auto *temp = head;
        while (temp != nullptr) {
            std::cout << " " << temp->m_key << " " << temp->m_value
                      << ((temp->m_next != nullptr) ? " --> " : "\n");
            temp = temp->m_next;
        }
    }

    ~SinglyLinkedList()
    {
        if (!head)
            return;

        auto *temp = head;
        while (temp != nullptr) {
            std::cout << "Deleting Node " << head->m_value << "\n";
            head = head->m_next;
            delete temp;
            temp = head;
        }
    }
};
