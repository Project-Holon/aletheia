/*
 * function: SCRCMD_CallTrainerEyePairEvent
 * address:  0x021AE994
 * packet:   pkt_ov021_021AE994
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_TRAINER_EYE_CreatePairEvent  0x021AE430  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_GetTrainerEntry  0x02159124  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct R { u8 pad[0x14]; u32 f14; u32 f18; } R;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern char *SCRIPT_WORK_GetTrainerEntry(char *p, int i);
extern u32 EVENT_TRAINER_EYE_CreatePairEvent(u32 a, u32 x, u32 y);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_CallTrainerEyePairEvent(u32 a, u32 b)
{
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);
    R *p = (R *)SCRIPT_WORK_GetTrainerEntry(x, 0);
    R *q = (R *)SCRIPT_WORK_GetTrainerEntry(x, 1);

    SCRIPT_SYS_CallEvent(x, (void *)EVENT_TRAINER_EYE_CreatePairEvent((u32)SCRCMD_WORK_GetGameSystem((void *)b), p->f18, q->f18));
    return 1;
}
