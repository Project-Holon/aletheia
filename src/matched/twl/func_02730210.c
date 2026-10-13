/*
 * function: MIi_GetWramBank_A
 * address:  0x02730210
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

u32 MIi_GetWramBank_A(u32 a)
{
    return *(u8 *)(a + 0x04004040);
}
