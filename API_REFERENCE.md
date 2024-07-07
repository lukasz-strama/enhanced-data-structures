# API Reference - Enhanced Data Structures (EDS)

# Overview

The Enhanced Data Structures (EDS) library provides a set of dynamic data structures implemented in C. This document details the API for the DynamicArray data structure.

## DynamicArray

The DynamicArray structure is a resizable array implementation that provides dynamic memory management for arrays in C.

### Struct Definition

The DynamicArray struct is defined as follows:

#### DynamicArray

- `void *data`: Pointer to the array storing elements.
- `size_t size`: Number of elements currently in the array.
- `size_t capacity`: Current capacity of the array.
- `size_t item_size`: Size of each element in bytes.

### Functions

`void dynamic_array_init(DynamicArray *arr, size_t initial_capacity, size_t item_size);`

Initializes a dynamic array with the specified initial capacity and item size.

- #### Parameters:

  - `arr`: Pointer to the DynamicArray structure to initialize.
  - `initial_capacity`: Initial capacity of the array.
  - `item_size`: Size of each element in bytes.

- #### Example:

  ```c
  DynamicArray arr;
  dynamic_array_init(&arr, 10, sizeof(int));
  ```

`void dynamic_array_push_back(DynamicArray *arr, const void *value);`

Adds an element to the end of the dynamic array.

- #### Parameters:

  - `arr`: Pointer to the DynamicArray structure.
  - `value`: Pointer to the value to be added.

- #### Example:

  ```c
  int value = 42;
  dynamic_array_push_back(&arr, &value);
  ```

`void *dynamic_array_at(const DynamicArray *arr, size_t index);`

Accesses the element at the specified index in the dynamic array.

- #### Parameters:

  - `arr`: Pointer to the DynamicArray structure.
  - `index`: Index of the element to access.

- #### Returns:

  - Pointer to the element at the specified index, or NULL if the index is out of bounds.

- #### Example:

  ```c
  int _value = *(int *)dynamic_array_at(&arr, 0);
  ```

`void dynamic_array_pop_back(DynamicArray *arr);`

Removes the last element from the dynamic array.

- #### Parameters:

  - `arr`: Pointer to the DynamicArray structure.

- #### Example:

  ```c
  dynamic_array_pop_back(&arr);
  ```

`size_t dynamic_array_size(const DynamicArray *arr);`

Returns the number of elements in the dynamic array.

- #### Parameters:

  - `arr`: Pointer to the DynamicArray structure.

- #### Returns:

  - Number of elements in the array.

- #### Example:

  ```c
  size_t size = dynamic_array_size(&arr);
  ```

`int dynamic_array_empty(const DynamicArray *arr);`

Checks if the dynamic array is empty.

- #### Parameters:

  - `arr`: Pointer to the DynamicArray structure.

- #### Returns:

  - 1 if the array is empty, 0 otherwise.

- #### Example:

  ```c
  int is_empty = dynamic_array_empty(&arr);
  ```

`void dynamic_array_reserve(DynamicArray *arr, size_t new_capacity);`

Reserves a minimum capacity for the dynamic array.

- #### Parameters:

  - `arr`: Pointer to the DynamicArray structure.
  - `new_capacity`: Minimum capacity to reserve.

- #### Example:

  ```c
  dynamic_array_reserve(&arr, 20);
  ```

`void dynamic_array_free(DynamicArray *arr);`

Frees the dynamically allocated memory used by the dynamic array.

- #### Parameters:

  - `arr`: Pointer to the DynamicArray structure to free.

- #### Example:

  ```c
  dynamic_array_free(&arr);
  ```

`void dynamic_array_copy(DynamicArray *dest, const DynamicArray *src);`

Copies the contents of one dynamic array to another.

- #### Parameters:

  - `dest`: Pointer to the destination DynamicArray structure.
  - `src`: Pointer to the source DynamicArray structure.

- #### Example:

  ```c
  DynamicArray dest;
  dynamic_array_copy(&dest, &src);
  ```

`void dynamic_array_insert(DynamicArray *arr, size_t index, const void *value);`

Inserts an element at the specified index in the dynamic array.

- #### Parameters:

  - `arr`: Pointer to the DynamicArray structure.
  - `index`: Index at which to insert the element.
  - `value`: Pointer to the value to be inserted.

- #### Example:

  ```c
  int value = 99;
  dynamic_array_insert(&arr, 1, &value);
  ```

`void dynamic_array_erase(DynamicArray *arr, size_t index);`

Removes the element at the specified index in the dynamic array.

- #### Parameters:

  - `arr`: Pointer to the DynamicArray structure.
  - `index`: Index of the element to remove.

- #### Example:

  ```c
  dynamic_array_erase(&arr, 0);
  ```

### Usage Example

```c
#include <stdio.h>
#include "dynamic_array.h"

int main() {
        DynamicArray arr;
        dynamic_array_init(&arr, 5, sizeof(int));

        for (int i = 0; i < 10; ++i) {
                dynamic_array_push_back(&arr, &i);
        }

        for (size_t i = 0; i < dynamic_array_size(&arr); ++i) {
                int *value = (int *)dynamic_array_at(&arr, i);
                printf("%d ", *value);
        }

        dynamic_array_free(&arr);
        return 0;
}
```
