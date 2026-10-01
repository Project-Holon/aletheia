# A counter initialized before a byte bound recolours the bound address

summary: when a Thumb byte-index search matches except for the scratch register used to address and load a byte bound, assigning the counter before loading the bound can change that scratch register without adding instructions.

Found in: `src/matched/ov/ov208_func_021BDB08.c` and `src/matched/ov/ov208_func_021BDB54.c`.

Both searches read the count byte at offset 0x68 and index eight-byte slots at 0x6c. The winning spelling is:

```c
i = 0;
count = p->count;
for (; i < count; i++) {
    /* search the slots */
}
```

Loading `count` first and initializing `i` in the `for` header left three concrete bytes wrong in 021BDB08: the count address and load used r2 instead of r3. Changing the bound from a byte local to unsigned, making the parameter const, and spelling the bound as a struct field left the same three bytes. Initializing the counter first gave EXACT* (74 instruction bytes plus two zero padding bytes). Applying that spelling to the twin 021BDB54 gave EXACT* on its first compile.

This case has a register-resident bound and no zero pool or spilled row offset. It differs from the counter-before-bound pool idiom and the counter-before-offset-spill idiom. One statement-order variant solved it; do not sweep declaration permutations.
