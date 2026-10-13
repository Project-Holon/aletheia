/*
 * function: EVENT_ENTRANCE_OUT_RunPlain
 * address:  0x021BDA30
 * packet:   pkt_ov021_021BDA30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_ENTRANCE_OUT_PostBgmFadeIn  0x021BDBF8  thumb  ov021
 *   EVENT_ENTRANCE_OUT_CallFadeIn  0x021BDC2C  thumb  ov021
 *   EVENT_ENTRANCE_OUT_ShowPlaceName  0x021BDC80  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj20137.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int EVENT_ENTRANCE_OUT_PostBgmFadeIn(u32 a);
extern void EVENT_ENTRANCE_OUT_CallFadeIn(u32 *, u32);
extern void EVENT_ENTRANCE_OUT_ShowPlaceName(u32 *);

u32 EVENT_ENTRANCE_OUT_RunPlain(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];

    switch (*st) {
    case 0:
        if (((struct Obj20137 *)p)->f48 != 0)
            EVENT_ENTRANCE_OUT_PostBgmFadeIn((u32)ctx);
        EVENT_ENTRANCE_OUT_CallFadeIn(ctx, a);
        (*st)++;
        break;
    case 1:
        EVENT_ENTRANCE_OUT_ShowPlaceName(ctx);
        return 1;
    }
    return 0;
}
