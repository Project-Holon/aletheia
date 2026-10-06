/*
 * function: func_021DFCE8
 * address:  0x021DFCE8
 * packet:   pkt_021DFCE8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021E0040  0x_021E0040  arm
 *
 * ARM tail jump to the untraced 0x021E0040 block of ov175's data area.
 */

typedef unsigned int   u32;
extern int func_021E0040(u32 *p);

int func_021DFCE8(u32 *a0)
{
    return func_021E0040(a0);
}

