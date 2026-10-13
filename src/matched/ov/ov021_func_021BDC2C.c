/*
 * function: EVENT_ENTRANCE_OUT_CallFadeIn
 * address:  0x021BDC2C
 * packet:   pkt_ov021_021BDC2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05065.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Evt;
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

void EVENT_ENTRANCE_OUT_CallFadeIn(u32 *ctx, u32 a)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj05065 *)p)->f4;
    u32 y = ((struct Obj05065 *)p)->fC;

    if (((struct Obj05065 *)p)->f40 != 0)
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)x, y, 3, 0, 0, p[0x44], p[0x45]));
    else
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)x, y, ((struct Obj05065 *)p)->f3C, 0, 1, 0, 0));
}
