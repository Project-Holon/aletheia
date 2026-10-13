/*
 * function: SCRCMD_PROC_FLD_CallFieldMapEvent
 * address:  0x021B5094
 * packet:   pkt_ov021_021B5094
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
typedef unsigned char  u8;
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_PROC_FLD_CallFieldMapEvent(u32 a, u32 b)
{
    void *s = SCRCMD_WORK_GetScriptWork((void *)b);
    void *d = SCRCMD_WORK_GetGameSystem((void *)b);

    SCRIPT_SYS_CallEvent(s, (void *)EVENT_FIELDMAP_CONTROL_StartFadeIn(d, (int)GAMESYSTEM_GetFieldMap((void *)d), 0, 0, 1, 0, 0));
    return 1;
}
