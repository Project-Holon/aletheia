/*
 * file:     field_effect_p12.c
 * unit:     yes
 * function: func_021ABC14, func_021ABC38, func_021ABC5C
 * address:  0x021ABC14
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
 *   func_021ABB54  0x021ABB54  thumb  ov021
 *   func_021ABD08  0x021ABD08  thumb  ov021
 *   func_021ABB78  0x021ABB78  thumb  ov021
 *   func_021AB760  0x021AB760  thumb ov021
 *   func_021ABBA0  0x021ABBA0  thumb ov021
 *   sub_0207C768   0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0218ECD4  0x0218ECD4  thumb ov021
 */
#include "../../matched/include/Obj00757.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int x; int y; int z; } V;

extern u32 func_021ABB54(u32, u32, u32, u32);
extern u32 func_021ABD08(u32, u32, u32);
extern u32 func_021ABB78(u32, u32, u32, u32);
extern unsigned int func_021AB760(u8 *p);
extern void func_021ABBA0(char *p, void *q, int *o1, int *o2);
extern u32 sub_0207C768(u32 a, u32 b);
extern void func_0218ECD4(int a, V *v);
int func_021ABC14(u8 *a, u32 b, u32 c, u32 d);
int func_021ABC38(u8 *a, u32 b, u32 c, u32 d);
void func_021ABC5C(u8 *a0, char *p, void *q);



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021ABC14(u8 *a, u32 b, u32 c, u32 d)
{
func_021ABB54((u32)a, b, c, d);
func_021ABC5C(a, (char *)b, (void *)c);
return func_021ABD08((u32)a, b, c);
}



int func_021ABC38(u8 *a, u32 b, u32 c, u32 d)
{
func_021ABB78((u32)a, b, c, d);
func_021ABC5C(a, (char *)b, (void *)c);
return func_021ABD08((u32)a, b, c);
}


void func_021ABC5C(u8 *a0, char *p, void *q)
{
    int a;
    int s;
    int d;
    V v;
    int dx;
    int dy;
    int dz;

    a = func_021AB760(a0);
    func_021ABBA0(p, q, &s, &d);
    dx = ((struct Obj00757 *)p)->f30 - ((struct Obj00757 *)p)->f24;
    dy = ((struct Obj00757 *)p)->f34 - ((struct Obj00757 *)p)->f28;
    dz = ((struct Obj00757 *)p)->f2C - ((struct Obj00757 *)p)->f20;
    v.x = ((struct Obj00757 *)p)->f20 +
          sub_0207C768((int)(((long long)dz * d + 0x800) >> 12), s);
    v.y = ((struct Obj00757 *)p)->f24 + sub_0207C768((int)(((long long)dx * d + 0x800) >> 12), s);
    v.z = ((struct Obj00757 *)p)->f28 + sub_0207C768((int)(((long long)dy * d + 0x800) >> 12), s);
    func_0218ECD4(a, &v);
}
