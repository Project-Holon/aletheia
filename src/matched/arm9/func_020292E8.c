/*
 * function: FIELD_SOUND_SYSTEM_UpdateLoadingAndPush
 * address:  0x020292E8
 * packet:   pkt_0202918C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_SOUND_SYSTEM_UpdateLoadingAndPush.c \\
 *       --func FIELD_SOUND_SYSTEM_UpdateLoadingAndPush --addr 0x020292E8 --thumb --cc 1.1p1
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_SetState  0x02029344  thumb
 *   FIELD_SOUND_SYSTEM_FinishRequest  0x02029364  thumb
 *   FIELD_SOUND_SYSTEM_PushCurrentBgm  0x0202939C  thumb
 *   FIELD_SOUND_SYSTEM_StepBgmLoading  0x02029434  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  FIELD_SOUND_SYSTEM_StepBgmLoading(u8 *p);
struct T;
extern void FIELD_SOUND_SYSTEM_PushCurrentBgm(struct T *p);
extern void FIELD_SOUND_SYSTEM_SetState(void *obj, u32 value);
extern void FIELD_SOUND_SYSTEM_FinishRequest(u8 *p);

void FIELD_SOUND_SYSTEM_UpdateLoadingAndPush(u8 *p)
{
    if (FIELD_SOUND_SYSTEM_StepBgmLoading(p) == 0) {
        return;
    }
    FIELD_SOUND_SYSTEM_PushCurrentBgm((struct T *)p);
    FIELD_SOUND_SYSTEM_SetState(p, 0);
    FIELD_SOUND_SYSTEM_FinishRequest(p);
}
