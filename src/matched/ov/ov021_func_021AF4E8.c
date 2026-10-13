/*
 * function: SCRCMD_PokeVoiceEvent
 * address:  0x021AF4E8
 * packet:   pkt_ov021_021AF4E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_IsLoaderBusy  0x02005C64  thumb
 *   PM_VOICE_GetPerapVoiceSave  0x02006CAC  thumb
 *   PM_VOICE_Play  0x02006984  thumb
 *   SCRCMD_WORK_SetFadeParam  0x0215A6B8  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 a;
    u16 b;
    u32 f4;
    u32 f8;
} Rec;

extern int GFL_USE_IsLoaderBusy(void);
extern void PM_VOICE_GetPerapVoiceSave(void **out);
extern u32 PM_VOICE_Play(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern void SCRCMD_WORK_SetFadeParam(u32 *a, u32 b);

int SCRCMD_PokeVoiceEvent(u32 a, u32 b, Rec *c)
{
    u32 v, r;

    if (GFL_USE_IsLoaderBusy()) {
        return 0;
    }
    if (c->f4) {
        u32 x, y;
        y = c->b;
        x = c->a;
        PM_VOICE_GetPerapVoiceSave((void **)(&v));
        r = PM_VOICE_Play(x, y, 0x40, 0, 0, 0, 0, (u32)(&v));
    } else {
        r = PM_VOICE_Play(c->a, c->b, 0x40, 0, 0, 0, 0, 0);
    }
    SCRCMD_WORK_SetFadeParam((u32 *)c->f8, r);
    return 1;
}
