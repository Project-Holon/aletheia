# An unsigned loop counter emits `blo`, a signed one `blt`

summary: The bound compare at the bottom of a counted loop encodes the
counter's signedness, so `blt` versus `blo` says whether the C declared `int`
or `unsigned`.

Found in: src/matched/func_021B7604.c (0x021B7604), src/matched/func_021B77C4.c (0x021B77C4)

Both functions are the same shape: a small counted loop that calls a per-slot
cleanup with the index.

```c
void func_021B7604(int *p)
{
    int i;
    for (i = 0; i < 0x21; i++)
        func_021B75E8(p, i);
}
```

compiles the bottom test to a *signed* branch, `blt`, and the two-byte
encoding at `+0012` does not reproduce the original's `blo`:

```
+0012    blo #0x21b760a     |    blt #0x21b760a
```

Declaring the counter `unsigned int` flips exactly that opcode and leaves the
rest of the loop, push/pop and increments, identical:

```c
void func_021B7604(int *p)
{
    unsigned int i;
    for (i = 0; i < 0x21; i++)
        func_021B75E8(p, i);
}
```

The bound constant gives no clue -- `0x21` is positive either way -- so the
branch opcode is the only evidence, and it is easy to read past because the
verdict comes back `DIFF` with a single concrete byte. Whenever a counted loop
in the original ends in `blo`/`bhi`/`bhs` rather than `blt`/`bgt`/`bge`, the
counter (or the compare's other operand) is unsigned.
