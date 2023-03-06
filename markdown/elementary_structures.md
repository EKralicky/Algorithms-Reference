# Elementary Data Structures


## Arrays

C++ Examples [Here](../examples/structures/array.cpp)

Arrays are Sequential locations in memory in linear order in which elements are accessed by index. In post programming languages, an array of n elements starts at index 0, and ends at index n-1

**Cost of Operations**
- **Search** - Θ(n)
  - Searching for an element (by value) requires us to iterate through the entire array. The best case is where the element is at the start of the array, O(1) and the worst case is where the element is at the end of the array O(n). Avg = Θ(n)
- **Insert** (at an index) - Θ(1)
  - This is why arrays are very useful. They have constant insert time at a specific index
- **Insert** (at the next open space) - Θ(n)
  - If we are inserting at the next open space, we need to iterate at worst n-1 times (if the space is at the end) which gives us a time complexity of Θ(n)
- **Delete** (given element value) - Θ(n)
  - Deleting an element by value requires us to search the entire array for that element which takes Θ(n) avg time.
- **Min** - Θ(n)
  - We need to seach for the min and keep track of the min - Θ(n)
- **Max** - Θ(n)
  - We need to seach for the max and keep track of the max - Θ(n)

## Linked Lists

### Singly linked lists
### Doubly linked lists
## Stacks
## Queues
## Heaps
