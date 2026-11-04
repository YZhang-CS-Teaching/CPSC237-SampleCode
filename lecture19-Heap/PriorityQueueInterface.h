#ifndef PRIORITY_QUEUE_INTERFACE_
#define PRIORITY_QUEUE_INTERFACE_

template<class ItemType>
class PriorityQueueInterface
{
public:
   /** Sees whether this priority queue is empty.
    @return True if the priority queue is empty, or false if not. */
   virtual bool isEmpty() const = 0;

   /** Adds a new entry to the priority queue.
    @param newEntry The entry to add.
    @return True if the addition is successful, or false if not. */
   virtual bool enqueue(const ItemType& newEntry) = 0;

   /** Removes the highest-priority entry from the priority queue.
    @return True if the removal is successful, or false if not. */
   virtual bool dequeue() = 0;

   /** Gets the highest-priority entry in the priority queue.
    @pre The priority queue is not empty.
    @return The highest-priority entry. */
   virtual ItemType peek() const = 0;

   /** Destroys this priority queue and frees its assigned memory. */
   virtual ~PriorityQueueInterface() { }
};

#endif
