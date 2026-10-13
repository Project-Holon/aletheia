/*
 * file:     btlv_scd.c
 * unit:     yes
 * function: func_06899AF0
 * address:  0x06899AF0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   func_02030734  0x02030734  arm
 *   STRBUF_Create  0x020457B0  arm
 *   func_021B9AF8  0x021B9AF8  thumb
 *   func_021D3D70  0x021D3D70  thumb
 *   func_06899E2C  0x06899E2C  thumb  ov095
 *   g_0689E7B8     0x0689E7B8  data    ov095  a4
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

extern Obj *func_02030734(u16 a, int b, int c, u8 *d, int e);
extern int func_021D3D70(void);
extern int func_021B9AF8(int a, int b);
extern int STRBUF_Create(int a, u16 b);
extern int PRINTSYS_QUE_Create(u16 a);
extern void func_06899E2C(unsigned char *p);
Obj *func_06899AF0(int a, int b, int c, int d, int e4, int e5, int e6, u16 e7);
extern u8 g_0689E7B8[];


Obj *func_06899AF0(int a, int b, int c, int d, int e4, int e5, int e6, u16 e7)
{
    Obj *o;

    o = func_02030734(e7, 0xb4, 1, g_0689E7B8, 0xc8);
    o->f9c = a;
    o->fa0 = b;
    o->fa4 = c;
    o->fac = e7;
    o->f08 = e4;
    o->f10 = e5;
    o->fa8 = func_021B9AF8(c, func_021D3D70());
    o->f0c = STRBUF_Create(0x80, e7);
    o->f74 = 0;
    o->f90 = e6;
    o->f91 = 0;
    o->f92.b.lo = 0;
    o->f92.b.hi = 0;
    o->f8f = 0;
    o->f14 = PRINTSYS_QUE_Create(o->fac);
    func_06899E2C((unsigned char *)o);
    return o;
}
