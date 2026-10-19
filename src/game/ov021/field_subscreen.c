/*
 * file:     field_subscreen.c
 * unit:     yes
 * function: FIELD_SUBSCREEN_Create, FIELD_SUBSCREEN_Delete, FIELD_SUBSCREEN_Main, FIELD_SUBSCREEN_MainNoTransition, FIELD_SUBSCREEN_CheckModeRequest, FIELD_SUBSCREEN_IsIdle, FIELD_SUBSCREEN_ResolveMode, FIELD_SUBSCREEN_RequestMode, FIELD_SUBSCREEN_ChangeModeNow, FIELD_SUBSCREEN_RequestModeWithCallback, FIELD_SUBSCREEN_GetMode, FIELD_SUBSCREEN_GetPanelResult, FIELD_SUBSCREEN_SetPanelResult, FIELD_SUBSCREEN_ClearPanelResult, FIELD_SUBSCREEN_ResumeField, FIELD_SUBSCREEN_InitCGear, FIELD_SUBSCREEN_InitCGearWithCallback, FIELD_SUBSCREEN_ExitCGear, FIELD_3DBG_ExitCGear, FIELD_3DBG_UpdateCGear, FIELD_3DBG_HandleCGearInput, FIELD_SUBSCREEN_InitNoGear, FIELD_SUBSCREEN_ExitNoGear, FIELD_SUBSCREEN_NoGearHook, FIELD_SUBSCREEN_UpdateNoGear, FIELD_SUBSCREEN_InitMenu, FIELD_SUBSCREEN_ExitMenu, FIELD_SUBSCREEN_UpdateMenu, FIELD_SUBSCREEN_UpdateMenuNoTransition, FIELD_SUBSCREEN_GetMenuSelectedButton, FIELD_SUBSCREEN_SetMenuSelectedButton, FIELD_SUBSCREEN_LoadBackdrop, FIELD_SUBSCREEN_GetCGear, FIELD_SUBSCREEN_InitUnion, FIELD_SUBSCREEN_ExitUnion, FIELD_SUBSCREEN_UpdateUnion, FIELD_SUBSCREEN_UpdateUnionNoTransition, FIELD_SUBSCREEN_InitIntrude, FIELD_SUBSCREEN_ExitIntrude, FIELD_SUBSCREEN_UpdateIntrude, FIELD_SUBSCREEN_DrawIntrude, FIELD_SUBSCREEN_CheckIntrudeRequest, FIELD_SUBSCREEN_InitBeaconView, FIELD_SUBSCREEN_ExitBeaconView, FIELD_SUBSCREEN_UpdateBeaconView, FIELD_SUBSCREEN_UpdateBeaconViewNoTransition, FIELD_SUBSCREEN_CheckBeaconViewRequest, FIELD_SUBSCREEN_InitDowsing, FIELD_SUBSCREEN_ExitDowsing, FIELD_SUBSCREEN_UpdateDowsing, FIELD_SUBSCREEN_UpdateDowsingNoTransition, FIELD_SUBSCREEN_InitReport, FIELD_SUBSCREEN_ExitReport, FIELD_SUBSCREEN_UpdateReport, FIELD_SUBSCREEN_UpdateReportNoTransition, FIELD_SUBSCREEN_IsReportReady, FIELD_SUBSCREEN_PrepareReportSave, FIELD_SUBSCREEN_StartReportSaveAnim, FIELD_SUBSCREEN_IsReportSaveAnimDone, FIELD_SUBSCREEN_StopReportSaveAnim, FIELD_SUBSCREEN_CheckReportSaveCounter, FIELD_SUBSCREEN_InitPowerOnoff, FIELD_SUBSCREEN_UpdatePowerOnoff, FIELD_SUBSCREEN_ExitPowerOnoff
 * address:  0x021A0CF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Takes field_3dbg_p01.c (021A10D4), unit_021A1144.c and the 22 mode glue functions 021A1428..021A1590 of field_3dbg.c (lane FXC3: one file from the field_subscreen.c anchor to the first field_3dbg.c anchor 021A15A4).
 * Split from field_fog.c (CL110): __FILE__ anchor field_subscreen.c at 0x021A0CF4; ends at field_3dbg.c (0x021A10D4, certain cut).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_SUBSCREEN_ResolveMode  0x021A0EE4  thumb  ov021
 *   d_021DDE48  0x021DDE48  data  ov021
 *   d_021D872C  0x021D872C  data  a4
 *   d_021D8738     0x021D8738  data
 *   FIELDMAP_IsEventActive  0x02189A2C  thumb  ov021
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   d_021D8734  0x021D8734  data  a4
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   BLOCK20_SAVEDATA_GetBlock  0x02009210  thumb
 *   CGEAR_SAVE_GetObtained  0x020090E0  thumb
 *   ZONEDATA_IsZone34  0x02013D20  thumb
 *   ZONEDATA_IsZone4BPair  0x02013D00  thumb
 *   FIELDMAP_GetVReq  0x02188E30  thumb  ov021
 *   FLD_VREQ_SetMainBlendBrightnessExt  0x021D3270  thumb  ov021
 *   FIELD_MSGBG_SetBlendThunk  0x02193060  thumb  ov021
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   FIELD_MSGBG_LoadWindowGraphics  0x021902A4  thumb  ov021
 *   BLOCK20_SAVEDATA_GetPanelState  0x02009208  thumb
 *   BLOCK20_SAVEDATA_SetPanelState  0x02009200  thumb
 *   GAMESYSTEM_GetAlwaysNetFlag  0x0201214C  thumb
 *   GAMESYSTEM_IsNetOffBySleep  0x02012204  thumb
 *   GAMESYSTEM_ClearNetOffBySleep  0x02012210  thumb
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   C_GEAR_Create  0x021F279C  thumb  ov029
 *   abs_id_1d      0x0000001D  data
 *   C_GEAR_Open  0x021F27D8  thumb  ov029
 *   C_GEAR_Destroy  0x021F2984  thumb  ov029
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   C_GEAR_HandleCommand  0x021F29D8  thumb  ov029
 *   C_GEAR_Nop 0x021F2980 thumb ov029
 *   C_GEAR_Restart  0x021F2994  thumb  ov029
 *   C_GEAR_Update  0x021F2848  thumb  ov029
 *   FIELD_MENU_ApplyBgScroll  0x021A8840  thumb  ov021
 *   INTRUDE_SUBDISP_Exit  0x0217D160  thumb  ov018
 *   INTRUDE_SUBDISP_Update  0x0217D1C0  thumb  ov018
 *   INTRUDE_SUBDISP_Draw  0x0217D3AC  thumb  ov018
 *   INTRUDE_SUBDISP_EventCheck  0x0217D4DC  thumb  ov018
 *   NO_GEAR_Create  0x021F00C8  thumb  ov030
 *   abs_id_1e      0x0000001E  data
 *   NO_GEAR_Destroy  0x021F0118  thumb  ov030
 *   NO_GEAR_Hook  0x021F0114  thumb  ov030
 *   NO_GEAR_Update  0x021F00F8  thumb  ov030
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   BG_SYS_ClearLayer  0x0204152C  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   FIELD_MENU_Create  0x021A836C  thumb  ov021
 *   FIELD_MENU_GetLayoutType  0x021A8B18  thumb  ov021
 *   INFOWIN_Init  0x02024A20  thumb
 *   FIELD_MENU_LoadFrameBg  0x021A8AFC  thumb  ov021
 *   d_021D8708     0x021D8708  data  a4
 *   INFOWIN_Exit  0x02024DCC  thumb
 *   FIELD_MENU_Delete  0x021A84BC  thumb  ov021
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   FIELD_MENU_Update  0x021A85B4  thumb  ov021
 *   INFOWIN_Update  0x02024ABC  thumb
 *   FIELD_SUBSCREEN_GetMode  0x021A0F90  thumb  ov021
 *   FIELD_MENU_GetSelectedButtonId  0x021A8E10  thumb  ov021
 *   FIELD_MENU_SelectButton  0x021A8E20  thumb  ov021
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   FLD_VREQ_SetBgVisible  0x021D3244  thumb  ov021
 *   UNION_SUBDISP_Create  0x021EFEC0  thumb  ov031
 *   abs_id_1f      0x0000001F  data
 *   UNION_SUBDISP_Delete  0x021EFFE8  thumb  ov031
 *   UNION_MAIN_IsIdle  0x0217394C  thumb  ov012
 *   UNION_SUBDISP_Draw  0x021F0054  thumb  ov031
 *   UNION_SUBDISP_Update  0x021F00D4  thumb  ov031
 *   INTRUDE_SUBDISP_Init  0x0217CFE4  thumb  ov018
 *   BEACON_VIEW_Create  0x021F2234  thumb  ov032
 *   abs_id_20      0x00000020  data
 *   BEACON_VIEW_Delete  0x021F22FC  thumb  ov032
 *   BEACON_VIEW_Update 0x021F2344 thumb ov032
 *   BEACON_VIEW_MainPrintQueue 0x021F23F8 thumb ov032
 *   BEACON_VIEW_CreateLeaveEvent 0x021F2404 thumb ov032
 *   DOWSING_Create  0x021F000C  thumb  ov033
 *   abs_id_21      0x00000021  data
 *   DOWSING_Delete  0x021F0124  thumb  ov033
 *   DOWSING_Update 0x021F0174 thumb ov033
 *   DOWSING_UpdateDisplay 0x021F05A4 thumb ov033
 *   REPORT_Create  0x021EFEC0  thumb  ov034
 *   abs_id_22      0x00000022  data
 *   REPORT_Delete  0x021EFF34  thumb  ov034
 *   REPORT_ShowPartyIcons  0x021EFF5C  thumb  ov034
 *   REPORT_UpdateWindows  0x021EFFB4  thumb  ov034
 *   REPORT_IsReady  0x021F0044  thumb  ov034
 *   REPORT_PrepareSave  0x021F0058  thumb  ov034
 *   REPORT_StartSaveAnim  0x021F00BC  thumb  ov034
 *   REPORT_IsSaveAnimDone  0x021F00F0  thumb  ov034
 *   REPORT_StopSaveAnim  0x021F0108  thumb  ov034
 *   REPORT_CheckSaveCounter  0x021F009C  thumb  ov034
 *   C_GEAR_POWER_ONOFF_Create  0x021EFEC0  thumb  ov035
 *   abs_id_23      0x00000023  data
 *   C_GEAR_POWER_ONOFF_Update 0x021EFF3C thumb ov035
 *   C_GEAR_POWER_ONOFF_Delete  0x021EFF2C  thumb  ov035
 */
#include "field_subscreen_types.h"

#define FIELD_SUBSCREEN_MODE_CGEAR      0   /* C-Gear panel (needs the C-Gear in the save) */
#define FIELD_SUBSCREEN_MODE_NO_CGEAR   5   /* fallback when there is no C-Gear */
#define FIELD_SUBSCREEN_MODE_NONE       0xB /* "previous mode" given to the first init */

#define FIELD_SUBSCREEN_STATE_RUN           0
#define FIELD_SUBSCREEN_STATE_FADE_OUT      1
#define FIELD_SUBSCREEN_STATE_FADE_OUT_WAIT 2
#define FIELD_SUBSCREEN_STATE_HALT          3
#define FIELD_SUBSCREEN_STATE_FADE_IN       4
#define FIELD_SUBSCREEN_STATE_FADE_IN_WAIT  5

struct BgTemplate;
struct FieldMenu;
struct MenuLayoutInfo;
struct ArchiveHandle;
struct FieldVReq;

#define FIELD_SUBSCREEN_MODE_MENU   1
#define FIELD_SUBSCREEN_MODE_CGEAR_CALLBACK 8

/* Overlay ids 30 and 31 are absolute symbols: the original loads them with a
 * literal pool word, a plain 30 or 31 would be a mov immediate. */
#define FIELD_SUBSCREEN_OVERLAY_NO_GEAR ((int)abs_id_1e)
#define FIELD_SUBSCREEN_OVERLAY_UNION   ((int)abs_id_1f)

typedef signed int     s32;

/* One row (0x1C bytes) of the mode table. */
typedef struct FieldSubscreenMode {
    void (*init)(FieldSubscreen *work, u32 prevMode);
    void (*update)(FieldSubscreen *work, s32 isFieldIdle);
    void (*updateNoTransition)(FieldSubscreen *work, s32 isFieldIdle);
    int (*checkRequest)(FieldSubscreen *work, u32 mode);
    void (*exit)(FieldSubscreen *work);
    u32 reserved14;
    u32 reserved18;
} FieldSubscreenMode;

u32 C_GEAR_Nop(u32 a);
u32 FIELD_3DBG_ExitCGear(FieldSubscreen *work);
extern int C_GEAR_Restart(int *cgear);
extern u32 C_GEAR_Update(u32, u32);
u32 FIELD_3DBG_UpdateCGear(FieldSubscreen *work, u32 active);
/* Unprototyped on purpose: the caller passes the work pointer as a third argument; a two-parameter prototype changes the bytes. */
int C_GEAR_HandleCommand();
extern void *GAMESYSTEM_GetMyPlayerWork(void *gameSystem);
extern u16 GAME_DATA_GetPlayerZoneId(void *playerLocation);
extern void *GAME_DATA_GetEventWork(void *gameData);
extern void *NO_GEAR_Create(void *cgearSave, FieldSubscreen *work, void *gameSystem);
extern void NO_GEAR_Destroy(void *noGear);
extern void NO_GEAR_Hook(void *noGear);
extern void NO_GEAR_Update(void *noGear);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *template, u32 type);
extern void BG_SYS_SetPlaneVisible(u8 bgId, u8 visible);
extern void BG_SYS_FreeSlot(u32 bgId);
extern void BG_SYS_ClearLayer(int bgId, u16 value);
extern void BG_SYS_SetSubPlaneVisible(u32 planeMask, u32 enable);
extern struct FieldMenu *FIELD_MENU_Create(u16 heapId, u16 subHeapId, FieldSubscreen *parent, void *fieldMap, int slideIn);
extern u32 FIELD_MENU_GetLayoutType(void *gameData, void *eventWork, u32 zoneId);
extern void INFOWIN_Init(u8 bgId, u8 paletteId, void *gameData, u16 heapId);
extern void FIELD_MENU_LoadFrameBg(int heapId, int slideIn);
extern int INFOWIN_Exit(void);
extern void FIELD_MENU_Delete(struct FieldMenu *menu);
extern void BG_SYS_FreeLayerBuf(u32 bgId);
extern u32 FIELD_MENU_Update(struct FieldMenu *menu);
extern void INFOWIN_Update(u32 value);
extern void FIELD_MENU_ApplyBgScroll(struct FieldMenu *menu);
extern u32 FIELD_SUBSCREEN_GetMode(FieldSubscreen *work);
extern u32 FIELD_MENU_GetSelectedButtonId(struct FieldMenu *menu);
extern void FIELD_MENU_SelectButton(struct FieldMenu *menu, u32 buttonId);
extern struct ArchiveHandle *ARC_TOOL_CreateHandle(unsigned int archiveId, unsigned int heapId);
extern void ARC_UTIL_UploadPaletteFromHandle(struct ArchiveHandle *handle, u32 fileId, u32 type, u32 offset, u32 srcOffset, u32 size, u32 heapId);
extern void ARC_UTIL_UploadBgCharFromHandle(struct ArchiveHandle *handle, u32 fileId, u32 bgId, u32 offset, u32 size, u32 mode, u32 heapId);
extern void ARC_UTIL_UploadBgPaletteAddFromHandle(struct ArchiveHandle *handle, u32 fileId, u32 bgId, u32 x, u32 y, u32 width, u32 height, u32 heapId);
extern void ARC_TOOL_DeleteHandle(struct ArchiveHandle *handle);
extern void FLD_VREQ_SetBgVisible(struct FieldVReq *vreq, int index, u8 value);
extern void *UNION_SUBDISP_Create(void *gameSystem);
extern void UNION_SUBDISP_Delete(void *unionPanel);
extern int UNION_MAIN_IsIdle(void *gameSystem);
extern void UNION_SUBDISP_Draw(void *unionPanel, int isFieldIdle);
extern void UNION_SUBDISP_Update(void *unionPanel, int isFieldIdle);
extern void *INTRUDE_SUBDISP_Init(void *gameSystem);
extern void INTRUDE_SUBDISP_Exit(void *intrudePanel);
extern void INTRUDE_SUBDISP_Update(void *intrudePanel, int isFieldIdle);
extern void INTRUDE_SUBDISP_Draw(void *intrudePanel);
extern void *INTRUDE_SUBDISP_EventCheck(void *intrudePanel, int mode, FieldSubscreen *work);
extern const struct BgTemplate d_021D8708;
void FIELD_SUBSCREEN_InitNoGear(FieldSubscreen *work);
void FIELD_SUBSCREEN_ExitNoGear(FieldSubscreen *work);
void FIELD_SUBSCREEN_NoGearHook(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateNoGear(FieldSubscreen *work);
void FIELD_SUBSCREEN_InitMenu(FieldSubscreen *work, u32 prevMode);
void FIELD_SUBSCREEN_ExitMenu(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateMenu(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateMenuNoTransition(FieldSubscreen *work);
u32 FIELD_SUBSCREEN_GetMenuSelectedButton(FieldSubscreen *work);
void FIELD_SUBSCREEN_SetMenuSelectedButton(FieldSubscreen *work, u32 buttonId);
void FIELD_SUBSCREEN_LoadBackdrop(FieldSubscreen *work, u32 heapId);
void *FIELD_SUBSCREEN_GetCGear(FieldSubscreen *work);
void FIELD_SUBSCREEN_InitUnion(FieldSubscreen *work);
void FIELD_SUBSCREEN_ExitUnion(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateUnion(FieldSubscreen *work, u32 isFieldIdle);
void FIELD_SUBSCREEN_UpdateUnionNoTransition(FieldSubscreen *work, u32 isFieldIdle);
void FIELD_SUBSCREEN_InitIntrude(FieldSubscreen *work);
void FIELD_SUBSCREEN_ExitIntrude(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateIntrude(FieldSubscreen *work, int isFieldIdle);
void FIELD_SUBSCREEN_DrawIntrude(FieldSubscreen *work);
void *FIELD_SUBSCREEN_CheckIntrudeRequest(FieldSubscreen *work, int mode);
extern void *BEACON_VIEW_Create(void *gameSystem, void *work);
extern void BEACON_VIEW_Delete(void *beaconView);
extern int BEACON_VIEW_Update(void *beaconView);
extern int BEACON_VIEW_MainPrintQueue(void *beaconView);
extern int BEACON_VIEW_CreateLeaveEvent(void *beaconView);
extern void *DOWSING_Create(u32 heapId, u32 owner, void *work, void *fieldSystem);
extern void DOWSING_Delete(void *dowsing);
extern int DOWSING_Update(void *dowsing);
extern int DOWSING_UpdateDisplay(void *dowsing);
extern void *REPORT_Create(void *gameSystem, u32 heapId);
extern void REPORT_Delete(void *report);
extern void REPORT_ShowPartyIcons(void *report);
extern void REPORT_UpdateWindows(void *report);
extern int REPORT_IsReady(void *report);
extern void REPORT_PrepareSave(void *report);
extern void REPORT_StartSaveAnim(void *report);
extern int REPORT_IsSaveAnimDone(void *report);
extern void REPORT_StopSaveAnim(void *report);
extern unsigned REPORT_CheckSaveCounter(void *report);
extern void *C_GEAR_POWER_ONOFF_Create(void *work, void *gameSystem, u32 heapId);
extern int C_GEAR_POWER_ONOFF_Update(void *powerOnoff);
extern void C_GEAR_POWER_ONOFF_Delete(void *powerOnoff);
void FIELD_SUBSCREEN_InitBeaconView(FieldSubscreen *work);
void FIELD_SUBSCREEN_ExitBeaconView(FieldSubscreen *work);
int FIELD_SUBSCREEN_UpdateBeaconView(FieldSubscreen *work);
int FIELD_SUBSCREEN_UpdateBeaconViewNoTransition(FieldSubscreen *work);
int FIELD_SUBSCREEN_CheckBeaconViewRequest(FieldSubscreen *work);
void FIELD_SUBSCREEN_InitDowsing(FieldSubscreen *work);
void FIELD_SUBSCREEN_ExitDowsing(FieldSubscreen *work);
int FIELD_SUBSCREEN_UpdateDowsing(FieldSubscreen *work);
int FIELD_SUBSCREEN_UpdateDowsingNoTransition(FieldSubscreen *work);
void FIELD_SUBSCREEN_InitReport(FieldSubscreen *work);
void FIELD_SUBSCREEN_ExitReport(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateReport(FieldSubscreen *work);
void FIELD_SUBSCREEN_UpdateReportNoTransition(FieldSubscreen *work);
int FIELD_SUBSCREEN_IsReportReady(FieldSubscreen *work);
void FIELD_SUBSCREEN_PrepareReportSave(FieldSubscreen *work);
void FIELD_SUBSCREEN_StartReportSaveAnim(FieldSubscreen *work);
int FIELD_SUBSCREEN_IsReportSaveAnimDone(FieldSubscreen *work);
void FIELD_SUBSCREEN_StopReportSaveAnim(FieldSubscreen *work);
int FIELD_SUBSCREEN_CheckReportSaveCounter(FieldSubscreen *work);
void FIELD_SUBSCREEN_InitPowerOnoff(FieldSubscreen *work);
int FIELD_SUBSCREEN_UpdatePowerOnoff(FieldSubscreen *work);
void FIELD_SUBSCREEN_ExitPowerOnoff(FieldSubscreen *work);
extern unsigned char abs_id_20[];
extern unsigned char abs_id_21[];
extern unsigned char abs_id_22[];
extern unsigned char abs_id_23[];
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_Free(void *p);
extern int FIELDMAP_IsEventActive(void *fieldMap);
extern void WIPE_SYS_Start(void *screen, u32 mainPattern, u32 subPattern, u32 color, u32 frames, u32 wait, u32 heapId);
extern u32 WIPE_SYS_EndCheck(void);
extern void *FIELDMAP_GetGameSystem(void *fieldMap);
extern u16 FIELDMAP_GetZoneId(void *fieldMap);
extern void *GAMESYSTEM_GetGameData(void *gameSystem);
extern void *GAME_DATA_GetSaveControl(void *gameData);
extern void *BLOCK20_SAVEDATA_GetBlock(void *cgearSaveBase);
extern u32 CGEAR_SAVE_GetObtained(void *cgearSave);
extern u32 ZONEDATA_IsZone34(void);
extern u32 ZONEDATA_IsZone4BPair(u32);
extern struct FieldVReq *FIELDMAP_GetVReq(void *fieldMap);
extern void FLD_VREQ_SetMainBlendBrightnessExt(struct FieldVReq *vreq, int a, int b, int c, int d, int e);
extern void FIELD_MSGBG_SetBlendThunk(u32);
extern void BG_SYS_ClearSlot(u32 i);
extern void FIELD_MSGBG_LoadWindowGraphics(u32, u32);
extern u8 BLOCK20_SAVEDATA_GetPanelState(void *cgearSave);
extern void BLOCK20_SAVEDATA_SetPanelState(void *cgearSave, u32 commState);
extern u32 GAMESYSTEM_GetAlwaysNetFlag(void *gameSystem);
extern u32 GAMESYSTEM_IsNetOffBySleep(void *gameSystem);
extern void GAMESYSTEM_ClearNetOffBySleep(void *gameSystem);
extern int GF_OVERLAY_Load(int);
extern void *C_GEAR_Create(void *cgearSave, FieldSubscreen *work, void *gameSystem, int showPowerOff);
extern void *C_GEAR_Open(void *cgearSave, FieldSubscreen *work, void *gameSystem, void (*callback)(int), u32 callbackArg, u32 commState);
extern void C_GEAR_Destroy(void *cgear);
extern void GF_OVERLAY_Unload(int);
void FIELD_SUBSCREEN_SetPanelResult(FieldSubscreen *work, int result);
void FIELD_SUBSCREEN_InitCGear(FieldSubscreen *work);
void FIELD_SUBSCREEN_InitCGearWithCallback(FieldSubscreen *work);
u32 FIELD_SUBSCREEN_ResolveMode(FieldSubscreen *work, u32 mode);

extern u8 d_021DDE48[];
extern const FieldSubscreenMode d_021D872C[];
extern unsigned char abs_id_1d[];
extern unsigned char abs_id_1e[];
extern unsigned char abs_id_1f[];

/*
 * Mode table d_021D872C: one FieldSubscreenMode row per mode, 0x1C bytes each.
 * The matching pool entries are the table address plus the field offset, so
 * every access is written as d_021D872C[mode].field.
 */
FieldSubscreen *FIELD_SUBSCREEN_Create(u32 heapId, void *fieldMap, u32 mode)
{
    FieldSubscreen *work;
    u32 resolved;

    work = (FieldSubscreen *)GFL_HEAP_Alloc((u16)heapId, sizeof(FieldSubscreen), 1, (const char *)d_021DDE48, 0x13c);
    work->state = FIELD_SUBSCREEN_STATE_RUN;
    work->heapId = heapId;
    work->cgear = 0;
    work->fieldMap = fieldMap;
    resolved = FIELD_SUBSCREEN_ResolveMode(work, mode);
    work->mode = resolved;
    work->nextMode = resolved;
    d_021D872C[resolved].init(work, FIELD_SUBSCREEN_MODE_NONE);
    return work;
}

u8 FIELD_SUBSCREEN_Delete(FieldSubscreen *work)
{
    u32 mode = work->mode;
    d_021D872C[mode].exit(work);
    GFL_HEAP_Free(work);
    return mode;
}

void FIELD_SUBSCREEN_Main(FieldSubscreen *work)
{
    switch (work->state) {
    case FIELD_SUBSCREEN_STATE_RUN:
        d_021D872C[work->mode].update(work, FIELDMAP_IsEventActive(work->fieldMap) == 0);
        break;
    case FIELD_SUBSCREEN_STATE_FADE_OUT:
        WIPE_SYS_Start((void *)4, 0, 0, 0, 1, 1, work->heapId);
        work->state = FIELD_SUBSCREEN_STATE_FADE_OUT_WAIT;
        break;
    case FIELD_SUBSCREEN_STATE_FADE_OUT_WAIT:
        if (WIPE_SYS_EndCheck() == 1) {
            d_021D872C[work->mode].exit(work);
            d_021D872C[work->nextMode].init(work, work->mode);
            work->mode = work->nextMode;
            work->state = FIELD_SUBSCREEN_STATE_FADE_IN;
        }
        break;
    case FIELD_SUBSCREEN_STATE_HALT:
        break;
    case FIELD_SUBSCREEN_STATE_FADE_IN:
        WIPE_SYS_Start((void *)4, 1, 1, 0, 1, 1, work->heapId);
        work->state = FIELD_SUBSCREEN_STATE_FADE_IN_WAIT;
        break;
    case FIELD_SUBSCREEN_STATE_FADE_IN_WAIT:
        if (WIPE_SYS_EndCheck() == 1) {
            work->state = FIELD_SUBSCREEN_STATE_RUN;
        }
        d_021D872C[work->mode].update(work, FIELDMAP_IsEventActive(work->fieldMap) == 0);
        break;
    }
}

void FIELD_SUBSCREEN_MainNoTransition(FieldSubscreen *work)
{
    s32 busy;

    switch (work->state) {
    case FIELD_SUBSCREEN_STATE_RUN:
        if (d_021D872C[work->mode].updateNoTransition != 0) {
            busy = FIELDMAP_IsEventActive(work->fieldMap);
            d_021D872C[work->mode].updateNoTransition(work, busy == 0);
        }
        break;
    case FIELD_SUBSCREEN_STATE_FADE_OUT:
    case FIELD_SUBSCREEN_STATE_FADE_OUT_WAIT:
    case FIELD_SUBSCREEN_STATE_HALT:
    case FIELD_SUBSCREEN_STATE_FADE_IN:
    case FIELD_SUBSCREEN_STATE_FADE_IN_WAIT:
        break;
    }
}

int FIELD_SUBSCREEN_CheckModeRequest(FieldSubscreen *work, u32 mode)
{
    if (work->state == FIELD_SUBSCREEN_STATE_RUN && d_021D872C[work->mode].checkRequest != 0)
        return d_021D872C[work->mode].checkRequest(work, mode);
    return 0;
}

int FIELD_SUBSCREEN_IsIdle(FieldSubscreen *work)
{
    if (work->state == FIELD_SUBSCREEN_STATE_RUN) {
        return 1;
    }
    return 0;
}

/* Maps the requested mode to the mode that can run: the C-Gear request falls
 * back to the no-C-Gear mode when the save has no C-Gear. */
u32 FIELD_SUBSCREEN_ResolveMode(FieldSubscreen *work, u32 mode)
{
    void *gameData;
    u32 zoneId;
    void *cgearSave;
    if (mode == FIELD_SUBSCREEN_MODE_CGEAR) {
        gameData = GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(work->fieldMap));
        zoneId = FIELDMAP_GetZoneId(work->fieldMap);
        if (ZONEDATA_IsZone34() != 0 || ZONEDATA_IsZone4BPair(zoneId) != 0)
            return FIELD_SUBSCREEN_MODE_NO_CGEAR;
        cgearSave = BLOCK20_SAVEDATA_GetBlock(GAME_DATA_GetSaveControl(gameData));
        if (CGEAR_SAVE_GetObtained(cgearSave) == 0)
            return FIELD_SUBSCREEN_MODE_NO_CGEAR;
    }
    return mode;
}

int FIELD_SUBSCREEN_RequestMode(FieldSubscreen *work, u32 mode)
{
    work->nextMode = FIELD_SUBSCREEN_ResolveMode(work, mode);
    work->state = FIELD_SUBSCREEN_STATE_FADE_OUT;
    return 1;
}

void FIELD_SUBSCREEN_ChangeModeNow(FieldSubscreen *work, u32 mode)
{
    u32 resolved = FIELD_SUBSCREEN_ResolveMode(work, mode);
    d_021D872C[work->mode].exit(work);
    work->nextMode = resolved;
    d_021D872C[resolved].init(work, work->mode);
    work->mode = work->nextMode;
    work->state = FIELD_SUBSCREEN_STATE_RUN;
}

int FIELD_SUBSCREEN_RequestModeWithCallback(FieldSubscreen *work, u32 mode, void (*callback)(int), u32 callbackArg)
{
    work->callback = callback;
    work->callbackArg = callbackArg;
    work->nextMode = FIELD_SUBSCREEN_ResolveMode(work, mode);
    work->state = FIELD_SUBSCREEN_STATE_FADE_OUT;
    return 1;
}

u32 FIELD_SUBSCREEN_GetMode(FieldSubscreen *work)
{
    return work->mode;
}

int FIELD_SUBSCREEN_GetPanelResult(FieldSubscreen *work)
{
    if (work != 0) {
        return work->panelResult;
    }
    return 0;
}

void FIELD_SUBSCREEN_SetPanelResult(FieldSubscreen *work, int result)
{
    if (work == 0)
        return;
    work->panelResult = result;
}

void FIELD_SUBSCREEN_ClearPanelResult(FieldSubscreen *work)
{
    FIELD_SUBSCREEN_SetPanelResult(work, 0);
}

void FIELD_SUBSCREEN_ResumeField(FieldSubscreen *work, u32 heapId)
{
    FLD_VREQ_SetMainBlendBrightnessExt(FIELDMAP_GetVReq(work->fieldMap), 1, 0, 0, 0, 0);
    FIELD_MSGBG_SetBlendThunk(0);
    BG_SYS_ClearSlot(1);
    FIELD_MSGBG_LoadWindowGraphics(1, heapId);
}

void FIELD_SUBSCREEN_InitCGear(FieldSubscreen *work)
{
    void *gameSystem;
    void *cgearSave;
    u32 cgearPowered, commState;
    gameSystem = FIELDMAP_GetGameSystem(work->fieldMap);
    cgearSave = BLOCK20_SAVEDATA_GetBlock(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem)));
    GF_OVERLAY_Load((int)abs_id_1d);
    cgearPowered = BLOCK20_SAVEDATA_GetPanelState(cgearSave);
    commState = GAMESYSTEM_GetAlwaysNetFlag(gameSystem);
    work->cgear = C_GEAR_Create(cgearSave, work, gameSystem, commState == 1 && cgearPowered == 0);
    BLOCK20_SAVEDATA_SetPanelState(cgearSave, commState);
    if (GAMESYSTEM_IsNetOffBySleep(gameSystem) != 0)
        GAMESYSTEM_ClearNetOffBySleep(gameSystem);
}

void FIELD_SUBSCREEN_InitCGearWithCallback(FieldSubscreen *work)
{
    void *gameSystem;
    void *cgearSaveBase;
    void *cgearSave;
    u32 commState;
    gameSystem = FIELDMAP_GetGameSystem(work->fieldMap);
    cgearSaveBase = GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem));
    GF_OVERLAY_Load((int)abs_id_1d);
    commState = GAMESYSTEM_GetAlwaysNetFlag(gameSystem);
    cgearSave = BLOCK20_SAVEDATA_GetBlock(cgearSaveBase);
    work->cgear = C_GEAR_Open(cgearSave, work, FIELDMAP_GetGameSystem(work->fieldMap), work->callback, work->callbackArg, commState);
    BLOCK20_SAVEDATA_SetPanelState(cgearSave, commState);
    if (GAMESYSTEM_IsNetOffBySleep(gameSystem) != 0)
        GAMESYSTEM_ClearNetOffBySleep(gameSystem);
    work->mode = 0;
    work->nextMode = 0;
}

void FIELD_SUBSCREEN_ExitCGear(FieldSubscreen *work)
{
    C_GEAR_Destroy(work->cgear);
    GF_OVERLAY_Unload((int)abs_id_1d);
}

u32 FIELD_3DBG_ExitCGear(FieldSubscreen *work) { return C_GEAR_Nop((u32)work->cgear); }

u32 FIELD_3DBG_UpdateCGear(FieldSubscreen *work, u32 active)
{
    u32 gameSystem, savedValue;
    if (active != 0) {
        gameSystem = (u32)FIELDMAP_GetGameSystem(work->fieldMap);
        savedValue = (u32)BLOCK20_SAVEDATA_GetBlock(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((void *)gameSystem)));
        if (GAMESYSTEM_IsNetOffBySleep((void *)gameSystem) != 0) {
            if (GAMESYSTEM_GetAlwaysNetFlag((void *)gameSystem) != 0) {
                GAMESYSTEM_ClearNetOffBySleep((void *)gameSystem);
            } else if (C_GEAR_Restart((int *)work->cgear) != 0) {
                BLOCK20_SAVEDATA_SetPanelState((void *)savedValue, 0);
                GAMESYSTEM_ClearNetOffBySleep((void *)gameSystem);
            }
        }
    }
    return C_GEAR_Update((u32)work->cgear, active);
}

int FIELD_3DBG_HandleCGearInput(FieldSubscreen *work, int button)
{
    return C_GEAR_HandleCommand(work->cgear, button, work);
}

/*
 * Mode glue of the field sub-screen (field_subscreen.c): the init, update and
 * exit functions that rows of the mode table d_021D872C point to, and the
 * accessors other files call on the running mode. Modes in this file:
 *   1 start menu (field_menu.c), 2 Union Room panel (overlay 31),
 *   3 Entralink panel (intrude_subdisp.c), 5 panel shown while the save has
 *   no C-Gear (overlay 30).
 * Mode 0 (C-Gear) and mode 8 (C-Gear with callback) are in field_subscreen.c.
 */

/* Mode 5 init: loads overlay 30 and creates the panel from the C-Gear save. */
void FIELD_SUBSCREEN_InitNoGear(FieldSubscreen *work)
{
    void *cgearSave;

    GF_OVERLAY_Load(FIELD_SUBSCREEN_OVERLAY_NO_GEAR);
    cgearSave = BLOCK20_SAVEDATA_GetBlock(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(work->fieldMap))));
    work->cgear = NO_GEAR_Create(cgearSave, work, FIELDMAP_GetGameSystem(work->fieldMap));
}

/* Mode 5 exit. */
void FIELD_SUBSCREEN_ExitNoGear(FieldSubscreen *work)
{
    NO_GEAR_Destroy(work->cgear);
    GF_OVERLAY_Unload(FIELD_SUBSCREEN_OVERLAY_NO_GEAR);
}

/* Mode 5 slot at table offset 0x14: calls the panel's empty hook. */
void FIELD_SUBSCREEN_NoGearHook(FieldSubscreen *work) { NO_GEAR_Hook(work->cgear); }

/* Mode 5 update. */
void FIELD_SUBSCREEN_UpdateNoGear(FieldSubscreen *work) { NO_GEAR_Update(work->cgear); }

/* Mode 1 init: sets up the lower screen BG and the start menu, and the info
 * window when the menu layout is not 1. The menu slides in when the previous
 * mode was the C-Gear or one of modes 2 to 6. */
void FIELD_SUBSCREEN_InitMenu(FieldSubscreen *work, u32 prevMode)
{
    void *gameSystem;
    u32 zoneId;
    void *gameData;
    void *eventWork;
    u32 slideIn;

    gameSystem = FIELDMAP_GetGameSystem(work->fieldMap);
    zoneId = GAME_DATA_GetPlayerZoneId(GAMESYSTEM_GetMyPlayerWork(gameSystem));
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    eventWork = GAME_DATA_GetEventWork(gameData);
    slideIn = 0;
    if (prevMode == FIELD_SUBSCREEN_MODE_CGEAR || prevMode - 2 <= 4)
        slideIn = 1;
    BG_SYS_InitBgLayer(4, &d_021D8708, 0);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_FreeSlot(4);
    BG_SYS_ClearLayer(4, 0);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    work->cgear = (void *)FIELD_MENU_Create(0x70, work->heapId, work, work->fieldMap, slideIn);
    if (FIELD_MENU_GetLayoutType(gameData, eventWork, zoneId) != 1)
        INFOWIN_Init(4, 0xe, gameData, work->heapId);
    FIELD_MENU_LoadFrameBg(work->heapId, slideIn);
}

/* Mode 1 exit. */
void FIELD_SUBSCREEN_ExitMenu(FieldSubscreen *work)
{
    void *gameSystem;
    u32 zoneId;
    void *gameData;

    gameSystem = FIELDMAP_GetGameSystem(work->fieldMap);
    zoneId = GAME_DATA_GetPlayerZoneId(GAMESYSTEM_GetMyPlayerWork(gameSystem));
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    if (FIELD_MENU_GetLayoutType(gameData, GAME_DATA_GetEventWork(gameData), zoneId) != 1)
        INFOWIN_Exit();
    FIELD_MENU_Delete((struct FieldMenu *)work->cgear);
    BG_SYS_FreeLayerBuf(4);
}

/* Mode 1 update. */
void FIELD_SUBSCREEN_UpdateMenu(FieldSubscreen *work)
{
    INFOWIN_Update(FIELD_MENU_Update((struct FieldMenu *)work->cgear));
}

/* Mode 1 update outside transitions. */
void FIELD_SUBSCREEN_UpdateMenuNoTransition(FieldSubscreen *work) { FIELD_MENU_ApplyBgScroll((struct FieldMenu *)work->cgear); }

/* Button the start menu has selected; 0 when the menu is not the running mode. */
u32 FIELD_SUBSCREEN_GetMenuSelectedButton(FieldSubscreen *work)
{
    if (FIELD_SUBSCREEN_GetMode(work) != FIELD_SUBSCREEN_MODE_MENU) {
        return 0;
    }
    return FIELD_MENU_GetSelectedButtonId((struct FieldMenu *)work->cgear);
}

/* Selects a button of the start menu when it is the running mode. */
void FIELD_SUBSCREEN_SetMenuSelectedButton(FieldSubscreen *work, u32 buttonId)
{
    if (FIELD_SUBSCREEN_GetMode(work) == FIELD_SUBSCREEN_MODE_MENU)
        FIELD_MENU_SelectButton((struct FieldMenu *)work->cgear, buttonId);
}

/*
 * Loads the lower screen backdrop (palette, tiles and tile map from archive
 * 0x47) and shows layer 1 of the field request block.
 * Lever: ARC_TOOL_CreateHandle takes (id, heap); passing heapId as its second argument
 * is what gives heapId its register before the constant's.
 */
void FIELD_SUBSCREEN_LoadBackdrop(FieldSubscreen *work, u32 heapId)
{
    struct ArchiveHandle *archive = ARC_TOOL_CreateHandle(0x47, heapId);
    ARC_UTIL_UploadPaletteFromHandle(archive, 0, 0, 0x140, 0x140, 0x20, heapId);
    ARC_UTIL_UploadBgCharFromHandle(archive, 3, 1, 0x64, 0, 0, heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(archive, 0xf, 1, 0, 0x64, 0, 0, heapId);
    ARC_TOOL_DeleteHandle(archive);
    FLD_VREQ_SetMainBlendBrightnessExt(FIELDMAP_GetVReq(work->fieldMap), 1, 0, 0, 0, -6);
    FLD_VREQ_SetBgVisible(FIELDMAP_GetVReq(work->fieldMap), 1, 1);
}

/* Panel handle of the running C-Gear mode (mode 0 or 8); 0 for other modes. */
void *FIELD_SUBSCREEN_GetCGear(FieldSubscreen *work)
{
    if (work->mode == FIELD_SUBSCREEN_MODE_CGEAR || work->mode == FIELD_SUBSCREEN_MODE_CGEAR_CALLBACK)
        return work->cgear;
    return 0;
}

/* Mode 2 init: loads overlay 31 and creates the Union Room panel. */
void FIELD_SUBSCREEN_InitUnion(FieldSubscreen *work)
{
    GF_OVERLAY_Load(FIELD_SUBSCREEN_OVERLAY_UNION);
    work->cgear = UNION_SUBDISP_Create(FIELDMAP_GetGameSystem(work->fieldMap));
}

/* Mode 2 exit. */
void FIELD_SUBSCREEN_ExitUnion(FieldSubscreen *work)
{
    UNION_SUBDISP_Delete(work->cgear);
    GF_OVERLAY_Unload(FIELD_SUBSCREEN_OVERLAY_UNION);
}

/* Mode 2 update: the panel takes touch input only while the Union Room link runs. */
void FIELD_SUBSCREEN_UpdateUnion(FieldSubscreen *work, u32 isFieldIdle)
{
    void *gameSystem = FIELDMAP_GetGameSystem(work->fieldMap);
    if (isFieldIdle == 1 && UNION_MAIN_IsIdle(gameSystem) == 0)
        isFieldIdle = 0;
    UNION_SUBDISP_Draw(work->cgear, isFieldIdle);
}

/* Mode 2 update outside transitions. */
void FIELD_SUBSCREEN_UpdateUnionNoTransition(FieldSubscreen *work, u32 isFieldIdle)
{
    void *gameSystem = FIELDMAP_GetGameSystem(work->fieldMap);
    if (isFieldIdle == 1 && UNION_MAIN_IsIdle(gameSystem) == 0)
        isFieldIdle = 0;
    UNION_SUBDISP_Update(work->cgear, isFieldIdle);
}

/* Mode 3 init: creates the Entralink panel (the overlay is already loaded). */
void FIELD_SUBSCREEN_InitIntrude(FieldSubscreen *work)
{
    work->cgear = INTRUDE_SUBDISP_Init(FIELDMAP_GetGameSystem(work->fieldMap));
}

/* Mode 3 exit. */
void FIELD_SUBSCREEN_ExitIntrude(FieldSubscreen *work)
{
    INTRUDE_SUBDISP_Exit(work->cgear);
}

/* Mode 3 update. */
void FIELD_SUBSCREEN_UpdateIntrude(FieldSubscreen *work, int isFieldIdle)
{
    INTRUDE_SUBDISP_Update(work->cgear, isFieldIdle);
}

/* Mode 3 update outside transitions: redraws the panel. */
void FIELD_SUBSCREEN_DrawIntrude(FieldSubscreen *work)
{
    INTRUDE_SUBDISP_Draw(work->cgear);
}

/* Mode 3 request check: the panel's touch selection may start an event. */
void *FIELD_SUBSCREEN_CheckIntrudeRequest(FieldSubscreen *work, int mode)
{
    return INTRUDE_SUBDISP_EventCheck(work->cgear, mode, work);
}

/*
 * Glue of four rows of the field sub-screen mode table (modes 4, 6, 7, 9).
 * Each function forwards to the panel overlay loaded for that mode; the panel
 * handle lives in work->cgear. The overlay id is an absolute symbol, so it is
 * passed through a pointer cast.
 */

/* Mode 4 (beacon view, overlay 0x20) init: load the overlay and create the panel. */
void FIELD_SUBSCREEN_InitBeaconView(FieldSubscreen *work)
{
    GF_OVERLAY_Load((int)abs_id_20);
    work->cgear = BEACON_VIEW_Create(FIELDMAP_GetGameSystem(work->fieldMap), work);
}

/* Mode 4 exit: delete the beacon view panel and unload its overlay. */
void FIELD_SUBSCREEN_ExitBeaconView(FieldSubscreen *work)
{
    BEACON_VIEW_Delete(work->cgear);
    GF_OVERLAY_Unload((int)abs_id_20);
}

/* Mode 4 update. */
int FIELD_SUBSCREEN_UpdateBeaconView(FieldSubscreen *work) { return BEACON_VIEW_Update(work->cgear); }

/* Mode 4 update outside transitions. */
int FIELD_SUBSCREEN_UpdateBeaconViewNoTransition(FieldSubscreen *work) { return BEACON_VIEW_MainPrintQueue(work->cgear); }

/* Mode 4 request check. */
int FIELD_SUBSCREEN_CheckBeaconViewRequest(FieldSubscreen *work) { return BEACON_VIEW_CreateLeaveEvent(work->cgear); }

/* Mode 6 (dowsing, overlay 0x21) init: load the overlay and create the panel. */
void FIELD_SUBSCREEN_InitDowsing(FieldSubscreen *work)
{
    GF_OVERLAY_Load((int)abs_id_21);
    work->cgear = DOWSING_Create(0x70, work->heapId, work, work->fieldMap);
}

/* Mode 6 exit: delete the dowsing panel and unload its overlay. */
void FIELD_SUBSCREEN_ExitDowsing(FieldSubscreen *work)
{
    DOWSING_Delete(work->cgear);
    GF_OVERLAY_Unload((int)abs_id_21);
}

/* Mode 6 update. */
int FIELD_SUBSCREEN_UpdateDowsing(FieldSubscreen *work) { return DOWSING_Update(work->cgear); }

/* Mode 6 update outside transitions. */
int FIELD_SUBSCREEN_UpdateDowsingNoTransition(FieldSubscreen *work) { return DOWSING_UpdateDisplay(work->cgear); }

/* Mode 7 (save report, overlay 0x22) init: load the overlay and create the panel. */
void FIELD_SUBSCREEN_InitReport(FieldSubscreen *work)
{
    GF_OVERLAY_Load((int)abs_id_22);
    work->cgear = REPORT_Create(FIELDMAP_GetGameSystem(work->fieldMap), work->heapId);
}

/* Mode 7 exit: delete the report panel and unload its overlay. */
void FIELD_SUBSCREEN_ExitReport(FieldSubscreen *work)
{
    REPORT_Delete(work->cgear);
    GF_OVERLAY_Unload((int)abs_id_22);
}

/* Mode 7 update: show the panel objects once the print queue is idle. */
void FIELD_SUBSCREEN_UpdateReport(FieldSubscreen *work)
{
    REPORT_ShowPartyIcons(work->cgear);
}

/* Mode 7 update outside transitions: windows and texts of the panel. */
void FIELD_SUBSCREEN_UpdateReportNoTransition(FieldSubscreen *work)
{
    REPORT_UpdateWindows(work->cgear);
}

/* Report panel: true once its windows are shown (state 3). Called by the report event. */
int FIELD_SUBSCREEN_IsReportReady(FieldSubscreen *work)
{
    return REPORT_IsReady(work->cgear);
}

/* Report panel: read the save counters and reset the progress bar. */
void FIELD_SUBSCREEN_PrepareReportSave(FieldSubscreen *work)
{
    REPORT_PrepareSave(work->cgear);
}

/* Report panel: start the saving animation. */
void FIELD_SUBSCREEN_StartReportSaveAnim(FieldSubscreen *work)
{
    REPORT_StartSaveAnim(work->cgear);
}

/* Report panel: true when the saving animation has run to its end. */
int FIELD_SUBSCREEN_IsReportSaveAnimDone(FieldSubscreen *work)
{
    return REPORT_IsSaveAnimDone(work->cgear);
}

/* Report panel: stop the saving animation (the save failed). */
void FIELD_SUBSCREEN_StopReportSaveAnim(FieldSubscreen *work)
{
    REPORT_StopSaveAnim(work->cgear);
}

/* Report panel: true when the first counter reached a third of the second one. */
int FIELD_SUBSCREEN_CheckReportSaveCounter(FieldSubscreen *work)
{
    return REPORT_CheckSaveCounter(work->cgear);
}

/* Mode 9 (power on/off, overlay 0x23) init: load the overlay and create the panel. */
void FIELD_SUBSCREEN_InitPowerOnoff(FieldSubscreen *work)
{
    GF_OVERLAY_Load((int)abs_id_23);
    work->cgear = C_GEAR_POWER_ONOFF_Create(work, FIELDMAP_GetGameSystem(work->fieldMap), 0x70);
}

/* Mode 9 update. */
int FIELD_SUBSCREEN_UpdatePowerOnoff(FieldSubscreen *work) { return C_GEAR_POWER_ONOFF_Update(work->cgear); }

/* Mode 9 exit: delete the power on/off panel and unload its overlay. */
void FIELD_SUBSCREEN_ExitPowerOnoff(FieldSubscreen *work)
{
    C_GEAR_POWER_ONOFF_Delete(work->cgear);
    GF_OVERLAY_Unload((int)abs_id_23);
}
