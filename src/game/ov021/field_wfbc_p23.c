/*
 * file:     field_wfbc_p23.c
 * unit:     yes
 * function: func_021953D4, func_0219545C
 * address:  0x021953D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207CA00  0x0207CA00  arm
 *   func_02048AFC  0x02048AFC  arm
 *   func_02048B20  0x02048B20  arm
 *   func_02048B44  0x02048B44  arm
 *   func_02048B60  0x02048B60  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_0207D7C4  0x0207D7C4  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_02048B30  0x02048B30  arm
 *   func_02048B54  0x02048B54  arm
 */
#include "../../matched/include/Obj01351.h"
#include "../../matched/include/Obj07211.h"

struct Light;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

typedef signed short   s16;

typedef signed char    s8;

extern void func_0207CA00(u8 *a, u8 *b, V *c);
extern void func_02048AFC(u32 o, V *a);
extern void func_02048B20(u32 o, V *a);
extern void func_02048B44(u32 o, V *a);
extern void func_02048B60(struct Light *l, const u32 *in);
extern void func_02048AD0(struct Light *l);
extern void func_0207D7C4(V *a, V *b, V *c, int d, int e);
extern u32 func_02048AE8(u32, u32, u32, u32);
extern u32 func_02048B0C(u32, u32);
extern u32 func_02048B30(u32, u32);
extern u32 func_02048B54(u32, u32);
void func_021953D4(u8 *p, int m);
int func_0219545C(u32 a, u32 b, u32 c, u32 d);


/*
 * Addresses are Black-image addresses.
 */
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
        func_02048B60((struct Light *)(((struct Obj01351 *)p)->f4), (const u32 *)(&f));
        func_02048AD0((struct Light *)(((struct Obj01351 *)p)->f4));
        return;
    }
    func_0207D7C4(&a, &b, &c, 1, 0);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219545C(u32 a, u32 b, u32 c, u32 d)
{
func_02048AE8(((struct Obj07211 *)((u8 *)(a)))->f4, (a + (202 << 4)), c, d);
func_02048B0C(((struct Obj07211 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 12)));
func_02048B30(((struct Obj07211 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 24)));
return func_02048B54(((struct Obj07211 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 36)));
}
