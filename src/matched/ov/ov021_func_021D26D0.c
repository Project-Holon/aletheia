/*
 * function: func_021D26D0
 * address:  0x021D26D0
 * packet:   pkt_ov021_021D26D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_021D26AC  0x021D26AC  thumb  ov021
 *   func_021D25E8  0x021D25E8  thumb  ov021
 *   func_020452E8  0x020452E8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_020362DC(void);
extern int func_021D26AC(u32 *a);
extern void func_021D25E8(u32 *p);
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);

u32 func_021D26D0(u32 a, u32 *st, u32 *p)
{
    switch (st[0]) {
    case 0:
        if (func_020362DC() & 3) {
            func_021D26AC(p);
            func_021D25E8(p);
            st[0]++;
        }
        break;
    case 1:
        func_020452E8((struct Descriptor *)p[0]);
        return 1;
    }
    return 0;
}
