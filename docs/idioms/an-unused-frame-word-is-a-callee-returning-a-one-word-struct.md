# An empty frame word with no stack traffic is a call returning a one-word struct

summary: a Thumb function that opens `push {r3, ...}; sub sp, #4` but never
touches `[sp]` is calling something that returns a 4-byte struct by value;
declare that callee's return (and the field it lands in) as a one-word struct
and the frame word appears. Dead locals, `(void)&x`, arrays and struct locals
are all optimised away and do not reserve it.

Found in: src/matched/ov/ov093_func_021DF5F4.c (0x021DF5F4)

The original stores the result of `bl func_021E8A58` straight into a record
(`str r0, [r4, #8]`), yet the prologue is `push {r3, r4, r5, r6, lr}; sub
sp, #4` and nothing is ever stored at `sp`. With `int func_021E8A58(void)`
every other byte matched and only the frame differed (`push {r4, r5, r6,
lr}`, no `sub`). Tried and refused: an unused `int`, `int[1]`, a struct local,
a `char[4]`, an address-taken local. Declaring

```c
typedef struct Word { unsigned int v; } Word;
extern Word func_021E8A58(void);
...
r->f08 = func_021E8A58();   /* f08 declared Word */
```

gives EXACT: mwcc reserves a temporary for the struct return, then forwards
r0 and never uses the slot. The same shape is in ov093's func_021D6130 and
func_021D61F0 (`func_021E8918` returns a bitfield union by value).
