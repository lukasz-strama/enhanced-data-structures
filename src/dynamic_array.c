#include "../include/dynamic_array.h"
#include <stdlib.h>

// Copies `size` bytes from `src` to `dest` memory locations.
static void element_copy(void *dest, const void *src, size_t size)
{
    char *d = (char *)dest;
    const char *s = (const char *)src;
    for (size_t i = 0; i < size; ++i)
    {
        d[i] = s[i];
    }
}

// Initializes a dynamic array with specified initial capacity and item size.
void dynamic_array_init(DynamicArray *arr, size_t initial_capacity, size_t item_size)
{
    arr->data = malloc(initial_capacity * item_size);           // Allocate memory for data array
    arr->size = 0;                                              // Initialize size to 0
    arr->capacity = (arr->data != NULL) ? initial_capacity : 0; // Set initial capacity based on allocation success
    arr->item_size = item_size;                                 // Set size of each item in the array
}

// Adds an element to the end of the dynamic array.
void dynamic_array_push_back(DynamicArray *arr, const void *value)
{
    if (arr->size >= arr->capacity)
    {
        size_t new_capacity = arr->capacity * 2; // Double the current capacity
        if (new_capacity == 0)
            new_capacity = 1;                     // Ensure minimum capacity of 1 if current capacity is 0
        dynamic_array_reserve(arr, new_capacity); // Reserve space if needed
    }

    element_copy((char *)arr->data + arr->size * arr->item_size, value, arr->item_size); // Copy the value to the end
    arr->size++;                                                                         // Increment the size of the array
}

// Retrieves a pointer to the element at the specified index in the dynamic array.
void *dynamic_array_at(const DynamicArray *arr, size_t index)
{
    if (index < arr->size)
    {
        return (char *)arr->data + index * arr->item_size; // Calculate and return pointer to element
    }
    else
    {
        return NULL; // Return NULL if index is out of bounds
    }
}

// Removes the last element from the dynamic array.
void dynamic_array_pop_back(DynamicArray *arr)
{
    if (arr->size > 0)
    {
        arr->size--; // Decrement the size of the array to remove the last element
    }
}

// Returns the number of elements in the dynamic array.
size_t dynamic_array_size(const DynamicArray *arr)
{
    return arr->size; // Return the current size of the array
}

// Checks if the dynamic array is empty.
int dynamic_array_empty(const DynamicArray *arr)
{
    return (arr->size == 0); // Return 1 if the array is empty, 0 otherwise
}

// Reserves a minimum capacity for the dynamic array.
void dynamic_array_reserve(DynamicArray *arr, size_t new_capacity)
{
    if (new_capacity > arr->capacity)
    {
        void *new_data = realloc(arr->data, new_capacity * arr->item_size); // Attempt to reallocate memory
        if (new_data != NULL)
        {
            arr->data = new_data;         // Update pointer to the new memory block
            arr->capacity = new_capacity; // Update capacity of the array
        }
    }
}

// Frees the dynamically allocated memory used by the dynamic array.
void dynamic_array_free(DynamicArray *arr)
{
    free(arr->data);   // Free memory allocated for the data array
    arr->data = NULL;  // Set data pointer to NULL
    arr->size = 0;     // Reset size of the array to 0
    arr->capacity = 0; // Reset capacity of the array to 0
}
