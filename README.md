# Linux-Style Heap Memory Manager in C

This project implements a simplified Linux-style memory manager in C, simulating the behavior of `malloc()` and `free()` using a custom heap layout, metadata structures, and internal block linking logic. It allows dynamic memory allocation and deallocation for user-defined data structures at runtime.

---

##  Features

- Custom heap block allocation with size metadata
- Free block reuse to minimize fragmentation
- Runtime memory tracking and leak detection
- User-defined data structure support via `css.h`
- Linked block management via custom glue thread logic

---

##  How It Works

At the heart of the project is a memory manager that:
- Initializes a fixed-size heap
- Allocates memory using metadata headers
- Maintains free/used block lists
- Simulates `malloc()` and `free()` behaviors
- Supports user-defined objects via metadata descriptors

The file `mm.c` implements internal allocation logic, while `testapp.c` shows how the manager can be used like a real allocator.

---

##  How to Build and Run

### Step 1: Compile

Use `gcc` to compile the project from the root folder:

```bash
gcc mm.c gluethread/glthread.c testapp.c -o memory_manager
```

> Make sure you're inside the `LinuxMemoryManager` folder after unzipping.

---

### Step 2: Run the test app

```bash
./memory_manager
```

This runs `testapp.c`, which creates and allocates memory for user-defined objects using your custom allocator.

---

## 📁 File Structure

```
LinuxMemoryManager/
├── mm.c                 # Core heap memory manager logic
├── mm.h                 # Public declarations for mm.c
├── css.h                # Custom structure system definitions
├── uapi_mm.h            # User-facing API for memory allocation
├── testapp.c            # Sample test application using the memory manager
├── gluethread/
│   ├── glthread.c       # Internal block/thread linking logic
│   └── glthread.h
```

---

##  Concepts Demonstrated

- Manual heap management
- Simulated metadata headers
- Memory fragmentation and block merging
- Pointer arithmetic
- Struct layout introspection
- Threaded memory block traversal

---

##  Sample Output (From `testapp.c`)

```
Initializing memory manager...
Memory allocated for object EMPLOYEE
Object fields:
Name: John Doe
Age: 30
...
Memory manager shutting down. Cleaning up heap.
```

---

##  Why This Matters

This project mimics low-level system memory allocation without relying on standard `malloc/free`, making it perfect for:
- OS-level memory simulation
- Embedded systems
- Compiler/runtime internals
- Interview prep on memory management

---
