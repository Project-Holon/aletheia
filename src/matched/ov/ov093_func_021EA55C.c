/*
 * function: func_021EA55C
 * address:  0x021EA55C
 * packet:   pkt_ov093_021EA55C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEE80  0x021EEE80  thumb  ov093
 *   func_021EEEF4  0x021EEEF4  thumb  ov093
 *   func_021EF694  0x021EF694  thumb  ov093
 *   func_021EF6A8  0x021EF6A8  thumb  ov093
 *   func_021EF6E8  0x021EF6E8  thumb  ov093
 *   func_021EF5E8  0x021EF5E8  thumb  ov093
 *   func_021EF664  0x021EF664  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct H {
    u16 h0;
    u8 b2;
    u8 op : 4;
    u8 hi : 4;
    int f4;
    int f8;
};

extern void func_021EEE80(u32 a, u16 k, u32 *p);
extern void func_021EEEF4(u32 a, u16 b, u32 c);
extern void func_021EF694(u32 a, u32 b);
extern void func_021EF6A8(u32 a, u32 b, u32 c);
extern void func_021EF6E8(u32 a, u32 b, u32 c);
extern void func_021EF5E8(u32 a, u8 b, u16 c);
extern void func_021EF664(int a, u16 b, int c);

void func_021EA55C(struct H *p, int a)
{
    switch (p->op) {
    case 1:
        func_021EEE80(a, p->h0, (u32 *)(&p->f4));
        break;
    case 2:
        func_021EEEF4(a, p->h0, (u32)(&p->f4));
        break;
    case 3:
        func_021EF694(a, p->h0);
        break;
    case 5:
        func_021EF6A8(a, p->h0, (u32)(&p->f4));
        break;
    case 6:
        func_021EF6E8(a, p->h0, (u32)(&p->f4));
        break;
    case 4:
        func_021EF5E8(a, p->f4, p->f8);
        break;
    case 7:
        func_021EF664(a, p->f4, p->f8);
        break;
    }
}
