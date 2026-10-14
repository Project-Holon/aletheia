/*
 * function: ZUKAN_DETAIL_AREA_FinishHideOverlay
 * address:  0x021C2090
 * packet:   pkt_ov208_021C2090
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 */
#include "../include/Obj00081.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);

void ZUKAN_DETAIL_AREA_FinishHideOverlay(void *unused, u8 *p)
{
    if (CLACT_GetActorDrawEnable((struct Obj *)(*(int *)&((struct Obj00081 *)p)->fC8)) == 0) {
        if (*(int *)&((struct Obj00081 *)p)->f90 == 0) {
            p[0x414] = 1;
        } else {
            p[0x414] = 2;
        }
    }
}
