# A table slot spelled with a subscript keeps the table base in its own register; the byte-offset spelling folds it away

summary: `a[i + 1]` on an `int *` table reproduces the image's register split
(table base in one register, the scaled index added fresh each pass);
`*(int *)((char *)a + 4 + i * 4)` folds `a + 4` into a base register and
rotates every occurrence, a pure register diff with no byte-count change.

Found in: src/matched/func_021F89D0.c (0x021F89D0),
src/matched/func_021EEFA4.c (0x021EEFA4)

A small loop walks a fixed-stride table living at a constant offset from a
pointer parameter. The two obvious spellings of "the i-th slot" are not the
same code:

```c
/* rotates the loop's registers: a+4 is pre-folded into a base */
func_021FB494(*(int *)((char *)a + 4 + i * 4));
*(int *)((char *)a + 4 + i * 4) = 0;
```

versus

```c
/* image shape: table pointer stays put and a+i*4+4 is recomputed */
func_021FB494(a[i + 1]);
a[i + 1] = 0;
```

In `func_021F89D0` the byte-offset form leaves the table base in `r4`, the
index in `r5` and the zero in `r7`; the subscript form puts the base in `r6`,
the index in `r4` and the zero in `r7`, matching the image byte for byte. The
blocker read as "register allocation, the original recomputes `a + i*4 + 4`",
which is exactly the tell: the subscript is what forces the recompute. The
same switch closed `func_021EEFA4`, whose table sits at `a + 0x24`: typing the
parameter `int *a` and writing `a[9 + i]` (0x24/4 = 9) replaced the byte-offset
`*(int *)(a + 0x24 + i * 4)`.

Two details matter and are easy to miss:

- The parameter has to be the element type (`int *a`), not `int a`; the
  subscript scales by `sizeof(int)` for free. Changing the parameter's type
  does not change the ABI, so it is safe.
- This is a *shape* lever, not a signedness or const lever: `volatile`,
  pointer typedefs and `a[i] + ...` sub-expressions all land back on the folded
  form. When the only residue is a run of register numbers around a table
  access, reach for the subscript before anything else.

The sibling `declaration-order-decides-which-register-a-local-gets` covers the
rest of the residue when two locals also swap: here `char *base` declared
before `unsigned int i` is what pinned the remaining pair in `func_021EEFA4`.
