/*
 * file:     c_gear.c
 * unit:     yes
 * function: C_GEAR_IsColumnRowValid, C_GEAR_SetStepFunc, C_GEAR_ChangeStep, C_GEAR_GetHexNeighbors, C_GEAR_SpawnRippleActor, C_GEAR_AcquireActorSlot, C_GEAR_IsTileActorIdle, C_GEAR_StepRipple, C_GEAR_StartRippleFlood, C_GEAR_HitTestTile, C_GEAR_InitTabTimersPowerOn, C_GEAR_InitTabTimersPowerOff, C_GEAR_ResetTabPalettes, C_GEAR_UpdateTabInput, C_GEAR_IsCallTabActive, C_GEAR_TickTabTimers, C_GEAR_SetTabMode, C_GEAR_UpdateTabPalettes, C_GEAR_UpdateTabPaletteKind3, C_GEAR_UpdateTabPaletteKind1, C_GEAR_UpdateTabPaletteKind2, C_GEAR_UpdateTabPaletteKind0, C_GEAR_UpdateTabPaletteKind4, C_GEAR_BlendTabPalette, C_GEAR_LoadTargetPalette, C_GEAR_SelectTabPalette, C_GEAR_InitTiles, C_GEAR_StepTiles, C_GEAR_IsAnyTileFlashing, C_GEAR_StopTileFlashes, C_GEAR_InitTile, C_GEAR_ResetTileFlash, C_GEAR_StartTileFlash, C_GEAR_StopTileFlash, C_GEAR_StepTileFlash, C_GEAR_SetTileFlashStep, C_GEAR_IsTileFlashing, C_GEAR_GetTilePalette, C_GEAR_InitTabTimer, C_GEAR_TickTabTimer, C_GEAR_IsTabTimerFull, C_GEAR_ResetTabTimerCount, C_GEAR_ClearTabTimerCount, C_GEAR_GetTabTimerCount, C_GEAR_SetTabTimerRunning, C_GEAR_TileToScreen, C_GEAR_IsIdleForInput, C_GEAR_CountCellsOfKind, C_GEAR_TintPalettes, C_GEAR_StartFlashFade, C_GEAR_FadeBackground, C_GEAR_FadeAccentColors, C_GEAR_StartFadeOut, C_GEAR_StartFadeIn, C_GEAR_StopFade, C_GEAR_GetFadeRequestBits, C_GEAR_DrawEmptyBoard, C_GEAR_StepIntroTiles, C_GEAR_StepOutroTiles, C_GEAR_ResetAllTiles, C_GEAR_DrawTile, C_GEAR_FindCellOfKind, C_GEAR_DrawAllCells, C_GEAR_LoadSkin, C_GEAR_LoadSpriteResources, C_GEAR_LoadFrameGraphics, C_GEAR_SetupBackgrounds, C_GEAR_SetupSubScreenBlend, C_GEAR_HandleButton, C_GEAR_OnButtonEvent, C_GEAR_SetPaintModeIcon, C_GEAR_CreateHudActors, C_GEAR_SetTileMarkersVisible, C_GEAR_SetAllActorsVisible, C_GEAR_SetSplashActorsVisible, C_GEAR_CreateSplashActors, C_GEAR_DeleteSplashActors, C_GEAR_IsSplashDone, C_GEAR_CreateBarActors, C_GEAR_UpdateBeaconColors, C_GEAR_DeleteBarActors, C_GEAR_LoadGraphics, C_GEAR_DeleteActors, C_GEAR_FreeGraphics, C_GEAR_GetBatteryFrame, C_GEAR_UpdateClock, C_GEAR_UpdateTileMarkers, C_GEAR_RunFrame, C_GEAR_StepIdle, C_GEAR_StepIntroEnd, C_GEAR_StepOpen, C_GEAR_StepClose, C_GEAR_LoadCustomBackground, C_GEAR_OnCommDisconnect, C_GEAR_OnCommEvent, C_GEAR_TransferPalettesTask, C_GEAR_Init, C_GEAR_Cleanup, C_GEAR_Create, C_GEAR_Open, C_GEAR_Update, C_GEAR_Nop, C_GEAR_Destroy, C_GEAR_Restart, C_GEAR_HandleCommand, C_GEAR_IsLastCommandKind5, C_GEAR_StopRingtone, C_GEAR_SetCellKind, C_GEAR_GetCellKind, C_GEAR_IsCellMarked, C_GEAR_IsCellKind, CTRDG_IsAgbCartridge, C_GEAR_StepIconAnim, C_GEAR_StepFadeIcon, C_GEAR_NoOp, C_GEAR_ShowOffIndicator, C_GEAR_ShowCommIndicator, C_GEAR_HideCommIndicator, C_GEAR_HideOffIndicator, C_GEAR_TickIndicators, C_GEAR_ApplyIndicators, C_GEAR_IsAnyIndicatorShown, C_GEAR_TickTabFrame, C_GEAR_CreateFadeFx, C_GEAR_DeleteFadeFx, C_GEAR_StartFadeFx, C_GEAR_StepFadeFx, C_GEAR_StartPanelEvent, C_GEAR_PanelEventMain, C_GEAR_StartSelectedRipple, C_GEAR_DeleteActorSlots, C_GEAR_AreActorSlotsIdle, C_GEAR_StepWaitSlots, C_GEAR_SetPowerState, C_GEAR_LoadSkinMember
 * address:  0x021EFEC0
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   CLACT_SetActorSurfacePosAxis  0x0204B49C  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_GetActorAnimSeqCount  0x0204B918  arm
 *   CLACT_GetActorAnimFrame  0x0204B8F4  arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   d_021F333C     0x021F333C  data  a4
 *   d_021F334C     0x021F334C  data  a4
 *   d_021F31BC     0x021F31BC  data  ov029  a2
 *   d_021F31AB     0x021F31AB  data  ov029  a1
 *   d_021F31B0     0x021F31B0  data  ov029  a1
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetField1A0  0x0201283C  thumb
 *   WIH_DWC_PollStatus  0x0201058C  thumb
 *   INTRUDE_COMM_GetRequestState  0x02158630  thumb  ov010
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021F31EC     0x021F31EC  data  ov029  a4
 *   d_021F31F8     0x021F31F8  data  ov029  a4
 *   d_021F3255     0x021F3255  data  ov029  a1
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021F3292 0x021F3292 data ov029 a1
 *   d_021F3204 0x021F3204 data ov029 a1
 *   PALANM_CopyToSlot  0x020215BC  thumb
 *   d_021F31A8     0x021F31A8  data  ov029  a1
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   d_021F323C     0x021F323C  data  a1
 *   d_021F32B3 0x021F32B3 data a1
 *   d_021F3344     0x021F3344  data  a4
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GXx_GetMasterBrightness_ 0x0207D55C arm
 *   ICA_ANIME_GetField20 0x0201210C thumb
 *   FIELDMAP_GetSubscreenBusy 0x02189A48 thumb ov021
 *   PALANM_GetDefaultWork  0x02021728  thumb
 *   PALANM_GetTransWork  0x02021730  thumb
 *   PALANM_BlendColors  0x02021F64  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   d_021F31B6     0x021F31B6  data  a2
 *   PALANM_RequestFade  0x0202173C  thumb
 *   PALANM_ForceStopFade 0x02021B18 thumb
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   d_021F3324     0x021F3324  data  a4
 *   d_021F331C     0x021F331C  data  a4
 *   d_021F3410     0x021F3410  data  a4
 *   d_021F31D4     0x021F31D4  data  a2
 *   d_021F348C     0x021F348C  data  a4
 *   d_021F3334     0x021F3334  data  a4
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   d_021F3354     0x021F3354  data  a4
 *   func_020091AC  0x020091AC  thumb
 *   d_021F332C     0x021F332C  data  a4
 *   func_02049F78  0x02049F78  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   GXS_LoadBGPltt  0x0207E468  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BG_SYS_CreateRun  0x0203FA08  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   func_02049990  0x02049990  arm
 *   d_021F31E0     0x021F31E0  data  a4
 *   d_021F32E0     0x021F32E0  data  a4
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   GFL_NET_RestartWithTimeout  0x0203D88C  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   d_021F31C8     0x021F31C8  data  a4
 *   d_021F33CC     0x021F33CC  data  a4
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_SetVisibleLayer  0x0204047C  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   d_021F338C     0x021F338C  data  ov029  a4
 *   d_021F33AC     0x021F33AC  data  a4
 *   d_021F336C     0x021F336C  data  ov029  a4
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   func_020355D8  0x020355D8  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   BG_SYS_DeleteHalf  0x0203FB44  arm
 *   func_020090E8  0x020090E8  thumb
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   CLACT_SetActorVisible  0x0204BA20  arm
 *   d_021F3526     0x021F3526  data  ov029  a1
 *   d_021F3531     0x021F3531  data  ov029  a1
 *   d_021F353C     0x021F353C  data  ov029  a1
 *   d_021F3548     0x021F3548  data  ov029  a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   GAME_BEACON_GetReceiveCount  0x02026C8C  thumb
 *   GAME_BEACON_GetNextNewLogIndex  0x02026CA0  thumb
 *   GAME_BEACON_GetLogByReceiveNo  0x02026C78  thumb
 *   GAME_BEACON_ACCESSOR_GetFavoriteColorIndex  0x02165CD8  thumb  ov010
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020090F0  0x020090F0  thumb
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_CreateRenderer  0x0204B034  arm
 *   CLACT_SetUnitRenderer  0x0204B258  arm
 *   BUTTON_MAN_Create  0x02051B84  arm
 *   d_021F3214     0x021F3214  data  a4
 *   d_021F3272     0x021F3272  data  a2
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   BUTTON_MAN_Delete  0x02051C6C  arm
 *   CLACT_DeleteRenderer  0x0204B084  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   UI_GetPowerState 0x0203568C arm
 *   d_021F3520 0x021F3520 data a1
 *   GF_STANDARD_SetField00  0x0203F4CC  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   BUTTON_MAN_UpdateSlots  0x02051C88  arm
 *   func_021F2BF0  0x021F2BF0  thumb  ov029
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SAVE_CONTROL_LoadExtraSaveWithBuffer  0x020072CC  thumb
 *   GF_STANDARD_SetupCalc  0x0203F1FC  arm
 *   BLOCK20_SAVEDATA_GetBlock  0x02009210  thumb
 *   func_0200910C  0x0200910C  thumb
 *   MUSICAL_DIST_SAVE_IsFooterSet  0x0200C6F0  thumb
 *   BG_SYS_LoadTileData  0x02040B1C  arm
 *   BG_SYS_LoadPltt  0x02040E78  arm
 *   BG_SYS_DecodeTile  0x02040AE0  arm
 *   func_0200734C  0x0200734C  thumb
 *   d_021F3554     0x021F3554  data  a4
 *   TCB_Main  0x02030D28  arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   ICA_ANIME_IsConfigFlagSet  0x0201214C  thumb
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   TCB_GetTaskOffset  0x02030CB0  arm
 *   TCB_Init  0x02030CBC  arm
 *   func_02009100  0x02009100  thumb
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   UI_SetSleepHookGlobal  0x02035010  arm
 *   UI_SetWakeHookGlobal  0x02035040  arm
 *   GAMESYSTEM_IsEventActive  0x020120D8  thumb
 *   INTRUDE_COMM_GetVisitProgress  0x021585E0  thumb  ov010
 *   INTRUDE_COMM_SetCompleted  0x02158614  thumb  ov010
 *   GFL_NET_RestartNoTimeout  0x0203D8AC  arm
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb
 *   PALANM_Delete  0x02021540  thumb
 *   TCB_Noop  0x02030DA4  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   func_02028A70  0x02028A70  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020056EC  0x020056EC  thumb
 *   FIELD_SOUND_SYSTEM_StartRingtone  0x02028A64  thumb
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb
 *   WIPE_ResetBrightness  0x02022230  thumb
 *   func_02009110 0x02009110 thumb
 *   func_02009134 0x02009134 thumb
 *   func_02009160 0x02009160 thumb
 *   gCGearFadeSteps     0x021F3224  data  a4
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   EVENT_GSYNC_Entry  0x02154668  thumb  ov000
 *   abs_id_0       0x00000000  data
 *   IRC_BATTLE_ENTRY_Create  0x021559E4  thumb  ov010
 *   SCRCMD_NETWORK_CreateWifiProcEvent  0x0215FBF4  thumb  ov010
 *   EVENT_RESEARCH_RADAR_CreateTopTask  0x02167044  thumb  ov010
 *   FIELD_COMM_ACTOR_CreateSubscreenChangeEvent  0x021945A4  thumb  ov021
 *   FIELD_STATUS_CreateSubProcCallbackEvent  0x02014808  thumb
 *   abs_id_124     0x0000007C  data
 *   d_021D4D40     0x021D4D40  data  ov124  a4
 *   FIELD_SUBSCREEN_CreateAnimTask  0x021D297C  thumb  ov021
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   CTRDGi_IsAgbCartridgeAtInit 0x02035c60 arm
 *   func_020091FC  0x020091FC  thumb
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef signed int s32;

#include "c_gear_types.h"

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_DB_BLDCNT (*(volatile u16 *)0x04001050)
#define REG_DB_MASTER_BRIGHT (*(volatile u16 *)0x0400106C)

typedef enum { Zero } ZeroValue;

struct GameEvent;
struct GameData;
struct PlayerSettings;
struct SaveData;
struct SaveCtrl;
struct CustomBgBuffer;
struct SoundSys;
struct BeaconLog;

struct BgTemplate {
    u32 x;
    u32 y;
    u32 bufSize;
    u32 baseTile;
    u8 screenSize;
    u8 colorMode;
    u8 screenBase;
    u8 charBase;
    u32 areaOver;
    u8 bgMode;
    u8 priority;
    u8 mosaic;
    u8 padding;
    u32 reserved;
};

typedef struct {
    u32 hour;
    u32 minute;
    u32 second;
} RtcTime;

extern void CLACT_SetActorAnimSeq(struct Actor *p, u16 value);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void CLACT_SetActorSurfacePosAxis(struct Actor *actor, s16 value, u32 space, u32 axis);
extern struct Actor *CLACT_CreateActor(struct ActorSystem *system, u32 i, u32 j, u32 k, const void *position, u16 space, u16 heap);
extern void CLACT_SetActorAutoAnim(struct Actor *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Actor *p, u32 v);
extern u16 CLACT_GetActorAnimSeqCount(struct Actor *p);
extern u32 CLACT_GetActorAnimFrame(struct Actor *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void *ICA_ANIME_GetField24(const struct GameSystem *gameSystem);
extern void *ICA_ANIME_GetField1C(const struct GameSystem *p);
extern void *GAME_DATA_GetField1A0(const void *gameData);
extern u32 WIH_DWC_PollStatus(void *key);
extern int INTRUDE_COMM_GetRequestState(void *eventWork);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern void MI_CpuFill8(void *, int, int);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BG_SYS_PushTile(unsigned int index);
extern unsigned int WIPE_SYS_EndCheck(void);
extern int GXx_GetMasterBrightness_(volatile u16 *reg);
extern void *ICA_ANIME_GetField20(const struct GameSystem *p);
extern int FIELDMAP_GetSubscreenBusy(void *gameData);
extern char *PALANM_GetDefaultWork(struct PalAnmSlot *palAnm, int bank);
extern char *PALANM_GetTransWork(struct PalAnmSlot *palAnm, int bank);
extern void PALANM_BlendColors(u16 *src, u16 *dst, int count, int weight, u16 color);
extern void MI_CpuCopy8(void *src, void *dst, int n);
extern int PALANM_RequestFade(struct PalAnmSlot *palAnm, u16 mask, u16 color, s16 step, u8 startLevel, u8 endLevel, u16 tint, struct FadeCtx *fadeCtx);
extern void PALANM_ForceStopFade(struct PalAnmSlot *o);
extern u32 PALANM_GetFadeRequestBits(const struct PalAnmSlot *palAnm);
extern u32 BG_SYS_GetBuf(int channel);
extern void func_020091AC(struct HexMap *obj, int row, int col, int kind, int marked, int flagged);
extern void *func_02049F78(void *archive, u32 member, CGearFileInfo **outFile, u32 heapId);
extern void DWCi_ScreenDC_FlushRange(void *a, u32 b);
extern void GXS_LoadBGPltt(void *a, u32 b, u32 c);
extern u32 GFL_HEAP_Free(void *p);
extern u32 BG_SYS_CreateRun(u32 a, u32 b, u32 c);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 CLACT_RegisterPalette(void *a, unsigned int b, unsigned int c, unsigned int d, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, unsigned int first, unsigned int second, unsigned int mode);
extern void GFL_NET_RestartWithTimeout(u32 a, u32 b);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);
extern void BG_SYS_SetTileEntry(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void G2x_SetBlendAlpha_(u32, int, int, int, int);
extern void func_020355D8(u8 v);
extern u32 TOUCHPANEL_GetPointCont(int *outX, int *outY);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern int C_GEAR_IsAnyIndicatorShown(CGearWork *work);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void func_020090E8(struct HexMap *obj, u8 value);
extern void CLACT_SetActorAnimIndex(struct Actor *actor, int index);
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern int OS_IsRunOnTwl(void);
extern void CLACT_SetActorVisible(struct Actor *a, u32 v);
extern void CLACT_DeleteActor(struct Actor *p);
extern u32 GAME_BEACON_GetReceiveCount(void);
extern int GAME_BEACON_GetNextNewLogIndex(int *p);
extern void *GAME_BEACON_GetLogByReceiveNo(int n);
extern u8 GAME_BEACON_ACCESSOR_GetFavoriteColorIndex(struct BeaconLog *p);
extern struct PlayerSettings *GAME_DATA_GetMyStatus(void *gameData);
extern unsigned char func_02008550(const struct PlayerSettings *obj);
extern unsigned char func_020090F0(const struct HexMap *obj);
extern struct ActorSystem *CLACT_CreateUnit(int count, unsigned char flag, u32 heapId);
extern struct ActorResources *CLACT_CreateRenderer(const char *name, u32 flag, u32 heapId);
extern void CLACT_SetUnitRenderer(struct ActorSystem *system, struct ActorResources *resources);
extern struct ButtonTask *BUTTON_MAN_Create(const char *name, void (*callback)(int, int, CGearWork *), CGearWork *work, u32 heapId);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void BUTTON_MAN_Delete(struct ButtonTask *task);
extern void CLACT_DeleteRenderer(struct ActorResources *resources);
extern u32 CLACT_DeleteUnit(struct ActorSystem *bank);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern int UI_GetPowerState(void);
extern void GF_STANDARD_SetField00(RtcTime *time);
extern void CLACT_AddActorSurfacePos(struct Actor *actor, const CGearPos *delta, u32 which);
extern void CLACT_SetActorDrawPriority(struct Actor *node, u32 val);
extern s32 BUTTON_MAN_UpdateSlots(struct ButtonTask *task);
extern void C_GEAR_TickIndicators(CGearWork *work);
extern void C_GEAR_TickTabFrame(CGearWork *work);
extern void *GFL_HEAP_Alloc(u32 heap, u32 size, int flag, const char *file, u16 line);
extern struct SaveCtrl *GAME_DATA_GetSaveControl(void *gameData);
extern u32 SAVE_CONTROL_LoadExtraSaveWithBuffer(struct SaveCtrl *sv, u32 id, u8 heap, void *buf, u32 size);
extern u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);
extern struct HexMap *BLOCK20_SAVEDATA_GetBlock(void *saveSys);
extern u16 func_0200910C(const struct HexMap *obj);
extern u32 MUSICAL_DIST_SAVE_IsFooterSet(const u8 *bgData);
extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);
extern void BG_SYS_LoadPltt(u32 a, void *src, u32 size, u32 ofs);
extern void BG_SYS_DecodeTile(u32 index, const void *src, u32 mode);
extern void func_0200734C(struct SaveCtrl *sv, u32 id);
extern void TCB_Main(struct FadeCtx *ctx);
extern void PALANM_TransferPalettes(struct PalAnmSlot *p);
extern u32 ICA_ANIME_IsConfigFlagSet(const struct GameSystem *p);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern u32 TCB_GetTaskOffset(u32 n);
extern struct FadeCtx *TCB_Init(u32 capacity, void *mem);
extern u8 func_02009100(const struct HexMap *obj);
extern struct PalAnmSlot *PALANM_Create(u32 heapId);
extern void PALANM_SetAutoTransfer(struct PalAnmSlot *o, int v);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern struct VBlankTask *GFL_USE_AddMainTask(void (*callback)(void *, CGearWork *), CGearWork *work, int priority);
extern void UI_SetSleepHookGlobal(void (*callback)(CGearWork *), CGearWork *work);
extern void UI_SetWakeHookGlobal(void (*callback)(CGearWork *), CGearWork *work);
extern void C_GEAR_CreateFadeFx(CGearWork *work, CGearFadeFx *fx);
extern int GAMESYSTEM_IsEventActive(const struct GameSystem *gameSystem);
extern void C_GEAR_SetPowerState(CGearWork *work, int powerOn);
extern void C_GEAR_ApplyIndicators(CGearWork *work);
extern int INTRUDE_COMM_GetVisitProgress(void *eventWork);
extern void INTRUDE_COMM_SetCompleted(void *p);
extern void C_GEAR_DeleteFadeFx(CGearFadeFx *fx);
extern void GFL_NET_RestartNoTimeout(void);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(struct PalAnmSlot *palAnm);
extern void TCB_Noop(struct FadeCtx *ctx);
extern void TCB_DeleteTask(struct VBlankTask *task);
extern struct SoundSys *GAME_DATA_GetBgmInfo(const void *gameData);
extern void func_02028A70(struct SoundSys *sys);
extern void ARC_TOOL_DeleteHandle(void *archive);
extern u32 func_020056EC(u32 range);
extern void FIELD_SOUND_SYSTEM_StartRingtone(struct SoundSys *sys);
extern void WIPE_SetBrightnessFadeOut(u32 a, u32 color);
extern void WIPE_ResetBrightness(u32 which);
extern void C_GEAR_StartSelectedRipple(CGearWork *work);
extern void C_GEAR_StepWaitSlots(CGearWork *work);
extern struct GameEvent *C_GEAR_StartPanelEvent(CGearWork *work, int kind);
void C_GEAR_NoOp(CGearWork *work);
extern u32 func_02009110(const struct HexMap *obj, int row, int col);
extern int func_02009134(const struct HexMap *obj, int row, int col);
extern u32 func_02009160(const struct HexMap *obj, int row, int col, int kind);
int C_GEAR_IsColumnRowValid(int col, int row);
void C_GEAR_SetStepFunc(CGearWork *work, CGearStepFunc stepFunc);
void C_GEAR_ChangeStep(CGearWork *work, CGearStepFunc stepFunc, int line);
void C_GEAR_GetHexNeighbors(int col, int row, int *outCols, int *outRows);
void C_GEAR_SpawnRippleActor(CGearWork *work, int col, int row);
CGearActorSlot *C_GEAR_AcquireActorSlot(CGearWork *work);
int C_GEAR_IsTileActorIdle(CGearWork *work, int col, int row);
int C_GEAR_StepRipple(CGearWork *work);
void C_GEAR_StartRippleFlood(CGearWork *work);
int C_GEAR_HitTestTile(const CGearWork *work, int touchX, int touchY, int *outCol, int *outRow);
void C_GEAR_InitTabTimersPowerOn(CGearWork *work);
void C_GEAR_InitTabTimersPowerOff(CGearWork *work);
void C_GEAR_ResetTabPalettes(CGearWork *work);
void C_GEAR_UpdateTabInput(CGearWork *work, int tabKind, int slot, int resetPriorities, int modeEnabled);
int C_GEAR_IsCallTabActive(CGearWork *work);
void C_GEAR_TickTabTimers(CGearWork *work);
void C_GEAR_SetTabMode(CGearWork *work, int mode, int variant);
void C_GEAR_UpdateTabPalettes(CGearWork *work);
void C_GEAR_UpdateTabPaletteKind3(CGearWork *work, int slot, CGearTabTimer *timer);
void C_GEAR_UpdateTabPaletteKind1(CGearWork *work, int slot, CGearTabTimer *timer);
void C_GEAR_UpdateTabPaletteKind2(CGearWork *work, int slot, CGearTabTimer *timer);
void C_GEAR_UpdateTabPaletteKind0(CGearWork *work, int slot, CGearTabTimer *timer);
void C_GEAR_UpdateTabPaletteKind4(CGearWork *work, int slot, CGearTabTimer *timer);
void C_GEAR_BlendTabPalette(CGearWork *work, int slot, int step, int steps);
void C_GEAR_LoadTargetPalette(CGearWork *work, const u8 *paletteFile, int bank);
int C_GEAR_SelectTabPalette(CGearWork *work, int slot, int paletteIndex, int kind, int wantedKind, int wantedSlot);
void C_GEAR_InitTiles(CGearWork *work);
void C_GEAR_StepTiles(CGearWork *work);
int C_GEAR_IsAnyTileFlashing(CGearWork *work);
void C_GEAR_StopTileFlashes(CGearWork *work);
void C_GEAR_InitTile(CGearTile *tile, int col, int row);
void C_GEAR_ResetTileFlash(CGearTile *tile, CGearWork *work, int surfaceVariant);
void C_GEAR_StartTileFlash(CGearTile *tile, CGearWork *work, int palRow, int mode, int variant, u16 stepPeriod);
void C_GEAR_StopTileFlash(CGearTile *tile);
void C_GEAR_StepTileFlash(CGearTile *tile, CGearWork *work);
void C_GEAR_SetTileFlashStep(CGearTile *tile, int step);
int C_GEAR_IsTileFlashing(CGearTile *tile);
int C_GEAR_GetTilePalette(CGearWork *work, int palRow, int col, int row);
void C_GEAR_InitTabTimer(CGearTabTimer *timer, u16 limit, u8 stagger, u8 resetOnFire);
void C_GEAR_TickTabTimer(CGearTabTimer *timer);
int C_GEAR_IsTabTimerFull(CGearTabTimer *timer, int slot);
void C_GEAR_ResetTabTimerCount(CGearTabTimer *timer, int slot);
void C_GEAR_ClearTabTimerCount(CGearTabTimer *timer, int slot);
u16 C_GEAR_GetTabTimerCount(CGearTabTimer *timer, int slot);
void C_GEAR_SetTabTimerRunning(CGearTabTimer *timer, char running);
void C_GEAR_TileToScreen(int col, int row, int *outX, int *outY);
int C_GEAR_IsIdleForInput(CGearWork *work);
int C_GEAR_CountCellsOfKind(CGearWork *work, int kind);
void C_GEAR_TintPalettes(CGearWork *work, int commEnabled);
void C_GEAR_StartFlashFade(CGearWork *work);
void C_GEAR_FadeBackground(CGearWork *work, int faded);
void C_GEAR_FadeAccentColors(CGearWork *work, int faded);
void C_GEAR_StartFadeOut(CGearWork *work);
void C_GEAR_StartFadeIn(CGearWork *work);
void C_GEAR_StopFade(CGearWork *work);
int C_GEAR_GetFadeRequestBits(CGearWork *work);
void C_GEAR_DrawEmptyBoard(CGearWork *work);
int C_GEAR_StepIntroTiles(CGearWork *work);
int C_GEAR_StepOutroTiles(CGearWork *work);
void C_GEAR_ResetAllTiles(CGearWork *work);
void C_GEAR_DrawTile(CGearWork *work, int col, int row, int kind);
int C_GEAR_FindCellOfKind(CGearWork *work, int kind, int *outX, int *outY);
void C_GEAR_DrawAllCells(CGearWork *work);
u32 C_GEAR_LoadSkin(CGearWork *work, int theme, int skin, int loadPalettes);
void C_GEAR_LoadSpriteResources(CGearWork *work, int theme);
void C_GEAR_LoadFrameGraphics(CGearWork *work, int customBgLoaded);
void C_GEAR_SetupBackgrounds(CGearWork *work);
void C_GEAR_SetupSubScreenBlend(CGearWork *work);
void C_GEAR_HandleButton(CGearWork *work, int key);
void C_GEAR_OnButtonEvent(int key, int buttonState, CGearWork *work);
void C_GEAR_SetPaintModeIcon(CGearWork *work, int paintMode);
void C_GEAR_CreateHudActors(CGearWork *work);
void C_GEAR_SetTileMarkersVisible(CGearWork *work, int visible);
void C_GEAR_SetAllActorsVisible(CGearWork *work, int visible);
void C_GEAR_SetSplashActorsVisible(CGearWork *work, int visible);
void C_GEAR_CreateSplashActors(CGearWork *work);
void C_GEAR_DeleteSplashActors(CGearWork *work);
int C_GEAR_IsSplashDone(CGearWork *work);
void C_GEAR_CreateBarActors(CGearWork *work);
void C_GEAR_UpdateBeaconColors(CGearWork *work);
void C_GEAR_DeleteBarActors(CGearWork *work);
void C_GEAR_LoadGraphics(CGearWork *work, int introMode);
void C_GEAR_DeleteActors(CGearWork *work);
void C_GEAR_FreeGraphics(CGearWork *work);
u8 C_GEAR_GetBatteryFrame(void);
void C_GEAR_UpdateClock(CGearWork *work);
void C_GEAR_UpdateTileMarkers(CGearWork *work);
void C_GEAR_RunFrame(CGearWork *work);
void C_GEAR_StepIdle(CGearWork *work);
void C_GEAR_StepIntroEnd(CGearWork *work);
void C_GEAR_StepOpen(CGearWork *work);
void C_GEAR_StepClose(CGearWork *work);
int C_GEAR_LoadCustomBackground(CGearWork *work, struct GameSystem *gameSystem);
void C_GEAR_OnCommDisconnect(CGearWork *work);
void C_GEAR_OnCommEvent(CGearWork *work);
void C_GEAR_TransferPalettesTask(void *task, CGearWork *work);
void C_GEAR_Init(CGearWork *work, struct HexMap *hexMap, int parentWork, struct GameSystem *gameSystem, int introMode);
void C_GEAR_Cleanup(CGearWork *work);
CGearWork *C_GEAR_Create(struct HexMap *hexMap, int parentWork, struct GameSystem *gameSystem, int introMode);
CGearWork *C_GEAR_Open(struct HexMap *hexMap, int parentWork, struct GameSystem *gameSystem, void (*callback)(int), int callbackArg, int introMode);
void C_GEAR_Update(CGearWork *work, u8 powerOn);
void C_GEAR_Nop(void);
void C_GEAR_Destroy(CGearWork *work);
int C_GEAR_Restart(CGearWork *work);
struct GameEvent *C_GEAR_HandleCommand(CGearWork *work, int enabled);
int C_GEAR_IsLastCommandKind5(CGearWork *work);
void C_GEAR_StopRingtone(CGearWork *work);
void C_GEAR_SetCellKind(CGearWork *work, struct HexMap *hexMap, int col, int row, int kind);
u32 C_GEAR_GetCellKind(const CGearWork *work, int col, int row);
int C_GEAR_IsCellMarked(const CGearWork *work, int col, int row);
int C_GEAR_IsCellKind(const CGearWork *work, int col, int row, int kind);
extern CGearParityPair d_021F333C;
extern CGearParityPair d_021F334C;
extern u16 d_021F31BC[];
extern u8 d_021F31AB[];
extern u8 d_021F31B0[];
extern const u32 d_021F31EC[];
extern const int d_021F31F8[];
extern u8 d_021F3255[];
extern unsigned char d_021F3292[];
extern unsigned char d_021F3204[];
extern const u8 d_021F31A8[];
extern const u8 d_021F323C[];
extern const unsigned char d_021F32B3[][9];
extern const CGearParityPair d_021F3344;
extern u16 d_021F31B6[];
extern const CGearParityPair d_021F3324;
extern const CGearParityPair d_021F331C;
extern const CGearFlashStep d_021F3410[];
extern const u16 d_021F31D4[];
extern const CGearFlashStep d_021F348C[];
extern const CGearParityPair d_021F3334;
extern const CGearTileBases d_021F3354;
extern const int d_021F332C[2];
extern const int d_021F31E0[];
extern const int d_021F32E0[][3];
extern const int d_021F31C8[];
extern const int d_021F33CC[];
extern struct BgTemplate d_021F338C;
extern struct BgTemplate d_021F33AC;
extern struct BgTemplate d_021F336C;
extern const u8 d_021F3526[];
extern const u8 d_021F3531[];
extern const u8 d_021F353C[];
extern const int d_021F3548[];
extern char d_021F3214[];
extern char d_021F3272[];
extern const u8 d_021F3520[];
extern const char d_021F3554[];
typedef struct GameEvent *(*GameEventCreatorFn)(struct GameSystem *gameSystem, void *arg);
extern struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, void *handler, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern struct GameEvent *GAME_EVENT_CreateOverlayEvent(struct GameSystem *gameSystem, u32 overlayId, GameEventCreatorFn creator, void *arg);
extern struct GameEvent *EVENT_GSYNC_Entry(struct GameSystem *gameSystem, void *arg);
extern struct GameEvent *IRC_BATTLE_ENTRY_Create(struct GameSystem *gameSystem, void *fieldMap, int a, int b);
extern struct GameEvent *SCRCMD_NETWORK_CreateWifiProcEvent(struct GameSystem *gameSystem, void *fieldMap, int a, int b);
extern struct GameEvent *EVENT_RESEARCH_RADAR_CreateTopTask(struct GameSystem *gameSystem, void *fieldMap);
extern struct GameEvent *FIELD_COMM_ACTOR_CreateSubscreenChangeEvent(struct GameSystem *gameSystem, void *fieldMap, u32 a);
extern struct GameEvent *FIELD_STATUS_CreateSubProcCallbackEvent(struct GameSystem *gameSystem, void *fieldMap, u32 overlayId, const void *procData, void *procWork, void (*callback)(void *), void *callbackWork);
extern struct GameEvent *FIELD_SUBSCREEN_CreateAnimTask(struct GameSystem *gameSystem);
extern void GAME_EVENT_ChangeEvent(struct GameEvent *now, struct GameEvent *next);
extern int GFL_NET_GetRunState(void);
int C_GEAR_StepIconAnim(CGearWork *work);
int C_GEAR_StepFadeIcon(CGearWork *work);
void C_GEAR_ShowOffIndicator(CGearWork *work);
void C_GEAR_ShowCommIndicator(CGearWork *work);
void C_GEAR_HideCommIndicator(CGearWork *work);
void C_GEAR_HideOffIndicator(CGearWork *work);
void C_GEAR_StartFadeFx(CGearFadeFx *fx, int palette);
int C_GEAR_StepFadeFx(CGearFadeFx *fx);
int C_GEAR_PanelEventMain(struct GameEvent *event, int *seq, CGearEventWork *req);
void C_GEAR_DeleteActorSlots(CGearWork *work);
int C_GEAR_AreActorSlotsIdle(CGearWork *work);
extern const unsigned int gCGearFadeSteps[];
/* Overlay ids are absolute link-time symbols (pool words), so no literal. */
extern u8 abs_id_0[];
extern u8 abs_id_124[];
extern const u8 d_021D4D40[];
struct ArcFile;
struct HexMap;
void C_GEAR_LoadSkinMember(struct HexMap *hexMap, struct ArcFile *arc, int skinIndex, int heapId);
int CTRDG_IsAgbCartridge(CGearWork *work);
extern int CTRDGi_IsAgbCartridgeAtInit(void);
extern void *func_020091FC(void *cgearSave);
extern void ARC_TOOL_ReadHandleMember(struct ArcFile *arc, u32 member, void *dst);










int C_GEAR_IsColumnRowValid(int col, int row)
{
    if (col % 2 == 0) {
        if (row < 3)
            return 1;
    } else {
        if (row < 4)
            return 1;
    }
    return 0;
}






void C_GEAR_SetStepFunc(CGearWork *work, CGearStepFunc stepFunc)
{
    work->stepFunc = stepFunc;
    work->phaseTimer = 0;
    work->phase = 0;
}







/*
 * evidence: C_GEAR_SetStepFunc is ov029's own code (a store leaf ending in bx lr
 * after the bx lr at 0x021EFEE0), inside ov029's window, so only ov029 can be
 * resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference; it
 * attests as sole-ref/code from ov029's own listing.
 *
 * `line`: every caller loads r2 with a constant, but the callee never
 * reads it, so the thunk takes it and drops it.
 */
void C_GEAR_ChangeStep(CGearWork *work, CGearStepFunc stepFunc, int line)
{
    C_GEAR_SetStepFunc(work, stepFunc);
}






void C_GEAR_GetHexNeighbors(int col, int row, int *outCols, int *outRows)
{
    int parity = col % 2;

    if (parity == 0) {
        outCols[0] = col;
        outRows[0] = row - 1;
        outCols[1] = col;
        outRows[1] = row + 1;
        outCols[2] = col + 1;
        outRows[2] = row;
        outCols[3] = col + 1;
        outRows[3] = row - 1;
        outCols[4] = col - 1;
        outRows[4] = row;
        outCols[5] = col - 1;
        outRows[5] = row - 1;
    } else {
        outCols[0] = col;
        outRows[0] = row - 1;
        outCols[1] = col;
        outRows[1] = row + 1;
        outCols[2] = col + 1;
        outRows[2] = row;
        outCols[3] = col + 1;
        outRows[3] = row + 1;
        outCols[4] = col - 1;
        outRows[4] = row;
        outCols[5] = col - 1;
        outRows[5] = row + 1;
    }
}







void C_GEAR_SpawnRippleActor(CGearWork *work, int col, int row)
{
    CGearActorDesc desc;
    int screenX;
    int screenY;
    CGearActorSlot *slot;

    C_GEAR_TileToScreen(col, row, &screenX, &screenY);
    desc.x = screenX * 8 + 16;
    desc.y = screenY * 8 + 16;
    desc.animIndex = work->rippleKind + 10;
    desc.palOffset = 0;
    desc.surface = 2;
    slot = C_GEAR_AcquireActorSlot(work);
    if (slot->actor != 0) {
        CLACT_SetActorAnimSeq(slot->actor, desc.animIndex);
        CLACT_RestartActorAnim(slot->actor);
        CLACT_SetActorSurfacePosAxis(slot->actor, desc.x, 0, 0);
        CLACT_SetActorSurfacePosAxis(slot->actor, desc.y, 0, 1);
    } else {
        slot->actor = CLACT_CreateActor(work->spriteSystem, work->spriteCharRes, work->spritePlttRes, work->spriteAnimRes, &desc, 0, work->heapId);
        CLACT_SetActorAutoAnim(slot->actor, 1);
        CLACT_SetActorDrawEnable(slot->actor, 1);
    }
    slot->col = col;
    slot->row = row;
}







CGearActorSlot *C_GEAR_AcquireActorSlot(CGearWork *work)
{
    int bestSeq = -1;
    int bestFrame = -1;
    int bestIdx = 0;
    int i;
    int animSeq;
    int animFrame;

    for (i = 0; i < 20; i++) {
        if (work->actorSlots[i].actor == 0) {
            return &work->actorSlots[i];
        }
        animSeq = CLACT_GetActorAnimSeqCount(work->actorSlots[i].actor);
        animFrame = CLACT_GetActorAnimFrame(work->actorSlots[i].actor);
        if (animSeq > bestSeq || (animSeq == bestSeq && animFrame > bestFrame)) {
            bestSeq = animSeq;
            bestFrame = animFrame;
            bestIdx = i;
        }
    }
    return &work->actorSlots[bestIdx];
}






int C_GEAR_IsTileActorIdle(CGearWork *work, int col, int row)
{
    int i;
    for (i = 0; i < 20; i++) {
        if (work->actorSlots[i].actor != 0 && work->actorSlots[i].col == col && work->actorSlots[i].row == row) {
            if (CLACT_IsActorAnimActive(work->actorSlots[i].actor) != 0) return 0;
        }
    }
    return 1;
}







int C_GEAR_StepRipple(CGearWork *work)
{
    int y;
    int x;
    int k;
    int neighborCols[6];
    int neighborRows[6];

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 9; x++) {
            if (work->grid[x][y] == 4 && C_GEAR_IsTileActorIdle(work, x, y) != 0) {
                work->grid[x][y] = 5;
            }
            if (work->grid[x][y] == 2) {
                C_GEAR_SpawnRippleActor(work, x, y);
                work->grid[x][y] = 3;
            }
        }
    }
    work->rippleStep++;
    if (work->rippleStep >= 16) {
        return 1;
    }
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 9; x++) {
            if (work->grid[x][y] == 3) {
                work->grid[x][y] = 4;
                C_GEAR_GetHexNeighbors(x, y, neighborCols, neighborRows);
                for (k = 0; k < 6; k++) {
                    if (neighborCols[k] >= 0 && neighborCols[k] < 9 && neighborRows[k] >= 0 && neighborRows[k] < 4) {
                        if (work->grid[neighborCols[k]][neighborRows[k]] == 1) {
                            work->grid[neighborCols[k]][neighborRows[k]] = 2;
                        } else if (work->grid[neighborCols[k]][neighborRows[k]] == 0) {
                            work->grid[neighborCols[k]][neighborRows[k]] = 3;
                        }
                    }
                }
            }
        }
    }
    return 0;
}







void C_GEAR_StartRippleFlood(CGearWork *work)
{
    int kind;
    int j;
    int i;

    kind = C_GEAR_GetCellKind(work, work->selectedCol, work->selectedRow);
    work->rippleKind = kind;
    i = 0;
    work->rippleStep = i;
    for (; i < 4; i++) {
        for (j = 0; j < 9; j++) {
            if (kind == C_GEAR_GetCellKind(work, j, i)) {
                work->grid[j][i] = 1;
            }
        }
    }
    work->grid[work->selectedCol][work->selectedRow] = 2;
    C_GEAR_StepRipple(work);
}







/*
 * note 2026-10-05 (wD6 lane14): closed by reusing parameter a for x (the early
 * `adds r4,r1,#0` copy), b for the b/8 - lo[m] intermediate, and two 8-byte
 * struct copies of the tables (ldm r5,{r3,r5}).
 */
int C_GEAR_HitTestTile(const CGearWork *work, int touchX, int touchY, int *outCol, int *outRow)
{
    int row;
    CGearParityPair rowOffset;
    CGearParityPair rowCount;
    int kind = 5;
    int parity;

    rowOffset = d_021F333C;
    rowCount = d_021F334C;
    touchX = (touchX / 8 + 2) / 4;
    if (touchX < 0) {
        return 5;
    }
    parity = touchX % 2;
    touchY = touchY / 8 - rowOffset.value[parity];
    if (touchY < 0) {
        return 5;
    }
    row = touchY / 4;
    if (touchX < 9 && row < rowCount.value[parity]) {
        kind = C_GEAR_GetCellKind(work, touchX, row);
    }
    *outCol = touchX;
    *outRow = row;
    return kind;
}







void C_GEAR_InitTabTimersPowerOn(CGearWork *work)
{
    CGearTabTimer *timers = work->tabTimers;
    int i;
    int j;

    for (i = 0; i < 5; i++) {
        C_GEAR_InitTabTimer(&timers[i], d_021F31BC[i], d_021F31AB[i], d_021F31B0[i]);
        if (i == 0) {
            C_GEAR_SetTabTimerRunning(&timers[i], 0);
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            C_GEAR_UpdateTabInput(work, i, j, 0, 0);
        }
    }
}







void C_GEAR_InitTabTimersPowerOff(CGearWork *work)
{
    CGearTabTimer *timers = work->tabTimers;
    int i;
    int j;

    for (i = 0; i < 5; i++) {
        C_GEAR_InitTabTimer(&timers[i], d_021F31BC[i], d_021F31AB[i], d_021F31B0[i]);
        if (i != 0) {
            C_GEAR_SetTabTimerRunning(&timers[i], 0);
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            C_GEAR_UpdateTabInput(work, i, j, 1, work->tabMode);
        }
    }
}






void C_GEAR_ResetTabPalettes(CGearWork *work)
{
    int i;
    for (i = 0; i < 3; i++) C_GEAR_BlendTabPalette(work, i, 0, 31);
}







/*
 * `const` on the two key/row tables schedules the second table's pool load
 * above the `[sp]` stack-argument store in the cycle loop (14 bytes out
 * without it). The four-way reset is `s18 = s8 = sc = s14 = 0`: the chain
 * stores right to left.
 */
void C_GEAR_UpdateTabInput(CGearWork *work, int tabKind, int slot, int resetPriorities, int modeEnabled)
{
    void *eventWork;
    int keyGroups;
    int keysHeld;
    int linkMode;
    int kind4;
    int kind3;
    int i;
    int kind2;
    int kind1;
    u32 padKeys;
    int cycleIdx;

    eventWork = ICA_ANIME_GetField24(work->gameSystem);
    keyGroups = 0;
    keysHeld = 1;
    kind1 = 1;
    kind4 = 4;
    kind3 = 3;
    kind2 = 2;
    if (resetPriorities != 0) {
        kind4 = kind1 = kind2 = kind3 = 0;
    }
    padKeys = WIH_DWC_PollStatus(GAME_DATA_GetField1A0(ICA_ANIME_GetField1C(work->gameSystem)));
    linkMode = INTRUDE_COMM_GetRequestState(eventWork);
    if (modeEnabled != 0) {
        if (linkMode == 3) {
            C_GEAR_SelectTabPalette(work, 2, 3, kind3, tabKind, slot);
        } else if (padKeys & 8) {
            keyGroups |= 4;
            C_GEAR_SelectTabPalette(work, 2, 2, kind3, tabKind, slot);
        }
    }
    if (keyGroups == 0) {
        keysHeld = 0;
        if (padKeys & 2) {
            keyGroups |= 2;
        }
        if (padKeys & 0x3c) {
            keyGroups |= 4;
        }
        if (padKeys & 0x3c0) {
            keyGroups |= 8;
        }
        if (padKeys & 0x40) {
            C_GEAR_SelectTabPalette(work, 1, 3, kind2, tabKind, slot);
        } else if (padKeys & 0x100) {
            C_GEAR_SelectTabPalette(work, 1, 0, kind2, tabKind, slot);
        } else if (padKeys & 0x80) {
            C_GEAR_SelectTabPalette(work, 1, 1, kind2, tabKind, slot);
        } else if (padKeys & 0x200) {
            C_GEAR_SelectTabPalette(work, 1, 0, kind2, tabKind, slot);
        }
        if (linkMode != 0) {
            if (linkMode != 3) {
                C_GEAR_SelectTabPalette(work, 2, 3, kind2, tabKind, slot);
            }
        } else {
            for (i = 0; i < 3; i++) {
                work->keyCycle = (work->keyCycle + 1) % 3;
                cycleIdx = work->keyCycle;
                if ((d_021F31EC[cycleIdx] & padKeys) || (cycleIdx == 2 && work->beaconPending != 0)) {
                    if (C_GEAR_SelectTabPalette(work, 2, d_021F31F8[cycleIdx], kind2, tabKind, slot) != 0) {
                        if (work->keyCycle == 2) {
                            work->beaconPending = 0;
                        }
                        break;
                    }
                }
            }
            if (i == 3) {
                C_GEAR_SelectTabPalette(work, 2, 8, kind1, tabKind, slot);
            }
        }
    }
    if (keysHeld == 0) {
        C_GEAR_SelectTabPalette(work, 0, 6, kind1, tabKind, slot);
        if (!(keyGroups & 8)) {
            C_GEAR_SelectTabPalette(work, 1, 7, kind1, tabKind, slot);
        }
        if (!(keyGroups & 4)) {
            C_GEAR_SelectTabPalette(work, 2, 8, kind1, tabKind, slot);
        }
    } else {
        C_GEAR_SelectTabPalette(work, 0, 5, kind4, tabKind, slot);
        C_GEAR_SelectTabPalette(work, 1, 5, kind4, tabKind, slot);
    }
}






int C_GEAR_IsCallTabActive(CGearWork *work)
{
    if (work->tabVariant == 1 && work->tabMode == 1) return 1;
    return 0;
}







void C_GEAR_TickTabTimers(CGearWork *work)
{
    CGearTabTimer *timers2;
    CGearTabTimer *timers;
    int i;
    int j;
    int flag;

    flag = 0;
    for (i = 0; i < 5; i++) {
        timers = work->tabTimers;
        C_GEAR_TickTabTimer(&timers[i]);
        for (j = 0; j < 3; j++) {
            if (C_GEAR_IsTabTimerFull(&timers[i], j) || work->refreshFlag) {
                C_GEAR_UpdateTabInput(work, i, j, 0, work->tabMode);
                if (i == 0) {
                    flag = 1;
                }
                if (C_GEAR_IsTabTimerFull(&timers[i], j)) {
                    C_GEAR_ResetTabTimerCount(&timers[i], j);
                }
            }
        }
    }
    if (flag) {
        timers2 = work->tabTimers;
        for (i = 0; i < 5; i++) {
            if (i != 0) {
                C_GEAR_SetTabTimerRunning(&timers2[i], 1);
                for (j = 0; j < 3; j++) {
                    C_GEAR_UpdateTabInput(work, i, j, 0, work->tabMode);
                }
            } else {
                C_GEAR_SetTabTimerRunning(&timers2[i], 0);
            }
        }
    }
    work->refreshFlag = 0;
}







void C_GEAR_SetTabMode(CGearWork *work, int mode, int variant)
{
    CGearTabTimer *timers;
    int i;
    int j;
    int k;

    for (i = 0; i < 3; i++) {
        C_GEAR_BlendTabPalette(work, i, 0, 0x1f);
    }
    timers = work->tabTimers;
    for (j = 0; j < 5; j++) {
        for (k = 0; k < 3; k++) {
            C_GEAR_ClearTabTimerCount(&timers[j], k);
        }
    }
    work->tabMode = mode;
    work->refreshFlag = 1;
    work->tabActive = 1;
    work->tabFrame = 0;
    work->tabVariant = variant;
}







void C_GEAR_UpdateTabPalettes(CGearWork *work)
{
    CGearTabTimer *timers = work->tabTimers;
    int i;

    for (i = 0; i < 3; i++) {
        u8 kind = work->tabState[i];

        switch (kind) {
        case 3:
            C_GEAR_UpdateTabPaletteKind3(work, i, &timers[kind]);
            break;
        case 1:
            C_GEAR_UpdateTabPaletteKind1(work, i, &timers[kind]);
            break;
        case 2:
            C_GEAR_UpdateTabPaletteKind2(work, i, &timers[kind]);
            break;
        case 0:
            C_GEAR_UpdateTabPaletteKind0(work, i, &timers[kind]);
            break;
        case 4:
            C_GEAR_UpdateTabPaletteKind4(work, i, &timers[kind]);
            break;
        }
    }
}







void C_GEAR_UpdateTabPaletteKind3(CGearWork *work, int slot, CGearTabTimer *timer)
{
    unsigned int value = C_GEAR_GetTabTimerCount(timer, slot);
    if (value > 0x24 || value < 4) return;
    value = (u16)(value - 4);
    value = (unsigned)(((int)value % 8) * 28) >> 3;
    value = d_021F3255[value];
    C_GEAR_BlendTabPalette(work, slot, value, 0x1f);
}






void C_GEAR_UpdateTabPaletteKind1(CGearWork *work, int slot, CGearTabTimer *timer)
{
    unsigned int value = C_GEAR_GetTabTimerCount(timer, slot);
    if (value > 112 || value < 12) return;
    value = (unsigned)((unsigned short)(value - 12)) * 28 / 100;
    value = d_021F3255[value];
    C_GEAR_BlendTabPalette(work, slot, value, 31);
}






void C_GEAR_UpdateTabPaletteKind2(CGearWork *work, int slot, CGearTabTimer *timer)
{
    unsigned int value = C_GEAR_GetTabTimerCount(timer, slot);
    if (value > 78 || value < 8) return;
    value = (unsigned)((unsigned short)(value - 8)) * 32 / 70;
    value = d_021F3292[value];
    C_GEAR_BlendTabPalette(work, slot, value, 31);
}






void C_GEAR_UpdateTabPaletteKind0(CGearWork *work, int slot, CGearTabTimer *timer)
{
    unsigned int value = C_GEAR_GetTabTimerCount(timer, slot);
    if (value > 20) return;
    value = (unsigned)(((int)value % 10) * 28) / 10;
    value = d_021F3255[value];
    C_GEAR_BlendTabPalette(work, slot, value, 31);
}






void C_GEAR_UpdateTabPaletteKind4(CGearWork *work, int slot, CGearTabTimer *timer)
{
    unsigned int value = C_GEAR_GetTabTimerCount(timer, slot);
    if (value > 15) return;
    value = (unsigned)(value * 12) / 15;
    value = d_021F3204[value];
    C_GEAR_BlendTabPalette(work, slot, value, 31);
}







void C_GEAR_BlendTabPalette(CGearWork *work, int slot, int step, int steps)
{
    int colorIdx;
    int channel;
    int base;
    int delta;

    for (colorIdx = 0; colorIdx < 5; colorIdx++) {
        work->blendPalette[slot][colorIdx] = 0;
        for (channel = 0; channel < 3; channel++) {
            base = (work->basePalette[slot][colorIdx] >> (channel * 5)) & 0x1f;
            delta = ((work->targetPalette[work->targetPalIndex[slot]][colorIdx] >> (channel * 5)) & 0x1f) - base;
            work->blendPalette[slot][colorIdx] |= ((base + delta * step / steps) & 0x1f) << (channel * 5);
        }
        PALANM_CopyToSlot(work->palAnm, &work->blendPalette[slot][colorIdx], 1, (u16)(d_021F31A8[slot] + (colorIdx + 1) * 16), 2);
    }
}






void C_GEAR_LoadTargetPalette(CGearWork *work, const u8 *paletteFile, int bank)
{
    int i;
    for (i = 0; i < 5; i++) work->targetPalette[bank][i] = ((const u16 *)(paletteFile + bank * 32 + 0x16))[i];
}






int C_GEAR_SelectTabPalette(CGearWork *work, int slot, int paletteIndex, int kind, int wantedKind, int wantedSlot)
{
    if (kind == wantedKind && slot == wantedSlot) {
        work->targetPalIndex[slot] = paletteIndex;
        work->tabState[slot] = kind;
        return 1;
    }
    return 0;
}






void C_GEAR_InitTiles(CGearWork *work)
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) C_GEAR_InitTile(&work->tiles[i][j], i, j);
    }
}






void C_GEAR_StepTiles(CGearWork *work)
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) C_GEAR_StepTileFlash(&work->tiles[i][j], work);
    }
}






int C_GEAR_IsAnyTileFlashing(CGearWork *work)
{
    int result, i, j;
    result = 0;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            if (C_GEAR_IsTileFlashing(&work->tiles[i][j])) {
                result = 1;
                break;
            }
        }
    }
    return result;
}






void C_GEAR_StopTileFlashes(CGearWork *work)
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            C_GEAR_StopTileFlash(&work->tiles[i][j]);
        }
    }
}




void C_GEAR_InitTile(CGearTile *tile, int col, int row)
{
    MI_CpuFill8(tile, 0, 8);
    tile->col = col;
    tile->row = row;
}



void C_GEAR_ResetTileFlash(CGearTile *tile, CGearWork *work, int surfaceVariant)
{
    tile->palRow = 0;
    C_GEAR_DrawTile(work, tile->col, tile->row, surfaceVariant);
    C_GEAR_SetTileFlashStep(tile, 0);
}



/*
 * note:     `t = 0` must come first: set after the stores, the third parameter stays in r2
 *           instead of moving to r1 at entry (27 bytes out).
 */
void C_GEAR_StartTileFlash(CGearTile *tile, CGearWork *work, int palRow, int mode, int variant, u16 stepPeriod)
{
    int lastStep;

    lastStep = 0;
    tile->palRow = palRow;
    tile->tick = 0;
    tile->active = 1;
    tile->stepPeriod = stepPeriod;
    if (mode == 0) {
        tile->stopStep = 0;
    } else if (mode == 1) {
        tile->stopStep = 4;
    } else if (mode == 2) {
        tile->stopStep = C_GEAR_GetTilePalette(work, palRow, tile->col, tile->row);
        tile->tick = stepPeriod * 5;
        lastStep = 4;
    }
    C_GEAR_DrawTile(work, tile->col, tile->row, variant);
    C_GEAR_SetTileFlashStep(tile, lastStep);
}










void C_GEAR_StopTileFlash(CGearTile *tile)
{
    tile->active = 0;
}










void C_GEAR_StepTileFlash(CGearTile *tile, CGearWork *work)
{
    unsigned int step;
    int redraw;

    if (tile->active) {
        tile->tick = tile->tick + 1;
        step = tile->tick / tile->stepPeriod;
        redraw = 0;
        if (step >= 5) {
            step = 4 - step % 5;
            if (step == tile->stopStep)
                tile->active = 0;
        }
        if (step < 5) {
            if (tile->tick % tile->stepPeriod == 0)
                redraw = 1;
        }
        if (redraw)
            C_GEAR_SetTileFlashStep(tile, step);
    }
}










void C_GEAR_SetTileFlashStep(CGearTile *tile, int step)
{
    int tileX, tileY, width;
    int palette;

    palette = (d_021F323C + tile->palRow * 5)[step];
    C_GEAR_TileToScreen(tile->col, tile->row, &tileX, &tileY);
    width = 4;
    if (tileX < 0) {
        width = tileX + 4;
        tileX = 0;
    } else if (tileX + 4 > 0x20) {
        width = 0x20 - tileX;
    }
    BG_SYS_FillTileMap(4, tileX, tileY, width, 4, palette);
    BG_SYS_PushTile(4);
}









int C_GEAR_IsTileFlashing(CGearTile *tile)
{
    return tile->active;
}









int C_GEAR_GetTilePalette(CGearWork *work, int palRow, int col, int row)
{
    if (C_GEAR_IsCellMarked(work, col, row)) return d_021F32B3[palRow][4];
    return d_021F32B3[palRow][col];
}









/*
 * lever: enum zero and f2,f4,f0,f6 logical store order recover the
 * original scheduling; the previous f2,f0,f4,f6 order differed at two stores.
 */
void C_GEAR_InitTabTimer(CGearTabTimer *timer, u16 limit, u8 stagger, u8 resetOnFire)
{
    ZeroValue zero;
    zero = Zero;
    timer->count[1] = stagger;
    timer->count[2] = zero;
    timer->count[0] = stagger * 2;
    timer->limit = limit;
    timer->resetOnFire = resetOnFire;
    timer->running = 1;
}









void C_GEAR_TickTabTimer(CGearTabTimer *timer)
{
    int i;
    if (timer->running) {
        for (i = 0; i < 3; i++) {
            if (timer->count[i] < timer->limit)
                timer->count[i]++;
        }
    }
}









int C_GEAR_IsTabTimerFull(CGearTabTimer *timer, int slot)
{
    if (timer->count[slot] >= timer->limit) return 1;
    return 0;
}









void C_GEAR_ResetTabTimerCount(CGearTabTimer *timer, int slot)
{
    if (timer->resetOnFire != 0) timer->count[slot] = 0;
}









void C_GEAR_ClearTabTimerCount(CGearTabTimer *timer, int slot)
{
    timer->count[slot] = 0;
}










u16 C_GEAR_GetTabTimerCount(CGearTabTimer *timer, int slot)
{
    return timer->count[slot];
}










void C_GEAR_SetTabTimerRunning(CGearTabTimer *timer, char running)
{
    timer->running = running;
}










void C_GEAR_TileToScreen(int col, int row, int *outX, int *outY)
{
    CGearParityPair rowShift = d_021F3344;
    *outX = col * 4 - 2;
    *outY = rowShift.value[col % 2] + row * 4;
}









/*
 * 2026-10-04 (wD2 lane 09): bytes are identical; only the relocation at +0024 is open.
 * Filed the callee as matched ov021_func_02189A48.c (EXACT, returns *(u32 *)(p+0x144)).
 * The tool still reports no independent witness for 02189A48 (3 overlays overlap).
 * Needs the integrator to regenerate the witness index, nothing left in the source.
 * interface: 0201210C returns the full word at +0x20; it is passed directly
 * to 02189A48, whose ov021 body reads the full word at +0x144. No value lost.
 */
int C_GEAR_IsIdleForInput(CGearWork *work)
{
    if (!WIPE_SYS_EndCheck()) return 0;
    if (GXx_GetMasterBrightness_(&REG_DB_MASTER_BRIGHT)) return 0;
    if (!FIELDMAP_GetSubscreenBusy(ICA_ANIME_GetField20(work->gameSystem))) return 1;
    return 0;
}









int C_GEAR_CountCellsOfKind(CGearWork *work, int kind)
{
    int j, i, count;
    if (kind == 4) return 1;
    count = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 9; j++) {
            if (kind == C_GEAR_GetCellKind(work, j, i)) count++;
        }
    }
    return count;
}










void C_GEAR_TintPalettes(CGearWork *work, int commEnabled)
{
    char *srcPal, *dstPal;
    int i;

    if (commEnabled == 0) {
        srcPal = PALANM_GetDefaultWork(work->palAnm, 3);
        dstPal = PALANM_GetTransWork(work->palAnm, 3);
        for (i = 0; i < 14; i++) {
            if (0xFBEE & (1 << i)) {
                PALANM_BlendColors((u16 *)(srcPal + i * 0x20), (u16 *)(srcPal + i * 0x20), 0x10, 8,
                              d_021F31B6[work->colorTheme]);
                MI_CpuCopy8(srcPal + i * 0x20, dstPal + i * 0x20, 0x20);
            }
        }
        srcPal = PALANM_GetDefaultWork(work->palAnm, 1);
        dstPal = PALANM_GetTransWork(work->palAnm, 1);
        for (i = 0; i < 14; i++) {
            if (0x3E & (1 << i)) {
                PALANM_BlendColors((u16 *)(srcPal + i * 0x20), (u16 *)(srcPal + i * 0x20), 0x10, 8,
                              d_021F31B6[work->colorTheme]);
                MI_CpuCopy8(srcPal + i * 0x20, dstPal + i * 0x20, 0x20);
            }
        }
    }
}










void C_GEAR_StartFlashFade(CGearWork *work)
{
    PALANM_RequestFade(work->palAnm, 8, 0xFFFF, -120, 0, 0x10,
                  d_021F31B6[work->colorTheme], work->fadeCtx);
}










void C_GEAR_FadeBackground(CGearWork *work, int faded)
{
    int endLevel = 8;
    if (faded == 0)
        endLevel = 0;
    PALANM_RequestFade(work->palAnm, 8, 0xFFFF, -120, 0, endLevel,
                  d_021F31B6[work->colorTheme], work->fadeCtx);
    PALANM_RequestFade(work->palAnm, 2, 0x3E, -120, 0, endLevel,
                  d_021F31B6[work->colorTheme], work->fadeCtx);
}










void C_GEAR_FadeAccentColors(CGearWork *work, int faded)
{
    int endLevel = 8;
    if (faded == 0)
        endLevel = 0;
    PALANM_RequestFade(work->palAnm, 8, 0x3C0, -120, 0, endLevel,
                  d_021F31B6[work->colorTheme], work->fadeCtx);
}










void C_GEAR_StartFadeOut(CGearWork *work)
{
    PALANM_RequestFade(work->palAnm, 8, 0xFFFF, 1, 0, 0x10,
                  d_021F31B6[work->colorTheme], work->fadeCtx);
}










void C_GEAR_StartFadeIn(CGearWork *work)
{
    PALANM_RequestFade(work->palAnm, 8, 0xFFFF, 1, 0x10, 0,
                  d_021F31B6[work->colorTheme], work->fadeCtx);
}









/*
 * extent: followed by existing ov029_func_021F1000.c.
 */
void C_GEAR_StopFade(CGearWork *work)
{
    PALANM_ForceStopFade(work->palAnm);
}










int C_GEAR_GetFadeRequestBits(CGearWork *work)
{
    return PALANM_GetFadeRequestBits(work->palAnm);
}









void C_GEAR_DrawEmptyBoard(CGearWork *work)
{
    CGearParityPair columnRows = d_021F3324;
    int i, j, rows;

    for (i = 0; i < 9; i++) {
        rows = columnRows.value[i % 2];
        for (j = 0; j < rows; j++)
            C_GEAR_DrawTile(work, i, j, 0);
    }
    BG_SYS_PushTile(4);
}









int C_GEAR_StepIntroTiles(CGearWork *work)
{
    CGearParityPair columnRows = d_021F331C;
    int i, j, rows;
    unsigned int stepIdx;
    const CGearFlashStep *step;
    int kind;
    int tileRow;
    int tileCol;

    switch (work->phase) {
    case 0:
        for (i = 0; i < 9; i++) {
            rows = columnRows.value[i % 2];
            for (j = 0; j < rows; j++)
                C_GEAR_StartTileFlash(&work->tiles[i][j], work, 4, 1, 4, 2);
        }
        work->phase++;
        break;
    case 1:
        if (C_GEAR_IsAnyTileFlashing(work) == 0)
            work->phase++;
        break;
    case 2:
        for (stepIdx = 0; stepIdx < 0x1F; stepIdx++) {
            step = &d_021F3410[stepIdx];
            if (work->phaseTimer == d_021F3410[stepIdx].startTick) {
                tileRow = step->row;
                tileCol = step->col;
                kind = C_GEAR_GetCellKind(work, tileCol, tileRow);
                C_GEAR_StartTileFlash(&work->tiles[tileCol][tileRow], work, (u8)d_021F31D4[kind], 2, kind, step->stepPeriod);
            }
        }
        if (work->phaseTimer >= 4) {
            C_GEAR_StartFadeIn(work);
            C_GEAR_SetTileMarkersVisible(work, 1);
            work->phase++;
        }
        work->phaseTimer++;
        break;
    case 3:
        if (C_GEAR_IsAnyTileFlashing(work) == 0 && C_GEAR_GetFadeRequestBits(work) == 0)
            return 1;
        break;
    }
    C_GEAR_StepTiles(work);
    return 0;
}









/*
 * The byte phaseTimer must be spelled out at each use (no cached pointer
 * local): a local pointer makes the increment reload the pool constant.
 */
int C_GEAR_StepOutroTiles(CGearWork *work)
{
    unsigned int i;

    if (work->phaseTimer <= 0x7E) {
        for (i = 0; i < 0x24; i++) {
            if (work->phaseTimer == d_021F348C[i].startTick)
                C_GEAR_StartTileFlash(&work->tiles[d_021F348C[i].col][d_021F348C[i].row],
                              work, 4, 0, 4, d_021F348C[i].stepPeriod);
        }
        work->phaseTimer = work->phaseTimer + 1;
    } else {
        if (C_GEAR_IsAnyTileFlashing(work) == 0)
            return 1;
    }
    C_GEAR_StepTiles(work);
    return 0;
}









void C_GEAR_ResetAllTiles(CGearWork *work)
{
    CGearParityPair columnRows = d_021F3334;
    int i, j, rows;

    i = 0;
    for (; i < 9; i++) {
        rows = columnRows.value[i % 2];
        for (j = 0; j < rows; j++)
            C_GEAR_ResetTileFlash(&work->tiles[i][j], work, 4);
    }
}









/*
 * note 2026-10-05 (wD7 lane15): closed. The table entry is a named block local (w = t.w[c]) in the
 *   store block. mwcc puts a named local first in `w + o` (adds r0,r0,r4); the plain t.w[c] load
 *   is a temp and goes second, which was the last 2-byte residue.
 */
void C_GEAR_DrawTile(CGearWork *work, int col, int row, int kind)
{
    CGearTileBases tileBases = d_021F3354;
    int mapCol, mapRow, mapRowIdx, palRow, palette, i, mapColIdx, j;
    u16 *tilemap;

    tilemap = (u16 *)BG_SYS_GetBuf(4);
    C_GEAR_TileToScreen(col, row, &mapCol, &mapRow);
    palRow = d_021F31D4[kind];
    palette = C_GEAR_GetTilePalette(work, palRow, col, row);
    mapRowIdx = mapRow;
    for (i = 0; i < 4; i++) {
        int o = i * 32;
        u16 *mapLine = tilemap + mapRowIdx * 32;
        mapColIdx = mapCol;
        for (j = 0; j < 4; j++) {
            if (mapColIdx >= 0 && mapColIdx < 0x20) {
                int w = tileBases.base[kind];
                mapLine[mapColIdx] = (w + o + j) | ((d_021F323C + palRow * 5)[palette] << 12);
            }
            mapColIdx++;
        }
        mapRowIdx++;
    }
}









int C_GEAR_FindCellOfKind(CGearWork *work, int kind, int *outX, int *outY)
{
    int firstCol = 0;
    int firstRow = 0;
    int found = 0;
    int col;
    int row;

    for (row = 0; row < 4; row++) {
        for (col = 0; col < 9; col++) {
            if (kind == C_GEAR_GetCellKind(work, col, row)) {
                if (found == 0) {
                    firstCol = col;
                    firstRow = row;
                    found = 1;
                }
                if (C_GEAR_IsCellMarked(work, col, row)) {
                    C_GEAR_TileToScreen(col, row, outX, outY);
                    return 1;
                }
                if (C_GEAR_IsCellKind(work, col, row, kind)) {
                    firstCol = col;
                    firstRow = row;
                    found = 1;
                }
            }
        }
    }
    if (found) {
        C_GEAR_TileToScreen(firstCol, firstRow, outX, outY);
        func_020091AC(work->hexMap, firstCol, firstRow, kind, 1, 0);
        C_GEAR_DrawTile(work, firstCol, firstRow, kind);
        BG_SYS_PushTile(4);
        return 1;
    }
    return 0;
}









void C_GEAR_DrawAllCells(CGearWork *work)
{
    int columnRows[2];
    int i;
    int j;
    int rows;

    columnRows[0] = d_021F332C[0];
    columnRows[1] = d_021F332C[1];
    for (i = 0; i < 9; i++) {
        rows = columnRows[i % 2];
        for (j = 0; j < rows; j++)
            C_GEAR_DrawTile(work, i, j, C_GEAR_GetCellKind(work, i, j));
    }
    BG_SYS_PushTile(4);
}









/*
 * The basePalette table must be a struct member (u16 [3][5]); a raw cast keeps
 * the table address in ip and spills the source pointer instead. `n` is declared
 * before `r` so the counter lands at [sp,#0x20] and the handle at [sp,#0x1c].
 */
u32 C_GEAR_LoadSkin(CGearWork *work, int theme, int skin, int loadPalettes)
{
    int colorIdx;
    void *handle;
    CGearFileInfo *file;
    u8 *fileData;
    int slot;
    int k;
    u32 charSize;
    u32 charBase;

    if (loadPalettes) {
        handle = func_02049F78(work->archive, d_021F31E0[theme], &file, 0x8070);
        DWCi_ScreenDC_FlushRange(file->data, file->size);
        GXS_LoadBGPltt(file->data, 0, file->size);
        fileData = file->data;
        for (colorIdx = 0; colorIdx < 5; colorIdx++) {
            for (slot = 0; slot < 3; slot++) {
                work->basePalette[slot][colorIdx] = ((u16 *)(fileData + (colorIdx + 1) * 0x20))[d_021F31A8[slot]];
            }
        }
        GFL_HEAP_Free(handle);
        handle = func_02049F78(work->archive, 0x17, &file, 0x8070);
        for (k = 0; k < 9; k++) {
            C_GEAR_LoadTargetPalette(work, file->data, k);
        }
        GFL_HEAP_Free(handle);
    }
    charSize = 0x5000;
    charBase = BG_SYS_CreateRun(6, charSize, 0);
    work->bgCharBlock = (u16)charBase | (charSize << 16);
    ARC_UTIL_UploadBgCharFromHandle(work->archive, d_021F32E0[skin][theme], 6, charBase, 0, 0, 0x70);
    return func_02049990(work->archive, 2, 6, 0, (u16)work->bgCharBlock, 0, 0, 0x70);
}









/*
 * note:     the two tables are `const`: non-const, the copy of p lands after the first
 *           stack-argument store (4 bytes out). The loop needs i = 0 hoisted first, the
 *           base hoisted and the destination pointer stepped by 4.
 */
void C_GEAR_LoadSpriteResources(CGearWork *work, int theme)
{
    int i;
    void *handle;
    CGearFileInfo *file;
    int *base;

    i = 0;
    work->spritePlttRes = CLACT_RegisterPalette(work->archive, d_021F31C8[theme], 1, 0, 0x70);
    work->spriteCharRes = CLACT_RegisterCharacter(work->archive, 0x16, 0, 1, 0x70);
    work->spriteAnimRes = CLACT_RegisterCellAnim(work->archive, 0x15, 0x14, work->heapId);
    handle = func_02049F78(work->archive, 0x18, &file, work->heapId);
    base = (int *)file->data;
    for (; i < 17; i++) {
        work->beaconColors[i] = base[d_021F33CC[i]];
    }
    GFL_HEAP_Free(handle);
    GFL_NET_RestartWithTimeout(0xda, 0xe);
    GFL_NET_RestartWithDefaultTimeout(0, work->heapId);
}








void C_GEAR_LoadFrameGraphics(CGearWork *work, int customBgLoaded)
{
    if (customBgLoaded == 0)
        func_02049990(work->archive, 1, 5, 0, (u16)work->bgCharBlock, 0, 0, 0x70);
}









/*
 * volatile: 0x021F1722 ldr / 0x021F1726 str of 0x04001000 (REG_DB_DISPCNT_SUB read-modify-write, hardware register)
 *
 * Twin of ov030 NO_GEAR_SetupBackgrounds (same three BgTemplate blocks), plus the
 * C_GEAR_SetupSubScreenBlend call and the sub-screen window-mask clear. d_021F33AC's
 * ov029 hint is contested by another overlay, so its line carries only a4.
 */
void C_GEAR_SetupBackgrounds(CGearWork *work)
{
    int i;

    for (i = 4; i <= 7; i++) {
        BG_SYS_SetPlaneVisible(i, 0);
    }
    {
        struct BgTemplate t = d_021F338C;
        BG_SYS_InitBgLayer(6, &t, 0);
        BG_SYS_SetPlaneVisible(6, 1);
        BG_SYS_SetVisibleLayer(6, 3);
        BG_SYS_SetTileEntry(6, 0, 0, 0, 0x20, 0x20, 0x11);
        BG_SYS_PushTile(6);
    }
    {
        struct BgTemplate t = d_021F33AC;
        BG_SYS_InitBgLayer(5, &t, 0);
        BG_SYS_SetPlaneVisible(5, 1);
        BG_SYS_SetVisibleLayer(5, 1);
        BG_SYS_SetTileEntry(5, 0, 0, 0, 0x20, 0x20, 0x11);
        BG_SYS_PushTile(5);
    }
    {
        struct BgTemplate t = d_021F336C;
        BG_SYS_InitBgLayer(4, &t, 0);
        BG_SYS_SetPlaneVisible(4, 1);
        BG_SYS_SetVisibleLayer(4, 2);
        BG_SYS_SetTileEntry(4, 0, 0, 0, 0x20, 0x20, 0x11);
        BG_SYS_PushTile(4);
    }
    C_GEAR_SetupSubScreenBlend(work);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
}








void C_GEAR_SetupSubScreenBlend(CGearWork *work)
{
    G2x_SetBlendAlpha_(0x04001050, 2, 0x15, 9, 0x10);
}









/*
 * Stack order: c, d, x, y declared in that order ([sp,#0x10], #0xc, #8, #4).
 * The inner switch lists case 3 before case 2 (bodies 1, 6, 5 in the image).
 * C_GEAR_IsColumnRowValid is the unlabelled ov029 leaf filed as ov029_func_021EFEC0.c.
 */
void C_GEAR_HandleButton(CGearWork *work, int key)
{
    int touchCol;
    int touchRow;
    int touchX;
    int touchY;
    int kind;
    u32 bgChar;

    if (work->commEnabled == 0 && key != 6 && key != 0)
        return;
    if (work->command != 0)
        return;
    func_020355D8(1);
    switch (key) {
    case 0:
        TOUCHPANEL_GetPointCont(&touchX, &touchY);
        kind = C_GEAR_HitTestTile(work, touchX, touchY, &touchCol, &touchRow);
        if (work->paintMode != 0) {
            work->touchX = touchX;
            work->touchY = touchY;
            if ((C_GEAR_CountCellsOfKind(work, kind) > 1 || kind == 4) && C_GEAR_IsColumnRowValid(touchCol, touchRow) != 0) {
                C_GEAR_SetCellKind(work, work->hexMap, touchCol, touchRow, (kind + 1) % 5);
                BG_SYS_PushTile(4);
                GFL_USE_PlaySeDefaultVolume(0x628);
            }
        } else if (C_GEAR_IsAnyIndicatorShown(work) == 0) {
            work->selectedCol = touchCol;
            work->selectedRow = touchRow;
            switch (kind) {
            case 1:
                work->command = 1;
                break;
            case 3:
                work->command = 6;
                break;
            case 2:
                work->command = 5;
                break;
            }
        }
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x628);
        work->paintMode ^= 1;
        C_GEAR_SetPaintModeIcon(work, work->paintMode);
        break;
    case 2:
        work->command = 0xC;
        break;
    case 3:
        work->command = 7;
        break;
    case 4:
        work->command = 0xB;
        break;
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x628);
        bgChar = work->bgCharBlock;
        BG_SYS_DeleteHalf(6, (u16)bgChar, (u16)(bgChar >> 16));
        work->skinIndex++;
        work->skinIndex = work->skinIndex % 5;
        func_020090E8(work->hexMap, work->skinIndex);
        C_GEAR_LoadSkin(work, work->colorTheme, work->skinIndex, 0);
        C_GEAR_DrawAllCells(work);
        C_GEAR_SetTileMarkersVisible(work, 1);
        break;
    case 6:
        work->command = 0xD;
        break;
    }
}








void C_GEAR_OnButtonEvent(int key, int buttonState, CGearWork *work)
{
    if (C_GEAR_IsAnyIndicatorShown(work) == 0 && buttonState == 0)
        C_GEAR_HandleButton(work, key);
}









void C_GEAR_SetPaintModeIcon(CGearWork *work, int paintMode)
{
    if (paintMode) {
        CLACT_SetActorAnimIndex(work->hudActors[9], 0);
        CLACT_SetActorAutoAnimSpeed(work->hudActors[9], 0x2000);
        CLACT_SetActorAutoAnim(work->hudActors[9], 1);
    } else {
        CLACT_SetActorAutoAnim(work->hudActors[9], 0);
        CLACT_SetActorAnimIndex(work->hudActors[9], 1);
    }
}









void C_GEAR_CreateHudActors(CGearWork *work)
{
    int i;
    int j;
    CGearActorDesc desc;

    BG_SYS_SetSubPlaneVisible(0x10, 1);
    j = 0;
    for (i = 0; i < 11; i++) {
        desc.x = d_021F3531[i];
        desc.y = d_021F353C[i];
        desc.animIndex = d_021F3526[i];
        if (desc.animIndex == 6 && OS_IsRunOnTwl()) {
            desc.animIndex = 7;
        }
        desc.palOffset = 0;
        desc.surface = 2;
        work->hudActors[i] = CLACT_CreateActor(work->spriteSystem, work->spriteCharRes, work->spritePlttRes,
                                work->spriteAnimRes, &desc, 0, work->heapId);
        CLACT_SetActorDrawEnable(work->hudActors[i], 0);
        CLACT_SetActorVisible(work->hudActors[i], 0);
    }
    C_GEAR_SetPaintModeIcon(work, 0);
    for (j = 0; j < 3; j++) {
        desc.x = 8;
        desc.y = 8;
        desc.animIndex = d_021F3548[j];
        desc.palOffset = 0;
        desc.surface = 2;
        work->tileMarkerActors[j] = CLACT_CreateActor(work->spriteSystem, work->spriteCharRes, work->spritePlttRes,
                                work->spriteAnimRes, &desc, 0, work->heapId);
        CLACT_SetActorDrawEnable(work->tileMarkerActors[j], 0);
        CLACT_SetActorVisible(work->tileMarkerActors[j], 0);
    }
    C_GEAR_UpdateClock(work);
    C_GEAR_UpdateTileMarkers(work);
}








void C_GEAR_SetTileMarkersVisible(CGearWork *work, int visible)
{
    int i;
    for (i = 0; i < 3; i++)
        CLACT_SetActorDrawEnable(work->tileMarkerActors[i], visible);
}









void C_GEAR_SetAllActorsVisible(CGearWork *work, int visible)
{
    int i;

    for (i = 0; i < 20; i++) {
        if (work->actorSlots[i].actor != 0) {
            CLACT_SetActorDrawEnable(work->actorSlots[i].actor, visible);
        }
    }
    for (i = 0; i < 3; i++) {
        if (work->tileMarkerActors[i] != 0 && work->commEnabled != 0) {
            CLACT_SetActorDrawEnable(work->tileMarkerActors[i], visible);
        }
    }
    for (i = 0; i < 11; i++) {
        if (work->hudActors[i] != 0) {
            if ((unsigned)(i - 8) <= 1) {
                if (work->commEnabled != 0) {
                    CLACT_SetActorDrawEnable(work->hudActors[i], visible);
                }
            } else {
                CLACT_SetActorDrawEnable(work->hudActors[i], visible);
            }
        }
    }
    if (work->barActors[0] != 0 && work->commEnabled != 0) {
        CLACT_SetActorDrawEnable(work->barActors[0], visible);
    }
    if (work->barActors[1] != 0 && work->commEnabled != 0) {
        CLACT_SetActorDrawEnable(work->barActors[1], visible);
    }
    if (work->barActors[2] != 0 && work->commEnabled != 0) {
        CLACT_SetActorDrawEnable(work->barActors[2], visible);
    }
    if (visible == 1) {
        C_GEAR_UpdateClock(work);
    }
}








void C_GEAR_SetSplashActorsVisible(CGearWork *work, int visible)
{
    int i;
    for (i = 0; i < 18; i++)
        CLACT_SetActorDrawEnable(work->splashActors[i], visible);
}









void C_GEAR_CreateSplashActors(CGearWork *work)
{
    int i;
    CGearActorDesc desc;

    for (i = 0; i < 18; i++) {
        desc.x = 0x80;
        desc.y = 0x60;
        desc.animIndex = i + 0x12;
        desc.palOffset = 0;
        desc.surface = 2;
        work->splashActors[i] = CLACT_CreateActor(work->spriteSystem, work->spriteCharRes, work->spritePlttRes,
                                work->spriteAnimRes, &desc, 0, work->heapId);
        CLACT_SetActorDrawEnable(work->splashActors[i], 0);
        CLACT_SetActorAutoAnimSpeed(work->splashActors[i], 0x2000);
        CLACT_RestartActorAnim(work->splashActors[i]);
        CLACT_SetActorAutoAnim(work->splashActors[i], 1);
    }
}








void C_GEAR_DeleteSplashActors(CGearWork *work)
{
    int i;
    if (work->splashActors[0] != 0) {
        for (i = 0; i < 18; i++) {
            CLACT_DeleteActor(work->splashActors[i]);
            work->splashActors[i] = 0;
        }
    }
}








int C_GEAR_IsSplashDone(CGearWork *work)
{
    int i;
    for (i = 0; i < 18; i++) {
        if (CLACT_IsActorAnimActive(work->splashActors[i]) == 1)
            return 0;
    }
    return 1;
}









void C_GEAR_CreateBarActors(CGearWork *work)
{
    CGearActorDesc desc;

    desc.x = 0x68;
    desc.y = 0xaa;
    desc.animIndex = 0x28;
    desc.palOffset = 0;
    desc.surface = 2;
    work->barActors[0] = CLACT_CreateActor(work->spriteSystem, work->spriteCharRes, work->spritePlttRes,
                                        work->spriteAnimRes, &desc, 0, work->heapId);
    CLACT_SetActorDrawEnable(work->barActors[0], 0);
    CLACT_SetActorVisible(work->barActors[0], 0);

    desc.x = 0x68;
    desc.y = 0xaa;
    desc.animIndex = 0x27;
    desc.palOffset = 0x14;
    desc.surface = 2;
    work->barActors[1] = CLACT_CreateActor(work->spriteSystem, work->spriteCharRes, work->spritePlttRes,
                                        work->spriteAnimRes, &desc, 0, work->heapId);
    CLACT_SetActorDrawEnable(work->barActors[1], 0);
    CLACT_SetActorVisible(work->barActors[1], 0);

    desc.x = 0x22;
    desc.y = 0xaa;
    desc.animIndex = 0x10;
    desc.palOffset = 0;
    desc.surface = 2;
    work->barActors[2] = CLACT_CreateActor(work->spriteSystem, work->spriteCharRes, work->spritePlttRes,
                                        work->spriteAnimRes, &desc, 0, work->heapId);
    CLACT_SetActorDrawEnable(work->barActors[2], 0);
    CLACT_SetActorVisible(work->barActors[2], 0);
}









void C_GEAR_UpdateBeaconColors(CGearWork *work)
{
    int receiveNo;
    int slotCount;
    int attempt;
    int newLogIdx;
    void *log;

    slotCount = 0;
    if (work->commEnabled == 0) {
        return;
    }
    if (C_GEAR_IsCallTabActive(work) != 0) {
        return;
    }
    receiveNo = GAME_BEACON_GetReceiveCount();
    if (work->beaconPending == 0) {
        newLogIdx = 0;
        if (GAME_BEACON_GetNextNewLogIndex(&newLogIdx) != 30) {
            work->beaconPending = 1;
        }
    }
    receiveNo--;
    for (attempt = 0; attempt < 30; attempt++) {
        if (slotCount >= 10) {
            break;
        }
        if (receiveNo < 0) {
            PALANM_CopyToSlot(work->palAnm, &work->beaconColors[16], 3, (u16)(d_021F33CC[slotCount] * 2 + 0x60), 4);
            slotCount++;
        } else {
            log = GAME_BEACON_GetLogByReceiveNo(receiveNo);
            if (log != 0) {
                PALANM_CopyToSlot(work->palAnm, &work->beaconColors[GAME_BEACON_ACCESSOR_GetFavoriteColorIndex(log)], 3,
                              (u16)(d_021F33CC[slotCount] * 2 + 0x60), 4);
                slotCount++;
            }
            receiveNo--;
        }
    }
}








void C_GEAR_DeleteBarActors(CGearWork *work)
{
    if (work->barActors[0] != 0) {
        CLACT_DeleteActor(work->barActors[0]);
        work->barActors[0] = 0;
    }
    if (work->barActors[1] != 0)
        CLACT_DeleteActor(work->barActors[1]);
    if (work->barActors[2] != 0) {
        CLACT_DeleteActor(work->barActors[2]);
        work->barActors[2] = 0;
    }
}









void C_GEAR_LoadGraphics(CGearWork *work, int introMode)
{
    int z;

    work->colorTheme = func_02008550(GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C(work->gameSystem)));
    work->skinIndex = func_020090F0(work->hexMap);
    z = 0;
    work->spriteSystem = CLACT_CreateUnit(0x44, 0, work->heapId);
    work->spriteResList = CLACT_CreateRenderer(d_021F3214, 1, work->heapId);
    CLACT_SetUnitRenderer(work->spriteSystem, work->spriteResList);
    C_GEAR_LoadSkin(work, work->colorTheme, work->skinIndex, 1);
    C_GEAR_LoadSpriteResources(work, work->colorTheme);
    C_GEAR_CreateHudActors(work);
    C_GEAR_CreateBarActors(work);
    work->buttonTask = BUTTON_MAN_Create(d_021F3272, C_GEAR_OnButtonEvent, work, work->heapId);
    if (introMode) {
        C_GEAR_DrawEmptyBoard(work);
        C_GEAR_SetAllActorsVisible(work, z);
    } else {
        C_GEAR_DrawAllCells(work);
        C_GEAR_SetAllActorsVisible(work, 1);
        C_GEAR_SetTileMarkersVisible(work, 1);
    }
}









void C_GEAR_DeleteActors(CGearWork *work)
{
    int i;
    unsigned int v;

    C_GEAR_DeleteBarActors(work);
    C_GEAR_DeleteSplashActors(work);
    for (i = 0; i < 11; i++) {
        if (work->hudActors[i] != 0) {
            CLACT_DeleteActor(work->hudActors[i]);
            work->hudActors[i] = 0;
        }
    }
    for (i = 0; i < 3; i++) {
        if (work->tileMarkerActors[i] != 0) {
            CLACT_DeleteActor(work->tileMarkerActors[i]);
            work->tileMarkerActors[i] = 0;
        }
    }
    for (i = 0; i < 20; i++) {
        if (work->actorSlots[i].actor != 0) {
            CLACT_DeleteActor(work->actorSlots[i].actor);
            work->actorSlots[i].actor = 0;
        }
    }
    CLACT_ReleaseCellAnim(work->spriteAnimRes);
    CLACT_ReleaseCharacter(work->spriteCharRes);
    CLACT_ReleasePalette(work->spritePlttRes);
    v = work->bgCharBlock;
    BG_SYS_DeleteHalf(6, (unsigned short)v, (unsigned short)(v >> 16));
}








void C_GEAR_FreeGraphics(CGearWork *work)
{
    if (work->buttonTask)
        BUTTON_MAN_Delete(work->buttonTask);
    C_GEAR_DeleteActors(work);
    CLACT_DeleteRenderer(work->spriteResList);
    CLACT_DeleteUnit(work->spriteSystem);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_SetPlaneVisible(5, 0);
    BG_SYS_SetPlaneVisible(6, 0);
}







u8 C_GEAR_GetBatteryFrame(void)
{
    return d_021F3520[UI_GetPowerState()];
}








static inline void SetActorAnimFrame(struct Actor *actor, int frame)
{
    if (frame != CLACT_GetActorAnimSeqCount(actor)) {
        CLACT_SetActorAnimIndex(actor, (u16)frame);
    }
}








void C_GEAR_UpdateClock(CGearWork *work)
{
    RtcTime time;
    struct Actor *actor;
    int digit;

    GF_STANDARD_SetField00(&time);
    CLACT_SetActorDrawEnable(work->hudActors[0], 0);

    actor = work->hudActors[1];
    digit = time.hour / 10;
    SetActorAnimFrame(actor, digit);
    if (digit == 0) {
        CLACT_SetActorDrawEnable(actor, 0);
    } else {
        CLACT_SetActorDrawEnable(actor, 1);
    }

    actor = work->hudActors[2];
    digit = time.hour % 10;
    SetActorAnimFrame(actor, digit);
    actor = work->hudActors[3];
    digit = time.second & 1;
    SetActorAnimFrame(actor, digit);
    actor = work->hudActors[4];
    digit = time.minute / 10;
    SetActorAnimFrame(actor, digit);
    actor = work->hudActors[5];
    digit = time.minute % 10;
    SetActorAnimFrame(actor, digit);

    actor = work->hudActors[6];
    if (OS_IsRunOnTwl()) {
        SetActorAnimFrame(actor, C_GEAR_GetBatteryFrame());
    } else {
        SetActorAnimFrame(actor, UI_GetPowerState() == 5);
    }
}








void C_GEAR_UpdateTileMarkers(CGearWork *work)
{
    int i;
    int pixelX;
    int pixelY;
    CGearPos pos;

    for (i = 0; i < 3; i++) {
        if (C_GEAR_FindCellOfKind(work, i + 1, &pixelX, &pixelY)) {
            pixelX = pixelX * 8;
            pixelY = pixelY * 8;
            pos.x = pixelX + 0x10;
            pos.y = pixelY + 0xf;
            CLACT_AddActorSurfacePos(work->tileMarkerActors[i], &pos, 0);
            pixelX += 0x20;
            CLACT_SetActorDrawPriority(work->tileMarkerActors[i], (pixelX / 8) & 0xff);
        } else {
            pos.x = -0x40;
            pos.y = 0;
            CLACT_AddActorSurfacePos(work->tileMarkerActors[i], &pos, 0);
        }
    }
}








void C_GEAR_RunFrame(CGearWork *work)
{
    BUTTON_MAN_UpdateSlots(work->buttonTask);
    C_GEAR_TickIndicators(work);
    C_GEAR_TickTabFrame(work);
    C_GEAR_UpdateClock(work);
    if (C_GEAR_IsAnyIndicatorShown(work) == 0) {
        if (work->commEnabled) {
            C_GEAR_TickTabTimers(work);
            C_GEAR_UpdateTabPalettes(work);
            C_GEAR_UpdateBeaconColors(work);
        }
    } else {
        work->command = 0;
    }
}







void C_GEAR_StepIdle(CGearWork *work)
{
    if (work->endCallback != 0)
        (work->endCallback)(work->endCallbackArg);
    work->endCallback = 0;
    work->endCallbackArg = 0;
    if (C_GEAR_IsIdleForInput(work))
        C_GEAR_RunFrame(work);
}








void C_GEAR_StepIntroEnd(CGearWork *work)
{
    void (*callback)(int);

    if (C_GEAR_StepIntroTiles(work) == 0) {
        callback = work->endCallback;
        if (callback)
            callback(work->endCallbackArg);
        work->endCallback = 0;
        work->endCallbackArg = 0;
        return;
    }
    C_GEAR_InitTabTimersPowerOff(work);
    C_GEAR_ChangeStep(work, C_GEAR_StepIdle, 0xF92);
}








void C_GEAR_StepOpen(CGearWork *work)
{
    switch (work->phase) {
    case 0:
        C_GEAR_DrawEmptyBoard(work);
        C_GEAR_ResetTabPalettes(work);
        C_GEAR_SetAllActorsVisible(work, 0);
        (work->phase)++;
        return;
    case 1:
        if (C_GEAR_IsIdleForInput(work)) {
            C_GEAR_CreateSplashActors(work);
            C_GEAR_SetSplashActorsVisible(work, 1);
            (work->phase)++;
            return;
        }
        break;
    case 2:
        if (C_GEAR_IsSplashDone(work)) {
            C_GEAR_StartFadeOut(work);
            work->phaseTimer = 0;
            (work->phase)++;
            return;
        }
        break;
    case 3:
        if (CTRDG_IsAgbCartridge(work)) {
            C_GEAR_StopFade(work);
            work->phase = 7;
            return;
        }
        if (work->phaseTimer < 8) {
            (work->phaseTimer)++;
            return;
        }
        C_GEAR_SetSplashActorsVisible(work, 0);
        C_GEAR_DeleteSplashActors(work);
        C_GEAR_StartFlashFade(work);
        (work->phase)++;
        work->phaseTimer = 0;
        return;
    case 4:
        if (CTRDG_IsAgbCartridge(work)) {
            work->phase = 7;
            return;
        }
        if (C_GEAR_StepOutroTiles(work) == 1) {
            work->phaseTimer = 0;
            (work->phase)++;
            return;
        }
        break;
    case 5:
        if (CTRDG_IsAgbCartridge(work)) {
            work->phase = 7;
            return;
        }
        (work->phaseTimer)++;
        if (work->phaseTimer >= 8) {
            C_GEAR_ResetAllTiles(work);
            work->phaseTimer = 0;
            (work->phase)++;
            return;
        }
        break;
    case 6:
        (work->phaseTimer)++;
        if (work->phaseTimer >= 8) {
            C_GEAR_SetAllActorsVisible(work, 1);
            C_GEAR_SetTileMarkersVisible(work, 0);
            C_GEAR_ChangeStep(work, C_GEAR_StepIntroEnd, 0x100b);
            return;
        }
        break;
    case 7:
        C_GEAR_DeleteSplashActors(work);
        C_GEAR_StartFlashFade(work);
        C_GEAR_StopTileFlashes(work);
        C_GEAR_ResetAllTiles(work);
        work->phaseTimer = 8;
        work->phase = 6;
        break;
    }
}








void C_GEAR_StepClose(CGearWork *work)
{
    if (work->phaseTimer == 0) {
        C_GEAR_StartFlashFade(work);
        C_GEAR_SetAllActorsVisible(work, 1);
        C_GEAR_SetTileMarkersVisible(work, 0);
        C_GEAR_DeleteSplashActors(work);
        C_GEAR_DrawEmptyBoard(work);
        C_GEAR_ResetTabPalettes(work);
    }
    work->phaseTimer += 1;
    if (work->phaseTimer >= 0x10) {
        work->phaseTimer = 0;
        C_GEAR_ChangeStep(work, C_GEAR_StepIntroEnd, 0x1041);
    }
}








/*
 * base is a u32 holding (u16)work->bgCharBlock and re-cast (u16) in the palette add:
 * that is the second lsls/lsrs pair.  The 0x0200910C result goes to a
 * local before base is loaded (the load sits between the call and cmp);
 * declaring i before buf gives i r4 and buf r5.
 */
int C_GEAR_LoadCustomBackground(CGearWork *work, struct GameSystem *gameSystem)
{
    int result;
    struct SaveCtrl *saveSys;
    u16 crc;
    u32 charBase;
    u16 savedCrc;
    int i;
    u8 *buf;
    u16 *pal;

    result = 0;
    buf = GFL_HEAP_Alloc(0x70, 0x3000, 0, d_021F3554, 0x104E);
    saveSys = GAME_DATA_GetSaveControl(ICA_ANIME_GetField1C(gameSystem));
    if (SAVE_CONTROL_LoadExtraSaveWithBuffer(saveSys, 4, 0x70, buf, 0x3000) == 1) {
        crc = GF_STANDARD_SetupCalc(buf, 0x2600);
        savedCrc = func_0200910C(BLOCK20_SAVEDATA_GetBlock(saveSys));
        charBase = (u16)work->bgCharBlock;
        if (crc == savedCrc && MUSICAL_DIST_SAVE_IsFooterSet(buf) != 0) {
            result = 1;
            for (i = 0; i < 15; i++) {
                BG_SYS_LoadTileData(6, buf + i * 0x220, 0x220, charBase + (i + 5) * 0x20);
            }
            BG_SYS_LoadPltt(6, buf + 0x1FE0, 0x20, 0x140);
            BG_SYS_DecodeTile(5, buf + 0x2000, 0x600);
            pal = (u16 *)BG_SYS_GetBuf(5);
            for (i = 0; i < 0x600 / 2; i++) {
                pal[i] += (u16)charBase;
            }
            BG_SYS_PushTile(5);
        }
    }
    func_0200734C(saveSys, 4);
    GFL_HEAP_Free(buf);
    return result;
}








void C_GEAR_OnCommDisconnect(CGearWork *work)
{
    C_GEAR_StopFade(work);
    if (work->fadeCtx != 0)
        TCB_Main(work->fadeCtx);
    C_GEAR_StartFlashFade(work);
    C_GEAR_DrawEmptyBoard(work);
    if (work->fadeCtx != 0)
        TCB_Main(work->fadeCtx);
    work->commEvent = 1;
}







void C_GEAR_OnCommEvent(CGearWork *work)
{
    work->commEvent = 2;
}







void C_GEAR_TransferPalettesTask(void *task, CGearWork *work)
{
    if (work->palAnm != 0)
        PALANM_TransferPalettes(work->palAnm);
}






/*
 * 2026-10-05 (wave D5 lane 02): arm9 UI_SetSleepHookGlobal/UI_SetWakeHookGlobal and their setters UI_SetSleepHook/UI_SetWakeHook are now filed in src/matched/arm9/; the wrappers show MATCH only until the labels exist. Re-run after the integrator labels them.
 * 2026-10-04 (wD2 lane 09): bytes are identical; 3 of 41 relocations open.
 * Filed leaf C_GEAR_OnCommEvent as matched ov029_func_021F24FC.c (EXACT).
 * Open: ABS32 +01C0 to 021F24FC (witness index not yet regenerated),
 * and THM_CALL +0128/+0130 to unlabelled arm9 02035010 and 02035040 (arm9 wrappers:
 * r2=*(0x021469BC), tail call to 02035004/02035034 style stubs, no source or label yet).
 *
 * Byte-correct.  Blocked by two unlabelled ARM9 leaves (the integrator's), so the
 * overlay leaf 0x021F24FC is not filed either:
 *   +0128 UI_SetSleepHookGlobal (arm): verified MATCH with `one --arm`, capped
 *     only by its own unlabelled tail-call target 0x02035004
 *     (str r1,[r0,#0x14]; str r2,[r0,#0x28]; bx lr):
 *       extern void *d_021469BC;
 *       void UI_SetSleepHookGlobal(void *cb, void *arg)
 *       { UI_SetSleepHook(d_021469BC, cb, arg); }
 *   +0130 UI_SetWakeHookGlobal (arm): the same wrapper over 0x02035034
 *     (str r1,[r0,#0x10]; str r2,[r0,#0x28]; bx lr), MATCH likewise:
 *       void UI_SetWakeHookGlobal(void *cb, void *arg)
 *       { UI_SetWakeHook(d_021469BC, cb, arg); }
 *   +01C0 ABS32 C_GEAR_OnCommEvent (ov029): unlabelled leaf
 *     `void C_GEAR_OnCommEvent(CGearWork *work) { work->commEvent = 2; }` (ldr r1,=0x451;
 *     movs r2,#2; strb r2,[r0,r1]; bx lr).
 * Levers: r = 0 at the top shares the zero register with the command/lastCommand
 * stores; t = 1 assigned after the PALANM_Create store keeps t in a stack
 * slot and 0x1C0 in r7; commEnabled is a u8 field (ldrb); C_GEAR_SetPowerState's second
 * argument is int here (no narrowing before the call).
 *
 * 2026-10-05 (wD4 lane 15): re-run, still MATCH. Open: unlabelled arm9 02035010 and 02035040 (no source change possible here).
 */
void C_GEAR_Init(CGearWork *work, struct HexMap *hexMap, int parentWork, struct GameSystem *gameSystem, int introMode)
{
    int customBgLoaded = 0;
    int powerOn;
    void *eventWork;

    work->heapId = 0x70;
    work->hexMap = hexMap;
    work->parentWork = parentWork;
    work->gameSystem = gameSystem;
    work->powerOn = 1;
    work->commEnabled = ICA_ANIME_IsConfigFlagSet(gameSystem);
    work->agbSlotPresent = 1;
    work->command = 0;
    work->lastCommand = 0;
    work->archive = ARC_TOOL_CreateHandle(0x1e, 0x70);
    work->fadeMem = GFL_HEAP_Alloc(0x70, TCB_GetTaskOffset(4), 1, d_021F3554, 4280);
    work->fadeCtx = TCB_Init(4, work->fadeMem);
    if (introMode != 0) {
        C_GEAR_ChangeStep(work, C_GEAR_StepOpen, 4284);
    } else {
        C_GEAR_InitTabTimersPowerOn(work);
        C_GEAR_ChangeStep(work, C_GEAR_StepIdle, 4287);
    }
    C_GEAR_SetupBackgrounds(work);
    C_GEAR_LoadGraphics(work, introMode);
    if (func_02009100(work->hexMap) != 0)
        customBgLoaded = C_GEAR_LoadCustomBackground(work, gameSystem);
    C_GEAR_LoadFrameGraphics(work, customBgLoaded);
    C_GEAR_InitTiles(work);
    work->palAnm = PALANM_Create(0x70);
    powerOn = 1;
    PALANM_SetAutoTransfer(work->palAnm, 1);
    PALANM_AllocSlotBuffers(work->palAnm, 3, 0x1C0, 0x70);
    PALANM_AllocSlotBuffers(work->palAnm, 1, 0x1C0, 0x70);
    PALANM_CopyHwPaletteToSlot(work->palAnm, 3, 0, 0x1C0);
    PALANM_CopyHwPaletteToSlot(work->palAnm, 1, 0, 0x1C0);
    C_GEAR_TintPalettes(work, work->commEnabled);
    PALANM_TransferPalettes(work->palAnm);
    work->palTransferTask = GFL_USE_AddMainTask(C_GEAR_TransferPalettesTask, work, 1);
    UI_SetSleepHookGlobal(C_GEAR_OnCommDisconnect, work);
    UI_SetWakeHookGlobal(C_GEAR_OnCommEvent, work);
    C_GEAR_CreateFadeFx(work, &work->fadeFx);
    C_GEAR_UpdateBeaconColors(work);
    C_GEAR_UpdateClock(work);
    if (introMode == 0) {
        if (GAMESYSTEM_IsEventActive(gameSystem) != 0)
            powerOn = 0;
        C_GEAR_SetPowerState(work, powerOn);
        C_GEAR_ApplyIndicators(work);
    } else {
        C_GEAR_StepOpen(work);
    }
    if (work->fadeCtx != 0)
        TCB_Main(work->fadeCtx);
    eventWork = ICA_ANIME_GetField24(gameSystem);
    if (eventWork != 0 && INTRUDE_COMM_GetVisitProgress(eventWork) == 2)
        INTRUDE_COMM_SetCompleted(eventWork);
}






void C_GEAR_Cleanup(CGearWork *work)
{
    void *r = ICA_ANIME_GetField24(work->gameSystem);

    if (r != 0) {
        if (INTRUDE_COMM_GetVisitProgress(r) == 2)
            INTRUDE_COMM_SetCompleted(r);
    }
    C_GEAR_DeleteFadeFx(&work->fadeFx);
    UI_SetSleepHookGlobal(0, 0);
    UI_SetWakeHookGlobal(0, 0);
    GFL_NET_RestartNoTimeout();
    GFL_NET_RestartWithDefaultTimeout(0, work->heapId);
    PALANM_FreeSlotBuffers(work->palAnm, 3);
    PALANM_FreeSlotBuffers(work->palAnm, 1);
    PALANM_Delete(work->palAnm);
    TCB_Noop(work->fadeCtx);
    GFL_HEAP_Free(work->fadeMem);
    TCB_DeleteTask(work->palTransferTask);
    if (work->lastCommand != 5) {
        func_02028A70(GAME_DATA_GetBgmInfo(ICA_ANIME_GetField1C(work->gameSystem)));
    }
    ARC_TOOL_DeleteHandle(work->archive);
    C_GEAR_FreeGraphics(work);
    REG_DB_BLDCNT = 0;
    MI_CpuFill8(work, 0, sizeof(CGearWork));
}





CGearWork *C_GEAR_Create(struct HexMap *hexMap, int parentWork, struct GameSystem *gameSystem, int introMode)
{
    CGearWork *work;
    work = GFL_HEAP_Alloc(0x70, sizeof(CGearWork), 1, d_021F3554, 0x1147);
    C_GEAR_Init(work, hexMap, parentWork, gameSystem, introMode);
    return work;
}





CGearWork *C_GEAR_Open(struct HexMap *hexMap, int parentWork, struct GameSystem *gameSystem, void (*callback)(int), int callbackArg, int introMode)
{
    CGearWork *work = C_GEAR_Create(hexMap, parentWork, gameSystem, introMode);

    work->endCallback = callback;
    work->endCallbackArg = callbackArg;
    if (introMode != 0) {
        C_GEAR_ChangeStep(work, C_GEAR_StepOpen, 0x1160);
        work->agbSlotPresent = 0;
    } else {
        if (work->endCallback != 0)
            (work->endCallback)(work->endCallbackArg);
        work->endCallback = 0;
        work->endCallbackArg = 0;
    }
    C_GEAR_LoadSkinMember(hexMap, work->archive, func_020056EC(10), 0x70);
    C_GEAR_UpdateTileMarkers(work);
    return work;
}





/*
 * The listing extent (316 B) runs over an unlabelled 4-byte follower at
 * 0x021F2980 (`bx lr`); the function is 312 B.  C_GEAR_SetPowerState's second
 * argument is this function's r1, forwarded untouched.
 */
void C_GEAR_Update(CGearWork *work, u8 powerOn)
{
    int linkMode;
    u32 padKeys;
    struct SoundSys *soundSys;

    if (work->commEvent == 1)
        return;

    C_GEAR_SetPowerState(work, powerOn);
    if (C_GEAR_IsAnyIndicatorShown(work) == 0) {
        linkMode = INTRUDE_COMM_GetRequestState(ICA_ANIME_GetField24(work->gameSystem));
        if (linkMode == 3) {
            if (work->callTabShown == 0) {
                C_GEAR_SetTabMode(work, 1, 0);
                work->callTabShown = 1;
            }
        } else {
            if (work->callTabShown == 1) {
                C_GEAR_SetTabMode(work, 0, 0);
                work->callTabShown = 0;
            }
        }
        if (linkMode == 0) {
            padKeys = WIH_DWC_PollStatus(GAME_DATA_GetField1A0(ICA_ANIME_GetField1C(work->gameSystem)));
            soundSys = GAME_DATA_GetBgmInfo(ICA_ANIME_GetField1C(work->gameSystem));
            if (padKeys & 8) {
                if (work->ringtoneActive == 0) {
                    work->ringtoneActive = 1;
                    C_GEAR_SetTabMode(work, 1, 1);
                }
                FIELD_SOUND_SYSTEM_StartRingtone(soundSys);
            } else if ((padKeys & 8) == 0 && work->ringtoneActive != 0) {
                func_02028A70(soundSys);
                work->ringtoneActive = 0;
                C_GEAR_SetTabMode(work, 0, 0);
            }
        }
    }

    if (work->commEvent == 2) {
        work->commEvent = 0;
        if (C_GEAR_IsAnyIndicatorShown(work) == 0) {
            C_GEAR_ChangeStep(work, C_GEAR_StepClose, 0x11C5);
        } else {
            C_GEAR_DeleteSplashActors(work);
            C_GEAR_SetAllActorsVisible(work, 1);
            C_GEAR_DrawAllCells(work);
            C_GEAR_FadeBackground(work, C_GEAR_IsAnyIndicatorShown(work));
            C_GEAR_InitTabTimersPowerOn(work);
            C_GEAR_ChangeStep(work, C_GEAR_StepIdle, 0x11D4);
        }
    }

    if (work->stepFunc != 0)
        work->stepFunc(work);
    if (work->fadeCtx != 0)
        TCB_Main(work->fadeCtx);
}




void C_GEAR_Nop(void)
{
}


void C_GEAR_Destroy(CGearWork *work)
{
    C_GEAR_Cleanup(work);
    GFL_HEAP_Free(work);
}





int C_GEAR_Restart(CGearWork *work)
{
    struct HexMap *hexMap = work->hexMap;
    int parentWork = work->parentWork;
    struct GameSystem *gameSystem = work->gameSystem;

    if (work->stepFunc == C_GEAR_StepIdle) {
        WIPE_SetBrightnessFadeOut(1, 0);
        C_GEAR_Cleanup(work);
        C_GEAR_Init(work, hexMap, parentWork, gameSystem, 0);
        WIPE_ResetBrightness(1);
        return 1;
    }
    return 0;
}





/*
 * The listing extent (252 B) runs over the matched follower 0x021F2AB8;
 * the function is 224 B.  Case order 1/6, 5, 12/13, 7/11 is the table's
 * code order; the shared "sound; r = C_GEAR_StartPanelEvent" tails are cross-jumped.
 */
struct GameEvent *C_GEAR_HandleCommand(CGearWork *work, int enabled)
{
    struct GameEvent *event = 0;
    void *handlerData;

    ICA_ANIME_GetField24(work->gameSystem);
    handlerData = ICA_ANIME_GetField20(work->gameSystem);
    if (enabled == 0 || handlerData == 0)
        return 0;

    switch (work->command) {
    case 1:
    case 6:
        if (C_GEAR_IsCallTabActive(work) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x54E);
            event = C_GEAR_StartPanelEvent(work, work->command);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x7E3);
            C_GEAR_StartSelectedRipple(work);
            C_GEAR_ChangeStep(work, C_GEAR_StepWaitSlots, 0x1238);
        }
        break;
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x54E);
        event = C_GEAR_StartPanelEvent(work, work->command);
        break;
    case 12:
    case 13:
        GFL_USE_PlaySeDefaultVolume(0x628);
        event = C_GEAR_StartPanelEvent(work, work->command);
        break;
    case 7:
    case 11:
        if (C_GEAR_IsCallTabActive(work) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x628);
            event = C_GEAR_StartPanelEvent(work, work->command);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x7E3);
        }
        break;
    }

    if (event != 0) {
        work->lastCommand = work->command;
        C_GEAR_ChangeStep(work, C_GEAR_NoOp, 0x1256);
    }
    work->command = 0;
    return event;
}





/*
 * Unlabelled leaf, sole blocker of ov021 FIELD_EVENT_CHECK_StopSoundAfterEvent.
 */
int C_GEAR_IsLastCommandKind5(CGearWork *work)
{
    if (work == 0)
        return 0;
    if (work->lastCommand == 5)
        return 1;
    return 0;
}




void C_GEAR_StopRingtone(CGearWork *work)
{
    if (work != 0) {
        work->ringtoneActive = 0;
        C_GEAR_SetTabMode(work, 0, 0);
    }
}





void C_GEAR_SetCellKind(CGearWork *work, struct HexMap *hexMap, int col, int row, int kind)
{
    int scanRow;
    int scanCol;

    for (scanRow = 0; scanRow < 4; scanRow++) {
        for (scanCol = 0; scanCol < 9; scanCol++) {
            if (kind == C_GEAR_GetCellKind(work, scanCol, scanRow)) {
                if (C_GEAR_IsCellMarked(work, scanCol, scanRow) != 0) {
                    func_020091AC(hexMap, scanCol, scanRow, kind, 0, 1);
                    C_GEAR_DrawTile(work, scanCol, scanRow, kind);
                } else if (C_GEAR_IsCellKind(work, scanCol, scanRow, kind) != 0) {
                    func_020091AC(hexMap, scanCol, scanRow, kind, 0, 0);
                }
            }
        }
    }
    func_020091AC(hexMap, col, row, kind, 1, 0);
    C_GEAR_DrawTile(work, col, row, kind);
    BG_SYS_PushTile(4);
    C_GEAR_UpdateTileMarkers(work);
}




u32 C_GEAR_GetCellKind(const CGearWork *work, int col, int row)
{
    if (work->commEnabled != 0)
        return func_02009110(work->hexMap, col, row);
    return 0;
}




int C_GEAR_IsCellMarked(const CGearWork *work, int col, int row)
{
    if (work->commEnabled != 0)
        return func_02009134(work->hexMap, col, row);
    return 0;
}




int C_GEAR_IsCellKind(const CGearWork *work, int col, int row, int kind)
{
    if (work->commEnabled != 0)
        return func_02009160(work->hexMap, col, row, kind);
    return 0;
}


int CTRDG_IsAgbCartridge(CGearWork *work)
{
    if (work->agbSlotPresent) {
        if (CTRDGi_IsAgbCartridgeAtInit())
            return 1;
    }
    return 0;
}




int C_GEAR_StepIconAnim(CGearWork *work)
{
    switch (work->phase) {
    case 0:
        CLACT_SetActorAutoAnim(work->hudActors[work->activeIcon], 1);
        CLACT_SetActorAutoAnimSpeed(work->hudActors[work->activeIcon], 1 << 13);
        work->phase += 1;
        break;
    case 1:
        if (CLACT_IsActorAnimActive(work->hudActors[work->activeIcon]) == 0)
            return 1;
        break;
    }
    return 0;
}


int C_GEAR_StepFadeIcon(CGearWork *work)
{
    switch (work->phase) {
    case 0:
        switch (work->activeIcon) {
        case 3:
            C_GEAR_StartFadeFx(&work->fadeFx, 0x1c0);
            break;
        case 4:
            C_GEAR_StartFadeFx(&work->fadeFx, 0x200);
            break;
        }
        work->phase += 1;
        break;
    case 1:
        if (C_GEAR_StepFadeFx(&work->fadeFx) != 0)
            return 1;
        break;
    }
    return 0;
}

/*
 * Unlabelled empty callback (bx lr), printed as a pool word; its only
 * referrer is the pool word in C_GEAR_HandleCommand, which it blocks.
 */
void C_GEAR_NoOp(CGearWork *work)
{
}


void C_GEAR_ShowOffIndicator(CGearWork *work)
{
    if (work->offIndicator == 0) {
        work->offIndicator = 1;
        work->indicatorDirty = 1;
        work->indicatorTimer = 0;
    }
}

void C_GEAR_ShowCommIndicator(CGearWork *work)
{
    if (work->commIndicator == 0) {
        work->commIndicator = 1;
        work->indicatorDirty = 1;
        work->indicatorTimer = 0;
    }
}

void C_GEAR_HideCommIndicator(CGearWork *work)
{
    if (work->commIndicator != 0) {
        work->commIndicator = 0;
        work->indicatorDirty = 1;
        work->indicatorTimer = 0;
    }
}

void C_GEAR_HideOffIndicator(CGearWork *work)
{
    if (work->offIndicator == 1) {
        work->offIndicator = 0;
        work->indicatorDirty = 1;
        work->indicatorTimer = 0;
    }
}

void C_GEAR_TickIndicators(CGearWork *work)
{
    if (work->indicatorDirty != 0) {
        work->indicatorTimer++;
        if (work->indicatorTimer >= 8) {
            C_GEAR_FadeBackground(work, C_GEAR_IsAnyIndicatorShown(work));
            work->indicatorDirty = 0;
        }
    }
}

void C_GEAR_ApplyIndicators(CGearWork *work)
{
    if (work->indicatorDirty != 0) {
        C_GEAR_FadeBackground(work, C_GEAR_IsAnyIndicatorShown(work));
        work->indicatorDirty = 0;
    }
}

int C_GEAR_IsAnyIndicatorShown(CGearWork *work)
{
    if (work->offIndicator != 0)
        return 1;
    if (work->commIndicator != 0)
        return 1;
    return 0;
}


void C_GEAR_TickTabFrame(CGearWork *work)
{
    if (C_GEAR_IsAnyIndicatorShown(work) == 0 && work->tabActive != 0) {
        work->tabFrame += 1;
        if (work->tabFrame >= 8) {
            if (C_GEAR_IsCallTabActive(work) != 0)
                C_GEAR_FadeAccentColors(work, 1);
            else
                C_GEAR_FadeAccentColors(work, 0);
            work->tabActive = 0;
        }
    }
}


void C_GEAR_CreateFadeFx(CGearWork *work, CGearFadeFx *fx)
{
    struct {
        unsigned short a;
        unsigned short b;
        unsigned short c;
        unsigned char d;
        unsigned char e;
    } header;

    header.a = 0;
    header.b = 0;
    header.c = 0x25;
    header.d = 0;
    header.e = 2;
    fx->actor = CLACT_CreateActor(work->spriteSystem, work->spriteCharRes, work->spritePlttRes,
                              work->spriteAnimRes, &header, 0, work->heapId);
    CLACT_SetActorDrawEnable(fx->actor, 0);
    fx->palAnm = work->palAnm;
    fx->fadeCtx = work->fadeCtx;
}


void C_GEAR_DeleteFadeFx(CGearFadeFx *fx)
{
    CLACT_DeleteActor(fx->actor);
}

void C_GEAR_StartFadeFx(CGearFadeFx *fx, int palette)
{
    CLACT_RestartActorAnim(fx->actor);
    CLACT_SetActorAutoAnim(fx->actor, 1);
    CLACT_SetActorAutoAnimSpeed(fx->actor, 0x2000);
    fx->active = 1;
    fx->palette = palette;
}


int C_GEAR_StepFadeFx(CGearFadeFx *fx)
{
    if (fx->active == 0)
        return 1;
    if (CLACT_IsActorAnimActive(fx->actor) == 0) {
        fx->active = 0;
        return 1;
    }
    PALANM_RequestFade(fx->palAnm, 8, fx->palette, -0x78, 0,
                       (u8)gCGearFadeSteps[CLACT_GetActorAnimSeqCount(fx->actor)], 0,
                       fx->fadeCtx);
    return 0;
}


struct GameEvent *C_GEAR_StartPanelEvent(CGearWork *work, int kind)
{
    struct GameEvent *event = GAME_EVENT_Create(work->gameSystem, 0, C_GEAR_PanelEventMain, 8);
    CGearEventWork *req = func_020124E8(event);

    req->work = work;
    req->kind = kind;
    switch (kind) {
    case 1:
    case 5:
    case 6:
        C_GEAR_StartRippleFlood(req->work);
        break;
    case 11:
        work->activeIcon = 4;
        break;
    case 7:
        work->activeIcon = 3;
        break;
    case 12:
        work->activeIcon = 8;
        break;
    case 13:
        work->activeIcon = 10;
        break;
    }
    return event;
}


int C_GEAR_PanelEventMain(struct GameEvent *event, int *seq, CGearEventWork *req)
{
    CGearWork *work;
    void *fieldMap;
    int done;
    struct GameEvent *next;
    CGearSubprocArgs *args;

    work = req->work;
    done = 0;
    fieldMap = ICA_ANIME_GetField20(work->gameSystem);
    switch (req->kind) {
    case 1:
    case 5:
    case 6:
        done = C_GEAR_StepRipple(req->work);
        break;
    case 7:
    case 11:
        done = C_GEAR_StepFadeIcon(req->work);
        break;
    case 12:
    case 13:
        done = C_GEAR_StepIconAnim(req->work);
        break;
    }
    if (done == 0)
        return 0;

    switch (req->kind) {
    case 6:
        next = GAME_EVENT_CreateOverlayEvent(work->gameSystem, (u32)abs_id_0, EVENT_GSYNC_Entry, fieldMap);
        break;
    case 1:
        next = IRC_BATTLE_ENTRY_Create(work->gameSystem, fieldMap, 0, 1);
        break;
    case 5:
        next = SCRCMD_NETWORK_CreateWifiProcEvent(work->gameSystem, fieldMap, 0, 1);
        break;
    case 11:
        next = EVENT_RESEARCH_RADAR_CreateTopTask(work->gameSystem, fieldMap);
        break;
    case 7:
        next = FIELD_COMM_ACTOR_CreateSubscreenChangeEvent(work->gameSystem, fieldMap, 4);
        break;
    case 12:
        args = GFL_HEAP_Alloc(4, 8, 1, d_021F3554, 0x14B7);
        args->playerData = (u8 *)GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C(work->gameSystem));
        args->gameSystem = work->gameSystem;
        next = FIELD_STATUS_CreateSubProcCallbackEvent(work->gameSystem, fieldMap, (u32)abs_id_124, d_021D4D40, args, 0, args);
        break;
    case 13:
        next = FIELD_SUBSCREEN_CreateAnimTask(work->gameSystem);
        break;
    }
    GAME_EVENT_ChangeEvent(event, next);
    return 0;
}

void C_GEAR_StartSelectedRipple(CGearWork *work)
{
    work->rippleKind = C_GEAR_GetCellKind(work, work->selectedCol, work->selectedRow);
    work->rippleStep = 0;
    C_GEAR_SpawnRippleActor(work, work->selectedCol, work->selectedRow);
}

/*
 * extent: trailing two-byte zero alignment padding.
 */
void C_GEAR_DeleteActorSlots(CGearWork *work)
{
    int i;
    for (i = 0; i < 20; i++) {
        if (work->actorSlots[i].actor) {
            CLACT_DeleteActor(work->actorSlots[i].actor);
            work->actorSlots[i].actor = 0;
        }
    }
}

int C_GEAR_AreActorSlotsIdle(CGearWork *work)
{
    int result = 1;
    int i;
    for (i = 0; i < 20; i++) {
        if (work->actorSlots[i].actor) {
            if (CLACT_IsActorAnimActive(work->actorSlots[i].actor)) {
                result = 0;
                break;
            }
        }
    }
    return result;
}

/*
 * interface: caller sets r2=0x1514 despite two-input thunk/leaf; retained
 * in the caller extern to reproduce original argument setup.
 */
void C_GEAR_StepWaitSlots(CGearWork *work)
{
    C_GEAR_RunFrame(work);
    if (C_GEAR_AreActorSlotsIdle(work)) {
        C_GEAR_DeleteActorSlots(work);
        C_GEAR_ChangeStep(work, C_GEAR_StepIdle, 0x1514);
    }
}


void C_GEAR_SetPowerState(CGearWork *work, int powerOn)
{
    if (GFL_NET_GetRunState() == 0 && work->commEnabled != 0)
        C_GEAR_ShowCommIndicator(work);
    else
        C_GEAR_HideCommIndicator(work);
    if (work->powerOn != powerOn) {
        if (powerOn == 0)
            C_GEAR_ShowOffIndicator(work);
        else
            C_GEAR_HideOffIndicator(work);
        work->powerOn = powerOn;
    }
}


/* Reads archive member (skinIndex + 0x19) into the buffer of the C-Gear save. */
void C_GEAR_LoadSkinMember(struct HexMap *hexMap, struct ArcFile *arc, int skinIndex, int heapId)
{
    void *skinBuffer = func_020091FC(hexMap);

    ARC_TOOL_ReadHandleMember(arc, skinIndex + 0x19, skinBuffer);
}
