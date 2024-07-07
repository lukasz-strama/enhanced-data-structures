#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

/**
 * @brief Struct representing a dynamic array.
 */
typedef struct
{
    void *data;       /**< Pointer to the array storing elements. */
    size_t size;      /**< Number of elements currently in the array. */
    size_t capacity;  /**< Current capacity of the array. */
    size_t item_size; /**< Size of each element in bytes. */
} DynamicArray;

/**
 * @brief Initializes a dynamic array with given initial capacity and item size.
 *
 * @param arr Pointer to the DynamicArray structure to initialize.
 * @param initial_capacity Initial capacity of the array.
 * @param item_size Size of each element in bytes.
 */
void dynamic_array_init(DynamicArray *arr, size_t initial_capacity, size_t item_size);

/**
 * @brief Adds an element to the end of the dynamic array.
 *
 * @param arr Pointer to the DynamicArray structure.
 * @param value Pointer to the value to be added.
 */
void dynamic_array_push_back(DynamicArray *arr, const void *value);

/**
 * @brief Accesses the element at the specified index in the dynamic array.
 *
 * @param arr Pointer to the DynamicArray structure.
 * @param index Index of the element to access.
 * @return Pointer to the element at the specified index.
 */
void *dynamic_array_at(const DynamicArray *arr, size_t index);

/**
 * @brief Removes the last element from the dynamic array.
 *
 * @param arr Pointer to the DynamicArray structure.
 */
void dynamic_array_pop_back(DynamicArray *arr);

/**
 * @brief Returns the number of elements in the dynamic array.
 *
 * @param arr Pointer to the DynamicArray structure.
 * @return Number of elements in the array.
 */
size_t dynamic_array_size(const DynamicArray *arr);

/**
 * @brief Checks if the dynamic array is empty.
 *
 * @param arr Pointer to the DynamicArray structure.
 * @return 1 if the array is empty, 0 otherwise.
 */
int dynamic_array_empty(const DynamicArray *arr);

/**
 * @brief Reserves a minimum capacity for the dynamic array.
 *
 * @param arr Pointer to the DynamicArray structure.
 * @param new_capacity Minimum capacity to reserve.
 */
void dynamic_array_reserve(DynamicArray *arr, size_t new_capacity);

/**
 * @brief Frees the dynamically allocated memory used by the dynamic array.
 *
 * @param arr Pointer to the DynamicArray structure to free.
 */
void dynamic_array_free(DynamicArray *arr);

/**
 * @brief Copies the contents of one dynamic array to another.
 *
 * @param dest Pointer to the destination DynamicArray structure.
 * @param src Pointer to the source DynamicArray structure.
 */
void dynamic_array_copy(DynamicArray *dest, const DynamicArray *src);

/**
 * @brief Inserts an element at the specified index in the dynamic array.
 *
 * @param arr Pointer to the DynamicArray structure.
 * @param index Index at which to insert the element.
 * @param value Pointer to the value to be inserted.
 */
void dynamic_array_insert(DynamicArray *arr, size_t index, const void *value);

/**
 * @brief Removes the element at the specified index in the dynamic array.
 *
 * @param arr Pointer to the DynamicArray structure.
 * @param index Index of the element to remove.
 */
void dynamic_array_erase(DynamicArray *arr, size_t index);

#endif /* DYNAMIC_ARRAY_H */
