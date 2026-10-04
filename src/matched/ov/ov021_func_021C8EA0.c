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

struct G3dOwner;
struct G3dRec;
struct G3dSys;
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(int *self);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
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
    r6 = func_021ABE24((u8 *)p[0]);
    for (i = 0; i < 4; i++) {
        p[1 + i] = (u32)func_02046E24(r6, a.v[i]);
        func_02046FF8((int *)p[1 + i]);
    }
    for (i = 0; i < 5; i++) {
        p[5 + i] = (u32)func_02046E24(r6, b.v[i]);
    }
    p[11] = (u32)func_02047400((void *)p[1], 0, (void *)p[1]);
    p[10] = (u32)func_02047564((struct G3dOwner *)p[11], (const struct G3dOwner *)p[5], 0);
    p[12] = (u32)func_0204767C(p[11], p + 10, 1);
    func_020477A4((struct G3dSys *)p[12], 0);
}
