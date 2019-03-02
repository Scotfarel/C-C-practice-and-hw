#include <iostream>

void f(int a) {
    char f[100000000];
}

void b(int a) {
    char* f = new char[1000000];
    delete[] f;
}

char* test(int a) {
    char* f = new char[1000000];
    return f;
}


class Queue {
    struct Node {
        int data;
        Node* next;
        explicit Node(int data) : data(data), next(nullptr) {}
    };

public:
    Queue();
    Queue(const Queue&) = delete;
    Queue(Queue&&) = delete;
    Queue& operator= (const Queue&) = delete;
    Queue& operator= (Queue&&) = delete;
    ~Queue();

    void Equeue(int data);
    int Dequeue();
    bool IsEmpty() const {return head == nullptr && tail == head; }

private:
    Node* head;
    Node* tail;
};

Queue::Queue() : head(nullptr), tail(nullptr) {
}

Queue::~Queue() {
    while (!IsEmpty()) {
        Dequeue();
    }
}

void Queue::Equeue(int data) {
    Node* node = new Node(data);
    if (IsEmpty()) {
        head = tail = node;
        return;
    }
    tail->next = node;
    tail = node;
}

int Queue::Dequeue() {
    int tmpData = head->data;
    Node* tmpNode = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete tmpNode;
    return tmpData;
}

int main() {
    //f(10);  //   bad way to do a large array on stack
    //b(10);  // good way
    //test(10);   //  c-style, warning

    Queue queue;
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int operation = 0;
        int value = 0;
        std::cin >> operation >> value;
        switch (operation) {
            case 2: {
                int queue_value = -1;
                if (!queue.IsEmpty()) {
                    queue_value = queue.Dequeue();
                }
                if (queue_value != value) {
                    std::cout << "NO" << std::endl;
                    return 0;
                }
                break;
            }
            case 3:
                queue.Equeue(value);
                break;
            default:
                std::cout << "NO" << std::endl;
                return 0;
        }
    }
    std::cout << "YES" << std::endl;

    return 0;
}
