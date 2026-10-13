/*
 * function: SYMBOL_MAP_ScrCmdStartPicker
 * address:  0x02166A00
 * packet:   pkt_ov010_02166A00
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
 *   GAME_DATA_GetSaveSyncBlock  0x02012F38  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SYMBOL_MAP_CreatePickerTask  0x02166854  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

extern void *SCRCMD_WORK_GetScriptWork(void *b);
extern void *SCRCMD_WORK_GetGameSystem(void *b);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_GetSaveSyncBlock(int base);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a, void *b);
typedef unsigned int   u32;
extern void *SYMBOL_MAP_CreatePickerTask(void *a, int b, u32 c, u32 d, u32 e);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SYMBOL_MAP_ScrCmdStartPicker(void *a, void *b)
{
    void *r6 = SCRCMD_WORK_GetScriptWork((void *)b);
    void *r7 = SCRCMD_WORK_GetGameSystem((void *)b);
    int v1;
    unsigned short *v2;
    unsigned short *v3;
    unsigned short *v4;
    int t;
    GAME_DATA_GetSaveSyncBlock((int)GAMESYSTEM_GetGameData((void *)r7));
    v1 = SCRIPT_WORK_ReadWorkValue(a, b);
    v2 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    v3 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    v4 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    t = (int)SYMBOL_MAP_CreatePickerTask(r7, v1, (u32)v2, (u32)v3, (u32)v4);
    if (t == 0)
        return 1;
    SCRIPT_SYS_CallEvent(r6, (void *)t);
    return 1;
}
