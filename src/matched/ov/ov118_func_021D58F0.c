/*
 * function: func_021D58F0
 * address:  0x021D58F0
 * packet:   pkt_ov118_021D58F0
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02051A34  0x02051A34  arm
 *   func_02011610  0x02011610  thumb
 *   func_02051838  0x02051838  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13876.h"
#include "../include/Obj22675.h"
#include "../include/Obj22676.h"

typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern int func_02051A34(void *p);
struct IcaAnime;
struct Rec12;
extern unsigned int func_02011610(struct IcaAnime *, struct Rec12 *);
extern void func_02051838(void *, Vec *);

void func_021D58F0(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)func_02051A34(obj);
        if (((struct Obj22675 *)(*(char * *)&((struct Obj13876 *)w)->fC))->f98 != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            func_02011610(((struct Obj22676 *)(*(char * *)&((struct Obj13876 *)w)->fC))->f98, (struct Rec12 *)v);
            func_02051838(obj, v);
        }
    }
}
