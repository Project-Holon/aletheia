# A named per-element pointer settles Thumb loop register colours

summary: when a Thumb loop already computes base plus scaled index correctly but swaps the computed element pointer with a constant or moves the counter to r0, bind each element address to a named local before accessing its fields. Inline repeated raw-offset expressions can have the same instruction count and different register allocation.

Found in: src/matched/ov/ov119_func_021DCAD4.c (0x021DCAD4), src/matched/ov/ov119_func_021DCB30.c (0x021DCB30)

Under dsi/1.1p1 -O4,p, the initializer in func_021DCAD4 wrote two fields in each of two slots. This spelling compiled to the right size, with six concrete bytes wrong: the zero lived in r6 and the per-slot pointer in r3, where the image uses r3 and r6 respectively.

```c
for (i = 0; i < 2; i++) {
    *(int *)(p + 0x1048 + i * 4) = 0;
    *(int *)(p + 0x1050 + i * 4) = 1;
}
```

Naming the per-slot pointer is EXACT:

```c
for (i = 0; i < 2; i++) {
    char *d = p + i * 4;
    *(int *)(d + 0x1048) = 0;
    *(int *)(d + 0x1050) = 1;
}
```

An unsigned zero local and unsigned first store did not change the six-byte residue. In func_021DCB30, direct expressions for two copies from q+i*8 into p+i*4 left 27 concrete bytes wrong, all in the two loops. A const source pointer and independent block counters did not improve it. Naming both `const int *s = (const int *)(q + i*8)` and `char *d = p + i*4` in the copy loop, and `char *d = p + j*4` in the fill loop, made the whole function EXACT. The copy loop then holds its counter in r6 and its source pointer in r5, matching the image.

This is a register-allocation tell even when both forms already produce the same additions. For an actual reassociation of the far offset, see pointer-sum-with-a-far-offset-associates-differently.md.
