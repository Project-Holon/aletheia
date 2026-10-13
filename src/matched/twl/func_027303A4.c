/*
 * function: MI_GetWramMapStart_A
 * address:  0x027303A4
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
typedef unsigned int u32;

u32 MI_GetWramMapStart_A(void)
{
    return ((((*(volatile u32 *)0x04004054) & 0xFF0) >> 4) << 16) + 0x03000000;
}
