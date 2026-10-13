/*
 * function: SCRCMD_SCREENEFFECTS_StartDoorOpen
 * address:  0x021B2B24
 * packet:   pkt_ov021_021B2B24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_GetEvent  0x02158F50  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FIELD_DOOR_ANIME_StartOpen  0x021C978C  thumb  ov021
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *SCRIPT_WORK_GetEvent(void *p);
extern u32 FIELD_DOOR_ANIME_StartOpen(u32 a, u32 b, u32 c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_SCREENEFFECTS_StartDoorOpen(u32 a, u32 b)
{
    void *d = SCRCMD_WORK_GetGameSystem((void *)b);
    void *s = SCRCMD_WORK_GetScriptWork((void *)b);
    void *w = GAMESYSTEM_GetFieldMap((void *)d);

    SCRIPT_SYS_CallEvent(s, (void *)FIELD_DOOR_ANIME_StartOpen((u32)SCRIPT_WORK_GetEvent((void *)s), (u32)d, (u32)w));
    return 1;
}
