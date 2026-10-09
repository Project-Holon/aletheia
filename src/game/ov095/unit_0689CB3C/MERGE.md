# ov095 unit_0689CB3C: boundaries left

Each boundary below is a real file boundary for now.

- unit_0689CB3C_p01.c | unit_0689CB3C_p02.c: 132 uncovered bytes, 0x0689CCB4..0x0689CD37: two unmatched thumb leaves
  at 0x0689CCB4 and 0x0689CCF8 (push {r3,r4}; loop over the byte count at +0x42, compare id[i] with r1, test c[i] at +0x30;
  the first stores a[i]+b[i] through r2, the second requires c[i]==1 and stores a[i]). They use the S layout of p01
  (id[6] u32, a[6], b[6] u16, c[6] u8, n at 0x42).
  Round 5 near miss (draft in the r5g03 scratch, vt_q3.c): `for (i = 0; i < p->n; i++) { t = p->id[i]; if (t == id && p->c[i] != 0) { *out = p->a[i] + p->b[i]; return 1; } } return 0;`
  with u32 i and a local t gives the same loop and the same cmp order, but the compiler keeps p->n in r4 across the loop
  (push {r4,r5}, no reload at the bottom test). The original reloads p->n at the bottom (adds r4,r0,#0; adds r4,#0x42; ldrb)
  and needs only r3,r4. A break/result-variable form, void*/int* out, inline getter and do-while forms were tried: no change.
- unit_0689CB3C_p02.c | unit_0689CB3C_p03.c: 16 bytes at 0x0689CDBC: linker veneer (bx pc; ldr ip,[pc]; bx ip; .word). Real boundary.
- unit_0689CB3C_p03.c | unit_0689CB3C_p04.c: 48 bytes at 0x0689CE28: three linker veneers. Real boundary.
