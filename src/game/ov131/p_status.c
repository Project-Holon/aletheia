/*
 * file:     p_status.c
 * unit:     yes
 * function: P_STATUS_InitWork, P_STATUS_ExitWork, P_STATUS_MainSeq, P_STATUS_VBlankTask, P_STATUS_InitGraphics, P_STATUS_ExitGraphics, P_STATUS_InitBgLayer, P_STATUS_LoadObjResource, P_STATUS_DeleteObjResource, P_STATUS_CreateButtonActors, P_STATUS_DeleteButtonActors, P_STATUS_InitMessage, P_STATUS_ExitMessage, P_STATUS_UpdateTouch, P_STATUS_UpdateInput, P_STATUS_CheckKey, P_STATUS_CheckTouch, P_STATUS_UpdatePaletteAnime, P_STATUS_SetInputEnable, P_STATUS_ChangePokemon, P_STATUS_SearchPokemon, P_STATUS_LoadPokemonState, P_STATUS_RequestRefresh, P_STATUS_UpdateRefresh, P_STATUS_GetPokePara, P_STATUS_GetPokeParaSource, P_STATUS_SetFastMode, P_STATUS_PrintMsg, P_STATUS_PrintMsgToWin, P_STATUS_PrintWordSetMsg, P_STATUS_PrintWordSetMsgToWin, P_STATUS_PrintWordSetMsgRight, P_STATUS_PrintWordSetMsgRightToWin, P_STATUS_CanUseButtons, P_STATUS_HasRibbon, P_STATUS_ProcInit, P_STATUS_ProcExit, P_STATUS_ProcMain
 * address:  0x021D4240
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from p_sta_oam.c at 0x021D65D8 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   UI_GetInputMode 0x020355C4 arm
 *   POKE_TOOL_CreateFromBoxParam 0x0201747C thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   MIi_CpuCopy16 0x02082A60 arm
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   GAME_DATA_SetSaveFlag 0x02012BE0 thumb
 *   func_020355D8 0x020355D8 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   CLACT_DrawSystem 0x0204A600 arm
 *   MCSS_Main 0x02014C08 thumb
 *   func_02047964 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   MCSS_Draw 0x02014D2C thumb
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3X_SetEdgeColorTable 0x0207DCF8 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   BG_SYS_SetLowBit 0x0204044C arm
 *   MCSS_Init 0x02014B08 thumb
 *   MCSS_SetTextureTransAdrs 0x02016020 thumb
 *   MCSS_SetGlobalScale 0x020160C0 thumb
 *   _VramBankConfig 0x021DC0E4 data ov131
 *   _DispConfig 0x021DBFF4 data ov131
 *   _BgSetups 0x021DC004 data ov131
 *   ClactSysDefaultSetup 0x020A1448 data
 *   _CameraVecs 0x021DBFC0 data ov131
 *   _EdgeColorTable 0x021DBFE4 data ov131
 *   NNS_GfdResetVramTransferTaskQueue 0x02061C30 arm
 *   MCSS_Exit 0x02014BA8 thumb
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   _ButtonPlacement 0x021DBFA0 data ov131
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   PRINTSYS_QUE_CreateEx 0x0201C450 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   _TouchHitRects 0x021DC114 data a1
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   KEY_GetRepeat 0x0203633C arm
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   _CursorColorsFrom 0x021DBFA8 data a2
 *   _CursorColorsTo 0x021DBFB8 data a2
 *   FX_SinCosTable_ 0x020A1B38 data
 *   PM_VOICE_StopSlot 0x02006BB4 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   PM_VOICE_GetPerapVoiceSave 0x02006CAC thumb
 *   PM_VOICE_Play 0x02006984 thumb
 *   POKE_TOOL_GetBoxParamSize 0x020173E8 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   STRBUF_Create 0x020457B0 arm
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   KEY_GetCont 0x0203630C arm
 *   POKEPARTY_Create 0x0201A920 thumb
 *   POKEPARTY_InitEx 0x0201A954 thumb
 *   POKE_TOOL_Create 0x020173F0 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   POKEPARTY_Add 0x0201A98C thumb
 *   POKE_TOOL_ClearBoxParam 0x02017550 thumb
 *   GFL_USE_GetRandomBelow 0x02005728 thumb
 *   POKE_TOOL_SetupBoxParam 0x02017600 thumb
 *   POKE_TOOL_SetBoxValue 0x02017E64 thumb
 *   GAME_DATA_Create 0x020124F4 thumb
 *   _SourceFileName 0x021DC80C data a1
 *   _DebugMovesParty 0x021DC138 data a2
 *   _DebugMovesArray 0x021DC144 data a2
 *   GAME_DATA_Delete 0x02012704 thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   P_STA_SUB_Create 0x021D65D8 thumb ov131
 *   P_STA_SUB_Delete 0x021D6608 thumb ov131
 *   P_STA_SUB_Main 0x021D6614 thumb ov131
 *   P_STA_SUB_LoadArcGraphics 0x021D67EC thumb ov131
 *   P_STA_SUB_Exit 0x021D6808 thumb ov131
 *   P_STA_SUB_CreateObjects 0x021D6810 thumb ov131
 *   P_STA_SUB_DeleteObjects 0x021D694C thumb ov131
 *   P_STA_SUB_InitWindows 0x021D697C thumb ov131
 *   P_STA_SUB_Refresh 0x021D6A38 thumb ov131
 *   P_STA_SUB_FreeWindows 0x021D6CDC thumb ov131
 *   P_STA_SUB_HideSprite 0x021D6D04 thumb ov131
 *   P_STA_INFO_AllocWork 0x021D7B00 thumb ov131
 *   P_STA_INFO_FreeWork 0x021D7B34 thumb ov131
 *   P_STA_INFO_Main 0x021D7B48 thumb ov131
 *   P_STA_INFO_LoadResources 0x021D7B4C thumb ov131
 *   P_STA_INFO_FreeResources 0x021D7BF0 thumb ov131
 *   P_STA_INFO_Setup 0x021D7C38 thumb ov131
 *   P_STA_INFO_ShowPage 0x021D7CAC thumb ov131
 *   P_STA_INFO_DeleteWindows 0x021D7E84 thumb ov131
 *   P_STA_INFO_HidePage 0x021D7EAC thumb ov131
 *   P_STA_RIBBON_Create 0x021D87E0 thumb ov131
 *   P_STA_RIBBON_Delete 0x021D881C thumb ov131
 *   P_STA_RIBBON_Main 0x021D8830 thumb ov131
 *   P_STA_RIBBON_LoadArcGraphics 0x021D8884 thumb ov131
 *   P_STA_RIBBON_FreeArcGraphics 0x021D8904 thumb ov131
 *   P_STA_RIBBON_CreateObjects 0x021D8938 thumb ov131
 *   P_STA_RIBBON_DeleteObjects 0x021D89FC thumb ov131
 *   P_STA_RIBBON_Init 0x021D8F50 thumb ov131
 *   P_STA_RIBBON_Show 0x021D8FAC thumb ov131
 *   P_STA_RIBBON_Deactivate 0x021D909C thumb ov131
 *   P_STA_RIBBON_Hide 0x021D90C0 thumb ov131
 *   P_STA_RIBBON_CollectOwned 0x021D911C thumb ov131
 *   P_STA_RIBBON_Noop 0x021D91EC thumb ov131
 *   P_STA_SKILL_Create 0x021D96B0 thumb ov131
 *   P_STA_SKILL_Delete 0x021D9734 thumb ov131
 *   P_STA_SKILL_Main 0x021D9740 thumb ov131
 *   P_STA_SKILL_LoadArcGraphics 0x021D9980 thumb ov131
 *   P_STA_SKILL_Exit 0x021D9A04 thumb ov131
 *   P_STA_SKILL_CreateObjects 0x021D9A4C thumb ov131
 *   P_STA_SKILL_DeleteObjects 0x021D9BD4 thumb ov131
 *   P_STA_SKILL_InitStatsPage 0x021D9C3C thumb ov131
 *   P_STA_SKILL_ShowStatsPage 0x021D9CD0 thumb ov131
 *   P_STA_SKILL_FreeStatsPage 0x021D9D44 thumb ov131
 *   P_STA_SKILL_HideStatsPage 0x021D9D94 thumb ov131
 *   P_STA_SKILL_InitMovesPage 0x021DA6A4 thumb ov131
 *   P_STA_SKILL_ShowMovesPage 0x021DA7A4 thumb ov131
 *   P_STA_SKILL_FreeMovesPage 0x021DA84C thumb ov131
 *   P_STA_SKILL_HideMovesPage 0x021DA8BC thumb ov131
 *   P_STA_RIBBON_GetRibbonInfo 0x021DBF2C thumb ov131
 *   POKE_TOOL_ClearPartyParam  0x02017528  thumb  arm9
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb  arm9
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb  arm9
 *   APP_ICON_GetArchiveId  0x020275E4  thumb  arm9
 *   APP_ICON_GetTouchBarFileId  0x020275E8  thumb  arm9
 *   APP_ICON_GetTypeCellFileId  0x020275F8  thumb  arm9
 *   APP_ICON_GetTypePaletteFileId  0x020275FC  thumb  arm9
 *   APP_ICON_GetTypeAnimFileId  0x02027600  thumb  arm9
 *   APP_ICON_GetMoveKindAnimFileId  0x02027618  thumb  arm9
 *   APP_ICON_GetStatusCellFileId  0x0202761C  thumb  arm9
 *   APP_ICON_GetStatusPaletteFileId  0x02027620  thumb  arm9
 *   APP_ICON_GetStatusAnimFileId  0x02027624  thumb  arm9
 *   APP_ICON_GetStatusFrameFileId  0x02027628  thumb  arm9
 *   APP_ICON_GetStatusDataFileId  0x0202762C  thumb  arm9
 *   APP_ICON_GetSealCellFileId  0x020276B4  thumb  arm9
 *   APP_ICON_GetSealPaletteFileId  0x020276B8  thumb  arm9
 *   APP_ICON_GetSealAnimFileId  0x020276BC  thumb  arm9
 *   APP_ICON_GetSealFrameFileId  0x020276C0  thumb  arm9
 *   APP_ICON_GetBallThrowCellFileId  0x02027720  thumb  arm9
 *   APP_ICON_GetBallThrowAnimFileId  0x0202772C  thumb  arm9
 *   APP_ICON_GetBallOpenCellFileId  0x02027738  thumb  arm9
 *   APP_ICON_GetBallOpenPaletteFileId  0x02027740  thumb  arm9
 *   APP_ICON_GetBallOpenAnimFileId  0x02027748  thumb  arm9
 *   APP_ICON_GetEffectCellFileId  0x0202774C  thumb  arm9
 *   APP_ICON_GetEffectPaletteFileId  0x02027750  thumb  arm9
 *   APP_ICON_GetEffectAnimFileId  0x02027754  thumb  arm9
 *   APP_ICON_GetGearDataFileId  0x02027768  thumb  arm9
 *   APP_ICON_GetGearExtraFileId  0x0202776C  thumb  arm9
 *   APP_ICON_GetGearFrameFileId  0x02027770  thumb  arm9
 *   APP_ICON_GetGearAnim2FileId  0x02027774  thumb  arm9
 *   POKE_TOOL_Dummy  0x020185F0  thumb  arm9
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb  arm9
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb  arm9
 *   GF_FONT_MeasureWidestLine  0x0201D304  thumb  arm9
 */

#include "p_status_types.h"

struct Mon;
struct Tcb;
struct ClactObj;
struct McssSys;
struct PrintSys;
struct DispVram;
struct DispConfig;
struct ClactUnit;
struct Camera;
struct BgTemplate;
struct GfFont;
struct MsgBank;
struct PokePara;
struct StrBuf;
struct BmpWin;
struct WordSet;
struct StrObj;
struct HeapSys;
struct Party;
struct PartyMon;
struct SaveData;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
typedef signed char s8;
typedef unsigned long long u64;

/* One background layer setup (_BgSetups), passed on as struct BgTemplate. */
struct BgSetup { u32 data[8]; };

/* Cell actor system setup (ClactSysDefaultSetup); P_STATUS_InitGraphics changes limits[0]. */
struct ClactSysSetup { u32 setup[4]; u16 limits[6]; };

/* Camera position, target and up vector (_CameraVecs). */
struct Vec3 { u32 x, y, z; };

typedef enum {GX_DISP_SELECT_SUB_MAIN=0, GX_DISP_SELECT_MAIN_SUB=1} GXDispSelect;

/* One byte per button actor (_ButtonPlacement rows: x position, unused row, animation). */
struct ButtonBytes { u8 v[8]; };

/* Sub screen background palette 14: colors 9 and 10 are the text colors. */
typedef struct { u16 otherColors[9]; u16 fontColor, shadowColor; } TextPalette;

/* Touch areas of the eight buttons plus the end mark (_TouchHitRects). */
struct TpHitTable { unsigned char rect[36]; };

/* Four cursor colors (_CursorColorsFrom, _CursorColorsTo: the two ends of the blink). */
struct CursorColors { u16 color[4]; };

/* Moves given to the debug Pokemon (_DebugMovesParty, _DebugMovesArray). */
typedef struct { u16 move[5]; } DebugMoves;

/* Hardware registers (main engine A, sub engine B) and palette RAM. */
#define HW_REG_DISPCNT 0x04000000
#define HW_REG_BG3CNT 0x0400000c
#define HW_REG_MOSAIC 0x0400004c
#define HW_REG_BLDCNT 0x04000050
#define HW_REG_DISP3DCNT 0x04000060
#define HW_REG_POWCNT1 0x04000304
#define HW_REG_DISPCNT_SUB 0x04001000
#define HW_REG_BG2CNT_SUB 0x0400100a
#define HW_REG_BG3CNT_SUB 0x0400100c
#define HW_REG_MOSAIC_SUB 0x0400104c
#define HW_REG_BLDCNT_SUB 0x04001050
#define HW_PLTT_MAIN_OBJ 0x05000200
#define HW_PLTT_SUB_BG 0x05000400
#define HW_VBLANK_COUNT_BUF 0x02FFFC3C
static inline u32 OS_GetVBlankCount(void) { return *(volatile u32 *)HW_VBLANK_COUNT_BUF; }

extern u8 UI_GetInputMode(void);
extern void *POKE_TOOL_CreateFromBoxParam(struct Mon *p, u32 heap);
extern void *GFL_USE_AddMainTask(u32,u32,u32);
extern void MIi_CpuCopy16(const void *,void *,u32);
extern int GAME_DATA_CheckSaveFlag(int a0, int a1);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern void TCB_DeleteTask(struct Tcb *n);
extern void GAME_DATA_SetSaveFlag(void *p, u32 a, u32 b);
extern void func_020355D8(u8);
extern u32 GFL_HEAP_Free(void *p);
extern u32 TOUCHPANEL_GetPointCont(u32 *,u32 *);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 CLACT_IsActorAnimActive(struct ClactObj *a);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void CLACT_DrawSystem(void);
extern void MCSS_Main(char *);
extern void func_02047964(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void MCSS_Draw(struct McssSys *sys);
extern void G3D_SYSTEM_DrawEnd(void);
extern void BG_SYS_ResetSlot(u32,u32,u32);
extern void CLACT_SetActorAnimSeq(struct ClactObj *p, u16 value);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32,u32);
extern u32 WIPE_ResetWndMask(void *);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void BG_SYS_Create(u16),BMP_WIN_Init(u16);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void BG_SYS_SetPlaneVisible(unsigned int which, unsigned char enable);
extern void G2x_SetBlendAlpha_(u32 *,u32,u32,u32,u32);
extern void CLACT_InitSystem(const struct ClactSysSetup *cfg, u32 arg, u32 heapId);
extern struct ClactUnit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct ClactUnit *bank);
extern void BG_SYS_SetMainPlaneVisible(u32,u32),BG_SYS_SetSubPlaneVisible(u32,u32);
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u16,void (*)(void));
extern u32 *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,struct Vec3 *,struct Vec3 *,struct Vec3 *,u16);
extern void G3D_CAMERA_Reset(struct Camera *l);
extern void G3X_SetEdgeColorTable(const void *);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32,u32),BG_SYS_SetLowBit(u32);
extern void *MCSS_Init(u32,void *);
extern void MCSS_SetTextureTransAdrs(void *,u32);
extern void MCSS_SetGlobalScale(char *p, unsigned int v);
extern void NNS_GfdResetVramTransferTaskQueue(void);
extern void MCSS_Exit(u8 *a0);
extern unsigned int G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
extern u32 CLACT_DeleteUnit(struct ClactUnit *bank);
extern void CLACT_ExitSystem(void);
extern void BG_SYS_FreeLayerBuf(unsigned int);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u32);
extern void BG_SYS_PushTile(u32);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *,u32,u32,u32,u32,u16);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *,u32,u32,u32,u32,u32,u16);
extern int CLACT_RegisterPaletteEx(void *,u32,u32,u32,u16,u16,u16);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetTouchBarFileId(void);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern u32 APP_ICON_GetTypePaletteFileId(u32);
extern u32 APP_ICON_GetTypeAnimFileId(u32);
extern u32 APP_ICON_GetTypeCellFileId(u32);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern u32 APP_ICON_GetStatusCellFileId(u32);
extern u32 APP_ICON_GetStatusPaletteFileId(u32);
extern int APP_ICON_GetGearDataFileId(void);
extern int APP_ICON_GetGearExtraFileId(int);
extern int APP_ICON_GetGearFrameFileId(int);
extern int APP_ICON_GetGearAnim2FileId(int);
extern u32 APP_ICON_GetSealCellFileId(void);
extern u32 APP_ICON_GetSealPaletteFileId(void);
extern u32 APP_ICON_GetSealAnimFileId(u32);
extern u32 APP_ICON_GetSealFrameFileId(u32);
extern int APP_ICON_GetBallThrowCellFileId(int);
extern int APP_ICON_GetBallThrowAnimFileId(int);
extern int APP_ICON_GetBallOpenCellFileId(int,int);
extern int APP_ICON_GetBallOpenPaletteFileId(int,int);
extern int APP_ICON_GetBallOpenAnimFileId(void);
extern int APP_ICON_GetEffectCellFileId(int);
extern int APP_ICON_GetEffectPaletteFileId(int);
extern int APP_ICON_GetEffectAnimFileId(int);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern struct ClactObj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void CLACT_SetActorAutoAnim(struct ClactObj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct ClactObj *p, u32 v);
extern void CLACT_DeleteActor(struct ClactObj *p);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32,u32,u32,u32,u32,u16);
extern void *PRINTSYS_QUE_CreateEx(u16,u32);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern unsigned int MSGDATA_Delete(struct MsgBank *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern int TOUCHPANEL_HitTrg(const void *key);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern unsigned int KEY_GetRepeat(void);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32 size);
extern void POKE_TOOL_ClearPartyParam(struct PokePara *p);
extern u32 POKE_TOOL_GetBoxValue(void *p, int id, void *v);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void PM_VOICE_StopSlot(u32);
extern void PM_VOICE_GetPerapVoiceSave(void **);
extern u32 PM_VOICE_Play(u32,u32,u32,u32,u32,u32,u32,u32);
extern void *POKE_TOOL_Dummy(void *);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetBoxParamSize(void);
extern u32 POKE_TOOL_DecodePartyParam(struct PokePara *p);
extern u32 POKE_TOOL_EncodePartyParam(struct PokePara *p, u32 f);
extern u32 POKE_TOOL_DecodeBoxParam(struct PokePara *p);
extern u32 POKE_TOOL_EncodeBoxParam(struct PokePara *p, u32 f);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct StrBuf *vec);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *BMP_WIN_GetBmp(struct BmpWin *p);
extern struct StrBuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern u32 GF_FONT_MeasureWidestLine(struct StrObj *s, u32 a, u32 b);
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
extern void *PROCSYS_AllocProcWork(struct HeapSys *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,int);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 KEY_GetCont(void);
extern struct Party *POKEPARTY_Create(u32 heap);
extern void POKEPARTY_InitEx(struct Party *p, s32 capacity);
extern void *POKE_TOOL_Create(u16,u16,u32,u32,u32);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern void POKE_TOOL_ClearBoxParam(struct PokePara *p);
extern u32 GFL_USE_GetRandomBelow(u32 range);
extern void POKE_TOOL_SetupBoxParam(void *obj,u16 species,u16 level,u64 id);
extern void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);
extern void *GAME_DATA_Create(u16);
extern void GAME_DATA_Delete(u8 *p);
extern void PROCSYS_FreeProcWork(struct SaveData *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
int P_STATUS_InitWork(PStatusWork *wk);
int P_STATUS_ExitWork(PStatusWork *wk);
int P_STATUS_MainSeq(PStatusWork *wk);
void P_STATUS_VBlankTask(void);
void P_STATUS_InitGraphics(PStatusWork *wk);
void P_STATUS_ExitGraphics(PStatusWork *wk);
void P_STATUS_InitBgLayer(struct BgSetup *cfg,u32 bg,u32 mode);
void P_STATUS_LoadObjResource(PStatusWork *wk);
void P_STATUS_DeleteObjResource(PStatusWork *wk);
void P_STATUS_CreateButtonActors(PStatusWork *wk);
void P_STATUS_DeleteButtonActors(PStatusWork *wk);
void P_STATUS_InitMessage(PStatusWork *wk);
void P_STATUS_ExitMessage(PStatusWork *wk);
void P_STATUS_UpdateTouch(PStatusWork *wk);
void P_STATUS_UpdateInput(PStatusWork *wk);
int P_STATUS_CheckKey(PStatusWork *wk);
void P_STATUS_CheckTouch(PStatusWork *wk);
s32 P_STATUS_UpdatePaletteAnime(PStatusWork *wk);
void P_STATUS_SetInputEnable(PStatusWork *wk,int enable);
int P_STATUS_ChangePokemon(PStatusWork *wk,int direction);
int P_STATUS_SearchPokemon(PStatusWork *wk,int direction,unsigned short *out);
void P_STATUS_LoadPokemonState(PStatusWork *wk);
void P_STATUS_RequestRefresh(PStatusWork *wk);
void P_STATUS_UpdateRefresh(PStatusWork *wk);
void *P_STATUS_GetPokePara(PStatusWork *wk);
int P_STATUS_GetPokeParaSource(PStatusWork *wk);
void P_STATUS_SetFastMode(PStatusWork *wk,int fastMode);
void P_STATUS_PrintMsg(PStatusWork *wk,int bmpWin,int msgId,int x,unsigned short y,unsigned short color);
void P_STATUS_PrintMsgToWin(PStatusWork *wk,unsigned int bmpWinData,int msgId,int x,unsigned short y,unsigned short color);
void P_STATUS_PrintWordSetMsg(PStatusWork *wk,int bmpWin,void *wordSet,int msgId,unsigned short x,unsigned short y,unsigned short color);
void P_STATUS_PrintWordSetMsgToWin(PStatusWork *wk,unsigned int bmpWinData,void *wordSet,int msgId,unsigned short x,unsigned short y,unsigned short color);
void P_STATUS_PrintWordSetMsgRight(PStatusWork *wk,int bmpWin,void *wordSet,int msgId,unsigned short x,unsigned short y,unsigned short color);
void P_STATUS_PrintWordSetMsgRightToWin(PStatusWork *wk,unsigned int bmpWinData,void *wordSet,int msgId,unsigned short x,unsigned short y,unsigned short color);
int P_STATUS_CanUseButtons(PStatusWork *wk);
int P_STATUS_HasRibbon(PStatusWork *wk, void *pp);
int P_STATUS_ProcInit(void *proc,int *seq,PStatusParam *pwk,PStatusWork *mywk);
int P_STATUS_ProcExit(void *proc, int *seq, PStatusParam *pwk, PStatusWork *mywk);
int P_STATUS_ProcMain(void *proc, int *seq, PStatusParam *pwk, PStatusWork *mywk);
PStaSubWork *P_STA_SUB_Create(PStatusWork *wk);
void P_STA_SUB_Delete(PStatusWork *wk, PStaSubWork *pageWork);
void P_STA_SUB_Main(PStatusWork *wk, PStaSubWork *pageWork);
void P_STA_SUB_LoadArcGraphics(PStatusWork *wk, PStaSubWork *pageWork, void *arc);
void P_STA_SUB_Exit(PStatusWork *wk, PStaSubWork *pageWork);
void P_STA_SUB_CreateObjects(PStatusWork *wk, PStaSubWork *pageWork);
void P_STA_SUB_DeleteObjects(PStatusWork *wk, PStaSubWork *pageWork);
void P_STA_SUB_InitWindows(PStatusWork *wk, PStaSubWork *pageWork);
void P_STA_SUB_Refresh(PStatusWork *wk, PStaSubWork *pageWork);
void P_STA_SUB_FreeWindows(PStatusWork *wk, PStaSubWork *pageWork);
void P_STA_SUB_HideSprite(PStatusWork *wk, PStaSubWork *pageWork);
PStaInfoWork *P_STA_INFO_AllocWork(PStatusWork *wk);
void P_STA_INFO_FreeWork(PStatusWork *wk, PStaInfoWork *pageWork);
void P_STA_INFO_Main(PStatusWork *wk, PStaInfoWork *pageWork);
void P_STA_INFO_LoadResources(PStatusWork *wk, PStaInfoWork *pageWork, void *arc);
void P_STA_INFO_FreeResources(PStatusWork *wk, PStaInfoWork *pageWork);
void P_STA_INFO_Setup(PStatusWork *wk, PStaInfoWork *pageWork);
void P_STA_INFO_ShowPage(PStatusWork *wk, PStaInfoWork *pageWork);
void P_STA_INFO_DeleteWindows(PStatusWork *wk, PStaInfoWork *pageWork);
void P_STA_INFO_HidePage(PStatusWork *wk, PStaInfoWork *pageWork);
PStaRibbonWork *P_STA_RIBBON_Create(PStatusWork *wk);
void P_STA_RIBBON_Delete(PStatusWork *wk, PStaRibbonWork *pageWork);
void P_STA_RIBBON_Main(PStatusWork *wk, PStaRibbonWork *pageWork);
void P_STA_RIBBON_LoadArcGraphics(PStatusWork *wk, PStaRibbonWork *pageWork, void *arc);
void P_STA_RIBBON_FreeArcGraphics(PStatusWork *wk, PStaRibbonWork *pageWork);
void P_STA_RIBBON_CreateObjects(PStatusWork *wk, PStaRibbonWork *pageWork);
void P_STA_RIBBON_DeleteObjects(PStatusWork *wk, PStaRibbonWork *pageWork);
void P_STA_RIBBON_Init(PStatusWork *wk, PStaRibbonWork *pageWork);
void P_STA_RIBBON_Show(PStatusWork *wk, PStaRibbonWork *pageWork);
void P_STA_RIBBON_Deactivate(PStatusWork *wk, PStaRibbonWork *pageWork);
void P_STA_RIBBON_Hide(PStatusWork *wk, PStaRibbonWork *pageWork);
void P_STA_RIBBON_CollectOwned(PStatusWork *wk, PStaRibbonWork *pageWork);
void P_STA_RIBBON_Noop(PStatusWork *wk, PStaRibbonWork *pageWork);
PStaSkillWork *P_STA_SKILL_Create(PStatusWork *wk);
void P_STA_SKILL_Delete(PStatusWork *wk, PStaSkillWork *pageWork);
void P_STA_SKILL_Main(PStatusWork *wk, PStaSkillWork *pageWork);
void P_STA_SKILL_LoadArcGraphics(PStatusWork *wk, PStaSkillWork *pageWork, void *arc);
void P_STA_SKILL_Exit(PStatusWork *wk, PStaSkillWork *pageWork);
void P_STA_SKILL_CreateObjects(PStatusWork *wk, PStaSkillWork *pageWork);
void P_STA_SKILL_DeleteObjects(PStatusWork *wk, PStaSkillWork *pageWork);
void P_STA_SKILL_InitStatsPage(PStatusWork *wk, PStaSkillWork *pageWork);
void P_STA_SKILL_ShowStatsPage(PStatusWork *wk, PStaSkillWork *pageWork);
void P_STA_SKILL_FreeStatsPage(PStatusWork *wk, PStaSkillWork *pageWork);
void P_STA_SKILL_HideStatsPage(PStatusWork *wk, PStaSkillWork *pageWork);
void P_STA_SKILL_InitMovesPage(PStatusWork *wk, PStaSkillWork *pageWork);
void P_STA_SKILL_ShowMovesPage(PStatusWork *wk, PStaSkillWork *pageWork);
void P_STA_SKILL_FreeMovesPage(PStatusWork *wk, PStaSkillWork *pageWork);
void P_STA_SKILL_HideMovesPage(PStatusWork *wk, PStaSkillWork *pageWork);
u32 P_STA_RIBBON_GetRibbonInfo(u32 ribbonNo, u32 field);
extern const struct DispVram _VramBankConfig;
extern struct DispConfig _DispConfig;
extern struct BgSetup _BgSetups[7];
extern struct ClactSysSetup ClactSysDefaultSetup;
extern struct Vec3 _CameraVecs[3];
extern u16 _EdgeColorTable[8];
extern struct ButtonBytes _ButtonPlacement[3];
extern const struct TpHitTable _TouchHitRects;
extern const struct CursorColors _CursorColorsFrom;
extern const struct CursorColors _CursorColorsTo;
extern const s16 FX_SinCosTable_[];
extern const char _SourceFileName[];
extern const DebugMoves _DebugMovesParty;
extern const DebugMoves _DebugMovesArray;












int P_STATUS_InitWork(PStatusWork *wk)
{
    u8 i;
    wk->pos=wk->param->pos;
    wk->dispPos=255;
    wk->vblankCount=0;
    wk->lastTick=OS_GetVBlankCount();
    wk->dispPage=4;
    wk->isInputEnabled=1;
    wk->prevButtonAnim=0;
    wk->nextButtonAnim=0;
    wk->retCode=0;
    wk->refreshReq=1;
    wk->mosaicSeq=0;
    wk->mosaicLevel=0;
    wk->seq=0;
    wk->pushedButton = (void *)0;
    wk->playCryReq=0;
    wk->restoreModeAll=0;
    wk->inputType=UI_GetInputMode();
    if (wk->param->mode==3) {
        wk->param->mode=2;
        wk->restoreModeAll=1;
    }
    if (wk->param->ppt==2) wk->tempPP=POKE_TOOL_CreateFromBoxParam(P_STATUS_GetPokePara(wk),wk->heapId);
    else wk->tempPP=0;
    P_STATUS_InitGraphics(wk);
    wk->subWork=P_STA_SUB_Create(wk);
    wk->infoWork=P_STA_INFO_AllocWork(wk);
    wk->skillWork=P_STA_SKILL_Create(wk);
    wk->ribbonWork=P_STA_RIBBON_Create(wk);
    P_STATUS_LoadObjResource(wk);
    P_STATUS_InitMessage(wk);
    P_STATUS_CreateButtonActors(wk);
    wk->vblankTask=GFL_USE_AddMainTask((u32)P_STATUS_VBlankTask,(u32)wk,8);
    wk->blinkAngle=0;
    MIi_CpuCopy16((void *)(HW_PLTT_MAIN_OBJ + 0x6c),wk->savedCursorPal,12);
    MIi_CpuCopy16((void *)(HW_PLTT_MAIN_OBJ + 0x160),wk->glowPalBase,64);
    MIi_CpuCopy16((void *)(HW_PLTT_MAIN_OBJ + 0x1a0),wk->markPal,32);
    MIi_CpuCopy16((void *)(HW_PLTT_MAIN_OBJ + 0x1a0),wk->markPalBase,32);
    P_STATUS_LoadPokemonState(wk);
    if (wk->param->mode==2) {
        wk->page=3;
        P_STA_SUB_InitWindows(wk,wk->subWork);
        P_STA_SKILL_InitMovesPage(wk,wk->skillWork);
        P_STA_RIBBON_CollectOwned(wk,wk->ribbonWork);
    } else {
        wk->page=wk->param->page;
        if (wk->page<3) {
            for(i=0;i<3;i++) wk->pageToggle[i]=GAME_DATA_CheckSaveFlag((int)(wk->param->config),i+7);
        }
        P_STA_SUB_InitWindows(wk,wk->subWork);
        P_STA_RIBBON_CollectOwned(wk,wk->ribbonWork);
        switch (wk->page) {
        case 0: P_STA_INFO_Setup(wk,wk->infoWork); break;
        case 1: P_STA_SKILL_InitStatsPage(wk,wk->skillWork); break;
        case 2: P_STA_RIBBON_Init(wk,wk->ribbonWork); break;
        default: wk->page=0;
            P_STA_INFO_Setup(wk,wk->infoWork); break;
        }
    }
    GFL_NET_RestartWithDefaultTimeout(1,wk->heapId);
    return 1;
}












/*
 * extent: Two zero alignment bytes at 0x021D44C6.
 */
int P_STATUS_ExitWork(PStatusWork *wk)
{
    u8 i;
    TCB_DeleteTask(wk->vblankTask);
    wk->param->pos=wk->pos;
    P_STATUS_DeleteButtonActors(wk);
    P_STATUS_ExitMessage(wk);
    P_STATUS_DeleteObjResource(wk);
    P_STA_RIBBON_Noop(wk,wk->ribbonWork);
    P_STA_RIBBON_Delete(wk,wk->ribbonWork);
    P_STA_SKILL_Delete(wk,wk->skillWork);
    P_STA_INFO_FreeWork(wk,wk->infoWork);
    P_STA_SUB_Delete(wk,wk->subWork);
    P_STATUS_ExitGraphics(wk);
    if(wk->page<3){
        for(i=0;i<3;i++) GAME_DATA_SetSaveFlag(wk->param->config,i+7,wk->pageToggle[i]);
    }
    if(wk->restoreModeAll==1){
        wk->param->mode=3;
        wk->restoreModeAll=0;
    }
    func_020355D8(wk->inputType);
    if(wk->tempPP) GFL_HEAP_Free(wk->tempPP);
    return 1;
}












/*
 * interface: 02035CB8 writes fields only on success; their previous values
 *   remain initialized on failure. 021D5BAC guards a null output pointer.
 *   Tick difference is unsigned full-word arithmetic then byte truncation.
 *   Follower 021D46E4 is the complete eight-byte no-argument tail stub
 *   to owner 0204A648 (void(void)), with no return consumed.
 */
int P_STATUS_MainSeq(PStatusWork *wk)
{
    u32 tick;
    wk->prevTpX=wk->tpX;
    wk->prevTpY=wk->tpY;
    TOUCHPANEL_GetPointCont(&wk->tpX,&wk->tpY);
    switch (wk->seq) {
    case 0:
        if (wk->refreshReq==1) P_STATUS_UpdateRefresh(wk);
        else {
            WIPE_SYS_Start(0,1,1,0,6,1,wk->heapId);
            wk->seq=1;
        }
        break;
    case 1:
        if (WIPE_SYS_EndCheck()==1) wk->seq=4;
        break;
    case 2:
        if (wk->pushedButton==0 || CLACT_IsActorAnimActive(wk->pushedButton)==0 || wk->param->forceExit==1) {
            WIPE_SYS_Start(0,0,0,0,6,1,wk->heapId);
            wk->seq=3;
        }
        break;
    case 3:
        if (WIPE_SYS_EndCheck()==1) return wk->retCode;
        break;
    case 4:
        P_STATUS_UpdateTouch(wk);
        if (wk->refreshReq==1) P_STATUS_UpdateRefresh(wk);
        else {
            P_STA_SUB_Main(wk,wk->subWork);
            if (wk->param->forceExit==1) {
                wk->retCode=1;
                wk->seq=2;
            }
            P_STATUS_UpdateInput(wk);
            if (wk->refreshReq==0) {
                switch (wk->dispPage) {
                case 0: P_STA_INFO_Main(wk,wk->infoWork); break;
                case 1:
                case 3: P_STA_SKILL_Main(wk,wk->skillWork); break;
                case 2: P_STA_RIBBON_Main(wk,wk->ribbonWork); break;
                }
            }
        }
        break;
    }
    PRINTSYS_QUE_Main(wk->printQue);
    CLACT_DrawSystem();
    MCSS_Main((char *)wk->mcssSys);
    func_02047964();
    G3D_SYSTEM_ApplyLookAt();
    MCSS_Draw(wk->mcssSys);
    G3D_SYSTEM_DrawEnd();
    tick=OS_GetVBlankCount();
    wk->vblankCount+=(u8)(tick-wk->lastTick);
    wk->lastTick=tick;
    while (wk->vblankCount>=4) {
        BG_SYS_ResetSlot(3,1,1);
        BG_SYS_ResetSlot(3,4,1);
        BG_SYS_ResetSlot(7,1,1);
        BG_SYS_ResetSlot(7,4,1);
        wk->vblankCount-=4;
    }
    if (wk->prevButtonAnim==1 && CLACT_IsActorAnimActive(wk->buttonActor[4])==0) {
        if (P_STATUS_SearchPokemon(wk,0,0)==1) CLACT_SetActorAnimSeq(wk->buttonActor[4],3);
        else CLACT_SetActorAnimSeq(wk->buttonActor[4],17);
        wk->prevButtonAnim=0;
    }
    if (wk->nextButtonAnim==1 && CLACT_IsActorAnimActive(wk->buttonActor[5])==0) {
        if (P_STATUS_SearchPokemon(wk,1,0)==1) CLACT_SetActorAnimSeq(wk->buttonActor[5],2);
        else CLACT_SetActorAnimSeq(wk->buttonActor[5],16);
        wk->nextButtonAnim=0;
    }
    P_STATUS_UpdatePaletteAnime(wk);
    return 0;
}












void P_STATUS_VBlankTask(void) { CLACT_VBlankSystem(); }












static inline void GX_SetVisiblePlane(int plane)
{ *(volatile u32 *)HW_REG_DISPCNT=(u32)((*(volatile u32 *)HW_REG_DISPCNT & ~0x1f00) | (plane<<8)); }












static inline void GXS_SetVisiblePlane(int plane)
{ *(volatile u32 *)HW_REG_DISPCNT_SUB=(u32)((*(volatile u32 *)HW_REG_DISPCNT_SUB & ~0x1f00) | (plane<<8)); }












static inline void GX_SetDispSelect(GXDispSelect sel)
{ *(volatile u16 *)HW_REG_POWCNT1=(u16)((*(volatile u16 *)HW_REG_POWCNT1 & ~0x8000) | (sel<<15)); }












/*
 * interface: complete original 020160C0 bytes 41 64 70 47 store r1 at
 *   r0+0x44 and return. Caller supplies object and full word 0x10000.
 *   02046440 owner's s16 heap is u16 here: original ldrh zero-extends its
 *   outgoing stack word. Lower 16-bit callee conversion remains unchanged.
 *   Config c initializes all 28 bytes before h[0] and consumer reads.
 * lever: game hardware writes use vendor visible-plane and enum display
 *   selection inlines; raw compound assignments change constant sharing.
 * witness: 020160C0 filed as src/matched/arm9/MCSS_SetGlobalScale.c.
 * volatile: hardware DISPCNT/BLDCNT/POWCNT1/DISP3DCNT registers
 */
void P_STATUS_InitGraphics(PStatusWork *wk)
{
    struct ClactSysSetup setup;
    BG_SYS_ClearMainPlanes();BG_SYS_ClearSubPlanes();
    GX_SetVisiblePlane(0);GXS_SetVisiblePlane(0);
    WIPE_SetBrightnessFadeOut(0,0);WIPE_SetBrightnessFadeOut(1,0);
    WIPE_ResetWndMask(0);WIPE_ResetWndMask((void *)1);
    *(volatile u16 *)HW_REG_BLDCNT=0;
    *(volatile u16 *)HW_REG_BLDCNT_SUB=0;
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    BG_SYS_SetVramBanks(&_VramBankConfig);
    BG_SYS_Create(wk->heapId);BMP_WIN_Init(wk->heapId);
    BG_SYS_SetGraphicsMode(&_DispConfig);
    P_STATUS_InitBgLayer(&_BgSetups[6],1,0);P_STATUS_InitBgLayer(&_BgSetups[4],2,0);P_STATUS_InitBgLayer(&_BgSetups[0],3,0);
    BG_SYS_SetPlaneVisible(0,1);
    P_STATUS_InitBgLayer(&_BgSetups[1],4,0);P_STATUS_InitBgLayer(&_BgSetups[2],5,0);P_STATUS_InitBgLayer(&_BgSetups[3],6,0);P_STATUS_InitBgLayer(&_BgSetups[5],7,0);
    G2x_SetBlendAlpha_((u32 *)HW_REG_BLDCNT,4,30,13,16);
    G2x_SetBlendAlpha_((u32 *)HW_REG_BLDCNT_SUB,4,8,13,16);
    setup=ClactSysDefaultSetup;setup.limits[0]=110;
    CLACT_InitSystem(&setup,(u32)(&_VramBankConfig),wk->heapId);
    wk->clunit=CLACT_CreateUnit(96,0,wk->heapId);
    CLACT_SetUnitDefaultRenderer(wk->clunit);
    BG_SYS_SetMainPlaneVisible(16,1);BG_SYS_SetSubPlaneVisible(16,1);
    G3D_SYSTEM_Init(0,2,0,1,0,wk->heapId,0);
    wk->camera=G3D_CAMERA_Create(2,0xc0000,0,0,0x100000,0x80000,0x200000,0,&_CameraVecs[0],&_CameraVecs[2],&_CameraVecs[1],wk->heapId);
    G3D_CAMERA_Reset(wk->camera);
    G3X_SetEdgeColorTable(_EdgeColorTable);
    *(volatile u16 *)HW_REG_DISP3DCNT &= ~0x3020;
    G3D_SYSTEM_SetSwapBuffersMode(0,0);BG_SYS_SetLowBit(0);
    wk->mcssSys=MCSS_Init(2,(void *)wk->heapId);
    MCSS_SetTextureTransAdrs(wk->mcssSys,0);
    MCSS_SetGlobalScale(wk->mcssSys,0x10000);
}
















/*
 * 2026-10-02 R3: closed by the arm9 witness src/matched/arm9/NNS_GfdResetVramTransferTaskQueue.c
 *   (the tail-call stub matches under ../2.0/sp2; see its header).
 * extent: Two zero padding bytes at 0x021D493E.
 */
void P_STATUS_ExitGraphics(PStatusWork *wk)
{
    NNS_GfdResetVramTransferTaskQueue();
    MCSS_Exit(wk->mcssSys);
    G3D_CAMERA_Delete(wk->camera);
    G3D_SYSTEM_Exit();
    CLACT_DeleteUnit(wk->clunit);
    CLACT_ExitSystem();
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BMP_WIN_Exit();
    BG_SYS_Delete();
}
















void P_STATUS_InitBgLayer(struct BgSetup *cfg,u32 bg,u32 mode)
{
    BG_SYS_InitBgLayer(bg,(const struct BgTemplate *)cfg,mode);
    BG_SYS_SetPlaneVisible(bg,1);
    BG_SYS_FreeSlot(bg);
    BG_SYS_PushTile(bg);
}
















/*
 * following: 0x021D4F22 is two bytes of alignment padding before P_STATUS_DeleteObjResource.
 * lever: the loop store associates (p+i*4)+0x130; the second constructor result after APP_ICON_GetGearFrameFileId/74 is stored at +0x120.
 * initialization: resource handles come from the original constructors; no uninitialized local or added success assumption. The u8 counter visits 0..16.
 */
void P_STATUS_LoadObjResource(PStatusWork *wk)
{
    u32 cellArcId, anmArcId;
    void *statusArc;
    void *commonArc;
    u8 i;
    statusArc=ARC_TOOL_CreateHandle(78,wk->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(statusArc,0,0,0,0,wk->heapId);
    ARC_UTIL_UploadBgCharFromHandle(statusArc,8,2,0,0,0,wk->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(statusArc,70,3,0,0,0,wk->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(statusArc,1,4,0,0,wk->heapId);
    ARC_UTIL_UploadBgCharFromHandle(statusArc,10,6,0,0,0,wk->heapId);
    ARC_UTIL_UploadBgCharFromHandle(statusArc,9,5,0,0,0,wk->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(statusArc,71,7,0,0,0,wk->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(statusArc,65,5,0,0,0,wk->heapId);
    wk->objRes[PSTATUS_RES_PLTT_START + 0]=CLACT_RegisterPaletteEx(statusArc,3,0,0,0,4,wk->heapId);
    wk->objRes[PSTATUS_RES_PLTT_START + 6]=CLACT_RegisterPaletteEx(statusArc,5,0,0x160,0,2,wk->heapId);
    wk->objRes[PSTATUS_RES_PLTT_START + 7]=CLACT_RegisterPaletteEx(statusArc,6,1,0,0,5,wk->heapId);
    wk->objRes[PSTATUS_RES_PLTT_START + 8]=CLACT_RegisterPaletteEx(statusArc,4,0,0x1a0,0,1,wk->heapId);
    wk->objRes[PSTATUS_RES_PLTT_START + 11]=CLACT_RegisterPaletteEx(statusArc,2,0,0x1c0,0,1,wk->heapId);
    wk->objRes[PSTATUS_RES_CHR_START + 0]=CLACT_RegisterCharacter(statusArc,11,0,0,wk->heapId);
    wk->objRes[PSTATUS_RES_CHR_START + 8]=CLACT_RegisterCharacter(statusArc,15,0,0,wk->heapId);
    wk->objRes[PSTATUS_RES_CHR_START + 9]=CLACT_RegisterCharacter(statusArc,14,0,0,wk->heapId);
    wk->objRes[PSTATUS_RES_CHR_START + 12]=CLACT_RegisterCharacter(statusArc,13,0,0,wk->heapId);
    wk->objRes[PSTATUS_RES_CELL_START + 0]=CLACT_RegisterCellAnim(statusArc,78,129,wk->heapId);
    wk->objRes[PSTATUS_RES_CELL_START + 7]=CLACT_RegisterCellAnim(statusArc,81,132,wk->heapId);
    wk->objRes[PSTATUS_RES_CELL_START + 8]=CLACT_RegisterCellAnim(statusArc,80,131,wk->heapId);
    wk->objRes[PSTATUS_RES_CELL_START + 11]=CLACT_RegisterCellAnim(statusArc,82,133,wk->heapId);
    wk->objRes[PSTATUS_RES_CELL_START + 12]=CLACT_RegisterCellAnim(statusArc,79,130,wk->heapId);
    commonArc=ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(),wk->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(commonArc,APP_ICON_GetStatusAnimFileId(),0,0x120,32,wk->heapId);
    ARC_UTIL_UploadBgCharFromHandle(commonArc,APP_ICON_GetStatusFrameFileId(),1,0,0,0,wk->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(commonArc,APP_ICON_GetStatusDataFileId(),1,0,0,0,wk->heapId);
    BG_SYS_FillTileMap(1,0,21,32,3,9);
    ARC_UTIL_UploadPaletteFromHandleWhole(commonArc,0,4,0x1a0,32,wk->heapId);
    wk->objRes[PSTATUS_RES_PLTT_START + 5]=CLACT_RegisterPaletteEx(commonArc,1,1,0x100,0,1,wk->heapId);
    wk->objRes[PSTATUS_RES_CHR_START + 7]=CLACT_RegisterCharacter(commonArc,2,0,1,wk->heapId);
    wk->objRes[PSTATUS_RES_CELL_START + 6]=CLACT_RegisterCellAnim(commonArc,5,8,wk->heapId);
    wk->objRes[PSTATUS_RES_PLTT_START + 3]=CLACT_RegisterPaletteEx(commonArc,APP_ICON_GetTouchBarFileId(),0,0x100,0,3,wk->heapId);
    wk->objRes[PSTATUS_RES_PLTT_START + 4]=CLACT_RegisterPaletteEx(commonArc,APP_ICON_GetTouchBarFileId(),1,0xa0,0,3,wk->heapId);
    cellArcId=APP_ICON_GetTypePaletteFileId(2); anmArcId=APP_ICON_GetTypeAnimFileId(2);
    wk->objRes[PSTATUS_RES_CELL_START + 4]=CLACT_RegisterCellAnim(commonArc,cellArcId,anmArcId,wk->heapId);
    cellArcId=APP_ICON_GetTypePaletteFileId(0); anmArcId=APP_ICON_GetTypeAnimFileId(0);
    wk->objRes[PSTATUS_RES_CELL_START + 5]=CLACT_RegisterCellAnim(commonArc,cellArcId,anmArcId,wk->heapId);
    for(i=0;i<PSTATUS_TYPE_MAX;i++) wk->typeChrRes[i]=CLACT_RegisterCharacter(commonArc,APP_ICON_GetTypeCellFileId(i),0,0,wk->heapId);
    wk->objRes[PSTATUS_RES_CHR_START + 4]=CLACT_RegisterCharacter(commonArc,56,0,1,wk->heapId);
    wk->objRes[PSTATUS_RES_CHR_START + 5]=CLACT_RegisterCharacter(commonArc,57,0,1,wk->heapId);
    wk->objRes[PSTATUS_RES_CHR_START + 6]=CLACT_RegisterCharacter(commonArc,58,0,1,wk->heapId);
    wk->objRes[PSTATUS_RES_CHR_START + 1]=CLACT_RegisterCharacter(commonArc,APP_ICON_GetMoveKindAnimFileId(),0,0,wk->heapId);
    cellArcId=APP_ICON_GetStatusCellFileId(2); anmArcId=APP_ICON_GetStatusPaletteFileId(2);
    wk->objRes[PSTATUS_RES_CELL_START + 1]=CLACT_RegisterCellAnim(commonArc,cellArcId,anmArcId,wk->heapId);
    wk->objRes[PSTATUS_RES_PLTT_START + 9]=CLACT_RegisterPaletteEx(commonArc,APP_ICON_GetGearDataFileId(),0,0xa0,0,1,wk->heapId);
    wk->objRes[PSTATUS_RES_CHR_START + 10]=CLACT_RegisterCharacter(commonArc,APP_ICON_GetGearExtraFileId(2),0,0,wk->heapId);
    cellArcId=APP_ICON_GetGearFrameFileId(2); anmArcId=APP_ICON_GetGearAnim2FileId(2);
    wk->objRes[PSTATUS_RES_CELL_START + 9]=CLACT_RegisterCellAnim(commonArc,cellArcId,anmArcId,wk->heapId);
    wk->objRes[PSTATUS_RES_PLTT_START + 2]=CLACT_RegisterPaletteEx(commonArc,APP_ICON_GetBallOpenAnimFileId(),0,0xc0,0,1,wk->heapId);
    wk->objRes[PSTATUS_RES_CHR_START + 3]=CLACT_RegisterCharacter(commonArc,APP_ICON_GetEffectCellFileId(2),0,0,wk->heapId);
    cellArcId=APP_ICON_GetEffectPaletteFileId(2); anmArcId=APP_ICON_GetEffectAnimFileId(2);
    wk->objRes[PSTATUS_RES_CELL_START + 3]=CLACT_RegisterCellAnim(commonArc,cellArcId,anmArcId,wk->heapId);
    wk->objRes[PSTATUS_RES_PLTT_START + 10]=CLACT_RegisterPaletteEx(commonArc,APP_ICON_GetSealCellFileId(),0,0x80,0,1,wk->heapId);
    wk->objRes[PSTATUS_RES_CHR_START + 11]=CLACT_RegisterCharacter(commonArc,APP_ICON_GetSealPaletteFileId(),0,0,wk->heapId);
    cellArcId=APP_ICON_GetSealAnimFileId(2); anmArcId=APP_ICON_GetSealFrameFileId(2);
    wk->objRes[PSTATUS_RES_CELL_START + 10]=CLACT_RegisterCellAnim(commonArc,cellArcId,anmArcId,wk->heapId);
    wk->objRes[PSTATUS_RES_PLTT_START + 1]=CLACT_RegisterPaletteEx(commonArc,APP_ICON_GetBallThrowCellFileId(1),0,0xe0,0,1,wk->heapId);
    wk->objRes[PSTATUS_RES_CHR_START + 2]=CLACT_RegisterCharacter(commonArc,APP_ICON_GetBallThrowAnimFileId(1),0,0,wk->heapId);
    cellArcId=APP_ICON_GetBallOpenCellFileId(1,2); anmArcId=APP_ICON_GetBallOpenPaletteFileId(1,2);
    wk->objRes[PSTATUS_RES_CELL_START + 2]=CLACT_RegisterCellAnim(commonArc,cellArcId,anmArcId,wk->heapId);
    ARC_TOOL_DeleteHandle(commonArc);
    P_STA_SUB_LoadArcGraphics(wk,wk->subWork,statusArc);
    P_STA_INFO_LoadResources(wk,wk->infoWork,statusArc);
    P_STA_SKILL_LoadArcGraphics(wk,wk->skillWork,statusArc);
    P_STA_RIBBON_LoadArcGraphics(wk,wk->ribbonWork,statusArc);
    ARC_TOOL_DeleteHandle(statusArc);
}
















/*
 * extent: Two trailing zero alignment bytes at 0x021D4FBA.
 */
void P_STATUS_DeleteObjResource(PStatusWork *wk)
{
    u8 i;
    P_STA_RIBBON_FreeArcGraphics(wk,wk->ribbonWork);
    P_STA_SKILL_Exit(wk,wk->skillWork);
    P_STA_INFO_FreeResources(wk,wk->infoWork);
    P_STA_SUB_Exit(wk,wk->subWork);
    for(i=PSTATUS_RES_PLTT_START;i<=PSTATUS_RES_PLTT_END;i++) CLACT_ReleasePalette(wk->objRes[i]);
    for(i=PSTATUS_RES_CHR_START;i<=PSTATUS_RES_CHR_END;i++) CLACT_ReleaseCharacter(wk->objRes[i]);
    for(i=PSTATUS_RES_CELL_START;i<=PSTATUS_RES_CELL_END;i++) CLACT_ReleaseCellAnim(wk->objRes[i]);
    for(i=0;i<PSTATUS_TYPE_MAX;i++) CLACT_ReleaseCharacter(wk->typeChrRes[i]);
}
















/*
 * lever: real far bank/actor struct fields retain four offset spills.
 * interface: owner 0204B294 legacy void prototype tail-forwards allocator
 *   0204CFDC, whose full body returns an object pointer; caller consumes r0.
 *   All seven arguments preserve owner's full-word ids and u16 stack args.
 *   Descriptor x/y/z/kind/flag all initialize before any consumer call.
 *   Byte tables are consecutive records at witnessed base 021DBFA0.
 */
void P_STATUS_CreateButtonActors(PStatusWork *wk)
{
    struct ButtonBytes anmSeq=_ButtonPlacement[2];
    struct ButtonBytes posX=_ButtonPlacement[0];
    StaOamActorPos init;
    u8 i,j;
    u32 chrRes,cellRes;
    init.drawPriority=10;init.bgPriority=0;
    for(i=0;i<8;i++){
        if(i<=2){chrRes=wk->objRes[PSTATUS_RES_CHR_START + 0];cellRes=wk->objRes[PSTATUS_RES_CELL_START + 0];}
        else{chrRes=wk->objRes[PSTATUS_RES_CHR_START + 1];cellRes=wk->objRes[PSTATUS_RES_CELL_START + 1];}
        init.x=posX.v[i];init.y=(i==3)?172:168;init.animSeq=anmSeq.v[i];
        wk->buttonActor[i]=CLACT_CreateActor(wk->clunit,chrRes,wk->objRes[PSTATUS_RES_PLTT_START + 0],cellRes,&init,0,wk->heapId);
        CLACT_SetActorAutoAnim(wk->buttonActor[i],1);
        CLACT_SetActorDrawEnable(wk->buttonActor[i],1);
    }
    init.x=0;init.y=0;init.animSeq=0;
    wk->typeIconActor[0]=CLACT_CreateActor(wk->clunit,wk->typeChrRes[0],wk->objRes[PSTATUS_RES_PLTT_START + 3],wk->objRes[PSTATUS_RES_CELL_START + 4],&init,0,wk->heapId);
    wk->typeIconActor[1]=CLACT_CreateActor(wk->clunit,wk->typeChrRes[0],wk->objRes[PSTATUS_RES_PLTT_START + 3],wk->objRes[PSTATUS_RES_CELL_START + 4],&init,0,wk->heapId);
    for(j=0;j<2;j++)CLACT_SetActorDrawEnable(wk->typeIconActor[j],0);
    if(wk->param->mode==2)for(i=0;i<8;i++)if(i!=7)CLACT_SetActorDrawEnable(wk->buttonActor[i],0);
    if(P_STATUS_CanUseButtons(wk)==0){CLACT_SetActorDrawEnable(wk->buttonActor[6],0);CLACT_SetActorDrawEnable(wk->buttonActor[3],0);}
    P_STA_SUB_CreateObjects(wk,wk->subWork);
    P_STA_RIBBON_CreateObjects(wk,wk->ribbonWork);
    P_STA_SKILL_CreateObjects(wk,wk->skillWork);
}
















void P_STATUS_DeleteButtonActors(PStatusWork *wk)
{
    u8 i;
    P_STA_RIBBON_DeleteObjects(wk,wk->ribbonWork);
    P_STA_SKILL_DeleteObjects(wk,wk->skillWork);
    P_STA_SUB_DeleteObjects(wk,wk->subWork);
    for (i=0;i<8;i++) CLACT_DeleteActor(wk->buttonActor[i]);
    for (i=0;i<2;i++) CLACT_DeleteActor(wk->typeIconActor[i]);
}
















void P_STATUS_InitMessage(PStatusWork *wk)
{
    wk->font=GF_FONT_Create(23,0,0,0,wk->heapId);
    wk->msgData=MSGDATA_CreateFromArchive(0,2,158,wk->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,448,32,wk->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,448,32,wk->heapId);
    {
        enum { COLOR=0x4e59 } color=COLOR;
        enum { BASE=(HW_PLTT_SUB_BG + 0x1c0) } base=BASE;
        ((TextPalette *)base)->fontColor=color;
        ((TextPalette *)base)->shadowColor=0x6a52;
    }
    wk->printQue=PRINTSYS_QUE_CreateEx(4096,wk->heapId);
}
















void P_STATUS_ExitMessage(PStatusWork *wk)
{
    PRINTSYS_QUE_Clear(wk->printQue);
    PRINTSYS_QUE_Delete(wk->printQue);
    MSGDATA_Delete(wk->msgData);
    GF_FONT_Delete(wk->font);
}
















void P_STATUS_UpdateTouch(PStatusWork *wk)
{
    struct TpHitTable hitRects = _TouchHitRects;
    wk->tpHit = TOUCHPANEL_HitTrg(&hitRects);
}
















void P_STATUS_UpdateInput(PStatusWork *wk)
{
    if (wk->isInputEnabled == 1 && PRINTSYS_QUE_IsFinished(wk->printQue) == 1 && P_STATUS_CheckKey(wk) == 0) {
        P_STATUS_CheckTouch(wk);
    }
}
















int P_STATUS_CheckKey(PStatusWork *wk)
{
    int lastPage;
    if (KEY_GetRepeat() & 0x80) {
        if (P_STATUS_ChangePokemon(wk,1)==1) {
            P_STATUS_RequestRefresh(wk);
            CLACT_SetActorAnimSeq(wk->buttonActor[4],3);
            CLACT_SetActorAnimSeq(wk->buttonActor[5],10);
            wk->prevButtonAnim=0;
            wk->nextButtonAnim=1;
            GFL_USE_PlaySeDefaultVolume(1636);
            wk->inputType=0;
            return 1;
        }
    } else if (KEY_GetRepeat() & 0x40) {
        if (P_STATUS_ChangePokemon(wk,0)==1) {
            P_STATUS_RequestRefresh(wk);
            CLACT_SetActorAnimSeq(wk->buttonActor[4],11);
            CLACT_SetActorAnimSeq(wk->buttonActor[5],2);
            wk->prevButtonAnim=1;
            wk->nextButtonAnim=0;
            GFL_USE_PlaySeDefaultVolume(1636);
            wk->inputType=0;
            return 1;
        }
    } else if (KEY_GetRepeat() & 0x10) {
        lastPage=2;
        if (wk->hasRibbon==0) lastPage=1;
        if (wk->page<lastPage && wk->isEgg==0) {
            wk->page++;
            P_STATUS_RequestRefresh(wk);
            GFL_USE_PlaySeDefaultVolume(1637);
            wk->inputType=0;
            return 1;
        }
    } else if (KEY_GetRepeat() & 0x20) {
        if (wk->page>0 && wk->isEgg==0) {
            wk->page--;
            P_STATUS_RequestRefresh(wk);
            GFL_USE_PlaySeDefaultVolume(1637);
            wk->inputType=0;
            return 1;
        }
    } else if (KEY_GetTrg() & 2) {
        wk->retCode=1;
        wk->param->retSel=1;
        wk->seq=2;
        CLACT_SetActorAnimSeq(wk->buttonActor[7],9);
        wk->pushedButton=wk->buttonActor[7];
        GFL_USE_PlaySeDefaultVolume(1361);
        wk->inputType=0;
        return 1;
    } else if ((KEY_GetTrg() & 0x400) && P_STATUS_CanUseButtons(wk)==1) {
        wk->retCode=2;
        wk->param->retSel=2;
        wk->seq=2;
        CLACT_SetActorAnimSeq(wk->buttonActor[6],8);
        wk->pushedButton=wk->buttonActor[6];
        GFL_USE_PlaySeDefaultVolume(1366);
        wk->inputType=0;
        return 1;
    } else if ((KEY_GetTrg() & 0x800) && P_STATUS_CanUseButtons(wk)==1) {
        if (wk->page<3) {
            if (wk->pageToggle[wk->page]==1) {
                wk->pageToggle[wk->page]=0;
                CLACT_SetActorAnimSeq(wk->buttonActor[3],6);
            } else {
                wk->pageToggle[wk->page]=1;
                CLACT_SetActorAnimSeq(wk->buttonActor[3],7);
            }
            GFL_USE_PlaySeDefaultVolume(1606);
            wk->inputType=0;
        }
        return 1;
    }
    return 0;
}
















/*
 * arithmetic: signed p+58 guard accepts negatives; scaled address uses
 *   unsigned 32-bit multiply/add for the original wrapping lsl/add sequence.
 */
void P_STATUS_CheckTouch(PStatusWork *wk)
{
    switch (wk->tpHit) {
    case 0:
        if (wk->page!=0) {
            wk->page=0;
            P_STATUS_RequestRefresh(wk);
            GFL_USE_PlaySeDefaultVolume(1637);
            wk->inputType=1;
        }
        break;
    case 1:
        if (wk->page!=1 && wk->isEgg==0) {
            wk->page=1;
            P_STATUS_RequestRefresh(wk);
            GFL_USE_PlaySeDefaultVolume(1637);
            wk->inputType=1;
        }
        break;
    case 2:
        if (wk->page!=2 && wk->isEgg==0 && wk->hasRibbon==1) {
            wk->page=2;
            P_STATUS_RequestRefresh(wk);
            GFL_USE_PlaySeDefaultVolume(1637);
            wk->inputType=1;
        }
        break;
    case 3:
        if (wk->page<3 && P_STATUS_CanUseButtons(wk)==1) {
            if (wk->pageToggle[wk->page]==1) {
                wk->pageToggle[wk->page]=0;
                CLACT_SetActorAnimSeq(wk->buttonActor[3],6);
            } else {
                wk->pageToggle[wk->page]=1;
                CLACT_SetActorAnimSeq(wk->buttonActor[3],7);
            }
            GFL_USE_PlaySeDefaultVolume(1606);
            wk->inputType=1;
        }
        break;
    case 4:
        if (P_STATUS_ChangePokemon(wk,0)==1) {
            P_STATUS_RequestRefresh(wk);
            CLACT_SetActorAnimSeq(wk->buttonActor[4],11);
            CLACT_SetActorAnimSeq(wk->buttonActor[5],2);
            wk->prevButtonAnim=1;
            wk->nextButtonAnim=0;
            GFL_USE_PlaySeDefaultVolume(1636);
            wk->inputType=1;
        }
        break;
    case 5:
        if (P_STATUS_ChangePokemon(wk,1)==1) {
            P_STATUS_RequestRefresh(wk);
            CLACT_SetActorAnimSeq(wk->buttonActor[4],3);
            CLACT_SetActorAnimSeq(wk->buttonActor[5],10);
            wk->prevButtonAnim=0;
            wk->nextButtonAnim=1;
            GFL_USE_PlaySeDefaultVolume(1636);
            wk->inputType=1;
        }
        break;
    case 6:
        if (P_STATUS_CanUseButtons(wk)==1) {
            wk->retCode=2;
            wk->param->retSel=2;
            wk->seq=2;
            CLACT_SetActorAnimSeq(wk->buttonActor[6],8);
            wk->pushedButton=wk->buttonActor[6];
            GFL_USE_PlaySeDefaultVolume(1366);
            wk->inputType=1;
        }
        break;
    case 7:
        wk->retCode=1;
        wk->param->retSel=1;
        wk->seq=2;
        CLACT_SetActorAnimSeq(wk->buttonActor[7],9);
        wk->pushedButton=wk->buttonActor[7];
        GFL_USE_PlaySeDefaultVolume(1361);
        wk->inputType=1;
        break;
    }
}
















s32 P_STATUS_UpdatePaletteAnime(PStatusWork *wk)
{
    struct CursorColors A;
    struct CursorColors B;
    u16 ang;
    float t;
    u8 n_1;
    u16 ca_1, cb_1;
    s8 r_1, g_1, b_1;
    u16 ca_2, cb_2;
    s8 r_2, g_2, b_2;
    u16 ca_3;
    s8 r_3, g_3, b_3, r2_3, g2_3, b2_3;
    int IR_3, IG_3, IB_3;

    ang = wk->blinkAngle;
    if (ang + 0x400 >= 0x10000) {
        wk->blinkAngle = ang - 0xfc00;
    } else {
        wk->blinkAngle = ang + 0x400;
    }
    A = _CursorColorsFrom;
    B = _CursorColorsTo;
    t = (float)((FX_SinCosTable_[(wk->blinkAngle >> 4) * 2] + 0x1000) / 2) / 4096.0f;

    for (n_1 = 0; n_1 < 4; n_1++) {
        ca_1 = A.color[n_1];
        r_1 = (s8)(ca_1 & 0x1f);
        g_1 = (s8)((ca_1 & 0x3e0) >> 5);
        b_1 = (s8)((ca_1 & 0x7c00) >> 10);
        cb_1 = B.color[n_1];
        r_1 = (s8)(int)((float)r_1 + t * (float)((s8)(cb_1 & 0x1f) - r_1));
        g_1 = (s8)(int)((float)g_1 + t * (float)((s8)((cb_1 & 0x3e0) >> 5) - g_1));
        b_1 = (s8)(int)((float)b_1 + t * (float)((s8)((cb_1 & 0x7c00) >> 10) - b_1));
        if (r_1 < 0) r_1 = 0;
        if (g_1 < 0) g_1 = 0;
        if (b_1 < 0) b_1 = 0;
        if (r_1 > 31) r_1 = 31;
        if (g_1 > 31) g_1 = 31;
        if (b_1 > 31) b_1 = 31;
        wk->cursorPal[n_1] = (b_1 << 10) | ((g_1 << 5) | r_1);
    }
    NNS_GfdRegisterNewVramTransferTask((void *)14, 0x6c, (u32)wk->cursorPal, 8);

    for (n_1 = 0; n_1 < 16; n_1++) {
        ca_2 = wk->glowPalBase[n_1];
        r_2 = (s8)(ca_2 & 0x1f);
        g_2 = (s8)((ca_2 & 0x3e0) >> 5);
        b_2 = (s8)((ca_2 & 0x7c00) >> 10);
        cb_2 = wk->glowPalTarget[n_1];
        r_2 = (s8)(int)((float)r_2 + t * (float)((s8)(cb_2 & 0x1f) - r_2));
        g_2 = (s8)(int)((float)g_2 + t * (float)((s8)((cb_2 & 0x3e0) >> 5) - g_2));
        b_2 = (s8)(int)((float)b_2 + t * (float)((s8)((cb_2 & 0x7c00) >> 10) - b_2));
        if (r_2 < 0) r_2 = 0;
        if (g_2 < 0) g_2 = 0;
        if (b_2 < 0) b_2 = 0;
        if (r_2 > 31) r_2 = 31;
        if (g_2 > 31) g_2 = 31;
        if (b_2 > 31) b_2 = 31;
        wk->glowPal[n_1] = (b_2 << 10) | ((g_2 << 5) | r_2);
    }
    NNS_GfdRegisterNewVramTransferTask((void *)14, 0x180, (u32)wk->glowPal, 0x20);

    for (n_1 = 12; n_1 <= 14; n_1++) {
        ca_3 = wk->markPalBase[n_1];
        IR_3 = ca_3 & 0x1f;
        r_3 = (s8)IR_3;
        IG_3 = (ca_3 & 0x3e0) >> 5;
        g_3 = (s8)IG_3;
        IB_3 = (ca_3 & 0x7c00) >> 10;
        b_3 = (s8)IB_3;
        r2_3 = (s8)(IR_3 + 10);
        g2_3 = (s8)(IG_3 + 10);
        b2_3 = (s8)(IB_3 + 10);
        if (r2_3 > 31) r2_3 = 31;
        if (g2_3 > 31) g2_3 = 31;
        if (b2_3 > 31) b2_3 = 31;
        r_3 = (s8)(int)((float)r_3 + t * (float)(r2_3 - r_3));
        g_3 = (s8)(int)((float)g_3 + t * (float)(g2_3 - g_3));
        b_3 = (s8)(int)((float)b_3 + t * (float)(b2_3 - b_3));
        if (r_3 < 0) r_3 = 0;
        if (g_3 < 0) g_3 = 0;
        if (b_3 < 0) b_3 = 0;
        if (r_3 > 31) r_3 = 31;
        if (g_3 > 31) g_3 = 31;
        if (b_3 > 31) b_3 = 31;
        wk->markPal[n_1] = (b_3 << 10) | ((g_3 << 5) | r_3);
    }
    return NNS_GfdRegisterNewVramTransferTask((void *)14, 0x1a0, (u32)wk->markPal, 0x20);
}
















void P_STATUS_SetInputEnable(PStatusWork *wk,int enable)
{
    wk->isInputEnabled=enable;
    if(enable==0){
        CLACT_SetActorDrawEnable(wk->buttonActor[0],0);
        CLACT_SetActorDrawEnable(wk->buttonActor[1],0);
        CLACT_SetActorDrawEnable(wk->buttonActor[2],0);
        CLACT_SetActorDrawEnable(wk->buttonActor[3],0);
        CLACT_SetActorDrawEnable(wk->buttonActor[4],0);
        CLACT_SetActorDrawEnable(wk->buttonActor[5],0);
        CLACT_SetActorDrawEnable(wk->buttonActor[6],0);
    }else{
        CLACT_SetActorDrawEnable(wk->buttonActor[0],1);
        CLACT_SetActorDrawEnable(wk->buttonActor[1],1);
        if(wk->hasRibbon==1) CLACT_SetActorDrawEnable(wk->buttonActor[2],1);
        CLACT_SetActorDrawEnable(wk->buttonActor[4],1);
        CLACT_SetActorDrawEnable(wk->buttonActor[5],1);
        if(P_STATUS_CanUseButtons(wk)==1){
            CLACT_SetActorDrawEnable(wk->buttonActor[3],1);
            CLACT_SetActorDrawEnable(wk->buttonActor[6],1);
        }
    }
}
















int P_STATUS_ChangePokemon(PStatusWork *wk,int direction)
{
 unsigned short newPos;
 int found=P_STATUS_SearchPokemon(wk,direction,&newPos);
 if(found==1) {
 wk->pos=newPos;
 if(wk->param->ppt==2) {
 if(wk->tempPP) {POKE_TOOL_ClearPartyParam(wk->tempPP);GFL_HEAP_Free(wk->tempPP);}
 wk->tempPP=POKE_TOOL_CreateFromBoxParam(P_STATUS_GetPokePara(wk),wk->heapId);
 }
 P_STATUS_LoadPokemonState(wk);
 }
 return found;
}















int P_STATUS_SearchPokemon(PStatusWork *wk,int direction,unsigned short *out)
{
 int found=0;
 int savedPos;
 int done;
 void *pp;
 done=0;
 savedPos=wk->pos;
 do {
 if(direction==1 && wk->pos>=wk->param->max-1) {done=1;continue;}
 if(direction==0 && wk->pos==0) {done=1;continue;}
 if(direction==1) ++wk->pos; else --wk->pos;
 pp=P_STATUS_GetPokePara(wk);
 if(POKE_TOOL_GetBoxValue(pp,169,0)!=0) {
 if(POKE_TOOL_GetBoxValue(pp,76,0)!=1 || wk->page==0) {
 if(wk->page!=2 || P_STATUS_HasRibbon(wk,pp)!=0) {done=1;found=1;}
 }
 }
 } while(done==0);
 if(out) *out=wk->pos;
 wk->pos=savedPos;
 return found;
}















void P_STATUS_LoadPokemonState(PStatusWork *wk)
{
 void *ppSrc=(void *)P_STATUS_GetPokeParaSource(wk);
 void *pp=P_STATUS_GetPokePara(wk);
 int one=1;
 P_STATUS_SetFastMode(wk,1);
 wk->isEgg=POKE_TOOL_GetPartyValue(ppSrc,76,0);
 wk->friendship=POKE_TOOL_GetPartyValue(ppSrc,9,0);
 wk->hasRibbon=P_STATUS_HasRibbon(wk,pp);
 P_STATUS_SetFastMode(wk,0);
 wk->playCryReq=one;
}















/*
 * volatile: hardware halfwords reread at 021D5D96, 021D5DA0, 021D5DA6
 *   and written at 021D5D9C, 021D5DA4, 021D5DAA.
 * arithmetic: full-word selectors have cases 0..3 and an empty default;
 *   no selector bound is assumed. Halfword OR with 64 fits promoted int.
 * interfaces: own matched 60D4,697C,7C38,9C3C,8F50,9D44,A84C;
 *   matched callers 4418,4240,7BF0 supply remaining two-argument calls.
 *   Full original 6CDC and 909C confirm both incoming payloads are passed.
 */
void P_STATUS_RequestRefresh(PStatusWork *wk)
{
    P_STATUS_SetFastMode(wk,1);
    if (wk->dispPos!=wk->pos) {
        if (wk->dispPos!=255) {
            P_STA_SUB_FreeWindows(wk,wk->subWork);
            P_STA_RIBBON_Noop(wk,wk->ribbonWork);
        }
        P_STA_SUB_InitWindows(wk,wk->subWork);
        P_STA_RIBBON_CollectOwned(wk,wk->ribbonWork);
    }
    switch (wk->dispPage) {
    case 0: P_STA_INFO_DeleteWindows(wk,wk->infoWork); break;
    case 1: P_STA_SKILL_FreeStatsPage(wk,wk->skillWork); break;
    case 2: P_STA_RIBBON_Deactivate(wk,wk->ribbonWork); break;
    case 3: P_STA_SKILL_FreeMovesPage(wk,wk->skillWork); break;
    }
    switch (wk->page) {
    case 0: P_STA_INFO_Setup(wk,wk->infoWork); break;
    case 1: P_STA_SKILL_InitStatsPage(wk,wk->skillWork); break;
    case 2: P_STA_RIBBON_Init(wk,wk->ribbonWork); break;
    case 3: P_STA_SKILL_InitMovesPage(wk,wk->skillWork); break;
    }
    if (wk->dispPage!=wk->page) {
        wk->mosaicSeq=1;
        wk->mosaicLevel=0;
        *(volatile u16 *)HW_REG_BG3CNT |= 64;
        *(volatile u16 *)HW_REG_BG2CNT_SUB |= 64;
        *(volatile u16 *)HW_REG_BG3CNT_SUB |= 64;
    }
    P_STATUS_SetFastMode(wk,0);
    wk->refreshReq=1;
}















/*
 * volatile: byte hardware writes 0400004C at 021D5DE6/021D5E1C
 *   and 0400104C at 021D5DF2/021D5E28; no ordinary object is volatile.
 * arithmetic: byte inc/dec is modulo 256; reloaded byte <=255 shifted
 *   by five fits int. Signed selector <3 admits negatives: address uses
 *   unsigned full-word multiply/add, preserving original wrap.
 * output: matched unit_02006CAC unconditionally stores the one-word out;
 *   the pointer payload passed as the eighth 02006984 argument is u32.
 * interfaces: callee own matched files; 7EAC keeps second caller payload
 *   visibly set at 021D5E9C despite its own body's unused parameter.
 */
void P_STATUS_UpdateRefresh(PStatusWork *wk)
{
    void *ppSrc;
    u32 species,form;
    void *voicePlayer;
    if (wk->mosaicSeq==1) {
        ++wk->mosaicLevel;
        *(volatile u8 *)HW_REG_MOSAIC=wk->mosaicLevel | (wk->mosaicLevel<<5);
        *(volatile u8 *)HW_REG_MOSAIC_SUB=wk->mosaicLevel | (wk->mosaicLevel<<5);
        if (wk->mosaicLevel>=3) wk->mosaicSeq=2;
    }
    if (wk->mosaicSeq==3) {
        --wk->mosaicLevel;
        *(volatile u8 *)HW_REG_MOSAIC=wk->mosaicLevel | (wk->mosaicLevel<<5);
        *(volatile u8 *)HW_REG_MOSAIC_SUB=wk->mosaicLevel | (wk->mosaicLevel<<5);
        if (wk->mosaicLevel==0) {
            wk->refreshReq=0;
            wk->mosaicSeq=0;
            return;
        }
    }
    if (PRINTSYS_QUE_IsFinished(wk->printQue)==1 &&
        (wk->mosaicSeq==2 || wk->mosaicSeq==0)) {
        if (wk->dispPos!=wk->pos) {
            if (wk->dispPos!=255) P_STA_SUB_HideSprite(wk,wk->subWork);
            P_STA_SUB_Refresh(wk,wk->subWork);
            wk->dispPos=wk->pos;
        }
        switch (wk->dispPage) {
        case 0: P_STA_INFO_HidePage(wk,wk->infoWork); break;
        case 1: P_STA_SKILL_HideStatsPage(wk,wk->skillWork); break;
        case 2: P_STA_RIBBON_Hide(wk,wk->ribbonWork); break;
        case 3: P_STA_SKILL_HideMovesPage(wk,wk->skillWork); break;
        }
        switch (wk->page) {
        case 0: P_STA_INFO_ShowPage(wk,wk->infoWork); break;
        case 1: P_STA_SKILL_ShowStatsPage(wk,wk->skillWork); break;
        case 2: P_STA_RIBBON_Show(wk,wk->ribbonWork); break;
        case 3: P_STA_SKILL_ShowMovesPage(wk,wk->skillWork); break;
        }
        if (wk->isEgg==0 && wk->param->mode!=2) {
            CLACT_SetActorDrawEnable(wk->buttonActor[1],1);
            if (wk->hasRibbon==0) CLACT_SetActorDrawEnable(wk->buttonActor[2],0);
            else CLACT_SetActorDrawEnable(wk->buttonActor[2],1);
        } else {
            CLACT_SetActorDrawEnable(wk->buttonActor[1],0);
            CLACT_SetActorDrawEnable(wk->buttonActor[2],0);
        }
        if (wk->prevButtonAnim==0) {
            if (P_STATUS_SearchPokemon(wk,0,0)==1) CLACT_SetActorAnimSeq(wk->buttonActor[4],3);
            else CLACT_SetActorAnimSeq(wk->buttonActor[4],17);
        }
        if (wk->nextButtonAnim==0) {
            if (P_STATUS_SearchPokemon(wk,1,0)==1) CLACT_SetActorAnimSeq(wk->buttonActor[5],2);
            else CLACT_SetActorAnimSeq(wk->buttonActor[5],16);
        }
        if (wk->page<3 && P_STATUS_CanUseButtons(wk)==1) {
            if (wk->pageToggle[wk->page]==1)
                CLACT_SetActorAnimSeq(wk->buttonActor[3],7);
            else CLACT_SetActorAnimSeq(wk->buttonActor[3],6);
        }
        if (wk->playCryReq==1) {
            wk->playCryReq=0;
            PM_VOICE_StopSlot(0);
            if (wk->isEgg==0) {
                ppSrc=(void *)P_STATUS_GetPokeParaSource(wk);
                species=POKE_TOOL_GetPartyValue(ppSrc,5,0);
                form=POKE_TOOL_GetPartyValue(ppSrc,111,0);
                PM_VOICE_GetPerapVoiceSave(&voicePlayer);
                PM_VOICE_Play(species,form,64,0,0,0,0,(u32)&voicePlayer);
            }
        }
        if (wk->mosaicSeq==2) {
            wk->mosaicSeq=3;
            wk->dispPage=wk->page;
            return;
        }
        wk->refreshReq=0;
        wk->dispPage=wk->page;
    }
}















void *P_STATUS_GetPokePara(PStatusWork *wk)
{
 switch(wk->param->ppt) {
 case 0: return POKE_TOOL_Dummy(wk->param->ppd);
 case 1: return POKE_TOOL_Dummy(POKEPARTY_GetMember(wk->param->ppd,wk->pos));
 case 2: return (unsigned char *)wk->param->ppd+POKE_TOOL_GetBoxParamSize()* wk->pos;
 default: return 0;
 }
}














int P_STATUS_GetPokeParaSource(PStatusWork *wk)
{
    PStatusParam *param = wk->param;
    switch (param->ppt) {
    case 0:
        return (int)param->ppd;
    case 1:
        return (int)POKEPARTY_GetMember(param->ppd, wk->pos);
    case 2:
        return (int)wk->tempPP;
    default:
        return 0;
    }
}














void P_STATUS_SetFastMode(PStatusWork *wk,int fastMode)
{
 void *pp;
 switch(wk->param->ppt) {
 case 0:
 pp=wk->param->ppd;
 if(fastMode==1) POKE_TOOL_DecodePartyParam(pp); else POKE_TOOL_EncodePartyParam(pp,1);
 break;
 case 1:
 pp=POKEPARTY_GetMember(wk->param->ppd,wk->pos);
 if(fastMode==1) POKE_TOOL_DecodePartyParam(pp); else POKE_TOOL_EncodePartyParam(pp,1);
 break;
 case 2:
 pp=P_STATUS_GetPokePara(wk);
 if(fastMode==1) {POKE_TOOL_DecodePartyParam(wk->tempPP);POKE_TOOL_DecodeBoxParam(pp);}
 else {POKE_TOOL_EncodePartyParam(wk->tempPP,1);POKE_TOOL_EncodeBoxParam(pp,1);}
 break;
 }
}












void P_STATUS_PrintMsg(PStatusWork *wk,int bmpWin,int msgId,int x,unsigned short y,unsigned short color)
{
 void *text=MSGDATA_AllocString(wk->msgData,msgId);
 PRINTSYS_PrintQueColor(wk->printQue,bmpWin,(short)x,(short)y,(u32)text,(int)wk->font,color);
 STRBUF_Delete(text);
}











void P_STATUS_PrintMsgToWin(PStatusWork *wk,unsigned int bmpWinData,int msgId,int x,unsigned short y,unsigned short color)
{
 P_STATUS_PrintMsg(wk,(int)BMP_WIN_GetBmp((struct BmpWin *)bmpWinData),msgId,x,y,color);
}











void P_STATUS_PrintWordSetMsg(PStatusWork *wk,int bmpWin,void *wordSet,int msgId,unsigned short x,unsigned short y,unsigned short color)
{
 void *str=STRBUF_Create(16,wk->heapId);
 void *fmt=MSGDATA_AllocString(wk->msgData,msgId);
 WORDSET_CopyTaggedText(wordSet,str,fmt);
 PRINTSYS_PrintQueColor(wk->printQue,bmpWin,(short)x,(short)y,(u32)str,(int)wk->font,color);
 STRBUF_Delete(fmt);
 STRBUF_Delete(str);
}










void P_STATUS_PrintWordSetMsgToWin(PStatusWork *wk,unsigned int bmpWinData,void *wordSet,int msgId,unsigned short x,unsigned short y,unsigned short color)
{
 P_STATUS_PrintWordSetMsg(wk,(int)BMP_WIN_GetBmp((struct BmpWin *)bmpWinData),wordSet,msgId,x,y,color);
}










void P_STATUS_PrintWordSetMsgRight(PStatusWork *wk,int bmpWin,void *wordSet,int msgId,unsigned short x,unsigned short y,unsigned short color)
{
 void *str=STRBUF_Create(16,wk->heapId);
 void *fmt=MSGDATA_AllocString(wk->msgData,msgId);
 int width;
 WORDSET_CopyTaggedText(wordSet,str,fmt);
 width=GF_FONT_MeasureWidestLine(str,(int)wk->font,0);
 PRINTSYS_PrintQueColor(wk->printQue,bmpWin,(short)(x-width),(short)y,(u32)str,(int)wk->font,color);
 STRBUF_Delete(fmt);
 STRBUF_Delete(str);
}














void P_STATUS_PrintWordSetMsgRightToWin(PStatusWork *wk,unsigned int bmpWinData,void *wordSet,int msgId,unsigned short x,unsigned short y,unsigned short color)
{
 P_STATUS_PrintWordSetMsgRight(wk,(int)BMP_WIN_GetBmp((struct BmpWin *)bmpWinData),wordSet,msgId,x,y,color);
}















int P_STATUS_CanUseButtons(PStatusWork *wk)
{
    return wk->param->canUseButtons == 1;
}














int P_STATUS_HasRibbon(PStatusWork *wk, void *pp)
{
    unsigned char i;
    for (i = 0; i < 0x50; i++) {
        if (POKE_TOOL_GetBoxValue(pp, P_STA_RIBBON_GetRibbonInfo(i, 0), 0) == 1) {
            return 1;
        }
    }
    return 0;
}














static inline void SetPartyMoves(void *pokePara, DebugMoves moves) { POKE_TOOL_SetPartyValue(pokePara,0x8e,(u32)(&moves)); }














static inline void SetArrayMoves(void *pokePara, DebugMoves moves) { POKE_TOOL_SetBoxValue(pokePara,0x8e,(u32)(&moves)); }














int P_STATUS_ProcInit(void *proc,int *seq,PStatusParam *pwk,PStatusWork *mywk)
{
    switch(*seq) {
    case 0: {
        PStatusParam *param=pwk;
        PStatusWork *wk;
        u8 i;
        GFL_HEAP_CreateChildHeap(1,0x42,0x50000);
        wk=PROCSYS_AllocProcWork(proc,0x264,0x42);
        MI_CpuFill8(wk,0,0x264);
        wk->heapId=0x42;
        i=0;
        if(param==0) {
            param=GFL_HEAP_Alloc(1,0x28,0,_SourceFileName,0x4d);
            if((KEY_GetCont()&0x400)==0) {
                void *party;
                void *pokePara;
                party=POKEPARTY_Create(1);
                POKEPARTY_InitEx(party,6);
                for(i=0;i<5;i++) {
                    pokePara=POKE_TOOL_Create(i+3,10,-1,0,1);
                    SetPartyMoves(pokePara,_DebugMovesParty);
                    POKE_TOOL_SetPartyValue(pokePara,0x9a,0);
                    POKEPARTY_Add(party,pokePara);
                    GFL_HEAP_Free(pokePara);
                }
                param->pos=0;
                param->ppd=party;
                param->ppt=1;
                param->max=5;
            } else {
                int monSize;
                u8 *monArray;
                u32 byteOffset;
                monSize=POKE_TOOL_GetBoxParamSize();
                param->ppd=GFL_HEAP_Alloc(1,monSize*0x1e,1,_SourceFileName,0x81);
                param->ppt=2;
                param->max=0x1e;
                param->pos=0xff;
                for(i=0;i<param->max;i++) {
                    monSize=POKE_TOOL_GetBoxParamSize();
                    monArray=(u8 *)param->ppd;
                    byteOffset=i*monSize;
                    POKE_TOOL_ClearBoxParam((struct PokePara *)(monArray+byteOffset));
                    if(GFL_USE_GetRandomBelow(3)!=0) {
                        POKE_TOOL_SetupBoxParam(monArray+byteOffset,i+1,0x32,(u64)-1);
                        SetArrayMoves(monArray+byteOffset,_DebugMovesArray);
                        POKE_TOOL_SetBoxValue(monArray+byteOffset,0x9a,0);
                        if(param->pos==0xff) param->pos=i;
                    }
                }
            }
            i=0;
            param->mode=0;
            param->page=0;
            param->canUseButtons=1;
            param->isNationalDex=1;
            param->config=GAME_DATA_Create(1);
            if(KEY_GetCont()&0x400) {
                param->mode=2;
                param->canUseButtons=i;
                param->newMove=10;
            }
            if(KEY_GetCont()&0x100) {
                param->mode=1;
                param->canUseButtons=0;
            }
            func_020355D8(1);
        }
        wk->param=param;
        *seq=1;
        break;
    }
    case 1:
        if(P_STATUS_InitWork(mywk)==1) return 1;
        break;
    }
    return 0;
}














int P_STATUS_ProcExit(void *proc, int *seq, PStatusParam *pwk, PStatusWork *mywk)
{
    if (!P_STATUS_ExitWork(mywk)) return 0;
    if (!pwk) {
        GAME_DATA_Delete(mywk->param->config);
        GFL_HEAP_Free(mywk->param->ppd);
        GFL_HEAP_Free(mywk->param);
    }
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(0x42);
    return 1;
}

int P_STATUS_ProcMain(void *proc, int *seq, PStatusParam *pwk, PStatusWork *mywk)
{
    int ret = P_STATUS_MainSeq(mywk);
    if (ret == 1)
        return 1;
    if (ret == 2)
        return 1;
    return 0;
}
