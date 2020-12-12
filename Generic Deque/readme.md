# Statement: 
Implementation of deque.
What is deque?
Deque is the same as dynamic arrays with the ability
to resize itself automatically when an element is
inserted or deleted, with their storage being handled
automatically by the container.
* They support insertion and Deletion from both ends
in amortized constant time.
* Inserting and erasing in the middle is linear in time.
What is expected as solution?
The C++ standard specifies that a legal (i.e., standardconforming) implementation of deque must satisfy
# the following functions requirements:
* deque() - initialize a blank deque.
* deque(n,x) - initialize a deque of length n with all
values as x.
* push_back(x) - append data x at the end.
* pop_back() - erase data at the end.
* push_front(x) - append data x at the beginning.
* pop_front() - erase data at the beginning.
* front() - returns the first element(value) in the deque.
* back() - returns the last element(value) in the deque.
* empty() - returns true if deque is empty else returns
false.
* size() - returns the current size of deque.
* resize(x, d) - changes the size dynamically. If the
new size is greater than the current size of the
deque, then fill the empty space with the default
value d.
* clear() - remove all elements of deque.
* D[n] - returns the nth element of the deque.
# Evaluation parameters: Accuracy of operations and
performance.
# The following represent the corresponding query number for each function:
1. push_front(x) <br />
2. pop_front() <br />
3. push_back(x) <br />
4. pop_back() <br />
5. deque() <br />
6. deque(n,x) <br />
7. front() <br /> 
8. back() <br />
9. empty() <br />
10. size() <br />
11. resize(x, d) <br />
12. clear() <br />
13. D[n] <br />
14. display() - display contents of deque <br />
Your task is to take Q queries as input and perform the corresponding function and display the
queue.
# Input format for this question:
First Line contains the query count Q
Next Q lines contain the query no and input( if any)
# Output format for this question:
Q-1 lines displaying queue after each query <br />
NOTE: for correct execution, the first query will be always deque() or deque(n,x) <br />
Output for first query is not required as deque() will be empty
SAMPLE:
INPUT <br />
6 <br />
5 <br />
1 2 <br />
1 3 <br />
3 4 <br /> 
7 <br />
10 <br />
Output <br />
2 <br />
3 2  <br />
3 2 4 <br />
3 <br />
3 <br />
