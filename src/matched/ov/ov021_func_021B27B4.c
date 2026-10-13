/*
 * function: SCRCMD_FIELD_GIMMICK_ROTATING_ROOM_CallSecondEvent
 * address:  0x021B27B4
 * packet:   pkt_ov021_021B27B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELD_GIMMICK_ROTATING_ROOM_StartLeverEvent  0x021F3AD0  thumb  ov046
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern int FIELD_GIMMICK_ROTATING_ROOM_StartLeverEvent(void *a, int b, int c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_FIELD_GIMMICK_ROTATING_ROOM_CallSecondEvent(int a, int b)
{
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);
    void *y = SCRCMD_WORK_GetGameSystem((void *)b);
    int p = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    int q = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    int r = FIELD_GIMMICK_ROTATING_ROOM_StartLeverEvent(y, p, q);

    if (r == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(x, (void *)r);
    return 1;
}
