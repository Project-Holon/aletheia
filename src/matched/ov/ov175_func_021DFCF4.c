/*
 * function: func_021DFCF4
 * address:  0x021DFCF4
 * packet:   pkt_021DFCF4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021E0070  0x_021E0070  arm
 *
 * ARM tail jump to the untraced 0x021E0070 block of ov175's data area.
 */

typedef unsigned int   u32;
extern int func_021E0070(u32 *p);

int func_021DFCF4(u32 *a0)
{
    return func_021E0070(a0);
}

