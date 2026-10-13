/*
 * function: SCRCMD_TRIALHOUSE_StartPartySelect
 * address:  0x0216A470
 * packet:   pkt_ov010_0216A470
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
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FLD_BTL_INST_TOOL_CreatePartySelectStepEvent  0x02168BF0  thumb  ov010
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
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Desc;
extern struct Desc *FLD_BTL_INST_TOOL_CreatePartySelectStepEvent(int a, int b, int c, int d, u16 *e);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);

int SCRCMD_TRIALHOUSE_StartPartySelect(int a0, int a1)
{
    void *r7;
    void *l4;
    int *r6;
    int l8;
    int lc;
    u16 *l0;

    r7 = SCRCMD_WORK_GetScriptWork((void *)a1);
    l4 = SCRCMD_WORK_GetGameSystem((void *)a1);
    r6 = (int *)GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData((const struct Ctx *)l4));
    l8 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    lc = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    l0 = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    SCRIPT_SYS_CallEvent(r7, FLD_BTL_INST_TOOL_CreatePartySelectStepEvent((int)l4, *r6, l8, lc, l0));
    return 1;
}
