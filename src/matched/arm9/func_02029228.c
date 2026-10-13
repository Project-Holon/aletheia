/*
 * function: FIELD_SOUND_SYSTEM_UpdateFadingOutToLoad
 * address:  0x02029228
 * packet:   pkt_0202918C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_SOUND_SYSTEM_UpdateFadingOutToLoad.c \\
 *       --func FIELD_SOUND_SYSTEM_UpdateFadingOutToLoad --addr 0x02029228 --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_USE_IsBgmFading  0x02005E50  thumb
 *   FIELD_SOUND_SYSTEM_SetState  0x02029344  thumb
 *   FIELD_SOUND_SYSTEM_StartLoadingRequestedBgm  0x02029408  thumb
 *   FIELD_SOUND_SYSTEM_IsSaving  0x0202947C  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int GFL_USE_IsBgmFading(void);
extern u32  FIELD_SOUND_SYSTEM_IsSaving(u8 *p);
extern u32 FIELD_SOUND_SYSTEM_StartLoadingRequestedBgm(u8 *p);
extern void FIELD_SOUND_SYSTEM_SetState(void *obj, u32 value);

void FIELD_SOUND_SYSTEM_UpdateFadingOutToLoad(u8 *p)
{
    if (GFL_USE_IsBgmFading() != 0) {
        return;
    }
    if (FIELD_SOUND_SYSTEM_IsSaving(p) != 0) {
        return;
    }
    FIELD_SOUND_SYSTEM_StartLoadingRequestedBgm(p);
    FIELD_SOUND_SYSTEM_SetState(p, 9);
}
