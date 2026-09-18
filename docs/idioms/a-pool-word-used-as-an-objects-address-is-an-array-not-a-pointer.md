# A pool word used as an object's address must be declared as an array, not a pointer

summary: when a pool word holds the address of a data object and the code
dereferences it at an offset, declaring the extern as `T *x` costs an extra
`ldr` (the pointer is loaded from the pool and then *its* value is loaded),
while `extern T x[]` makes the pool word the object's address and the access
compiles to the original's single load or store; a function-pointer pool word
used as a value has the same shape, `(u32)func_XXXXXXXX` with the function
declared normally.

Found in: `src/matched/func_020379C8.c` (0x020379C8)

The original ends

```
020379DC  ldr r0, [pc, #0x54]     ; pool word 0x020A7A20
020379E0  mov r1, #4
020379E4  strb r1, [r0, #1]       ; store to 0x020A7A21
```

Written as

```c
extern char *g_020A7A20;
...
*(u8 *)(g_020A7A20 + 1) = 4;
```

the compiler emits two loads - one to fetch the pointer from its own slot in
the pool, one to fetch the byte it points at - and the function comes out four
bytes too long (128 against the original's 124), with every address after the
store shifted by one instruction. Written as

```c
extern u8 g_020A7A20[];
...
g_020A7A20[1] = 4;
```

the pool word *is* the object's address and the store is the single
`strb r1, [r0, #1]` the original has. The tell is that the pool word appears in
the disassembly as the base register of the access with no load between the
`ldr rX, [pc, ...]` and the store: a pointer would have to be dereferenced
first, and a pointer to a pointer is what the extra `ldr r0, [r0]` in the
compiled listing means.

The same file carries the second half of the pattern, a pool word that holds
*code* rather than data (0x02037858 and 0x02038924): there the extern is an
ordinary function declaration and the use is `(u32)func_02037858`, which emits
the `R_ARM_ABS32` the linker fills with the function's address. Declaring those
as `u32` variables instead would put a load in the pool word's place and lose
the relocation.

Related: the companion register-assignment tell in the same function - with
`char *c = func_0203D788();` declared before `int r;`, the parameter landed in
r5 and the call result in r4, exactly reversed from the original's r4/r6 pair;
moving the `int r;` declaration above the initialised pointer fixed the whole
function to EXACT with no other change. When a function is right but every
register is rotated by one, try the declaration order of the call-bound
temporaries before anything else.
