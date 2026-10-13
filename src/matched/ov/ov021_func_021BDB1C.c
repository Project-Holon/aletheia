/*
 * function: EVENT_ENTRANCE_OUT_RunAppear
 * address:  0x021BDB1C
 * packet:   pkt_ov021_021BDB1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENT_APPEAR_CreateDescendingSpin  0x021BF644  thumb  ov021
 *   EVENT_ENTRANCE_OUT_ShowPlaceName  0x021BDC80  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12894.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int EVENT_APPEAR_CreateDescendingSpin(int a, int b, int c);
extern void EVENT_ENTRANCE_OUT_ShowPlaceName(u32 *);
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

u32 EVENT_ENTRANCE_OUT_RunAppear(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj12894 *)p)->f4;
    u32 y = ((struct Obj12894 *)p)->fC;

    switch (*st) {
    case 0:
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_APPEAR_CreateDescendingSpin(0, x, y));
        (*st)++;
        break;
    case 1:
        EVENT_ENTRANCE_OUT_ShowPlaceName(ctx);
        return 1;
    }
    return 0;
}
