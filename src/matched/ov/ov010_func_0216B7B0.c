/*
 * function: SCRCMD_RESEARCH_CmdSetSurveyAnswer
 * address:  0x0216B7B0
 * packet:   pkt_ov010_0216B7B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_0200E3A0  0x0200E3A0  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   func_0200E3E8  0x0200E3E8  thumb
 *   GAME_BEACON_SetQuestionnaire  0x02027100  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200E394(void *a0);
extern void *func_0200E3A0(void *a);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void func_0200E3E8(u8 *bits, int id, u32 value);
extern void GAME_BEACON_SetQuestionnaire(const void *src);

int SCRCMD_RESEARCH_CmdSetSurveyAnswer(int c, int vm)
{
    void *r6;
    int a;
    int b;

    SCRCMD_WORK_GetScriptWork((void *)vm);
    r6 = func_0200E3A0(func_0200E394(GAME_DATA_GetSaveControl((struct Big *)SCRCMD_WORK_GetGameData((void *)vm))));
    a = SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    b = SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    func_0200E3E8(r6, (u8)a, b);
    GAME_BEACON_SetQuestionnaire(r6);
    return 0;
}
