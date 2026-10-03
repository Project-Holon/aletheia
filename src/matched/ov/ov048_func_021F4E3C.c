/*
 * function: func_021F4E3C
 * address:  0x021F4E3C
 * packet:   pkt_021F4E3C
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020111E8  0x020111E8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern u32 func_020111E8(void);

int func_021F4E3C(int *p)
{
    if (p[0] == 0)
        return 1;
    if (p[0] == func_020111E8())
        return 1;
    return 0;
}
