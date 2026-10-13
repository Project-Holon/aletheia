/*
 * function: EVENT_ENTRANCE_OUT_RunFadeSe
 * address:  0x021BDB9C
 * packet:   pkt_ov021_021BDB9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_ENTRANCE_OUT_PostBgmFadeIn  0x021BDBF8  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   EVENT_ENTRANCE_OUT_ShowPlaceName  0x021BDC80  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09653.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Evt;
extern int EVENT_ENTRANCE_OUT_PostBgmFadeIn(u32 a);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void EVENT_ENTRANCE_OUT_ShowPlaceName(u32 *);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

u32 EVENT_ENTRANCE_OUT_RunFadeSe(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj09653 *)p)->f4;
    u32 y = ((struct Obj09653 *)p)->fC;

    switch (*st) {
    case 0:
        if (((struct Obj09653 *)p)->f48 != 0)
            EVENT_ENTRANCE_OUT_PostBgmFadeIn((u32)ctx);
        (*st)++;
        break;
    case 1:
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)x, y, 2, 0, 0, 0, 0));
        (*st)++;
        break;
    case 2:
        EVENT_ENTRANCE_OUT_ShowPlaceName(ctx);
        return 1;
    }
    return 0;
}
