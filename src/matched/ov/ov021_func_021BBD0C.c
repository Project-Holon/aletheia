/*
 * function: func_021BBD0C
 * address:  0x021BBD0C
 * packet:   pkt_ov021_021BBD0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_021AC1F0  0x021AC1F0  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 *   d_021D9B0C     0x021D9B0C  data  a2
 *
 * Twin of func_021AC6D4 (same Arg local, same three calls per iteration).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Arg { u32 a; u8 b4, b5, b6, b7; u32 c; } Arg;

struct BbActRec;
struct BbActSys;
struct X;
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern void func_021AC1F0(struct X *x, void *b);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern u16 d_021D9B0C[];

void func_021BBD0C(u32 *p)
{
    Arg s;
    int i;
    const u16 *t = d_021D9B0C;
    u32 r7 = func_021ABE24((u8 *)p[0]);
    s.b4 = 2;
    s.b5 = 0x11;
    s.b6 = 0x10;
    s.b7 = 0x10;
    s.c = 1;
    for (i = 0; i < 0x1a; i++, t++) {
        s.a = (u32)func_02046E24(r7, *t);
        func_021AC1F0((struct X *)p[0], (void *)s.a);
        ((u16 *)p)[4 + i] = func_020500F0((struct BbActSys *)p[1], (const struct BbActRec *)(&s), 1);
    }
}
