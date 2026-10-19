/*
 * function: SCRCMD_PROC_FLD_CallGameManual
 * address:  0x021B5008
 * packet:   pkt_ov021_021B5008
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
 *   EVENT_GAME_MANUAL_Create  0x021D30B8  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *EVENT_GAME_MANUAL_Create(void *, u16 *);
extern void SCRIPT_SYS_CallEvent(void *, void *);

int SCRCMD_PROC_FLD_CallGameManual(u32 a, u32 b)
{
    void *d = SCRCMD_WORK_GetGameSystem((void *)b);
    void *s = SCRCMD_WORK_GetScriptWork((void *)b);

    SCRIPT_SYS_CallEvent(s, EVENT_GAME_MANUAL_Create(d, SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b)));
    return 1;
}
