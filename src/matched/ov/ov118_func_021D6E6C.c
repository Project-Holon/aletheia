/*
 * function: func_021D6E6C
 * address:  0x021D6E6C
 * packet:   pkt_ov118_021D6E6C
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
#include "../include/Obj13882.h"
#include "../include/Obj22692.h"
#include "../include/Obj22693.h"

typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern int func_02051A34(void *p);
struct IcaAnime;
struct Rec12;
extern unsigned int func_02011610(struct IcaAnime *, struct Rec12 *);
extern void func_02051838(void *, Vec *);

void func_021D6E6C(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)func_02051A34(obj);
        if (((struct Obj22692 *)(*(char * *)&((struct Obj13882 *)w)->fC))->f98 != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            func_02011610(((struct Obj22693 *)(*(char * *)&((struct Obj13882 *)w)->fC))->f98, (struct Rec12 *)v);
            func_02051838(obj, v);
        }
    }
}
