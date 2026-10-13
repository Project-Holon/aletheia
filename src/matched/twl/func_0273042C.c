/*
 * function: MIi_GetAddress_A
 * address:  0x0273042C
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_GetWramMapStart_A 0x027303A4 arm twl
 */
typedef unsigned int u32;

extern u32 MI_GetWramMapStart_A(void);

u32 MIi_GetAddress_A(u32 a)
{
    return MI_GetWramMapStart_A() + (a << 16);
}
