#include <bits/stdc++.h>
using namespace std;
template <typename T>
class QueueUsingArray
{
    T *data;
    int front, rear, size;
    int capacity;

public:
    QueueUsingArray(int s)
    {
        data = new T[s];
        front = 0;
        rear = -1;
        size = 0;
        capacity = s;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        if (size == capacity)
        {
            // cout << "Queue Full!" << endl;
            // return;

            T *newData = new T[2 * capacity];
            int j = 0;
            for (int i = rear; i < capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < rear; i++)
            {
                newData[j] = data[i];
                j++;
            }

            delete[] data;
            data = newData;
            rear = 0;
            front = capacity;
            capacity *= 2;
        }

        data[front] = element;
        front = (front + 1) % capacity;
        if (rear == -1)
        {
            rear = 0;
        }
        size++;
    }
    T FrontNo()
    {
        if (isEmpty())
        {
            cout << "Queue is empty !" << endl;
            return 0;
        }
        return data[rear];
    }
    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty !" << endl;
            return 0;
        }
        T ans = data[rear];
        rear = (rear + 1) % capacity;
        size--;
        if (size == 0)
        {
            rear = -1;
            front = 0;
        }

        return ans;
    }
};

int main()
{
    QueueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << q.FrontNo() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
}
