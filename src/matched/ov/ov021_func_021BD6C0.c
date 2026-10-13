/*
 * function: EVENT_ENTRANCE_IN_RunPlain
 * address:  0x021BD6C0
 * packet:   pkt_ov021_021BD6C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_ENTRANCE_IN_ReplaceBgm  0x021BD94C  thumb  ov021
 *   EVENT_ENTRANCE_IN_CallFadeOut  0x021BD988  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj20132.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void EVENT_ENTRANCE_IN_ReplaceBgm(u32 *);
extern void EVENT_ENTRANCE_IN_CallFadeOut(u32 *, u32);
extern void GFL_USE_PlaySeDefaultVolume(u32);

u32 EVENT_ENTRANCE_IN_RunPlain(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];

    switch (*st) {
    case 0:
        EVENT_ENTRANCE_IN_ReplaceBgm(ctx);
        if (((struct Obj20132 *)p)->f38 != 2)
            GFL_USE_PlaySeDefaultVolume(0x559);
        EVENT_ENTRANCE_IN_CallFadeOut(ctx, a);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
