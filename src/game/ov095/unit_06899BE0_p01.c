/*
 * function: func_06899BE0
 * address:  0x06899BE0
 * packet:   pkt_ov095_06899BE0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_06899C4C  0x06899C4C  thumb  ov095
 *   func_06899C5C  0x06899C5C  thumb  ov095
 *   func_06899C6C  0x06899C6C  thumb  ov095
 *   func_06899C7C  0x06899C7C  thumb  ov095
 *   func_06899C8C  0x06899C8C  thumb  ov095
 *   func_06899C9C  0x06899C9C  arm    ov095
 *   func_06899D38  0x06899D38  thumb  ov095
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    u8 pad0[8];
    int f08;
    u8 pad0c[0x8f - 0x0c];
    u8 f8f;
    u8 f90;
    u8 pad91[0xa0 - 0x91];
    int fa0;
    u8 pada4[0xac - 0xa4];
    u16 fac;
    u8 padae[2];
    int fb0;
} Obj;

extern int func_06899C4C(int a);
extern int func_06899C5C(int a);
extern int func_06899C6C(int a);
extern int func_06899C7C(void);
extern int func_06899C8C(int a, int b, int c, int d, int e, u8 *f, int g, int h);
extern void func_06899C9C(int a, int b);
extern void func_06899D38(Obj *o);

void func_06899BE0(Obj *o)
{
    int a;
    int b;
    int c;
    int d;

    a = func_06899C4C(o->fa0);
    b = func_06899C5C(o->fa0);
    c = func_06899C6C(o->fa0);
    d = func_06899C7C();
    o->fb0 = func_06899C8C(a, b, c, d, o->f08, &o->f8f, o->f90, o->fac);
    func_06899C9C(0x10, 1);
    func_06899D38(o);
}
