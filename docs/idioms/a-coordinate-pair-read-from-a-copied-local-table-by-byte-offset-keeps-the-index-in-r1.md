# A coordinate pair read from a copied local table by byte offset keeps the index in r1

summary: when a loop copies x/y from a stack copy of a short-pair table into a create record, member access `t.pos[i].x` / `t.pos[i].y` gives the `i*4` temp r0 and the y address r1; the original's `i*4` in r1 and y in r0 come from reading the pair through byte offsets of the table.

Found in: src/matched/ov/ov119_func_021E6CB8.c (0x021E6CB8).

The table is a 32-byte, 2-aligned extern copied to the stack (the halfword copy loop), then read once per iteration:

```c
Table t = d_021E7E64;
...
for (i = 0; i < 8; i++) {
    c.x = *(short *)((char *)&t + i * 4); c.y = *(short *)((char *)&t + i * 4 + 2); c.z = 0; c.a = 0; c.b = 1;
    *(int *)(p + i * 4 + 0x10cc) = func_0204B294(..., *(int *)(p + i * 4 + 0x1114), ..., &c, 1, heap);
    ...
}
```

Original: `lsls r1,r4,#2; add r2,sp,#0x34; ldrsh r2,[r2,r1]; add r0,sp,#0x34; adds r0,r0,r1; ... ldrsh r0,[r0,r2]`, with the 0x1114 pool load in r1 right after `adds r6,r5,r1` and `&c` built late in r0.

Every member spelling (`t.pos[i].x`, a `Pt *` local, a `short v[8][2]` member, swapped declaration order, a separate counter, a `const` local, `u16` record fields) gave the same 20-byte residue: the same instructions with r0 and r1 exchanged for the index temp and the y value. A flat `short v[16]` indexed `v[i*2]`, `v[i*2+1]` was worse (58 bytes). The byte-offset casts closed it with no other change.

Try this when a loop reading a local table copy is byte-correct except for an r0/r1 exchange around the `lsls` of the index.
