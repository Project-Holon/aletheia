/*
 * function: func_0219EF7C
 * address:  0x0219EF7C
 * packet:   pkt_ov021_0219EF7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A298  0x0204A298  arm
 *   func_0209C2B0  0x0209C2B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct S {
    u32 *f0;
    u32 f4;
    u16 h8;
    u16 hA;
    u16 hC;
    u16 hE;
    u8  pad10[8];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u8  pad28[12];
    u32 f34;
};

extern u32 *func_0204A298(u32, u32, u32, u32, u32 *);
extern u32 func_0209C2B0(u32, u32);

void func_0219EF7C(struct S *p, u32 b, u32 c)
{
    u32 loc;
    p->f0 = func_0204A298(0x4f, b, 0, (u16)c, &loc);
    p->f4 = loc;
    p->f18 = (u32)p->f0 + p->f0[2];
    p->h8 = func_0209C2B0(p->f0[3] - p->f0[2], 0x70);
    p->f1c = (u32)p->f0 + p->f0[3];
    p->hA = func_0209C2B0(p->f0[4] - p->f0[3], 0x48);
    p->f20 = (u32)p->f0 + p->f0[4];
    p->hC = func_0209C2B0(p->f0[5] - p->f0[4], 0x24);
    p->f24 = (u32)p->f0 + p->f0[5];
    p->hE = func_0209C2B0(p->f0[6] - p->f0[5], 0x24);
    p->f34 = *(u32 *)((u8 *)p->f0 + p->f0[1]);
}
