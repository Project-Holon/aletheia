/*
 * function: func_021D4A54
 * address:  0x021D4A54
 * packet:   pkt_ov118_021D4A54
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BUTTON_MAN_GetUserData  0x02051A34  arm
 *   func_02011610  0x02011610  thumb
 *   BUTTON_MAN_SetEmitterPos  0x02051838  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13874.h"
#include "../include/Obj22660.h"
#include "../include/Obj22661.h"

typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern int BUTTON_MAN_GetUserData(void *p);
struct IcaAnime;
struct Rec12;
extern unsigned int func_02011610(struct IcaAnime *, struct Rec12 *);
extern void BUTTON_MAN_SetEmitterPos(void *, Vec *);

void func_021D4A54(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)BUTTON_MAN_GetUserData(obj);
        if (((struct Obj22660 *)(*(char * *)&((struct Obj13874 *)w)->fC))->f9C != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            func_02011610(((struct Obj22661 *)(*(char * *)&((struct Obj13874 *)w)->fC))->f9C, (struct Rec12 *)v);
            BUTTON_MAN_SetEmitterPos(obj, v);
        }
    }
}
