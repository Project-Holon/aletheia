/*
 * function: func_021D03C4
 * address:  0x021D03C4
 * packet:   pkt_ov021_021D03C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C67D8  0x021C67D8  thumb  ov021
 *   data_021DB92C  0x021DB92C  data  ov021  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct T {
    u16 a;
    u16 b;
} T;

typedef struct W {
    u16 h[2];
    u32 f4;
    u16 g[2];
} W;

typedef unsigned char  u8;
extern u32 func_021ABE24(u8 *p);
extern u32 func_021ABE18(u32 a);
extern void func_021C6AE0(u32 a);
extern int func_021C6AF0(u32 a, u32 b, u32 c);
extern void func_021C6AF8(u8 *p, u32 v);
extern void func_021C6AFC(u32 *, u16);
extern int func_021C6574(u32 a, u32 b, u32 c);
extern u16 func_021C6590(u32, u32, u32, u32);
extern void func_021C67D8(u32, u32, u32);
extern const T data_021DB92C[];

void func_021D03C4(W *p)
{
    u32 buf[9];
    u32 k;
    u32 h;
    int i = 0;
    const T *t = data_021DB92C;
    u16 *hp = (u16 *)p;
    u16 *q;

    k = func_021ABE24((u8 *)p->f4);
    h = func_021ABE18(p->f4);
    for (; i < 2; i++, t++) {
        func_021C6AE0((u32)buf);
        func_021C6AF0((u32)buf, k, t->a);
        func_021C6AF8((u8 *)buf, k);
        func_021C6AFC(buf, t->b);
        q = hp + i;
        hp[i] = func_021C6574(h, (u32)buf, 0);
        q[4] = func_021C6590(h, hp[i], 0, 0);
        func_021C67D8(h, q[4], 1);
    }
}
