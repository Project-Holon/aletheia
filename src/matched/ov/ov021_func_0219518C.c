/*
 * function: TALKMSGWIN_BuildShape
 * address:  0x0219518C
 * packet:   pkt_ov021_0219518C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VEC_Subtract  0x0207CA00  arm
 *   VEC_Mag  0x0207CBD0  arm
 *   func_0207C768  0x0207C768  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07458.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

extern void VEC_Subtract(const V *a, const V *b, V *c);
extern int VEC_Mag(V *a);
extern u32 func_0207C768(u32 a, u32 b);

static inline void setv(V *o, int x, int y, int z)
{
    o->x = x;
    o->y = y;
    o->z = z;
}

static inline void set3(s16 *o, s16 x, s16 y, s16 z)
{
    o[0] = x;
    o[1] = y;
    o[2] = z;
}

void TALKMSGWIN_BuildShape(u8 *p, u8 *e, const V *a, V *b, V *c, V *d, V *f, V *g, V *h)
{
    V l0;
    V l1;
    V l2;
    V l3;
    V l4;
    V l5;
    int m;
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;

    VEC_Subtract(b, a, &l0);
    VEC_Subtract(c, a, &l1);
    VEC_Subtract(d, a, &l2);
    VEC_Subtract(f, a, &l3);
    VEC_Subtract(g, a, &l4);
    VEC_Subtract(h, a, &l5);
    m = VEC_Mag(&l0);
    m1 = VEC_Mag(&l1);
    m2 = VEC_Mag(&l2);
    m3 = VEC_Mag(&l3);
    m4 = VEC_Mag(&l4);
    m5 = VEC_Mag(&l5);
    if (m < m1) {
        m = m1;
    }
    if (m < m2) {
        m = m2;
    }
    if (m < m3) {
        m = m3;
    }
    if (m < m4) {
        m = m4;
    }
    if (m < m5) {
        m = m5;
    }
    setv((V *)(e + 0x1C), a->x, a->y, a->z);
    ((struct Obj07458 *)e)->f28 = m;
    ((struct Obj07458 *)e)->f2C = 0;
    ((struct Obj07458 *)e)->f2E = 0;
    ((struct Obj07458 *)e)->f30 = 0;
    set3((s16 *)(e + 0x32), func_0207C768(l0.x, m), func_0207C768(l0.y, m), func_0207C768(l0.z, m));
    set3((s16 *)(e + 0x38), func_0207C768(l1.x, m), func_0207C768(l1.y, m), func_0207C768(l1.z, m));
    set3((s16 *)(e + 0x3E), func_0207C768(l2.x, m), func_0207C768(l2.y, m), func_0207C768(l2.z, m));
    set3((s16 *)(e + 0x44), func_0207C768(l3.x, m), func_0207C768(l3.y, m), func_0207C768(l3.z, m));
    set3((s16 *)(e + 0x4A), func_0207C768(l4.x, m), func_0207C768(l4.y, m), func_0207C768(l4.z, m));
    set3((s16 *)(e + 0x50), func_0207C768(l5.x, m), func_0207C768(l5.y, m), func_0207C768(l5.z, m));
}
