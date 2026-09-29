/*
 * function: func_021A20C8
 * address:  0x021A20C8
 * packet:   pkt_ov021_021A20C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A2724  0x021A2724  thumb  ov021
 *   func_021A2924  0x021A2924  thumb  ov021
 *   func_021A28A0  0x021A28A0  thumb  ov021
 *   func_021A284C  0x021A284C  thumb  ov021
 *   func_021A26D8  0x021A26D8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct O {
    u32 pad0[8];
    u32 *f20;
    u8  pad24[2];
    u8  f26;
} O;

extern void func_021A2724(O *p, u32 v, int z);
extern void func_021A2924(O *p);
extern void func_021A28A0(O *p);
extern void func_021A284C(O *p);
extern void func_021A26D8(O *p);

void func_021A20C8(O *p)
{
    if (p->f26 == 0) {
        return;
    }
    if (p->f26 <= 0xb) {
        func_021A2724(p, p->f20[0x11], 0);
    }
    if (p->f26 <= 0xc) {
        func_021A2924(p);
        func_021A28A0(p);
        func_021A284C(p);
    }
    func_021A26D8(p);
}
