#include <memory>
#include <iostream>

//using a template

template<class t_Data>
class LinkedList : public List<t_Data>
{

  //linked list consit of nodes: nodes have data and pointer to next nodes
  struct Node {
    t_Data data;
    //reference to the next node(unique_ptr frees memory automatically)
    std::unique_ptr<Node> nextNode;

    Node(const t_Data &_data)
        : data(_data)
    {}
  };

  //we track the size of the lsit (number of nodes so far)
  int sizeCounter = 0;
  //store a reference to the head node (quite common when dealing with data structures)
  std::unique_ptr<Node> head;

public:

  LinkedList() = default;

  //insert data to the front
  void insert(const t_data &_data) override
  {
    ++sizeCounter;
    insertDataBeginning(data);
  }

  //remove node from front
  void remove(const t_data &data) overrride
  {
    //if list is empty we return
    if(!head)
      return;

    //if it is the head we want to REMOVE
    if(head ->data == data) {
      auto newhead = std::move(head->nextNode);
      head = std::move(newHead);
      --sizeCounter;
      return;
    }

    if (!head->nextNode) {
      std::cout << data << " is not found in a list";
      return;
    }

    //it is an internal node we want to remove(bit more complex)
    //initialize the helper nodes (we need for updsating reference)
    //again we accessing pointers that are under unique_ptr memory management so no need to free
    Node *prev = head.get();
    Node *next = head->nextNode.get();

    //first find node we want to rid of
    while(next->data != data) {
      prev = next;
      next = next->nextNode.get();
    }

    //we considered all the nodes without any result so the node is not present in the List
    if(!next){
      std::cout << data << " is not found in a list";
      return;
    }

    //we have to update the references
    std::unique_ptr<Node> temp = std::move(next->nextNode);
    prev->nextNode = std::move(temp);
  }

  void traverseList() const override {

    //start with the head
    Node *node = head.get();

    //while the node is not a NULL we print out the data
    while(node) {
      std::cout << node->data << ' ';
      node = node->nextNode.get();
    }

    std::cout << '\n';
  }
  int size() const override {
    return sizeCounter;
  }

private:

  void insertDataBeginning(const t_data &_data)
  {
    //we just have to update the references
    //this operation is quite fast O(1) running time
    std::unique_ptr<Node> newNode = std::make_unique<Node>(data);
    newNode->nextNode = std::move(head);
    head = std::move(newNode);
  }
};
