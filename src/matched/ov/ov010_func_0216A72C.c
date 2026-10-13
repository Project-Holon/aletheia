/*
 * function: SCRCMD_TRIALHOUSE_StartAward
 * address:  0x0216A72C
 * packet:   pkt_ov010_0216A72C
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
 *   FLD_BTL_INST_TOOL_CreateTrialHouseAwardEvent  0x02168E5C  thumb  ov010
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
extern int FLD_BTL_INST_TOOL_CreateTrialHouseAwardEvent(int a, int b, int c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_TRIALHOUSE_StartAward(int a0, int a1)
{
    void *r6;
    void *r7;
    int l0;

    r6 = SCRCMD_WORK_GetScriptWork((void *)a1);
    r7 = SCRCMD_WORK_GetGameSystem((void *)a1);
    GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData((const struct Ctx *)r7));
    l0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    SCRIPT_SYS_CallEvent(r6, (void *)FLD_BTL_INST_TOOL_CreateTrialHouseAwardEvent((int)r7, l0, SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1)));
    return 1;
}
