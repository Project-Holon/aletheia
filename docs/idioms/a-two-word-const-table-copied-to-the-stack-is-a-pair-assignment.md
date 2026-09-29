# A two-word constant table copied onto the stack is a Pair assignment

summary: a stack copy of an 8-byte overlay table (`ldr r1,[r0]; ldr r0,[r0,#4]; str; str` off one pool address, then indexed by `i % 2` through `add r0, sp`) is `Pair t = d_table;` on an `extern const` struct, read back as `((int *)&t)[i % 2]`.

Found in: src/matched/ov/ov029_func_021F1010.c (0x021F1010), src/matched/ov/ov029_func_021F122C.c (0x021F122C)

Both functions open with one pool load of a data address, two word loads from it
and two stores into the frame, then index that stack copy by a signed `i % 2`
(the `lsrs/lsls/subs/rors` sequence):

    typedef struct { int a, b; } Pair;
    extern const Pair d_021F3324;          /* symbols: data a4 */

    Pair t = d_021F3324;
    n = ((int *)&t)[i % 2];

Other spellings:

- `int t[2] = { ... }` with literal values never touches the table's address: the
  compiler emits its own initialiser template, and the pool word stays an
  unresolved `@N` symbol.
- An `ldm rB, {rX, rB}` copy of the table (ov029 0x021F020C) is the same pair
  load with ascending registers; there a `u64` load split into the two words
  gave the `ldm` where the `Pair` copy did not.
- `extern const int d[2]` read element-wise (`t0 = d[0]; t1 = d[1]`) gives a
  separate load/store per element with a different register order, not the
  paired load-both-then-store-both shape (see
  `an-eight-byte-pair-copy-loads-both-words-first.md`).

The struct assignment is the only form that reproduces the copy and keeps the
address as a resolvable `data a4` relocation. In 0x021F122C the loop counter and
the base pointer are also spilled; declare the base before the counter and set
`i = 0` before the base assignment to get `i` at [sp] and the base at [sp,#4].
