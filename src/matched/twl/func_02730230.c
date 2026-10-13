/*
 * function: MIi_GetWramBank_C
 * address:  0x02730230
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;

u32 MIi_GetWramBank_C(u32 a)
{
    return *(u8 *)(a + 0x0400404C);
}
