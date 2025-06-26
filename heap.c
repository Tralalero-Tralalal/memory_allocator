#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define CAPACITY 640000
#define HEAP_ALLOCED_CAPACITY 1024
#define HEAP_FREED_CAPACITY 1024

typedef struct {
  void *start;
  size_t size;
} Heap_Chunk;

char heap[CAPACITY] = {0};
Heap_Chunk heap_alloced[HEAP_ALLOCED_CAPACITY];
Heap_Chunk heap_freed[HEAP_FREED_CAPACITY]

size_t heap_freed = 0;
size_t heap_alloced_size = 0;
size_t heap_size = 0;

void *heap_alloc(size_t size) {
  if (size > 0) {
    assert(heap_size + size <= CAPACITY);
    // This uses pointer arithmetic to point to a block in memory (bytes * heap_size) after the heap memory address
    // This memory is now used, and is returned as a pointer.
    void *result = heap + heap_size;
    // let the program update the size
    
    heap_size += size;
   
    Heap_Chunk chunk = {
      .start = result,
      .size = size,
    
    assert(heap_alloced_size <HEAP_ALLOCED_CAPACITY);
   
    heap_alloced[heap_alloced_size++] = chunk;
   
    return result;
  } else {
    return 0;
  }
}

void heap_dump_alloced_chunks(void) {
  for (size_t i = 0; i < heap_alloced_size; ++i) {
    printf(" start: %p, size: %zu\n", heap_alloced[i].start, heap_alloced[i].size);
  }
}

// marks a place in memory as deallocated
void heap_free(void *ptr) {
  for (size_t i = 0; i < heap_alloced_size; i++) {
    if (heap_alloced[i].start == ptr) {
      printf("hello!");
    }
  }
}

void heap_collect() {
  assert(false && "TODO: heap collect is not implemented");
}
int main() {
  /*for (int i = 0; i < 100; i++) {
    heap_alloc(i);
  }*/ 
  heap_free(heap_alloc(27));

  heap_dump_alloced_chunks();
  return 0;
}

