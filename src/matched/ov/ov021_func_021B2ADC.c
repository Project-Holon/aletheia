/*
 * function: SCRCMD_SCREENEFFECTS_StartRecoveryBallsEvent
 * address:  0x021B2ADC
 * packet:   pkt_ov021_021B2ADC
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
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   SCRIPT_WORK_GetEvent  0x02158F50  thumb  ov010
 *   EVENT_RECOVERY_CreateBallsEvent  0x021C0820  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *SCRIPT_WORK_GetEvent(void *p);
typedef unsigned int   u32;
extern void *EVENT_RECOVERY_CreateBallsEvent(void *p, int a1, u32 n);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_SCREENEFFECTS_StartRecoveryBallsEvent(int a, int b)
{
    void *y = SCRCMD_WORK_GetGameSystem((void *)b);
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);
    int p = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);

    FIELDMAP_GetFieldPlayer(GAMESYSTEM_GetFieldMap((void *)y));
    SCRIPT_SYS_CallEvent(x, EVENT_RECOVERY_CreateBallsEvent(y, (int)SCRIPT_WORK_GetEvent((void *)x), (unsigned char)p));
    return 1;
}
