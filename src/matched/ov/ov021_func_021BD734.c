/*
 * function: EVENT_ENTRANCE_IN_RunObjectAnime
 * address:  0x021BD734
 * packet:   pkt_ov021_021BD734
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_ENTRANCE_IN_ShouldFadeBgm  0x021BD8C0  thumb  ov021
 *   EVENT_ENTRANCE_IN_StartBgmFadeOut  0x021BD96C  thumb  ov021
 *   EVENT_ENTRANCE_IN_ReplaceBgm  0x021BD94C  thumb  ov021
 *   EVENT_ENTRANCE_IN_CallFadeOut  0x021BD988  thumb  ov021
 *   EVENT_FIELD_PROCLINK_StartHopAnim  0x02161B1C  thumb  ov010
 *   EVENT_FIELD_PROCLINK_IsHopAnimDone  0x02161B74  thumb  ov010
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12883.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 EVENT_ENTRANCE_IN_ShouldFadeBgm(u32 *ctx);
extern void EVENT_ENTRANCE_IN_StartBgmFadeOut(u32 *, u32);
extern void EVENT_ENTRANCE_IN_ReplaceBgm(u32 *);
extern void EVENT_ENTRANCE_IN_CallFadeOut(u32 *, u32);
extern int EVENT_FIELD_PROCLINK_StartHopAnim(void *a);
extern int EVENT_FIELD_PROCLINK_IsHopAnimDone(int a0);
extern void GFL_USE_PlaySeDefaultVolume(u32);

u32 EVENT_ENTRANCE_IN_RunObjectAnime(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];
    u32 x = ((struct Obj12883 *)p)->fC;

    switch (*st) {
    case 0:
        if (EVENT_ENTRANCE_IN_ShouldFadeBgm(ctx))
            EVENT_ENTRANCE_IN_StartBgmFadeOut(ctx, a);
        else
            EVENT_ENTRANCE_IN_ReplaceBgm(ctx);
        ctx[1] = EVENT_FIELD_PROCLINK_StartHopAnim((void *)x);
        (*st)++;
        break;
    case 1:
        if (EVENT_FIELD_PROCLINK_IsHopAnimDone(ctx[1])) {
            if (((struct Obj12883 *)p)->f38 != 2)
                GFL_USE_PlaySeDefaultVolume(0x559);
            EVENT_ENTRANCE_IN_CallFadeOut(ctx, a);
            (*st)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}
