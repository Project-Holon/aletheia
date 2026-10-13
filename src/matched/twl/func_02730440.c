/*
 * function: MIi_GetAddress_B
 * address:  0x02730440
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_GetWramMapStart_B 0x027303C4 arm twl
 */
typedef unsigned int u32;

extern u32 MI_GetWramMapStart_B(void);

static u32 MIi_GetAddress_B(u32 a)
{
    return MI_GetWramMapStart_B() + (a << 15);
}
