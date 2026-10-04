/*
 * function: func_02167178
 * address:  0x02167178
 * packet:   pkt_ov010_02167178
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021672D0  0x021672D0  thumb  ov010
 *   func_02190708  0x02190708  thumb  ov021
 */

typedef unsigned short u16;

struct O {
    u16 pad0[8];
    int f10;
    int f14;
    int f18;
};

extern int func_021672D0(int a0);
extern int func_02190708(int a, int b, u16 c, u16 d, u16 e, u16 f);

void func_02167178(struct O *o)
{
    int a;
    int b;
    int c;
    switch (func_021672D0((int)o)) {
    case 0:
        a = 1;
        b = 0x1e;
        c = 4;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        a = 1;
        b = 0x1e;
        c = 8;
        break;
    }
    o->f14 = func_02190708(o->f10, o->f18, a, a, b, c);
}
