# A far offset before the index keeps the base and index separate across calls

summary: For adjacent far fields, inline `(u32)p + K + (u32)n * 8` keeps p, the scaled index and K in separate saved registers; `(u32)p + (u32)n * 8 + K` caches the base-plus-index sum and shortens the function.

Found in: src/matched/ov/ov180_func_021B7798.c (0x021B7798), src/matched/ov/ov180_func_021B77DC.c (0x021B77DC).

Both originals keep p in r5, n*8 in r4 and one far offset in r6. Before each call they compute p+n*8 afresh, load through the offset, and derive the neighbouring field offset by adding or subtracting four.

The matching form is:
```c
*(void **)((u32)p + 0x9120 + (u32)n * 8)
*(void **)((u32)p + 0x9124 + (u32)n * 8)
```

Putting the scaled index before K makes mwcc hold p+n*8 as one saved value. In 021B7798 that form compiled 36 bytes with 34 concrete bytes different from the 44-byte original. In 021B77DC it compiled 52 bytes with 47 concrete bytes different from the 56-byte original. Both the pointer arithmetic and fully unsigned address arithmetic forms had these same differences.

Moving only K before the scaled index made both EXACT under dsi/1.1p1 -O4,p Thumb c99. The unsigned spelling retains full-word modular address arithmetic.

This complements parenthesise-the-offset-sum-base-plus-index-plus-constant.md: the association chosen before repeated accesses controls which partial sum mwcc caches, even when the final effective addresses are identical.
