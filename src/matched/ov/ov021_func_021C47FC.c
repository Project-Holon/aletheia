/*
 * function: func_021C47FC
 * address:  0x021C47FC
 * packet:   pkt_ov021_021C47FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_021AC1F0  0x021AC1F0  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct S { u32 w0; u8 b4, b5, b6, b7; u32 w8; } S;
typedef struct P { u32 f0; u32 f4; u16 f8; } P;

extern u32 func_021ABE24(u32 a);
extern u32 func_02046E24(u32 a, u32 b);
extern void func_021AC1F0(u32 a, u32 b);
extern u16 func_020500F0(u32 a, S *b, u32 c);

void func_021C47FC(P *p)
{
    S s;
    u32 x = func_021ABE24(p->f0);

    s.b4 = 2;
    s.b5 = 0x13;
    s.b6 = 0x10;
    s.b7 = 0x10;
    s.w8 = 1;
    s.w0 = func_02046E24(x, 0x2e);
    func_021AC1F0(p->f0, s.w0);
    p->f8 = func_020500F0(p->f4, &s, 1);
}
