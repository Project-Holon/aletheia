/*
 * function: func_021C8EA0
 * address:  0x021C8EA0
 * packet:   pkt_ov021_021C8EA0
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
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   d_021DAB6C     0x021DAB6C  data  a4
 *   d_021DAB7C     0x021DAB7C  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct A4 { u32 v[4]; } A4;
typedef struct A5 { u32 v[5]; } A5;

extern u32 func_021ABE24(u32);
extern u32 func_02046E24(u32, u32);
extern void func_02046FF8(u32);
extern u32 func_02047400(u32, u32, u32);
extern u32 func_02047564(u32, u32, u32);
extern u32 func_0204767C(u32, u32 *, u32);
extern void func_020477A4(u32, u32);
extern const A4 d_021DAB6C;
extern const A5 d_021DAB7C;

void func_021C8EA0(u32 *p)
{
    A4 a;
    A5 b;
    u32 r6;
    u32 i;

    a = d_021DAB6C;
    b = d_021DAB7C;
    r6 = func_021ABE24(p[0]);
    for (i = 0; i < 4; i++) {
        p[1 + i] = func_02046E24(r6, a.v[i]);
        func_02046FF8(p[1 + i]);
    }
    for (i = 0; i < 5; i++) {
        p[5 + i] = func_02046E24(r6, b.v[i]);
    }
    p[11] = func_02047400(p[1], 0, p[1]);
    p[10] = func_02047564(p[11], p[5], 0);
    p[12] = func_0204767C(p[11], p + 10, 1);
    func_020477A4(p[12], 0);
}
