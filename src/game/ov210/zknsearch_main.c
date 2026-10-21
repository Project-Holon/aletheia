/*
 * file:     zknsearch_main.c
 * unit:     yes
 * function: ZKNSEARCH_MAIN_InitBackgrounds, ZKNSEARCH_MAIN_DeleteBackgrounds, ZKNSEARCH_MAIN_ShowLayerSetA, ZKNSEARCH_MAIN_ShowLayerSetB, ZKNSEARCH_MAIN_LoadCommonGraphics, ZKNSEARCH_MAIN_InitPaletteAnim, ZKNSEARCH_MAIN_DeletePaletteAnim, ZKNSEARCH_MAIN_RequestPaletteFade, ZKNSEARCH_MAIN_SetBrightness, ZKNSEARCH_MAIN_ConfigureWindow, ZKNSEARCH_MAIN_ResetWindow, ZKNSEARCH_MAIN_InitTextSystem, ZKNSEARCH_MAIN_DeleteTextSystem, ZKNSEARCH_MAIN_InitBlinkPalette, ZKNSEARCH_MAIN_UpdateBlinkPalette, ZKNSEARCH_MAIN_InitScrollWindow, ZKNSEARCH_MAIN_DeleteScrollWindow, ZKNSEARCH_MAIN_LoadBgTile93, ZKNSEARCH_MAIN_LoadBgTile89, ZKNSEARCH_MAIN_LoadBgTile88, ZKNSEARCH_MAIN_LoadBgTile90, ZKNSEARCH_MAIN_LoadBgTile86, ZKNSEARCH_MAIN_LoadBgTile87, ZKNSEARCH_MAIN_LoadResultGraphics, ZKNSEARCH_MAIN_DeleteResultGraphics, ZKNSEARCH_MAIN_ShowResultLayout, ZKNSEARCH_MAIN_HideResultLayout, ZKNSEARCH_MAIN_SetFadeStateA, ZKNSEARCH_MAIN_SetFadeStateB, ZKNSEARCH_MAIN_EnterResultLayout, ZKNSEARCH_MAIN_StartScrollMove, ZKNSEARCH_MAIN_UpdateScrollMove, ZKNSEARCH_MAIN_GetListIndexA, ZKNSEARCH_MAIN_GetListIndexB, ZKNSEARCH_MAIN_LookupEntryId, ZKNSEARCH_MAIN_LookupSavedEntryId, ZKNSEARCH_MAIN_NormalizeRecordByte, ZKNSEARCH_MAIN_DenormalizeRecordByte, ZKNSEARCH_MAIN_RunState, ZKNSEARCH_MAIN_InitSearchScreen, ZKNSEARCH_MAIN_ExitSearchScreen, ZKNSEARCH_MAIN_WaitFadeDone, ZKNSEARCH_MAIN_EnterSearchResult, ZKNSEARCH_MAIN_UpdateSearchResult, ZKNSEARCH_MAIN_ExitState, ZKNSEARCH_MAIN_EnterSearchEngine, ZKNSEARCH_MAIN_UpdateSearchEngine, ZKNSEARCH_MAIN_UpdateListInput, ZKNSEARCH_MAIN_EnterListPage1, ZKNSEARCH_MAIN_UpdateListPage1, ZKNSEARCH_MAIN_ExitListPage1, ZKNSEARCH_MAIN_EnterListPage2, ZKNSEARCH_MAIN_UpdateListPage2, ZKNSEARCH_MAIN_ExitListPage2, ZKNSEARCH_MAIN_EnterListPage3, ZKNSEARCH_MAIN_UpdateListPage3, ZKNSEARCH_MAIN_ExitListPage3, ZKNSEARCH_MAIN_EnterListPage4, ZKNSEARCH_MAIN_UpdateListPage4, ZKNSEARCH_MAIN_ExitListPage4, ZKNSEARCH_MAIN_EnterListPage5, ZKNSEARCH_MAIN_UpdateListPage5, ZKNSEARCH_MAIN_ExitListPage5, ZKNSEARCH_MAIN_UpdateConfirmDialog, ZKNSEARCH_MAIN_UpdateMessageDialog, ZKNSEARCH_MAIN_EnterMessageDialog, ZKNSEARCH_MAIN_SelectEntry1, ZKNSEARCH_MAIN_ClearEntry1, ZKNSEARCH_MAIN_ToggleEntry1, ZKNSEARCH_MAIN_ClearEntry2, ZKNSEARCH_MAIN_ToggleEntry2, ZKNSEARCH_MAIN_ClearEntry3, ZKNSEARCH_MAIN_ToggleEntry3, ZKNSEARCH_MAIN_ClearEntry4, ZKNSEARCH_MAIN_ToggleEntry4, ZKNSEARCH_MAIN_ClearEntry5, ZKNSEARCH_MAIN_EnterMessageState, ZKNSEARCH_MAIN_EnterListState, ZKNSEARCH_MAIN_ToggleSaveFlag, ZKNSEARCH_MAIN_InitBmpWindows, ZKNSEARCH_MAIN_DeleteBmpWindows, ZKNSEARCH_MAIN_UpdateBmpWindows, ZKNSEARCH_MAIN_PrintWindowText, ZKNSEARCH_MAIN_MakeWindowScreen, ZKNSEARCH_MAIN_InitWindowTexts, ZKNSEARCH_MAIN_UpdateResultTexts, ZKNSEARCH_MAIN_PrintLabel1, ZKNSEARCH_MAIN_ClearLabel1, ZKNSEARCH_MAIN_InitListTexts, ZKNSEARCH_MAIN_PrintEntryCount, ZKNSEARCH_MAIN_InitListTexts2, ZKNSEARCH_MAIN_PrintEntryCount2, ZKNSEARCH_MAIN_InitListTexts3, ZKNSEARCH_MAIN_PrintEntryCount3, ZKNSEARCH_MAIN_InitListTexts4, ZKNSEARCH_MAIN_PrintEntryCount4, ZKNSEARCH_MAIN_InitListTexts5, ZKNSEARCH_MAIN_PrintListRow, ZKNSEARCH_MAIN_TransferRowChars, ZKNSEARCH_MAIN_PrintMessageText, ZKNSEARCH_MAIN_PrintMessage11, ZKNSEARCH_MAIN_PrintMessage9, ZKNSEARCH_MAIN_PrintMessage10, ZKNSEARCH_MAIN_RedrawSubWindow, ZKNSEARCH_MAIN_InitActorSystem, ZKNSEARCH_MAIN_DeleteActorSystem, ZKNSEARCH_MAIN_UpdateActorAnims, ZKNSEARCH_MAIN_SetActorAnim, ZKNSEARCH_MAIN_SetActorAnimAuto, ZKNSEARCH_MAIN_GetActorAnimSeq, ZKNSEARCH_MAIN_IsActorAnimActive, ZKNSEARCH_MAIN_SetActorVisible, ZKNSEARCH_MAIN_GetActorVisible, ZKNSEARCH_MAIN_SetActorObjMode, ZKNSEARCH_MAIN_SetActorSurfacePos, ZKNSEARCH_MAIN_GetActorSurfacePos, ZKNSEARCH_MAIN_SetActorBgPriority, ZKNSEARCH_MAIN_InitClact, ZKNSEARCH_MAIN_RegisterActorRes, ZKNSEARCH_MAIN_ReleaseActorRes, ZKNSEARCH_MAIN_CreateActors, ZKNSEARCH_MAIN_DeleteActorAt, ZKNSEARCH_MAIN_DeleteActors, ZKNSEARCH_MAIN_HideAllActors, ZKNSEARCH_MAIN_ShowResultActors, ZKNSEARCH_MAIN_ShowActorsPage1, ZKNSEARCH_MAIN_ShowActorsPage2, ZKNSEARCH_MAIN_ShowActorsPage3, ZKNSEARCH_MAIN_ShowActorsPage4, ZKNSEARCH_MAIN_ShowActorsPage5, ZKNSEARCH_MAIN_ShowEntry6Actor, ZKNSEARCH_MAIN_LayoutScrollActors, ZKNSEARCH_MAIN_UpdateScrollBarActor, ZKNSEARCH_MAIN_UpdateCursorActors, ZKNSEARCH_MAIN_PlaceColumnActor, ZKNSEARCH_MAIN_HideColumnActors, ZKNSEARCH_MAIN_PlaceColumnActor1, ZKNSEARCH_MAIN_PlaceColumnActors2, ZKNSEARCH_MAIN_PlaceColumnActor3, ZKNSEARCH_MAIN_PlaceColumnActor4, ZKNSEARCH_MAIN_PlaceScrollActor, ZKNSEARCH_MAIN_PlaceScrollActor2, ZKNSEARCH_MAIN_PlacePageActor, ZKNSEARCH_MAIN_MoveColumnActors, ZKNSEARCH_MAIN_MoveScrollActors, ZKNSEARCH_MAIN_PlaceProgressActor, ZKNSEARCH_MAIN_InitCursorMove, ZKNSEARCH_MAIN_DeleteCursorMove, ZKNSEARCH_MAIN_SetCursorTile, ZKNSEARCH_MAIN_PollMenuInput, ZKNSEARCH_MAIN_MoveCursor, ZKNSEARCH_MAIN_SetCursor, ZKNSEARCH_MAIN_DeselectCursor, ZKNSEARCH_MAIN_SelectCursor, ZKNSEARCH_MAIN_UpdateCursor, ZKNSEARCH_MAIN_WaitConfirmInput, ZKNSEARCH_MAIN_PollListInput, ZKNSEARCH_MAIN_PollListInput2
 * address:  0x021BC3F0
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   g_0784 0x021C0784 data
 *   g_0814 0x021C0814 data
 *   g_07F4 0x021C07F4 data
 *   g_0854 0x021C0854 data
 *   g_0874 0x021C0874 data
 *   g_0834 0x021C0834 data
 *   g_07D4 0x021C07D4 data
 *   g_07B4 0x021C07B4 data
 *   g_0794 0x021C0794 data
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetStatusFrameFileId 0x02027628 thumb
 *   APP_ICON_GetStatusAnimFileId 0x02027624 thumb
 *   APP_ICON_GetStatusDataFileId 0x0202762C thumb
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   BG_SYS_GetBuf 0x0204162C arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb
 *   PALANM_Delete  0x02021540  thumb
 *   GFL_USE_GetMainTaskList 0x020056BC thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete  0x02045808  arm
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   BLINK_PALANM_Create 0x0202E940 thumb
 *   BLINK_PALANM_LoadPalettes 0x0202E9AC thumb
 *   BGWINFRM_Create 0x0202C9B4 thumb
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_SetFrameData 0x0202CAC4 thumb
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BGWINFRM_Delete  0x0202CA0C  thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   d_021C0E80 0x021C0E80 data a4
 *   BG_SYS_DrawTile 0x02041090 arm
 *   GAME_DATA_ContainsRecentId 0x02012BF8 thumb
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   BGWINFRM_StartMove 0x0202CD64 thumb
 *   d_021C072E  0x021C072E  data  a2
 *   d_021C0720  0x021C0720  data  a1
 *   d_021C0894  0x021C0894  data  a4
 *   ZUKAN_TickCounter  0x021C93E4  thumb  ov212
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   ov067_id  0x00000043  data
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   ZUKAN_SAVE_GetViewMode  0x0200CA70  thumb
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   ZKNSEARCH_SYS_SetVramBanks  0x021BC3D4  thumb  ov210
 *   ZKNSEARCH_SYS_RegisterVBlank  0x021BC294  thumb  ov210
 *   ZKNSEARCH_SYS_RegisterHBlank  0x021BC318  thumb  ov210
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   ZKNSEARCH_SYS_UnregisterHBlank 0x021BC330 thumb ov210
 *   ZKNSEARCH_SYS_UnregisterVBlank 0x021BC2AC thumb ov210
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   BLINK_PALANM_Update  0x0202EA40  thumb
 *   ZUKAN_InitQuery  0x021C9380  thumb  ov212
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   ZUKAN_SEARCH_ENGINE_Create  0x021C9428  thumb  ov212
 *   ZUKAN_SEARCH_ENGINE_ReleaseWork  0x021C9460  thumb  ov212
 *   ZUKAN_SEARCH_ENGINE_Filter  0x021C9468  thumb  ov212
 *   UI_GetInputMode 0x020355C4 arm
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   ZKNSEARCH_MENU_InitFrameList 0x021C0234 thumb ov210
 *   FRAME_LIST_UpdateInit 0x021B7A64 thumb ov067
 *   FRAME_LIST_Update  0x021B7AB0  thumb  ov067
 *   ZKNSEARCH_RESULT_DeleteFrameList  0x021C0550  thumb  ov210
 *   ZKNSEARCH_LIST_InitFrameList 0x021C02DC thumb ov210
 *   ZKNSEARCH_LIST_InitFrameList2 0x021C0384 thumb ov210
 *   ZKNSEARCH_COND_InitFrameList 0x021C0434 thumb ov210
 *   ZKNSEARCH_RESULT_InitFrameList 0x021C04CC thumb ov210
 *   FRAME_LIST_SetCursor  0x021B93D4  thumb  ov067
 *   FRAME_LIST_GetScrollPos 0x021B93B8 thumb ov067
 *   GAME_DATA_SetRecentId 0x02012BE0 thumb
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   d_021C0900 0x021C0900 data a1
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   FRAME_LIST_GetPrinter 0x021B9394 thumb ov067
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_GetActorAutoAnim 0x0204B944 arm
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   ZKNSEARCH_SYS_GetVramBanks 0x021BC3E8 thumb ov210
 *   CLACT_InitSystem 0x0204A48C arm
 *   d_021C0990 0x021C0990 data a4 ov210
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   ZUKAN_CreateActor 0x021C940C thumb ov212
 *   data_021C09AC 0x021C09AC data
 *   data_021C0978 0x021C0978 data
 *   data_021C0960 0x021C0960 data
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   FRAME_LIST_ClampToScrollBar 0x021B8AE4 thumb ov067
 *   FRAME_LIST_GetCursor  0x021B93B0  thumb ov067
 *   FRAME_LIST_CanScrollDown  0x021B93C0  thumb ov067
 *   CURSOR_MOVE_Create 0x02025CD0 thumb
 *   CURSOR_MOVE_EnableInput 0x02025D1C thumb
 *   d_021C0B60 0x021C0B60 data a4
 *   d_021C0B14 0x021C0B14 data a4
 *   CURSOR_MOVE_Delete 0x02025D14 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   UI_SetInputMode 0x020355D8 arm
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   BLINK_PALANM_ResetPhase 0x0202EB04 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   FRAME_LIST_ShowCursor 0x021B940C thumb ov067
 *   d_021C0B3C 0x021C0B3C data a4
 *   d_021C0B24 0x021C0B24 data a4
 *   BMP_WIN_MakeScreen  0x02045374  arm  arm9
 *   BMP_WIN_GetBgLayer  0x02045730  arm  arm9
 *   CURSOR_MOVE_GetEntry  0x0202616C  thumb  arm9
 *   BG_SYS_SetPriority  0x0204047C  arm  arm9
 *   BLINK_PALANM_Delete  0x0202EA20  thumb  arm9
 */
struct Query;
struct TouchBarWindow;
#include "../arm9/game_data.h"
#include "../sdk_ioreg.h"
#include "../ov212/zukan_types.h"
#include "zknsearch_types.h"
#include "../ov067/touchbar.h"

struct PaletteFade;
struct PalAnmObj;
struct MsgBank;
struct GfFont;
struct WordSet;
struct U16Vec;
struct PrintSys;
struct Rec;
struct CodeIn;
struct CodeIn;
struct WinMgr;
struct Blk37;
struct Row;
struct Search;
struct CursorMove;
struct FrameList;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct StrObj;
struct Obj;
struct Actor;
struct Vec2;
struct PtS;
struct Bank;

struct Sound;


#include "../arm9/bg_sys.h"





typedef u32 (*StateFn)(u8 *);

struct ZknSearchBmpTemplate {
    u8 x, y, w, h, charW, charH;
};














typedef enum { kMsgWindowOffset = 0x1c4 } WindowOffset;








typedef struct { u32 words[7]; } ClactConfig;


typedef enum { YCoordMin = -2147483647, YCoordMax = 2147483647 } YCoord;

#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
#include "../arm9/app_icon.h"
#include "../arm9/palanm.h"
struct TcbList;
#include "../arm9/gfl_use.h"
struct GameData;
#include "../arm9/g2.h"
#include "../arm9/msgdata.h"
#include "../arm9/gf_font.h"
struct PrintQueue;
#include "../arm9/printsys.h"
struct Strbuf;
#include "../arm9/strbuf.h"
#include "../arm9/wordset.h"
struct BlinkPalAnm;
#include "../arm9/blink_palanm.h"
struct BgWinFrmWork;
#include "../arm9/bgwinfrm.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/mi_memory.h"
#include "../ov212/zukan.h"
#include "../arm9/gf_overlay.h"
#include "../arm9/gx.h"
struct ZukanSave;
#include "../arm9/zukan_save.h"
#include "../arm9/net.h"
#include "zknsearch_sys.h"
#include "../ov212/zukan_search_engine.h"
#include "../arm9/ui.h"
struct Cursor;
#include "../arm9/cursor_move.h"
#include "zknsearch_menu.h"
#include "../ov067/frame_list.h"
#include "zknsearch_result.h"
#include "zknsearch_list.h"
#include "zknsearch_cond.h"
#include "../arm9/bmp_win.h"
struct BmpWin;
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/clact.h"
struct DispVramCfg;
struct SysInit;
struct CursorVtbl;
struct CursorEntry;
#include "../arm9/key.h"
#include "../arm9/touchpanel.h"
void ZKNSEARCH_MAIN_InitBackgrounds(void);
void ZKNSEARCH_MAIN_DeleteBackgrounds(u32 work);
void ZKNSEARCH_MAIN_ShowLayerSetA(u32 work);
void ZKNSEARCH_MAIN_ShowLayerSetB(void);
void ZKNSEARCH_MAIN_LoadCommonGraphics(void);
void ZKNSEARCH_MAIN_InitPaletteAnim(char *p);
void ZKNSEARCH_MAIN_DeletePaletteAnim(u8 *p);
void ZKNSEARCH_MAIN_RequestPaletteFade(char *p,u8 b,u8 c);
void ZKNSEARCH_MAIN_SetBrightness(int mode);
void ZKNSEARCH_MAIN_ConfigureWindow(void);
void ZKNSEARCH_MAIN_ResetWindow(u32 work);
void ZKNSEARCH_MAIN_InitTextSystem(char *p);
u32 ZKNSEARCH_MAIN_DeleteTextSystem(u8 *p);
void ZKNSEARCH_MAIN_InitBlinkPalette(int p);
u32 ZKNSEARCH_MAIN_UpdateBlinkPalette(u8 *p);
void ZKNSEARCH_MAIN_InitScrollWindow(char *p);
void ZKNSEARCH_MAIN_DeleteScrollWindow(u8 *p);
void ZKNSEARCH_MAIN_LoadBgTile93(void *work);
void ZKNSEARCH_MAIN_LoadBgTile89(u8 *work);
void ZKNSEARCH_MAIN_LoadBgTile88(u8 *work);
void ZKNSEARCH_MAIN_LoadBgTile90(u8 *work);
void ZKNSEARCH_MAIN_LoadBgTile86(u8 *work);
void ZKNSEARCH_MAIN_LoadBgTile87(u8 *work);
void ZKNSEARCH_MAIN_LoadResultGraphics(char *p);
u32 ZKNSEARCH_MAIN_DeleteResultGraphics(u8 *p);
void ZKNSEARCH_MAIN_ShowResultLayout(char *p);
void ZKNSEARCH_MAIN_HideResultLayout(char *p);
void ZKNSEARCH_MAIN_SetFadeStateA(u8 *p);
void ZKNSEARCH_MAIN_SetFadeStateB(u8 *p);
void ZKNSEARCH_MAIN_EnterResultLayout(char *p);
void ZKNSEARCH_MAIN_StartScrollMove(char *p, int delta);
int ZKNSEARCH_MAIN_UpdateScrollMove(char *p);
u32 ZKNSEARCH_MAIN_GetListIndexA(u32 a, u32 b);
u32 ZKNSEARCH_MAIN_GetListIndexB(u32 a, u32 b);
u16 ZKNSEARCH_MAIN_LookupEntryId(char *work, int index);
u16 ZKNSEARCH_MAIN_LookupSavedEntryId(int work, int index);
void ZKNSEARCH_MAIN_NormalizeRecordByte(u8 *p);
void ZKNSEARCH_MAIN_DenormalizeRecordByte(u8 *p);
u32 ZKNSEARCH_MAIN_RunState(u8 *p);
u32 ZKNSEARCH_MAIN_InitSearchScreen(u8 *p);
int ZKNSEARCH_MAIN_ExitSearchScreen(char *p);
u32 ZKNSEARCH_MAIN_WaitFadeDone(u8 *p);
int ZKNSEARCH_MAIN_EnterSearchResult(u8 *p);
u32 ZKNSEARCH_MAIN_UpdateSearchResult(u8 *p);
u32 ZKNSEARCH_MAIN_ExitState(u8 *p);
u32 ZKNSEARCH_MAIN_EnterSearchEngine(u8 *p);
int ZKNSEARCH_MAIN_UpdateSearchEngine(unsigned char *p);
int ZKNSEARCH_MAIN_UpdateListInput(u8 *p);
int ZKNSEARCH_MAIN_EnterListPage1(u8 *p);
u32 ZKNSEARCH_MAIN_UpdateListPage1(u8 *p);
u32 ZKNSEARCH_MAIN_ExitListPage1(u32 p);
int ZKNSEARCH_MAIN_EnterListPage2(u8 *p);
u32 ZKNSEARCH_MAIN_UpdateListPage2(u8 *p);
u32 ZKNSEARCH_MAIN_ExitListPage2(u8 *p);
int ZKNSEARCH_MAIN_EnterListPage3(u8 *p);
u32 ZKNSEARCH_MAIN_UpdateListPage3(u8 *p);
u32 ZKNSEARCH_MAIN_ExitListPage3(u8 *p);
int ZKNSEARCH_MAIN_EnterListPage4(u8 *p);
u32 ZKNSEARCH_MAIN_UpdateListPage4(u8 *p);
u32 ZKNSEARCH_MAIN_ExitListPage4(u8 *p);
int ZKNSEARCH_MAIN_EnterListPage5(u8 *p);
u32 ZKNSEARCH_MAIN_UpdateListPage5(u8 *p);
u32 ZKNSEARCH_MAIN_ExitListPage5(u8 *p);
int ZKNSEARCH_MAIN_UpdateConfirmDialog(u8 *p);
int ZKNSEARCH_MAIN_UpdateMessageDialog(u8 *p);
u32 ZKNSEARCH_MAIN_EnterMessageDialog(u8 *p);
void ZKNSEARCH_MAIN_SelectEntry1(u8 *p, u32 v);
void ZKNSEARCH_MAIN_ClearEntry1(u8 *p);
void ZKNSEARCH_MAIN_ToggleEntry1(u8 *p, int n);
void ZKNSEARCH_MAIN_ClearEntry2(u8 *p);
void ZKNSEARCH_MAIN_ToggleEntry2(u8 *p, int n);
void ZKNSEARCH_MAIN_ClearEntry3(u8 *p);
void ZKNSEARCH_MAIN_ToggleEntry3(u8 *p, int index);
void ZKNSEARCH_MAIN_ClearEntry4(u8 *p);
void ZKNSEARCH_MAIN_ToggleEntry4(u8 *p, int index);
void ZKNSEARCH_MAIN_ClearEntry5(u8 *p);
u32 ZKNSEARCH_MAIN_EnterMessageState(u8 *p, u32 a, u32 b, u32 c);
u32 ZKNSEARCH_MAIN_EnterListState(u8 *p, u32 a);
void ZKNSEARCH_MAIN_ToggleSaveFlag(u8 *p);
void ZKNSEARCH_MAIN_InitBmpWindows(u8 *p);
void ZKNSEARCH_MAIN_DeleteBmpWindows(char *p);
void ZKNSEARCH_MAIN_UpdateBmpWindows(u8 *p);
void ZKNSEARCH_MAIN_PrintWindowText(u8 *p, int slot, u32 message, int x, int y, u16 color, u32 mode);
void ZKNSEARCH_MAIN_MakeWindowScreen(u8 *p);
void ZKNSEARCH_MAIN_InitWindowTexts(u8 *p);
void ZKNSEARCH_MAIN_UpdateResultTexts(u8 *p);
void ZKNSEARCH_MAIN_PrintLabel1(u8 *p);
void ZKNSEARCH_MAIN_ClearLabel1(u8 *p);
void ZKNSEARCH_MAIN_InitListTexts(u8 *p);
void ZKNSEARCH_MAIN_PrintEntryCount(u8 *p);
void ZKNSEARCH_MAIN_InitListTexts2(u8 *p);
void ZKNSEARCH_MAIN_PrintEntryCount2(u8 *p);
void ZKNSEARCH_MAIN_InitListTexts3(u8 *p);
void ZKNSEARCH_MAIN_PrintEntryCount3(u8 *p);
void ZKNSEARCH_MAIN_InitListTexts4(u8 *p);
void ZKNSEARCH_MAIN_PrintEntryCount4(u8 *p);
void ZKNSEARCH_MAIN_InitListTexts5(u8 *p);
void ZKNSEARCH_MAIN_PrintListRow(char *p, int *a, struct Strbuf *b);
void ZKNSEARCH_MAIN_TransferRowChars(int a, unsigned *p);
void ZKNSEARCH_MAIN_PrintMessageText(u8 *p, unsigned message);
void ZKNSEARCH_MAIN_PrintMessage11(void *a);
void ZKNSEARCH_MAIN_PrintMessage9(void *a);
void ZKNSEARCH_MAIN_PrintMessage10(void *a);
void ZKNSEARCH_MAIN_RedrawSubWindow(int p);
void ZKNSEARCH_MAIN_InitActorSystem(int p);
void ZKNSEARCH_MAIN_DeleteActorSystem(int p);
void ZKNSEARCH_MAIN_UpdateActorAnims(int p);
void ZKNSEARCH_MAIN_SetActorAnim(char *p, int idx, int v);
void ZKNSEARCH_MAIN_SetActorAnimAuto(int p, int i, int v);
int ZKNSEARCH_MAIN_GetActorAnimSeq(int p, int i);
int ZKNSEARCH_MAIN_IsActorAnimActive(int work, int actorIndex);
void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);
int ZKNSEARCH_MAIN_GetActorVisible(int p, int i);
void ZKNSEARCH_MAIN_SetActorObjMode(char *p, int idx, int flag);
void ZKNSEARCH_MAIN_SetActorSurfacePos(char *p, int idx, int a, short b, unsigned short c);
void ZKNSEARCH_MAIN_GetActorSurfacePos(char *p, int idx, short *outA, short *outB, unsigned short in);
void ZKNSEARCH_MAIN_SetActorBgPriority(int p, int i, unsigned v);
void ZKNSEARCH_MAIN_InitClact(void);
void ZKNSEARCH_MAIN_RegisterActorRes(ZknSearchWork *p);
void ZKNSEARCH_MAIN_ReleaseActorRes(u8 *p);
void ZKNSEARCH_MAIN_CreateActors(ZknSearchWork *p);
void ZKNSEARCH_MAIN_DeleteActorAt(int p, int i);
void ZKNSEARCH_MAIN_DeleteActors(int p);
void ZKNSEARCH_MAIN_HideAllActors(u8 *p);
unsigned ZKNSEARCH_MAIN_ShowResultActors(u8 *p);
void ZKNSEARCH_MAIN_ShowActorsPage1(int p);
void ZKNSEARCH_MAIN_ShowActorsPage2(char *p);
void ZKNSEARCH_MAIN_ShowActorsPage3(char *p);
void ZKNSEARCH_MAIN_ShowActorsPage4(char *p);
void ZKNSEARCH_MAIN_ShowActorsPage5(char *p);
void ZKNSEARCH_MAIN_ShowEntry6Actor(char *p);
void ZKNSEARCH_MAIN_LayoutScrollActors(char *p);
void ZKNSEARCH_MAIN_UpdateScrollBarActor(char *p);
void ZKNSEARCH_MAIN_UpdateCursorActors(u8 *p, int a);
void ZKNSEARCH_MAIN_PlaceColumnActor(char *p, int idx, int y, int flag);
void ZKNSEARCH_MAIN_HideColumnActors(char *p);
void ZKNSEARCH_MAIN_PlaceColumnActor1(char *p, int i, int flag);
void ZKNSEARCH_MAIN_PlaceColumnActors2(char *p, u8 a, u8 b);
void ZKNSEARCH_MAIN_PlaceColumnActor3(char *p, int y, int flag);
void ZKNSEARCH_MAIN_PlaceColumnActor4(char *p, int i, int flag);
void ZKNSEARCH_MAIN_PlaceScrollActor(char *ctx, int slot, int index);
void ZKNSEARCH_MAIN_PlaceScrollActor2(char *ctx);
void ZKNSEARCH_MAIN_PlacePageActor(char *ctx, unsigned long slot, YCoord y, int flag);
void ZKNSEARCH_MAIN_MoveColumnActors(int p, int v);
void ZKNSEARCH_MAIN_MoveScrollActors(char *p, int dx);
void ZKNSEARCH_MAIN_PlaceProgressActor(int p, int n);
void ZKNSEARCH_MAIN_InitCursorMove(char *ctx, int index);
void ZKNSEARCH_MAIN_DeleteCursorMove(int p);
void ZKNSEARCH_MAIN_SetCursorTile(int p, unsigned int a, unsigned int b);
u32 ZKNSEARCH_MAIN_PollMenuInput(int p);
void ZKNSEARCH_MAIN_MoveCursor(int p, unsigned b);
void ZKNSEARCH_MAIN_SetCursor(int p, unsigned b);
void ZKNSEARCH_MAIN_DeselectCursor(int p, unsigned a, unsigned b);
void ZKNSEARCH_MAIN_SelectCursor(int p, unsigned a, unsigned b);
void ZKNSEARCH_MAIN_UpdateCursor(int p, unsigned a, unsigned b);
int ZKNSEARCH_MAIN_WaitConfirmInput(unsigned char *ctx);
int ZKNSEARCH_MAIN_PollListInput(char *ctx);
int ZKNSEARCH_MAIN_PollListInput2(char *ctx);
extern const struct DispConfig g_0784;
extern const struct BgTemplate g_0814;
extern const struct BgTemplate g_07F4;
extern const struct BgTemplate g_0854;
extern const struct BgTemplate g_0874;
extern const struct BgTemplate g_0834;
extern const struct BgTemplate g_07D4;
extern const struct BgTemplate g_07B4;
extern const struct BgTemplate g_0794;
extern const char d_021C0E80[];
extern u16 d_021C072E[];
extern u8 d_021C0720[];
extern StateFn d_021C0894[];
extern u8 ov067_id[];
extern const struct ZknSearchBmpTemplate d_021C0900[];
extern const ClactConfig d_021C0990;
extern const struct ZknSearchActorTemplate data_021C09AC[15];
extern const struct ZknSearchActorTemplate data_021C0978;
extern const struct ZknSearchActorTemplate data_021C0960;
extern const unsigned d_021C0B60[], d_021C0B14[];
extern const unsigned d_021C0B3C[];
extern const unsigned d_021C0B24[];






void ZKNSEARCH_MAIN_InitBackgrounds(void)
{
    BG_SYS_Create(0x7B);
    {
        struct DispConfig d = g_0784;
        BG_SYS_SetGraphicsMode(&d);
    }
    {
        struct BgTemplate t = g_0814;
        BG_SYS_InitBgLayer(0, &t, 0);
    }
    {
        struct BgTemplate t = g_07F4;
        BG_SYS_InitBgLayer(1, &t, 0);
        BG_SYS_ClearSlot(1);
        BG_SYS_MarkTileDirty(1);
    }
    {
        struct BgTemplate t = g_0854;
        BG_SYS_InitBgLayer(2, &t, 0);
    }
    {
        struct BgTemplate t = g_0874;
        BG_SYS_InitBgLayer(3, &t, 0);
        BG_SYS_ClearSlot(3);
        BG_SYS_MarkTileDirty(3);
    }
    {
        struct BgTemplate t = g_0834;
        BG_SYS_InitBgLayer(4, &t, 0);
    }
    {
        struct BgTemplate t = g_07D4;
        BG_SYS_InitBgLayer(5, &t, 0);
        BG_SYS_ClearSlot(5);
        BG_SYS_MarkTileDirty(5);
    }
    {
        struct BgTemplate t = g_07B4;
        BG_SYS_InitBgLayer(6, &t, 0);
    }
    {
        struct BgTemplate t = g_0794;
        BG_SYS_InitBgLayer(7, &t, 0);
        BG_SYS_ClearSlot(7);
        BG_SYS_MarkTileDirty(7);
    }
    BG_SYS_SetMainPlaneVisible(0xF, 1);
    BG_SYS_SetSubPlaneVisible(0xF, 1);
}






void ZKNSEARCH_MAIN_DeleteBackgrounds(u32 work)
{
    BG_SYS_SetMainPlaneVisible(15, 0);
    BG_SYS_SetSubPlaneVisible(15, 0);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_Delete();
}






/*
 * Addresses are Black-image addresses.
 */
void ZKNSEARCH_MAIN_ShowLayerSetA(u32 work)
{
    BG_SYS_SetPriority(0, 1);
    BG_SYS_SetPriority(1, 0);
}






void ZKNSEARCH_MAIN_ShowLayerSetB(void)
{
    BG_SYS_SetPriority(0, 0);
    BG_SYS_SetPriority(1, 1);
}






/*
 * note 2026-10-05 (wD9r lane54): closed. ARC_UTIL_UploadBgCharFromHandle returns a value (as in the matched
 *   ov123 021D9D3C and ov110 021BB328); declared void, it let mwcc pool the 4s and zeros into r7/r5
 *   copies and took r7 from 0x807B. With the u32 return and an uninitialised u32 i set by the for statement it is EXACT.
 */
void ZKNSEARCH_MAIN_LoadCommonGraphics(void)
{
    void *h;
    u32 base;
    u32 i;
    u8 *scr;

    h = ARC_TOOL_CreateHandle(0x9F, 0x807B);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 0x49, 0, 0, 0xC0, 0x7B);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 0x4A, 4, 0, 0xA0, 0x7B);
    ARC_UTIL_RegisterObjCharFromHandle(h, 0x51, 0, 0, 0, 0x7B);
    ARC_UTIL_UploadBgCharFromHandle(h, 0x51, 1, 0, 0, 0, 0x7B);
    ARC_UTIL_UploadBgCharFromHandle(h, 0x51, 3, 0, 0, 0, 0x7B);
    ARC_UTIL_UploadBgCharFromHandle(h, 0x4F, 2, 0, 0, 0, 0x7B);
    ARC_UTIL_UploadBgCharFromHandle(h, 0x51, 5, 0, 0, 0, 0x7B);
    ARC_UTIL_UploadBgCharFromHandle(h, 0x50, 6, 0, 0, 0, 0x7B);
    ARC_UTIL_UploadBgCharFromHandle(h, 0x50, 4, 0, 0, 0, 0x7B);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x5F, 2, 0, 0, 0, 0x7B);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x5E, 4, 0, 0, 0, 0x7B);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x60, 6, 0, 0, 0, 0x7B);
    ARC_TOOL_DeleteHandle(h);
    h = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), 0x807B);
    base = ARC_UTIL_RegisterObjCharFromHandle(h, APP_ICON_GetStatusFrameFileId(), 0, 0, 0, 0x7B);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, APP_ICON_GetStatusAnimFileId(), 0, 0x1C0, 0x20, 0x7B);
    ARC_UTIL_UploadBgPaletteFromHandle(h, APP_ICON_GetStatusDataFileId(), 0, 0, 0, 0, 0x7B);
    BG_SYS_FillTileMap(0, 0, 0x15, 0x20, 3, 0xE);
    BG_SYS_MarkTileDirty(0);
    ARC_TOOL_DeleteHandle(h);
    scr = (u8 *)BG_SYS_GetBuf(0);
    for (i = 0; i < 0x60; i++) {
        ((u16 *)scr)[i + 0x2A0] += (u16)base;
    }
    BG_SYS_MarkTileDirty(0);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1E0, 0x20, 0x7B);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x1E0, 0x20, 0x7B);
}





void ZKNSEARCH_MAIN_InitPaletteAnim(char *work)
{
    ((ZknSearchWork *)work)->palAnm=PALANM_Create(123);
    PALANM_AllocSlotBuffers(*(struct PaletteFade * *)&((ZknSearchWork *)work)->palAnm,0,512,123);
    PALANM_AllocSlotBuffers(*(struct PaletteFade * *)&((ZknSearchWork *)work)->palAnm,1,512,123);
    PALANM_AllocSlotBuffers(*(struct PaletteFade * *)&((ZknSearchWork *)work)->palAnm,2,512,123);
    PALANM_AllocSlotBuffers(*(struct PaletteFade * *)&((ZknSearchWork *)work)->palAnm,3,512,123);
    PALANM_CopyHwPaletteToSlot(*(struct PaletteFade **)&((ZknSearchWork *)work)->palAnm,0,0,512);
    PALANM_CopyHwPaletteToSlot(*(struct PaletteFade **)&((ZknSearchWork *)work)->palAnm,1,0,512);
    PALANM_CopyHwPaletteToSlot(*(struct PaletteFade **)&((ZknSearchWork *)work)->palAnm,2,0,512);
    PALANM_CopyHwPaletteToSlot(*(struct PaletteFade **)&((ZknSearchWork *)work)->palAnm,3,0,512);
}






void ZKNSEARCH_MAIN_DeletePaletteAnim(u8 *work)
{
    PALANM_FreeSlotBuffers((PaletteFade *)((*(u32 *)&((ZknSearchWork *)work)->palAnm)), 0);
    PALANM_FreeSlotBuffers((PaletteFade *)((*(u32 *)&((ZknSearchWork *)work)->palAnm)), 1);
    PALANM_FreeSlotBuffers((PaletteFade *)((*(u32 *)&((ZknSearchWork *)work)->palAnm)), 2);
    PALANM_FreeSlotBuffers((PaletteFade *)((*(u32 *)&((ZknSearchWork *)work)->palAnm)), 3);
    PALANM_Delete((void *)(*(u32 *)&((ZknSearchWork *)work)->palAnm));
}





void ZKNSEARCH_MAIN_RequestPaletteFade(char *work,u8 startLevel,u8 endLevel)
{
    PALANM_RequestFade((PaletteFade *)(*(struct PalAnmObj * *)&((ZknSearchWork *)work)->palAnm),1,0xbfff,-14,startLevel,endLevel,0,(void *)GFL_USE_GetMainTaskList());
    PALANM_RequestFade((PaletteFade *)(*(struct PalAnmObj * *)&((ZknSearchWork *)work)->palAnm),2,0x7fef,-14,startLevel,endLevel,0,(void *)GFL_USE_GetMainTaskList());
    PALANM_RequestFade((PaletteFade *)(*(struct PalAnmObj * *)&((ZknSearchWork *)work)->palAnm),4,0xfe1f,-14,startLevel,endLevel,0,(void *)GFL_USE_GetMainTaskList());
    PALANM_RequestFade((PaletteFade *)(*(struct PalAnmObj * *)&((ZknSearchWork *)work)->palAnm),8,0xbfff,-14,startLevel,endLevel,0,(void *)GFL_USE_GetMainTaskList());
}






void ZKNSEARCH_MAIN_SetBrightness(int mode)
{
    if (mode == 1) {
        G2x_SetBlendAlpha_((unsigned int *)REG_BLDCNT_ADDR, 8, 4, 16, 6);
        G2x_SetBlendAlpha_((unsigned int *)REG_DB_BLDCNT_ADDR, 2, 6, 6, 10);
        return;
    }
    *(volatile u16 *)0x04001050 = 0;
}





static inline void inside(int wnd,int effect)
{
    u32 tmp=(*(volatile u16 *)REG_DB_WINOUT_ADDR & ~0x3f00) | ((u32)wnd<<8);
    if (effect) tmp|=0x20<<8;
    *(volatile u16 *)0x0400104a=(u16)tmp;
}





static inline void outside(int wnd,int effect)
{
    u32 tmp=(*(volatile u16 *)REG_DB_WINOUT_ADDR & ~0x3f) | (u32)wnd;
    if (effect) tmp|=0x20;
    *(volatile u16 *)0x0400104a=(u16)tmp;
}





static inline void visible(int window)
{
    *(volatile u32 *)0x04001000=(*(volatile u32 *)0x04001000 & ~0xe000) | (window<<13);
}





void ZKNSEARCH_MAIN_ConfigureWindow(void)
{
    inside(29,1);
    outside(31,1);
    visible(4);
}






void ZKNSEARCH_MAIN_ResetWindow(u32 work)
{
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
}





void ZKNSEARCH_MAIN_InitTextSystem(char *work)
{
    *(struct MsgBank * *)&((ZknSearchWork *)work)->msgBank = MSGDATA_CreateFromArchive(0, 2, 277, 123);
    ((ZknSearchWork *)work)->font = GF_FONT_Create(23, 0, 0, 0, 123);
    *(struct WordSet * *)&((ZknSearchWork *)work)->wordSet = WORDSET_CreateDefault(123);
    ((ZknSearchWork *)work)->printSys = (uptr)PRINTSYS_QUE_Create((unsigned int)123);
    *(struct U16Vec * *)&((ZknSearchWork *)work)->strBuf = (struct U16Vec *)STRBUF_Create(128, 123);
}






u32 ZKNSEARCH_MAIN_DeleteTextSystem(u8 *work)
{
    STRBUF_Delete((struct Strbuf *)(((ZknSearchWork *)work)->strBuf));
    PRINTSYS_QUE_Delete((struct PrintQueue *)(((ZknSearchWork *)work)->printSys));
    WORDSET_Delete((struct WordSet *)(((ZknSearchWork *)work)->wordSet));
    GF_FONT_Delete(((ZknSearchWork *)work)->font);
    return MSGDATA_Delete((struct MsgBank *)(((ZknSearchWork *)work)->msgBank));
}






void ZKNSEARCH_MAIN_InitBlinkPalette(int work)
{
    void *h = ARC_TOOL_CreateHandle(0x9f, 0x807b);

    ((ZknSearchWork *)work)->blinkPal = (sptr)BLINK_PALANM_Create(0x30, 0x10, 1, 0x7b);
    BLINK_PALANM_LoadPalettes((struct BlinkPalAnm *)(((ZknSearchWork *)work)->blinkPal), h, 0x49, 0x20, 0x30);
    ARC_TOOL_DeleteHandle(h);
}






u32 ZKNSEARCH_MAIN_UpdateBlinkPalette(u8 *work)
{
    return BLINK_PALANM_Delete((struct BlinkPalAnm *)(((ZknSearchWork *)work)->blinkPal));
}





void ZKNSEARCH_MAIN_InitScrollWindow(char *work)
{
    u32 base = BG_SYS_GetBuf(0);
    *(struct WinMgr * *)&((ZknSearchWork *)work)->scrollWin = (struct WinMgr *)BGWINFRM_Create(2, 1, 123);
    BGWINFRM_AddFrame((struct BgWinFrmWork *)(*(struct WinMgr * *)&((ZknSearchWork *)work)->scrollWin), 0, 0, 32, 3);
    BGWINFRM_SetFrameData((struct BgWinFrmWork *)(*(struct WinMgr * *)&((ZknSearchWork *)work)->scrollWin), 0, (void *)(base + 0x540));
    BG_SYS_SetTileEntry(0, 0, 0, 21, 32, 3, 0);
    BG_SYS_MarkTileDirty(0);
}






void ZKNSEARCH_MAIN_DeleteScrollWindow(u8 *work)
{
    BGWINFRM_Delete((struct BgWinFrmWork *)(*(struct WinMgr * *)&((ZknSearchWork *)work)->scrollWin));
}





void ZKNSEARCH_MAIN_LoadBgTile93(void *work)
{
    void *h = ARC_TOOL_CreateHandle(159, 0x807b);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 93, 0, 0, 0, 0, 123);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 92, 3, 0, 0, 0, 123);
    ARC_TOOL_DeleteHandle(h);
}






void ZKNSEARCH_MAIN_LoadBgTile89(u8 *work)
{
    void *h = ARC_TOOL_CreateHandle(159, 0x807b);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 89, 3, 0, 0, 0, 123);
    ARC_TOOL_DeleteHandle(h);
}






void ZKNSEARCH_MAIN_LoadBgTile88(u8 *work)
{
    void *h = ARC_TOOL_CreateHandle(159, 0x807b);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 88, 3, 0, 0, 0, 123);
    ARC_TOOL_DeleteHandle(h);
}






void ZKNSEARCH_MAIN_LoadBgTile90(u8 *work)
{
    void *h = ARC_TOOL_CreateHandle(159, 0x807b);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 90, 3, 0, 0, 0, 123);
    ARC_TOOL_DeleteHandle(h);
}






void ZKNSEARCH_MAIN_LoadBgTile86(u8 *work)
{
    void *h = ARC_TOOL_CreateHandle(159, 0x807b);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 86, 3, 0, 0, 0, 123);
    ARC_TOOL_DeleteHandle(h);
}






void ZKNSEARCH_MAIN_LoadBgTile87(u8 *work)
{
    void *h = ARC_TOOL_CreateHandle(159, 0x807b);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 87, 3, 0, 0, 0, 123);
    ARC_TOOL_DeleteHandle(h);
}





void ZKNSEARCH_MAIN_LoadResultGraphics(char *work)
{
    void *out;
    void *h;
    void *blob;
    ((ZknSearchWork *)work)->resultGraphics = GFL_HEAP_Alloc(123, 384, 0, d_021C0E80, 0x3b0);
    h = ARC_TOOL_CreateHandle(159, 0x807b);
    blob = ARC_UTIL_LoadPaletteDataFromHandle(h, 91, 0, (void **)&out, 0x807b);
    MIi_CpuCopy16((char *)out + 12, ((ZknSearchWork *)work)->resultGraphics, 384);
    GFL_HEAP_Free(blob);
    ARC_TOOL_DeleteHandle(h);
}






u32 ZKNSEARCH_MAIN_DeleteResultGraphics(u8 *work)
{
    return GFL_HEAP_Free((void *)(((ZknSearchWork *)work)->resultGraphics));
}





void ZKNSEARCH_MAIN_ShowResultLayout(char *work)
{
    BG_SYS_DrawTile(1, ((ZknSearchWork *)work)->resultGraphics, 0, 17, 32, 6);
    BG_SYS_MarkTileDirty(1);
    ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 2, 15);
    ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 3, 14);
    if (GAME_DATA_ContainsRecentId((struct GameData *)(**(int * *)&((ZknSearchWork *)work)->save), 16) == 1)
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 4, 22);
    else
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 4, 21);
    ZKNSEARCH_MAIN_SetActorBgPriority((sptr)work, 2, 1);
    ZKNSEARCH_MAIN_SetActorBgPriority((sptr)work, 3, 1);
    ZKNSEARCH_MAIN_SetActorBgPriority((sptr)work, 4, 1);
}





void ZKNSEARCH_MAIN_HideResultLayout(char *work)
{
    ZKNSEARCH_MAIN_SetActorVisible((sptr)((u8 *)work), 8, 0);
    BG_SYS_SetTileEntry(1, 0, 0, 17, 32, 6, 0);
    BG_SYS_MarkTileDirty(1);
    ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 2, 1);
    ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 3, 0);
    if (GAME_DATA_ContainsRecentId((struct GameData *)(**(int * *)&((ZknSearchWork *)work)->save), 16) == 1)
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 4, 7);
    else
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 4, 6);
    ZKNSEARCH_MAIN_SetActorBgPriority((sptr)work, 2, 0);
    ZKNSEARCH_MAIN_SetActorBgPriority((sptr)work, 3, 0);
    ZKNSEARCH_MAIN_SetActorBgPriority((sptr)work, 4, 0);
    ZKNSEARCH_MAIN_RedrawSubWindow((sptr)work);
}





void ZKNSEARCH_MAIN_SetFadeStateA(u8 *work)
{
    work[0x2b8] = 1;
}





/*
 * trailing: 2-byte alignment padding at 0x021BCDA2.
 */
void ZKNSEARCH_MAIN_SetFadeStateB(u8 *work)
{
    work[0x2b8] = 2;
    BG_SYS_ClearSlot(1);
    BG_SYS_ClearSlot(3);
    BG_SYS_ClearSlot(5);
    BG_SYS_MarkTileDirty(1);
    BG_SYS_MarkTileDirty(3);
    BG_SYS_MarkTileDirty(5);
    BG_SYS_SetTileEntry(0, 0, 0, 0, 32, 21, 0);
    BG_SYS_MarkTileDirty(0);
    BG_SYS_ChangeScroll(1, 3, 0);
    BG_SYS_ChangeScroll(5, 3, 0);
}





/*
 * trailing: 2-byte alignment padding at 0x021BCE0A.
 * BEE38 parameters widened: original call uses signed full-width loads.
 */
void ZKNSEARCH_MAIN_EnterResultLayout(char *work)
{
    unsigned int i;
    short x, y;
    BG_SYS_ChangeScroll(4, 3, 48);
    BG_SYS_ChangeScroll(7, 3, 48);
    BGWINFRM_PutFrame((struct BgWinFrmWork *)(*(struct WinMgr * *)&((ZknSearchWork *)work)->scrollWin), 0, 0, 27);
    BGWINFRM_UpdateMoves((struct BgWinFrmWork *)(*(struct WinMgr * *)&((ZknSearchWork *)work)->scrollWin));
    for (i = 2; i <= 4; i++) {
        ZKNSEARCH_MAIN_GetActorSurfacePos(work, i, &x, &y, 0);
        y += 48;
        ZKNSEARCH_MAIN_SetActorSurfacePos(work, i, x, y, 0);
    }
}





void ZKNSEARCH_MAIN_StartScrollMove(char *work, int delta)
{
    int magnitude;
    int direction;
    ((ZknSearchWork *)work)->scrollRemaining = 48;
    ((ZknSearchWork *)work)->scrollDelta = delta;
    magnitude = delta < 0 ? -delta : delta;
    direction = delta / (delta < 0 ? -delta : delta);
    BGWINFRM_StartMove((struct BgWinFrmWork *)(*(struct WinMgr * *)&((ZknSearchWork *)work)->scrollWin), 0, 0, direction, 48 / magnitude);
}





/*
 * BEE38 parameters widened: original call uses signed full-width loads.
 */
int ZKNSEARCH_MAIN_UpdateScrollMove(char *work)
{
    unsigned int i;
    short x, y;
    int magnitude;
    if (((ZknSearchWork *)work)->scrollRemaining == 0) return 0;
    BGWINFRM_UpdateMoves((struct BgWinFrmWork *)(*(struct WinMgr * *)&((ZknSearchWork *)work)->scrollWin));
    BG_SYS_ChangeScroll(4, 4, ((ZknSearchWork *)work)->scrollDelta);
    BG_SYS_ChangeScroll(7, 4, ((ZknSearchWork *)work)->scrollDelta);
    for (i = 2; i <= 4; i++) {
        ZKNSEARCH_MAIN_GetActorSurfacePos(work, i, &x, &y, 0);
        y += ((ZknSearchWork *)work)->scrollDelta;
        ZKNSEARCH_MAIN_SetActorSurfacePos(work, i, x, y, 0);
    }
    magnitude = ((ZknSearchWork *)work)->scrollDelta;
    if (magnitude < 0) magnitude = -magnitude;
    ((ZknSearchWork *)work)->scrollRemaining -= (u16)magnitude;
    return 1;
}





u32 ZKNSEARCH_MAIN_GetListIndexA(u32 work, u32 index)
{
    return index;
}





u32 ZKNSEARCH_MAIN_GetListIndexB(u32 work, u32 index)
{
    return index;
}






u16 ZKNSEARCH_MAIN_LookupEntryId(char *work, int index)
{
    (void)work;
    return d_021C072E[index];
}






/*
 * Meeting-room / map index helper: halfword lookup into the table at
 * 0x021C072E by the second argument.  Blocker target of ZKNSEARCH_MAIN_PrintEntryCount3.
 *
 * Addresses are Black-image addresses.
 */
u16 ZKNSEARCH_MAIN_LookupSavedEntryId(int work, int index)
{
    (void)work;
    return d_021C072E[index];
}






/*
 * 2026-10-05 (wD5 lane01): EXACT. The three co-live values are coloured in declaration order
 *   (lowest register first): declare i, v, rec in that order at the top.
 * 2026-10-05 (wD4 lane16): also tried a do/while with u32 counter declared after the pointer, and a u8 counter with break: both worse (17 and 27 bytes). Residue unchanged (rec=r4/counter=r2 in image).
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (8 bytes): image rec=r4, counter=r2; ours rec=r2, counter=r4. Colouring looks priority ordered (counter gets the callee-saved register in ours); no source form found that lowers the pointer's priority.
 *
 * 2026-10-02: 44 bytes, size exact, one relocation resolved.  Only the colours
 * differ: the image keeps the record pointer in r4 and the loop counter in r2;
 * the compile swaps them (counter r4, pointer r2).  Tried: counter declared
 * first, int counter, do/while, break form, u32 value local, early return.
 *
 * Addresses are Black-image addresses.
 */
void ZKNSEARCH_MAIN_NormalizeRecordByte(u8 *work)
{
    u32 i;
    u8 v;
    u8 *rec;

    rec = *(u8 **)(*(u8 **)work + 8);
    v = rec[6];
    if (v != 0xff) {
        for (i = 0; i < 14; i++) {
            if (v == d_021C0720[i]) {
                rec[6] = i;
                return;
            }
        }
    }
}






void ZKNSEARCH_MAIN_DenormalizeRecordByte(u8 *work)
{
    u8 *r0 = *(u8 * *)&((ZknSearchWork *)work)->save;
    u8 *r2 = *(u8 * *)&((ZknSearchSave *)r0)->record;
    u8 r1 = r2[6];

    if (r1 != 0xff) {
        r2[6] = d_021C0720[r1];
    }
}






u32 ZKNSEARCH_MAIN_RunState(u8 *work)
{
    u32 s = ((ZknSearchWork *)work)->state;

    s = d_021C0894[s](work);
    ((ZknSearchWork *)work)->state = s;
    if (s == 0x1b) {
        return 0;
    }
    ZKNSEARCH_MAIN_UpdateActorAnims((sptr)work);
    ZKNSEARCH_MAIN_UpdateBmpWindows(work);
    ZUKAN_TickCounter(2, 6, (u32 *)(work + 0x2c4));
    return 1;
}






u32 ZKNSEARCH_MAIN_InitSearchScreen(u8 *work)
{
    u32 z;
    uptr ra = REG_BLDCNT_ADDR;
    uptr rb = REG_DB_BLDCNT_ADDR;
    int m;

    GF_OVERLAY_Load((uptr)ov067_id);
    z = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)ra = z;
    *(volatile u16 *)rb = z;
    BG_SYS_SetLcdSwap(0);
    m = -16;
    GXx_SetMasterBrightness_((volatile u16 *)(ra + 0x1c), m);
    GXx_SetMasterBrightness_((volatile u16 *)(rb + 0x1c), m);
    if (ZUKAN_SAVE_GetViewMode((struct ZukanSave *)(((ZknSearchWork *)work)->save->block)) == 1) {
        ((ZknSearchWork *)work)->save->record[0] = z;
    } else {
        ((ZknSearchWork *)work)->save->record[0] = 1;
    }
    ZKNSEARCH_SYS_SetVramBanks();
    ZKNSEARCH_MAIN_InitBackgrounds();
    ZKNSEARCH_MAIN_LoadCommonGraphics();
    ZKNSEARCH_MAIN_InitTextSystem((char *)work);
    ZKNSEARCH_MAIN_InitBmpWindows(work);
    ZKNSEARCH_MAIN_InitActorSystem((sptr)work);
    ZKNSEARCH_MAIN_InitBlinkPalette((sptr)work);
    GFL_NET_RefreshWmIconAtTopRight(1, 0x7b);
    ZKNSEARCH_MAIN_InitScrollWindow((char *)work);
    ZKNSEARCH_MAIN_EnterResultLayout((char *)work);
    ZKNSEARCH_MAIN_InitPaletteAnim((char *)work);
    ZKNSEARCH_MAIN_RequestPaletteFade((char *)work, 16, 16);
    ZKNSEARCH_MAIN_LoadResultGraphics((char *)work);
    ZKNSEARCH_MAIN_ConfigureWindow();
    ZKNSEARCH_SYS_RegisterVBlank(work);
    ZKNSEARCH_SYS_RegisterHBlank(work);
    work[0x2b9] = 0xff;
    ZKNSEARCH_MAIN_NormalizeRecordByte(work);
    return 3;
}





/*
 * volatile: hardware stores at 0x021BD0D8 and 0x021BD0DC.
 */
int ZKNSEARCH_MAIN_ExitSearchScreen(char *work)
{
    if (ZKNSEARCH_MAIN_UpdateScrollMove(work) == 1 || PALANM_GetFadeRequestBits((const PaletteFade *)(*(char * *)&((ZknSearchWork *)work)->palAnm)) != 0) return 1;
    ZKNSEARCH_SYS_UnregisterHBlank((u8 *)work);
    ZKNSEARCH_MAIN_ResetWindow(ZKNSEARCH_SYS_UnregisterVBlank((u8 *)work));
    ZKNSEARCH_MAIN_DeleteResultGraphics((u8 *)work);
    ZKNSEARCH_MAIN_DeleteScrollWindow((u8 *)work);
    ZKNSEARCH_MAIN_DeletePaletteAnim((u8 *)work);
    ZKNSEARCH_MAIN_UpdateBlinkPalette((u8 *)work);
    ZKNSEARCH_MAIN_DeleteActorSystem((sptr)work);
    ZKNSEARCH_MAIN_DeleteBmpWindows(work);
    ZKNSEARCH_MAIN_DeleteBackgrounds(ZKNSEARCH_MAIN_DeleteTextSystem((u8 *)work));
    GXx_SetMasterBrightness_((void *)REG_MASTER_BRIGHT_ADDR, -16);
    GXx_SetMasterBrightness_((void *)REG_DB_MASTER_BRIGHT_ADDR, -16);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    GF_OVERLAY_Unload((sptr)ov067_id);
    return 27;
}






u32 ZKNSEARCH_MAIN_WaitFadeDone(u8 *work)
{
    if (PALANM_GetFadeRequestBits((const PaletteFade *)((const char *)(((ZknSearchWork *)work)->palAnm))) == 0) {
        return ((ZknSearchWork *)work)->returnState2;
    }
    return 2;
}





int ZKNSEARCH_MAIN_EnterSearchResult(u8 *work)
{
    if (PALANM_GetFadeRequestBits((const PaletteFade *)(*(char * *)&((ZknSearchWork *)work)->palAnm)) != 0) return 3;
    ZKNSEARCH_MAIN_SetBrightness(1);
    ZKNSEARCH_MAIN_LoadBgTile93(work);
    ZKNSEARCH_MAIN_UpdateResultTexts(work);
    ZKNSEARCH_MAIN_ShowLayerSetA(ZKNSEARCH_MAIN_ShowResultActors(work));
    ZKNSEARCH_MAIN_SetFadeStateA(work);
    if (work[0x2b9] == 255) {
        ZKNSEARCH_MAIN_InitCursorMove((char *)work, 0);
        GXx_SetMasterBrightness_((void *)REG_MASTER_BRIGHT_ADDR, 0);
        GXx_SetMasterBrightness_((void *)REG_DB_MASTER_BRIGHT_ADDR, 0);
        ZKNSEARCH_MAIN_StartScrollMove((char *)work, -8);
        ZKNSEARCH_MAIN_RequestPaletteFade((char *)work, 16, 0);
        return 4;
    } else {
        ZKNSEARCH_MAIN_InitCursorMove((char *)work, work[0x2b9]);
        return 4;
    }
}






u32 ZKNSEARCH_MAIN_UpdateSearchResult(u8 *work)
{
    if (ZKNSEARCH_MAIN_UpdateScrollMove((char *)work) == 1 || PALANM_GetFadeRequestBits((const PaletteFade *)((const char *)(*(u32 *)&((ZknSearchWork *)work)->palAnm))) != 0) {
        return 4;
    }
    switch (ZKNSEARCH_MAIN_PollMenuInput((sptr)work)) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 0, 0, ZKNSEARCH_MAIN_EnterListState(work, 9));
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 0, 1, ZKNSEARCH_MAIN_EnterListState(work, 12));
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 0, 2, ZKNSEARCH_MAIN_EnterListState(work, 15));
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 0, 3, ZKNSEARCH_MAIN_EnterListState(work, 18));
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 0, 4, ZKNSEARCH_MAIN_EnterListState(work, 21));
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 0, 5, 7);
    case 6:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 0, 6, 6);
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x646);
        ZKNSEARCH_MAIN_ToggleSaveFlag(work);
        break;
    case 8:
        GFL_USE_PlaySeDefaultVolume(0x556);
        ((ZknSearchWork *)work)->save->mode = 2;
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 3, 8);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 3, 0x1a);
    case 9:
        GFL_USE_PlaySeDefaultVolume(0x551);
        ZKNSEARCH_MAIN_DenormalizeRecordByte(work);
        ((ZknSearchWork *)work)->save->mode = 1;
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 2, 9);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 2, 0x1a);
    case (u32)-4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case (u32)-3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case (u32)-2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        ZKNSEARCH_MAIN_DenormalizeRecordByte(work);
        ((ZknSearchWork *)work)->save->mode = 1;
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 2, 9);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 2, 0x1a);
    }
    BLINK_PALANM_Update((struct BlinkPalAnm *)(((ZknSearchWork *)work)->blinkPal));
    return 4;
}






u32 ZKNSEARCH_MAIN_ExitState(u8 *work)
{
    ZKNSEARCH_MAIN_SetFadeStateB(work);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 7, 0);
    ZKNSEARCH_MAIN_DeleteCursorMove((sptr)work);
    return ((ZknSearchWork *)work)->returnState;
}






u32 ZKNSEARCH_MAIN_EnterSearchEngine(u8 *work)
{
    u32 *ctx = *(u32 * *)&((ZknSearchWork *)work)->save;

    ZUKAN_InitQuery((struct Blk37 *)ctx[1], (u8 *)ctx[2]);
    ZKNSEARCH_MAIN_UpdateResultTexts(work);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 7, 0);
    return 4;
}






/*
 * 2026-10-05 (wD5 lane14): EXACT. ZKNSEARCH_MAIN_PlaceProgressActor takes the state byte as a
 *   second argument (its matched body uses n); the r1 load was that argument.
 * 2026-10-05 (wD4 lane16): re-read; still the single r1/r0 load at the 0x79 test after ZUKAN_SEARCH_ENGINE_ReleaseWork. No change tried that moved it (callee arity cannot explain it: the load is after the call).
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (2 bytes: ldrb r1/cmp r1,#0x79 in the image, r0 in ours). Also tried the 0x79 test through a u32 local and p[0x2BB]++ for the tail; no change. Lesson from ZKNSEARCH_MAIN_UpdateMessageDialog (same overlay): a callee that takes the byte as a second argument with r0 untouched explains an r1 load, but no call here does.
 *
 * 2026-10-02 (wave C2 lane 03): re-checked, still the same two bytes at
 * 0x021BD448: the image loads the 0x2bb byte into r1 before `cmp #0x79`.
 * The path into this compare falls through from `ZUKAN_SEARCH_ENGINE_ReleaseWork(p[0x2cc])`;
 * no later call takes the byte as a second argument (checked
 * 021BED04, 021BED10, 021BFE84).  Next idea: look at the callers' use of
 * ZUKAN_SEARCH_ENGINE_ReleaseWork with a second argument.
 *
 * Re-verified 2026-09-27 (DIFF fixer lane): size-exact, 2 concrete bytes.
 * The three func_021C94xx symbols were wrongly hinted ov210; they live in
 * ov212's window (ov212 is co-resident with ov210), so the hints are
 * corrected to ov212 and 13 of 14 relocations now resolve.  The two differing
 * bytes are the image's `ldrb r1,[r4,r5] / cmp r1,#0x79` versus the compile's
 * `ldrb r0,... / cmp r0,#0x79` (the dead argument register is reused for the
 * load) -- the same allocator tell as HALL_OF_FAME_DeleteMonSprite/ZKNSEARCH_MAIN_PrintEntryCount3.  The last
 * site, ZUKAN_SEARCH_ENGINE_ReleaseWork, is a Thumb-shaped linker stub (`ldr r3,[pc,#0];
 * bx r3; .word 0x020307B0`) that disasm emits as an unlabelled .word run, so
 * the `veneer` class cannot attest it; only the ARM stub shape attests
 * (docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md).
 *
 * Update 2026-09-27 (recursive MATCH unblocker): 0x021C9460 was matched
 * bottom-up as src/matched/ZUKAN_SEARCH_ENGINE_ReleaseWork.c (EXACT, pkt_ov212_021C9460),
 * so the +0096 site now resolves `matched` and all 14 relocations resolve.
 * The verdict is unchanged DIFF on the same two concrete bytes (the r1/r0
 * allocator tell above); target matching cannot promote it.
 */
int ZKNSEARCH_MAIN_UpdateSearchEngine(unsigned char *work)
{
    unsigned short v;
    int w;
    int r;

    if (work[0x2BB] == 0) {
        GFL_USE_PlaySeDefaultVolume(0x63F);
        ZKNSEARCH_MAIN_ShowResultLayout((char *)work);
        ZKNSEARCH_MAIN_PrintMessage11(work);
        ZKNSEARCH_MAIN_ClearLabel1(work);
    }
    if (work[0x2BB] == 0x64)
        GFL_USE_StopAllSe();
    if (work[0x2BB] == 1) {
        ZKNSEARCH_MAIN_DenormalizeRecordByte(work);
        *(int *)(work + 0x2CC) =
            (sptr)ZUKAN_SEARCH_ENGINE_Create((struct Search *)(*(int *)(*(int *)work + 4)), (struct Query *)(*(int *)(*(int *)work + 8)), 0x807B);
        *(int *)(work + 0x2D0) = 0;
    }
    if (work[0x2BB] >= 2) {
        if (*(int *)(work + 0x2D0) == 0) {
            r = ZUKAN_SEARCH_ENGINE_Filter((struct Search *)(*(int *)(work + 0x2CC)), 0x69, &v, (u16 **)(&w));
            *(int *)(work + 0x2D0) = r;
            if (r == 1) {
                *(unsigned short *)(*(int *)work + 0x14) = v;
                *(int *)(*(int *)work + 0x10) = w;
                ZUKAN_SEARCH_ENGINE_ReleaseWork(*(int *)(work + 0x2CC));
            }
        }
    }
    if (work[0x2BB] == 0x79) {
        if (*(int *)(work + 0x2D0) == 1) {
            if (*(unsigned short *)(*(int *)work + 0x14) != 0) {
                GFL_USE_PlaySeDefaultVolume(0x76F);
                ZKNSEARCH_MAIN_PrintMessage9(work);
            } else {
                GFL_USE_PlaySeDefaultVolume(0x557);
                ZKNSEARCH_MAIN_PrintMessage10(work);
            }
            work[0x2BB] = 0;
            return 8;
        }
    } else {
        ZKNSEARCH_MAIN_PlaceProgressActor((sptr)work, work[0x2BB]);
        work[0x2BB] = work[0x2BB] + 1;
    }
    return 7;
}





int ZKNSEARCH_MAIN_UpdateListInput(u8 *work)
{
    if (ZKNSEARCH_MAIN_WaitConfirmInput(work) == 1) {
        u8 *head = *(u8 * *)&((ZknSearchWork *)work)->save;
        if (((ZknSearchSave *)head)->state != 0) {
            ((ZknSearchSave *)head)->mode = 0;
            return 26;
        }
        ZKNSEARCH_MAIN_HideResultLayout((char *)work);
        ZKNSEARCH_MAIN_PrintLabel1(work);
        if (UI_GetInputMode() == 1)
            CURSOR_MOVE_SetState(((ZknSearchWork *)work)->cursorMove, 0);
        else
            CURSOR_MOVE_SetState(((ZknSearchWork *)work)->cursorMove, 1);
        ZKNSEARCH_MAIN_NormalizeRecordByte(work);
        return 4;
    }
    return 8;
}





int ZKNSEARCH_MAIN_EnterListPage1(u8 *work)
{
    switch (work[0x2BA]) {
    case 0:
        work[0x2B9] = 0;
        ZKNSEARCH_MAIN_SetBrightness(1);
        ZKNSEARCH_MAIN_InitListTexts(work);
        ZKNSEARCH_MENU_InitFrameList((char *)work);
        work[0x2BA]++;
    case 1:
        if (FRAME_LIST_UpdateInit(((ZknSearchWork *)work)->frameList) == 0) {
            ZKNSEARCH_MAIN_ShowActorsPage1((sptr)work);
            ZKNSEARCH_MAIN_LoadBgTile89(work);
            ZKNSEARCH_MAIN_ShowLayerSetB();
            ZKNSEARCH_MAIN_SetFadeStateA(work);
            work[0x2BA] = 0;
            return 10;
        }
    }
    return 9;
}






u32 ZKNSEARCH_MAIN_UpdateListPage1(u8 *work)
{
    int r5 = FRAME_LIST_Update((struct FrameList *)(*(u32 *)&((ZknSearchWork *)work)->frameList));

    if (r5 != -1) {
        switch (r5) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            if (UI_GetInputMode() == 0) {
                GFL_USE_PlaySeDefaultVolume(0x54c);
                ZKNSEARCH_MAIN_SelectEntry1(work, r5);
            }
            break;
        }
    } else {
    r5 = ZKNSEARCH_MAIN_PollListInput((char *)work);
    switch (r5) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x551);
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 2, 9);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 2, 11);
    case 8:
        GFL_USE_PlaySeDefaultVolume(0x551);
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 2, 9);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 2, 11);
    case 9:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        ZKNSEARCH_MAIN_ClearEntry1(work);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        ZKNSEARCH_MAIN_SelectEntry1(work, r5 - 1);
        break;
    }
    }
    return 10;
}






u32 ZKNSEARCH_MAIN_ExitListPage1(u32 work)
{
    ZKNSEARCH_MAIN_SetFadeStateB((u8 *)work);
    ZKNSEARCH_MAIN_HideAllActors((u8 *)work);
    ZKNSEARCH_RESULT_DeleteFrameList((u8 *)work);
    return 3;
}





/*
 * prototype: 021BCAF8 receives the caller's explicit r0 even though its body ignores it; BC5C8 reads no inputs.
 */
int ZKNSEARCH_MAIN_EnterListPage2(u8 *work)
{
    switch (work[0x2BA]) {
    case 0:
        work[0x2B9] = 1;
        ZKNSEARCH_MAIN_SetBrightness(1);
        ZKNSEARCH_MAIN_InitListTexts2(work);
        ZKNSEARCH_LIST_InitFrameList((char *)work);
        work[0x2BA]++;
    case 1:
        if (FRAME_LIST_UpdateInit(((ZknSearchWork *)work)->frameList) == 0) {
            ZKNSEARCH_MAIN_UpdateCursorActors(work, 0);
            ZKNSEARCH_MAIN_ShowActorsPage2((char *)work);
            ZKNSEARCH_MAIN_LoadBgTile88(work);
            ZKNSEARCH_MAIN_ShowLayerSetB();
            ZKNSEARCH_MAIN_SetFadeStateA(work);
            work[0x2BA] = 0;
            return 13;
        }
    }
    return 12;
}






u32 ZKNSEARCH_MAIN_UpdateListPage2(u8 *work)
{
    u32 ret = 13;
    u32 r5 = FRAME_LIST_Update((struct FrameList *)(*(u32 *)&((ZknSearchWork *)work)->frameList));

    switch (r5) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        if (UI_GetInputMode() == 0) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZKNSEARCH_MAIN_ToggleEntry1(work, r5);
        }
        break;
    case (u32)-12:
        break;
    case (u32)-11:
    case (u32)-10:
    case (u32)-9:
    case (u32)-8:
        ZKNSEARCH_MAIN_UpdateCursorActors(work, 0);
        break;
    case (u32)-7:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 6, 12);
        work[0x2c1] = 6;
        ((ZknSearchWork *)work)->dialogState = 0;
        ((ZknSearchWork *)work)->returnState = ret;
        ret = 0x18;
        break;
    case (u32)-6:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 5, 13);
        work[0x2c1] = 5;
        ((ZknSearchWork *)work)->dialogState = 0;
        ((ZknSearchWork *)work)->returnState = ret;
        ret = 0x18;
        break;
    case (u32)-5:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 6, 12);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 6, 13);
    case (u32)-4:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 5, 13);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 5, 13);
    case (u32)-3:
    case (u32)-2:
        ZKNSEARCH_MAIN_HideColumnActors((char *)work);
        ZKNSEARCH_MAIN_PlaceScrollActor((char *)work, 0, (*(u8 **)(*(u8 * *)&((ZknSearchWork *)work)->save + 8))[2]);
        work[0x2c1] = 0x39;
        ((ZknSearchWork *)work)->dialogState = 1;
        ((ZknSearchWork *)work)->returnState = ret;
        ret = 0x18;
        break;
    case (u32)-1:
        r5 = ZKNSEARCH_MAIN_PollListInput((char *)work);
        switch (r5) {
        case 0:
            GFL_USE_PlaySeDefaultVolume(0x551);
            ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 2, 9);
            return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 2, 14);
        case 8:
            GFL_USE_PlaySeDefaultVolume(0x551);
            ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 2, 9);
            return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 2, 14);
        case 9:
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZKNSEARCH_MAIN_ClearEntry2(work);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZKNSEARCH_MAIN_UpdateCursorActors(work, 0);
            ZKNSEARCH_MAIN_ToggleEntry1(work, r5 - 1);
            break;
        }
        break;
    }
    ZKNSEARCH_MAIN_UpdateScrollBarActor((char *)work);
    return ret;
}






u32 ZKNSEARCH_MAIN_ExitListPage2(u8 *work)
{
    ZKNSEARCH_MAIN_SetFadeStateB(work);
    ZKNSEARCH_MAIN_HideAllActors(work);
    ZKNSEARCH_RESULT_DeleteFrameList(work);
    return 3;
}





int ZKNSEARCH_MAIN_EnterListPage3(u8 *work)
{
    switch (work[0x2BA]) {
    case 0:
        work[0x2B9] = 2;
        ZKNSEARCH_MAIN_SetBrightness(1);
        ZKNSEARCH_MAIN_InitListTexts3(work);
        ZKNSEARCH_LIST_InitFrameList2((char *)work);
        work[0x2BA]++;
    case 1:
        if (FRAME_LIST_UpdateInit(((ZknSearchWork *)work)->frameList) == 0) {
            ZKNSEARCH_MAIN_UpdateCursorActors(work, 0);
            ZKNSEARCH_MAIN_ShowActorsPage3((char *)work);
            ZKNSEARCH_MAIN_LoadBgTile90(work);
            ZKNSEARCH_MAIN_ShowLayerSetB();
            ZKNSEARCH_MAIN_SetFadeStateA(work);
            work[0x2BA] = 0;
            return 16;
        }
    }
    return 15;
}






u32 ZKNSEARCH_MAIN_UpdateListPage3(u8 *work)
{
    u32 ret = 16;
    u32 r5 = FRAME_LIST_Update((struct FrameList *)(*(u32 *)&((ZknSearchWork *)work)->frameList));

    switch (r5) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        if (UI_GetInputMode() == 0) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZKNSEARCH_MAIN_ToggleEntry2(work, r5);
        }
        break;
    case (u32)-12:
        break;
    case (u32)-11:
    case (u32)-10:
    case (u32)-9:
    case (u32)-8:
        ZKNSEARCH_MAIN_UpdateCursorActors(work, 0);
        break;
    case (u32)-7:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 6, 12);
        work[0x2c1] = 6;
        ((ZknSearchWork *)work)->dialogState = 0;
        ((ZknSearchWork *)work)->returnState = ret;
        ret = 0x18;
        break;
    case (u32)-6:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 5, 13);
        work[0x2c1] = 5;
        ((ZknSearchWork *)work)->dialogState = 0;
        ((ZknSearchWork *)work)->returnState = ret;
        ret = 0x18;
        break;
    case (u32)-5:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 6, 12);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 6, 16);
    case (u32)-4:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 5, 13);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 5, 16);
    case (u32)-3:
    case (u32)-2:
        ZKNSEARCH_MAIN_HideColumnActors((char *)work);
        ZKNSEARCH_MAIN_PlaceScrollActor((char *)work, 0, (u16)ZKNSEARCH_MAIN_GetListIndexB((uptr)work, (*(u8 **)(*(u8 * *)&((ZknSearchWork *)work)->save + 8))[3]));
        ZKNSEARCH_MAIN_PlaceScrollActor((char *)work, 1, (u16)ZKNSEARCH_MAIN_GetListIndexB((uptr)work, (*(u8 **)(*(u8 * *)&((ZknSearchWork *)work)->save + 8))[4]));
        work[0x2c1] = 0x39;
        ((ZknSearchWork *)work)->dialogState = 1;
        ((ZknSearchWork *)work)->returnState = ret;
        ret = 0x18;
        break;
    case (u32)-1:
        r5 = ZKNSEARCH_MAIN_PollListInput((char *)work);
        switch (r5) {
        case 0:
            GFL_USE_PlaySeDefaultVolume(0x551);
            ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 2, 9);
            return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 2, 0x11);
        case 8:
            GFL_USE_PlaySeDefaultVolume(0x551);
            ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 2, 9);
            return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 2, 0x11);
        case 9:
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZKNSEARCH_MAIN_ClearEntry3(work);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZKNSEARCH_MAIN_UpdateCursorActors(work, 0);
            ZKNSEARCH_MAIN_ToggleEntry2(work, r5 - 1);
            break;
        }
        break;
    }
    ZKNSEARCH_MAIN_UpdateScrollBarActor((char *)work);
    return ret;
}






u32 ZKNSEARCH_MAIN_ExitListPage3(u8 *work)
{
    ZKNSEARCH_MAIN_SetFadeStateB(work);
    ZKNSEARCH_MAIN_HideAllActors(work);
    ZKNSEARCH_RESULT_DeleteFrameList(work);
    return 3;
}





/*
 * prototype: 021BCB58 receives the caller's explicit r0 even though its body ignores it; BC5C8 reads no inputs.
 */
int ZKNSEARCH_MAIN_EnterListPage4(u8 *work)
{
    switch (work[0x2BA]) {
    case 0:
        work[0x2B9] = 3;
        ZKNSEARCH_MAIN_SetBrightness(1);
        ZKNSEARCH_MAIN_InitListTexts4(work);
        ZKNSEARCH_COND_InitFrameList((char *)work);
        work[0x2BA]++;
    case 1:
        if (FRAME_LIST_UpdateInit(((ZknSearchWork *)work)->frameList) == 0) {
            ZKNSEARCH_MAIN_UpdateCursorActors(work, 0);
            ZKNSEARCH_MAIN_ShowActorsPage4((char *)work);
            ZKNSEARCH_MAIN_LoadBgTile86(work);
            ZKNSEARCH_MAIN_ShowLayerSetB();
            ZKNSEARCH_MAIN_SetFadeStateA(work);
            work[0x2BA] = 0;
            return 19;
        }
    }
    return 18;
}






u32 ZKNSEARCH_MAIN_UpdateListPage4(u8 *work)
{
    u32 ret = 19;
    u32 r5 = FRAME_LIST_Update((struct FrameList *)(*(u32 *)&((ZknSearchWork *)work)->frameList));

    switch (r5) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        if (UI_GetInputMode() == 0) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZKNSEARCH_MAIN_ToggleEntry3(work, r5);
        }
        break;
    case (u32)-12:
        break;
    case (u32)-11:
    case (u32)-10:
    case (u32)-9:
    case (u32)-8:
        ZKNSEARCH_MAIN_UpdateCursorActors(work, 0);
        break;
    case (u32)-7:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 6, 12);
        work[0x2c1] = 6;
        ((ZknSearchWork *)work)->dialogState = 0;
        ((ZknSearchWork *)work)->returnState = ret;
        ret = 0x18;
        break;
    case (u32)-6:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 5, 13);
        work[0x2c1] = 5;
        ((ZknSearchWork *)work)->dialogState = 0;
        ((ZknSearchWork *)work)->returnState = ret;
        ret = 0x18;
        break;
    case (u32)-5:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 6, 12);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 6, 19);
    case (u32)-4:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 5, 13);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 5, 19);
    case (u32)-3:
    case (u32)-2:
        ZKNSEARCH_MAIN_HideColumnActors((char *)work);
        ZKNSEARCH_MAIN_PlaceScrollActor((char *)work, 0, (*(u8 **)(*(u8 * *)&((ZknSearchWork *)work)->save + 8))[5]);
        work[0x2c1] = 0x39;
        ((ZknSearchWork *)work)->dialogState = 1;
        ((ZknSearchWork *)work)->returnState = ret;
        ret = 0x18;
        break;
    case (u32)-1:
        r5 = ZKNSEARCH_MAIN_PollListInput((char *)work);
        switch (r5) {
        case 0:
            GFL_USE_PlaySeDefaultVolume(0x551);
            ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 2, 9);
            return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 2, 0x14);
        case 8:
            GFL_USE_PlaySeDefaultVolume(0x551);
            ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 2, 9);
            return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 2, 0x14);
        case 9:
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZKNSEARCH_MAIN_ClearEntry4(work);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZKNSEARCH_MAIN_UpdateCursorActors(work, 0);
            ZKNSEARCH_MAIN_ToggleEntry3(work, r5 - 1);
            break;
        }
        break;
    }
    ZKNSEARCH_MAIN_UpdateScrollBarActor((char *)work);
    return ret;
}






u32 ZKNSEARCH_MAIN_ExitListPage4(u8 *work)
{
    ZKNSEARCH_MAIN_SetFadeStateB(work);
    ZKNSEARCH_MAIN_HideAllActors(work);
    ZKNSEARCH_RESULT_DeleteFrameList(work);
    return 3;
}





/*
 * prototype: 021BCB88 receives the caller's explicit r0 even though its body ignores it; BC5C8 reads no inputs.
 */
int ZKNSEARCH_MAIN_EnterListPage5(u8 *work)
{
    switch (work[0x2BA]) {
    case 0:
        work[0x2B9] = 4;
        ZKNSEARCH_MAIN_SetBrightness(1);
        ZKNSEARCH_MAIN_InitListTexts5(work);
        ZKNSEARCH_RESULT_InitFrameList((char *)work);
        work[0x2BA]++;
    case 1:
        if (FRAME_LIST_UpdateInit(((ZknSearchWork *)work)->frameList) == 0) {
            ZKNSEARCH_MAIN_UpdateCursorActors(work, 0);
            ZKNSEARCH_MAIN_ShowActorsPage5((char *)work);
            ZKNSEARCH_MAIN_LoadBgTile87(work);
            ZKNSEARCH_MAIN_ShowLayerSetB();
            ZKNSEARCH_MAIN_SetFadeStateA(work);
            work[0x2BA] = 0;
            return 22;
        }
    }
    return 21;
}






u32 ZKNSEARCH_MAIN_UpdateListPage5(u8 *work)
{
    u32 r5;
    u32 ret = 22;

    r5 = FRAME_LIST_Update((struct FrameList *)(*(u32 *)&((ZknSearchWork *)work)->frameList));

    switch (r5) {
    case 0:
    case 1:
    case 2:
    case 3:
        if (UI_GetInputMode() == 0) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZKNSEARCH_MAIN_ToggleEntry4(work, r5);
        }
        break;
    case (u32)-12:
        break;
    case (u32)-11:
    case (u32)-10:
    case (u32)-9:
    case (u32)-8:
        ZKNSEARCH_MAIN_UpdateCursorActors(work, 0);
        break;
    case (u32)-7:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 6, 12);
        work[0x2c1] = 6;
        ((ZknSearchWork *)work)->dialogState = 0;
        ((ZknSearchWork *)work)->returnState = ret;
        ret = 0x18;
        break;
    case (u32)-6:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 5, 13);
        work[0x2c1] = 5;
        ((ZknSearchWork *)work)->dialogState = 0;
        ((ZknSearchWork *)work)->returnState = ret;
        ret = 0x18;
        break;
    case (u32)-5:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 6, 12);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 6, 22);
    case (u32)-4:
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 5, 13);
        return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 5, 22);
    case (u32)-3:
    case (u32)-2:
        ZKNSEARCH_MAIN_LayoutScrollActors((char *)work);
        ZKNSEARCH_MAIN_HideColumnActors((char *)work);
        ZKNSEARCH_MAIN_PlaceScrollActor2((char *)work);
        work[0x2c1] = 0x39;
        ((ZknSearchWork *)work)->dialogState = 1;
        ((ZknSearchWork *)work)->returnState = ret;
        ret = 0x18;
        break;
    case (u32)-1:
        r5 = ZKNSEARCH_MAIN_PollListInput2((char *)work);
        switch (r5) {
        case 0:
            GFL_USE_PlaySeDefaultVolume(0x551);
            ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 2, 9);
            return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 2, 0x17);
        case 8:
            GFL_USE_PlaySeDefaultVolume(0x551);
            ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 2, 9);
            return ZKNSEARCH_MAIN_EnterMessageState(work, 1, 2, 0x17);
        case 9:
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZKNSEARCH_MAIN_ClearEntry5(work);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZKNSEARCH_MAIN_UpdateCursorActors(work, 0);
            ZKNSEARCH_MAIN_ToggleEntry4(work, r5 - 1);
            break;
        }
        break;
    }
    ZKNSEARCH_MAIN_UpdateScrollBarActor((char *)work);
    return ret;
}






u32 ZKNSEARCH_MAIN_ExitListPage5(u8 *work)
{
    ZKNSEARCH_MAIN_SetFadeStateB(work);
    ZKNSEARCH_MAIN_HideAllActors(work);
    ZKNSEARCH_RESULT_DeleteFrameList(work);
    return 3;
}





int ZKNSEARCH_MAIN_UpdateConfirmDialog(u8 *work)
{
    switch (((ZknSearchWork *)work)->dialogState) {
    case 0:
        if (FRAME_LIST_Update(((ZknSearchWork *)work)->frameList) == -1)
            ++((ZknSearchWork *)work)->dialogState;
        break;
    case 1:
        if (work[0x2C1] != 57 && ZKNSEARCH_MAIN_IsActorAnimActive((sptr)work, work[0x2C1]) != 0)
            break;
        ((ZknSearchWork *)work)->dialogState = 0;
        ZKNSEARCH_MAIN_UpdateCursorActors(work, 0);
        return ((ZknSearchWork *)work)->returnState;
    }
    return 24;
}






int ZKNSEARCH_MAIN_UpdateMessageDialog(u8 *work)
{
    if (*(u8 *)(work + 0x2C0) == 0) {
        switch (*(u8 *)(work + 0x2C2)) {
        case 0:
        case 2:
            if (*(u8 *)(work + 0x2C3) == 0) {
                ZKNSEARCH_MAIN_SetCursorTile((sptr)work, *(u8 *)(work + 0x2C1), 1);
                *(u8 *)(work + 0x2C3) = 4;
                (*(u8 *)(work + 0x2C2))++;
            } else {
                (*(u8 *)(work + 0x2C3))--;
            }
            break;
        case 1:
        case 3:
            if (*(u8 *)(work + 0x2C3) == 0) {
                ZKNSEARCH_MAIN_SetCursorTile((sptr)work, *(u8 *)(work + 0x2C1), 2);
                *(u8 *)(work + 0x2C3) = 4;
                (*(u8 *)(work + 0x2C2))++;
            } else {
                (*(u8 *)(work + 0x2C3))--;
            }
            break;
        case 4:
            if (UI_GetInputMode() == 1)
                ZKNSEARCH_MAIN_SetCursorTile((sptr)work, *(u8 *)(work + 0x2C1), 1);
            else
                ZKNSEARCH_MAIN_SetCursorTile((sptr)work, *(u8 *)(work + 0x2C1), 3);
            return *(u32 *)(work + 0x1C);
        }
    } else if (ZKNSEARCH_MAIN_IsActorAnimActive((sptr)work, *(u8 *)(work + 0x2C1)) == 0) {
        if (*(u32 *)(work + 0x1E0) != 0)
            ZKNSEARCH_MAIN_UpdateCursorActors(work, 0);
        return *(u32 *)(work + 0x1C);
    }
    return 0x19;
}






u32 ZKNSEARCH_MAIN_EnterMessageDialog(u8 *work)
{
    ZKNSEARCH_MAIN_DeleteCursorMove((sptr)work);
    ZKNSEARCH_MAIN_StartScrollMove((char *)work, 8);
    ZKNSEARCH_MAIN_RequestPaletteFade((char *)work, 0, 16);
    return 1;
}






void ZKNSEARCH_MAIN_SelectEntry1(u8 *work, u32 index)
{
    (*(u8 **)(*(u8 * *)&((ZknSearchWork *)work)->save + 8))[1] = index;
    FRAME_LIST_SetCursor(((ZknSearchWork *)work)->frameList, index);
    ZKNSEARCH_MAIN_PrintEntryCount(work);
    ZKNSEARCH_MAIN_PlaceColumnActor1((char *)work, (u16)index, 1);
}






void ZKNSEARCH_MAIN_ClearEntry1(u8 *work)
{
    u32 t = *(u32 *)&((ZknSearchWork *)work)->save;
    *(u8 *)(((ZknSearchSave *)t)->record + 1) = 0;
    ZKNSEARCH_MAIN_PrintEntryCount(work);
    ZKNSEARCH_MAIN_PlaceColumnActor1((char *)work, 0, 1);
}





void ZKNSEARCH_MAIN_ToggleEntry1(u8 *work, int row)
{
    int value = row + FRAME_LIST_GetScrollPos(((ZknSearchWork *)work)->frameList);
    u8 *data = *(u8 * *)&((ZknSearchWork *)work)->save->record;
    if (data[2] == value) {
        data[2] = 255;
        ZKNSEARCH_MAIN_PlaceColumnActor1((char *)work, (u16)row, (unsigned int)0);
    } else {
        data[2] = value;
        ZKNSEARCH_MAIN_PlaceColumnActor1((char *)work, (u16)row, (unsigned int)1);
    }
    FRAME_LIST_SetCursor(((ZknSearchWork *)work)->frameList, row);
    ZKNSEARCH_MAIN_PrintEntryCount2(work);
}






void ZKNSEARCH_MAIN_ClearEntry2(u8 *work)
{
    u32 t = *(u32 *)&((ZknSearchWork *)work)->save;
    *(u8 *)(((ZknSearchSave *)t)->record + 2) = 0xff;
    ZKNSEARCH_MAIN_PrintEntryCount2(work);
    ZKNSEARCH_MAIN_HideColumnActors((char *)work);
}





/*
 * extent: compiled through 021BE20A; remaining 00 00 at 021BE20A is two-byte alignment padding before 021BE20C.
 * prototype: 93D4's s16 parameter widened because the original forwards full r4 without truncation.
 */
void ZKNSEARCH_MAIN_ToggleEntry2(u8 *work, int row)
{
    int value = ZKNSEARCH_MAIN_GetListIndexA((uptr)work, row + FRAME_LIST_GetScrollPos(((ZknSearchWork *)work)->frameList));
    u8 *data = *(u8 * *)&((ZknSearchWork *)work)->save->record;
    if (data[3] == 255) {
        data[3] = value;
    } else if (data[4] == 255) {
        if (data[3] == value)
            data[3] = 255;
        else
            data[4] = value;
    } else if (data[3] == value) {
        data[3] = data[4];
        (*(u8 **)(*(u8 * *)&((ZknSearchWork *)work)->save + 8))[4] = 255;
    } else if (data[4] == value) {
        data[4] = 255;
    } else {
        data[3] = data[4];
        (*(u8 **)(*(u8 * *)&((ZknSearchWork *)work)->save + 8))[4] = value;
    }
    FRAME_LIST_SetCursor(((ZknSearchWork *)work)->frameList, row);
    ZKNSEARCH_MAIN_PrintEntryCount3(work);
    data = *(u8 * *)&((ZknSearchWork *)work)->save->record;
    ZKNSEARCH_MAIN_PlaceColumnActors2((char *)work, data[3], data[4]);
}






void ZKNSEARCH_MAIN_ClearEntry3(u8 *work)
{
    (*(u8 **)(*(u8 * *)&((ZknSearchWork *)work)->save + 8))[3] = 0xff;
    (*(u8 **)(*(u8 * *)&((ZknSearchWork *)work)->save + 8))[4] = 0xff;
    ZKNSEARCH_MAIN_PrintEntryCount3(work);
    ZKNSEARCH_MAIN_HideColumnActors((char *)work);
}





/*
 * ABI: 93D4 receives full entry index in r1 without caller-side truncation;
 *      widen its legacy s16 declaration. F85C explicitly narrows r1 to u16.
 */
void ZKNSEARCH_MAIN_ToggleEntry3(u8 *work, int index)
{
    int sum = index + FRAME_LIST_GetScrollPos((struct FrameList *)(*(char * *)&((ZknSearchWork *)work)->frameList));
    u8 *data = *(u8 * *)&((ZknSearchWork *)work)->save->record;
    if (data[5] == sum) {
        data[5] = 255;
        ZKNSEARCH_MAIN_PlaceColumnActor1((char *)work, (u16)index, 0);
    } else {
        data[5] = sum;
        ZKNSEARCH_MAIN_PlaceColumnActor1((char *)work, (u16)index, 1);
    }
    FRAME_LIST_SetCursor(*(struct FrameList * *)&((ZknSearchWork *)work)->frameList, index);
    ZKNSEARCH_MAIN_PrintEntryCount4(work);
}






void ZKNSEARCH_MAIN_ClearEntry4(u8 *work)
{
    u32 t = *(u32 *)&((ZknSearchWork *)work)->save;
    *(u8 *)(((ZknSearchSave *)t)->record + 5) = 0xff;
    ZKNSEARCH_MAIN_PrintEntryCount4(work);
    ZKNSEARCH_MAIN_HideColumnActors((char *)work);
}





/*
 * ABI: 93D4 receives full entry index in r1 without caller-side truncation;
 *      widen its legacy s16 declaration. FA7C explicitly narrows r1 to u16.
 */
void ZKNSEARCH_MAIN_ToggleEntry4(u8 *work, int index)
{
    int sum = index + FRAME_LIST_GetScrollPos((struct FrameList *)(*(char * *)&((ZknSearchWork *)work)->frameList));
    u8 *data = *(u8 * *)&((ZknSearchWork *)work)->save->record;
    if (data[6] == sum) {
        data[6] = 255;
        ZKNSEARCH_MAIN_PlaceColumnActor4((char *)work, (u16)index, 0);
    } else {
        data[6] = sum;
        ZKNSEARCH_MAIN_PlaceColumnActor4((char *)work, (u16)index, 1);
    }
    FRAME_LIST_SetCursor(*(struct FrameList * *)&((ZknSearchWork *)work)->frameList, index);
    ZKNSEARCH_MAIN_ShowEntry6Actor((char *)work);
}






void ZKNSEARCH_MAIN_ClearEntry5(u8 *work)
{
    u32 t = *(u32 *)&((ZknSearchWork *)work)->save;
    *(u8 *)(((ZknSearchSave *)t)->record + 6) = 0xff;
    ZKNSEARCH_MAIN_ShowEntry6Actor((char *)work);
    ZKNSEARCH_MAIN_HideColumnActors((char *)work);
}





u32 ZKNSEARCH_MAIN_EnterMessageState(u8 *work, u32 dialogKind, u32 messageId, u32 returnState)
{
    work[0x2c0] = dialogKind;
    work[0x2c1] = messageId;
    work[0x2c2] = 0;
    work[0x2c3] = 0;
    ((ZknSearchWork *)work)->returnState2 = returnState;
    return 25;
}





u32 ZKNSEARCH_MAIN_EnterListState(u8 *work, u32 returnState)
{
    work[0x2ba] = 0;
    ((ZknSearchWork *)work)->returnState = returnState;
    return 5;
}





/*
 * tail: 021BE366..021BE368 is zero alignment padding.
 * proof: 071CC forwards to 0319A4, which forwards fixed r1=0x36 to
 *        033B68; their full matched bodies use no incoming r2/r3.
 * ABI: 02012BF8's full 20-byte body preserves r1 across EC0/C404 and
 *      supplies only r0/r1 to C44C. EC0 reads only r0; C404 forwards r0
 *      through C40C/071CC with fixed r1=0x36. C44C reads r0/r1 only.
 *      Legacy trailing a2/a3 are omitted; all original visible inputs remain.
 */
void ZKNSEARCH_MAIN_ToggleSaveFlag(u8 *work)
{
    if (GAME_DATA_ContainsRecentId((**(void ** *)&((ZknSearchWork *)work)->save), 16) == 1) {
        GAME_DATA_SetRecentId(**(void ** *)&((ZknSearchWork *)work)->save, 16, 0);
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 4, 6);
    } else {
        GAME_DATA_SetRecentId(**(void ** *)&((ZknSearchWork *)work)->save, 16, 1);
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 4, 7);
    }
}





void ZKNSEARCH_MAIN_InitBmpWindows(u8 *work)
{
    unsigned i;
    BMP_WIN_Init(123);
    for (i = 0; i < 16; i++) {
        const struct ZknSearchBmpTemplate *r = &d_021C0900[i];
        *(unsigned *)(work + i * 8 + 0x14c) = (uptr)BMP_WIN_Create((unsigned int)r->x, (unsigned int)r->y, (unsigned int)r->w, r->h, r->charW, r->charH, 1);
    }
    ZKNSEARCH_MAIN_InitWindowTexts(work);
}






void ZKNSEARCH_MAIN_DeleteBmpWindows(char *work)
{
    unsigned int i;
    for (i = 0; i < 0x10; i++)
    {
        BMP_WIN_Delete(*(void **)(work + 0x14c + i * 8));
    }
    BMP_WIN_Exit();
}





/*
 * lever: each int offset is assigned 0x1DC, then its final literal;
 *        spilled locals retain both stores without a reload.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`release = 0x1dc;` before `release = 0x14c;`; `clear = 0x1dc;` before
 * `clear = 0x150;` and 2 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void ZKNSEARCH_MAIN_UpdateBmpWindows(u8 *work)
{
    int release, clear, get, flag;
    unsigned i;
    PRINTSYS_QUE_Main((struct PrintQueue *)(*(struct PrintSys * *)&((ZknSearchWork *)work)->printSys));
    release = 0x14c;
    clear = 0x150;
    get = 0x14c;
    flag = 0x150;
    for (i = 0; i < 16; i++) {
        struct PrintSys *ps = *(struct PrintSys * *)&((ZknSearchWork *)work)->printSys;
        u8 *record = work + i * 8;
        if (record[flag] != 0 && PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)ps, BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor **)(record + get)))) == 0) {
            BMP_WIN_TransferChars((struct BmpWin *)(*(struct Descriptor **)(record + release)));
            record[clear] = 0;
        }
    }
}





void ZKNSEARCH_MAIN_PrintWindowText(u8 *work, int slot, u32 message, int x, int y, u16 color, u32 mode)
{
    struct Strbuf *text = MSGDATA_AllocString(*(struct MsgBank * *)&((ZknSearchWork *)work)->msgBank, message);
    TOUCHBAR_PrintAligned((TouchBarWindow *)(work + 0x14c + slot * 8), (void *)(((ZknSearchWork *)work)->printSys), x, y, text, ((ZknSearchWork *)work)->font, color, mode);
    STRBUF_Delete(text);
}






void ZKNSEARCH_MAIN_MakeWindowScreen(u8 *zknSearchBmpWin)
{
    BMP_WIN_MakeScreen((struct BmpWin *)(((ZknSearchBmpWin *)zknSearchBmpWin)->bmp));
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)(((ZknSearchBmpWin *)zknSearchBmpWin)->bmp)));
}






void ZKNSEARCH_MAIN_InitWindowTexts(u8 *work)
{
    if (*(u8 *)(*(u32 *)(*(u32 *)&((ZknSearchWork *)work)->save + 8)) == 0)
        ZKNSEARCH_MAIN_PrintWindowText(work, 0, 0x12, 0, 4, 0x3C40, 0);
    else
        ZKNSEARCH_MAIN_PrintWindowText(work, 0, 0x11, 0, 4, 0x3C40, 0);
    ZKNSEARCH_MAIN_PrintWindowText(work, 2, 0xC, 0x28, 4, 0x3C40, 2);
    ZKNSEARCH_MAIN_PrintWindowText(work, 3, 0xD, 0x28, 4, 0x3C40, 2);
    ZKNSEARCH_MAIN_PrintWindowText(work, 4, 0xE, 0x28, 4, 0x3C40, 2);
    ZKNSEARCH_MAIN_PrintWindowText(work, 5, 0xF, 0x28, 4, 0x3C40, 2);
    ZKNSEARCH_MAIN_PrintWindowText(work, 6, 0x10, 0x28, 4, 0x3C40, 2);
    ZKNSEARCH_MAIN_PrintWindowText(work, 0xB, 0x14, 0x28, 4, 0x3C40, 2);
}






static inline u8 *Bytes021BE564(u8 *work)
{
    return *(u8 * *)&((ZknSearchWork *)work)->save->record;
}






void ZKNSEARCH_MAIN_UpdateResultTexts(u8 *work)
{
    u32 v;
    struct Strbuf *s1;
    struct Strbuf *s2;
    struct Strbuf *s3;
    u8 w;
    u8 x;

    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x14C);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x15C);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x164);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x16C);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x174);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x17C);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x1A4);
    ZKNSEARCH_MAIN_PrintLabel1(work);

    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)((ZknSearchWork *)work)->bmpWin[7].bmp)), 0);
    ZKNSEARCH_MAIN_PrintWindowText(work, 7, Bytes021BE564(work)[1] + 0x19, 0x28, 4, 0x3C40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x184);

    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)((ZknSearchWork *)work)->bmpWin[8].bmp)), 0);
    v = Bytes021BE564(work)[2];
    if (v == 0xFF)
        ZKNSEARCH_MAIN_PrintWindowText(work, 8, 0x5F, 8, 4, 0x3C40, 2);
    else
        ZKNSEARCH_MAIN_PrintWindowText(work, 8, v + 0x33, 8, 4, 0x3C40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x18C);

    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)((ZknSearchWork *)work)->bmpWin[9].bmp)), 0);
    if (Bytes021BE564(work)[3] == 0xFF) {
        ZKNSEARCH_MAIN_PrintWindowText(work, 9, 0x30, 0x40, 4, 0x3C40, 2);
    } else if (Bytes021BE564(work)[4] == 0xFF) {
        ZKNSEARCH_MAIN_PrintWindowText(work, 9, ZKNSEARCH_MAIN_LookupSavedEntryId((sptr)work, Bytes021BE564(work)[3]), 0x40, 4, 0x3C40, 2);
    } else {
        s1 = MSGDATA_AllocString((struct MsgBank *)(*(u32 *)&((ZknSearchWork *)work)->msgBank), 0x31);
        TOUCHBAR_PrintAligned((TouchBarWindow *)(work + 0x194), (void *)(((ZknSearchWork *)work)->printSys), 0x42, 4, s1, ((ZknSearchWork *)work)->font, 0x3C40, 2);
        w = PRINTSYS_MeasureWidestLine(s1, ((ZknSearchWork *)work)->font, 0);
        STRBUF_Delete(s1);
        x = 0x40 - (u8)(w / 2);
        s2 = MSGDATA_AllocString((struct MsgBank *)(*(u32 *)&((ZknSearchWork *)work)->msgBank), ZKNSEARCH_MAIN_LookupSavedEntryId((sptr)work, Bytes021BE564(work)[3]));
        TOUCHBAR_PrintAligned((TouchBarWindow *)(work + 0x194), (void *)(((ZknSearchWork *)work)->printSys), x + 2, 4, s2, ((ZknSearchWork *)work)->font, 0x3C40, 1);
        STRBUF_Delete(s2);
        x += w;
        s3 = MSGDATA_AllocString((struct MsgBank *)(*(u32 *)&((ZknSearchWork *)work)->msgBank), ZKNSEARCH_MAIN_LookupSavedEntryId((sptr)work, Bytes021BE564(work)[4]));
        TOUCHBAR_PrintAligned((TouchBarWindow *)(work + 0x194), (void *)(((ZknSearchWork *)work)->printSys), x + 2, 4, s3, ((ZknSearchWork *)work)->font, 0x3C40, 0);
        STRBUF_Delete(s3);
    }
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x194);

    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)((ZknSearchWork *)work)->bmpWin[10].bmp)), 0);
    v = Bytes021BE564(work)[5];
    if (v == 0xFF)
        ZKNSEARCH_MAIN_PrintWindowText(work, 10, 0x6A, 0x28, 4, 0x3C40, 2);
    else
        ZKNSEARCH_MAIN_PrintWindowText(work, 10, v + 0x60, 0x28, 4, 0x3C40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x19C);
}






void ZKNSEARCH_MAIN_PrintLabel1(u8 *work)
{
    u32 z = 0;

    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)*(u32 *)&((ZknSearchWork *)work)->bmpWin[1].bmp)), 0);
    ZKNSEARCH_MAIN_PrintWindowText(work, 1, 1, 0, 4, 0x440, z);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x154);
}






void ZKNSEARCH_MAIN_ClearLabel1(u8 *work)
{
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)((ZknSearchWork *)work)->bmpWin[1].bmp)), 0);
    BMP_WIN_TransferChars((struct BmpWin *)((ZknSearchWork *)work)->bmpWin[1].bmp);
}





void ZKNSEARCH_MAIN_InitListTexts(u8 *work)
{
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x14c);
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((ZknSearchWork *)work)->bmpWin[1].bmp)), 0);
    ZKNSEARCH_MAIN_PrintWindowText(work, 1, 4, 0, 4, 0x440, 0);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x154);
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((ZknSearchWork *)work)->bmpWin[12].bmp)), 0);
    ZKNSEARCH_MAIN_PrintWindowText(work, 12, 12, 40, 0, 0x3c40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x1ac);
    ZKNSEARCH_MAIN_PrintEntryCount(work);
}





void ZKNSEARCH_MAIN_PrintEntryCount(u8 *work)
{
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((ZknSearchWork *)work)->bmpWin[13].bmp)), 0);
    ZKNSEARCH_MAIN_PrintWindowText(work, 13, (*(u8 **)(*(u8 * *)&((ZknSearchWork *)work)->save + 8))[1] + 25, 48, 0, 0x3c40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x1b4);
}






void ZKNSEARCH_MAIN_InitListTexts2(u8 *work)
{
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x14C);
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)*(u32 *)&((ZknSearchWork *)work)->bmpWin[1].bmp)), 0);
    ZKNSEARCH_MAIN_PrintWindowText(work, 1, 5, 0, 4, 0x440, 0);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x154);
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)*(u32 *)&((ZknSearchWork *)work)->bmpWin[12].bmp)), 0);
    ZKNSEARCH_MAIN_PrintWindowText(work, 0xC, 0xD, 0x28, 0, 0x3C40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x1AC);
    ZKNSEARCH_MAIN_PrintEntryCount2(work);
}





/*
 * tail: 021BE9D2..021BE9D4 is zero alignment padding.
 */
void ZKNSEARCH_MAIN_PrintEntryCount2(u8 *work)
{
    unsigned message;
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((ZknSearchWork *)work)->bmpWin[13].bmp)), 0);
    message = (*(u8 **)(*(u8 * *)&((ZknSearchWork *)work)->save + 8))[2];
    if (message != 255) ZKNSEARCH_MAIN_PrintWindowText(work, 13, message + 51, 48, 0, 0x3c40, 2);
    else ZKNSEARCH_MAIN_PrintWindowText(work, 13, 95, 48, 0, 0x3c40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x1b4);
}






void ZKNSEARCH_MAIN_InitListTexts3(u8 *work)
{
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x14C);
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)*(u32 *)&((ZknSearchWork *)work)->bmpWin[1].bmp)), 0);
    ZKNSEARCH_MAIN_PrintWindowText(work, 1, 6, 0, 4, 0x440, 0);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x154);
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)*(u32 *)&((ZknSearchWork *)work)->bmpWin[12].bmp)), 0);
    ZKNSEARCH_MAIN_PrintWindowText(work, 0xC, 0xE, 0x28, 0, 0x3C40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x1AC);
    ZKNSEARCH_MAIN_PrintEntryCount3(work);
}






void ZKNSEARCH_MAIN_PrintEntryCount3(u8 *work)
{
    u8 c;

    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)*(u32 *)&((ZknSearchWork *)work)->bmpWin[13].bmp)), 0);
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)((ZknSearchWork *)work)->bmpWin[14].bmp)), 0);
    c = ((u8 *)*(u32 *)(*(u32 *)&((ZknSearchWork *)work)->save + 8))[3];
    if (c != 0xFF)
        ZKNSEARCH_MAIN_PrintWindowText(work, 0xD, ZKNSEARCH_MAIN_LookupSavedEntryId((sptr)work, c), 0x30, 0, 0x3C40, 2);
    else
        ZKNSEARCH_MAIN_PrintWindowText(work, 0xD, 0x30, 0x30, 0, 0x3C40, 2);
    c = ((u8 *)*(u32 *)(*(u32 *)&((ZknSearchWork *)work)->save + 8))[4];
    if (c != 0xFF)
        ZKNSEARCH_MAIN_PrintWindowText(work, 0xE, ZKNSEARCH_MAIN_LookupSavedEntryId((sptr)work, c), 0x30, 0, 0x3C40, 2);
    else
        ZKNSEARCH_MAIN_PrintWindowText(work, 0xE, 0x30, 0x30, 0, 0x3C40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x1B4);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x1BC);
}






void ZKNSEARCH_MAIN_InitListTexts4(u8 *work)
{
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x14C);
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)*(u32 *)&((ZknSearchWork *)work)->bmpWin[1].bmp)), 0);
    ZKNSEARCH_MAIN_PrintWindowText(work, 1, 8, 0, 4, 0x440, 0);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x154);
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)*(u32 *)&((ZknSearchWork *)work)->bmpWin[12].bmp)), 0);
    ZKNSEARCH_MAIN_PrintWindowText(work, 0xC, 0xF, 0x28, 0, 0x3C40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x1AC);
    ZKNSEARCH_MAIN_PrintEntryCount4(work);
}






void ZKNSEARCH_MAIN_PrintEntryCount4(u8 *work)
{
    u32 v;
    u8 *b;

    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)*(u32 *)&((ZknSearchWork *)work)->bmpWin[13].bmp)), 0);
    b = (u8 *)*(u32 *)(*(u32 *)&((ZknSearchWork *)work)->save + 8);
    v = b[5];
    if (v != 0xFF)
        ZKNSEARCH_MAIN_PrintWindowText(work, 0xD, v + 0x60, 0x30, 0, 0x3C40, 2);
    else
        ZKNSEARCH_MAIN_PrintWindowText(work, 0xD, 0x6A, 0x30, 0, 0x3C40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x1B4);
}






void ZKNSEARCH_MAIN_InitListTexts5(u8 *work)
{
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x14c);
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((ZknSearchWork *)work)->bmpWin[1].bmp)), 0);
    ZKNSEARCH_MAIN_PrintWindowText(work, 1, 7, 0, 4, 0x440, 0);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x154);
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((ZknSearchWork *)work)->bmpWin[12].bmp)), 0);
    ZKNSEARCH_MAIN_PrintWindowText(work, 12, 16, 40, 0, 0x3c40, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + 0x1ac);
}






void ZKNSEARCH_MAIN_PrintListRow(char *work, int *window, struct Strbuf *text)
{
    u32 x = (uptr)FRAME_LIST_GetPrinter((struct FrameList *)(*(char * *)&((ZknSearchWork *)work)->frameList));

    TOUCHBAR_PrintAligned((TouchBarWindow *)window, (void *)x, (u16)(BMP_WIN_GetWidth((struct BmpWin *)(*window)) * 8 / 2), 4, text,
                  ((ZknSearchWork *)work)->font, 0x39e0, 2);
}






void ZKNSEARCH_MAIN_TransferRowChars(int work, unsigned *window)
{
    BMP_WIN_TransferChars((struct BmpWin *)*window);
}





void ZKNSEARCH_MAIN_PrintMessageText(u8 *work, unsigned message)
{
    WindowOffset offset = kMsgWindowOffset;
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor **)(work + offset))), 6);
    ZKNSEARCH_MAIN_PrintWindowText(work, 15, message, 120, 0, 0x446, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(work + offset);
}






void ZKNSEARCH_MAIN_PrintMessage11(void *work)
{
    ZKNSEARCH_MAIN_PrintMessageText((u8 *)work, 0xb);
}






void ZKNSEARCH_MAIN_PrintMessage9(void *work)
{
    ZKNSEARCH_MAIN_PrintMessageText((u8 *)work, 9);
}






void ZKNSEARCH_MAIN_PrintMessage10(void *work)
{
    ZKNSEARCH_MAIN_PrintMessageText((u8 *)work, 0xa);
}






void ZKNSEARCH_MAIN_RedrawSubWindow(int work)
{
    ZKNSEARCH_MAIN_MakeWindowScreen((u8 *)(work + 0x1a4));
}






void ZKNSEARCH_MAIN_InitActorSystem(int work)
{
    ZKNSEARCH_MAIN_InitClact();
    ZKNSEARCH_MAIN_RegisterActorRes((ZknSearchWork *)work);
    ZKNSEARCH_MAIN_CreateActors((ZknSearchWork *)work);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}






void ZKNSEARCH_MAIN_DeleteActorSystem(int work)
{
    ZKNSEARCH_MAIN_DeleteActors(work);
    ZKNSEARCH_MAIN_ReleaseActorRes((u8 *)work);
    CLACT_ExitSystem();
}






void ZKNSEARCH_MAIN_UpdateActorAnims(int work)
{
    unsigned i;

    for (i = 0; i < 0x39; i++) {
        ZknSearchWork *q = (ZknSearchWork *)work;

        if (q->actors[i] != 0 && CLACT_GetActorAutoAnim((struct ClactActor *)q->actors[i]) != 1)
            CLACT_AddActorAnimFrame((struct ClactActor *)q->actors[i], 0x1000);
    }
    CLACT_DrawSystem();
}






void ZKNSEARCH_MAIN_SetActorAnim(char *work, int idx, int animSeq)
{
    CLACT_SetActorAnimFrame(*(void **)(work + 0x28 + idx * 4), 0);
    CLACT_SetActorAnimSeq(*(void **)(work + 0x28 + idx * 4), (unsigned short)animSeq);
}






void ZKNSEARCH_MAIN_SetActorAnimAuto(int work, int i, int animSeq)
{
    ZKNSEARCH_MAIN_SetActorAnim((char *)work, i, animSeq);
    CLACT_SetActorAutoAnim((struct ClactActor *)((struct Actor *)((ZknSearchWork *)work)->actors[i]), 1);
}






int ZKNSEARCH_MAIN_GetActorAnimSeq(int work, int i)
{
    return CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)((ZknSearchWork *)work)->actors[i]));
}






int ZKNSEARCH_MAIN_IsActorAnimActive(int work, int actorIndex)
{
    

    return CLACT_IsActorAnimActive((struct ClactActor *)((struct Actor *)((ZknSearchWork *)work)->actors[actorIndex]));
}






void ZKNSEARCH_MAIN_SetActorVisible(int work, int i, int visible)
{
    int h = (sptr)((ZknSearchWork *)work)->actors[i];

    if (h != 0)
        CLACT_SetActorDrawEnable((struct ClactActor *)h, visible);
}






int ZKNSEARCH_MAIN_GetActorVisible(int work, int i)
{
    return CLACT_GetActorDrawEnable((struct ClactActor *)((struct Actor *)((ZknSearchWork *)work)->actors[i]));
}






void ZKNSEARCH_MAIN_SetActorObjMode(char *work, int idx, int flag)
{
    if (flag == 1)
    {
        CLACT_SetActorObjMode(*(void **)(work + 0x28 + idx * 4), 1);
    }
    else
    {
        CLACT_SetActorObjMode(*(void **)(work + 0x28 + idx * 4), 0);
    }
}






void ZKNSEARCH_MAIN_SetActorSurfacePos(char *work, int idx, int posX, short posY, unsigned short space)
{
    unsigned short buf[2];
    buf[0] = posX;
    buf[1] = posY;
    CLACT_AddActorSurfacePos((struct ClactActor *)(*(void **)(work + idx * 4 + 0x28)), (const struct ClactVec2 *)buf, space);
}






void ZKNSEARCH_MAIN_GetActorSurfacePos(char *work, int idx, short *outA, short *outB, unsigned short in)
{
    short buf[2];
    CLACT_GetActorSurfacePos((struct ClactActor *)(*(void **)(work + idx * 4 + 0x28)), (struct ClactVec2 *)buf, in);
    *outA = buf[0];
    *outB = buf[1];
}






void ZKNSEARCH_MAIN_SetActorBgPriority(int work, int i, unsigned bgPriority)
{
    CLACT_SetActorBgPriority(((ZknSearchWork *)work)->actors[i], (unsigned char)bgPriority);
}






void ZKNSEARCH_MAIN_InitClact(void)
{
    ClactConfig tbl = d_021C0990;

    CLACT_InitSystem((const struct ClactSysInit *)((struct SysInit *)(&tbl)), (const struct DispVramCfg *)ZKNSEARCH_SYS_GetVramBanks(), 0x7b);
}






void ZKNSEARCH_MAIN_RegisterActorRes(ZknSearchWork *work)
{
    u32 i;
    void *arc;
    void *arc2;

    for (i = 0; i < 6; i++)
        work->charRes[i] = -1;
    for (i = 0; i < 6; i++)
        work->palRes[i] = -1;
    for (i = 0; i < 4; i++)
        work->cellRes[i] = -1;

    arc = ARC_TOOL_CreateHandle(0x9F, 0x807B);
    work->charRes[1] = CLACT_RegisterCharacter(arc, 0x4E, 0, 0, 0x7B);
    work->palRes[1] = CLACT_RegisterPalette(arc, 0x4B, 0, 0, 0x7B);
    work->cellRes[1] = CLACT_RegisterCellAnim(arc, 0x54, 0x64, 0x7B);
    work->charRes[2] = CLACT_RegisterCharacter(arc, 0x4E, 0, 1, 0x7B);
    work->palRes[2] = CLACT_RegisterPalette(arc, 0x4B, 1, 0, 0x7B);
    work->charRes[5] = CLACT_RegisterCharacter(arc, 0x4D, 0, 0, 0x7B);
    work->palRes[5] = CLACT_RegisterPalette(arc, 0x48, 0, 0x60, 0x7B);
    work->cellRes[3] = CLACT_RegisterCellAnim(arc, 0x53, 0x63, 0x7B);
    work->charRes[3] = CLACT_RegisterCharacter(arc, 0x52, 0, 0, 0x7B);
    work->palRes[3] = CLACT_RegisterPalette(arc, 0x4C, 0, 0x80, 0x7B);
    work->cellRes[2] = CLACT_RegisterCellAnim(arc, 0x55, 0x65, 0x7B);
    work->charRes[4] = CLACT_RegisterCharacter(arc, 0x52, 0, 1, 0x7B);
    work->palRes[4] = CLACT_RegisterPalette(arc, 0x4C, 1, 0x60, 0x7B);
    ARC_TOOL_DeleteHandle(arc);

    arc2 = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), 0x807B);
    work->charRes[0] = CLACT_RegisterCharacter(arc2, APP_ICON_GetMoveKindAnimFileId(), 0, 0, 0x7B);
    work->palRes[0] = CLACT_RegisterPalette(arc2, APP_ICON_GetMoveKindPaletteFileId(), 0, 0xA0, 0x7B);
    work->cellRes[0] = CLACT_RegisterCellAnim(arc2, APP_ICON_GetStatusCellFileId(2), APP_ICON_GetStatusPaletteFileId(2), 0x7B);
    ARC_TOOL_DeleteHandle(arc2);
}




void ZKNSEARCH_MAIN_ReleaseActorRes(u8 *work)
{
    unsigned i;
    for (i = 0; i < 6; i++) {
        unsigned v = ((ZknSearchWork *)work)->charRes[i];
        if (v != -1) CLACT_ReleaseCharacter(v);
    }
    for (i = 0; i < 6; i++) {
        unsigned v = ((ZknSearchWork *)work)->palRes[i];
        if (v != -1) CLACT_ReleasePalette(v);
    }
    for (i = 0; i < 4; i++) {
        unsigned v = ((ZknSearchWork *)work)->cellRes[i];
        if (v != -1) CLACT_ReleaseCellAnim(v);
    }
}





void ZKNSEARCH_MAIN_CreateActors(ZknSearchWork *work)
{
    u32 i;
    struct ZknSearchActorTemplate t0;
    struct ZknSearchActorTemplate t;
    struct ZknSearchActorTemplate ta;
    struct ZknSearchActorTemplate tb;

    work->actorBank = CLACT_CreateUnit(0x39, 0, 0x7B);
    for (i = 0; i < 0x39; i++)
        work->actors[i] = 0;

    for (i = 0; i <= 14; i++) {
        t0 = data_021C09AC[i];
        t0.charIdx = work->charRes[t0.charIdx];
        t0.palIdx = work->palRes[t0.palIdx];
        t0.cellIdx = work->cellRes[t0.cellIdx];
        work->actors[i] = ZUKAN_CreateActor(work->actorBank, (struct ZknSearchActorTemplate *)(&t0), 0x7B);
    }

    if (GAME_DATA_ContainsRecentId((work->save->gameData), 0x10) == 1)
        ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 4, 7);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 5, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 6, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 1, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 7, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 8, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 9, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 10, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 11, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 12, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 13, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 14, 0);
    CLACT_SetActorObjMode(work->actors[13], 2);
    CLACT_SetActorObjMode(work->actors[14], 2);
    ZKNSEARCH_MAIN_SetActorObjMode((char *)work, 11, 1);
    ZKNSEARCH_MAIN_SetActorObjMode((char *)work, 12, 1);

    ta = data_021C0978;
    tb = data_021C0960;
    for (i = 0; i < 14; i++) {
        t = ta;
        t.charIdx = work->charRes[t.charIdx];
        t.palIdx = work->palRes[t.palIdx];
        t.cellIdx = work->cellRes[t.cellIdx];
        t.id = i;
        work->actors[15 + i] = ZUKAN_CreateActor(work->actorBank, (struct ZknSearchActorTemplate *)(&t), 0x7B);
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, i + 15, 0);

        t = tb;
        t.charIdx = work->charRes[t.charIdx];
        t.palIdx = work->palRes[t.palIdx];
        t.cellIdx = work->cellRes[t.cellIdx];
        t.id = i;
        work->actors[29 + i] = ZUKAN_CreateActor(work->actorBank, (struct ZknSearchActorTemplate *)(&t), 0x7B);
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, i + 29, 0);
        ZKNSEARCH_MAIN_SetActorObjMode((char *)work, (int)i + 29, 1);
        work->actors[43 + i] = ZUKAN_CreateActor(work->actorBank, (struct ZknSearchActorTemplate *)(&t), 0x7B);
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, i + 43, 0);
        CLACT_SetActorObjMode(work->actors[43 + i], 2);
    }
}





void ZKNSEARCH_MAIN_DeleteActorAt(int work, int i)
{
    int o = i * 4;
    ZknSearchWork *q = (ZknSearchWork *)work;

    if (q->actors[i] != 0) {
        CLACT_DeleteActor((struct ClactActor *)q->actors[i]);
        q->actors[i] = 0;
    }
}





void ZKNSEARCH_MAIN_DeleteActors(int work)
{
    unsigned i;

    for (i = 0; i < 0x39; i++)
        ZKNSEARCH_MAIN_DeleteActorAt(work, i);
    CLACT_DeleteUnit(((ZknSearchWork *)work)->actorBank);
}



void ZKNSEARCH_MAIN_HideAllActors(u8 *work)
{
    unsigned int i;

    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 1, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 9, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xA, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xB, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xC, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xD, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xE, 0);
    for (i = 0; i < 0xE; i++) {
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, i + 0xF, 0);
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, i + 0x1D, 0);
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, i + 0x2B, 0);
    }
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 7, 0);
}




/*
 * ABI: matched caller BD118 consumes r0. The inactive arm retains the
 *      nested object pointer; the active arm retains BEDF0's return register.
 *      Declare BEDF0's observable r0 return despite void legacy declarations.
 */
unsigned ZKNSEARCH_MAIN_ShowResultActors(u8 *work)
{
    u8 *data;
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 6, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 5, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 2, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 3, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 4, 1);
    data = *(u8 * *)&((ZknSearchWork *)work)->save->record;
    if (data[6] == 255)
        return (uptr)data;
    ZKNSEARCH_MAIN_SetActorAnim((char *)work, 7, data[6]);
    ZKNSEARCH_MAIN_SetActorSurfacePos((char *)work, 7, 192, 116, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 7, 1);
#ifndef __MWERKS__
    return 0; /* the DS code falls off the end here; r0 is not set */
#endif
}






void ZKNSEARCH_MAIN_ShowActorsPage1(int work)
{
    ZKNSEARCH_MAIN_SetActorVisible((int)work, 3, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)work, 4, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)work, 2, 1);
}





void ZKNSEARCH_MAIN_ShowActorsPage2(char *work)
{
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 3, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 4, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 2, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 5, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 6, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 1, 1);
    ZKNSEARCH_MAIN_SetActorSurfacePos(work, 0, 0xfc, 12, 0);
}





void ZKNSEARCH_MAIN_ShowActorsPage3(char *work)
{
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 3, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 4, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 2, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 5, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 6, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 1, 1);
    ZKNSEARCH_MAIN_SetActorSurfacePos(work, 0, 0xfc, 12, 0);
}




void ZKNSEARCH_MAIN_ShowActorsPage4(char *work)
{
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 3, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 4, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 2, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 5, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 6, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 1, 1);
    ZKNSEARCH_MAIN_SetActorSurfacePos(work, 0, 0xfc, 12, 0);
}




void ZKNSEARCH_MAIN_ShowActorsPage5(char *work)
{
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 3, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 4, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 2, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 5, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 6, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0, 1);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 1, 1);
    ZKNSEARCH_MAIN_SetActorSurfacePos(work, 0, 0xfc, 12, 0);
    ZKNSEARCH_MAIN_ShowEntry6Actor(work);
}




void ZKNSEARCH_MAIN_ShowEntry6Actor(char *work)
{
    unsigned char v = (*(unsigned char **)(*(char * *)&((ZknSearchWork *)work)->save + 8))[6];
    if (v != 0xff) {
        ZKNSEARCH_MAIN_SetActorAnim(work, 7, v);
        ZKNSEARCH_MAIN_SetActorSurfacePos(work, 7, 0x40, 0x68, 0);
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 7, 1);
    } else {
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 7, 0);
    }
}




void ZKNSEARCH_MAIN_LayoutScrollActors(char *work)
{
    short base = FRAME_LIST_GetScrollPos((struct FrameList *)(*(char * *)&((ZknSearchWork *)work)->frameList));
    short i;
    for (i = 0; i < 14; i++) {
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, i + 15, 0);
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, i + 29, 0);
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, i + 43, 0);
    }
    for (i = 0; i < 5; i++) {
        ZKNSEARCH_MAIN_PlacePageActor(work, (unsigned short)(base + i), (short)(i * 40), 1);
        if (base - (i + 1) >= 0)
            ZKNSEARCH_MAIN_PlacePageActor(work, (unsigned short)(base - (i + 1)), (short)(192 - (i + 1) * 40), 0);
    }
}




void ZKNSEARCH_MAIN_UpdateScrollBarActor(char *work)
{
    short pos[2];
    unsigned int y;
    ZKNSEARCH_MAIN_GetActorSurfacePos(work, 0, &pos[1], &pos[0], 0);
    y = FRAME_LIST_ClampToScrollBar(*(struct FrameList * *)&((ZknSearchWork *)work)->frameList, pos[0]);
    if (y < 12) y = 12;
    else if (y > 156) y = 156;
    ZKNSEARCH_MAIN_SetActorSurfacePos(work, 0, 0xfc, (short)y, 0);
}





void ZKNSEARCH_MAIN_UpdateCursorActors(u8 *work, int force)
{
    int r6 = FRAME_LIST_GetCursor((struct FrameList *)(((ZknSearchWork *)work)->frameList));

    if (ZKNSEARCH_MAIN_GetActorAnimSeq((sptr)work, 6) != 0xC || force == 0) {
        if (FRAME_LIST_GetScrollPos((struct FrameList *)(((ZknSearchWork *)work)->frameList)) == 0 && r6 == 0)
            ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 6, 0x12);
        else
            ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 6, 4);
    }
    if (ZKNSEARCH_MAIN_GetActorAnimSeq((sptr)work, 5) != 0xD || force == 0) {
        if (FRAME_LIST_CanScrollDown((struct FrameList *)(((ZknSearchWork *)work)->frameList)) == 0 &&
            r6 == ((ZknSearchWork *)work)->entryCount - 1)
            ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 5, 0x13);
        else
            ZKNSEARCH_MAIN_SetActorAnimAuto((sptr)work, 5, 5);
    }
}




void ZKNSEARCH_MAIN_PlaceColumnActor(char *work, int idx, int y, int flag)
{
    int index;
    int coord;
    if (flag == 1) {
        index = idx + 9;
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, index, 1);
        coord = y + 12;
        ZKNSEARCH_MAIN_SetActorSurfacePos(work, index, 0x8c, coord, 0);
    } else {
        int other = idx + 11;
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, other, 1);
        coord = y + 12;
        ZKNSEARCH_MAIN_SetActorSurfacePos(work, other, 0x8c, coord, 1);
        index = idx + 13;
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, index, 1);
        ZKNSEARCH_MAIN_SetActorSurfacePos(work, index, 0x8c, coord, 1);
    }
}




void ZKNSEARCH_MAIN_HideColumnActors(char *work)
{
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 9, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 10, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 11, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 12, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 13, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 14, 0);
}




/*
 * Caller sign-extends r3 to 16 bits before EE38; existing callee uses u16.
 */
void ZKNSEARCH_MAIN_PlaceColumnActor1(char *work, int i, int flag)
{
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 9, flag);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 11, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 13, 0);
    if (flag == 1)
        ZKNSEARCH_MAIN_SetActorSurfacePos(work, 9, 0x8c, (short)(i * 24 + 12), 0);
}





void ZKNSEARCH_MAIN_PlaceColumnActors2(char *work, u8 firstEntry, u8 secondEntry)
{
    u8 cur = (u8)FRAME_LIST_GetScrollPos(((ZknSearchWork *)work)->frameList);
    u8 d;
    int y;

    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 9, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xA, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xB, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xC, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xD, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xE, 0);
    if (firstEntry != 0xFF) {
        firstEntry = (u8)ZKNSEARCH_MAIN_GetListIndexB((uptr)work, firstEntry);
        d = (u8)(firstEntry - cur < 0 ? -(firstEntry - cur) : firstEntry - cur);
        if (firstEntry < cur) {
            if (d <= 8) {
                ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xB, 1);
                y = (8 - d) * 0x18 + 0xC;
                ZKNSEARCH_MAIN_SetActorSurfacePos(work, 0xB, 0x8C, (s16)y, 1);
                ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xD, 1);
                ZKNSEARCH_MAIN_SetActorSurfacePos(work, 0xD, 0x8C, (s16)y, 1);
            }
        } else if (d <= 7) {
            ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 9, 1);
            ZKNSEARCH_MAIN_SetActorSurfacePos(work, 9, 0x8C, (s16)(d * 0x18 + 0xC), 0);
        }
    }
    if (secondEntry != 0xFF) {
        secondEntry = (u8)ZKNSEARCH_MAIN_GetListIndexB((uptr)work, secondEntry);
        d = (u8)(secondEntry - cur < 0 ? -(secondEntry - cur) : secondEntry - cur);
        if (secondEntry < cur) {
            if (d <= 8) {
                ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xC, 1);
                y = (8 - d) * 0x18 + 0xC;
                ZKNSEARCH_MAIN_SetActorSurfacePos(work, 0xC, 0x8C, (s16)y, 1);
                ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xE, 1);
                ZKNSEARCH_MAIN_SetActorSurfacePos(work, 0xE, 0x8C, (s16)y, 1);
            }
        } else if (d <= 7) {
            ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xA, 1);
            ZKNSEARCH_MAIN_SetActorSurfacePos(work, 0xA, 0x8C, (s16)(d * 0x18 + 0xC), 0);
        }
    }
}



void ZKNSEARCH_MAIN_PlaceColumnActor3(char *work, int y, int flag)
{
    int coord;
    if (flag == 1) {
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 9, 1);
        coord = y + 20;
        ZKNSEARCH_MAIN_SetActorSurfacePos(work, 9, 0x8c, coord, 0);
    } else {
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 11, 1);
        coord = y + 20;
        ZKNSEARCH_MAIN_SetActorSurfacePos(work, 11, 0x8c, coord, 1);
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 13, 1);
        ZKNSEARCH_MAIN_SetActorSurfacePos(work, 13, 0x8c, coord, 1);
    }
}



void ZKNSEARCH_MAIN_PlaceColumnActor4(char *work, int i, int flag)
{
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 9, flag);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 11, 0);
    ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 13, 0);
    if (flag == 1)
        ZKNSEARCH_MAIN_SetActorSurfacePos(work, 9, 0x8c, (short)(i * 40 + 20), 0);
}



void ZKNSEARCH_MAIN_PlaceScrollActor(char *ctx, int slot, int index)
{
    unsigned center = FRAME_LIST_GetScrollPos((struct FrameList *)(*(char * *)&((ZknSearchWork *)ctx)->frameList));
    signed short lower = center - 7;
    signed short upper = center + 7;
    if (lower < 0) lower = 0;
    if (index >= lower && index < center) {
        ZKNSEARCH_MAIN_PlaceColumnActor(ctx, slot, (signed short)(192 - (center - index) * 24), 0);
    } else if (index >= center && index < upper) {
        ZKNSEARCH_MAIN_PlaceColumnActor(ctx, slot, (signed short)((index - center) * 24), 1);
    }
}



void ZKNSEARCH_MAIN_PlaceScrollActor2(char *ctx)
{
    unsigned center = FRAME_LIST_GetScrollPos((struct FrameList *)(*(char * *)&((ZknSearchWork *)ctx)->frameList));
    int index = (*(unsigned char ***)(ctx))[2][6];
    signed short lower = index - 4;
    signed short upper = index + 4;
    if (lower < 0) lower = 0;
    if (index >= lower && index < center) {
        ZKNSEARCH_MAIN_PlaceColumnActor3(ctx, (signed short)(192 - (center - index) * 40), 0);
    } else if (index >= center && index < upper) {
        ZKNSEARCH_MAIN_PlaceColumnActor3(ctx, (signed short)((index - center) * 40), 1);
    }
}



/*
 * lever: unsigned long slot keeps updates in its home; enum y keeps the wide updated value and repeats s16 call truncation. int/short variants sank or cached updates (110–118 B); check3b EXACT 108 B.
 */
void ZKNSEARCH_MAIN_PlacePageActor(char *ctx, unsigned long slot, YCoord y, int flag)
{
    unsigned long second;
    if (flag == 1) {
        slot += 15;
        ZKNSEARCH_MAIN_SetActorVisible((sptr)ctx, (unsigned)slot, (unsigned)1);
        y += 20;
        ZKNSEARCH_MAIN_SetActorSurfacePos(ctx, (unsigned)slot, (unsigned short)204, y, 0);
    } else {
        second = slot + 29;
        ZKNSEARCH_MAIN_SetActorVisible((sptr)ctx, (unsigned)second, (unsigned)1);
        y += 20;
        ZKNSEARCH_MAIN_SetActorSurfacePos(ctx, (unsigned)second, (unsigned short)204, y, 1);
        slot += 43;
        ZKNSEARCH_MAIN_SetActorVisible((sptr)ctx, (unsigned)slot, (unsigned)1);
        ZKNSEARCH_MAIN_SetActorSurfacePos(ctx, (unsigned)slot, (unsigned short)204, y, 1);
    }
}




void ZKNSEARCH_MAIN_MoveColumnActors(int work, int deltaY)
{
    unsigned i;
    short pos[2];

    for (i = 9; i <= 10; i++) {
        if (ZKNSEARCH_MAIN_GetActorVisible(work, i) != 0) {
            int t;

            ZKNSEARCH_MAIN_GetActorSurfacePos((char *)work, i, &pos[1], &pos[0], 0);
            ZKNSEARCH_MAIN_SetActorSurfacePos((char *)work, i, (short)pos[1], (short)(pos[0] + deltaY), (int)0);
            t = pos[0] + deltaY;
            if (t <= -12 || t >= 0xcc)
                ZKNSEARCH_MAIN_SetActorVisible((int)work, i, 0);
        }
    }
    for (i = 11; i <= 12; i++) {
        if (ZKNSEARCH_MAIN_GetActorVisible(work, i) != 0) {
            int t;

            ZKNSEARCH_MAIN_GetActorSurfacePos((char *)work, i, &pos[1], &pos[0], 1);
            ZKNSEARCH_MAIN_SetActorSurfacePos((char *)work, i, (short)pos[1], (short)(pos[0] + deltaY), (int)1);
            ZKNSEARCH_MAIN_SetActorSurfacePos((char *)work, i + 2, (short)pos[1], (short)(pos[0] + deltaY), (int)1);
            t = pos[0] + deltaY;
            if (t <= -12 || t >= 0xcc) {
                ZKNSEARCH_MAIN_SetActorVisible((int)work, i, 0);
                ZKNSEARCH_MAIN_SetActorVisible((int)work, i + 2, 0);
            }
        }
    }
}




void ZKNSEARCH_MAIN_MoveScrollActors(char *work, int dx)
{
    u32 i;
    struct { short x; short y; } pos;

    for (i = 0xF; i < 0x1D; i++) {
        if (ZKNSEARCH_MAIN_GetActorVisible((sptr)work, i)) {
            ZKNSEARCH_MAIN_GetActorSurfacePos(work, i, &pos.y, &pos.x, 0);
            ZKNSEARCH_MAIN_SetActorSurfacePos(work, i, pos.y, (short)(pos.x + dx), 0);
            if (pos.x + dx <= -20 || pos.x + dx >= 0xDC) {
                ZKNSEARCH_MAIN_SetActorVisible((sptr)work, i, 0);
            }
        }
    }
    ZKNSEARCH_MAIN_GetActorSurfacePos(work, 9, &pos.y, &pos.x, 0);
    ZKNSEARCH_MAIN_SetActorSurfacePos(work, 9, pos.y, (short)(pos.x + dx), 0);
    if (pos.x + dx <= -20 || pos.x + dx >= 0xDC) {
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 9, 0);
    }
    for (i = 0x1D; i < 0x2B; i++) {
        if (ZKNSEARCH_MAIN_GetActorVisible((sptr)work, i)) {
            ZKNSEARCH_MAIN_GetActorSurfacePos(work, i, &pos.y, &pos.x, 1);
            ZKNSEARCH_MAIN_SetActorSurfacePos(work, i, pos.y, (short)(pos.x + dx), 1);
            ZKNSEARCH_MAIN_SetActorSurfacePos(work, i + 0xE, pos.y, (short)(pos.x + dx), 1);
            if (pos.x + dx <= -28 || pos.x + dx >= 0xD4) {
                ZKNSEARCH_MAIN_SetActorVisible((sptr)work, i, 0);
                ZKNSEARCH_MAIN_SetActorVisible((sptr)work, (int)i + 0xE, 0);
            }
        }
    }
    ZKNSEARCH_MAIN_GetActorSurfacePos(work, 0xB, &pos.y, &pos.x, 1);
    ZKNSEARCH_MAIN_SetActorSurfacePos(work, 0xB, pos.y, (short)(pos.x + dx), 1);
    ZKNSEARCH_MAIN_SetActorSurfacePos(work, 0xD, pos.y, (short)(pos.x + dx), 1);
    if (pos.x + dx <= -28 || pos.x + dx >= 0xD4) {
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xB, 0);
        ZKNSEARCH_MAIN_SetActorVisible((sptr)work, 0xD, 0);
    }
}




void ZKNSEARCH_MAIN_PlaceProgressActor(int work, int progress)
{
    ZKNSEARCH_MAIN_SetActorVisible((int)work, 8, 1);
    ZKNSEARCH_MAIN_SetActorSurfacePos((char *)work, 8, (short)(progress * 2 + 8), 0xa8, (int)0);
}



void ZKNSEARCH_MAIN_InitCursorMove(char *ctx, int index)
{
    if (UI_GetInputMode() == 1) {
        ((ZknSearchWork *)ctx)->cursorMove = CURSOR_MOVE_Create((struct CursorEntry *)d_021C0B60, (struct CursorVtbl *)d_021C0B14, (uptr)ctx, 0, index, 123);
    } else {
        ((ZknSearchWork *)ctx)->cursorMove = CURSOR_MOVE_Create((struct CursorEntry *)d_021C0B60, (struct CursorVtbl *)d_021C0B14, (uptr)ctx, 1, index, 123);
        ZKNSEARCH_MAIN_SetCursorTile((sptr)ctx, index, 3);
    }
    CURSOR_MOVE_EnableInput(((ZknSearchWork *)ctx)->cursorMove);
}




void ZKNSEARCH_MAIN_DeleteCursorMove(int work)
{
    int *q = (int *)work;

    if (q[0xac] != 0) {
        CURSOR_MOVE_Delete((void *)q[0xac]);
        q[0xac] = 0;
    }
}




/*
 * note:     CURSOR_MOVE_GetEntry takes (record, a); passing a as the second argument keeps r1 live,
 *           so the 0x2B0 offset lands in r2.
 */
void ZKNSEARCH_MAIN_SetCursorTile(int work, unsigned int index, unsigned int fill)
{
    u8 *t;
    int *q = (int *)work;

    if (index > 6)
        return;
    t = (u8 *)CURSOR_MOVE_GetEntry((struct Cursor *)q[0xac], index);
    BG_SYS_FillTileMap(0, t[0], t[1], t[2], t[3], (u8)fill);
    BG_SYS_MarkTileDirty(0);
}




u32 ZKNSEARCH_MAIN_PollMenuInput(int work)
{
    int *q = (int *)work;
    int r = CURSOR_MOVE_PollRepeatInput((struct Cursor *)q[0xac]);
    unsigned k;

    if (r != -1)
        return r;
    k = KEY_GetTrg();
    if (k & 0x400) {
        UI_SetInputMode(0);
        return 8;
    }
    k = KEY_GetTrg();
    if (k & 0x800) {
        if (UI_GetInputMode() == 1)
            CURSOR_MOVE_SetState((struct Cursor *)q[0xac], 1);
        UI_SetInputMode(0);
        return 7;
    }
    k = KEY_GetTrg();
    if (k & 8) {
        if (UI_GetInputMode() == 1)
            CURSOR_MOVE_SetState((struct Cursor *)q[0xac], 1);
        UI_SetInputMode(0);
        ZKNSEARCH_MAIN_MoveCursor(work, 5);
        return 5;
    }
    k = KEY_GetTrg();
    if (k & 4) {
        if (UI_GetInputMode() == 1)
            CURSOR_MOVE_SetState((struct Cursor *)q[0xac], 1);
        UI_SetInputMode(0);
        ZKNSEARCH_MAIN_MoveCursor(work, 6);
        return 6;
    }
    if (KEY_GetTrg() != 0 && UI_GetInputMode() == 1) {
        UI_SetInputMode(0);
        CURSOR_MOVE_SetState((struct Cursor *)q[0xac], 1);
        return -4;
    }
    return r;
}




void ZKNSEARCH_MAIN_MoveCursor(int work, unsigned index)
{
    int *q = (int *)work;

    ZKNSEARCH_MAIN_SetCursorTile(work, CURSOR_MOVE_GetCurrent((struct Cursor *)q[0xac]), 1);
    ZKNSEARCH_MAIN_SetCursorTile(work, index, 3);
    CURSOR_MOVE_SetCurrent((struct Cursor *)q[0xac], (unsigned char)index);
}




void ZKNSEARCH_MAIN_SetCursor(int work, unsigned index)
{
    unsigned r = KEY_GetTrg();

    if ((r & 2) && !(r & 0xf1))
        return;
    ZKNSEARCH_MAIN_SetCursorTile(work, index, 3);
    BLINK_PALANM_ResetPhase((struct BlinkPalAnm *)(((int *)work)[0xad]));
}




void ZKNSEARCH_MAIN_DeselectCursor(int work, unsigned index, unsigned prevIndex)
{
    ZKNSEARCH_MAIN_SetCursorTile(work, prevIndex, 1);
    ZKNSEARCH_MAIN_SetCursorTile(work, index, 1);
}




void ZKNSEARCH_MAIN_SelectCursor(int work, unsigned index, unsigned prevIndex)
{
    ZKNSEARCH_MAIN_SetCursorTile(work, prevIndex, 1);
    ZKNSEARCH_MAIN_SetCursorTile(work, index, 3);
    BLINK_PALANM_ResetPhase((struct BlinkPalAnm *)(((int *)work)[0xad]));
}




void ZKNSEARCH_MAIN_UpdateCursor(int work, unsigned index, unsigned prevIndex)
{
    ZKNSEARCH_MAIN_SetCursorTile(work, prevIndex, 1);
    if (index == 7)
        CURSOR_MOVE_SetCurrent((struct Cursor *)(((int *)work)[0xac]), (unsigned char)prevIndex);
}



int ZKNSEARCH_MAIN_WaitConfirmInput(unsigned char *ctx)
{
    if (ctx[0x2bb] == 90) {
        ctx[0x2bb] = 0;
        return 1;
    }
    ctx[0x2bb]++;
    if (TOUCHPANEL_GetTrg()) {
        UI_SetInputMode(1);
        ctx[0x2bb] = 0;
        return 1;
    }
    if (KEY_GetTrg() & 3) {
        UI_SetInputMode(0);
        ctx[0x2bb] = 0;
        return 1;
    }
    return 0;
}



int ZKNSEARCH_MAIN_PollListInput(char *ctx)
{
    int result = TOUCHPANEL_HitTrg((const TouchHitTable *)d_021C0B3C);
    if (result != -1) {
        UI_SetInputMode(1);
        return result;
    }
    if (KEY_GetTrg() & 2) {
        UI_SetInputMode(0);
        return 8;
    }
    if (KEY_GetTrg() & 8) {
        UI_SetInputMode(0);
        return 8;
    }
    if (KEY_GetTrg() & 4) {
        if (UI_GetInputMode() == 1) {
            UI_SetInputMode(0);
            FRAME_LIST_ShowCursor(((ZknSearchWork *)ctx)->frameList);
        }
        return 9;
    }
    return result;
}



int ZKNSEARCH_MAIN_PollListInput2(char *ctx)
{
    int result = TOUCHPANEL_HitTrg((const TouchHitTable *)d_021C0B24);
    if (result != -1) { UI_SetInputMode(1); return result; }
    if (KEY_GetTrg() & 2) { UI_SetInputMode(0); return 8; }
    if (KEY_GetTrg() & 8) { UI_SetInputMode(0); return 8; }
    if (KEY_GetTrg() & 4) {
        if (UI_GetInputMode() == 1) {
            UI_SetInputMode(0);
            FRAME_LIST_ShowCursor(((ZknSearchWork *)ctx)->frameList);
        }
        return 9;
    }
    return result;
}
