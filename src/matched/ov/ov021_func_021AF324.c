/*
 * function: SCRCMD_WaitBgmThenPop
 * address:  0x021AF324
 * packet:   pkt_ov021_021AF324
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   func_02005F38  0x02005F38  thumb
 *   FIELD_SOUND_SYSTEM_IsBusy  0x020289B8  thumb
 *   FIELD_SOUND_SYSTEM_StartPopAndWaitTask  0x02029620  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct Ctx;
struct Sys;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern int func_02005F38(void);
extern u32 FIELD_SOUND_SYSTEM_IsBusy(struct Sys *s);
typedef unsigned short u16;
extern void *FIELD_SOUND_SYSTEM_StartPopAndWaitTask(void *a, u32 b, u32 c);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);

int SCRCMD_WaitBgmThenPop(u32 a, u32 b)
{
    u32 y;
    void *x;
    void *p;

    x = SCRCMD_WORK_GetGameSystem((void *)b);
    p = SCRCMD_WORK_GetScriptWork((void *)b);
    y = GAME_DATA_GetBgmInfo((const struct BigObj *)GAMESYSTEM_GetGameData(x));
    if (func_02005F38() == 0 && FIELD_SOUND_SYSTEM_IsBusy((struct Sys *)y) == 0) {
        SCRIPT_SYS_CallEvent(p, FIELD_SOUND_SYSTEM_StartPopAndWaitTask(x, 0, 6));
        return 1;
    }
    return 0;
}
