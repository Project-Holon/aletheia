/*
 * file:     unit_02730210.c
 * unit:     yes
 * function: func_02730210, func_02730220, func_02730230, func_02730240, func_0273025C, func_02730278
 * address:  0x02730210
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

/* Register accessors: the argument is a register-block base. */
u32 func_02730210(u32 a)
{
    return *(u8 *)(a + 0x04004040);
}


u32 func_02730220(u32 a)
{
    return *(u8 *)(a + 0x04004044);
}


u32 func_02730230(u32 a)
{
    return *(u8 *)(a + 0x0400404C);
}


void func_02730240(u32 a, u32 v)
{
    *(u8 *)(a + 0x04004040) = (*(u8 *)(a + 0x04004040) & ~1) | v;
}


void func_0273025C(u32 a, u32 v)
{
    *(u8 *)(a + 0x04004044) = (*(u8 *)(a + 0x04004044) & ~3) | v;
}


void func_02730278(u32 a, u32 v)
{
    *(u8 *)(a + 0x0400404C) = (*(u8 *)(a + 0x0400404C) & ~3) | v;
}
