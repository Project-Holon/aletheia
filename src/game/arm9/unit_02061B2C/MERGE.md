# unit_02061B2C (arm9)

3 files remain (was 6), all EXACT.

- `unit_02061B2C_p01.c`: func_02061B2C .. func_02061C30 (compiler ../2.0/sp2)
- `unit_02061B2C_p02.c`: func_02061C44 .. DWCi_TSKlForm (compiler 1.1p1)
- `unit_02061B2C_p03.c`: func_02061EB8 .. func_020625D8 (compiler ../2.0/sp2; old p03..p06 merged in round w10d)

Round w10d: one struct Cfg for g_02146B94 (two symbols at one address kept, the image has two pool words),
one struct HeapB for g_02146BB0, func_02061FF8 takes (u32 *, u32 *) everywhere.

Boundaries left: p01|p02 and p02|p03 change compiler (2.0 / 1.1p1). Re-tested in w10d: p01+p02 is DIFF in
both orders. Real.
