/*
 * function: func_021FD6DC
 * address:  0x021FD6DC
 * packet:   pkt_021FD6DC
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021FCEA8  0x021FCEA8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern void func_021FCEA8(int unused, int kind, u32 value, u32 id);

void func_021FD6DC(char *p)
{
    func_021FCEA8((int)p, 5, *(int *)(*(int *)(p + 0x140) + 0x24), 0xff);
}
