/*
 * function: func_021D6ECC
 * address:  0x021D6ECC
 * packet:   pkt_ov118_021D6ECC
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
#include "../include/Obj13883.h"
#include "../include/Obj22694.h"
#include "../include/Obj22695.h"

typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern int BUTTON_MAN_GetUserData(void *p);
struct IcaAnime;
struct Rec12;
extern unsigned int ICA_ANIME_GetTranslate(struct IcaAnime *p, struct Rec12 *dst);
extern void BUTTON_MAN_SetEmitterPos(void *, Vec *);

void func_021D6ECC(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)BUTTON_MAN_GetUserData(obj);
        if (((struct Obj22694 *)(*(char * *)&((struct Obj13883 *)w)->fC))->f9C != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            ICA_ANIME_GetTranslate(((struct Obj22695 *)(*(char * *)&((struct Obj13883 *)w)->fC))->f9C, (struct Rec12 *)v);
            BUTTON_MAN_SetEmitterPos(obj, v);
        }
    }
}
