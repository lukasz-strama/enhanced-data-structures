# Enhanced Data Structures (EDS)

Enhanced Data Structures (EDS) is an open-source library providing various dynamic data structures implemented in C. This library is designed for versatility, efficiency, and ease of use in applications where dynamic data management is crucial.

## Features

- [x] **Dynamic Array:** Efficient resizable array implementation.
- [ ] **Binary Tree:** _Coming soon..._
- [ ] **Hash Table:** _Coming soon..._
- [ ] **Linked List:** _Coming soon..._

## Getting Started

To use EDS in your project, follow these steps:

### Prerequisites

- C compiler (supporting C99 or later)

### Installation

1. Clone the repository:

   ```sh
   git clone https://github.com/your-username/EDS-C-Library.git
   ```

2. Include `dynamic_array.h` in your C project:

   ```c
   #include "dynamic_array.h"
   ```

3. Compile your project with the library files.

## Usage

Here’s a quick example of how to use the Dynamic Array in your C code:

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

## API Reference

_For detailed documentation, refer to the [API Reference](API_REFERENCE.md)._

## Contributing

Contributions are welcome! Fork the repository and submit a pull request for any enhancements or bug fixes. For major changes, please open an issue first to discuss the proposed changes.
