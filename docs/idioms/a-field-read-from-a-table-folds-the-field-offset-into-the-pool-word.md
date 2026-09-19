# A field read from a table folds the field offset into the pool word, not into the load

summary: `&tbl[i].b` where `b` sits at +2 of a four-byte record is not
`ldrh rD, [base + i*4 + 2]`; mwccarm puts the *base plus two* in the pool word
and keeps `[rB, rI]`, so the pool word holds `tbl + 2` and not `tbl`.  Reading
the same bytes through a `u16[]` indexing trick gives the same instruction and
the wrong pool word, which caps the function at MATCH forever.

Found in: `src/matched/func_0200E124.c` (0x0200E124, `pkt_0200E0BC`)

The table is two `u16` keys in a four-byte record, and the function reads the
second one:

```
0200E130  81 00        lsls r1, r0, #2        ; ret * 4, one record
0200E132  0a 48        ldr r0, [pc, #0x28]    ; <<< the pool word
0200E134  46 5a        ldrh r6, [r0, r1]      ; the b field, no +2 immediate
...
0200E15C  92 de 09 02  .word 0x0209DE92       ; table + 2, i.e. &tbl[0].b
```

Written as `extern u16 g[]; ... g[i * 2]` the compiler emits the identical
three instructions but pools `0x0209DE90`, one byte pair away from the
original: the pool word's low byte is the whole difference, and the function
comes out MATCH (the relocation field is wildcarded, every concrete byte
right).  Written as `g[i * 2 + 1]` for the same element it gives 68 bytes of
code instead of 64, because the +2 has to be added at run time somewhere.

The spelling that reproduces it is the struct, so the field offset is a
constant the front end is free to fold into the address constant:

```c
struct Rec { u16 a; u16 b; };
extern struct Rec g_0209DE90[];

u32 hi = g_0209DE90[func_0200E0BC(idx)].b;
```

Three consequences worth carrying to the next table read.

**The pool word is a claim about which field was read.** 2 in a pool word is as
falsifiable as any other byte: it is the difference between `.a` and `.b`, and
a relocation that resolves one byte-pair off cannot be made to resolve by any
amount of register or scheduling work.

**`&tbl[i].f` and `tbl[i * k + j]` are not interchangeable spellings.**  When
the array element is a record, the struct spelling is the one that lets the
fold happen; the flat-array spelling asks the compiler to prove a fixed offset
into a variable index, and it answers by doing the arithmetic in a register.

**A companion lever is the temporary that keeps pointer maths opaque.**
`u32 *o = obj;` and then `o + (idx + 1)` is the same address as
`obj + idx + 1`, but the second lets mwcc strength-reduce it to
`(obj + idx) + 4`, which reorders the whole argument set-up.  That single
difference was worth 11 of the 12 remaining bytes in the same function.
