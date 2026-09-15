# A declared struct local folds to sp-relative, a cast byte buffer keeps the pointer

summary: when a stack scratch object's address is passed to a call and then
read back, declaring it as the struct folds the read to `[sp, #off]` while
declaring it as a byte array and casting keeps the read on the register that
already holds the address; binding `&obj` to a pointer local does not change
it, only the storage declaration does.

Found in: `src/matched/func_02046084.c` (0x02046084)

When a stack scratch object's address is handed to a call and then read back,
the two obvious spellings do not compile to the same thing. Declare it as the
struct and the read folds into the frame pointer; declare it as a raw byte
array and cast, and the read goes through the register that already holds the
address.

```c
struct Hdr h;                        u8 h[12];
p = &h;                              p = (struct Hdr *)h;
read(stream, 12, p);                 read(stream, 12, p);
n = p->count;                        n = p->count;
```

```
add r6, sp, #4                       add r6, sp, #4
...                                  ...
ldrh r1, [sp, #4]        <- folded   ldrh r1, [r6]
```

Binding the address to a pointer local first does **not** stop the fold: the
compiler propagates `&h` through the local and still addresses the object off
`sp`. The declared type of the storage is what decides it.

## Worked case

`func_02046084` reads a twelve-byte archive header onto the stack, uses its
language count to size an allocation, then copies the stack image into the
front of that allocation. Everything about the function matched first try
except one instruction:

```
  * +0038    ldrh r1, [r6]     |    ldrh r1, [sp, #4]
```

Two bytes, in a 140-byte function with six resolved relocations. Ruled out
before the buffer spelling: binding `&hdr` to a pointer local and using it
everywhere (unchanged), reading through an explicit `*(u16 *)hp` (unchanged),
and marking the pointer `volatile` (much worse, 148 bytes). Changing the
declaration from `struct MsgFileHdr hdr;` to `u8 hdr[12];` with a cast fixed
it outright.

## Why it is not just cosmetic

The fold also changes the frame: an `sp`-relative access has no dependency on
the register holding the address, so the scheduler is free to sink or hoist
it, and with three or more uses the address may stop being materialised into a
callee-saved register at all. If the original keeps a register pointing at the
scratch and yours does not, this is the first thing to try.

## Rule

Match the storage declaration to the addressing mode in the original. Register
addressing (`[r6]`, `[r6, #off]`) on a stack object whose address was passed
to a call means a cast buffer; `sp`-relative addressing means the struct was
declared directly. Do not spend the attempt on pointer locals or casts at the
use site: neither moves it.
