# A halfword OR update casts the whole expression, not the shifted operand

summary: For a variable shifted bit ORed into a `u16`, `field = (u16)(field | (1 << index))` keeps the shift at int width until the final store. `field |= 1 << index` narrows the shifted operand first, adding a `lsls #16; lsrs #16` pair and changing instruction scheduling.

Found in: docs/notes/pkt_ov010_02162230.c.txt (0x02162230, byte experiment with a domain proof gap), src/matched/ov/ov010_func_02162278.c (0x02162278)

Both functions update the flags halfword at offset 2. The original loads the
halfword, shifts an int-width one, ORs the values, and stores with `strh`.
There is no truncation pair between the variable shift and the OR.

This spelling assumes a proven nonnegative count at most 30 for the signed
`1` shift and a valid destination object; it does not define ARM register
shift behavior for arbitrary counts. For these eight-byte record slots,
the intended object-bound index range is 0..2. `func_02162120` proves that
range for `func_02162278`: r4 starts at zero at 0x0216212A, is incremented
at 0x02162188 and compared with three at 0x0216218A before looping. Its
shift count is therefore 5..7. The setter `func_02162230` has only a
u16-narrowed callback argument in the inspected ov011 path; that alone
does not establish a valid shift count or object-bound index. Its byte
comparison is an experiment, not a proof of that caller's input domain.

```c
*(u16 *)(p + 2) = (u16)(*(u16 *)(p + 2) | (1 << index));
```

For the second function the index is `index + 5`; the same whole-expression
cast applies. The compound form adds a truncation pair on the shifted one.
It also moves the load in the first function and delays the preceding final
record store in the second.

With fixed dsi/1.1p1 `-O4,p`, Wave49 S17 logs `02162230-one-1.log` and
`02162278-one-1.log` show 14 and 22 concrete differing bytes respectively.
Changing only the update expression gives EXACT* in both `one-2` logs;
their remaining two extent bytes are zero alignment padding. See also
`a-u16-cast-over-the-whole-register-update-keeps-the-full-complement-mask.md`
for the analogous constant-mask narrowing in a hardware register update.
