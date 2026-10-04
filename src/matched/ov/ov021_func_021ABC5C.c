/*
 * function: func_021ABC5C
 * address:  0x021ABC5C
 * packet:   pkt_ov021_021ABC5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AB760  0x021AB760  thumb ov021
 *   func_021ABBA0  0x021ABBA0  thumb ov021
 *   sub_0207C768   0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0218ECD4  0x0218ECD4  thumb ov021
 */
#include "../include/Obj00757.h"

typedef struct { int x; int y; int z; } V;

extern int func_021AB760(int a);
extern void func_021ABBA0(char *p, void *q, int *o1, int *o2);
typedef unsigned int   u32;
extern u32 sub_0207C768(u32 a, u32 b);
extern void func_0218ECD4(int a, V *v);

void func_021ABC5C(int a0, char *p, void *q)
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
