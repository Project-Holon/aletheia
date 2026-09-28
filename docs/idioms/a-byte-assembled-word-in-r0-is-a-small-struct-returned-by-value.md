# A word assembled in r0 from four ldrb of one record is a 4-byte struct returned by value

summary: four `ldrb` off one record pointer, shifted by 8/16/24 and `orrs`-ed into
`r0`, loaded in the order byte 1, 0, 2, 3 with the pool constant at byte 1, is
`return obj->table[i];` for a byte-aligned 4-byte struct. No shift/or expression
reproduces its register allocation.

Found in: src/matched/func_02008A54.c (0x02008A54)

The original:

```
lsls r1, r1, #2
adds r3, r0, r1        ; record pointer in r3
ldr  r1, =0x605        ; byte 1 of the record at +0x604
ldrb r2, [r3, r1]
subs r0, r1, #1
ldrb r0, [r3, r0]      ; byte 0 straight into r0
lsls r2, r2, #8
orrs r0, r2
...                    ; bytes 2 and 3, shifted 16 and 24
```

A 432-shape sweep of hand-written `b1 << 8 | b0 | b2 << 16 | b3 << 24`
spellings (every term order, accumulator or single expression, array or struct
indexing) plus a 1500-compile permuter run sat at 17 bytes out: the record
pointer lands in r0 and the accumulator in r3. The fix is the type, not the
expression: with `struct Rec { u8 a, b, c, d; }` the function is

```c
struct Rec f(struct Obj *obj, int i) { return obj->unk604[i]; }
```

and the compiler's own struct-return packing gives the 1, 0, 2, 3 order and the
r3/r0 allocation. The tell at the call site is a caller that reads `r0` back as
separate byte fields (`and #0xFF`, `lsr #8` ...) right after the `bl`.
