/*
 * function: BTLV_SCD_Create
 * address:  0x06899AF0
 * packet:   pkt_ov095_06899AF0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_06899BA0  0x06899BA0  arm    ov095
 *   func_06899BA8  0x06899BA8  thumb  ov095
 *   func_06899BB8  0x06899BB8  thumb  ov095
 *   func_06899BC8  0x06899BC8  arm    ov095
 *   func_06899BD0  0x06899BD0  thumb  ov095
 *   BTLV_SCD_ClearTasks  0x06899E2C  thumb  ov095
 *   gBtlvScdFileName     0x0689E7B8  data    ov095  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    u8 pad0[8];
    int f08;
    int f0c;
    int f10;
    int f14;
    u8 pad18[0x74 - 0x18];
    int f74;
    u8 pad78[0x8f - 0x78];
    u8 f8f;
    u8 f90;
    u8 f91;
    union {
        u8 raw;
        struct {
            u8 lo : 7;
            u8 hi : 1;
        } b;
    } f92;
    u8 pad93[0x9c - 0x93];
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    u16 fac;
} Obj;

extern u8 gBtlvScdFileName[];

extern Obj *func_06899BA0(u16 a, int b, int c, u8 *d, int e);
extern int func_06899BA8(void);
extern int func_06899BB8(int a, int b);
extern int func_06899BC8(int a, u16 b);
extern int func_06899BD0(u16 a);
extern void BTLV_SCD_ClearTasks(unsigned char *p);

Obj *BTLV_SCD_Create(int a, int b, int c, int d, int e4, int e5, int e6, u16 e7)
{
    Obj *o;

    o = func_06899BA0(e7, 0xb4, 1, gBtlvScdFileName, 0xc8);
    o->f9c = a;
    o->fa0 = b;
    o->fa4 = c;
    o->fac = e7;
    o->f08 = e4;
    o->f10 = e5;
    o->fa8 = func_06899BB8(c, func_06899BA8());
    o->f0c = func_06899BC8(0x80, e7);
    o->f74 = 0;
    o->f90 = e6;
    o->f91 = 0;
    o->f92.b.lo = 0;
    o->f92.b.hi = 0;
    o->f8f = 0;
    o->f14 = func_06899BD0(o->fac);
    BTLV_SCD_ClearTasks((unsigned char *)o);
    return o;
}
