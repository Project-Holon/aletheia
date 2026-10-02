# A halfword arithmetic update keeps a call result wide with explicit assignment

summary: Updating a `u16` through `*p = *p + f()` or `*p = *p * f()` keeps an unsigned word call result wide until `strh`. Compound `+=` or `*=` narrows the call result first with a redundant `lsls #16; lsrs #16` pair.

Found in: src/matched/ov/ov010_func_021597AC.c (0x021597AC), src/matched/ov/ov010_func_021597EC.c (0x021597EC)

Both handlers obtain a halfword pointer, call the two-argument script value
getter, load the halfword into r1, compute into r0 and store with `strh`.
The getter is declared to return `unsigned int`; the original does not
narrow r0 between the call and the arithmetic.

```c
u16 *p = func_02159AE8(a, b);
*p = *p + func_02159B10(a, b);
/* Or: *p = *p * func_02159B10(a, b); */
```

Fixed dsi/1.1p1 `-O4,p` produces EXACT* for both explicit assignments:
30 code bytes followed by two zero alignment bytes. The compound forms
produce 34 bytes and DIFF with 12 differing concrete bytes; the added
shift pair surrounds the halfword load before the arithmetic. S9's
`021597AC-run1.log`/`021597EC-run1.log` and corresponding `run2` logs
record the paired comparisons. No prototype or flag changed.

The OR-update idiom documents the analogous narrowing of a shifted operand,
and the bit-clear idiom documents a narrowed complement mask. Here the
operand is a word returned by a function, and both addition and multiplication
show the same narrowing behavior.
