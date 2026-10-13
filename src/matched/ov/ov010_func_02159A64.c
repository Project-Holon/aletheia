/*
 * function: SCRIPT_WORK_CmdReportSave
 * address:  0x02159A64
 * packet:   pkt_ov010_02159A64
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb
 *   FIELD_SAVEANIME_Create  0x021D1164  thumb
 *   FIELD_SAVEANIME_Start  0x021D11B0  thumb
 *   FIELD_SUBSCREEN_GetMode  0x021A0F90  thumb  ov021
 *   FIELD_SUBSCREEN_PrepareReportSave  0x021A1524  thumb  ov021
 *   FIELD_SUBSCREEN_StartReportSaveAnim  0x021A1530  thumb  ov021
 *   SCRIPT_WORK_SetReturnScriptId  0x021590F4  thumb  ov010
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   GAME_DATA_SaveStart  0x02012DAC  thumb
 *   VM_SetWait  0x020113D0  thumb
 *   SCRIPT_WORK_WaitReportSave  0x021599A8  thumb  ov010
 */

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned int   u32;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetHeapId(void *);
extern int FIELDMAP_GetSubscreen(void *);
extern int FIELD_SAVEANIME_Create(int, void *);
extern void FIELD_SAVEANIME_Start(int);
typedef unsigned char  u8;
struct Sub02008C20Obj;
extern u32 FIELD_SUBSCREEN_GetMode(u8 *p);
extern void FIELD_SUBSCREEN_PrepareReportSave(u32 *p);
extern void FIELD_SUBSCREEN_StartReportSaveAnim(u32 *p);
extern void SCRIPT_WORK_SetReturnScriptId(void *p, u32 v);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern int GAME_DATA_SaveStart(int a0);
extern void VM_SetWait(char *p, int val);
extern int SCRIPT_WORK_WaitReportSave(int, int);

int SCRIPT_WORK_CmdReportSave(int a, int b)
{
    void *s0 = SCRCMD_WORK_GetScriptWork((void *)b);
    void *s4 = SCRCMD_WORK_GetGameData((void *)b);
    int y, z, t;
    void *x;
    x = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b));
    y = FIELDMAP_GetHeapId(x);
    z = FIELDMAP_GetSubscreen(x);
    t = FIELD_SAVEANIME_Create(y, x);
    FIELD_SAVEANIME_Start(t);
    if (FIELD_SUBSCREEN_GetMode((u8 *)z) == 7) {
        FIELD_SUBSCREEN_PrepareReportSave((u32 *)z);
        FIELD_SUBSCREEN_StartReportSaveAnim((u32 *)z);
    }
    SCRIPT_WORK_SetReturnScriptId(s0, t);
    func_02008DF0(GAME_DATA_GetTrainerRecord(s4), 1);
    GAME_DATA_SaveStart((int)s4);
    VM_SetWait((char *)a, (int)SCRIPT_WORK_WaitReportSave);
    return 1;
}
