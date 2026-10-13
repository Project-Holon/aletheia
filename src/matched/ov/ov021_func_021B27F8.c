/*
 * function: SCRCMD_GIMMICK46_CallThirdEvent
 * address:  0x021B27F8
 * packet:   pkt_ov021_021B27F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FIELD_GIMMICK_ROTATING_ROOM_StartRotateEvent  0x021F3B18  thumb  ov046
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u32 FIELD_GIMMICK_ROTATING_ROOM_StartRotateEvent(void *, u32);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_GIMMICK46_CallThirdEvent(u32 a, u32 b)
{
    void *s = SCRCMD_WORK_GetScriptWork((void *)b);
    void *d = SCRCMD_WORK_GetGameSystem((void *)b);
    u32 r = FIELD_GIMMICK_ROTATING_ROOM_StartRotateEvent(d, SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b));

    if (r == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(s, (void *)r);
    return 1;
}
