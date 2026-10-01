# A byte local's signedness flips which callee-saved register it gets

summary: when a small function differs from the image only by a swap of two
callee-saved registers held by a byte local and a long-lived pointer, and every
declaration order is flat, try changing the byte local from `unsigned char` to
signed `char` (or the reverse) before calling it an allocator tie: 1.1p1 colours
the two webs by the local's signedness, and one sign reproduces the vendor's
pair on the nose.

Found in: src/pending/ov_sdk/ov009_func_0217D280.c (0x0217D280, GameSpy
`HexEncode16`), 9 B DIFF, permuter- and declaration-sweep-flat.

The function keeps a long-lived output cursor `aTextOutStream` and the byte
`aChar` read each iteration. The image gives the cursor `r6` and the byte `r7`;
1.1p1 gives the other way round for every declaration order, every block-scope
or initialiser spelling, and the true vendor source (that object is a
4.0.0.1025 front end whose allocator reverses the tie for this shape).

What no prior lane tried was the byte's *type*. Writing

```c
char aChar = (*theInStream++);          /* signed, no cast */
```

reproduces the image's assignment exactly — cursor `r6`, byte `r7` — and the
byte count falls from 9 to 6. The 6 that remain are consequences of the sign,
not of the allocation: the load becomes `ldrsb` where the image has `ldrb`, and
the `isgraph` expansion's predicate codes become `movge/lsllt/ldrhlt/andlt`
where the image has the unsigned `movhs/lsllo/ldrhlo/andlo`. The image's codegen
is unsigned, its allocation is the signed one, and 1.1p1 will not give both:

```
char aChar                     6 B  (r6/r7 right, ldrsb + signed preds)
unsigned char aChar            9 B  (r7/r6 wrong, ldrb + unsigned preds)
(char)(unsigned char)(...)    94 B
(const unsigned char *)ptr     6 B  (still ldrsb)
(unsigned int)char in cond   103 B  (mask/sign-extend materialised)
-char unsigned                 9 B  (plain char == unsigned char)
```

`int`, `unsigned short`, `register`, `signed char *aTextOutStream`, and
decoupling the cursor's declaration from its definition are all flat or worse.

The rule to carry forward: a register-pair tie on a byte local is worth one
signedness flip per direction before it is written off, and the flip is
*diagnostic* even when it does not close — if the allocation snaps into place
but `ldrb`/`ldrsb` and the predicate codes swap with it, the target object was
built by a front end that ordered the two webs differently and the tie is not
reachable from source under the mandated compiler.
