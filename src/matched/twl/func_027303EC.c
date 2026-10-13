/*
 * function: MI_GetWramMapStart_C
 * address:  0x027303EC
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
typedef unsigned int u32;

u32 MI_GetWramMapStart_C(void)
{
    return ((((*(volatile u32 *)0x0400405C) & 0xFF8) >> 3) << 15) + 0x03000000;
}
