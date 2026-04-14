#include "my_malloc.h"
#include <unistd.h>

struct block_meta {
  struct block_meta *next_block;
  size_t size;
  bool is_free;
};

static void *global_base = NULL;

struct block_meta *request_space(struct block_meta *last, size_t size) {
  struct block_meta *block;

  block = sbrk(0);

  void *request = sbrk(size + sizeof(struct block_meta));

  if (request == (void *)-1) {
    return NULL;
  }

  if (last != NULL) {
    last->next_block = block;
  }

  block->next_block = NULL;
  block->size = size;
  block->is_free = false;

  return block;
}

struct block_meta *find_free_block(struct block_meta **last, size_t size) {
  struct block_meta *current = global_base;
  while (current && !(current->is_free && current->size >= size)) {
    *last = current;
    current = current->next_block;
  }
  return current;
}

void my_free(void *ptr) {
  struct block_meta *block = ptr;

  block -= 1;

  block->is_free = true;
}

void *my_malloc(size_t size) {
  struct block_meta *block;

  if (global_base == NULL) {
    block = request_space(NULL, size);
    if (block == NULL)
      return NULL;
    global_base = block;
  } else {
    struct block_meta *last = global_base;

    block = find_free_block(&last, size);

    if (block == NULL) {
      block = request_space(last, size);
      if (block == NULL)
        return NULL;
    } else {
      block->is_free = false;
    }
  }
  return block + 1;
}
