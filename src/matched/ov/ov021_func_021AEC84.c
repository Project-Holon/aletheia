/*
 * function: SCRCMD_FadeInField
 * address:  0x021AEC84
 * packet:   pkt_ov021_021AEC84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_FadeInField(u32 a, u32 b)
{
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);
    void *y = SCRCMD_WORK_GetGameSystem((void *)b);

    SCRIPT_SYS_CallEvent(x, (void *)EVENT_FIELDMAP_CONTROL_StartFadeIn(y, (int)GAMESYSTEM_GetFieldMap((void *)y), 0, 0, 1, 0, 0));
    return 1;
}
