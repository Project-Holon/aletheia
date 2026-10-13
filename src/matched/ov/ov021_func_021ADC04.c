/*
 * function: FLDEFF_ENCOUNT_PlaySound
 * address:  0x021ADC04
 * packet:   pkt_ov021_021ADC04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   G3D_SYSTEM_GetObjectAnimeFrame  0x02047828  arm
 *   EFFECT_ENCOUNT_GetSpotDistance  0x021AAA4C  thumb  ov021
 *   func_0209C0A4  0x0209C0A4  arm
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_ClaimSlotWithOwner  0x02028ACC  thumb
 *   sEncountVolumes     0x021D9234  data   a1
 *
 * Levers: G3D_SYSTEM_GetObjectAnimeFrame's second parameter is an index (the zero stored to v
 * is passed in r1), not &v; the final call's arguments are named locals with
 * the inner call bound to a local after them, which keeps both loads above
 * the call in callee-saved registers.
 */
#include "../include/Obj05043.h"
#include "../include/Obj19888.h"
typedef unsigned char u8;
typedef unsigned short u16;

typedef signed int     s32;
typedef unsigned int   u32;
struct AnmCtl;
struct SoundSys2;
extern u32 G3D_SYSTEM_GetObjectAnimeFrame(struct AnmCtl *c, u32 idx, s32 *frame);
struct Self;
extern int EFFECT_ENCOUNT_GetSpotDistance(struct Self *self, short *out);
extern u16 func_0209C0A4(int a, int b);
struct BigObj;
extern unsigned int GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void FIELD_SOUND_SYSTEM_ClaimSlotWithOwner(struct SoundSys2 *s, u32 id, u32 who);
extern u8 sEncountVolumes[];

void FLDEFF_ENCOUNT_PlaySound(u8 *w, u8 *o)
{
    u16 v;
    int z;
    u8 c;
    u16 k;
    void *x;

    v = 0;
    G3D_SYSTEM_GetObjectAnimeFrame(*(void **)(o + 0x28 + w[0x1c] * 0x18), 0, &z);
    if (z == 0 && EFFECT_ENCOUNT_GetSpotDistance((struct Self *)(((struct Obj05043 *)w)->f34), (short int *)(&v)) != 0) {
        v = func_0209C0A4(v, 5);
        if (v > 3)
            v = 3;
        c = sEncountVolumes[v];
        k = ((struct Obj19888 *)o)->f8A;
        x = (void *)GAME_DATA_GetBgmInfo(*(void **)(((struct Obj05043 *)w)->f34 + 8));
        FIELD_SOUND_SYSTEM_ClaimSlotWithOwner(x, k, c);
    }
}
