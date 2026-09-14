# `*(p + n - 1)` and `p[n - 1]` are different code, and the original says which

summary: the subscript form folds the subtraction into the index and scales
once, `subs`/`lsls`/`strh` with a register offset; the pointer form scales `n`,
adds it to the base and then subtracts the element size, `lsls`/`adds`/`subs
#2`/`strh` with no offset, so the three instructions that reach the last
element of an array name the spelling the source used.

Found in: `src/matched/unit_0201F41C.c` (0x0201F41C)

`func_0201F41C` is a bounded wide-string copy that always terminates its
destination.  The terminating store is the last four instructions:

```
0201F43E  lsls r1, r4, #1       /* n * 2 */
0201F440  adds r1, r5, r1       /* dst + n */
0201F442  subs r1, r1, #2       /* ... minus one element */
0201F444  strh r0, [r1]
```

The obvious spelling produces three instructions and a register-offset store:

```c
dst[n - 1] = eos;        /* subs r1, r4, #1 ; lsls r1, r1, #1 ; strh r0, [r5, r1] */
```

which is seven concrete bytes wrong and two bytes short.  All three pointer
spellings give the original:

```c
*(dst + n - 1) = eos;
*((dst + n) - 1) = eos;
(dst + n)[-1] = eos;
```

The reason is where the constant folding happens.  In `dst[n - 1]` the index
expression `n - 1` is an integer computation the compiler finishes before
scaling, so there is one `lsls` and the base can stay in the store's register
offset.  In `*(dst + n - 1)` the `+ n` and the `- 1` are two separate pointer
adjustments; the compiler scales each one as it goes and only the second is a
constant it can fold into an immediate, which is why the `subs #2` survives as
its own instruction and the store loses its offset.

The reverse reading is the useful one and it is mechanical: **a load or store
whose address is built by scaling, adding and then subtracting the element size
was written as pointer arithmetic, and one that scales a decremented index was
written as a subscript.** Two bytes and one instruction apart, with the same
registers and the same value, so nothing else in the function distinguishes
them.
