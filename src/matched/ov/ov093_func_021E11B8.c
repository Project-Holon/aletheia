/*
 * function: func_021E11B8
 * address:  0x021E11B8
 * packet:   pkt_ov093_021E11B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021E112C  0x021E112C  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 */

typedef unsigned char u8;

extern int func_021D775C(int key);
extern u8 func_021E112C(int *a, u8 *p1, u8 *p2);
extern void func_021C83DC(void *p, int x);

void func_021E11B8(int a, void *b, int c)
{
    if (c == func_021D775C(2))
        func_021C83DC(b, func_021E112C(b, 0, 0));
}
