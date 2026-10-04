/*
 * function: func_021953D4
 * address:  0x021953D4
 * packet:   pkt_ov021_021953D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207CA00  0x0207CA00  arm
 *   func_02048AFC  0x02048AFC  arm
 *   func_02048B20  0x02048B20  arm
 *   func_02048B44  0x02048B44  arm
 *   func_02048B60  0x02048B60  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_0207D7C4  0x0207D7C4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01351.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

extern void func_0207CA00(u8 *a, u8 *b, V *c);
extern void func_02048AFC(u32 o, V *a);
extern void func_02048B20(u32 o, V *a);
extern void func_02048B44(u32 o, V *a);
extern void func_02048B60(u32 o, int *a);
struct Light;
extern void func_02048AD0(struct Light *l);
extern void func_0207D7C4(V *a, V *b, V *c, int d, int e);

void func_021953D4(u8 *p, int m)
{
    V t;
    V a;
    V b;
    V c;
    int f;

    func_0207CA00(p + 0xCA0, p + 0xCB8, &t);
    a.x = t.x;
    a.y = t.y;
    a.z = t.z;
    b.x = 0;
    b.y = 0x1000;
    b.z = 0;
    c.x = 0;
    c.y = 0;
    c.z = 0;
    if (m == 0) {
        f = 0x40000;
        if (((struct Obj01351 *)p)->fCC4 >= f)
            f = ((struct Obj01351 *)p)->fCC4 + 0x1000;
        func_02048AFC(((struct Obj01351 *)p)->f4, &a);
        func_02048B20(((struct Obj01351 *)p)->f4, &b);
        func_02048B44(((struct Obj01351 *)p)->f4, &c);
        func_02048B60(((struct Obj01351 *)p)->f4, &f);
        func_02048AD0((struct Light *)(((struct Obj01351 *)p)->f4));
        return;
    }
    func_0207D7C4(&a, &b, &c, 1, 0);
}
