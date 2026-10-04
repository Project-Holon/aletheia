/*
 * unit:     yes
 * function: func_06899ED0, func_06899F00
 * address:  0x06899ED0
 * packet:   pkt_ov095_06899ED0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two functions: 0x06899ED0 and the unlabelled tail-call stub 0x06899F00
 * (the extent 0x06899ED0..0x06899F28 is code and pool only).
 *
 * symbols:
 *   func_06899E48  0x06899E48  thumb  ov095
 *   func_0689A030  0x0689A030  thumb  ov095
 *   func_0689A76C  0x0689A76C  thumb  ov095
 *   func_0689A84C  0x0689A84C  thumb  ov095
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    u8 pad0[0x6c];
    int f6c;
    int f70;
    u8 pad74[0x8b - 0x74];
    u8 f8b;
    u8 pad8c[0x91 - 0x8c];
    u8 f91;
    u8 pad92[0x98 - 0x92];
    int f98;
} Obj;

extern void func_0689A030(void);
extern int func_0689A76C(int *st, u8 *s);
extern int func_0689A84C(u32 unused, u32 p);
extern void func_06899E48(Obj *o, void (*a)(void), void (*b)(void));

void func_06899ED0(Obj *o, int a, u8 b, u8 c, int d)
{
    o->f6c = a;
    o->f70 = d;
    o->f98 = 0;
    o->f8b = b;
    o->f91 = c;
    func_06899E48(o, func_0689A030, (void (*)(void))func_0689A76C);
}

void func_06899F00(Obj *o, int a, u8 b, int c)
{
    o->f6c = a;
    o->f70 = c;
    o->f98 = 0;
    o->f8b = b;
    func_06899E48(o, func_0689A030, (void (*)(void))func_0689A84C);
}
