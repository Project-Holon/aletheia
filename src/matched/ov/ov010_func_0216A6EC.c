/*
 * function: SCRCMD_TRIALHOUSE_StartSaveEvent
 * address:  0x0216A6EC
 * packet:   pkt_ov010_0216A6EC
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
 *   GAME_DATA_GetListCursor  0x02012F50  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   TRIAL_HOUSE_CreateSaveTask  0x021D0FE8  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetListCursor(void *base);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *TRIAL_HOUSE_CreateSaveTask(void *a, int unused, int c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_TRIALHOUSE_StartSaveEvent(int a0, int a1)
{
    void *r7;
    void *l0;
    int *r4;

    r7 = SCRCMD_WORK_GetScriptWork((void *)a1);
    l0 = SCRCMD_WORK_GetGameSystem((void *)a1);
    r4 = (int *)GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData((const struct Ctx *)l0));
    SCRIPT_SYS_CallEvent(r7, TRIAL_HOUSE_CreateSaveTask((void *)l0, *r4, SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1)));
    return 1;
}
