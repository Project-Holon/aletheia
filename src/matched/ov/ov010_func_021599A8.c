/*
 * function: SCRIPT_WORK_WaitReportSave
 * address:  0x021599A8
 * packet:   pkt_ov010_021599A8
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
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb
 *   GAME_DATA_IsSaving  0x02012E40  thumb
 *   GAME_DATA_SaveMain  0x02012DD0  thumb
 *   FIELD_SUBSCREEN_GetMode  0x021A0F90  thumb  ov021
 *   FIELD_SUBSCREEN_IsReportSaveAnimDone  0x021A153C  thumb  ov021
 *   FIELD_SUBSCREEN_StopReportSaveAnim  0x021A1548  thumb  ov021
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_GetReturnScriptId  0x021590FC  thumb  ov010
 *   FIELD_SAVEANIME_Stop  0x021D11D8  thumb
 *   FIELD_SAVEANIME_Delete  0x021D1194  thumb
 *   SCRIPT_WORK_SetReturnScriptId  0x021590F4  thumb  ov010
 */

typedef unsigned short u16;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetSubscreen(void *);
extern u8 GAME_DATA_IsSaving(const u8 *o);
extern int GAME_DATA_SaveMain(u8 *p);
extern u32 FIELD_SUBSCREEN_GetMode(u8 *p);
extern int FIELD_SUBSCREEN_IsReportSaveAnimDone(u32 *p);
extern void FIELD_SUBSCREEN_StopReportSaveAnim(u32 *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 SCRIPT_WORK_GetReturnScriptId(void *p);
extern void FIELD_SAVEANIME_Stop(int);
extern void FIELD_SAVEANIME_Delete(int);
extern void SCRIPT_WORK_SetReturnScriptId(void *p, u32 v);

int SCRIPT_WORK_WaitReportSave(int a, int b)
{
    void *s4 = SCRCMD_WORK_GetGameData((void *)b);
    void *s0 = SCRCMD_WORK_GetScriptWork((void *)b);
    int h;
    int ret;
    h = FIELDMAP_GetSubscreen(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b)));
    if (GAME_DATA_IsSaving(s4) == 0) {
        ret = 1;
        if (FIELD_SUBSCREEN_GetMode((u8 *)h) == 7) {
            if (FIELD_SUBSCREEN_IsReportSaveAnimDone((u32 *)h) == 0)
                ret = 0;
        }
    } else {
        switch (GAME_DATA_SaveMain(s4)) {
        case 0:
        case 1:
            ret = 0;
            break;
        case 2:
            *SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b) = 1;
            ret = 0;
            break;
        case 3:
            *SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b) = 0;
            ret = 1;
            if (FIELD_SUBSCREEN_GetMode((u8 *)h) == 7)
                FIELD_SUBSCREEN_StopReportSaveAnim((u32 *)h);
            break;
        }
    }
    if (ret == 1) {
        int t = SCRIPT_WORK_GetReturnScriptId(s0);
        FIELD_SAVEANIME_Stop(t);
        FIELD_SAVEANIME_Delete(t);
        SCRIPT_WORK_SetReturnScriptId(s0, 0);
    }
    return ret;
}
