/*
 * function: func_021AC6D4
 * address:  0x021AC6D4
 * packet:   pkt_ov021_021AC6D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021ABE28  0x021ABE28  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_021AC1F0  0x021AC1F0  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 *   d_021D911C     0x021D911C  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Arg { u32 a; u8 b4, b5, b6, b7; u32 c; } Arg;

struct BbActRec;
struct BbActSys;
struct X;
extern u32 func_021ABE24(u8 *p);
extern u32 func_021ABE14(u8 *p);
extern void *func_02188C80(void *p);
extern u8 func_021ABE28(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern void func_021AC1F0(struct X *x, void *b);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern u16 d_021D911C[];

void func_021AC6D4(u32 *p)
{
    Arg s;
    int i;
    u32 r7 = func_021ABE24((u8 *)p[0]);
    u16 *t;
    u32 lv;
    func_02188C80((void *)func_021ABE14((u8 *)p[0]));
    lv = func_021ABE28((u8 *)p[0]);
    s.b4 = 0;
    s.b5 = 0x24;
    s.b6 = 0x20;
    s.b7 = 0x20;
    s.c = 1;
    t = d_021D911C + lv;
    for (i = 0; i < 8; i++) {
        s.a = (u32)func_02046E24(r7, t[i * 4]);
        func_021AC1F0((struct X *)p[0], (void *)s.a);
        ((u16 *)p)[4 + i] = func_020500F0((struct BbActSys *)p[1], (const struct BbActRec *)(&s), 1);
    }
}
