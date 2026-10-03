/*
 * function: func_021CD2A4
 * address:  0x021CD2A4
 * packet:   pkt_ov021_021CD2A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012A54  0x02012A54  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0200C1F4  0x0200C1F4  thumb
 *   func_0200C20C  0x0200C20C  thumb
 *   func_02045924  0x02045924  arm
 *   func_021CD348  0x021CD348  thumb  ov021
 *   d_021DB44C     0x021DB44C  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u16 f20;
    u8 pad22[0x12];
    u32 f34;
    u8 pad38[4];
    u32 f3c;
    u8 pad40[4];
    u32 f44;
    u16 f48;
    u8 pad4a[2];
    u32 f4c;
} Obj;

extern const u8 d_021DB44C[];
extern u32 func_020122C0(u32 a, u32 b, void *cb, u32 n);
extern Obj *func_020124E8(u32 a);
extern u32 func_020120F4(u32 a);
extern u32 func_02012EBC(u32 a);
extern u32 func_0200C0F0(u32 a);
extern u32 func_02012944(u32 a);
extern u32 func_02012A54(u32 a);
extern u32 func_02008550(u32 a);
extern u32 func_020457B0(u32 a, u32 b);
extern u32 func_0200C1F4(u32 a);
extern u32 func_0200C20C(u32 a);
extern void func_02045924(u32 a, u32 b);
extern int func_021CD348(int a, int *st, u8 *c);

u32 func_021CD2A4(u32 a, u32 b, u32 x, u32 c, u32 d)
{
    u32 h;
    Obj *o;

    h = func_020122C0(a, x, func_021CD348, 0x50);
    o = func_020124E8(h);
    o->f00 = a;
    o->f04 = func_020120F4(a);
    o->f10 = b;
    o->f18 = d;
    o->f4c = c;
    o->f48 = 4;
    o->f08 = func_0200C0F0(func_02012EBC(o->f04));
    o->f0c = func_02012944(o->f04);
    o->f14 = func_02012A54(o->f04);
    o->f1c = c;
    o->f20 = func_02008550(o->f0c);
    o->f44 = o->f08;
    o->f34 = d_021DB44C[c - 5];
    o->f3c = func_020457B0(o->f34 + 1, o->f48);
    switch (c) {
    case 5:
        func_02045924(o->f3c, func_0200C1F4(o->f08));
        break;
    case 6:
        func_02045924(o->f3c, func_0200C20C(o->f08));
        break;
    case 7:
        break;
    }
    return h;
}
