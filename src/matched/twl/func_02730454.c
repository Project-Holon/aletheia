/*
 * function: MIi_GetAddress_C
 * address:  0x02730454
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_GetWramMapStart_C 0x027303EC arm twl
 */
typedef unsigned int u32;

extern u32 MI_GetWramMapStart_C(void);

static u32 MIi_GetAddress_C(u32 a)
{
    return MI_GetWramMapStart_C() + (a << 15);
}
