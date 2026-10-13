/*
 * function: EVENT_ENTRANCE_OUT_RunObjectAnime
 * address:  0x021BDAA8
 * packet:   pkt_ov021_021BDAA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENT_ENTRANCE_OUT_CallFadeIn  0x021BDC2C  thumb  ov021
 *   EVENT_ENTRANCE_OUT_PostBgmFadeIn  0x021BDBF8  thumb  ov021
 *   EVENT_ENTRANCE_OUT_StartBgmFadeIn  0x021BDC0C  thumb  ov021
 *   EVENT_ENTRANCE_OUT_ShowPlaceName  0x021BDC80  thumb  ov021
 *   EVENT_FIELD_PROCLINK_StartObjAnim  0x021618E0  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07540.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void EVENT_ENTRANCE_OUT_CallFadeIn(u32 *, u32);
struct Evt;
extern int EVENT_ENTRANCE_OUT_PostBgmFadeIn(u32 a);
extern void EVENT_ENTRANCE_OUT_StartBgmFadeIn(u32 *, u32);
extern void EVENT_ENTRANCE_OUT_ShowPlaceName(u32 *);
extern void *EVENT_FIELD_PROCLINK_StartObjAnim(void *a, void *b);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

u32 EVENT_ENTRANCE_OUT_RunObjectAnime(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj07540 *)p)->f4;
    u32 y = ((struct Obj07540 *)p)->fC;

    switch (*st) {
    case 0:
        EVENT_ENTRANCE_OUT_CallFadeIn(ctx, a);
        (*st)++;
        break;
    case 1:
        if (((struct Obj07540 *)p)->f48 != 0)
            EVENT_ENTRANCE_OUT_PostBgmFadeIn((u32)ctx);
        else if (((struct Obj07540 *)p)->f4C != 0)
            EVENT_ENTRANCE_OUT_StartBgmFadeIn(ctx, a);
        (*st)++;
        break;
    case 2:
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_FIELD_PROCLINK_StartObjAnim((void *)x, (void *)y));
        (*st)++;
        break;
    case 3:
        EVENT_ENTRANCE_OUT_ShowPlaceName(ctx);
        return 1;
    }
    return 0;
}
