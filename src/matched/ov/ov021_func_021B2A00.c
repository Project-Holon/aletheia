/*
 * function: SCRCMD_SCREENEFFECTS_FadeOutFast
 * address:  0x021B2A00
 * packet:   pkt_ov021_021B2A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_SCREENEFFECTS_CreateFadeTask  0x021B2EBC  thumb  ov021
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void SCRCMD_SCREENEFFECTS_CreateFadeTask(u32 a, u32 b, u32 c, u32 d, u32 e);

int SCRCMD_SCREENEFFECTS_FadeOutFast(u32 a, u32 b)
{
    void *d;

    SCRCMD_WORK_GetScriptWork((void *)b);
    d = SCRCMD_WORK_GetGameSystem((void *)b);
    SCRCMD_SCREENEFFECTS_CreateFadeTask((u32)d, (u32)GAMESYSTEM_GetFieldMap((void *)d), 3, 0, 0);
    return 0;
}
