# A redundant second assignment keeps an offset local out of the temp slots

summary: a local assigned once from a cheap expression (`off = idx * 4`) is
folded into a compiler temporary, and spilled temporaries take stack slots
above every spilled named local. When the image has that value in the lowest
spill slot, assign it a second time with the same expression in a branch that
does not change it; the local then keeps its own slot and obeys declaration
order (last declared lowest).

Found in: src/matched/ov/ov021_func_021B38E0.c (0x021B38E0)

The image spills three values: the table offset `idx * 4` at sp+4, the
allocation `q` at sp+8 and the count `n` at sp+0xc. Every spelling with one
assignment of the offset (named local, parameter reuse, inline helper,
array or struct local, `const`, `<<`, assignment inside the call argument)
compiled to the same code with the offset at sp+0xc: it became a temporary,
placed after the named locals `n` and `q`.

Observed slot order, low to high:

1. locals created by inline expansion (later expansion lower),
2. named locals, last declared lowest,
3. compiler temporaries (CSE results, constants), in creation order.

Giving the offset a second, redundant definition stops the fold:

```c
off = idx * 4;
if (func_02021288(**(u16 **)((char *)d_021DE1A8 + off))) {
    *(u8 *)(p + 354) = 1;
    off = idx * 4;          /* no code: CSE'd, but off stays a local */
}
```

with `int n;` declared before `q` and `int off;` declared last. EXACT. The
second assignment emits nothing.

Assigning the offset in both arms of the earlier if/else (where `idx` is
chosen) also keeps it a local, but the spill store is then tail-merged above
the pool load and the first use reloads it (2 extra instructions).
