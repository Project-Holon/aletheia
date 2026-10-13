/*
 * function: EVENT_ENTRANCE_IN_RunFadeSe
 * address:  0x021BD874
 * packet:   pkt_ov021_021BD874
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_ENTRANCE_IN_ReplaceBgm  0x021BD94C  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void EVENT_ENTRANCE_IN_ReplaceBgm(u32 *);
struct Evt;
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

u32 EVENT_ENTRANCE_IN_RunFadeSe(u32 a, int *st, u32 *ctx)
{
    u32 *p = (u32 *)ctx[2];
    u32 x = p[1];
    u32 y = p[3];

    switch (*st) {
    case 0:
        EVENT_ENTRANCE_IN_ReplaceBgm(ctx);
        GFL_USE_PlaySeDefaultVolume(0x737);
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)x, y, 2, 0));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
