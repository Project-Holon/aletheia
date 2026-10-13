/*
 * function: FIELD_SOUND_SYSTEM_HandleModeState1
 * address:  0x02029040
 * packet:   pkt_02028FD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A Thumb `add pc, r0` switch on p->f1c with eight arms, the twin of
 * FIELD_SOUND_SYSTEM_HandleModeState0 in the same packet.  Every callee takes the object pointer,
 * which is why the switch index lives in r1 and r0 keeps holding p.
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_SetState  0x02029344  thumb
 *   FIELD_SOUND_SYSTEM_DiscardRequest  0x02029354  thumb
 *   FIELD_SOUND_SYSTEM_FinishRequest  0x02029364  thumb
 *   FIELD_SOUND_SYSTEM_FadeOutCurrentBgm  0x0202938C  thumb
 *   FIELD_SOUND_SYSTEM_PlayRequestedBgmNow  0x0202945C  thumb
 */

typedef unsigned int u32;

struct T {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

extern void FIELD_SOUND_SYSTEM_SetState(void *obj, u32 value);
extern int FIELD_SOUND_SYSTEM_DiscardRequest(int a0);
typedef unsigned char  u8;
extern void FIELD_SOUND_SYSTEM_FinishRequest(u8 *p);
extern void FIELD_SOUND_SYSTEM_FadeOutCurrentBgm(u8 *p);
extern void FIELD_SOUND_SYSTEM_PlayRequestedBgmNow(u8 *p);

void FIELD_SOUND_SYSTEM_HandleModeState1(struct T *p)
{
    switch (p->f1c) {
    case 0:
        break;
    case 1:
        FIELD_SOUND_SYSTEM_DiscardRequest((int)p);
        break;
    case 2:
        FIELD_SOUND_SYSTEM_FadeOutCurrentBgm((u8 *)p);
        FIELD_SOUND_SYSTEM_SetState(p, 3);
        break;
    case 3:
        FIELD_SOUND_SYSTEM_FadeOutCurrentBgm((u8 *)p);
        FIELD_SOUND_SYSTEM_SetState(p, 5);
        break;
    case 4:
        FIELD_SOUND_SYSTEM_FadeOutCurrentBgm((u8 *)p);
        FIELD_SOUND_SYSTEM_SetState(p, 6);
        break;
    case 5:
        if (p->f0c == p->f08) {
            FIELD_SOUND_SYSTEM_DiscardRequest((int)p);
        } else {
            FIELD_SOUND_SYSTEM_FadeOutCurrentBgm((u8 *)p);
            FIELD_SOUND_SYSTEM_SetState(p, 8);
        }
        break;
    case 6:
        if (p->f0c == p->f08) {
            FIELD_SOUND_SYSTEM_DiscardRequest((int)p);
        } else {
            FIELD_SOUND_SYSTEM_FadeOutCurrentBgm((u8 *)p);
            FIELD_SOUND_SYSTEM_SetState(p, 0xd);
        }
        break;
    case 7:
        if (p->f0c == p->f08) {
            FIELD_SOUND_SYSTEM_DiscardRequest((int)p);
        } else {
            FIELD_SOUND_SYSTEM_PlayRequestedBgmNow((u8 *)p);
            FIELD_SOUND_SYSTEM_SetState(p, 1);
            FIELD_SOUND_SYSTEM_FinishRequest((u8 *)p);
        }
        break;
    }
}
