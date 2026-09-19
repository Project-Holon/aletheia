# A subscript whose index is a sum lands wherever the source groups the sum

summary: `base[off + i]` and `t = base + off; t[i]` are the same address, but
the first associates the index (`off + i`) and then indexes `base`, the second
adds to the pointer first and indexes with `i` -- and the two emit `add r0,
r0, sl` / `ldrb r0, [r1, r0]` versus `add r0, r1, r0` / `ldrb r0, [sl, r0]`.
Two bytes of diff, but the register pair decides which is which.

Found in: `src/matched/func_02046300.c` (0x02046300)

The original's tail

```
02046370  e5901000  ldr  r1, [r0]        ; hdr = g->data
02046374  e5910004  ldr  r0, [r1, #4]    ; hdr[1]
02046378  e0810000  add  r0, r1, r0      ; hdr + hdr[1]  -- the pointer is
0204637c  e7da0000  ldrb r0, [sl, r0]    ; indexed by idx last
```

is produced by

```c
u8 *t = (u8 *)g_02146A58->data + ((u32 *)g_02146A58->data)[1];
out[0x20] = t[idx];
```

Writing it as one subscript over the same global

```c
out[0x20] = ((u8 *)g_02146A58->data)[((u32 *)g_02146A58->data)[1] + idx];
```

gives the commuting pair instead

```
add  r0, r0, sl
ldrb r0, [r1, r0]
```

which is the same address computed as `(hdr + (off1 + idx))` with `hdr` as the
base. Nothing else about the function changes: same size, same loads, same
order of the two global reads. The tell is which register the `ldrb` uses as a
base -- the loop index register means the pointer sum was computed first.

This is the pointer-arithmetic form of
`commutative-operand-order-names-the-temporary.md`: there, `a + b` versus
`b + a` named the temporary; here the grouping inside a subscript decides which
half of the address lands in the base register.
