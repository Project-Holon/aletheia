/*
 * function: SCRCMD_SCREENEFFECTS_StartDoorClose
 * address:  0x021B2B94
 * packet:   pkt_ov021_021B2B94
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
 *   SCRIPT_WORK_GetEvent  0x02158F50  thumb  ov010
 *   FIELD_DOOR_ANIME_StartClose  0x021C98F4  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *SCRIPT_WORK_GetEvent(void *p);
typedef unsigned int   u32;
extern u32 FIELD_DOOR_ANIME_StartClose(u32 a, u32 b, u32 c, u32 d);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);

int SCRCMD_SCREENEFFECTS_StartDoorClose(int a, int b)
{
    void *y = SCRCMD_WORK_GetGameSystem((void *)b);
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);
    void *t = GAMESYSTEM_GetFieldMap((void *)y);
    int p = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);

    SCRIPT_SYS_CallEvent(x, (void *)FIELD_DOOR_ANIME_StartClose((u32)SCRIPT_WORK_GetEvent((void *)x), (u32)y, (u32)t, p));
    return 1;
}
