/*
 * function: FIELD_SOUND_SYSTEM_UpdateFadingOutToPush
 * address:  0x020291C4
 * packet:   pkt_0202918C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_SOUND_SYSTEM_UpdateFadingOutToPush.c \
 *       --func FIELD_SOUND_SYSTEM_UpdateFadingOutToPush --addr 0x020291C4 --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_USE_IsBgmFading  0x02005E50  thumb
 *   FIELD_SOUND_SYSTEM_SetState  0x02029344  thumb
 *   FIELD_SOUND_SYSTEM_FinishRequest  0x02029364  thumb
 *   FIELD_SOUND_SYSTEM_PushCurrentBgm  0x0202939C  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct T;
extern int GFL_USE_IsBgmFading(void);
extern void FIELD_SOUND_SYSTEM_PushCurrentBgm(struct T *p);
extern void FIELD_SOUND_SYSTEM_SetState(void *obj, u32 value);
extern void FIELD_SOUND_SYSTEM_FinishRequest(u8 *p);

void FIELD_SOUND_SYSTEM_UpdateFadingOutToPush(u8 *p)
{
    if (GFL_USE_IsBgmFading() != 0) {
        return;
    }
    FIELD_SOUND_SYSTEM_PushCurrentBgm((struct T *)p);
    FIELD_SOUND_SYSTEM_SetState(p, 0);
    FIELD_SOUND_SYSTEM_FinishRequest(p);
}
