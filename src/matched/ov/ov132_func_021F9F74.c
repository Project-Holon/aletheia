/*
 * function: func_021F9F74
 * address: 0x021F9F74
 * packet: pkt_ov132_021F9F74
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Non-const Vec source preserves alias dependence: inline setter
 * arguments load z, y, x after the handle store and before vector stores.
 * const int * and const Vec * sources both gave DIFF, 19 concrete bytes.
 * symbols:
 *   func_020515B4 0x020515B4 arm
 */
#include "../include/Obj14090.h"
typedef struct { int x, y, z; } Vec;
extern int func_020515B4(void *p, int b, int c);
typedef struct { int a; Vec v; } Part;
typedef struct { char pad[0x4808]; Part part[4]; } Obj;
static inline void set(Vec *p, int x, int y, int z)
{
    p->x = x;
    p->y = y;
    p->z = z;
}
void func_021F9F74(char *p, unsigned i, Vec *v)
{
    int a = func_020515B4(((struct Obj14090 *)p)->f4804, i, (int)v);
    if (a == 0 || i < 4) {
        ((Obj *)p)->part[i].a = a;
        set(&((Obj *)p)->part[i].v, v->x, v->y, v->z);
    }
}
