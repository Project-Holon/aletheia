/*
 * function: FIELD_SOUND_SYSTEM_UpdateFadingOutToReplace
 * address:  0x0202930C
 * packet:   pkt_0202918C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_SOUND_SYSTEM_UpdateFadingOutToReplace.c \\
 *       --func FIELD_SOUND_SYSTEM_UpdateFadingOutToReplace --addr 0x0202930C --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_USE_IsBgmFading  0x02005E50  thumb
 *   FIELD_SOUND_SYSTEM_SetState  0x02029344  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int GFL_USE_IsBgmFading(void);
extern void FIELD_SOUND_SYSTEM_SetState(void *obj, u32 value);

void FIELD_SOUND_SYSTEM_UpdateFadingOutToReplace(u8 *p)
{
    if (GFL_USE_IsBgmFading() != 0) {
        return;
    }
    FIELD_SOUND_SYSTEM_SetState(p, 0xe);
}
