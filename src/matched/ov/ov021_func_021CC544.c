/*
 * function: SCRCMD_PALPARK_CallFallEvent
 * address:  0x021CC544
 * packet:   pkt_ov021_021CC544
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task step: hands the field's current map object to ov010 SCRIPT_SYS_CallEvent with a lookup through NAMEIN_SETUP_StartFallEvent.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   NAMEIN_SETUP_StartFallEvent  0x0216C204  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *p);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
typedef unsigned char  u8;
extern int NAMEIN_SETUP_StartFallEvent(void *a, u8 *b);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);

int SCRCMD_PALPARK_CallFallEvent(void *task, void *p)
{
    void *a = SCRCMD_WORK_GetScriptWork(p);
    void *b = SCRCMD_WORK_GetGameSystem(p);
    SCRIPT_SYS_CallEvent(a, (void *)NAMEIN_SETUP_StartFallEvent((void *)b, (u8 *)GAMESYSTEM_GetFieldMap(b)));
    return 1;
}
