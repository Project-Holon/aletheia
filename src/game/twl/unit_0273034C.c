/*
 * file:     unit_0273034C.c
 * unit:     yes
 * function: func_0273034C, func_02730360, func_02730374
 * address:  0x0273034C
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Hidden functions written from the bytes (no src/matched file).
 */

typedef unsigned char u8;
typedef unsigned int u32;

/* Register readers: the argument is a register-block base, the mask picks the field. */
u32 func_0273034C(u32 a)
{
    return *(u8 *)(a + 0x04004040) & 1;
}


u32 func_02730360(u32 a)
{
    return *(u8 *)(a + 0x04004044) & 3;
}


u32 func_02730374(u32 a)
{
    return *(u8 *)(a + 0x0400404C) & 3;
}
