/*
 * function: SCRCMD_GIMMICK39_CallSecondEvent
 * address:  0x021B252C
 * packet:   pkt_ov021_021B252C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   GIMMICK39_UnlockLane  0x021F4184  thumb  ov039
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 GIMMICK39_UnlockLane(void *, u16);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_GIMMICK39_CallSecondEvent(u32 a, u32 b)
{
    void *s = SCRCMD_WORK_GetScriptWork((void *)b);
    void *d = SCRCMD_WORK_GetGameSystem((void *)b);
    u32 r = GIMMICK39_UnlockLane(d, *SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b));

    if (r == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(s, (void *)r);
    return 1;
}
