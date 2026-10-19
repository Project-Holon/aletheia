/*
 * function: SCRIPT_WORK_CmdPopAllBgm
 * address:  0x021598EC
 * packet:   pkt_ov010_021598EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   SCRCMD_FLDMMDL_UnpauseAllMmdls  0x021B1BE8  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_GetPendingBgmStackDepth  0x020288C4  thumb
 *   FIELD_SOUND_SYSTEM_StartPopAllTask  0x0202972C  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef signed int     s32;
typedef unsigned short u16;
struct Ctx;
struct Sys;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void SCRCMD_FLDMMDL_UnpauseAllMmdls(int);
struct BigObj;
extern unsigned int GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern s32 FIELD_SOUND_SYSTEM_GetPendingBgmStackDepth(struct Sys *s);
extern void *FIELD_SOUND_SYSTEM_StartPopAllTask(void *a, u16 b);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRIPT_WORK_CmdPopAllBgm(int a, int b)
{
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);
    void *y = SCRCMD_WORK_GetGameSystem((void *)b);
    int h = (int)GAMESYSTEM_GetGameData(y);
    int r = 0;
    SCRCMD_FLDMMDL_UnpauseAllMmdls(b);
    if (FIELD_SOUND_SYSTEM_GetPendingBgmStackDepth((struct Sys *)((int)GAME_DATA_GetBgmInfo((const struct BigObj *)h)))) {
        SCRIPT_SYS_CallEvent(x, FIELD_SOUND_SYSTEM_StartPopAllTask(y, r));
        r = 1;
    }
    return r;
}
