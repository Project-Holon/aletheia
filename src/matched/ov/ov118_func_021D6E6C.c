/*
 * function: POKETRADE_DEMO_MIDDLE_UpdateEmitterA
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
 *   BUTTON_MAN_GetUserData  0x02051A34  arm
 *   ICA_ANIME_GetTranslate  0x02011610  thumb
 *   BUTTON_MAN_SetEmitterPos  0x02051838  arm
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

extern int BUTTON_MAN_GetUserData(void *p);
struct IcaAnime;
struct Rec12;
extern unsigned int ICA_ANIME_GetTranslate(struct IcaAnime *, struct Rec12 *);
extern void BUTTON_MAN_SetEmitterPos(void *, Vec *);

void POKETRADE_DEMO_MIDDLE_UpdateEmitterA(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)BUTTON_MAN_GetUserData(obj);
        if (((struct Obj22692 *)(*(char * *)&((struct Obj13882 *)w)->fC))->f98 != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            ICA_ANIME_GetTranslate(((struct Obj22693 *)(*(char * *)&((struct Obj13882 *)w)->fC))->f98, (struct Rec12 *)v);
            BUTTON_MAN_SetEmitterPos(obj, v);
        }
    }
}
