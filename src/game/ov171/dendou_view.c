/*
 * file:     dendou_view.c
 * unit:     yes
 * function: DENDOU_VIEW_ProcInit, DENDOU_VIEW_ProcMain, DENDOU_VIEW_ProcExit, DENDOU_VIEW_StartVBlankTask, DENDOU_VIEW_StopVBlankTask, DENDOU_VIEW_VBlankTask, DENDOU_VIEW_InitVram, DENDOU_VIEW_GetVramBanks, DENDOU_VIEW_InitBgs, DENDOU_VIEW_ExitBgs, DENDOU_VIEW_LoadGraphics, DENDOU_VIEW_InitPalAnm, DENDOU_VIEW_ExitPalAnm, DENDOU_VIEW_ApplyPaletteFade, DENDOU_VIEW_IsPaletteFadeBusy, DENDOU_VIEW_InitBlend, DENDOU_VIEW_InitText, DENDOU_VIEW_ExitText, DENDOU_VIEW_LoadHallOfFame, DENDOU_VIEW_FreeHallOfFame, DENDOU_VIEW_RunState, DENDOU_VIEW_StateInit, DENDOU_VIEW_StateExit, DENDOU_VIEW_StateWaitWipe, DENDOU_VIEW_StateWaitButton, DENDOU_VIEW_StateOverview, DENDOU_VIEW_StateChangeRow, DENDOU_VIEW_StateEnterDetail, DENDOU_VIEW_StateDetail, DENDOU_VIEW_StateLeaveDetail, DENDOU_VIEW_StateRotate, DENDOU_VIEW_StateStartExit, DENDOU_VIEW_StartWipeIn, DENDOU_VIEW_StartWipeOut, DENDOU_VIEW_StartButtonAnim, DENDOU_VIEW_StepRow, DENDOU_VIEW_StepCursor, DENDOU_VIEW_IsMemberLeftOfCenter, DENDOU_VIEW_CountRotationSteps, DENDOU_VIEW_StartRotation, DENDOU_VIEW_AdvanceRotation, DENDOU_VIEW_InitWindows, DENDOU_VIEW_ExitWindows, DENDOU_VIEW_FlushWindows, DENDOU_VIEW_PresentWindow, DENDOU_VIEW_DrawTitle, DENDOU_VIEW_DrawPageCounter, DENDOU_VIEW_DrawMemberInfo, DENDOU_VIEW_ClearInfoWindow, DENDOU_VIEW_InitActors, DENDOU_VIEW_ExitActors, DENDOU_VIEW_UpdateActors, DENDOU_VIEW_SetActorVisible, DENDOU_VIEW_SetActorAnim, DENDOU_VIEW_IsActorAnimActive, DENDOU_VIEW_MoveActor, DENDOU_VIEW_GetActorPos, DENDOU_VIEW_InitClactSystem, DENDOU_VIEW_LoadButtonResources, DENDOU_VIEW_ReleaseCharacter, DENDOU_VIEW_ReleasePalette, DENDOU_VIEW_ReleaseCellAnim, DENDOU_VIEW_ReleaseResources, DENDOU_VIEW_CreateActor, DENDOU_VIEW_CreateButtonActors, DENDOU_VIEW_DeleteActor, DENDOU_VIEW_DeleteActors, DENDOU_VIEW_SwitchRowActors, DENDOU_VIEW_GetActiveActorBase, DENDOU_VIEW_PlaceActorOnEllipse, DENDOU_VIEW_SortActorPriorities, DENDOU_VIEW_InitPaletteFade, DENDOU_VIEW_InitPageCounterOam, DENDOU_VIEW_ExitPageCounterOam, DENDOU_VIEW_ReadOverviewInput, DENDOU_VIEW_ReadDetailInput, DENDOU_VIEW_ReadTouchedMember
 * address:  0x021DC860
 * region:   ov171
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * note: Four signed bounds are computed before clamping; the guarded do loop
 *   saves start only after its unsigned entry guard. Separate sentinel and
 *   explicit selection arms retain the original best-index register web.
 *   Listing after the 228-byte function and pool is rodata from 021DEA44.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   TCB_DeleteTask  0x02030EAC  arm
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   d_02FE0000 0x02FE0000 data a4
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   sVramBanks 0x021DEB20 data a4
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021DEA50 0x021DEA50 data a4
 *   d_021DEAC0 0x021DEAC0 data a4
 *   d_021DEAA0 0x021DEAA0 data a4
 *   sBgTemplateMain2 0x021DEB00 data a4
 *   sBgTemplateMain3 0x021DEA60 data a4
 *   d_021DEA80 0x021DEA80 data a4
 *   d_021DEAE0 0x021DEAE0 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   BG_SYS_DrawTile  0x02041090  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb
 *   PALANM_Delete  0x02021540  thumb
 *   PALANM_BlendChannelMask 0x02022004 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GAME_DATA_GetSaveBlock42 0x02012F68 thumb
 *   DENDOU_SAVEDATA_GetMemberCount 0x0200EC14 thumb
 *   DENDOU_SAVEDATA_GetRecordDate 0x0200EC98 thumb
 *   DENDOU_SAVEDATA_ExportMember 0x0200EC2C thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SAVE_CONTROL_LoadExtraSave 0x0200725C thumb
 *   SAVE_CONTROL_GetExtraSaveRecord 0x020073D8 thumb
 *   DENDOU_SAVEDATA_GetRingMemberCount 0x0200ECD0 thumb
 *   DENDOU_SAVEDATA_GetHallNumber 0x0200ECC4 thumb
 *   DENDOU_SAVEDATA_GetRingRecordDate 0x0200ED14 thumb
 *   DENDOU_SAVEDATA_ExportRingMember 0x0200ECF0 thumb
 *   SAVE_CONTROL_DeleteExtraSave 0x020072A4 thumb
 *   sStateHandlers 0x021DEB5C data a4
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   ov067_id       0x00000043  data
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   sRotationStepByCount 0x021DEB50 data a4
 *   WIPE_SYS_Start 0x0202208C thumb
 *   sAngleSpacingByCount 0x021DEB56 data
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BMP_WIN_GetDispWidth 0x02045748 arm
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   WORDSET_SetSlotSpeciesName 0x0201EE60 thumb
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_GetActorAutoAnim 0x0204B944 arm
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   d_021DEB88 0x021DEB88 data a4
 *   CLACT_InitSystem 0x0204A48C arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   sButtonActorTemplates 0x021DEBA4 data a4
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKEGRA_RegisterCgr 0x0202D81C thumb
 *   POKEGRA_RegisterPalette 0x0202D7D8 thumb
 *   POKEGRA_RegisterCellAnim 0x0202D898 thumb
 *   POKE_TOOL_IsShinyOtIdPersonality 0x02017ED8 thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   sMemberActorTemplates 0x021DEC04 data a4
 *   sMemberSlotsByCount 0x021DEC94 data a4
 *   GF_STANDARD_CosFromDegreesWrapped 0x0203F6D8 arm
 *   GF_STANDARD_SinFromDegreesWrapped 0x0203F684 arm
 *   _ll_mul 0x0209C054 arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   BMP_Create 0x02043678 arm
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_SetEnabled 0x02025774 thumb
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   KEY_GetRepeat 0x0203633C arm
 *   KEY_GetTrg 0x020362DC arm
 *   d_021DED24 0x021DED24 data a4
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 */
#include "dendou_view_types.h"
#include "../sdk_ioreg.h"
#include "../ov067/touchbar.h"

/* Library structures this file only passes around. */
struct ProcSys;
struct DispVram;

/* Display setup records (words not yet decoded, see open_items.tsv). */
#include "../arm9/bg_sys.h"
/* CLACT_InitSystem configuration (28 bytes, fields not yet decoded). */
typedef struct ClactSystemConfig { u32 w[7]; } ClactSystemConfig;
/* Actor surface position as CLACT_GetActorSurfacePos and AddActorSurfacePos use it. */
typedef struct DendouViewPos { s16 x, y; } DendouViewPos;
/* Same pair with y first: the layout the compiler gave the locals that receive x and y. */
typedef struct DendouViewPosYX { s16 y, x; } DendouViewPosYX;

#define DENDOU_VIEW_HEAP_TAIL 0x808c
#define DENDOU_VIEW_COMMON_RESOURCE 12

#define DENDOU_VIEW_REG_MAIN_BLDCNT REG_BLDCNT_ADDR
#define DENDOU_VIEW_REG_SUB_BLDCNT REG_DB_BLDCNT_ADDR
#define DENDOU_VIEW_REG_MAIN_BRIGHT REG_MASTER_BRIGHT_ADDR
#define DENDOU_VIEW_REG_SUB_BRIGHT REG_DB_MASTER_BRIGHT_ADDR

#define SPECIES_NIDORAN_F 29
#define SPECIES_NIDORAN_M 32

#include "../arm9/gfl_heap.h"
struct Proc;
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gfl_heap_wrap.h"
struct TcbTask;
#include "../arm9/gfl_use.h"
#include "../arm9/tcb_list.h"
extern void BG_SYS_Update(void), CLACT_VBlankSystem(void);
extern void BG_SYS_SetMainPlaneVisible(u32, u32), BG_SYS_SetSubPlaneVisible(u32, u32);
extern void BG_SYS_FreeLayerBuf(unsigned), BG_SYS_Delete(void);
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
#include "../arm9/palanm.h"
/* palanm.h does not declare these yet */
/* palanm.h does not declare these yet */
#include "../arm9/g2.h"
struct MsgBank;
#include "../arm9/msgdata.h"
#include "../arm9/gf_font.h"
struct WordSet;
struct PrintQueue;
/* The DS code was built against a prototype with a halfword x (the header has a word x). The host build uses the header. */
#ifdef __MWERKS__
#define PRINTSYS_PrintColor PRINTSYS_PrintColor_header
#endif
#include "../arm9/printsys.h"
#ifdef __MWERKS__
#undef PRINTSYS_PrintColor
extern void PRINTSYS_PrintColor(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);
#endif
#include "../arm9/strbuf.h"
#include "../arm9/wordset.h"
struct GameData;
#include "../arm9/game_data.h"
#include "../arm9/dendou_savedata.h"
struct RecordDate;
struct SaveControl;
#include "../arm9/save_control.h"
#include "../arm9/gf_overlay.h"
#include "../arm9/gx.h"
#include "../arm9/net.h"
#include "../arm9/wipe.h"
#include "../arm9/bmp_win.h"
struct BmpWin;
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/clact.h"
struct ClactActor;
struct DispVramCfg;
struct ClactSysInit;
#include "../arm9/app_icon.h"
struct Unit;
/* The DS code passes the archive handle as a pointer and the other arguments without volatile (the original prototypes); the header takes a word handle. The host build uses the header. */
#ifdef __MWERKS__
#define POKEGRA_RegisterCgr POKEGRA_RegisterCgr_header
#define POKEGRA_RegisterPalette POKEGRA_RegisterPalette_header
#endif
#include "../arm9/pokegra.h"
#ifdef __MWERKS__
#undef POKEGRA_RegisterCgr
#undef POKEGRA_RegisterPalette
extern u32 POKEGRA_RegisterCgr(void *handle, u32 species, u32 form, u32 gender, u32 shiny, u32 dir, u32 egg, u32 personality, u32 drawType, u16 heap);
extern u32 POKEGRA_RegisterPalette(void *handle, u32 species, u32 form, u32 gender, u32 shiny, u32 dir, u32 egg, u32 drawType, u16 palOffset, u16 heap);
#define DENDOU_VIEW_POKEGRA_HANDLE(h) (h)
#else
#define DENDOU_VIEW_POKEGRA_HANDLE(h) ((uptr)(h))
#endif
#include "../arm9/poke_tool.h"
#include "../arm9/gf_standard.h"
struct BmpOamSys;
#include "../arm9/touchpanel.h"
#include "../arm9/key.h"
#include "../arm9/bmp_oam.h"

/* Function prototypes of this file. */
int DENDOU_VIEW_ProcInit(struct ProcSys *proc, void *unused, DendouViewParams *params);
int DENDOU_VIEW_ProcMain(int unusedA, int unusedB, int unusedC, DendouViewWork *work);
int DENDOU_VIEW_ProcExit(void *work);
void DENDOU_VIEW_StartVBlankTask(DendouViewWork *work);
void DENDOU_VIEW_StopVBlankTask(DendouViewWork *work);
void DENDOU_VIEW_VBlankTask(struct TcbTask *unused, void *work);
void DENDOU_VIEW_InitVram(void);
const void *DENDOU_VIEW_GetVramBanks(void);
void DENDOU_VIEW_InitBgs(void);
void DENDOU_VIEW_ExitBgs(void);
void DENDOU_VIEW_LoadGraphics(void);
void DENDOU_VIEW_InitPalAnm(DendouViewWork *work);
void DENDOU_VIEW_ExitPalAnm(DendouViewWork *work);
void DENDOU_VIEW_ApplyPaletteFade(DendouViewWork *work);
int DENDOU_VIEW_IsPaletteFadeBusy(DendouViewWork *work);
void DENDOU_VIEW_InitBlend(void);
void DENDOU_VIEW_InitText(DendouViewWork *work);
void DENDOU_VIEW_ExitText(DendouViewWork *work);
void DENDOU_VIEW_LoadHallOfFame(DendouViewWork *work);
void DENDOU_VIEW_FreeHallOfFame(DendouViewWork *work);
int DENDOU_VIEW_RunState(DendouViewWork *work);
void DENDOU_VIEW_StateInit(DendouViewWork *work);
int DENDOU_VIEW_StateExit(DendouViewWork *work);
int DENDOU_VIEW_StateWaitWipe(DendouViewWork *work);
u32 DENDOU_VIEW_StateWaitButton(DendouViewWork *work);
int DENDOU_VIEW_StateOverview(DendouViewWork *work);
int DENDOU_VIEW_StateChangeRow(DendouViewWork *work);
int DENDOU_VIEW_StateEnterDetail(DendouViewWork *work);
int DENDOU_VIEW_StateDetail(DendouViewWork *work);
int DENDOU_VIEW_StateLeaveDetail(DendouViewWork *work);
int DENDOU_VIEW_StateRotate(DendouViewWork *work);
int DENDOU_VIEW_StateStartExit(DendouViewWork *work);
int DENDOU_VIEW_StartWipeIn(DendouViewWork *work, int nextState);
int DENDOU_VIEW_StartWipeOut(DendouViewWork *work, int nextState);
int DENDOU_VIEW_StartButtonAnim(DendouViewWork *work, int buttonActor, int animSeq, int nextState);
int DENDOU_VIEW_StepRow(DendouViewWork *work, s8 step);
int DENDOU_VIEW_StepCursor(DendouViewWork *work, s8 step);
int DENDOU_VIEW_IsMemberLeftOfCenter(DendouViewWork *work, int member);
u8 DENDOU_VIEW_CountRotationSteps(DendouViewWork *work, s8 from, int target, s8 step);
void DENDOU_VIEW_StartRotation(DendouViewWork *work, int step);
int DENDOU_VIEW_AdvanceRotation(DendouViewWork *work);
void DENDOU_VIEW_InitWindows(DendouViewWork *work);
void DENDOU_VIEW_ExitWindows(DendouViewWork *work);
void DENDOU_VIEW_FlushWindows(DendouViewWork *work);
void DENDOU_VIEW_PresentWindow(DendouViewWindow *window);
void DENDOU_VIEW_DrawTitle(DendouViewWork *work);
void DENDOU_VIEW_DrawPageCounter(DendouViewWork *work);
void DENDOU_VIEW_DrawMemberInfo(DendouViewWork *work);
void DENDOU_VIEW_ClearInfoWindow(DendouViewWork *work);
void DENDOU_VIEW_InitActors(DendouViewWork *work);
void DENDOU_VIEW_ExitActors(DendouViewWork *work);
void DENDOU_VIEW_UpdateActors(DendouViewWork *work);
void DENDOU_VIEW_SetActorVisible(DendouViewWork *work, int actorIndex, int visible);
void DENDOU_VIEW_SetActorAnim(DendouViewWork *work, int actorIndex, int animSeq);
int DENDOU_VIEW_IsActorAnimActive(DendouViewWork *work, int actorIndex);
void DENDOU_VIEW_MoveActor(DendouViewWork *work, int actorIndex, int dx, int dy);
void DENDOU_VIEW_GetActorPos(DendouViewWork *work, int actorIndex, s16 *outX, s16 *outY);
void DENDOU_VIEW_InitClactSystem(DendouViewWork *work);
void DENDOU_VIEW_LoadButtonResources(DendouViewWork *work);
void DENDOU_VIEW_ReleaseCharacter(DendouViewWork *work, int slot);
void DENDOU_VIEW_ReleasePalette(DendouViewWork *work, int slot);
void DENDOU_VIEW_ReleaseCellAnim(DendouViewWork *work, int slot);
void DENDOU_VIEW_ReleaseResources(DendouViewWork *work);
struct ClactActor *DENDOU_VIEW_CreateActor(DendouViewWork *work, const DendouViewActorTemplate *tmpl);
void DENDOU_VIEW_CreateButtonActors(DendouViewWork *work);
void DENDOU_VIEW_DeleteActor(DendouViewWork *work, int actorIndex);
void DENDOU_VIEW_DeleteActors(DendouViewWork *work);
void DENDOU_VIEW_SwitchRowActors(DendouViewWork *work);
int DENDOU_VIEW_GetActiveActorBase(DendouViewWork *work);
void DENDOU_VIEW_PlaceActorOnEllipse(DendouViewWork *work, int actorIndex, int angle);
void DENDOU_VIEW_SortActorPriorities(DendouViewWork *work);
void DENDOU_VIEW_InitPaletteFade(DendouViewWork *work, int initFade);
void DENDOU_VIEW_InitPageCounterOam(DendouViewWork *work);
void DENDOU_VIEW_ExitPageCounterOam(DendouViewWork *work);
int DENDOU_VIEW_ReadOverviewInput(DendouViewWork *work);
int DENDOU_VIEW_ReadDetailInput(DendouViewWork *work);
int DENDOU_VIEW_ReadTouchedMember(DendouViewWork *work);

extern const struct DispVram sVramBanks;
extern const struct DispConfig d_021DEA50;
extern const struct BgTemplate d_021DEAC0, d_021DEAA0, sBgTemplateMain2, sBgTemplateMain3, d_021DEA80, d_021DEAE0;
extern int (*sStateHandlers[])(DendouViewWork *);
extern u8 ov067_id[];
extern const u8 sRotationStepByCount[];
extern const u8 sAngleSpacingByCount[];
extern const ClactSystemConfig d_021DEB88;
extern const DendouViewActorTemplate sButtonActorTemplates[];
extern const DendouViewActorTemplate sMemberActorTemplates[];
extern const DendouViewSlot sMemberSlotsByCount[][DENDOU_VIEW_MEMBER_MAX];
extern const u8 d_021DED24[];

int DENDOU_VIEW_ProcInit(struct ProcSys *proc, void *unused, DendouViewParams *params)
{
    DendouViewWork *work;
    GFL_HEAP_CreateChildHeap(1, DENDOU_VIEW_HEAP, 0x60000);
    work = PROCSYS_AllocProcWork((struct Proc *)proc, sizeof(DendouViewWork), DENDOU_VIEW_HEAP);
    MI_CpuFill8(work, 0, sizeof(DendouViewWork));
    work->params = params;
    return 1;
}

int DENDOU_VIEW_ProcMain(int unusedA, int unusedB, int unusedC, DendouViewWork *work)
{
    if (DENDOU_VIEW_RunState(work))
        return 0;
    return 1;
}

int DENDOU_VIEW_ProcExit(void *work)
{
    PROCSYS_FreeProcWork(work);
    GFL_HEAP_DeleteChecked(DENDOU_VIEW_HEAP);
    return 1;
}

void DENDOU_VIEW_StartVBlankTask(DendouViewWork *work)
{
    work->vblankTaskId = GFL_USE_AddMainTask(DENDOU_VIEW_VBlankTask, work, 0);
}

void DENDOU_VIEW_StopVBlankTask(DendouViewWork *work)
{
    TCB_DeleteTask(work->vblankTaskId);
}

/*
 * VBlank task: updates actors and palettes, then sets the VBlank bit of the
 * IRQ check flag in DTCM (0x02FE3FF8).
 * lever: enum address base preserves split pools; halfword offset closes r1/r2 allocation; const input retains reads.
 */
void DENDOU_VIEW_VBlankTask(struct TcbTask *unused, void *workArg)
{
    const DendouViewWork *work = workArg;
    enum { IRQ_CHECK_FLAG_OFFSET = 0x3ff8 };
    u16 offset;
    enum { DTCM_BASE = 0x02fe0000 };
    enum { DtcmBase_ = DTCM_BASE } base;
    BG_SYS_Update();
    CLACT_VBlankSystem();
    PALANM_TransferPalettes((struct PaletteFade *)work->palAnm);
    base = DtcmBase_;
    offset = IRQ_CHECK_FLAG_OFFSET;
    *(u32 *)((u32)base + offset) |= 1;
}

void DENDOU_VIEW_InitVram(void)
{
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&sVramBanks);
}

const void *DENDOU_VIEW_GetVramBanks(void)
{
    return &sVramBanks;
}

void DENDOU_VIEW_InitBgs(void)
{
    struct DispConfig dispConfig;
    struct BgTemplate bgMain0, bgMain1, bgMain2, bgMain3, bgSub0, bgSub1;
    BG_SYS_Create(140);
    dispConfig = d_021DEA50;
    BG_SYS_SetGraphicsMode(&dispConfig);
    bgMain0 = d_021DEAC0;
    BG_SYS_InitBgLayer(0, &bgMain0, 0);
    bgMain1 = d_021DEAA0;
    BG_SYS_InitBgLayer(1, &bgMain1, 0);
    bgMain2 = sBgTemplateMain2;
    BG_SYS_InitBgLayer(2, &bgMain2, 0);
    bgMain3 = sBgTemplateMain3;
    BG_SYS_InitBgLayer(3, &bgMain3, 0);
    bgSub0 = d_021DEA80;
    BG_SYS_InitBgLayer(4, &bgSub0, 0);
    bgSub1 = d_021DEAE0;
    BG_SYS_InitBgLayer(5, &bgSub1, 0);
    BG_SYS_SetMainPlaneVisible(13, 1);
    BG_SYS_SetSubPlaneVisible(3, 1);
}

void DENDOU_VIEW_ExitBgs(void)
{
    BG_SYS_SetMainPlaneVisible(15, 0);
    BG_SYS_SetSubPlaneVisible(3, 0);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_Delete();
}

void DENDOU_VIEW_LoadGraphics(void)
{
    void *archive = ARC_TOOL_CreateHandle(0xd5, DENDOU_VIEW_HEAP_TAIL);

    ARC_UTIL_UploadPaletteFromHandleWhole(archive, 1, 0, 0, 0x80, DENDOU_VIEW_HEAP);
    ARC_UTIL_UploadPaletteFromHandleWhole(archive, 6, 4, 0, 0x40, DENDOU_VIEW_HEAP);
    ARC_UTIL_UploadBgCharFromHandle(archive, 0, 0, 0, 0, 1, DENDOU_VIEW_HEAP);
    ARC_UTIL_UploadBgCharFromHandle(archive, 5, 4, 0, 0, 1, DENDOU_VIEW_HEAP);
    ARC_UTIL_UploadBgPaletteFromHandle(archive, 2, 0, 0, 0, 1, DENDOU_VIEW_HEAP);
    ARC_UTIL_UploadBgPaletteFromHandle(archive, 3, 1, 0, 0, 1, DENDOU_VIEW_HEAP);
    ARC_UTIL_UploadBgPaletteFromHandle(archive, 4, 2, 0, 0, 1, DENDOU_VIEW_HEAP);
    ARC_UTIL_UploadBgPaletteFromHandle(archive, 7, 4, 0, 0, 1, DENDOU_VIEW_HEAP);
    ARC_TOOL_DeleteHandle(archive);
    BG_SYS_DrawTile(3, (void *)(BG_SYS_GetBuf(0) + 0x540), 0, 0x15, 0x20, 3);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1e0, 0x20, DENDOU_VIEW_HEAP);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x1e0, 0x20, DENDOU_VIEW_HEAP);
}

void DENDOU_VIEW_InitPalAnm(DendouViewWork *work)
{
    struct PaletteFade *palAnm = PALANM_Create(DENDOU_VIEW_HEAP);

    work->palAnm = palAnm;
    PALANM_AllocSlotBuffers(palAnm, 2, 0x200, DENDOU_VIEW_HEAP);
}

void DENDOU_VIEW_ExitPalAnm(DendouViewWork *work)
{
    PALANM_FreeSlotBuffers(work->palAnm, 2);
    PALANM_Delete(work->palAnm);
}

void DENDOU_VIEW_ApplyPaletteFade(DendouViewWork *work)
{
    unsigned i;
    for (i = 0; i < DENDOU_VIEW_MEMBER_MAX; i++)
        PALANM_BlendChannelMask((void *)work->palAnm, 2, (1 << i) | (1 << (i + 6)), work->fadeLevel[i], 0);
    PALANM_SetAutoTransfer((struct PaletteFade *)work->palAnm, 1);
}

int DENDOU_VIEW_IsPaletteFadeBusy(DendouViewWork *work)
{
    if (PALANM_GetFadeRequestBits((struct PaletteFade *)work->palAnm))
        return 1;
    PALANM_SetAutoTransfer((struct PaletteFade *)work->palAnm, 0);
    return 0;
}

void DENDOU_VIEW_InitBlend(void)
{
    G2x_SetBlendAlpha_((unsigned int *)DENDOU_VIEW_REG_MAIN_BLDCNT, 6, 0x11, 0x10, 8);
}

void DENDOU_VIEW_InitText(DendouViewWork *work)
{
    work->msgData = (struct MsgData *)MSGDATA_CreateFromArchive(0, 2, 0x55, DENDOU_VIEW_HEAP);
    work->fontBody = GF_FONT_Create(0x17, 0, 0, 0, DENDOU_VIEW_HEAP);
    work->fontLevelLabel = GF_FONT_Create(0x17, 3, 0, 0, DENDOU_VIEW_HEAP);
    work->wordSet = WORDSET_CreateDefault(DENDOU_VIEW_HEAP);
    work->printQueue = (struct PrintQue *)PRINTSYS_QUE_Create(DENDOU_VIEW_HEAP);
    work->textBuf = STRBUF_Create(0x400, DENDOU_VIEW_HEAP);
}

void DENDOU_VIEW_ExitText(DendouViewWork *work)
{
    STRBUF_Delete(work->textBuf);
    PRINTSYS_QUE_Delete((struct PrintQueue *)work->printQueue);
    WORDSET_Delete(work->wordSet);
    GF_FONT_Delete(work->fontLevelLabel);
    GF_FONT_Delete(work->fontBody);
    MSGDATA_Delete((struct MsgBank *)work->msgData);
}

/*
 * Loads the Hall of Fame entries. Source 0 reads the latest list of the save
 * block (one row); any other source reads the 15 rows of extra save 8.
 * lever: the locals in this order give the frame; the member address is taken
 * once per row and the date is written through &row->year.
 */
void DENDOU_VIEW_LoadHallOfFame(DendouViewWork *work)
{
    u16 loadRow;
    void *saveControl;
    void *extraData;
    u16 allocRow;
    u16 member;
    DendouViewParams *params;
    for (allocRow = 0; allocRow < DENDOU_VIEW_ROW_MAX; allocRow++) {
        for (member = 0; member < DENDOU_VIEW_MEMBER_MAX; member++) {
            work->rows[allocRow].members[member].nicknameStr = STRBUF_Create(0x20, DENDOU_VIEW_HEAP);
            work->rows[allocRow].members[member].otNameStr = STRBUF_Create(0x20, DENDOU_VIEW_HEAP);
        }
    }
    params = work->params;
    if (params->source == 0) {
        void *saveBlock = GAME_DATA_GetSaveBlock42(params->gameData);
        work->rows[0].memberCount = DENDOU_SAVEDATA_GetMemberCount((char *)saveBlock);
        DENDOU_SAVEDATA_GetRecordDate((const u8 *)saveBlock, (struct RecordDate *)(&work->rows[0].year));
        for (member = 0; member < work->rows[0].memberCount; member++)
            DENDOU_SAVEDATA_ExportMember((const struct DendouEntry *)saveBlock, member, &work->rows[0].members[member]);
        work->rowCount = 1;
    } else {
        u32 extraSaveId;
        saveControl = GAME_DATA_GetSaveControl(params->gameData);
        extraSaveId = 8;
        if (SAVE_CONTROL_LoadExtraSave(saveControl, extraSaveId, DENDOU_VIEW_HEAP) == 1) {
            extraData = SAVE_CONTROL_GetExtraSaveRecord(saveControl, extraSaveId, 0);
            if (extraData) {
                for (loadRow = 0; loadRow < DENDOU_VIEW_ROW_MAX; loadRow++) {
                    work->rows[loadRow].memberCount = DENDOU_SAVEDATA_GetRingMemberCount(extraData, loadRow);
                    work->rows[loadRow].hallNumber = DENDOU_SAVEDATA_GetHallNumber(extraData, loadRow);
                    DENDOU_SAVEDATA_GetRingRecordDate(extraData, loadRow, &work->rows[loadRow].year);
                    if (work->rows[loadRow].memberCount != 0) {
                        for (member = 0; member < work->rows[loadRow].memberCount; member++)
                            DENDOU_SAVEDATA_ExportRingMember((void *)extraData, loadRow, (void *)member, &work->rows[loadRow].members[member]);
                        work->rowCount++;
                    }
                }
            }
        }
        SAVE_CONTROL_DeleteExtraSave(saveControl, extraSaveId);
    }
}

void DENDOU_VIEW_FreeHallOfFame(DendouViewWork *work)
{
    unsigned short rowIndex, memberIndex;
    for (rowIndex = 0; rowIndex < DENDOU_VIEW_ROW_MAX; rowIndex++) {
        for (memberIndex = 0; memberIndex < DENDOU_VIEW_MEMBER_MAX; memberIndex++) {
            STRBUF_Delete(work->rows[rowIndex].members[memberIndex].nicknameStr);
            STRBUF_Delete(work->rows[rowIndex].members[memberIndex].otNameStr);
        }
    }
}

int DENDOU_VIEW_RunState(DendouViewWork *work)
{
    work->state = sStateHandlers[work->state](work);
    if (work->state == DENDOU_VIEW_STATE_END)
        return 0;
    DENDOU_VIEW_UpdateActors(work);
    DENDOU_VIEW_FlushWindows(work);
    return 1;
}

void DENDOU_VIEW_StateInit(DendouViewWork *work)
{
    GF_OVERLAY_Load((sptr)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)DENDOU_VIEW_REG_MAIN_BLDCNT = 0;
    *(volatile u16 *)DENDOU_VIEW_REG_SUB_BLDCNT = 0;
    BG_SYS_SetLcdSwap(0);
    GXx_SetMasterBrightness_((volatile u16 *)DENDOU_VIEW_REG_MAIN_BRIGHT, -0x10);
    GXx_SetMasterBrightness_((volatile u16 *)DENDOU_VIEW_REG_SUB_BRIGHT, -0x10);
    DENDOU_VIEW_LoadHallOfFame(work);
    DENDOU_VIEW_InitVram();
    DENDOU_VIEW_InitBgs();
    DENDOU_VIEW_LoadGraphics();
    DENDOU_VIEW_InitPalAnm(work);
    DENDOU_VIEW_InitText(work);
    DENDOU_VIEW_InitWindows(work);
    DENDOU_VIEW_InitActors(work);
    DENDOU_VIEW_StateChangeRow(work);
    DENDOU_VIEW_InitBlend();
    GFL_NET_RefreshWmIconAtTopRight(1, DENDOU_VIEW_HEAP);
    DENDOU_VIEW_StartVBlankTask(work);
    DENDOU_VIEW_StartWipeIn(work, DENDOU_VIEW_STATE_OVERVIEW);
}

int DENDOU_VIEW_StateExit(DendouViewWork *work)
{
    DENDOU_VIEW_StopVBlankTask(work);
    DENDOU_VIEW_ExitActors(work);
    DENDOU_VIEW_ExitWindows(work);
    DENDOU_VIEW_ExitText(work);
    DENDOU_VIEW_ExitPalAnm(work);
    DENDOU_VIEW_ExitBgs();
    DENDOU_VIEW_FreeHallOfFame(work);
    GXx_SetMasterBrightness_((volatile u16 *)DENDOU_VIEW_REG_MAIN_BRIGHT, -16);
    GXx_SetMasterBrightness_((volatile u16 *)DENDOU_VIEW_REG_SUB_BRIGHT, -16);
    *(volatile u16 *)DENDOU_VIEW_REG_MAIN_BLDCNT = 0;
    *(volatile u16 *)DENDOU_VIEW_REG_SUB_BLDCNT = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    GF_OVERLAY_Unload((sptr)ov067_id);
    return DENDOU_VIEW_STATE_END;
}

int DENDOU_VIEW_StateWaitWipe(DendouViewWork *work)
{
    if (PRINTSYS_QUE_IsFinished((struct PrintQueue *)work->printQueue) == 1 && WIPE_SYS_EndCheck() == 1)
        return work->wipeNextState;
    return DENDOU_VIEW_STATE_WAIT_WIPE;
}

u32 DENDOU_VIEW_StateWaitButton(DendouViewWork *work)
{
    if (DENDOU_VIEW_IsActorAnimActive(work, work->buttonActor) == 0)
        return work->stateAfterButton;
    return DENDOU_VIEW_STATE_WAIT_BUTTON;
}

int DENDOU_VIEW_StateOverview(DendouViewWork *work)
{
    int input;
    if (!PRINTSYS_QUE_IsFinished((struct PrintQueue *)work->printQueue))
        return DENDOU_VIEW_STATE_OVERVIEW;
    input = DENDOU_VIEW_ReadOverviewInput(work);
    switch (input) {
    case DENDOU_VIEW_INPUT_PREV:
        if (DENDOU_VIEW_StepRow(work, -1) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x54b);
            return DENDOU_VIEW_StartButtonAnim(work, DENDOU_VIEW_ACTOR_BUTTON_PREV, 12, DENDOU_VIEW_STATE_CHANGE_ROW);
        }
        break;
    case DENDOU_VIEW_INPUT_NEXT:
        if (DENDOU_VIEW_StepRow(work, 1) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x54b);
            return DENDOU_VIEW_StartButtonAnim(work, DENDOU_VIEW_ACTOR_BUTTON_NEXT, 13, DENDOU_VIEW_STATE_CHANGE_ROW);
        }
        break;
    case DENDOU_VIEW_INPUT_SWITCH:
        GFL_USE_PlaySeDefaultVolume(0x556);
        work->params->result = 1;
        return DENDOU_VIEW_StartButtonAnim(work, DENDOU_VIEW_ACTOR_BUTTON_SWITCH, 8, DENDOU_VIEW_STATE_START_EXIT);
    case DENDOU_VIEW_INPUT_CANCEL:
        GFL_USE_PlaySeDefaultVolume(0x551);
        work->params->result = 0;
        return DENDOU_VIEW_StartButtonAnim(work, DENDOU_VIEW_ACTOR_BUTTON_CANCEL, 9, DENDOU_VIEW_STATE_START_EXIT);
    case DENDOU_VIEW_INPUT_CONFIRM:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        work->selected = work->cursor;
        return DENDOU_VIEW_STATE_ENTER_DETAIL;
    case DENDOU_VIEW_INPUT_MEMBER_0:
    case DENDOU_VIEW_INPUT_MEMBER_1:
    case DENDOU_VIEW_INPUT_MEMBER_2:
    case DENDOU_VIEW_INPUT_MEMBER_3:
    case DENDOU_VIEW_INPUT_MEMBER_4:
    case DENDOU_VIEW_INPUT_MEMBER_5:
        work->selected = input - DENDOU_VIEW_INPUT_MEMBER_0;
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return DENDOU_VIEW_STATE_ENTER_DETAIL;
    }
    return DENDOU_VIEW_STATE_OVERVIEW;
}

int DENDOU_VIEW_StateChangeRow(DendouViewWork *work)
{
    work->cursor = 0;
    DENDOU_VIEW_SwitchRowActors(work);
    DENDOU_VIEW_DrawTitle(work);
    DENDOU_VIEW_DrawPageCounter(work);
    return DENDOU_VIEW_STATE_OVERVIEW;
}

int DENDOU_VIEW_StateEnterDetail(DendouViewWork *work)
{
    s8 previous;
    switch (work->substate) {
    case 0:
        DENDOU_VIEW_SetActorAnim(work, DENDOU_VIEW_ACTOR_BUTTON_PREV, 18);
        DENDOU_VIEW_SetActorAnim(work, DENDOU_VIEW_ACTOR_BUTTON_NEXT, 19);
        DENDOU_VIEW_SetActorAnim(work, DENDOU_VIEW_ACTOR_BUTTON_SWITCH, 14);
        BG_SYS_SetMainPlaneVisible(2, 1);
        DENDOU_VIEW_InitPaletteFade(work, 1);
        DENDOU_VIEW_ApplyPaletteFade(work);
        (work->substate)++;
        break;
    case 1:
        if (!DENDOU_VIEW_IsPaletteFadeBusy(work)) {
            work->substate = 0;
            previous = work->cursor;
            if (work->selected == previous) {
                work->cursor = work->selected;
                DENDOU_VIEW_DrawMemberInfo(work);
                return DENDOU_VIEW_STATE_DETAIL;
            }
            work->cursor = work->selected;
            if (DENDOU_VIEW_IsMemberLeftOfCenter(work, work->selected) == 1) {
                work->rotationStep = -sRotationStepByCount[work->rows[work->rowIndex].memberCount - 1];
                DENDOU_VIEW_StartRotation(work, (s8)(-DENDOU_VIEW_CountRotationSteps(work, previous, work->selected, 1)));
            } else {
                work->rotationStep = sRotationStepByCount[work->rows[work->rowIndex].memberCount - 1];
                DENDOU_VIEW_StartRotation(work, (s8)DENDOU_VIEW_CountRotationSteps(work, previous, work->selected, -1));
            }
            GFL_USE_PlaySeDefaultVolume(0x57b);
            return DENDOU_VIEW_STATE_ROTATE;
        }
        break;
    }
    return DENDOU_VIEW_STATE_ENTER_DETAIL;
}

int DENDOU_VIEW_StateDetail(DendouViewWork *work)
{
    int input;
    s8 previous;
    if (!PRINTSYS_QUE_IsFinished((struct PrintQueue *)work->printQueue))
        return DENDOU_VIEW_STATE_DETAIL;
    input = DENDOU_VIEW_ReadDetailInput(work);
    switch (input) {
    case DENDOU_VIEW_INPUT_PREV:
        if (DENDOU_VIEW_StepCursor(work, 1) == 1) {
            work->rotationStep = -sRotationStepByCount[work->rows[work->rowIndex].memberCount - 1];
            DENDOU_VIEW_StartRotation(work, (s8)(-1));
            GFL_USE_PlaySeDefaultVolume(0x57b);
            return DENDOU_VIEW_STATE_ROTATE;
        }
        break;
    case DENDOU_VIEW_INPUT_NEXT:
        if (DENDOU_VIEW_StepCursor(work, -1) == 1) {
            work->rotationStep = sRotationStepByCount[work->rows[work->rowIndex].memberCount - 1];
            DENDOU_VIEW_StartRotation(work, (s8)1);
            GFL_USE_PlaySeDefaultVolume(0x57b);
            return DENDOU_VIEW_STATE_ROTATE;
        }
        break;
    case DENDOU_VIEW_INPUT_CANCEL:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return DENDOU_VIEW_StartButtonAnim(work, DENDOU_VIEW_ACTOR_BUTTON_CANCEL, 9, DENDOU_VIEW_STATE_LEAVE_DETAIL);
    case DENDOU_VIEW_INPUT_MEMBER_0:
    case DENDOU_VIEW_INPUT_MEMBER_1:
    case DENDOU_VIEW_INPUT_MEMBER_2:
    case DENDOU_VIEW_INPUT_MEMBER_3:
    case DENDOU_VIEW_INPUT_MEMBER_4:
    case DENDOU_VIEW_INPUT_MEMBER_5:
        previous = work->cursor;
        if (input - DENDOU_VIEW_INPUT_MEMBER_0 == previous)
            break;
        work->cursor = input - DENDOU_VIEW_INPUT_MEMBER_0;
        if (DENDOU_VIEW_IsMemberLeftOfCenter(work, input - DENDOU_VIEW_INPUT_MEMBER_0) == 1) {
            work->rotationStep = -sRotationStepByCount[work->rows[work->rowIndex].memberCount - 1];
            DENDOU_VIEW_StartRotation(work, (s8)(-DENDOU_VIEW_CountRotationSteps(work, previous, (s8)(input - DENDOU_VIEW_INPUT_MEMBER_0), 1)));
        } else {
            work->rotationStep = sRotationStepByCount[work->rows[work->rowIndex].memberCount - 1];
            DENDOU_VIEW_StartRotation(work, (s8)DENDOU_VIEW_CountRotationSteps(work, previous, (s8)(input - DENDOU_VIEW_INPUT_MEMBER_0), -1));
        }
        GFL_USE_PlaySeDefaultVolume(0x57b);
        return DENDOU_VIEW_STATE_ROTATE;
    }
    return DENDOU_VIEW_STATE_DETAIL;
}

int DENDOU_VIEW_StateLeaveDetail(DendouViewWork *work)
{
    switch (work->substate) {
    case 0:
        DENDOU_VIEW_InitPaletteFade(work, 0);
        DENDOU_VIEW_ApplyPaletteFade(work);
        BG_SYS_SetMainPlaneVisible(2, 0);
        ++work->substate;
        break;
    case 1:
        if (!DENDOU_VIEW_IsPaletteFadeBusy(work)) {
            DENDOU_VIEW_SetActorAnim(work, DENDOU_VIEW_ACTOR_BUTTON_PREV, 4);
            DENDOU_VIEW_SetActorAnim(work, DENDOU_VIEW_ACTOR_BUTTON_NEXT, 5);
            DENDOU_VIEW_SetActorAnim(work, DENDOU_VIEW_ACTOR_BUTTON_SWITCH, 0);
            DENDOU_VIEW_ClearInfoWindow(work);
            work->substate = 0;
            return DENDOU_VIEW_STATE_OVERVIEW;
        }
        break;
    }
    return DENDOU_VIEW_STATE_LEAVE_DETAIL;
}

int DENDOU_VIEW_StateRotate(DendouViewWork *work)
{
    unsigned i;
    if (!DENDOU_VIEW_AdvanceRotation(work)) {
        for (i = 0; i < work->rows[work->rowIndex].memberCount; ++i)
            work->fadeSettled[i] = work->fadeTarget[i];
        DENDOU_VIEW_IsPaletteFadeBusy(work);
        DENDOU_VIEW_DrawMemberInfo(work);
        return DENDOU_VIEW_STATE_DETAIL;
    } else {
        for (i = 0; i < work->rows[work->rowIndex].memberCount; ++i) {
            if (work->fadeLevel[i] > work->fadeTarget[i])
                --work->fadeLevel[i];
            else if (work->fadeLevel[i] < work->fadeTarget[i])
                ++work->fadeLevel[i];
        }
        DENDOU_VIEW_ApplyPaletteFade(work);
        return DENDOU_VIEW_STATE_ROTATE;
    }
}

int DENDOU_VIEW_StateStartExit(DendouViewWork *work)
{
    return DENDOU_VIEW_StartWipeOut(work, 1);
}

int DENDOU_VIEW_StartWipeIn(DendouViewWork *work, int nextState)
{
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, DENDOU_VIEW_HEAP);
    work->wipeNextState = nextState;
    return DENDOU_VIEW_STATE_WAIT_WIPE;
}

int DENDOU_VIEW_StartWipeOut(DendouViewWork *work, int nextState)
{
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 140);
    work->wipeNextState = nextState;
    return DENDOU_VIEW_STATE_WAIT_WIPE;
}

/*
 * Starts the press animation of a button actor and waits for it, then goes to nextState.
 */
int DENDOU_VIEW_StartButtonAnim(DendouViewWork *work, int buttonActor, int animSeq, int nextState)
{
    DENDOU_VIEW_SetActorAnim(work, buttonActor, animSeq);
    work->buttonActor = buttonActor;
    work->stateAfterButton = nextState;
    return DENDOU_VIEW_STATE_WAIT_BUTTON;
}

/*
 * Moves to another entry, wrapping at both ends. Returns 1 when the entry changed.
 * lever: signed byte step avoids an extra truncation before the addition.
 */
int DENDOU_VIEW_StepRow(DendouViewWork *work, s8 step)
{
    int previous;
    previous = work->rowIndex;
    work->rowIndex += step;
    if (work->rowIndex < 0)
        work->rowIndex = work->rowCount - 1;
    else if (work->rowIndex >= work->rowCount)
        work->rowIndex = 0;
    if (work->rowIndex != previous)
        return 1;
    return 0;
}

/*
 * Moves the cursor to another Pokemon of the entry, wrapping. Returns 1 when it changed.
 */
int DENDOU_VIEW_StepCursor(DendouViewWork *work, s8 step)
{
    int previous;
    previous = work->cursor;
    work->cursor += step;
    if (work->cursor < 0)
        work->cursor = work->rows[work->rowIndex].memberCount - 1;
    else if (work->cursor >= work->rows[work->rowIndex].memberCount)
        work->cursor = 0;
    if (work->cursor != previous)
        return 1;
    return 0;
}

/*
 * Returns 1 when the member's actor stands left of the screen centre (x < 128).
 */
int DENDOU_VIEW_IsMemberLeftOfCenter(DendouViewWork *work, int member)
{
    DendouViewPosYX pos;
    DENDOU_VIEW_GetActorPos(work, (int)((u32)member + (u32)DENDOU_VIEW_GetActiveActorBase(work)), &pos.x, &pos.y);
    if (pos.x < 128)
        return 1;
    return 0;
}

/*
 * Number of rotation steps (at most 6) from one member to another in a direction.
 * lever: signed byte step avoids an extra entry truncation.
 */
u8 DENDOU_VIEW_CountRotationSteps(DendouViewWork *work, s8 from, int target, s8 step)
{
    u8 count;
    count = 1;
    do {
        from += step;
        if (from < 0)
            from = work->rows[work->rowIndex].memberCount - 1;
        else if (from >= work->rows[work->rowIndex].memberCount)
            from = 0;
        if (from == target)
            break;
        count++;
    } while (count < 6);
    return count;
}

/*
 * Starts a rotation by step positions: copies angles and fade levels of the
 * source slots to the target slots and sets the frame counter.
 * lever: A u16 count preserves the word spill at sp+0; bind the final quotient
 *   before multiplying. Explicit runtime calls preserve the zero divisor path.
 */
void DENDOU_VIEW_StartRotation(DendouViewWork *work, int step)
{
    s16 dst = work->cursor;
    s16 src = dst + step;
    unsigned i;
    int stepAngle;
    u16 count;
    if (src < 0) {
        count = work->rows[work->rowIndex].memberCount;
        src += (s16)count;
    } else {
        count = work->rows[work->rowIndex].memberCount;
        if (src >= count)
            src -= (s16)count;
    }
    for (i = 0; i < (unsigned)count; i++) {
        work->targetAngle[dst] = work->angle[src];
        work->fadeTarget[dst] = work->fadeSettled[src];
        dst += (s16)(step / (step < 0 ? -step : step));
        if (dst < 0) {
            count = work->rows[work->rowIndex].memberCount;
            dst = count - 1;
        } else {
            count = work->rows[work->rowIndex].memberCount;
            if (dst >= count)
                dst = 0;
        }
        src += (s16)(step / (step < 0 ? -step : step));
        if (src < 0)
            src = count - 1;
        else if (src >= count)
            src = 0;
    }
    stepAngle = work->rotationStep;
    if (stepAngle < 0)
        stepAngle = -stepAngle;
    if (step < 0)
        step = -step;
    stepAngle = sAngleSpacingByCount[count - 1] / stepAngle;
    work->rotationFramesLeft = stepAngle * step;
}

/*
 * One frame of rotation: moves every actor toward its target angle. Returns 0
 * when the rotation is over.
 * lever: Access the far halfwords as struct members; cache only the guard value, and retain field updates and reads.
 */
int DENDOU_VIEW_AdvanceRotation(DendouViewWork *work)
{
    int base;
    unsigned i;
    int angle;
    base = DENDOU_VIEW_GetActiveActorBase(work);
    if (work->rotationFramesLeft == 0) {
        for (i = 0; i < work->rows[work->rowIndex].memberCount; i++) {
            work->angle[i] = work->targetAngle[i];
            DENDOU_VIEW_PlaceActorOnEllipse(work, base + i, work->angle[i]);
        }
        DENDOU_VIEW_SortActorPriorities(work);
        return 0;
    } else {
        for (i = 0; i < work->rows[work->rowIndex].memberCount; i++) {
            work->angle[i] += work->rotationStep;
            angle = work->angle[i];
            if (angle < 0)
                work->angle[i] += 360;
            else if (angle >= 360)
                work->angle[i] -= 360;
            DENDOU_VIEW_PlaceActorOnEllipse(work, base + i, work->angle[i]);
        }
        DENDOU_VIEW_SortActorPriorities(work);
        (work->rotationFramesLeft)--;
        return 1;
    }
}

/*
 * lever: the first creation call passes 3 in r0, shared with its stack argument.
 */
void DENDOU_VIEW_InitWindows(DendouViewWork *work)
{
    BMP_WIN_Init(DENDOU_VIEW_HEAP);
    work->windows[0].win = BMP_WIN_Create(3, 1, 0, 30, 2, 3, 1);
    work->windows[1].win = BMP_WIN_Create(5, 4, 7, 24, 15, 1, 1);
}

void DENDOU_VIEW_ExitWindows(DendouViewWork *work)
{
    BMP_WIN_Delete(work->windows[0].win);
    BMP_WIN_Delete(work->windows[1].win);
    BMP_WIN_Exit();
}

/*
 * Runs the print queue and copies a window to VRAM once its text is drawn.
 * The typed DendouViewWork.windows[i] fields replace the four offset locals
 * that held the offsets of .win (0xB48) and .transferPending (0xB4C).
 */
void DENDOU_VIEW_FlushWindows(DendouViewWork *work)
{
    unsigned i;
    struct PrintQue *queue;
    PRINTSYS_QUE_Main((struct PrintQueue *)work->printQueue);
    for (i = 0; i < 2; ++i) {
        queue = work->printQueue;
        if (work->windows[i].transferPending) {
            if (!PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)queue, BMP_WIN_GetBmp(work->windows[i].win))) {
                BMP_WIN_TransferChars(work->windows[i].win);
                work->windows[i].transferPending = 0;
            }
        }
    }
}

void DENDOU_VIEW_PresentWindow(DendouViewWindow *window)
{
    BMP_WIN_MakeScreen(window->win);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window->win));
}

/*
 * Draws the title window: the heading, and for extra save entries the hall
 * number and the date.
 */
void DENDOU_VIEW_DrawTitle(DendouViewWork *work)
{
    DendouViewRow *row;
    struct Strbuf *titleText, *numberedText, *dateText;
    u32 dateWidth;
    row = &work->rows[work->rowIndex];
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)work->windows[0].win)), 0);
    if (work->params->source == 0) {
        titleText = MSGDATA_AllocString((struct MsgBank *)work->msgData, 0);
        TOUCHBAR_PrintAligned((TouchBarWindow *)&work->windows[0], (void *)work->printQueue, 0, 0, (uptr)titleText, (uptr)work->fontBody, 0x440, 0);
        STRBUF_Delete(titleText);
    } else {
        numberedText = MSGDATA_AllocString((struct MsgBank *)work->msgData, 1);
        WORDSET_SetSlotNumber((struct WordSet *)work->wordSet, 0, row->hallNumber, 4, 0, 1);
        WORDSET_CopyTaggedText((struct WordSet *)work->wordSet, (struct Strbuf *)work->textBuf, (struct Strbuf *)numberedText);
        TOUCHBAR_PrintAligned((TouchBarWindow *)&work->windows[0], (void *)work->printQueue, 0, 0, (uptr)work->textBuf, (uptr)work->fontBody, 0x440, 0);
        STRBUF_Delete(numberedText);
    }
    dateText = MSGDATA_AllocString((struct MsgBank *)work->msgData, 2);
    WORDSET_SetSlotNumber(work->wordSet, 0, row->year, 2, 2, 1);
    WORDSET_SetSlotNumber(work->wordSet, 1, row->month, 2, 2, 1);
    WORDSET_SetSlotNumber((struct WordSet *)work->wordSet, 2, row->day, 2, 2, 1);
    WORDSET_CopyTaggedText((struct WordSet *)work->wordSet, (struct Strbuf *)work->textBuf, (struct Strbuf *)dateText);
    dateWidth = BMP_WIN_GetDispWidth((struct BmpWin *)work->windows[0].win);
    TOUCHBAR_PrintAligned((TouchBarWindow *)&work->windows[0], (void *)work->printQueue, dateWidth << 3, 0, (uptr)work->textBuf, (uptr)work->fontBody, 0x14c0, 1);
    STRBUF_Delete(dateText);
    DENDOU_VIEW_PresentWindow(&work->windows[0]);
}

/*
 * Draws the "page n/m" counter into the page bitmap (only with more than one entry).
 */
void DENDOU_VIEW_DrawPageCounter(DendouViewWork *work)
{
    struct Strbuf *labelText, *numbersText;
    struct GfFont *font;
    struct Strbuf *text;
    u8 labelWidth, x;
    u32 numberWidth;
    if (work->rowCount == 1)
        return;
    BMP_Clear(work->pageBmp, 0);
    labelText = MSGDATA_AllocString((struct MsgBank *)work->msgData, 3);
    labelWidth = PRINTSYS_MeasureWidestLine(labelText, work->fontBody, 0);
    x = (40 - labelWidth) / 2;
    PRINTSYS_PrintColor(work->pageBmp, x, 4, labelText, work->fontBody, 0x1900);
    STRBUF_Delete(labelText);
    numbersText = MSGDATA_AllocString((struct MsgBank *)work->msgData, 4);
    WORDSET_SetSlotNumber(work->wordSet, 0, work->rowIndex + 1, 2, 0, 1);
    WORDSET_CopyTaggedText(work->wordSet, work->textBuf, numbersText);
    font = work->fontBody;
    text = work->textBuf;
    numberWidth = PRINTSYS_MeasureWidestLine(text, font, 0);
    PRINTSYS_PrintColor(work->pageBmp, x - numberWidth, 4, text, font, 0x1900);
    WORDSET_SetSlotNumber(work->wordSet, 0, work->rowCount, 2, 0, 1);
    WORDSET_CopyTaggedText(work->wordSet, work->textBuf, numbersText);
    PRINTSYS_PrintColor(work->pageBmp, x + labelWidth, 4, work->textBuf, work->fontBody, 0x1900);
    STRBUF_Delete(numbersText);
    BMP_OAM_UploadChars(work->pageBmpOam);
}

/*
 * Draws the detail window of the Pokemon in front: species, gender symbol
 * (not for Nidoran), level, nickname, trainer name and moves.
 */
void DENDOU_VIEW_DrawMemberInfo(DendouViewWork *work)
{
    DendouViewMember *member;
    struct Strbuf *speciesText, *maleText, *femaleText, *levelLabelText, *levelText, *nicknameText, *trainerText, *moveText;
    u32 levelLabelWidth, i;
    member = &work->rows[work->rowIndex].members[work->cursor];
    BMP_Clear(BMP_WIN_GetBmp(work->windows[1].win), 0);
    speciesText = MSGDATA_AllocString((struct MsgBank *)work->msgData, 5);
    WORDSET_SetSlotSpeciesName((struct WordSet *)work->wordSet, 0, member->species);
    WORDSET_CopyTaggedText((struct WordSet *)work->wordSet, (struct Strbuf *)work->textBuf, (struct Strbuf *)speciesText);
    TOUCHBAR_PrintAligned((TouchBarWindow *)&work->windows[1], (void *)work->printQueue, 0, 0, (uptr)work->textBuf, (uptr)work->fontBody, 0x440, 0);
    STRBUF_Delete(speciesText);
    if (member->gender == 0) {
        if (member->species != SPECIES_NIDORAN_M) {
            maleText = MSGDATA_AllocString((struct MsgBank *)work->msgData, 6);
            TOUCHBAR_PrintAligned((TouchBarWindow *)&work->windows[1], (void *)work->printQueue, 64, 0, (uptr)maleText, (uptr)work->fontBody, 0xc80, 0);
            STRBUF_Delete(maleText);
        }
    } else if (member->gender == 1) {
        if (member->species != SPECIES_NIDORAN_F) {
            femaleText = MSGDATA_AllocString((struct MsgBank *)work->msgData, 7);
            TOUCHBAR_PrintAligned((TouchBarWindow *)&work->windows[1], (void *)work->printQueue, 64, 0, (uptr)femaleText, (uptr)work->fontBody, 0x14c0, 0);
            STRBUF_Delete(femaleText);
        }
    }
    levelLabelText = MSGDATA_AllocString((struct MsgBank *)work->msgData, 11);
    levelLabelWidth = PRINTSYS_MeasureWidestLine((struct Strbuf *)levelLabelText, (struct GfFont *)work->fontLevelLabel, 0);
    TOUCHBAR_PrintAligned((TouchBarWindow *)&work->windows[1], (void *)work->printQueue, 80, 4, (uptr)levelLabelText, (uptr)work->fontLevelLabel, 0x440, 0);
    STRBUF_Delete(levelLabelText);
    levelText = MSGDATA_AllocString((struct MsgBank *)work->msgData, 8);
    WORDSET_SetSlotNumber((struct WordSet *)work->wordSet, 0, member->level, 3, 0, 1);
    WORDSET_CopyTaggedText((struct WordSet *)work->wordSet, (struct Strbuf *)work->textBuf, (struct Strbuf *)levelText);
    TOUCHBAR_PrintAligned((TouchBarWindow *)&work->windows[1], (void *)work->printQueue, levelLabelWidth + 80, 0, (uptr)work->textBuf, (uptr)work->fontBody, 0x440, 0);
    STRBUF_Delete(levelText);
    nicknameText = MSGDATA_AllocString((struct MsgBank *)work->msgData, 9);
    WORDSET_SetSlotTag((struct WordSet *)work->wordSet, 0, (struct Strbuf *)member->nicknameStr, 0, 1, 2);
    WORDSET_CopyTaggedText((struct WordSet *)work->wordSet, (struct Strbuf *)work->textBuf, (struct Strbuf *)nicknameText);
    TOUCHBAR_PrintAligned((TouchBarWindow *)&work->windows[1], (void *)work->printQueue, 0, 24, (uptr)work->textBuf, (uptr)work->fontBody, 0x440, 0);
    STRBUF_Delete(nicknameText);
    trainerText = MSGDATA_AllocString((struct MsgBank *)work->msgData, 10);
    WORDSET_SetSlotTag((struct WordSet *)work->wordSet, 0, (struct Strbuf *)member->otNameStr, 0, 1, 2);
    WORDSET_CopyTaggedText((struct WordSet *)work->wordSet, (struct Strbuf *)work->textBuf, (struct Strbuf *)trainerText);
    TOUCHBAR_PrintAligned((TouchBarWindow *)&work->windows[1], (void *)work->printQueue, 0, 48, (uptr)work->textBuf, (uptr)work->fontBody, 0x440, 0);
    STRBUF_Delete(trainerText);
    for (i = 0; i < 4; i++) {
        moveText = MSGDATA_AllocString((struct MsgBank *)work->msgData, i + 12);
        WORDSET_SetSlotFromMsgCB((struct WordSet *)work->wordSet, 0, member->traits[i]);
        WORDSET_CopyTaggedText((struct WordSet *)work->wordSet, (struct Strbuf *)work->textBuf, (struct Strbuf *)moveText);
        TOUCHBAR_PrintAligned((TouchBarWindow *)&work->windows[1], (void *)work->printQueue, (i & 1) * 96, (i >> 1) * 16 + 88, (uptr)work->textBuf, (uptr)work->fontBody, 0x440, 0);
        STRBUF_Delete(moveText);
    }
    DENDOU_VIEW_PresentWindow(&work->windows[1]);
}

void DENDOU_VIEW_ClearInfoWindow(DendouViewWork *work)
{
    BMP_WIN_ClearScreen(work->windows[1].win);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(work->windows[1].win));
    BMP_Clear(BMP_WIN_GetBmp(work->windows[1].win), 0);
    BMP_WIN_TransferChars(work->windows[1].win);
}

void DENDOU_VIEW_InitActors(DendouViewWork *work)
{
    DENDOU_VIEW_InitClactSystem(work);
    DENDOU_VIEW_LoadButtonResources(work);
    DENDOU_VIEW_CreateButtonActors(work);
    DENDOU_VIEW_InitPageCounterOam(work);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
}

void DENDOU_VIEW_ExitActors(DendouViewWork *work)
{
    DENDOU_VIEW_ExitPageCounterOam(work);
    DENDOU_VIEW_DeleteActors(work);
    DENDOU_VIEW_ReleaseResources(work);
    CLACT_ExitSystem();
}

/*
 * Advances the running animations by one frame and draws the actors.
 */
void DENDOU_VIEW_UpdateActors(DendouViewWork *work)
{
    unsigned i;
    for (i = 0; i < DENDOU_VIEW_ACTOR_MAX; i++) {
        if (work->actors[i] != 0 && CLACT_GetActorAutoAnim((struct ClactActor *)work->actors[i]) != 1)
            CLACT_AddActorAnimFrame((struct ClactActor *)work->actors[i], 4096);
    }
    CLACT_DrawSystem();
}

void DENDOU_VIEW_SetActorVisible(DendouViewWork *work, int actorIndex, int visible)
{
    struct ClactActor *actor = work->actors[actorIndex];
    if (actor)
        CLACT_SetActorDrawEnable((struct ClactActor *)actor, visible);
}

void DENDOU_VIEW_SetActorAnim(DendouViewWork *work, int actorIndex, int animSeq)
{
    CLACT_SetActorAnimFrame((struct ClactActor *)work->actors[actorIndex], 0);
    CLACT_SetActorAnimSeq((struct ClactActor *)work->actors[actorIndex], animSeq);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->actors[actorIndex], 1);
}

int DENDOU_VIEW_IsActorAnimActive(DendouViewWork *work, int actorIndex)
{
    return CLACT_IsActorAnimActive((struct ClactActor *)work->actors[actorIndex]);
}

void DENDOU_VIEW_MoveActor(DendouViewWork *work, int actorIndex, int dx, int dy)
{
    DendouViewPos delta;
    delta.x = dx;
    delta.y = dy;
    CLACT_AddActorSurfacePos((struct ClactActor *)work->actors[actorIndex], (const struct ClactVec2 *)&delta, 0);
}

/*
 * Reads the surface position of an actor into two shorts.
 */
void DENDOU_VIEW_GetActorPos(DendouViewWork *work, int actorIndex, s16 *outX, s16 *outY)
{
    struct ClactActor *actor = work->actors[actorIndex];
    DendouViewPos pos;
    CLACT_GetActorSurfacePos((struct ClactActor *)actor, (struct ClactVec2 *)&pos, 0);
    *outX = pos.x;
    *outY = pos.y;
}

void DENDOU_VIEW_InitClactSystem(DendouViewWork *work)
{
    ClactSystemConfig config = d_021DEB88;
    CLACT_InitSystem((struct ClactSysInit *)(&config), (struct DispVramCfg *)(DENDOU_VIEW_GetVramBanks()), 140);
}

/*
 * Clears the resource id tables and loads the resources shared by the button actors (slot 12).
 */
void DENDOU_VIEW_LoadButtonResources(DendouViewWork *work)
{
    unsigned i;
    void *archive;
    int cellArcId;
    for (i = 0; i < DENDOU_VIEW_RESOURCE_MAX; ++i)
        work->cgrIds[i] = -1;
    for (i = 0; i < DENDOU_VIEW_RESOURCE_MAX; ++i)
        work->palIds[i] = -1;
    for (i = 0; i < DENDOU_VIEW_RESOURCE_MAX; ++i)
        work->cellIds[i] = -1;
    archive = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), DENDOU_VIEW_HEAP_TAIL);
    work->cgrIds[DENDOU_VIEW_COMMON_RESOURCE] = CLACT_RegisterCharacter(archive, APP_ICON_GetMoveKindAnimFileId(), 0, 0, DENDOU_VIEW_HEAP);
    work->palIds[DENDOU_VIEW_COMMON_RESOURCE] = CLACT_RegisterPalette(archive, APP_ICON_GetMoveKindPaletteFileId(), 0, 0x180, DENDOU_VIEW_HEAP);
    cellArcId = APP_ICON_GetStatusCellFileId(2);
    work->cellIds[DENDOU_VIEW_COMMON_RESOURCE] = CLACT_RegisterCellAnim(archive, cellArcId, APP_ICON_GetStatusPaletteFileId(2), DENDOU_VIEW_HEAP);
    ARC_TOOL_DeleteHandle(archive);
}

void DENDOU_VIEW_ReleaseCharacter(DendouViewWork *work, int slot)
{
    if (work->cgrIds[slot] != -1) {
        CLACT_ReleaseCharacter(work->cgrIds[slot]);
        work->cgrIds[slot] = -1;
    }
}

void DENDOU_VIEW_ReleasePalette(DendouViewWork *work, int slot)
{
    if (work->palIds[slot] != -1) {
        CLACT_ReleasePalette(work->palIds[slot]);
        work->palIds[slot] = -1;
    }
}

void DENDOU_VIEW_ReleaseCellAnim(DendouViewWork *work, int slot)
{
    if (work->cellIds[slot] != -1) {
        CLACT_ReleaseCellAnim(work->cellIds[slot]);
        work->cellIds[slot] = -1;
    }
}

void DENDOU_VIEW_ReleaseResources(DendouViewWork *work)
{
    unsigned i;
    for (i = 0; i < DENDOU_VIEW_RESOURCE_MAX; i++)
        DENDOU_VIEW_ReleaseCharacter(work, i);
    for (i = 0; i < DENDOU_VIEW_RESOURCE_MAX; i++)
        DENDOU_VIEW_ReleasePalette(work, i);
    for (i = 0; i < DENDOU_VIEW_RESOURCE_MAX; i++)
        DENDOU_VIEW_ReleaseCellAnim(work, i);
}

/*
 * Creates an actor from a template; the template names the resource slots.
 */
struct ClactActor *DENDOU_VIEW_CreateActor(DendouViewWork *work, const DendouViewActorTemplate *tmpl)
{
    return CLACT_CreateActor((struct Unit *)work->clactUnit, work->cgrIds[tmpl->cgrSlot],
        work->palIds[tmpl->palSlot], work->cellIds[tmpl->cellSlot],
        (const struct ActorInitParam *)tmpl, tmpl->argLast, DENDOU_VIEW_HEAP);
}

/*
 * Creates the actor unit and the four button actors (slots 12 to 15).
 * lever: group the integer table offset before adding its symbol base.
 */
void DENDOU_VIEW_CreateButtonActors(DendouViewWork *work)
{
    unsigned i;
    work->clactUnit = CLACT_CreateUnit(31, 0, DENDOU_VIEW_HEAP);
    for (i = 0; i < DENDOU_VIEW_ACTOR_MAX; ++i)
        work->actors[i] = 0;
    for (i = DENDOU_VIEW_ACTOR_BUTTON_PREV; i <= DENDOU_VIEW_ACTOR_BUTTON_CANCEL; ++i)
        work->actors[i] = DENDOU_VIEW_CreateActor(work, (const DendouViewActorTemplate *)((const char *)sButtonActorTemplates + (i * sizeof(DendouViewActorTemplate) - DENDOU_VIEW_ACTOR_BUTTON_PREV * sizeof(DendouViewActorTemplate))));
    if (work->rowCount == 1) {
        DENDOU_VIEW_SetActorVisible(work, DENDOU_VIEW_ACTOR_BUTTON_PREV, 0);
        DENDOU_VIEW_SetActorVisible(work, DENDOU_VIEW_ACTOR_BUTTON_NEXT, 0);
    }
}

void DENDOU_VIEW_DeleteActor(DendouViewWork *work, int actorIndex)
{
    if (work->actors[actorIndex] != 0) {
        CLACT_DeleteActor((struct ClactActor *)work->actors[actorIndex]);
        work->actors[actorIndex] = 0;
    }
}

void DENDOU_VIEW_DeleteActors(DendouViewWork *work)
{
    u32 i;
    for (i = 0; i < DENDOU_VIEW_ACTOR_MAX; i++)
        DENDOU_VIEW_DeleteActor(work, i);
    CLACT_DeleteUnit(work->clactUnit);
}

/*
 * Builds the actors of the current entry in the inactive half, removes the
 * actors and resources of the old half and switches halves.
 */
void DENDOU_VIEW_SwitchRowActors(DendouViewWork *work)
{
    u32 i;
    void *pokegraArchive;
    DendouViewRow *row;
    struct ClactActor **slot;
    u32 half;
    DendouViewMember *member;
    u32 shiny;
    DendouViewActorTemplate tmpl;
    for (i = 0; i <= 11; i++)
        DENDOU_VIEW_SetActorVisible(work, i, 0);
    row = &work->rows[(s8)work->rowIndex];
    pokegraArchive = POKEGRA_OpenHandle(DENDOU_VIEW_HEAP_TAIL);
    {
        for (i = 0; i < row->memberCount; i++) {
            tmpl = sMemberActorTemplates[i];
            member = &row->members[i];
            shiny = POKE_TOOL_IsShinyOtIdPersonality(member->experience, member->pid);
            if (work->activeHalf == 1) {
                tmpl.cgrSlot += 6;
                tmpl.palSlot += 6;
                tmpl.cellSlot += 6;
                half = (u16)(i + 6);
                slot = &work->actors[half];
            } else {
                half = (u16)i;
                slot = &work->actors[half];
            }
            work->cgrIds[tmpl.cgrSlot] = POKEGRA_RegisterCgr(DENDOU_VIEW_POKEGRA_HANDLE(pokegraArchive), member->species, member->form, member->gender, shiny, 0, 0, member->pid, 0, DENDOU_VIEW_HEAP);
            work->palIds[tmpl.palSlot] = POKEGRA_RegisterPalette(DENDOU_VIEW_POKEGRA_HANDLE(pokegraArchive), member->species, member->form, member->gender, shiny, 0, 0, 0, (u16)(half << 5), DENDOU_VIEW_HEAP);
            work->cellIds[tmpl.cellSlot] = POKEGRA_RegisterCellAnim(member->species, member->form, member->gender, shiny, 0, 0, 2, 0, DENDOU_VIEW_HEAP);
            *slot = DENDOU_VIEW_CreateActor(work, &tmpl);
            DENDOU_VIEW_PlaceActorOnEllipse(work, half, sMemberSlotsByCount[row->memberCount - 1][i].angle);
            work->angle[i] = sMemberSlotsByCount[row->memberCount - 1][i].angle;
        }
    }
    PALANM_CopyHwPaletteToSlot(work->palAnm, 2, 0, 0x200);
    ARC_TOOL_DeleteHandle(pokegraArchive);
    if (work->activeHalf == 1) {
        for (i = 0; i <= 5; i++)
            DENDOU_VIEW_DeleteActor(work, i);
        for (i = 0; i <= 5; i++)
            DENDOU_VIEW_ReleaseCharacter(work, i);
        for (i = 0; i <= 5; i++)
            DENDOU_VIEW_ReleasePalette(work, i);
        for (i = 0; i <= 5; i++)
            DENDOU_VIEW_ReleaseCellAnim(work, i);
    } else {
        for (i = 6; i <= 11; i++)
            DENDOU_VIEW_DeleteActor(work, i);
        for (i = 6; i <= 11; i++)
            DENDOU_VIEW_ReleaseCharacter(work, i);
        for (i = 6; i <= 11; i++)
            DENDOU_VIEW_ReleasePalette(work, i);
        for (i = 6; i <= 11; i++)
            DENDOU_VIEW_ReleaseCellAnim(work, i);
    }
    work->activeHalf ^= 1;
    DENDOU_VIEW_SortActorPriorities(work);
}

/*
 * First actor index of the active half.
 */
int DENDOU_VIEW_GetActiveActorBase(DendouViewWork *work)
{
    if (work->activeHalf == 0)
        return 6;
    return 0;
}

/*
 * Puts an actor on the ellipse (radius 100 by 44 around the point 128, 88).
 * lever: mask each translated fixed point coordinate before shifting and narrowing.
 */
void DENDOU_VIEW_PlaceActorOnEllipse(DendouViewWork *work, int actorIndex, int angle)
{
    int x, y;
    x = (int)(((long long)GF_STANDARD_CosFromDegreesWrapped((u16)angle) * 0x64000 + 0x800) >> 12);
    y = (int)(((long long)GF_STANDARD_SinFromDegreesWrapped((u16)angle) * 0x2c000 + 0x800) >> 12);
    x += 0x80000;
    y += 0x58000;
    DENDOU_VIEW_MoveActor(work, actorIndex, (short)((x & 0x7ffff000) >> 12),
        (short)((y & 0x7ffff000) >> 12));
}

/*
 * Sets the draw priority of the active actors by screen y: the lower on the
 * screen, the nearer.
 */
void DENDOU_VIEW_SortActorPriorities(DendouViewWork *work)
{
    u8 order[6];
    DendouViewPosYX posI, posJ;
    int first = DENDOU_VIEW_GetActiveActorBase(work);
    u8 i, j, tmp;
    struct ClactActor *actor;
    for (i = 0; i < 6; i++)
        order[i] = first + i;
    for (i = 0; i < work->rows[work->rowIndex].memberCount - 1; i++) {
        DENDOU_VIEW_GetActorPos(work, order[i], &posI.x, &posI.y);
        for (j = i + 1; j < work->rows[work->rowIndex].memberCount; j++) {
            DENDOU_VIEW_GetActorPos(work, order[j], &posJ.x, &posJ.y);
            if (posI.y < posJ.y) {
                tmp = order[i];
                order[i] = order[j];
                order[j] = tmp;
                posI.y = posJ.y;
            }
        }
    }
    for (i = 0; i < work->rows[work->rowIndex].memberCount; i++) {
        actor = work->actors[order[i]];
        if (actor)
            CLACT_SetActorDrawPriority((struct ClactActor *)actor, i);
    }
}

/*
 * Sets the fade levels of the members: from the slot table when initFade is 1
 * (starting at the cursor), else all zero.
 * lever: slot and i are both set before count (`u16 i = 0;` at the declaration,
 *   loop with an empty init), so r0/r1 are live while count is computed; the scheduler then sinks them.
 */
void DENDOU_VIEW_InitPaletteFade(DendouViewWork *work, int initFade)
{
    u16 slot = work->cursor;
    u16 i = 0;
    u16 count = work->rows[work->rowIndex].memberCount;
    for (; i < count;) {
        if (initFade == 1) {
            work->fadeSettled[slot] = sMemberSlotsByCount[count - 1][i].fadeLevel;
            work->fadeLevel[slot] = work->fadeSettled[slot];
            slot++;
            if (slot >= work->rows[work->rowIndex].memberCount)
                slot = 0;
        } else {
            work->fadeSettled[i] = 0;
            work->fadeLevel[i] = 0;
        }
        i++;
        count = work->rows[work->rowIndex].memberCount;
    }
}

void DENDOU_VIEW_InitPageCounterOam(DendouViewWork *work)
{
    DendouViewBmpOamParam param;
    work->bmpOamSys = BMP_OAM_CreateSys(DENDOU_VIEW_HEAP, work->clactUnit);
    work->pageBmp = BMP_Create(5, 3, 0x20, DENDOU_VIEW_HEAP);
    param.bmp = work->pageBmp;
    param.x = 0x28;
    param.y = 0xA8;
    param.paletteId = work->palIds[DENDOU_VIEW_COMMON_RESOURCE];
    param.mode = 1;
    param.a = 0;
    param.b = 0;
    param.id = 0xFFFF;
    param.extra = 0;
    work->pageBmpOam = BMP_OAM_Create(work->bmpOamSys, (const struct BmpOamParam *)&param);
    if (work->rowCount == 1)
        BMP_OAM_SetEnabled(work->pageBmpOam, 0);
}

void DENDOU_VIEW_ExitPageCounterOam(DendouViewWork *work)
{
    BMP_OAM_Delete(work->pageBmpOam);
    BMP_Delete(work->pageBmp);
    BMP_OAM_DeleteSys(work->bmpOamSys);
}

/*
 * Overview input: touch first, then keys.
 */
int DENDOU_VIEW_ReadOverviewInput(DendouViewWork *work)
{
    int result = TOUCHPANEL_HitTrg((const TouchHitTable *)d_021DED24);
    if (result == -1) {
        result = DENDOU_VIEW_ReadTouchedMember(work);
        if (result == DENDOU_VIEW_INPUT_NONE) {
            if (KEY_GetRepeat() & 0x220)
                return DENDOU_VIEW_INPUT_PREV;
            if (KEY_GetRepeat() & 0x110)
                return DENDOU_VIEW_INPUT_NEXT;
            if (KEY_GetTrg() & 1)
                return DENDOU_VIEW_INPUT_CONFIRM;
            if (KEY_GetTrg() & 2)
                return DENDOU_VIEW_INPUT_CANCEL;
            return (KEY_GetTrg() & 0x400) ? DENDOU_VIEW_INPUT_SWITCH : DENDOU_VIEW_INPUT_NONE;
        }
    }
    return result;
}

/*
 * Detail input: like the overview but without confirm and switch.
 */
int DENDOU_VIEW_ReadDetailInput(DendouViewWork *work)
{
    int result = TOUCHPANEL_HitTrg((const TouchHitTable *)d_021DED24);
    if (result != 3) {
        result = DENDOU_VIEW_ReadTouchedMember(work);
        if (result == DENDOU_VIEW_INPUT_NONE) {
            if (KEY_GetRepeat() & 0x220)
                return DENDOU_VIEW_INPUT_PREV;
            if (KEY_GetRepeat() & 0x110)
                return DENDOU_VIEW_INPUT_NEXT;
            if (KEY_GetTrg() & 2)
                return DENDOU_VIEW_INPUT_CANCEL;
            return DENDOU_VIEW_INPUT_NONE;
        }
    }
    return result;
}

/*
 * Finds the Pokemon actor under the touch point. The hit box is 96 by 96
 * around the actor, clamped to the screen; of several hits the one lowest on
 * the screen wins. Returns the member input code or DENDOU_VIEW_INPUT_NONE.
 */
int DENDOU_VIEW_ReadTouchedMember(DendouViewWork *work)
{
    unsigned int touchX;
    unsigned int touchY;
    DendouViewPosYX pos;
    s16 actorX;
    s16 actorY;
    s16 bestY;
    int first;
    int best;
    int sentinel;
    unsigned int end;
    int i;
    if (TOUCHPANEL_GetPointTrg(&touchX, &touchY) == 0)
        return DENDOU_VIEW_INPUT_NONE;
    i = (s16)DENDOU_VIEW_GetActiveActorBase(work);
    best = -1;
    sentinel = -1;
    end = i + 6;
    if ((unsigned int)i < end) {
        first = i;
        do {
            if (work->actors[i] != 0) {
                DENDOU_VIEW_GetActorPos(work, i, &pos.x, &pos.y);
                actorX = pos.x;
                {
                    s16 left, right, top, bottom;
                    left = actorX - 0x30;
                    right = actorX + 0x30;
                    actorY = pos.y;
                    top = actorY - 0x30;
                    bottom = actorY + 0x30;
                    if (left < 0)
                        left = 0;
                    if (right > 0xff)
                        right = 0xff;
                    if (top < 0)
                        top = 0;
                    if (bottom > 0xff)
                        bottom = 0xff;
                    if (touchX < left)
                        continue;
                    if (touchX >= right)
                        continue;
                    if (touchY < top)
                        continue;
                    if (touchY >= bottom)
                        continue;
                }
                if (best == sentinel) {
                    bestY = actorY;
                    best = (s16)(i - first);
                } else if (actorY > bestY) {
                    bestY = actorY;
                    best = (s16)(i - first);
                }
            }
        } while ((unsigned int)++i < end);
    }
    if (best != -1)
        return (best % 6) + 5;
    else
        return DENDOU_VIEW_INPUT_NONE;
}
