/*
Will Hooker
10/20/2023
CS221-02
This program implements a queue using a struct, consisting of predetermined values.
It will use functions to enqueue and dequeue, find the sum of the elements in the queue, and determine if the queue is empty.
*/
#include <iostream>

using namespace std;

struct queue { //creation of the struct queue, containing variables to index the head and tail of the queue, the array itself, and the functions that operate on it
	int tail = -1;
	int head = 0;
	int array[5] = {};

	void enqueue(int data) { //the enqueue function
		tail++; //incrementing tail, to avoid the -1 value if the queue is empty
		if (isFull() == 1) { //checking if the queue is empty
			cout << "Queue is full. No more elements can be added." << endl;
			return;
		}
		array[tail] = data; //assigning the data value to the end of the queue, using the tail variable
		cout << "Enqueued element: " << array[tail] << endl;
	}
	void dequeue() { //the dequeue function
		if (isEmpty() == 1) { //first checks if the queue is empty using the value returned from the isEmpty function
			cout << "Queue is empty. There are no elements to remove." << endl;
			head = 0; //if the queue is empty, it resets the values of the tail and head variables
			tail = -1;
			return;
		}
		cout << "Dequeued element: " << array[head] << endl;
		array[head] = 0; //"deleting" the desired element of the queue by setting the value equal to 0
		head++; //incrementing head to represent the new head of the list
	}
	int isEmpty() { //function to check if the queue is empty
		if (tail == -1 || head == 5) { //the queue is empty is either the tail is equal to -1, or if the head is equal to 5 after dequeueing all of the elements
			return 1;
		}
		else return 0;
	}
	int isFull() { //checking if the queue is full
		if (tail == 5) {
			tail = 4; //resetting the tail variable to the last index of the array
			return 1;
		}
		else return 0;
	}
	void qSum() { //function to calculate the sum
		if (isEmpty() == 1) { //first checks if the queue is empty using the value returned from the isEmpty function
			cout << "Queue is empty. Cannot calculate sum." << endl;
			cout << "Sum of elements in the queue: 0" << endl;
			return;
		}
		int sum = 0;
		for (int i = 0; i < 5; i++) { //calculates the sum of the elements in the queue using a for loop
			sum += array[i];
		}
		cout << "Sum of elements in the queue: " << sum << endl;
	}
};

int main(){
	queue myQ; //initialization of the queue named myQ

	myQ.enqueue(10); //calling the enqueue function to add the desired elements
	myQ.enqueue(20);
	myQ.enqueue(30);
	myQ.enqueue(40);
	myQ.enqueue(50);
	myQ.enqueue(60); //tries adding an element after the queue is full

	myQ.qSum(); //calls the function to calculate the sum

	myQ.dequeue(); //calling the dequeue function to remove the element in the front of the queue
	myQ.dequeue();
	myQ.dequeue();
	myQ.dequeue();
	myQ.dequeue();
	myQ.dequeue(); //tries to remove an element after the queue is empty
	  
	myQ.qSum(); //calculates the sum again after the queue is empty

	return 0;
}