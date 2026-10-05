# A field increment operator reloads the field after a compare

summary: when the original compares a struct field and then loads the same field
again in the next block to add or subtract 1 (`ldrh` twice, no reuse of the compare
register), write the change as `p->f[i].step++;` / `p->f[i].step--;`.  The plain
form `step = step + 1;` reuses the compare load (CSE) and loses the second `ldrh`.

Found in: `src/matched/ov/ov223_func_021BB630.c` (ov223 0x021BB630)

Original, case 1 of a fade state switch:

```
ldrh r1, [r1]        ; step, compared with 0x10
cmp  r1, #0x10
bne  else
...
else:
ldr  r0, [sp, #4]    ; recompute the address
adds r0, r1, r0
adds r0, #0xd6
ldrh r0, [r0]        ; step loaded again
adds r2, r0, #1
```

`p->f[i].step = p->f[i].step + 1;` gives `adds r2, r1, #1` from the compare
register (16 bytes shorter over the two arms).  `p->f[i].step++;` (and `--` in the
other arm) gives the second load and closed the function together with:

- the 0x94-byte slots written as a struct array `p->f[i].field` (not raw
  `p + i*0x94 + K`), so `p + i*0x94` is recomputed from the spilled `p` and offset
  at each access instead of being kept in a register;
- inner-loop accesses written as `p->f[i].src[j]` directly, not through an element
  pointer `e = &p->f[i]` (the original adds the field offset to `p + i*0x94`);
- a signed weight (`int t`) so `/ 16` is the signed `asrs; lsrs #0x1c; adds; asrs`.
- the packed colour written as `A << 10 | (B | C << 5)`: the original computes the
  three channels in the order A, B, C and ORs `(C | B) | A`.
