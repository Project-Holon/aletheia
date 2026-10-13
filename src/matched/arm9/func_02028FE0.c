/*
 * function: FIELD_SOUND_SYSTEM_HandleModeState0
 * address:  0x02028FE0
 * packet:   pkt_02028FD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_SetState  0x02029344  thumb
 *   FIELD_SOUND_SYSTEM_FinishRequest  0x02029364  thumb
 *   FIELD_SOUND_SYSTEM_FadeInCurrentBgm  0x02029374  thumb
 *   FIELD_SOUND_SYSTEM_PopBgm  0x020293D8  thumb
 *   FIELD_SOUND_SYSTEM_PlayRequestedBgmNow  0x0202945C  thumb
 */

typedef unsigned int u32;

struct T {
    u32 pad00[7];
    u32 f1c;
};

extern void FIELD_SOUND_SYSTEM_SetState(void *obj, u32 value);
typedef unsigned char  u8;
extern void FIELD_SOUND_SYSTEM_FinishRequest(u8 *p);
extern void FIELD_SOUND_SYSTEM_FadeInCurrentBgm(u8 *p);
extern void FIELD_SOUND_SYSTEM_PopBgm(struct T *p);
extern void FIELD_SOUND_SYSTEM_PlayRequestedBgmNow(u8 *p);

void FIELD_SOUND_SYSTEM_HandleModeState0(struct T *p)
{
    switch (p->f1c) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        FIELD_SOUND_SYSTEM_PopBgm(p);
        FIELD_SOUND_SYSTEM_FadeInCurrentBgm((u8 *)p);
        FIELD_SOUND_SYSTEM_SetState(p, 7);
        break;
    case 5:
        FIELD_SOUND_SYSTEM_SetState(p, 8);
        break;
    case 6:
        FIELD_SOUND_SYSTEM_SetState(p, 0xd);
        break;
    case 7:
        FIELD_SOUND_SYSTEM_PlayRequestedBgmNow((u8 *)p);
        FIELD_SOUND_SYSTEM_SetState(p, 1);
        FIELD_SOUND_SYSTEM_FinishRequest((u8 *)p);
        break;
    }
}
