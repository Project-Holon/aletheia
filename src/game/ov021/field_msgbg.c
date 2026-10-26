/*
 * file:     field_msgbg.c
 * unit:     yes
 * function: FIELD_MSGBG_Create, FIELD_MSGBG_SetupBg, FIELD_MSGBG_SetupBgDelayed, FIELD_MSGBG_LoadWindowGraphics, FIELD_MSGBG_LoadWindowGraphicsStep, FIELD_MSGBG_Delete, FIELD_MSGBG_ReleaseBg, FIELD_MSGBG_ReleaseSysFrame, FIELD_MSGBG_SetupBgSingle, FIELD_MSGBG_IsSetupDone, FIELD_MSGBG_Main, FIELD_MSGBG_DrawTalkSys, FIELD_MSGBG_ClearPrintQue, FIELD_MSGBG_IsPrintQueFinished, FIELD_MSGBG_GetPrintQue, FIELD_MSGBG_GetFont, FIELD_MSGBG_CreateMsgData, FIELD_MSGBG_DeleteMsgData, FIELD_MSGBG_RequestSysFrame, FIELD_MSGBG_SetAutoMode, FIELD_MSGBG_AddMsgPrint, FIELD_MSGBG_DeleteMsgPrint, FIELD_MSGBG_MsgPrintPrintMsg, FIELD_MSGBG_MsgPrintPrintStr, FIELD_MSGBG_MsgPrintPrintStrColorFont, FIELD_MSGBG_MsgPrintPrintStrColor, FIELD_MSGBG_IsMsgPrintTransDone, FIELD_MSGBG_ClearMsgPrint, FIELD_MSGBG_FillMsgPrint, FIELD_MSGBG_GetMsgPrintQue, FIELD_MSGBG_GetMsgPrintUtil, FIELD_MSGBG_CreateMsgWinPalette, FIELD_MSGBG_CreateMsgWin, FIELD_MSGBG_DeleteMsgWin, FIELD_MSGBG_MsgWinPrintMsg, FIELD_MSGBG_MsgWinPrintStr, FIELD_MSGBG_MsgWinPrintStrColorFont, FIELD_MSGBG_IsMsgWinTransDone, FIELD_MSGBG_ClearMsgWin, FIELD_MSGBG_FillMsgWin, FIELD_MSGBG_CreateBottomMsgWin, FIELD_MSGBG_GetMsgWinBmpWin, FIELD_MSGBG_CreateInfoMsgWin, FIELD_MSGBG_DeleteInfoMsgWin, FIELD_MSGBG_InfoMsgWinPrintStr, FIELD_MSGBG_ClearInfoMsgWin, FIELD_MSGBG_CreateMenuFuncPalette, FIELD_MSGBG_CreateMenuFuncCallback, FIELD_MSGBG_CreateMenuFuncPos, FIELD_MSGBG_CreateMenuFunc, FIELD_MSGBG_CreateMenuFuncWork, FIELD_MSGBG_DeleteMenuFunc, FIELD_MSGBG_MenuFuncMain, FIELD_MSGBG_RewriteMenuFunc, FIELD_MSGBG_CreateMenuItems, FIELD_MSGBG_CreateMenuItemsFromTable, FIELD_MSGBG_AddMenuItemStr, FIELD_MSGBG_DeleteMenuItems, FIELD_MSGBG_GetMenuItemsMaxWidth, FIELD_MSGBG_GetMenuItemCount, FIELD_MSGBG_GetMenuItemsWidthChars, FIELD_MSGBG_GetMenuHeightChars, FIELD_MSGBG_SetMenuHeaderRect, FIELD_MSGBG_DrawMenuFuncFrame, FIELD_MSGBG_MakeListHeader, FIELD_MSGBG_CreateYesNoMenu, FIELD_MSGBG_YesNoMenuMain, FIELD_MSGBG_CreateMsgStreamColor, FIELD_MSGBG_MsgStreamCallback, FIELD_MSGBG_CreateMsgStream, FIELD_MSGBG_DeleteMsgStream, FIELD_MSGBG_MsgStreamMain, FIELD_MSGBG_CreateSysWin, FIELD_MSGBG_DeleteSysWin, FIELD_MSGBG_SysWinPrintMsg, FIELD_MSGBG_SysWinPrintStr, FIELD_MSGBG_SysWinMain, FIELD_MSGBG_CreateBottomSysWin, FIELD_MSGBG_ClearSysWin, FIELD_MSGBG_GetSysWinBmpWin, FIELD_MSGBG_CreateInfoSysWin, FIELD_MSGBG_DeleteInfoSysWin, FIELD_MSGBG_InfoSysWinPrintMsg, FIELD_MSGBG_InfoSysWinPrintStr, FIELD_MSGBG_InfoSysWinMain, FIELD_MSGBG_SysWinDrawCursor, FIELD_MSGBG_ClearInfoSysWin, FIELD_MSGBG_InfoSysWinPrintStrNow, FIELD_MSGBG_GetInfoSysWinBmpWin, FIELD_MSGBG_SetupTalkWin, FIELD_MSGBG_AddTalkWin, FIELD_MSGBG_DeleteTalkWin, FIELD_MSGBG_WaitTalkWinClose, FIELD_MSGBG_ClearTalkWin, FIELD_MSGBG_TalkWinPrintStr, FIELD_MSGBG_TalkWinMain, FIELD_MSGBG_TalkWinDrawCursor, FIELD_MSGBG_SetupPlainWin, FIELD_MSGBG_CreatePlainWin, FIELD_MSGBG_DeletePlainWin, FIELD_MSGBG_ClearPlainWin, FIELD_MSGBG_OpenPlainWin, FIELD_MSGBG_PlainWinPrintMsg, FIELD_MSGBG_PlainWinPrintStr, FIELD_MSGBG_PlainWinPrintStrColor, FIELD_MSGBG_PlainWinPrintStream, FIELD_MSGBG_PlainWinMain, FIELD_MSGBG_PlainWinDrawCursor, FIELD_MSGBG_GetPlainWinStreamState, FIELD_MSGBG_SetupSubMsgWin, FIELD_MSGBG_GetStrSizeChars, FIELD_MSGBG_AddSubMsgWinMsg, FIELD_MSGBG_AddSubMsgWinStr, FIELD_MSGBG_FreeSubMsgWin, FIELD_MSGBG_DeleteSubMsgWin, FIELD_MSGBG_DeleteAllSubMsgWin, FIELD_MSGBG_ExistsSubMsgWin, FIELD_MSGBG_SubMsgWinMain, FIELD_MSGBG_CreateBgWin, FIELD_MSGBG_CreateBgWinFont, FIELD_MSGBG_DeleteBgWin, FIELD_MSGBG_BgWinMain, FIELD_MSGBG_LoadBgWinGraphics, FIELD_MSGBG_DrawBgWinFrame, FIELD_MSGBG_ClearBgWinFrame, FIELD_MSGBG_IsLineMissing, FIELD_MSGBG_PrintTwoLines, FIELD_MSGBG_RollLines, FIELD_MSGBG_LoadSpWinPalette, FIELD_MSGBG_LoadFrameTile, FIELD_MSGBG_DrawFrameBmp, FIELD_MSGBG_PrintLines, FIELD_MSGBG_CreateSpWin, FIELD_MSGBG_DeleteSpWin, FIELD_MSGBG_SpWinPrintStr, FIELD_MSGBG_SpWinWaitKey, FIELD_MSGBG_GetStrWidthChars, FIELD_MSGBG_GetStrHeightChars, FIELD_MSGBG_CreateCursor, FIELD_MSGBG_DeleteCursor, FIELD_MSGBG_InitCursor, FIELD_MSGBG_ExitCursor, FIELD_MSGBG_IsCursorDrawn, FIELD_MSGBG_ClearCursor, FIELD_MSGBG_DrawCursor, FIELD_MSGBG_AnimateCursor, FIELD_MSGBG_AnimateCursorOnFrame, FIELD_MSGBG_LoadSysWindowFrameGraphics, FIELD_MSGBG_DrawSysWindowFrame, FIELD_MSGBG_CreateSysFrameWindow, FIELD_MSGBG_ClearSysWindowFrame, FIELD_MSGBG_DeleteSysFrameWindow, FIELD_MSGBG_InitBgTwoLayerTalk, FIELD_MSGBG_InitBgTwoLayer, FIELD_MSGBG_InitBgOneLayer, FIELD_MSGBG_VblankTalkSysTask, FIELD_MSGBG_SetupSysFrameBg, FIELD_MSGBG_SetupSysFrame, FIELD_MSGBG_LoadWindowGraphicsAll, FIELD_MSGBG_LoadWindowGraphicsStepFn, FIELD_MSGBG_SetBlend, FIELD_MSGBG_SetBlendThunk, FIELD_MSGBG_ReloadBg, FIELD_MSGBG_CreateWindow, FIELD_MSGBG_DeleteWindow, FIELD_MSGBG_LoadMenuGraphicsLower, FIELD_MSGBG_LoadMenuGraphicsUpper, FIELD_MSGBG_StoreSubMsgWin, FIELD_MSGBG_RemoveSubMsgWin, FIELD_MSGBG_KeyWaitInit, FIELD_MSGBG_KeyWaitReset, FIELD_MSGBG_KeyWaitSetAuto, FIELD_MSGBG_KeyWaitGetAuto, FIELD_MSGBG_KeyWaitGetCharWait, FIELD_MSGBG_KeyWaitCheckSkip, FIELD_MSGBG_KeyWaitCheckAdvance, FIELD_MSGBG_StreamSetSpeed
 * address:  0x021901EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Includes the former unit_02192860.c and unit_02192CF0.c (0x02192860..0x021932BF).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   d_021DDA50  0x021DDA50  data  ov021  a4
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   TALKMSGWIN_Delete  0x02194798  thumb  ov021
 *   TCBL_Destroy  0x02031140  arm
 *   BG_SYS_FreeTiles  0x02040DA8  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   STRBUF_Delete  0x02045808  arm
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   TCBL_Main  0x020310C4  arm
 *   TALKMSGWIN_Update  0x0219470C  thumb  ov021
 *   TALKMSGWIN_EndUpdate  0x02194760  thumb  ov021
 *   TALKMSGWIN_Draw  0x02194764  thumb  ov021
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BMP_FillRect  0x02043AF4  arm  arm9
 *   BMP_MENULIST_Create  0x0201FF30  thumb
 *   BMP_MENULIST_ResetCursorTile  0x02020CF8  thumb
 *   BMP_MENULIST_SetCancelDisabled  0x02020D10  thumb  arm9
 *   BMP_MENULIST_Delete  0x0202020C  thumb
 *   BMP_MENUWORK_Delete  0x0201F868  thumb
 *   BMP_MENULIST_Main  0x020200CC  thumb  arm9
 *   BMP_MENULIST_Redraw  0x02020234  thumb
 *   BMP_MENUWORK_Create  0x0201F81C  thumb
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 *   BMP_MENUWORK_AddStrItem  0x0201F898  thumb
 *   BMP_MENUWORK_ReleaseItems  0x0201F8F4  thumb
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb
 *   BMP_MENUWORK_CountItems  0x0201F91C  thumb
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   sYesNoMenuHeader     0x021D3F38  data   ov021  a4
 *   sYesNoMenuItems     0x021D3E68  data   ov021  a4
 *   PRINTSYS_PrintStreamCallBack  0x0201CD10  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   GFL_USE_IsAnySeBusy  0x02006238  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb
 *   PRINTSYS_PrintStreamGetWaitKind  0x0201CE34  thumb
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetCont  0x0203630C  arm
 *   TALKMSGWIN_SetupUpperBalloon  0x02194848  thumb  ov021
 *   TALKMSGWIN_SetupLowerBalloon  0x02194888  thumb  ov021
 *   TALKMSGWIN_SetupAutoBalloon  0x021948CC  thumb  ov021
 *   TALKMSGWIN_Open  0x02194940  thumb  ov021
 *   TALKMSGWIN_Close  0x02194950  thumb  ov021
 *   TALKMSGWIN_IsFree  0x02194960  thumb  ov021
 *   TALKMSGWIN_Release  0x0219492C  thumb  ov021
 *   TALKMSGWIN_GetBmpWin  0x02194990  thumb  ov021
 *   TALKMSGWIN_Reprint  0x0219499C  thumb  ov021
 *   TALKMSGWIN_IsShown  0x02194974  thumb  ov021
 *   TALKMSGWIN_GetPrintStream  0x02194984  thumb  ov021
 *   BG_SYS_ChangeScrollImmediate  0x02040618  arm
 *   TALKMSGWIN_AddFrameWindow  0x02194A00  thumb  ov021
 *   TALKMSGWIN_DeleteFrameWindow  0x02194A48  thumb  ov021
 *   TALKMSGWIN_ClearWindowFrame  0x02194A34  thumb  ov021
 *   TALKMSGWIN_SetupPlainWindow  0x021947E8  thumb  ov021
 *   PRINTSYS_CountLines  0x0201D42C  thumb  arm9
 *   STRBUF_GetLength  0x020458F8  arm
 *   STRBUF_Copy  0x02045838  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_Create  0x02043678  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   BMP_WIN_GetHeight  0x02045740  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_Delete  0x020437AC  arm
 *   BMP_CopyPixels  0x02043814  arm
 *   ARC_UTIL_UploadBgCharFromArchive  0x02049624  arm
 *   ARC_UTIL_UploadPaletteFromArchive  0x02049B90  arm
 *   PRINTSYS_CopyLine  0x0201D37C  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   BMP_GetWidth  0x020437DC  arm  arm9
 *   BMP_GetHeight  0x020437E4  arm  arm9
 *   BMP_Blit  0x020439A0  arm  arm9
 *   BMP_GetPixels  0x020437D4  arm  arm9
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm  arm9
 *   NNS_G2dGetUnpackedCharacterDataEx  0x02062A4C  arm  arm9
 *   MI_CpuCopy  0x02082EA4  arm  arm9
 *   GF_FONT_GetLineHeight  0x0201DC80  thumb
 *   STRBUF_Clone  0x02045874  arm
 *   BMP_CreateFromBuffer  0x020436FC  arm  arm9
 *   sCursorOffsetY     0x021D3E50  data   ov021  a1
 *   d_021D3E60     0x021D3E60  data  a2
 *   d_021D3E58     0x021D3E58  data  a2
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   TALKMSGWIN_Create  0x02194670  thumb  ov021
 *   TALKMSGWIN_LoadTexture  0x02194704  thumb  ov021
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   d_021D3E98     0x021D3E98  data  a4
 *   d_021D3E78     0x021D3E78  data  a4
 *   d_021D3ED8     0x021D3ED8  data  a4
 *   d_021D3EF8     0x021D3EF8  data  a4
 *   d_021D3EB8     0x021D3EB8  data  a4
 *   GFL_USE_IsCardIrqEnabled  0x02005C8C  thumb  arm9
 *   TCB_DeleteTask  0x02030EAC  arm  arm9
 *   BG_SYS_SetPriority  0x0204047C  arm
 *   d_021D3F18     0x021D3F18  data  a4
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   TALKMSGWIN_ReloadFrameGraphics  0x02195588  thumb  ov021
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   BMP_MENUWORK_GetPlttFileId  0x0201F548  thumb  arm9
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 *   MSG_SPEED_GetWaitForSpeed  0x02013080  thumb  arm9
 *   PRINTSYS_PrintStreamSetSpeed  0x0201CE8C  thumb  arm9
 *   PRINTSYS_PrintStreamResetSpeed  0x0201CEB8  thumb  arm9
 *   TCBL_Create  0x0203101C  arm  arm9
 */
#include "field_msgbg_types.h"
#include "../sdk_ioreg.h"
#include "talkmsgwin_types.h"

/* Cursor y offsets per animation frame. */
typedef struct FieldMsgCursorOffsets {
    u16 offsetY[3];
} FieldMsgCursorOffsets;

#define REG_BG2CNT (*(volatile u16 *)REG_BG2CNT_ADDR)

#define PAD_BUTTON_AB 0x0003 /* A and B */

/* windowKind values */
#define FIELD_MSGBG_PALETTE_SYSTEM 0xE
#define FIELD_MSGBG_PALETTE_TALK 0xB

/* Image of a BG template (struct BgTemplate, 8 words) as copied from the overlay data. */
typedef struct FieldBgTemplate {
    u32 word[8];
} FieldBgTemplate;

struct BgTemplate;

struct TcbTask;
struct TextPrinter;
struct PrintQueue;
struct TcblSystem;
struct NitroFileHeader;
struct TcbTask;
struct MsgBank;
struct MenuTemplate;
struct BmpMenuList;
#include "../arm9/bg_sys.h"
#include "../arm9/g2.h"
#include "../arm9/gfl_use.h"
#include "talkmsgwin.h"
#include "../arm9/tcb_list.h"
#include "../arm9/arc_util.h"
#include "../arm9/bmp_menuwork.h"
#include "../arm9/msg_speed.h"
#ifdef __MWERKS__
#define PRINTSYS_PrintStreamCallBack PRINTSYS_PrintStreamCallBack_header
#endif
#include "../arm9/printsys.h"
#ifdef __MWERKS__
#undef PRINTSYS_PrintStreamCallBack
#endif
#include "../arm9/mi_memory.h"
#include "../arm9/key.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gf_font.h"
#include "../arm9/tcbl.h"
#include "../arm9/nns_g2d_anim_bank.h"
#include "../arm9/strbuf.h"
#include "../arm9/bmp_win.h"
#include "../arm9/msgdata.h"
#include "../arm9/bmp_menulist.h"

extern const FieldMsgCursorOffsets d_021D3E60;
extern const FieldMsgCursorOffsets d_021D3E58;
extern const FieldBgTemplate d_021D3E98;
extern const FieldBgTemplate d_021D3E78;
extern const FieldBgTemplate d_021D3ED8;
extern const FieldBgTemplate d_021D3EF8;
extern const FieldBgTemplate d_021D3EB8;
extern const FieldBgTemplate d_021D3F18;

extern void FIELD_MSGBG_KeyWaitInit(FieldMsgKeyWait *keyWait);
extern void FIELD_MSGBG_InitBgTwoLayerTalk(FieldMsgBg *msgBg, int loadTalkSys);
extern void FIELD_MSGBG_InitBgTwoLayer(FieldMsgBg *msgBg, int loadTalkSys);
extern void FIELD_MSGBG_VblankTalkSysTask(struct TcbTask *task, void *msgBg);
extern void FIELD_MSGBG_LoadWindowGraphicsAll(int bgFrame, u16 heapId);
extern void FIELD_MSGBG_LoadWindowGraphicsStepFn(int bgFrame, u16 heapId, int step);
extern void FIELD_MSGBG_InitBgOneLayer(FieldMsgBg *msgBg);
extern void FIELD_MSGBG_KeyWaitSetAuto(FieldMsgKeyWait *keyWait, u8 autoMode);
typedef short s16_p07;
#include "../arm9/bmp.h"
extern void FIELD_MSGBG_SetupSysFrame(FieldMsgBg *msgBg);
extern struct BmpWin *FIELD_MSGBG_CreateWindow(int frame, int unusedHeapId, int x, int y, u16 width, u16 height, u16 palette);
extern void FIELD_MSGBG_LoadMenuGraphicsLower(u32 heapId);
extern void FIELD_MSGBG_SetBlend(u32 enable);
extern void FIELD_MSGBG_LoadMenuGraphicsUpper(u32 heapId);
extern int FIELD_MSGBG_DeleteWindow(struct BmpWin *bmpWin);
extern struct BmpWin *FIELD_MSGBG_CreateSysFrameWindow(u8 x, u8 y, u8 width, u8 height, u16 heapId);
extern void FIELD_MSGBG_DeleteSysFrameWindow(struct BmpWin *bmpWin);
#ifdef __MWERKS__
extern struct TextPrinter *PRINTSYS_PrintStreamCallBack(struct BmpWin *bmpWin, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, s32 wait,
                                         struct Tcbl *tcbl, u32 tcblPri, u16 heapId, u16 clearColor, int (*callback)(int));
#endif
extern void FIELD_MSGBG_KeyWaitReset(FieldMsgKeyWait *keyWait);
extern int FIELD_MSGBG_KeyWaitCheckSkip(FieldMsgKeyWait *keyWait);
extern int FIELD_MSGBG_KeyWaitCheckAdvance(FieldMsgKeyWait *keyWait, u32 streamParam);
extern u8 FIELD_MSGBG_KeyWaitGetAuto(FieldMsgKeyWait *keyWait);
extern void FIELD_MSGBG_StreamSetSpeed(struct TextPrinter *stream, int fast);
extern u32 FIELD_MSGBG_KeyWaitGetCharWait(FieldMsgKeyWait *keyWait);
extern void FIELD_MSGBG_AnimateCursor(FieldMsgCursor *cursor, struct Bmp *bmp, u32 color);
extern int FIELD_MSGBG_StoreSubMsgWin(FieldMsgBg *msgBg, FieldSubMsgWin *subMsgWin);
extern FieldSubMsgWin *FIELD_MSGBG_RemoveSubMsgWin(FieldMsgBg *msgBg, u32 id);
extern void FIELD_MSGBG_AnimateCursorOnFrame(FieldMsgCursor *cursor, struct Bmp *bmp, struct Bmp *backBmp);

FieldMsgBg *FIELD_MSGBG_Create(u16 heapId, struct G3dCamera *g3dCamera);
void FIELD_MSGBG_SetupBg(FieldMsgBg *msgBg);
void FIELD_MSGBG_SetupBgDelayed(FieldMsgBg *msgBg);
void FIELD_MSGBG_LoadWindowGraphics(u32 bgFrame, u16 heapId);
void FIELD_MSGBG_LoadWindowGraphicsStep(FieldMsgBg *msgBg, int step);
void FIELD_MSGBG_Delete(FieldMsgBg *msgBg);
void FIELD_MSGBG_ReleaseBg(FieldMsgBg *msgBg);
int FIELD_MSGBG_ReleaseSysFrame(FieldMsgBg *msgBg);
void FIELD_MSGBG_SetupBgSingle(FieldMsgBg *msgBg);
int FIELD_MSGBG_IsSetupDone(FieldMsgBg *msgBg);
void FIELD_MSGBG_Main(FieldMsgBg *msgBg);
void FIELD_MSGBG_DrawTalkSys(FieldMsgBg *msgBg);
void FIELD_MSGBG_ClearPrintQue(FieldMsgBg *msgBg);
int FIELD_MSGBG_IsPrintQueFinished(FieldMsgBg *msgBg);
struct PrintQue *FIELD_MSGBG_GetPrintQue(FieldMsgBg *msgBg);
struct GfFont *FIELD_MSGBG_GetFont(FieldMsgBg *msgBg);
struct MsgBank *FIELD_MSGBG_CreateMsgData(FieldMsgBg *msgBg, u32 fileId);
u32 FIELD_MSGBG_DeleteMsgData(struct MsgBank *msgData);
void FIELD_MSGBG_RequestSysFrame(FieldMsgBg *msgBg);
void FIELD_MSGBG_SetAutoMode(FieldMsgBg *msgBg, u8 autoMode);
FieldMsgPrint *FIELD_MSGBG_AddMsgPrint(FieldMsgBg *msgBg, struct MsgBank *msgData, struct BmpWin *bmpWin);
void FIELD_MSGBG_DeleteMsgPrint(FieldMsgPrint *msgPrint);
void FIELD_MSGBG_MsgPrintPrintMsg(FieldMsgPrint *msgPrint, int x, int y, u32 msgId);
void FIELD_MSGBG_MsgPrintPrintStr(FieldMsgPrint *msgPrint, int x, int y, struct Strbuf *str);
void FIELD_MSGBG_MsgPrintPrintStrColorFont(FieldMsgPrint *msgPrint, int x, int y, struct Strbuf *str, u16 color, struct GfFont *font);
void FIELD_MSGBG_MsgPrintPrintStrColor(FieldMsgPrint *msgPrint, int x, int y, struct Strbuf *str, u16 color);
u32 FIELD_MSGBG_IsMsgPrintTransDone(FieldMsgPrint *msgPrint);
void FIELD_MSGBG_ClearMsgPrint(FieldMsgPrint *msgPrint);
void FIELD_MSGBG_FillMsgPrint(FieldMsgPrint *msgPrint, int x, int y, int width, int height);
struct PrintQue *FIELD_MSGBG_GetMsgPrintQue(FieldMsgPrint *msgPrint);
PrintUtil *FIELD_MSGBG_GetMsgPrintUtil(FieldMsgPrint *msgPrint);
FieldMsgWin *FIELD_MSGBG_CreateMsgWinPalette(FieldMsgBg *msgBg, struct MsgBank *msgData, u16 x, u16 y, u16 width, u16 height, u16 palette);
FieldMsgWin *FIELD_MSGBG_CreateMsgWin(FieldMsgBg *msgBg, struct MsgBank *msgData, u16 x, u16 y, u16 width, u16 height);
int FIELD_MSGBG_DeleteMsgWin(FieldMsgWin *msgWin);
void FIELD_MSGBG_MsgWinPrintMsg(FieldMsgWin *msgWin, int x, int y, u32 msgId);
void FIELD_MSGBG_MsgWinPrintStr(FieldMsgWin *msgWin, int x, int y, struct Strbuf *str);
void FIELD_MSGBG_MsgWinPrintStrColorFont(FieldMsgWin *msgWin, u16 x, u16 y, struct Strbuf *str, u16 color, struct GfFont *font);
int FIELD_MSGBG_IsMsgWinTransDone(FieldMsgWin *msgWin);
void FIELD_MSGBG_ClearMsgWin(FieldMsgWin *msgWin);
void FIELD_MSGBG_FillMsgWin(FieldMsgWin *msgWin, int x, int y, int width, int height);
FieldMsgWin *FIELD_MSGBG_CreateBottomMsgWin(FieldMsgBg *msgBg, struct MsgBank *msgData);
struct BmpWin *FIELD_MSGBG_GetMsgWinBmpWin(FieldMsgWin *msgWin);
FieldMsgWin *FIELD_MSGBG_CreateInfoMsgWin(FieldMsgBg *msgBg, struct MsgBank *msgData, u32 x, u32 y, u16 width, u16 height);
int FIELD_MSGBG_DeleteInfoMsgWin(FieldMsgWin *msgWin);
void FIELD_MSGBG_InfoMsgWinPrintStr(FieldMsgWin *msgWin, int x, int y, struct Strbuf *str);
void FIELD_MSGBG_ClearInfoMsgWin(FieldMsgWin *msgWin);
FieldMenuFunc *FIELD_MSGBG_CreateMenuFuncPalette(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u16 listPos, u16 cursorPos,
                             u16 palette, u32 moveCallback, u32 lineCallback, void *work);
FieldMenuFunc *FIELD_MSGBG_CreateMenuFuncCallback(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u16 listPos, u16 cursorPos,
                             u32 moveCallback, u32 lineCallback, void *work);
FieldMenuFunc *FIELD_MSGBG_CreateMenuFuncPos(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u16 listPos, u16 cursorPos);
FieldMenuFunc *FIELD_MSGBG_CreateMenuFunc(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items);
FieldMenuFunc *FIELD_MSGBG_CreateMenuFuncWork(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u32 moveCallback, void *work,
                             u16 listPos, u16 cursorPos, u32 cancelable);
int FIELD_MSGBG_DeleteMenuFunc(FieldMenuFunc *menu);
int FIELD_MSGBG_MenuFuncMain(FieldMenuFunc *menu);
void FIELD_MSGBG_RewriteMenuFunc(FieldMenuFunc *menu);
struct BmpMenuWork *FIELD_MSGBG_CreateMenuItems(int count, u16 heapId);
struct BmpMenuWork *FIELD_MSGBG_CreateMenuItemsFromTable(const FieldMenuItemData *itemData, int count, struct MsgBank *msgData, u16 heapId);
void FIELD_MSGBG_AddMenuItemStr(struct BmpMenuWork *items, struct Strbuf *str, u32 param, u16 heapId);
void FIELD_MSGBG_DeleteMenuItems(struct BmpMenuWork *items);
u32 FIELD_MSGBG_GetMenuItemsMaxWidth(FieldMsgBg *msgBg, BmpMenuWork *items, u32 *outIndex, u32 margin);
unsigned FIELD_MSGBG_GetMenuItemCount(struct BmpMenuWork *items);
u32 FIELD_MSGBG_GetMenuItemsWidthChars(FieldMsgBg *msgBg, BmpMenuWork *items, u32 fontId, u32 margin);
unsigned FIELD_MSGBG_GetMenuHeightChars(unsigned lines, unsigned fontHeight, unsigned lineSpacing, int scrolls);
FieldMenuHeader *FIELD_MSGBG_SetMenuHeaderRect(FieldMenuHeader *header, u16 itemCount, u16 x, u16 y, u16 width, u16 height);
void FIELD_MSGBG_DrawMenuFuncFrame(FieldMenuFunc *menu);
void FIELD_MSGBG_MakeListHeader(BmpMenuListHeader *listHeader, const FieldMenuHeader *header);
FieldMenuFunc *FIELD_MSGBG_CreateYesNoMenu(FieldMsgBg *msgBg, u32 cursorPos);
int FIELD_MSGBG_YesNoMenuMain(FieldMenuFunc *menu);
FieldMsgStream *FIELD_MSGBG_CreateMsgStreamColor(FieldMsgBg *msgBg, struct Strbuf *str, struct BmpWin *bmpWin, u32 x, u16 y, u32 wait, u16 clearColor);
FieldMsgStreamCbRet FIELD_MSGBG_MsgStreamCallback(FieldMsgStreamCbArg code);
FieldMsgStream *FIELD_MSGBG_CreateMsgStream(FieldMsgBg *msgBg, struct Strbuf *str, struct BmpWin *bmpWin, u32 x, u16 y, u32 wait);
int FIELD_MSGBG_DeleteMsgStream(FieldMsgStream *stream);
int FIELD_MSGBG_MsgStreamMain(FieldMsgStream *stream);
FieldSysWin *FIELD_MSGBG_CreateSysWin(FieldMsgBg *msgBg, struct MsgBank *msgData, u32 x, u16 y, u16 width, u16 height);
int FIELD_MSGBG_DeleteSysWin(FieldSysWin *sysWin);
void FIELD_MSGBG_SysWinPrintMsg(FieldSysWin *sysWin, u32 x, u16 y, u32 msgId);
void FIELD_MSGBG_SysWinPrintStr(FieldSysWin *sysWin, u32 x, u16 y, struct Strbuf *str);
u32 FIELD_MSGBG_SysWinMain(FieldSysWin *sysWin);
FieldSysWin *FIELD_MSGBG_CreateBottomSysWin(FieldMsgBg *msgBg, struct MsgBank *msgData);
void FIELD_MSGBG_ClearSysWin(FieldSysWin *sysWin);
struct BmpWin *FIELD_MSGBG_GetSysWinBmpWin(FieldSysWin *sysWin);
FieldSysWin *FIELD_MSGBG_CreateInfoSysWin(FieldMsgBg *msgBg, struct MsgBank *msgData, u32 y);
int FIELD_MSGBG_DeleteInfoSysWin(FieldSysWin *sysWin);
void FIELD_MSGBG_InfoSysWinPrintMsg(FieldSysWin *sysWin, u32 x, u16 y, u32 msgId);
void FIELD_MSGBG_InfoSysWinPrintStr(FieldSysWin *sysWin, u32 x, u16 y, struct Strbuf *str);
u32 FIELD_MSGBG_InfoSysWinMain(FieldSysWin *sysWin);
void FIELD_MSGBG_SysWinDrawCursor(FieldSysWin *sysWin);
void FIELD_MSGBG_ClearInfoSysWin(FieldSysWin *sysWin);
void FIELD_MSGBG_InfoSysWinPrintStrNow(FieldSysWin *sysWin, u32 x, int y, struct Strbuf *str);
struct BmpWin *FIELD_MSGBG_GetInfoSysWinBmpWin(FieldSysWin *sysWin);
void FIELD_MSGBG_SetupTalkWin(FieldMsgBg *msgBg, FieldTalkWin *talkWin, int index, VecFx32 *pos, struct Strbuf *str, u32 winType, u32 tailType);
FieldTalkWin *FIELD_MSGBG_AddTalkWin(FieldMsgBg *msgBg, int index, VecFx32 *pos, struct Strbuf *str, u32 winType, u32 tailType);
void FIELD_MSGBG_DeleteTalkWin(FieldTalkWin *talkWin);
int FIELD_MSGBG_WaitTalkWinClose(FieldTalkWin *talkWin);
void FIELD_MSGBG_ClearTalkWin(FieldTalkWin *talkWin);
void FIELD_MSGBG_TalkWinPrintStr(FieldTalkWin *talkWin, struct Strbuf *str);
u32 FIELD_MSGBG_TalkWinMain(FieldTalkWin *talkWin);
void FIELD_MSGBG_TalkWinDrawCursor(FieldTalkWin *talkWin);
void FIELD_MSGBG_SetupPlainWin(FieldMsgBg *msgBg, FieldPlainWin *plainWin, u32 x, u32 y, u16 width, u16 height, u32 winType);
FieldPlainWin *FIELD_MSGBG_CreatePlainWin(FieldMsgBg *msgBg, struct MsgBank *msgData, u32 winType, u16 x, u16 y, u16 width, u16 height);
int FIELD_MSGBG_DeletePlainWin(FieldPlainWin *plainWin);
void FIELD_MSGBG_ClearPlainWin(FieldPlainWin *plainWin);
void FIELD_MSGBG_OpenPlainWin(FieldPlainWin *plainWin);
void FIELD_MSGBG_PlainWinPrintMsg(FieldPlainWin *plainWin, int x, int y, u32 msgId);
void FIELD_MSGBG_PlainWinPrintStr(FieldPlainWin *plainWin, int x, int y, struct Strbuf *str);
void FIELD_MSGBG_PlainWinPrintStrColor(FieldPlainWin *plainWin, int x, int y, struct Strbuf *str, u16 color);
void FIELD_MSGBG_PlainWinPrintStream(FieldPlainWin *plainWin, u32 x, u16 y, struct Strbuf *str);
u32 FIELD_MSGBG_PlainWinMain(FieldPlainWin *plainWin);
void FIELD_MSGBG_PlainWinDrawCursor(FieldPlainWin *plainWin);
int FIELD_MSGBG_GetPlainWinStreamState(FieldPlainWin *plainWin);
void FIELD_MSGBG_SetupSubMsgWin(FieldMsgBg *msgBg, FieldSubMsgWin *subMsgWin, struct Strbuf *str, u32 talkIndex, u8 x, u8 y, u8 width, u8 height, u32 id);
void FIELD_MSGBG_GetStrSizeChars(FieldMsgBg *msgBg, struct Strbuf *str, u8 *width, u8 *height);
void FIELD_MSGBG_AddSubMsgWinMsg(FieldMsgBg *msgBg, struct MsgBank *msgData, u32 msgId, u32 id, u8 x, u8 y, u8 width, u8 height);
void FIELD_MSGBG_AddSubMsgWinStr(FieldMsgBg *msgBg, struct Strbuf *str, u32 id, u8 x, u8 y, u8 width, u8 height);
int FIELD_MSGBG_FreeSubMsgWin(FieldSubMsgWin *subMsgWin);
void FIELD_MSGBG_DeleteSubMsgWin(FieldMsgBg *msgBg, u32 id);
void FIELD_MSGBG_DeleteAllSubMsgWin(FieldMsgBg *msgBg);
int FIELD_MSGBG_ExistsSubMsgWin(FieldMsgBg *msgBg);
int FIELD_MSGBG_SubMsgWinMain(FieldSubMsgWin *subMsgWin);
FieldBgWin *FIELD_MSGBG_CreateBgWin(FieldMsgBg *msgBg, int winType);
FieldBgWin *FIELD_MSGBG_CreateBgWinFont(FieldMsgBg *msgBg, u32 winType, struct GfFont *font);
void FIELD_MSGBG_DeleteBgWin(FieldBgWin *bgWin);
u32 FIELD_MSGBG_BgWinMain(FieldBgWin *bgWin, struct Strbuf *str);
void FIELD_MSGBG_LoadBgWinGraphics(u32 frame, u32 palSlot, u32 winType, u16 heapId);
void FIELD_MSGBG_DrawBgWinFrame(u8 frame, u8 x, u8 y, u8 width, u8 height, u16 tile, u8 palette);
void FIELD_MSGBG_ClearBgWinFrame(u8 frame, u8 x, u8 y, u8 width, u8 height, u16 tile, u8 palette);
int FIELD_MSGBG_IsLineMissing(struct Strbuf *str, struct Strbuf *lineStr, u32 line);
int FIELD_MSGBG_PrintTwoLines(struct Bmp *bmp, struct GfFont *font, struct Strbuf *str, struct Strbuf *lineStr, u32 *line, u8 color);
int FIELD_MSGBG_RollLines(struct Bmp *dst, struct Bmp *prevBmp, struct Bmp *nextBmp, int offset, u16 color);
void FIELD_MSGBG_LoadSpWinPalette(u32 bgFrame, u32 palSlot, u16 heapId);
void FIELD_MSGBG_LoadFrameTile(struct Bmp *bmp, u32 frameType, u16 heapId, u32 tileIndex);
void FIELD_MSGBG_DrawFrameBmp(struct Bmp *bmp, u32 frameType, u16 heapId);
void FIELD_MSGBG_PrintLines(u16 x, u16 y, struct Bmp *bmp, struct GfFont *font, struct Strbuf *str, u16 heapId);
FieldSpWin *FIELD_MSGBG_CreateSpWin(FieldMsgBg *msgBg, u32 frameType, u32 x, u16 y, u16 width, u16 height);
void FIELD_MSGBG_DeleteSpWin(FieldSpWin *spWin);
void FIELD_MSGBG_SpWinPrintStr(FieldSpWin *spWin, u16 x, u16 y, struct Strbuf *str);
int FIELD_MSGBG_SpWinWaitKey(FieldSpWin *spWin);
u32 FIELD_MSGBG_GetStrWidthChars(FieldMsgBg *msgBg, struct Strbuf *str, int margin);
u32 FIELD_MSGBG_GetStrHeightChars(FieldMsgBg *msgBg, struct Strbuf *str, u32 margin);
FieldMsgCursor *FIELD_MSGBG_CreateCursor(FieldMsgBg *msgBg);
void FIELD_MSGBG_DeleteCursor(FieldMsgCursor *cursor);
void FIELD_MSGBG_InitCursor(FieldMsgCursor *cursor, FieldMsgBg *msgBg);
void FIELD_MSGBG_ExitCursor(FieldMsgCursor *cursor);
u8 FIELD_MSGBG_IsCursorDrawn(FieldMsgCursor *cursor);
void FIELD_MSGBG_ClearCursor(FieldMsgCursor *cursor, struct Bmp *bmp, u32 color);

extern const char d_021DDA50[];
extern FieldMenuHeader sYesNoMenuHeader;
extern FieldYesNoItems sYesNoMenuItems;
extern const FieldMsgCursorOffsets sCursorOffsetY;

FieldMsgBg *FIELD_MSGBG_Create(u16 heapId, struct G3dCamera *g3dCamera)
{
    FieldMsgBg *msgBg = GFL_HEAP_Alloc(heapId, sizeof(*msgBg), 1, (char *)d_021DDA50, 0x1a4);

    msgBg->heapId = heapId;
    msgBg->bgFrame = 0xff;
    msgBg->bgFrameSys = 0xff;
    msgBg->g3dCamera = g3dCamera;
    msgBg->font = GF_FONT_Create(0x17, 0, 0, 0, msgBg->heapId);
    msgBg->printQue = (struct PrintQue *)PRINTSYS_QUE_Create(msgBg->heapId);
    msgBg->tcbl = (struct Tcbl *)TCBL_Create(msgBg->heapId, msgBg->heapId, 1, 4);
    FIELD_MSGBG_KeyWaitInit(&msgBg->keyWait);
    msgBg->cursorCharFile = ARC_UTIL_LoadMember(5, 0xc, 0, heapId);
    NNS_G2dGetUnpackedCharacterDataEx(msgBg->cursorCharFile, (void **)(&msgBg->cursorCharData));
    return msgBg;
}

void FIELD_MSGBG_SetupBg(FieldMsgBg *msgBg)
{
    FIELD_MSGBG_InitBgTwoLayerTalk(msgBg, 1);
}

void FIELD_MSGBG_SetupBgDelayed(FieldMsgBg *msgBg)
{
    FIELD_MSGBG_InitBgTwoLayer(msgBg, 0);
    if (msgBg->vblankTask == 0)
        msgBg->vblankTask = GFL_USE_AddMainTask(FIELD_MSGBG_VblankTalkSysTask, msgBg, 0);
}

void FIELD_MSGBG_LoadWindowGraphics(u32 bgFrame, u16 heapId)
{
    FIELD_MSGBG_LoadWindowGraphicsAll(bgFrame, heapId);
}

/* Called from EVENT_FIELDMAP_CONTROL_RunDefaultFadeIn. */
void FIELD_MSGBG_LoadWindowGraphicsStep(FieldMsgBg *msgBg, int step)
{
    FIELD_MSGBG_LoadWindowGraphicsStepFn(msgBg->bgFrame, msgBg->heapId, step);
}

void FIELD_MSGBG_Delete(FieldMsgBg *msgBg)
{
    int i;
    FieldMsgPrint *msgPrint;

    i = 0;
    msgPrint = msgBg->msgPrint;
    if (msgBg->cursorCharFile != 0) {
        GFL_HEAP_Free(msgBg->cursorCharFile);
    }
    if (msgBg->talkSys != 0) {
        TALKMSGWIN_Delete(msgBg->talkSys);
    }
    if (msgBg->tcbl != 0) {
        TCBL_Destroy((struct TcblSystem *)msgBg->tcbl);
    }
    if (msgBg->bgFrame != 0xff) {
        BG_SYS_FreeTiles(msgBg->bgFrame, 1, 0);
        BG_SYS_FreeLayerBuf((u8)msgBg->bgFrame);
    }
    if (msgBg->bgFrameSys != 0xff) {
        BG_SYS_FreeLayerBuf((u8)msgBg->bgFrameSys);
    }
    do {
        if (msgPrint->strBuf != 0) {
            STRBUF_Delete(msgPrint->strBuf);
        }
        i++;
        msgPrint++;
    } while (i < 4);
    if (msgBg->printQue != 0) {
        PRINTSYS_QUE_Delete((struct PrintQueue *)msgBg->printQue);
    }
    if (msgBg->font != 0) {
        GF_FONT_Delete(msgBg->font);
    }
    GFL_HEAP_Free(msgBg);
}

void FIELD_MSGBG_ReleaseBg(FieldMsgBg *msgBg)
{
    if (msgBg->talkSys != 0) {
        TALKMSGWIN_Delete(msgBg->talkSys);
        msgBg->talkSys = 0;
    }
    if (msgBg->bgFrame != 0xff) {
        BG_SYS_FreeTiles(msgBg->bgFrame, 1, 0);
        BG_SYS_FreeLayerBuf((u8)msgBg->bgFrame);
        msgBg->bgFrame = 0xff;
    }
}

int FIELD_MSGBG_ReleaseSysFrame(FieldMsgBg *msgBg)
{
    if (msgBg->bgFrameSys != 0xff) {
        BG_SYS_FreeLayerBuf((u8)msgBg->bgFrameSys);
        msgBg->bgFrameSys = 0xff;
        return 1;
    }
    return 0;
}

void FIELD_MSGBG_SetupBgSingle(FieldMsgBg *msgBg)
{
    if (msgBg->talkSys != 0) {
        TALKMSGWIN_Delete(msgBg->talkSys);
    }
    FIELD_MSGBG_InitBgOneLayer(msgBg);
    if (msgBg->vblankTask == 0) {
        msgBg->vblankTask = GFL_USE_AddMainTask(FIELD_MSGBG_VblankTalkSysTask, msgBg, 0);
    }
}

/* Called from EVENT_FIELDMAP_CONTROL_RunDefaultFadeIn. */
int FIELD_MSGBG_IsSetupDone(FieldMsgBg *msgBg)
{
    if (msgBg->vblankTask == 0)
        return 1;
    return 0;
}

void FIELD_MSGBG_Main(FieldMsgBg *msgBg)
{
    int i;
    FieldSubMsgWin **subMsgWin;
    FieldMsgPrint *msgPrint;
    int j;
    struct PrintQue *printQue;

    PRINTSYS_QUE_Main((struct PrintQueue *)msgBg->printQue);
    i = 0;
    subMsgWin = msgBg->subMsgWin;
    for (; i < 8; i++, subMsgWin++) {
        if (*subMsgWin != 0) {
            FIELD_MSGBG_SubMsgWinMain(*subMsgWin);
        }
    }
    msgPrint = msgBg->msgPrint;
    for (j = 0; j < 4; j++, msgPrint++) {
        printQue = msgPrint->printQue;
        if (printQue != 0) {
            if (msgPrint->printUtil.transReq != 0) {
                if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)printQue, BMP_WIN_GetBmp(msgPrint->printUtil.win)) == 0) {
                    BMP_WIN_TransferChars(msgPrint->printUtil.win);
                    msgPrint->printUtil.transReq = 0;
                }
            }
            msgPrint->transDone = (msgPrint->printUtil.transReq == 0) ? 1 : 0;
        }
    }
    TCBL_Main((struct TcblSystem *)msgBg->tcbl);
    if (msgBg->talkSys != 0) {
        TALKMSGWIN_Update(msgBg->talkSys);
        TALKMSGWIN_EndUpdate(msgBg->talkSys);
    }
}

void FIELD_MSGBG_DrawTalkSys(FieldMsgBg *msgBg)
{
    struct TalkMsgWinSys *talkSys = msgBg->talkSys;
    if (talkSys != 0)
        TALKMSGWIN_Draw(talkSys);
}

void FIELD_MSGBG_ClearPrintQue(FieldMsgBg *msgBg)
{
    PRINTSYS_QUE_Clear((struct PrintQueue *)msgBg->printQue);
}

int FIELD_MSGBG_IsPrintQueFinished(FieldMsgBg *msgBg)
{
    return PRINTSYS_QUE_IsFinished((struct PrintQueue *)msgBg->printQue);
}

struct PrintQue *FIELD_MSGBG_GetPrintQue(FieldMsgBg *msgBg)
{
    return msgBg->printQue;
}

struct GfFont *FIELD_MSGBG_GetFont(FieldMsgBg *msgBg)
{
    return msgBg->font;
}

struct MsgBank *FIELD_MSGBG_CreateMsgData(FieldMsgBg *msgBg, u32 fileId)
{
    return (struct MsgBank *)MSGDATA_CreateFromArchive(0, 2, (u16)fileId, msgBg->heapId);
}

u32 FIELD_MSGBG_DeleteMsgData(struct MsgBank *msgData)
{
    return MSGDATA_Delete((struct MsgBank *)msgData);
}

void FIELD_MSGBG_RequestSysFrame(FieldMsgBg *msgBg)
{
    msgBg->sysFrameReq = 1;
}

/*
 * The second parameter is what puts the offset temp in r2 instead of r1.
 */
void FIELD_MSGBG_SetAutoMode(FieldMsgBg *msgBg, u8 autoMode)
{
    FIELD_MSGBG_KeyWaitSetAuto(&msgBg->keyWait, autoMode);
}

FieldMsgPrint *FIELD_MSGBG_AddMsgPrint(FieldMsgBg *msgBg, struct MsgBank *msgData, struct BmpWin *bmpWin)
{
    FieldMsgPrint *msgPrint;
    int i;

    i = 0;
    msgPrint = msgBg->msgPrint;
    for (; i < 4; i++, msgPrint++) {
        if (msgPrint->printQue == 0) {
            msgPrint->msgBg = msgBg;
            msgPrint->bmpWin = bmpWin;
            msgPrint->transDone = 1;
            msgPrint->font = msgBg->font;
            msgPrint->printQue = msgBg->printQue;
            msgPrint->strBuf = STRBUF_Create(0xa0, msgBg->heapId);
            msgPrint->msgData = msgData;
            msgPrint->printUtil.win = bmpWin;
            msgPrint->printUtil.transReq = 0;
            return msgPrint;
        }
    }
    return 0;
}

void FIELD_MSGBG_DeleteMsgPrint(FieldMsgPrint *msgPrint)
{
    msgPrint->font = 0;
    msgPrint->printQue = 0;
    STRBUF_Delete(msgPrint->strBuf);
    msgPrint->strBuf = 0;
    msgPrint->msgData = 0;
}

void FIELD_MSGBG_MsgPrintPrintMsg(FieldMsgPrint *msgPrint, int x, int y, u32 msgId)
{
    struct PrintQue *printQue;

    MSGDATA_ReadString((struct MsgBank *)msgPrint->msgData, msgId, msgPrint->strBuf);
    printQue = msgPrint->printQue;
    PRINTSYS_PrintQue((struct PrintQueue *)printQue, BMP_WIN_GetBmp(msgPrint->printUtil.win), (s16)x, (s16)y, msgPrint->strBuf, msgPrint->font);
    msgPrint->printUtil.transReq = 1;
}

void FIELD_MSGBG_MsgPrintPrintStr(FieldMsgPrint *msgPrint, int x, int y, struct Strbuf *str)
{
    struct PrintQue *printQue;

    printQue = msgPrint->printQue;
    PRINTSYS_PrintQue((struct PrintQueue *)printQue, BMP_WIN_GetBmp(msgPrint->printUtil.win), (s16)x, (s16)y, str, msgPrint->font);
    msgPrint->printUtil.transReq = 1;
}

void FIELD_MSGBG_MsgPrintPrintStrColorFont(FieldMsgPrint *msgPrint, int x, int y, struct Strbuf *str, u16 color, struct GfFont *font)
{
    struct PrintQue *printQue;

    printQue = msgPrint->printQue;
    PRINTSYS_PrintQueColor((struct PrintQueue *)printQue, BMP_WIN_GetBmp(msgPrint->printUtil.win), (s16)x, (s16)y, str, font, color);
    msgPrint->printUtil.transReq = 1;
}

void FIELD_MSGBG_MsgPrintPrintStrColor(FieldMsgPrint *msgPrint, int x, int y, struct Strbuf *str, u16 color)
{
    FIELD_MSGBG_MsgPrintPrintStrColorFont(msgPrint, x, y, str, color, msgPrint->font);
}

/* Read through FIELD_MSGBG_IsMsgWinTransDone. */
u32 FIELD_MSGBG_IsMsgPrintTransDone(FieldMsgPrint *msgPrint)
{
    return msgPrint->transDone;
}

void FIELD_MSGBG_ClearMsgPrint(FieldMsgPrint *msgPrint)
{
    BMP_Clear(BMP_WIN_GetBmp(msgPrint->bmpWin), 255);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(msgPrint->bmpWin));
}

void FIELD_MSGBG_FillMsgPrint(FieldMsgPrint *msgPrint, int x, int y, int width, int height)
{
    BMP_FillRect(BMP_WIN_GetBmp(msgPrint->bmpWin), (s16)x, (s16)y, (u16)width, (u16)height, 0xFF);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(msgPrint->bmpWin));
}

struct PrintQue *FIELD_MSGBG_GetMsgPrintQue(FieldMsgPrint *msgPrint)
{
    return msgPrint->printQue;
}

PrintUtil *FIELD_MSGBG_GetMsgPrintUtil(FieldMsgPrint *msgPrint)
{
    return &msgPrint->printUtil;
}

FieldMsgWin *FIELD_MSGBG_CreateMsgWinPalette(FieldMsgBg *msgBg, struct MsgBank *msgData, u16 x, u16 y, u16 width, u16 height, u16 palette)
{
    u8 frame;
    FieldMsgWin *msgWin;

    frame = msgBg->bgFrame;
    FIELD_MSGBG_SetupSysFrame(msgBg);
    if (palette == 0xe) {
        frame = msgBg->bgFrameSys;
    }
    msgWin = GFL_HEAP_Alloc(msgBg->heapId, sizeof(*msgWin), 1, (char *)d_021DDA50, 0x483);
    msgWin->msgBg = msgBg;
    msgWin->bmpWin = FIELD_MSGBG_CreateWindow(frame, msgBg->heapId, x, y, width, height, palette);
    msgWin->msgPrint = FIELD_MSGBG_AddMsgPrint(msgBg, msgData, msgWin->bmpWin);
    if (palette == 0xe) {
        FIELD_MSGBG_LoadMenuGraphicsLower(msgBg->heapId);
        FIELD_MSGBG_SetBlend(1);
    } else {
        FIELD_MSGBG_LoadMenuGraphicsUpper(msgBg->heapId);
    }
    return msgWin;
}

FieldMsgWin *FIELD_MSGBG_CreateMsgWin(FieldMsgBg *msgBg, struct MsgBank *msgData, u16 x, u16 y, u16 width, u16 height)
{
    msgBg->windowKind = 0xE;
    return FIELD_MSGBG_CreateMsgWinPalette(msgBg, msgData, x, y, width, height, msgBg->windowKind);
}

int FIELD_MSGBG_DeleteMsgWin(FieldMsgWin *msgWin)
{
    FIELD_MSGBG_DeleteWindow(msgWin->bmpWin);
    FIELD_MSGBG_DeleteMsgPrint(msgWin->msgPrint);
    return GFL_HEAP_Free(msgWin);
}

void FIELD_MSGBG_MsgWinPrintMsg(FieldMsgWin *msgWin, int x, int y, u32 msgId)
{
    FIELD_MSGBG_MsgPrintPrintMsg(msgWin->msgPrint, x, y, msgId);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(msgWin->bmpWin));
}

void FIELD_MSGBG_MsgWinPrintStr(FieldMsgWin *msgWin, int x, int y, struct Strbuf *str)
{
    FIELD_MSGBG_MsgPrintPrintStr(msgWin->msgPrint, x, y, str);
}

void FIELD_MSGBG_MsgWinPrintStrColorFont(FieldMsgWin *msgWin, u16 x, u16 y, struct Strbuf *str, u16 color, struct GfFont *font)
{
    FIELD_MSGBG_MsgPrintPrintStrColorFont(msgWin->msgPrint, x, y, str, color, font);
}

int FIELD_MSGBG_IsMsgWinTransDone(FieldMsgWin *msgWin)
{
    return FIELD_MSGBG_IsMsgPrintTransDone(msgWin->msgPrint);
}

void FIELD_MSGBG_ClearMsgWin(FieldMsgWin *msgWin)
{
    FIELD_MSGBG_ClearMsgPrint(msgWin->msgPrint);
}

void FIELD_MSGBG_FillMsgWin(FieldMsgWin *msgWin, int x, int y, int width, int height)
{
    FIELD_MSGBG_FillMsgPrint(msgWin->msgPrint, x, y, width, height);
}

FieldMsgWin *FIELD_MSGBG_CreateBottomMsgWin(FieldMsgBg *msgBg, struct MsgBank *msgData)
{
    return FIELD_MSGBG_CreateMsgWin(msgBg, msgData, 1, 0x13, 0x1E, 4);
}

struct BmpWin *FIELD_MSGBG_GetMsgWinBmpWin(FieldMsgWin *msgWin)
{
    return msgWin->bmpWin;
}

FieldMsgWin *FIELD_MSGBG_CreateInfoMsgWin(FieldMsgBg *msgBg, struct MsgBank *msgData, u32 x, u32 y, u16 width, u16 height)
{
    FieldMsgWin *msgWin;

    msgBg->windowKind = 0xe;
    FIELD_MSGBG_SetupSysFrame(msgBg);
    msgWin = GFL_HEAP_Alloc(msgBg->heapId, sizeof(*msgWin), 1, (char *)d_021DDA50, 0x560);
    msgWin->msgBg = msgBg;
    msgWin->bmpWin = FIELD_MSGBG_CreateSysFrameWindow(x, y, width, height, msgBg->heapId);
    msgWin->msgPrint = FIELD_MSGBG_AddMsgPrint(msgBg, msgData, msgWin->bmpWin);
    FIELD_MSGBG_SetBlend(1);
    return msgWin;
}

int FIELD_MSGBG_DeleteInfoMsgWin(FieldMsgWin *msgWin)
{
    FIELD_MSGBG_DeleteSysFrameWindow(msgWin->bmpWin);
    FIELD_MSGBG_DeleteMsgPrint(msgWin->msgPrint);
    return GFL_HEAP_Free(msgWin);
}

void FIELD_MSGBG_InfoMsgWinPrintStr(FieldMsgWin *msgWin, int x, int y, struct Strbuf *str)
{
    FIELD_MSGBG_MsgPrintPrintStr(msgWin->msgPrint, (u16)(x + 8), y, str);
}

void FIELD_MSGBG_ClearInfoMsgWin(FieldMsgWin *msgWin)
{
    FIELD_MSGBG_ClearMsgPrint(msgWin->msgPrint);
}

/*
 * Builds the arm9 list header from the field header (FIELD_MSGBG_MakeListHeader plus the
 * caller's words) and creates the list with BMP_MENULIST_Create.
 * `const` on header is what interleaves its field loads with the
 * menu->items store.
 */
FieldMenuFunc *FIELD_MSGBG_CreateMenuFuncPalette(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u16 listPos, u16 cursorPos,
                             u16 palette, u32 moveCallback, u32 lineCallback, void *work)
{
    BmpMenuListHeader listHeader;
    u8 frame;
    FieldMenuFunc *menu;

    frame = msgBg->bgFrame;
    FIELD_MSGBG_SetupSysFrame(msgBg);
    if (palette == 0xe) {
        frame = msgBg->bgFrameSys;
    }
    menu = GFL_HEAP_Alloc(msgBg->heapId, sizeof(*menu), 1, (char *)d_021DDA50, 0x606);
    FIELD_MSGBG_MakeListHeader(&listHeader, header);
    menu->msgBg = msgBg;
    menu->items = items;
    menu->bmpWin = FIELD_MSGBG_CreateWindow(frame, msgBg->heapId, header->posX, header->posY, header->width, header->height, palette);
    menu->msgPrint = FIELD_MSGBG_AddMsgPrint(msgBg, 0, menu->bmpWin);
    listHeader.reserved24 = 0;
    listHeader.printUtil = FIELD_MSGBG_GetMsgPrintUtil(menu->msgPrint);
    listHeader.printQue = FIELD_MSGBG_GetMsgPrintQue(menu->msgPrint);
    listHeader.font = msgBg->font;
    listHeader.bmpWin = menu->bmpWin;
    listHeader.items = items;
    listHeader.lineCallback = lineCallback;
    listHeader.moveCallback = moveCallback;
    listHeader.work = work;
    menu->menuList = BMP_MENULIST_Create((struct BmpMenuListTemplate *)(&listHeader), listPos, cursorPos, msgBg->heapId);
    BMP_MENULIST_ResetCursorTile(menu->menuList, msgBg->heapId);
    if (palette == 0xe) {
        FIELD_MSGBG_LoadMenuGraphicsLower(msgBg->heapId);
        FIELD_MSGBG_SetBlend(1);
    } else {
        FIELD_MSGBG_LoadMenuGraphicsUpper(msgBg->heapId);
    }
    return menu;
}

FieldMenuFunc *FIELD_MSGBG_CreateMenuFuncCallback(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u16 listPos, u16 cursorPos,
                             u32 moveCallback, u32 lineCallback, void *work)
{
    msgBg->windowKind = 0xe;
    return FIELD_MSGBG_CreateMenuFuncPalette(msgBg, header, items, listPos, cursorPos, msgBg->windowKind, moveCallback, lineCallback, work);
}

FieldMenuFunc *FIELD_MSGBG_CreateMenuFuncPos(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u16 listPos, u16 cursorPos)
{
    return FIELD_MSGBG_CreateMenuFuncCallback(msgBg, header, items, listPos, cursorPos, 0, header->lineCallback, 0);
}

FieldMenuFunc *FIELD_MSGBG_CreateMenuFunc(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items)
{
    return FIELD_MSGBG_CreateMenuFuncPos(msgBg, header, items, 0, 0);
}

FieldMenuFunc *FIELD_MSGBG_CreateMenuFuncWork(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u32 moveCallback, void *work,
                             u16 listPos, u16 cursorPos, u32 cancelable)
{
    FieldMenuFunc *menu = FIELD_MSGBG_CreateMenuFuncPalette(msgBg, header, items, listPos, cursorPos, msgBg->windowKind, moveCallback, 0, work);
    if (cancelable == 0)
        BMP_MENULIST_SetCancelDisabled(menu->menuList, 1);
    return menu;
}

int FIELD_MSGBG_DeleteMenuFunc(FieldMenuFunc *menu)
{
    BMP_MENULIST_Delete(menu->menuList, 0, 0);
    BMP_MENUWORK_Delete(menu->items);
    FIELD_MSGBG_DeleteWindow(menu->bmpWin);
    FIELD_MSGBG_DeleteMsgPrint(menu->msgPrint);
    return GFL_HEAP_Free(menu);
}

int FIELD_MSGBG_MenuFuncMain(FieldMenuFunc *menu)
{
    int result;

    if (FIELD_MSGBG_IsPrintQueFinished(menu->msgBg) == 0)
        return -1;
    result = BMP_MENULIST_Main(menu->menuList);
    if (result == -1)
        return -1;
    if (result == -2)
        return -2;
    return result;
}

void FIELD_MSGBG_RewriteMenuFunc(FieldMenuFunc *menu)
{
    BMP_MENULIST_Redraw(menu->menuList);
}

struct BmpMenuWork *FIELD_MSGBG_CreateMenuItems(int count, u16 heapId)
{
    return BMP_MENUWORK_Create(count, heapId);
}

struct BmpMenuWork *FIELD_MSGBG_CreateMenuItemsFromTable(const FieldMenuItemData *itemData, int count, struct MsgBank *msgData, u16 heapId)
{
    struct BmpMenuWork *items;
    int i;

    items = FIELD_MSGBG_CreateMenuItems(count, heapId);
    for (i = 0; i < count; i++)
        BMP_MENUWORK_AddMsgItem(items, msgData, itemData[i].msgId, itemData[i].param, heapId);
    return items;
}

void FIELD_MSGBG_AddMenuItemStr(struct BmpMenuWork *items, struct Strbuf *str, u32 param, u16 heapId)
{
    BMP_MENUWORK_AddStrItem(items, (const struct U16Vec *)str, param, heapId);
}

void FIELD_MSGBG_DeleteMenuItems(struct BmpMenuWork *items)
{
    BMP_MENUWORK_ReleaseItems(items);
}

u32 FIELD_MSGBG_GetMenuItemsMaxWidth(FieldMsgBg *msgBg, BmpMenuWork *items, u32 *outIndex, u32 margin)
{
    u32 marginU16;
    u32 bestIndex;
    u32 bestWidth;
    u32 i;

    bestWidth = 0;
    bestIndex = 0;
    i = 0;
    if ((uptr)items->u.handle != -1) {
        marginU16 = (u16)margin;
        do {
            u32 width;
            if (items->u.handle == 0) {
                break;
            }
            width = PRINTSYS_MeasureWidestLine(items->u.handle, msgBg->font, marginU16);
            if (width > bestWidth) {
                bestWidth = width;
                bestIndex = i;
            }
            items++;
            i++;
        } while ((uptr)items->u.handle != -1);
    }
    *outIndex = bestIndex;
    return bestWidth;
}

/* Sole blocker of ov010 SCRCMD_WORK_StartMenu's MATCH (tail call through a pool word). */
unsigned FIELD_MSGBG_GetMenuItemCount(struct BmpMenuWork *items)
{
    return BMP_MENUWORK_CountItems(items);
}

u32 FIELD_MSGBG_GetMenuItemsWidthChars(FieldMsgBg *msgBg, BmpMenuWork *items, u32 fontId, u32 margin)
{
    u32 bestIndex;
    u32 width;
    u32 chars;

    width = FIELD_MSGBG_GetMenuItemsMaxWidth(msgBg, items, &bestIndex, margin);
    width += margin + 0x10;
    chars = width >> 3;
    if (width & 7)
        chars++;
    return chars;
}

/* Sole blocker of ov010 SCRCMD_WORK_StartMenu's MATCH. */
unsigned FIELD_MSGBG_GetMenuHeightChars(unsigned lines, unsigned fontHeight, unsigned lineSpacing, int scrolls)
{
    unsigned pixels = lines * (fontHeight + lineSpacing);
    unsigned chars = (pixels + 7) >> 3;
    if (scrolls && chars * 8 - pixels < 6) {
        chars++;
    }
    return chars;
}

FieldMenuHeader *FIELD_MSGBG_SetMenuHeaderRect(FieldMenuHeader *header, u16 itemCount, u16 x, u16 y, u16 width, u16 height)
{
    header->itemCount = itemCount;
    header->posY = y;
    header->posX = x;
    header->width = width;
    header->height = height;
    return header;
}

void FIELD_MSGBG_DrawMenuFuncFrame(FieldMenuFunc *menu)
{
    BMP_MENUWORK_DrawWindow(menu->bmpWin, 0, 1, 13);
}

void FIELD_MSGBG_MakeListHeader(BmpMenuListHeader *listHeader, const FieldMenuHeader *header)
{
    MI_CpuFill8(listHeader, 0, sizeof(*listHeader));
    listHeader->itemCount = header->itemCount;
    listHeader->maxLines = header->maxLines;
    listHeader->labelX = header->labelX;
    listHeader->dataX = header->dataX;
    listHeader->cursorX = header->cursorX;
    listHeader->lineY = header->lineY;
    listHeader->textColor = header->textColor;
    listHeader->bgColor = header->bgColor;
    listHeader->shadowColor = header->shadowColor;
    listHeader->cursorMargin = header->cursorMargin;
    listHeader->lineSpacing = header->lineSpacing;
    listHeader->pageSkip = header->pageSkip;
    listHeader->fontId = header->fontId;
    listHeader->fontHeight = header->fontHeight;
    listHeader->lineCallback = header->lineCallback;
}

FieldMenuFunc *FIELD_MSGBG_CreateYesNoMenu(FieldMsgBg *msgBg, u32 cursorPos)
{
    FieldMenuHeader header = sYesNoMenuHeader;
    FieldYesNoItems itemData = sYesNoMenuItems;
    struct MsgBank *msgData;
    struct BmpMenuWork *items;
    FieldMenuFunc *menu;

    msgData = FIELD_MSGBG_CreateMsgData(msgBg, 0xe9);
    items = FIELD_MSGBG_CreateMenuItemsFromTable(itemData.item, 2, msgData, msgBg->heapId);
    MSGDATA_Delete((struct MsgBank *)msgData);
    FIELD_MSGBG_SetMenuHeaderRect(&header, 2, 0x18, 0xa, 7, 4);
    menu = FIELD_MSGBG_CreateMenuFuncPalette(msgBg, &header, items, 0, (u16)cursorPos, msgBg->windowKind, 0, 0, 0);
    BMP_MENULIST_SetCancelDisabled(menu->menuList, 0);
    return menu;
}

int FIELD_MSGBG_YesNoMenuMain(FieldMenuFunc *menu)
{
    int result = FIELD_MSGBG_MenuFuncMain(menu);
    if (result == -1)
        return 2;
    if (result == -2)
        return 1;
    return result;
}

FieldMsgStream *FIELD_MSGBG_CreateMsgStreamColor(FieldMsgBg *msgBg, struct Strbuf *str, struct BmpWin *bmpWin, u32 x, u16 y, u32 wait, u16 clearColor)
{
    FieldMsgStream *stream;

    stream = GFL_HEAP_Alloc(msgBg->heapId, sizeof(*stream), 1, (char *)d_021DDA50, 0x85e);
    stream->msgBg = msgBg;
    stream->wait = wait;
    stream->stream = (struct TextPrinter *)PRINTSYS_PrintStreamCallBack(bmpWin, x, y, str, msgBg->font, wait, msgBg->tcbl, 0, msgBg->heapId, clearColor, FIELD_MSGBG_MsgStreamCallback);
    FIELD_MSGBG_KeyWaitReset(&stream->msgBg->keyWait);
    return stream;
}

FieldMsgStreamCbRet FIELD_MSGBG_MsgStreamCallback(FieldMsgStreamCbArg code)
{
    switch (code) {
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x56B);
        break;
    case 6:
        return GFL_USE_IsAnySeBusy();
    }
    return 0;
}

FieldMsgStream *FIELD_MSGBG_CreateMsgStream(FieldMsgBg *msgBg, struct Strbuf *str, struct BmpWin *bmpWin, u32 x, u16 y, u32 wait)
{
    return FIELD_MSGBG_CreateMsgStreamColor(msgBg, str, bmpWin, x, y, wait, 0xF);
}

int FIELD_MSGBG_DeleteMsgStream(FieldMsgStream *stream)
{
    PRINTSYS_PrintStreamDelete((struct TextPrinter *)stream->stream);
    return GFL_HEAP_Free(stream);
}

int FIELD_MSGBG_MsgStreamMain(FieldMsgStream *stream)
{
    int state = PRINTSYS_PrintStreamGetState((struct TextPrinter *)stream->stream);
    switch (state) {
    case 0:
        if (FIELD_MSGBG_KeyWaitCheckSkip(&stream->msgBg->keyWait) != 0) {
            FIELD_MSGBG_StreamSetSpeed(stream->stream, 1);
        } else {
            FIELD_MSGBG_StreamSetSpeed(stream->stream, 0);
        }
        break;
    case 1:
        if (FIELD_MSGBG_KeyWaitCheckAdvance(&stream->msgBg->keyWait, PRINTSYS_PrintStreamGetWaitKind((struct TextPrinter *)stream->stream)) != 0) {
            if (FIELD_MSGBG_KeyWaitGetAuto(&stream->msgBg->keyWait) == 0) {
                GFL_USE_PlaySeDefaultVolume(0x547);
            }
            PRINTSYS_PrintStreamReleasePause((struct TextPrinter *)stream->stream);
            state = 0;
            FIELD_MSGBG_StreamSetSpeed(stream->stream, 0);
        }
        break;
    case 2:
        break;
    }
    return state;
}

FieldSysWin *FIELD_MSGBG_CreateSysWin(FieldMsgBg *msgBg, struct MsgBank *msgData, u32 x, u16 y, u16 width, u16 height)
{
    FieldSysWin *sysWin;

    msgBg->windowKind = 0xe;
    FIELD_MSGBG_SetupSysFrame(msgBg);
    sysWin = GFL_HEAP_Alloc(msgBg->heapId, sizeof(*sysWin), 1, (char *)d_021DDA50, 0x8FF);
    sysWin->msgBg = msgBg;
    sysWin->msgData = msgData;
    sysWin->bmpWin = FIELD_MSGBG_CreateWindow(msgBg->bgFrameSys, msgBg->heapId, x, y, width, height, msgBg->windowKind);
    sysWin->strBuf = STRBUF_Create(0xA0, msgBg->heapId);
    FIELD_MSGBG_InitCursor(&sysWin->cursor, msgBg);
    FIELD_MSGBG_LoadMenuGraphicsLower(msgBg->heapId);
    FIELD_MSGBG_SetBlend(1);
    return sysWin;
}

int FIELD_MSGBG_DeleteSysWin(FieldSysWin *sysWin)
{
    FIELD_MSGBG_DeleteWindow(sysWin->bmpWin);
    if (sysWin->stream != 0) {
        FIELD_MSGBG_DeleteMsgStream(sysWin->stream);
    }
    if (sysWin->msgPrint != 0) {
        FIELD_MSGBG_DeleteMsgPrint(sysWin->msgPrint);
    }
    STRBUF_Delete(sysWin->strBuf);
    FIELD_MSGBG_ExitCursor(&sysWin->cursor);
    return GFL_HEAP_Free(sysWin);
}

void FIELD_MSGBG_SysWinPrintMsg(FieldSysWin *sysWin, u32 x, u16 y, u32 msgId)
{
    if (sysWin->stream != 0) {
        FIELD_MSGBG_DeleteMsgStream(sysWin->stream);
    }
    MSGDATA_ReadString((struct MsgBank *)sysWin->msgData, msgId, sysWin->strBuf);
    sysWin->stream = FIELD_MSGBG_CreateMsgStream(sysWin->msgBg, sysWin->strBuf, sysWin->bmpWin, x, y, FIELD_MSGBG_KeyWaitGetCharWait(&sysWin->msgBg->keyWait));
}

void FIELD_MSGBG_SysWinPrintStr(FieldSysWin *sysWin, u32 x, u16 y, struct Strbuf *str)
{
    if (sysWin->stream != 0)
        FIELD_MSGBG_DeleteMsgStream(sysWin->stream);
    sysWin->stream = FIELD_MSGBG_CreateMsgStream(sysWin->msgBg, str, sysWin->bmpWin, x, y, FIELD_MSGBG_KeyWaitGetCharWait(&sysWin->msgBg->keyWait));
}

u32 FIELD_MSGBG_SysWinMain(FieldSysWin *sysWin)
{
    u32 state = FIELD_MSGBG_MsgStreamMain(sysWin->stream);
    KEY_GetTrg();
    KEY_GetCont();
    switch (state) {
    case 0:
        if (FIELD_MSGBG_IsCursorDrawn(&sysWin->cursor) == 1) {
            FIELD_MSGBG_ClearCursor(&sysWin->cursor, BMP_WIN_GetBmp(sysWin->bmpWin), 15);
            BMP_WIN_TransferChars(sysWin->bmpWin);
        }
        break;
    case 1:
        if (FIELD_MSGBG_KeyWaitGetAuto(&sysWin->msgBg->keyWait) == 0) {
            FIELD_MSGBG_AnimateCursor(&sysWin->cursor, BMP_WIN_GetBmp(sysWin->bmpWin), 15);
            BMP_WIN_TransferChars(sysWin->bmpWin);
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

FieldSysWin *FIELD_MSGBG_CreateBottomSysWin(FieldMsgBg *msgBg, struct MsgBank *msgData)
{
    return FIELD_MSGBG_CreateSysWin(msgBg, msgData, 1, 0x13, 0x1E, 4);
}

void FIELD_MSGBG_ClearSysWin(FieldSysWin *sysWin)
{
    BMP_Clear(BMP_WIN_GetBmp(sysWin->bmpWin), 0xFF);
    BG_SYS_PushTile((u8)sysWin->msgBg->bgFrame);
}

/* Reached from EVENT_PERAP_RECORD_Main. */
struct BmpWin *FIELD_MSGBG_GetSysWinBmpWin(FieldSysWin *sysWin)
{
    return sysWin->bmpWin;
}

FieldSysWin *FIELD_MSGBG_CreateInfoSysWin(FieldMsgBg *msgBg, struct MsgBank *msgData, u32 y)
{
    FieldSysWin *sysWin;

    msgBg->windowKind = 0xe;
    FIELD_MSGBG_SetupSysFrame(msgBg);
    sysWin = GFL_HEAP_Alloc(msgBg->heapId, sizeof(*sysWin), 1, (char *)d_021DDA50, 0x9F4);
    sysWin->msgBg = msgBg;
    sysWin->msgData = msgData;
    sysWin->bmpWin = FIELD_MSGBG_CreateSysFrameWindow(1, y, 0x1E, 4, msgBg->heapId);
    sysWin->strBuf = STRBUF_Create(0xA0, msgBg->heapId);
    FIELD_MSGBG_InitCursor(&sysWin->cursor, msgBg);
    FIELD_MSGBG_LoadMenuGraphicsLower(msgBg->heapId);
    FIELD_MSGBG_SetBlend(1);
    return sysWin;
}

int FIELD_MSGBG_DeleteInfoSysWin(FieldSysWin *sysWin)
{
    FIELD_MSGBG_DeleteSysFrameWindow(sysWin->bmpWin);
    if (sysWin->stream != 0) {
        FIELD_MSGBG_DeleteMsgStream(sysWin->stream);
    }
    if (sysWin->msgPrint != 0) {
        FIELD_MSGBG_DeleteMsgPrint(sysWin->msgPrint);
    }
    STRBUF_Delete(sysWin->strBuf);
    FIELD_MSGBG_ExitCursor(&sysWin->cursor);
    return GFL_HEAP_Free(sysWin);
}

void FIELD_MSGBG_InfoSysWinPrintMsg(FieldSysWin *sysWin, u32 x, u16 y, u32 msgId)
{
    if (sysWin->stream != 0) {
        FIELD_MSGBG_DeleteMsgStream(sysWin->stream);
    }
    MSGDATA_ReadString((struct MsgBank *)sysWin->msgData, msgId, sysWin->strBuf);
    sysWin->stream = FIELD_MSGBG_CreateMsgStream(sysWin->msgBg, sysWin->strBuf, sysWin->bmpWin, (u16)(x + 8), y, FIELD_MSGBG_KeyWaitGetCharWait(&sysWin->msgBg->keyWait));
}

void FIELD_MSGBG_InfoSysWinPrintStr(FieldSysWin *sysWin, u32 x, u16 y, struct Strbuf *str)
{
    if (sysWin->stream != 0)
        FIELD_MSGBG_DeleteMsgStream(sysWin->stream);
    sysWin->stream = FIELD_MSGBG_CreateMsgStream(sysWin->msgBg, str, sysWin->bmpWin, (u16)(x + 8), y, FIELD_MSGBG_KeyWaitGetCharWait(&sysWin->msgBg->keyWait));
}

u32 FIELD_MSGBG_InfoSysWinMain(FieldSysWin *sysWin)
{
    u32 state = FIELD_MSGBG_MsgStreamMain(sysWin->stream);
    KEY_GetTrg();
    KEY_GetCont();
    switch (state) {
    case 0:
        if (FIELD_MSGBG_IsCursorDrawn(&sysWin->cursor) == 1) {
            FIELD_MSGBG_ClearCursor(&sysWin->cursor, BMP_WIN_GetBmp(sysWin->bmpWin), 15);
            BMP_WIN_TransferChars(sysWin->bmpWin);
        }
        break;
    case 1:
        if (FIELD_MSGBG_KeyWaitGetAuto(&sysWin->msgBg->keyWait) == 0) {
            FIELD_MSGBG_AnimateCursor(&sysWin->cursor, BMP_WIN_GetBmp(sysWin->bmpWin), 15);
            BMP_WIN_TransferChars(sysWin->bmpWin);
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

void FIELD_MSGBG_SysWinDrawCursor(FieldSysWin *sysWin)
{
    if (FIELD_MSGBG_KeyWaitGetAuto(&sysWin->msgBg->keyWait) == 0) {
        FIELD_MSGBG_AnimateCursor(&sysWin->cursor, BMP_WIN_GetBmp(sysWin->bmpWin), 0xF);
        BMP_WIN_TransferChars(sysWin->bmpWin);
    }
}

void FIELD_MSGBG_ClearInfoSysWin(FieldSysWin *sysWin)
{
    BMP_Clear(BMP_WIN_GetBmp(sysWin->bmpWin), 0xFF);
    BG_SYS_PushTile((u8)sysWin->msgBg->bgFrame);
}

void FIELD_MSGBG_InfoSysWinPrintStrNow(FieldSysWin *sysWin, u32 x, int y, struct Strbuf *str)
{
    if (sysWin->msgPrint != 0)
        FIELD_MSGBG_DeleteMsgPrint(sysWin->msgPrint);
    sysWin->msgPrint = FIELD_MSGBG_AddMsgPrint(sysWin->msgBg, 0, sysWin->bmpWin);
    FIELD_MSGBG_MsgPrintPrintStr(sysWin->msgPrint, (u16)(x + 8), y, str);
}

struct BmpWin *FIELD_MSGBG_GetInfoSysWinBmpWin(FieldSysWin *sysWin)
{
    return sysWin->bmpWin;
}

void FIELD_MSGBG_SetupTalkWin(FieldMsgBg *msgBg, FieldTalkWin *talkWin, int index, VecFx32 *pos, struct Strbuf *str, u32 winType, u32 tailType)
{
    talkWin->targetPos = pos;
    talkWin->pos = *pos;
    msgBg->windowKind = 11;
    talkWin->msgBg = msgBg;
    talkWin->talkSys = msgBg->talkSys;
    talkWin->index = index;
    FIELD_MSGBG_LoadMenuGraphicsUpper(msgBg->heapId);
    FIELD_MSGBG_SetBlend(0);
    switch (index) {
    case 0:
        TALKMSGWIN_SetupUpperBalloon(talkWin->talkSys, 0, pos, str, 15, winType, tailType, FIELD_MSGBG_KeyWaitGetCharWait(&msgBg->keyWait));
        break;
    case 1:
        TALKMSGWIN_SetupLowerBalloon(talkWin->talkSys, 1, pos, str, 15, winType, tailType, FIELD_MSGBG_KeyWaitGetCharWait(&msgBg->keyWait));
        break;
    default:
        TALKMSGWIN_SetupAutoBalloon(talkWin->talkSys, 2, pos, str, 15, winType, FIELD_MSGBG_KeyWaitGetCharWait(&msgBg->keyWait));
        break;
    }
    FIELD_MSGBG_KeyWaitReset(&msgBg->keyWait);
    TALKMSGWIN_Open(talkWin->talkSys, talkWin->index);
    FIELD_MSGBG_InitCursor(&talkWin->cursor, msgBg);
    if (winType == 1) {
        talkWin->shakeOffset = 8;
        GFL_USE_PlaySeDefaultVolume(0x72C);
    }
}

FieldTalkWin *FIELD_MSGBG_AddTalkWin(FieldMsgBg *msgBg, int index, VecFx32 *pos, struct Strbuf *str, u32 winType, u32 tailType)
{
    FieldTalkWin *talkWin;

    if (index < 3) {
        talkWin = &msgBg->talkWin[index];
        if (talkWin->talkSys == 0) {
            FIELD_MSGBG_SetupTalkWin(msgBg, talkWin, index, pos, str, winType, tailType);
            return talkWin;
        }
    }
    return 0;
}

void FIELD_MSGBG_DeleteTalkWin(FieldTalkWin *talkWin)
{
    if (talkWin->strBuf != 0) {
        STRBUF_Delete(talkWin->strBuf);
    }
    FIELD_MSGBG_ExitCursor(&talkWin->cursor);
    TALKMSGWIN_Close(talkWin->talkSys, talkWin->index);
}

int FIELD_MSGBG_WaitTalkWinClose(FieldTalkWin *talkWin)
{
    if (TALKMSGWIN_IsFree(talkWin->talkSys, talkWin->index) != 0) {
        MI_CpuFill8(talkWin, 0, sizeof(*talkWin));
        return 1;
    }
    return 0;
}

void FIELD_MSGBG_ClearTalkWin(FieldTalkWin *talkWin)
{
    if (talkWin->strBuf != 0) {
        STRBUF_Delete(talkWin->strBuf);
    }
    TALKMSGWIN_Release(talkWin->talkSys, talkWin->index);
    FIELD_MSGBG_ExitCursor(&talkWin->cursor);
    MI_CpuFill8(talkWin, 0, sizeof(*talkWin));
}

void FIELD_MSGBG_TalkWinPrintStr(FieldTalkWin *talkWin, struct Strbuf *str)
{
    struct BmpWin *bmpWin = TALKMSGWIN_GetBmpWin(talkWin->talkSys, talkWin->index);
    BMP_Clear(BMP_WIN_GetBmp(bmpWin), 255);
    TALKMSGWIN_Reprint(talkWin->talkSys, talkWin->index, str, FIELD_MSGBG_KeyWaitGetCharWait(&talkWin->msgBg->keyWait));
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(bmpWin));
}

u32 FIELD_MSGBG_TalkWinMain(FieldTalkWin *talkWin)
{
    struct TextPrinter *stream;
    u32 state;
    struct BmpWin *bmpWin;
    struct Bmp *bmp;

    if (TALKMSGWIN_IsShown(talkWin->talkSys, talkWin->index) == 0) {
        return 0;
    }
    stream = TALKMSGWIN_GetPrintStream(talkWin->talkSys, talkWin->index);
    state = PRINTSYS_PrintStreamGetState((struct TextPrinter *)stream);
    BG_SYS_ChangeScrollImmediate(1, 3, talkWin->shakeOffset);
    if (talkWin->shakeOffset < 0) {
        talkWin->shakeOffset += 2;
        if (talkWin->shakeOffset > 0) {
            talkWin->shakeOffset = 0;
        }
    }
    talkWin->shakeOffset = -talkWin->shakeOffset;
    switch (state) {
    case 0:
        if (FIELD_MSGBG_IsCursorDrawn(&talkWin->cursor) == 1) {
            bmpWin = TALKMSGWIN_GetBmpWin(talkWin->talkSys, talkWin->index);
            FIELD_MSGBG_ClearCursor(&talkWin->cursor, BMP_WIN_GetBmp(bmpWin), 15);
            BMP_WIN_TransferChars(bmpWin);
        }
        if (FIELD_MSGBG_KeyWaitCheckSkip(&talkWin->msgBg->keyWait) != 0) {
            FIELD_MSGBG_StreamSetSpeed(stream, 1);
        } else {
            FIELD_MSGBG_StreamSetSpeed(stream, 0);
        }
        break;
    case 1:
        bmpWin = TALKMSGWIN_GetBmpWin(talkWin->talkSys, talkWin->index);
        bmp = BMP_WIN_GetBmp(bmpWin);
        if (FIELD_MSGBG_KeyWaitGetAuto(&talkWin->msgBg->keyWait) == 0) {
            FIELD_MSGBG_AnimateCursor(&talkWin->cursor, bmp, 15);
        }
        if (FIELD_MSGBG_KeyWaitCheckAdvance(&talkWin->msgBg->keyWait, PRINTSYS_PrintStreamGetWaitKind((struct TextPrinter *)stream)) != 0) {
            if (FIELD_MSGBG_KeyWaitGetAuto(&talkWin->msgBg->keyWait) == 0) {
                GFL_USE_PlaySeDefaultVolume(0x547);
            }
            PRINTSYS_PrintStreamReleasePause((struct TextPrinter *)stream);
            FIELD_MSGBG_ClearCursor(&talkWin->cursor, bmp, 15);
            FIELD_MSGBG_StreamSetSpeed(stream, 0);
        }
        BMP_WIN_TransferChars(bmpWin);
        break;
    case 2:
        if (talkWin->shakeOffset != 0) {
            talkWin->shakeOffset = 0;
            BG_SYS_ChangeScrollImmediate(1, 3, talkWin->shakeOffset);
        }
        return 1;
    }
    return 0;
}

void FIELD_MSGBG_TalkWinDrawCursor(FieldTalkWin *talkWin)
{
    struct BmpWin *bmpWin;

    if (FIELD_MSGBG_KeyWaitGetAuto(&talkWin->msgBg->keyWait) == 0) {
        bmpWin = TALKMSGWIN_GetBmpWin(talkWin->talkSys, talkWin->index);
        FIELD_MSGBG_AnimateCursor(&talkWin->cursor, BMP_WIN_GetBmp(bmpWin), 0xF);
        BMP_WIN_TransferChars(bmpWin);
    }
}

void FIELD_MSGBG_SetupPlainWin(FieldMsgBg *msgBg, FieldPlainWin *plainWin, u32 x, u32 y, u16 width, u16 height, u32 winType)
{
    msgBg->windowKind = 11;
    plainWin->talkSys = msgBg->talkSys;
    FIELD_MSGBG_LoadMenuGraphicsUpper(msgBg->heapId);
    FIELD_MSGBG_SetBlend(0);
    plainWin->bmpWin = TALKMSGWIN_AddFrameWindow(plainWin->talkSys, x, y, width, height, winType);
    FIELD_MSGBG_InitCursor(&plainWin->cursor, msgBg);
}

FieldPlainWin *FIELD_MSGBG_CreatePlainWin(FieldMsgBg *msgBg, struct MsgBank *msgData, u32 winType, u16 x, u16 y, u16 width, u16 height)
{
    FieldPlainWin *plainWin;

    plainWin = GFL_HEAP_Alloc(msgBg->heapId, sizeof(*plainWin), 1, (char *)d_021DDA50, 0xCA7);
    plainWin->msgBg = msgBg;
    plainWin->msgData = msgData;
    plainWin->strBuf = STRBUF_Create(0xA0, msgBg->heapId);
    FIELD_MSGBG_SetupPlainWin(msgBg, plainWin, x, y, width, height, winType);
    if (winType == 1)
        plainWin->shakeOffset = 8;
    return plainWin;
}

int FIELD_MSGBG_DeletePlainWin(FieldPlainWin *plainWin)
{
    if (plainWin->stream != 0) {
        FIELD_MSGBG_DeleteMsgStream(plainWin->stream);
    }
    if (plainWin->msgPrint != 0) {
        FIELD_MSGBG_DeleteMsgPrint(plainWin->msgPrint);
    }
    if (plainWin->strBuf != 0) {
        STRBUF_Delete(plainWin->strBuf);
    }
    TALKMSGWIN_DeleteFrameWindow(plainWin->talkSys, plainWin->bmpWin);
    FIELD_MSGBG_ExitCursor(&plainWin->cursor);
    return GFL_HEAP_Free(plainWin);
}

void FIELD_MSGBG_ClearPlainWin(FieldPlainWin *plainWin)
{
    BMP_Clear(BMP_WIN_GetBmp(plainWin->bmpWin), 0xFF);
    BG_SYS_PushTile((u8)plainWin->msgBg->bgFrame);
}

void FIELD_MSGBG_OpenPlainWin(FieldPlainWin *plainWin)
{
    TALKMSGWIN_ClearWindowFrame(plainWin->talkSys, plainWin->bmpWin);
}

void FIELD_MSGBG_PlainWinPrintMsg(FieldPlainWin *plainWin, int x, int y, u32 msgId)
{
    if (plainWin->msgPrint != 0)
        FIELD_MSGBG_DeleteMsgPrint(plainWin->msgPrint);
    plainWin->msgPrint = FIELD_MSGBG_AddMsgPrint(plainWin->msgBg, plainWin->msgData, plainWin->bmpWin);
    FIELD_MSGBG_MsgPrintPrintMsg(plainWin->msgPrint, x, y, msgId);
}

void FIELD_MSGBG_PlainWinPrintStr(FieldPlainWin *plainWin, int x, int y, struct Strbuf *str)
{
    if (plainWin->msgPrint != 0)
        FIELD_MSGBG_DeleteMsgPrint(plainWin->msgPrint);
    plainWin->msgPrint = FIELD_MSGBG_AddMsgPrint(plainWin->msgBg, 0, plainWin->bmpWin);
    FIELD_MSGBG_MsgPrintPrintStr(plainWin->msgPrint, x, y, str);
}

void FIELD_MSGBG_PlainWinPrintStrColor(FieldPlainWin *plainWin, int x, int y, struct Strbuf *str, u16 color)
{
    if (plainWin->msgPrint != 0)
        FIELD_MSGBG_DeleteMsgPrint(plainWin->msgPrint);
    plainWin->msgPrint = FIELD_MSGBG_AddMsgPrint(plainWin->msgBg, 0, plainWin->bmpWin);
    FIELD_MSGBG_MsgPrintPrintStrColor(plainWin->msgPrint, x, y, str, color);
}

void FIELD_MSGBG_PlainWinPrintStream(FieldPlainWin *plainWin, u32 x, u16 y, struct Strbuf *str)
{
    if (plainWin->stream != 0)
        FIELD_MSGBG_DeleteMsgStream(plainWin->stream);
    plainWin->stream = FIELD_MSGBG_CreateMsgStream(plainWin->msgBg, str, plainWin->bmpWin, x, y, FIELD_MSGBG_KeyWaitGetCharWait(&plainWin->msgBg->keyWait));
}

u32 FIELD_MSGBG_PlainWinMain(FieldPlainWin *plainWin)
{
    u32 state;

    KEY_GetTrg();
    KEY_GetCont();
    state = FIELD_MSGBG_MsgStreamMain(plainWin->stream);
    plainWin->streamState = PRINTSYS_PrintStreamGetState((struct TextPrinter *)plainWin->stream->stream);
    BG_SYS_ChangeScrollImmediate(1, 3, plainWin->shakeOffset);
    if (plainWin->shakeOffset < 0) {
        plainWin->shakeOffset += 2;
        if (plainWin->shakeOffset > 0) {
            plainWin->shakeOffset = 0;
        }
    }
    plainWin->shakeOffset = -plainWin->shakeOffset;
    switch (state) {
    case 0:
        if (FIELD_MSGBG_IsCursorDrawn(&plainWin->cursor) == 1) {
            FIELD_MSGBG_ClearCursor(&plainWin->cursor, BMP_WIN_GetBmp(plainWin->bmpWin), 15);
            BMP_WIN_TransferChars(plainWin->bmpWin);
        }
        break;
    case 1:
        if (FIELD_MSGBG_KeyWaitGetAuto(&plainWin->msgBg->keyWait) == 0) {
            FIELD_MSGBG_AnimateCursor(&plainWin->cursor, BMP_WIN_GetBmp(plainWin->bmpWin), 15);
            BMP_WIN_TransferChars(plainWin->bmpWin);
        }
        break;
    case 2:
        if (plainWin->shakeOffset != 0) {
            plainWin->shakeOffset = 0;
            BG_SYS_ChangeScrollImmediate(1, 3, plainWin->shakeOffset);
        }
        return 1;
    }
    return 0;
}

void FIELD_MSGBG_PlainWinDrawCursor(FieldPlainWin *plainWin)
{
    if (FIELD_MSGBG_KeyWaitGetAuto(&plainWin->msgBg->keyWait) == 0) {
        FIELD_MSGBG_AnimateCursor(&plainWin->cursor, BMP_WIN_GetBmp(plainWin->bmpWin), 0xF);
        BMP_WIN_TransferChars(plainWin->bmpWin);
    }
}

int FIELD_MSGBG_GetPlainWinStreamState(FieldPlainWin *plainWin)
{
    return plainWin->streamState;
}

void FIELD_MSGBG_SetupSubMsgWin(FieldMsgBg *msgBg, FieldSubMsgWin *subMsgWin, struct Strbuf *str, u32 talkIndex, u8 x, u8 y, u8 width, u8 height, u32 id)
{
    msgBg->windowKind = 11;
    subMsgWin->talkSys = msgBg->talkSys;
    subMsgWin->talkIndex = talkIndex;
    subMsgWin->id = id;
    FIELD_MSGBG_LoadMenuGraphicsUpper(msgBg->heapId);
    FIELD_MSGBG_SetBlend(0);
    TALKMSGWIN_SetupPlainWindow(subMsgWin->talkSys, subMsgWin->talkIndex, str, x, y, width, height, 0xFF, 0, FIELD_MSGBG_KeyWaitGetCharWait(&msgBg->keyWait), 2, 0);
    TALKMSGWIN_Open(subMsgWin->talkSys, subMsgWin->talkIndex);
}

/*
 * The margins are locals (marginX = 2, marginY = 0): the `+ marginY` add is
 * folded to a move after coalescing, which is the original's
 * `adds r0, r0, #0` at +0x22. A literal `+ 0` folds early and loses it.
 */
void FIELD_MSGBG_GetStrSizeChars(FieldMsgBg *msgBg, struct Strbuf *str, u8 *width, u8 *height)
{
    u32 marginX = 2, marginY = 0;
    u32 widthChars = PRINTSYS_MeasureWidestLine(str, msgBg->font, 0) + marginX;
    u32 heightChars = PRINTSYS_CountLines(str, msgBg->font) + marginY;
    u32 pixels = widthChars;
    widthChars >>= 3;
    if (pixels & 7) widthChars++;
    pixels = heightChars;
    heightChars >>= 3;
    *width = widthChars;
    if (pixels & 7) heightChars++;
    *height = heightChars;
}

void FIELD_MSGBG_AddSubMsgWinMsg(FieldMsgBg *msgBg, struct MsgBank *msgData, u32 msgId, u32 id, u8 x, u8 y, u8 width, u8 height)
{
    FieldSubMsgWin *subMsgWin;
    int slot;

    subMsgWin = GFL_HEAP_Alloc(msgBg->heapId, sizeof(*subMsgWin), 1, (char *)d_021DDA50, 0xE2A);
    slot = FIELD_MSGBG_StoreSubMsgWin(msgBg, subMsgWin);
    subMsgWin->strBuf = STRBUF_Create(0x40, msgBg->heapId);
    MSGDATA_ReadString((struct MsgBank *)msgData, msgId, subMsgWin->strBuf);
    FIELD_MSGBG_SetupSubMsgWin(msgBg, subMsgWin, subMsgWin->strBuf, (u16)(slot + 3), x, y, width, height, id);
}

/* x is u8: its caller (0x021B11B6) truncates r3, and the narrow type is what
 * pins its home store to the front of the prologue. */
void FIELD_MSGBG_AddSubMsgWinStr(FieldMsgBg *msgBg, struct Strbuf *str, u32 id, u8 x, u8 y, u8 width, u8 height)
{
    FieldSubMsgWin *subMsgWin;
    u32 slot;

    subMsgWin = GFL_HEAP_Alloc(msgBg->heapId, sizeof(*subMsgWin), 1, (char *)d_021DDA50, 0xE48);
    slot = FIELD_MSGBG_StoreSubMsgWin(msgBg, subMsgWin);
    subMsgWin->strBuf = STRBUF_Create(STRBUF_GetLength(str) + 1, msgBg->heapId);
    STRBUF_Copy(subMsgWin->strBuf, str);
    FIELD_MSGBG_SetupSubMsgWin(msgBg, subMsgWin, subMsgWin->strBuf, (u16)(slot + 3), x, y, width, height, id);
}

int FIELD_MSGBG_FreeSubMsgWin(FieldSubMsgWin *subMsgWin)
{
    if (subMsgWin->strBuf != 0) {
        STRBUF_Delete(subMsgWin->strBuf);
    }
    TALKMSGWIN_Release(subMsgWin->talkSys, subMsgWin->talkIndex);
    return GFL_HEAP_Free(subMsgWin);
}

void FIELD_MSGBG_DeleteSubMsgWin(FieldMsgBg *msgBg, u32 id)
{
    FIELD_MSGBG_FreeSubMsgWin(FIELD_MSGBG_RemoveSubMsgWin(msgBg, id));
}

/*
 * The slot is cleared before it is read back, so the delete gets the cleared
 * value; the code is kept as the original has it (store, load, store).
 */
void FIELD_MSGBG_DeleteAllSubMsgWin(FieldMsgBg *msgBg)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (msgBg->subMsgWin[i] != 0) {
            msgBg->subMsgWin[i] = 0;
            {
                FieldSubMsgWin *entry = msgBg->subMsgWin[i];
                msgBg->subMsgWin[i] = 0;
                FIELD_MSGBG_FreeSubMsgWin(entry);
            }
        }
    }
}

int FIELD_MSGBG_ExistsSubMsgWin(FieldMsgBg *msgBg)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (msgBg->subMsgWin[i] != 0)
            return 1;
    }
    return 0;
}

int FIELD_MSGBG_SubMsgWinMain(FieldSubMsgWin *subMsgWin)
{
    if (TALKMSGWIN_IsShown(subMsgWin->talkSys, (int)subMsgWin->talkIndex) == 0)
        return 0;
    KEY_GetTrg();
    KEY_GetCont();
    switch (PRINTSYS_PrintStreamGetState((struct TextPrinter *)(TALKMSGWIN_GetPrintStream(subMsgWin->talkSys, subMsgWin->talkIndex)))) {
    case 0:
    case 1:
        break;
    case 2:
        return 1;
    }
    return 0;
}

FieldBgWin *FIELD_MSGBG_CreateBgWin(FieldMsgBg *msgBg, int winType)
{
    return FIELD_MSGBG_CreateBgWinFont(msgBg, winType, msgBg->font);
}

FieldBgWin *FIELD_MSGBG_CreateBgWinFont(FieldMsgBg *msgBg, u32 winType, struct GfFont *font)
{
    FieldBgWin *bgWin;
    u8 x;
    u8 y;
    u8 width;
    u8 height;

    bgWin = GFL_HEAP_Alloc(msgBg->heapId, sizeof(*bgWin), 1, (char *)d_021DDA50, 0xee0);
    bgWin->msgBg = msgBg;
    bgWin->font = font;
    bgWin->scrollY = -48;
    BG_SYS_ChangeScrollImmediate((u8)msgBg->bgFrame, 0, 0);
    BG_SYS_ChangeScrollImmediate((u8)bgWin->msgBg->bgFrame, 3, bgWin->scrollY);
    bgWin->bmpWin = BMP_WIN_Create((u8)msgBg->bgFrame, 2, 0x13, 0x1c, 4, 9, 1);
    bgWin->nextBmp = BMP_Create(0x1c, 4, 0x20, msgBg->heapId);
    bgWin->prevBmp = BMP_Create(0x1c, 4, 0x20, msgBg->heapId);
    BMP_Clear(BMP_WIN_GetBmp(bgWin->bmpWin), 15);
    BMP_WIN_MakeScreen(bgWin->bmpWin);
    BMP_WIN_TransferChars(bgWin->bmpWin);
    FIELD_MSGBG_LoadBgWinGraphics(msgBg->bgFrame, 9, winType, msgBg->heapId);
    x = BMP_WIN_GetPosX(bgWin->bmpWin);
    y = BMP_WIN_GetPosY(bgWin->bmpWin);
    width = BMP_WIN_GetWidth(bgWin->bmpWin);
    height = BMP_WIN_GetHeight(bgWin->bmpWin);
    FIELD_MSGBG_DrawBgWinFrame((u8)msgBg->bgFrame, x, y, width, height, 0x33, 9);
    BG_SYS_PushTile((u8)msgBg->bgFrame);
    FIELD_MSGBG_InitCursor(&bgWin->cursor, bgWin->msgBg);
    msgBg->windowKind = 11;
    FIELD_MSGBG_SetBlend(0);
    return bgWin;
}

void FIELD_MSGBG_DeleteBgWin(FieldBgWin *bgWin)
{
    u8 x;
    u8 y;
    u8 width;
    u8 height;

    BMP_WIN_GetBmp(bgWin->bmpWin);
    x = BMP_WIN_GetPosX(bgWin->bmpWin);
    y = BMP_WIN_GetPosY(bgWin->bmpWin);
    width = BMP_WIN_GetWidth(bgWin->bmpWin);
    height = BMP_WIN_GetHeight(bgWin->bmpWin);
    FIELD_MSGBG_ClearBgWinFrame((u8)bgWin->msgBg->bgFrame, x, y, width, height, 0, 15);
    BMP_WIN_ClearScreen(bgWin->bmpWin);
    x = BMP_WIN_GetPosX(bgWin->bmpWin);
    y = BMP_WIN_GetPosY(bgWin->bmpWin);
    width = BMP_WIN_GetWidth(bgWin->bmpWin);
    height = BMP_WIN_GetHeight(bgWin->bmpWin);
    BG_SYS_SetTileEntry((u8)bgWin->msgBg->bgFrame, 0, x, y, width, height, 0x11);
    BMP_WIN_TransferChars(bgWin->bmpWin);
    BMP_WIN_Delete(bgWin->bmpWin);
    BG_SYS_PushTile((u8)bgWin->msgBg->bgFrame);
    BG_SYS_ChangeScrollImmediate((u8)bgWin->msgBg->bgFrame, 3, 0);
    BMP_Delete(bgWin->prevBmp);
    BMP_Delete(bgWin->nextBmp);
    if (bgWin->lineStr != 0) {
        STRBUF_Delete(bgWin->lineStr);
    }
    FIELD_MSGBG_ExitCursor(&bgWin->cursor);
    GFL_HEAP_Free(bgWin);
}

u32 FIELD_MSGBG_BgWinMain(FieldBgWin *bgWin, struct Strbuf *str)
{
    switch (bgWin->seq) {
    case 0:
        bgWin->str = str;
        bgWin->lineStr = STRBUF_Create(STRBUF_GetLength(str) + 2, bgWin->msgBg->heapId);
        FIELD_MSGBG_PrintTwoLines(BMP_WIN_GetBmp(bgWin->bmpWin), bgWin->font, bgWin->str, bgWin->lineStr, &bgWin->lineIndex, 15);
        BMP_WIN_TransferChars(bgWin->bmpWin);
        BG_SYS_PushTile((u8)bgWin->msgBg->bgFrame);
        bgWin->seq++;
        break;
    case 1:
        bgWin->scrollY += 12;
        if (bgWin->scrollY >= 0) {
            bgWin->scrollY = 0;
            bgWin->seq++;
        }
        BG_SYS_ChangeScrollImmediate((u8)bgWin->msgBg->bgFrame, 3, bgWin->scrollY);
        break;
    case 2:
        if (FIELD_MSGBG_IsLineMissing(bgWin->str, bgWin->lineStr, bgWin->lineIndex) == 1) {
            bgWin->seq = 5;
            break;
        }
        bgWin->seq++;
    case 3:
        if ((KEY_GetTrg() & 3) == 0) {
            FIELD_MSGBG_AnimateCursor(&bgWin->cursor, BMP_WIN_GetBmp(bgWin->bmpWin), 15);
            BMP_WIN_TransferChars(bgWin->bmpWin);
            break;
        }
        FIELD_MSGBG_ClearCursor(&bgWin->cursor, BMP_WIN_GetBmp(bgWin->bmpWin), 15);
        BMP_CopyPixels(BMP_WIN_GetBmp(bgWin->bmpWin), bgWin->prevBmp);
        FIELD_MSGBG_PrintTwoLines(bgWin->nextBmp, bgWin->font, bgWin->str, bgWin->lineStr, &bgWin->lineIndex, 15);
        bgWin->rollOffset = 0;
        GFL_USE_PlaySeDefaultVolume(0x547);
        bgWin->seq++;
    case 4:
        if (FIELD_MSGBG_RollLines(BMP_WIN_GetBmp(bgWin->bmpWin), bgWin->prevBmp, bgWin->nextBmp, bgWin->rollOffset, 15) == 1) {
            bgWin->seq = 2;
        } else {
            bgWin->rollOffset += 4;
        }
        BMP_WIN_TransferChars(bgWin->bmpWin);
        BG_SYS_PushTile((u8)bgWin->msgBg->bgFrame);
        break;
    case 5:
        if ((KEY_GetTrg() & 0xf3) == 0) {
            break;
        }
        bgWin->seq++;
    case 6:
        bgWin->scrollY -= 12;
        if (bgWin->scrollY <= -48) {
            bgWin->scrollY = -48;
        }
        BG_SYS_ChangeScrollImmediate((u8)bgWin->msgBg->bgFrame, 3, bgWin->scrollY);
        if (bgWin->scrollY == -48) {
            bgWin->seq++;
            return 1;
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}

void FIELD_MSGBG_LoadBgWinGraphics(u32 frame, u32 palSlot, u32 winType, u16 heapId)
{
    if (winType >= 4)
        winType = 0;
    ARC_UTIL_UploadBgCharFromArchive(5, 6, frame, 0x33, 0, 0, heapId);
    ARC_UTIL_UploadPaletteFromArchive(5, 1, 0, winType << 5, palSlot << 5, 0x20, heapId);
}

void FIELD_MSGBG_DrawBgWinFrame(u8 frame, u8 x, u8 y, u8 width, u8 height, u16 tile, u8 palette)
{
    BG_SYS_SetTileEntry(frame, tile, x - 2, y - 1, 1, 1, palette);
    BG_SYS_SetTileEntry(frame, tile + 1, x - 1, y - 1, 1, 1, palette);
    BG_SYS_SetTileEntry(frame, tile + 2, x, y - 1, width, 1, palette);
    BG_SYS_SetTileEntry(frame, tile + 4, x + width, y - 1, 1, 1, palette);
    BG_SYS_SetTileEntry(frame, tile + 5, x + width + 1, y - 1, 1, 1, palette);
    BG_SYS_SetTileEntry(frame, tile + 6, x - 2, y, 1, height, palette);
    BG_SYS_SetTileEntry(frame, tile + 7, x - 1, y, 1, height, palette);
    BG_SYS_SetTileEntry(frame, tile + 10, x + width, y, 1, height, palette);
    BG_SYS_SetTileEntry(frame, tile + 11, x + width + 1, y, 1, height, palette);
    BG_SYS_SetTileEntry(frame, tile + 12, x - 2, y + height, 1, 1, palette);
    BG_SYS_SetTileEntry(frame, tile + 13, x - 1, y + height, 1, 1, palette);
    BG_SYS_SetTileEntry(frame, tile + 14, x, y + height, width, 1, palette);
    BG_SYS_SetTileEntry(frame, tile + 16, x + width, y + height, 1, 1, palette);
    BG_SYS_SetTileEntry(frame, tile + 17, x + width + 1, y + height, 1, 1, palette);
}

void FIELD_MSGBG_ClearBgWinFrame(u8 frame, u8 x, u8 y, u8 width, u8 height, u16 tile, u8 palette)
{
    BG_SYS_SetTileEntry(frame, tile, x - 2, y - 1, 1, 1, palette);
    BG_SYS_SetTileEntry(frame, tile, x - 1, y - 1, 1, 1, palette);
    BG_SYS_SetTileEntry(frame, tile, x, y - 1, width, 1, palette);
    BG_SYS_SetTileEntry(frame, tile, x + width, y - 1, 1, 1, palette);
    BG_SYS_SetTileEntry(frame, tile, x + width + 1, y - 1, 1, 1, palette);
    BG_SYS_SetTileEntry(frame, tile, x - 2, y, 1, height, palette);
    BG_SYS_SetTileEntry(frame, tile, x - 1, y, 1, height, palette);
    BG_SYS_SetTileEntry(frame, tile, x + width, y, 1, height, palette);
    BG_SYS_SetTileEntry(frame, tile, x + width + 1, y, 1, height, palette);
    BG_SYS_SetTileEntry(frame, tile, x - 2, y + height, 1, 1, palette);
    BG_SYS_SetTileEntry(frame, tile, x - 1, y + height, 1, 1, palette);
    BG_SYS_SetTileEntry(frame, tile, x, y + height, width, 1, palette);
    BG_SYS_SetTileEntry(frame, tile, x + width, y + height, 1, 1, palette);
    BG_SYS_SetTileEntry(frame, tile, x + width + 1, y + height, 1, 1, palette);
}

int FIELD_MSGBG_IsLineMissing(struct Strbuf *str, struct Strbuf *lineStr, u32 line)
{
    if (PRINTSYS_CopyLine(str, lineStr, line) == 0) {
        return 1;
    }
    return 0;
}

int FIELD_MSGBG_PrintTwoLines(struct Bmp *bmp, struct GfFont *font, struct Strbuf *str, struct Strbuf *lineStr, u32 *line, u8 color)
{
    int y;

    BMP_Clear(bmp, color);
    if (PRINTSYS_CopyLine(str, lineStr, *line) == 0)
        return 1;
    PRINTSYS_Print(bmp, 1, 1, lineStr, font);
    y = 1;
    y += PRINTSYS_CountLines(lineStr, font) + 1;
    if (PRINTSYS_CopyLine(str, lineStr, ++*line) == 0)
        return 1;
    PRINTSYS_Print(bmp, 1, y, lineStr, font);
    ++*line;
    return 0;
}

int FIELD_MSGBG_RollLines(struct Bmp *dst, struct Bmp *prevBmp, struct Bmp *nextBmp, int offset, u16 color)
{
    int width;
    int height;

    width = BMP_GetWidth(dst);
    height = BMP_GetHeight(dst);
    BMP_Clear(dst, color);
    if (offset > height)
        offset = height;
    BMP_Blit(prevBmp, dst, 0, offset, 0, 0, width, height - offset, color);
    BMP_Blit(nextBmp, dst, 0, 0, 0, height - offset, width, offset, color);
    if (offset >= height) return 1;
    return 0;
}

void FIELD_MSGBG_LoadSpWinPalette(u32 bgFrame, u32 palSlot, u16 heapId)
{
    ARC_UTIL_UploadPaletteFromArchive(5, 2, 0, 0, palSlot * 32, 0x20, heapId);
}

void FIELD_MSGBG_LoadFrameTile(struct Bmp *bmp, u32 frameType, u16 heapId, u32 tileIndex)
{
    enum { FRAME_SET_FIRST } frameSet = FRAME_SET_FIRST;
    u8 *pixels;
    void *file;
    NNSG2dCharacterData *charData;

    pixels = BMP_GetPixels(bmp);
    file = ARC_UTIL_LoadMember(5, 8, 0, heapId);
    NNS_G2dGetUnpackedCharacterDataEx(file, (void **)(&charData));
    MI_CpuCopy((u8 *)charData->pRawData + frameSet * 32 + tileIndex * 32, pixels, 0x20);
    GFL_HEAP_Free(file);
}

static inline void blit(struct Bmp *tile, struct Bmp *bmp, u16 x, u16 y)
{
    BMP_Blit(tile, bmp, 0, 0, x * 8, y * 8, 8, 8, 0xFFFF);
}

/*
 * Nine-slice frame: loads each frame tile into an 8x8 scratch bitmap with
 * FIELD_MSGBG_LoadFrameTile and blits it over the centre, the four edges and the four
 * corners of the target bitmap.
 *
 * The edge loops use u16 locals truncated at their definition from the
 * CSE'd int width-1 / height-1 (spilled); the corners reuse the loop
 * counters i and j as the x/y tile positions, assigned before each tile
 * load, so the u16 truncation is scheduled ahead of the FIELD_MSGBG_LoadFrameTile call.
 */
void FIELD_MSGBG_DrawFrameBmp(struct Bmp *bmp, u32 frameType, u16 heapId)
{
    u16 width;
    u16 j;
    u16 height;
    u16 i;
    struct Bmp *tile;
    u16 lastRow;
    u16 lastCol;

    width = BMP_GetWidth(bmp) >> 3;
    height = BMP_GetHeight(bmp) >> 3;
    tile = BMP_Create(1, 1, 0x20, heapId);
    FIELD_MSGBG_LoadFrameTile(tile, frameType, heapId, 9);
    for (j = 0; j < height; j++)
        for (i = 0; i < width; i++)
            blit(tile, bmp, i, j);
    FIELD_MSGBG_LoadFrameTile(tile, frameType, heapId, 1);
    for (i = 0; i < width; i++)
        blit(tile, bmp, i, 0);
    FIELD_MSGBG_LoadFrameTile(tile, frameType, heapId, 0x11);
    lastRow = height - 1;
    for (i = 0; i < width; i++)
        blit(tile, bmp, i, lastRow);
    FIELD_MSGBG_LoadFrameTile(tile, frameType, heapId, 8);
    for (i = 0; i < height; i++)
        blit(tile, bmp, 0, i);
    FIELD_MSGBG_LoadFrameTile(tile, frameType, heapId, 0xA);
    lastCol = width - 1;
    for (i = 0; i < height; i++)
        blit(tile, bmp, lastCol, i);
    FIELD_MSGBG_LoadFrameTile(tile, frameType, heapId, 0);
    blit(tile, bmp, 0, 0);
    i = width - 1;
    FIELD_MSGBG_LoadFrameTile(tile, frameType, heapId, 2);
    blit(tile, bmp, i, 0);
    i = height - 1;
    FIELD_MSGBG_LoadFrameTile(tile, frameType, heapId, 0x10);
    blit(tile, bmp, 0, i);
    i = width - 1;
    j = height - 1;
    FIELD_MSGBG_LoadFrameTile(tile, frameType, heapId, 0x12);
    blit(tile, bmp, i, j);
    BMP_Delete(tile);
}

void FIELD_MSGBG_PrintLines(u16 x, u16 y, struct Bmp *bmp, struct GfFont *font, struct Strbuf *str, u16 heapId)
{
    int line;
    struct Strbuf *lineStr;
    int lineHeight;

    lineHeight = GF_FONT_GetLineHeight(font) + 2;
    lineStr = STRBUF_Create(STRBUF_GetLength(str) + 1, heapId);
    for (line = 0; PRINTSYS_CopyLine(str, lineStr, line) == 1; line++) {
        PRINTSYS_Print(bmp, (s16)x, (s16)y, lineStr, font);
        y += (u16)lineHeight;
    }
    STRBUF_Delete(lineStr);
}

FieldSpWin *FIELD_MSGBG_CreateSpWin(FieldMsgBg *msgBg, u32 frameType, u32 x, u16 y, u16 width, u16 height)
{
    FieldSpWin *spWin;

    spWin = GFL_HEAP_Alloc(msgBg->heapId, sizeof(*spWin), 1, (char *)d_021DDA50, 0x115D);
    spWin->msgBg = msgBg;
    spWin->bmpWin = BMP_WIN_Create((u8)msgBg->bgFrame, (u8)x, (u8)y, (u8)width, (u8)height, 9, 1);
    spWin->frameBmp = BMP_Create(1, 1, 0x20, msgBg->heapId);
    FIELD_MSGBG_LoadFrameTile(spWin->frameBmp, frameType, msgBg->heapId, 9);
    FIELD_MSGBG_DrawFrameBmp(BMP_WIN_GetBmp(spWin->bmpWin), frameType, msgBg->heapId);
    FIELD_MSGBG_LoadSpWinPalette(msgBg->bgFrame, 9, msgBg->heapId);
    BMP_WIN_MakeScreen(spWin->bmpWin);
    BMP_WIN_TransferChars(spWin->bmpWin);
    BG_SYS_PushTile((u8)msgBg->bgFrame);
    FIELD_MSGBG_InitCursor(&spWin->cursor, msgBg);
    msgBg->windowKind = 0xB;
    FIELD_MSGBG_SetBlend(0);
    return spWin;
}

void FIELD_MSGBG_DeleteSpWin(FieldSpWin *spWin)
{
    u8 x;
    u8 y;
    u8 width;
    u8 height;

    BMP_WIN_ClearScreen(spWin->bmpWin);
    x = BMP_WIN_GetPosX(spWin->bmpWin);
    y = BMP_WIN_GetPosY(spWin->bmpWin);
    width = BMP_WIN_GetWidth(spWin->bmpWin);
    height = BMP_WIN_GetHeight(spWin->bmpWin);
    BG_SYS_SetTileEntry((u8)spWin->msgBg->bgFrame, 0, x, y, width, height, 0x11);
    BMP_WIN_TransferChars(spWin->bmpWin);
    BG_SYS_PushTile((u8)spWin->msgBg->bgFrame);
    FIELD_MSGBG_ExitCursor(&spWin->cursor);
    BMP_Delete(spWin->frameBmp);
    BMP_WIN_Delete(spWin->bmpWin);
    GFL_HEAP_Free(spWin);
}

void FIELD_MSGBG_SpWinPrintStr(FieldSpWin *spWin, u16 x, u16 y, struct Strbuf *str)
{
    FieldMsgBg *msgBg = spWin->msgBg;
    FIELD_MSGBG_PrintLines(x, y, BMP_WIN_GetBmp(spWin->bmpWin), msgBg->font, str, msgBg->heapId);
    BMP_WIN_TransferChars(spWin->bmpWin);
    BG_SYS_PushTile((u8)spWin->msgBg->bgFrame);
}

int FIELD_MSGBG_SpWinWaitKey(FieldSpWin *spWin)
{
    u32 cont = KEY_GetTrg();
    KEY_GetCont();
    if (cont & 3)
        return 1;
    FIELD_MSGBG_AnimateCursorOnFrame(&spWin->cursor, BMP_WIN_GetBmp(spWin->bmpWin), spWin->frameBmp);
    BMP_WIN_TransferChars(spWin->bmpWin);
    return 0;
}

u32 FIELD_MSGBG_GetStrWidthChars(FieldMsgBg *msgBg, struct Strbuf *str, int margin)
{
    u32 width;
    u32 chars;

    width = margin * 2 + PRINTSYS_MeasureWidestLine(str, msgBg->font, 0);
    chars = width >> 3;
    if (width & 7)
        chars++;
    return chars;
}

u32 FIELD_MSGBG_GetStrHeightChars(FieldMsgBg *msgBg, struct Strbuf *str, u32 margin)
{
    u32 height;
    struct Strbuf *lineStr;
    u32 lines;

    height = margin * 2 + PRINTSYS_CountLines(str, msgBg->font);
    lineStr = STRBUF_Clone(str, msgBg->heapId);
    lines = 0;
    if (PRINTSYS_CopyLine(str, lineStr, 0) == 1) {
        while (++lines < 0x18 && PRINTSYS_CopyLine(str, lineStr, lines) == 1)
            ;
    }
    STRBUF_Delete(lineStr);
    height += (lines - 1) * 2;
    if (height & 7)
        height += 8;
    return height >> 3;
}

FieldMsgCursor *FIELD_MSGBG_CreateCursor(FieldMsgBg *msgBg)
{
    FieldMsgCursor *cursor = GFL_HEAP_Alloc(msgBg->heapId, sizeof(*cursor), 1, (char *)d_021DDA50, 0x1202);
    FIELD_MSGBG_InitCursor(cursor, msgBg);
    return cursor;
}

void FIELD_MSGBG_DeleteCursor(FieldMsgCursor *cursor)
{
    FIELD_MSGBG_ExitCursor(cursor);
    GFL_HEAP_Free(cursor);
}

void FIELD_MSGBG_InitCursor(FieldMsgCursor *cursor, FieldMsgBg *msgBg)
{
    MI_CpuFill8(cursor, 0, sizeof(*cursor));
    cursor->bmp = BMP_CreateFromBuffer(msgBg->cursorCharData->pRawData, 1, 1, 0x20, msgBg->heapId);
}

void FIELD_MSGBG_ExitCursor(FieldMsgCursor *cursor)
{
    cursor->isDrawn = 0;
    BMP_Delete(cursor->bmp);
}

u8 FIELD_MSGBG_IsCursorDrawn(FieldMsgCursor *cursor)
{
    return cursor->isDrawn;
}

void FIELD_MSGBG_ClearCursor(FieldMsgCursor *cursor, struct Bmp *bmp, u32 color)
{
    FieldMsgCursorOffsets offsets = sCursorOffsetY;
    u16 x;
    u16 y;

    x = BMP_GetWidth(bmp) - 8;
    y = BMP_GetHeight(bmp) - 8 - offsets.offsetY[cursor->animFrame];
    BMP_FillRect(bmp, (s16)x, (s16)y, (u16)8, (u16)8, (u8)color);
    cursor->isDrawn = 0;
}

void FIELD_MSGBG_DrawCursor(FieldMsgCursor *cursor, struct Bmp *bmp, u32 unusedColor)
{
    FieldMsgCursorOffsets offsets = d_021D3E60;
    u16 x;
    u16 y;

    x = BMP_GetWidth(bmp) - 8;
    y = BMP_GetHeight(bmp) - 8 - offsets.offsetY[cursor->animFrame];
    BMP_Blit(cursor->bmp, bmp, 0, 0, x, y, 8, 8, 0);
    cursor->isDrawn = 1;
}

void FIELD_MSGBG_AnimateCursor(FieldMsgCursor *cursor, struct Bmp *bmp, u32 color)
{
    FIELD_MSGBG_ClearCursor(cursor, bmp, color);
    cursor->animWait++;
    if (cursor->animWait >= 4) {
        cursor->animWait = 0;
        cursor->animFrame++;
        cursor->animFrame %= 3;
    }
    FIELD_MSGBG_DrawCursor(cursor, bmp, color);
}

void FIELD_MSGBG_AnimateCursorOnFrame(FieldMsgCursor *cursor, struct Bmp *bmp, struct Bmp *frameBmp)
{
    FieldMsgCursorOffsets offsets = d_021D3E58;
    s16 x;
    s16 y;
    s16 shift;

    x = BMP_GetWidth(bmp) - 8;
    y = BMP_GetHeight(bmp) - 8 - offsets.offsetY[cursor->animFrame];
    shift = y & 7;
    if (shift != 0)
        BMP_Blit(frameBmp, bmp, 0, 8 - shift, x, y, 8, shift, 0xFFFF);
    BMP_Blit(frameBmp, bmp, 0, 0, x, y + shift, 8, 8 - shift, 0xFFFF);
    cursor->animWait++;
    if (cursor->animWait >= 4) {
        cursor->animWait = 0;
        cursor->animFrame++;
        cursor->animFrame = cursor->animFrame % 3;
    }
    x = BMP_GetWidth(bmp) - 8;
    y = BMP_GetHeight(bmp) - 8 - offsets.offsetY[cursor->animFrame];
    BMP_Blit(cursor->bmp, bmp, 0, 0, x, y, 8, 8, 0);
    cursor->isDrawn = 1;
}

void FIELD_MSGBG_LoadSysWindowFrameGraphics(u16 heapId)
{
    ARC_UTIL_UploadBgCharFromArchive(5, 10, 1, 0x1F, 0, 0, heapId);
}

/* Draws a one-tile frame around a window (tiles 0x1F..0x30, palette 13). */
void FIELD_MSGBG_DrawSysWindowFrame(struct BmpWin *bmpWin)
{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u32 bgFrame;

    x = BMP_WIN_GetPosX(bmpWin);
    y = BMP_WIN_GetPosY(bmpWin);
    width = BMP_WIN_GetWidth(bmpWin);
    height = BMP_WIN_GetHeight(bmpWin);
    bgFrame = BMP_WIN_GetBgLayer(bmpWin);
    BG_SYS_SetTileEntry(bgFrame, 0x1f, x - 1, y - 1, 1, 1, 13);
    BG_SYS_SetTileEntry(bgFrame, 0x20, x, y - 1, width, 1, 13);
    BG_SYS_SetTileEntry(bgFrame, 0x24, x + width, y - 1, 1, 1, 13);
    BG_SYS_SetTileEntry(bgFrame, 0x25, x - 1, y, 1, height, 13);
    BG_SYS_SetTileEntry(bgFrame, 0x2a, x + width, y, 1, height, 13);
    BG_SYS_SetTileEntry(bgFrame, 0x2b, x - 1, y + height, 1, 1, 13);
    BG_SYS_SetTileEntry(bgFrame, 0x2d, x, y + height, width, 1, 13);
    BG_SYS_SetTileEntry(bgFrame, 0x30, x + width, y + height, 1, 1, 13);
    BG_SYS_PushTile(bgFrame);
}

struct BmpWin *FIELD_MSGBG_CreateSysFrameWindow(u8 x, u8 y, u8 width, u8 height, u16 heapId)
{
    struct BmpWin *bmpWin;

    bmpWin = BMP_WIN_Create(2, x, y, width, height, 0xE, 1);
    BMP_Clear(BMP_WIN_GetBmp(bmpWin), 0xFF);
    BMP_WIN_MakeScreen(bmpWin);
    BMP_WIN_TransferChars(bmpWin);
    FIELD_MSGBG_DrawSysWindowFrame(bmpWin);
    return bmpWin;
}

void FIELD_MSGBG_ClearSysWindowFrame(struct BmpWin *bmpWin)
{
    u32 bgFrame;
    u32 x;
    u32 y;
    u32 width;
    u32 height;

    bgFrame = BMP_WIN_GetBgLayer(bmpWin);
    x = BMP_WIN_GetPosX(bmpWin);
    y = BMP_WIN_GetPosY(bmpWin);
    width = BMP_WIN_GetWidth(bmpWin);
    height = BMP_WIN_GetHeight(bmpWin);
    BG_SYS_SetTileEntry(bgFrame, 0, (u8)(x - 1), (u8)(y - 1), (u8)(width + 2), (u8)(height + 2), 0);
    BG_SYS_PushTile(bgFrame);
}

void FIELD_MSGBG_DeleteSysFrameWindow(struct BmpWin *bmpWin)
{
    FIELD_MSGBG_ClearSysWindowFrame(bmpWin);
    BMP_WIN_Delete(bmpWin);
}

/* Two-layer setup: message frame 1 and system frame 2, plus the talk balloon system. */
void FIELD_MSGBG_InitBgTwoLayerTalk(FieldMsgBg *msgBg, int loadTalkSys)
{
    FieldBgTemplate msgTemplate;
    FieldBgTemplate sysTemplate;
    TalkMsgWinParam talkParam;

    msgBg->bgFrame = 1;
    msgTemplate = d_021D3E98;
    BG_SYS_InitBgLayer((u8)msgBg->bgFrame, (const struct BgTemplate *)&msgTemplate, 0);
    msgBg->bgFrameSys = 2;
    sysTemplate = d_021D3E78;
    BG_SYS_InitBgLayer((u8)msgBg->bgFrameSys, (const struct BgTemplate *)&sysTemplate, 0);
    BG_SYS_Init(msgBg->bgFrame, 0, 1, 0);
    BG_SYS_SetTileEntry((u8)msgBg->bgFrame, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry((u8)msgBg->bgFrameSys, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile((u8)msgBg->bgFrame);
    BG_SYS_PushTile((u8)msgBg->bgFrameSys);
    if (loadTalkSys)
        FIELD_MSGBG_LoadWindowGraphicsAll(msgBg->bgFrame, msgBg->heapId);
    if (msgBg->g3dCamera != 0) {
        talkParam.heapId = msgBg->heapId;
        talkParam.camera = msgBg->g3dCamera;
        talkParam.font = msgBg->font;
        talkParam.frameBaseTile = 0xb;
        talkParam.bgLayer = 1;
        talkParam.framePalette = 0xc;
        talkParam.bmpWinPalette = FIELD_MSGBG_PALETTE_TALK;
        msgBg->talkSys = TALKMSGWIN_Create(&talkParam);
        TALKMSGWIN_LoadTexture(msgBg->talkSys);
    }
    G2x_SetBlendAlpha_((u32 *)REG_BLDCNT_ADDR, 4, 0x1b, 0x10, 4);
    BG_SYS_SetPlaneVisible(msgBg->bgFrame, 1);
    BG_SYS_SetPlaneVisible(msgBg->bgFrameSys, 1);
    msgBg->windowKind = FIELD_MSGBG_PALETTE_SYSTEM;
}

/* Same as FIELD_MSGBG_InitBgTwoLayerTalk with another template pair, and without TALKMSGWIN_LoadTexture. */
void FIELD_MSGBG_InitBgTwoLayer(FieldMsgBg *msgBg, int loadTalkSys)
{
    FieldBgTemplate msgTemplate;
    FieldBgTemplate sysTemplate;
    TalkMsgWinParam talkParam;

    msgBg->bgFrame = 1;
    msgTemplate = d_021D3ED8;
    BG_SYS_InitBgLayer((u8)msgBg->bgFrame, (const struct BgTemplate *)&msgTemplate, 0);
    msgBg->bgFrameSys = 2;
    sysTemplate = d_021D3EF8;
    BG_SYS_InitBgLayer((u8)msgBg->bgFrameSys, (const struct BgTemplate *)&sysTemplate, 0);
    BG_SYS_Init(msgBg->bgFrame, 0, 1, 0);
    BG_SYS_SetTileEntry((u8)msgBg->bgFrame, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry((u8)msgBg->bgFrameSys, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile((u8)msgBg->bgFrame);
    BG_SYS_PushTile((u8)msgBg->bgFrameSys);
    if (loadTalkSys)
        FIELD_MSGBG_LoadWindowGraphicsAll(msgBg->bgFrame, msgBg->heapId);
    if (msgBg->g3dCamera != 0) {
        talkParam.heapId = msgBg->heapId;
        talkParam.camera = msgBg->g3dCamera;
        talkParam.font = msgBg->font;
        talkParam.frameBaseTile = 0xb;
        talkParam.bgLayer = 1;
        talkParam.framePalette = 0xc;
        talkParam.bmpWinPalette = FIELD_MSGBG_PALETTE_TALK;
        msgBg->talkSys = TALKMSGWIN_Create(&talkParam);
    }
    G2x_SetBlendAlpha_((u32 *)REG_BLDCNT_ADDR, 4, 0x1b, 0x10, 4);
    BG_SYS_SetPlaneVisible(msgBg->bgFrame, 1);
    BG_SYS_SetPlaneVisible(msgBg->bgFrameSys, 1);
    msgBg->windowKind = FIELD_MSGBG_PALETTE_SYSTEM;
}

/* One-layer setup: message frame 1 only, always loads the window graphics. */
void FIELD_MSGBG_InitBgOneLayer(FieldMsgBg *msgBg)
{
    FieldBgTemplate msgTemplate;
    TalkMsgWinParam talkParam;

    msgBg->bgFrame = 1;
    msgTemplate = d_021D3EB8;
    BG_SYS_InitBgLayer((u8)msgBg->bgFrame, (const struct BgTemplate *)&msgTemplate, 0);
    BG_SYS_Init(msgBg->bgFrame, 0, 1, 0);
    BG_SYS_SetTileEntry((u8)msgBg->bgFrame, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile((u8)msgBg->bgFrame);
    FIELD_MSGBG_LoadWindowGraphicsAll(msgBg->bgFrame, msgBg->heapId);
    if (msgBg->g3dCamera != 0) {
        talkParam.heapId = msgBg->heapId;
        talkParam.camera = msgBg->g3dCamera;
        talkParam.font = msgBg->font;
        talkParam.frameBaseTile = 0xb;
        talkParam.bgLayer = 1;
        talkParam.framePalette = 0xc;
        talkParam.bmpWinPalette = FIELD_MSGBG_PALETTE_TALK;
        msgBg->talkSys = TALKMSGWIN_Create(&talkParam);
    }
    BG_SYS_SetPlaneVisible(msgBg->bgFrame, 1);
    msgBg->windowKind = FIELD_MSGBG_PALETTE_SYSTEM;
}

/* Task callback: once the transition is over, uploads the balloon graphics and ends itself. */
void FIELD_MSGBG_VblankTalkSysTask(struct TcbTask *task, void *arg)
{
    FieldMsgBg *msgBg = arg;

    if (GFL_USE_IsCardIrqEnabled() == 0) {
        TALKMSGWIN_LoadTexture(msgBg->talkSys);
        msgBg->vblankTask = 0;
        TCB_DeleteTask(task);
    }
}

/* Sets up the system window frame on BG 2. */
void FIELD_MSGBG_SetupSysFrameBg(int useTemplate)
{
    FieldBgTemplate sysTemplate;

    BG_SYS_SetPlaneVisible(2, 0);
    if (useTemplate == 1) {
        sysTemplate = d_021D3F18;
        BG_SYS_InitBgLayer(2, (const struct BgTemplate *)&sysTemplate, 0);
    } else {
        /* Keep priority and mosaic, screen base 0x1F, character base 4. */
        REG_BG2CNT = (REG_BG2CNT & 0x43) | 0x1F10;
    }
    BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(2);
    G2x_SetBlendAlpha_((u32 *)REG_BLDCNT_ADDR, 4, 0x1b, 0x10, 4);
    BG_SYS_SetPriority(2, 2);
    BG_SYS_SetPlaneVisible(2, 1);
}

void FIELD_MSGBG_SetupSysFrame(FieldMsgBg *msgBg)
{
    if (msgBg->sysFrameReq != 0) {
        msgBg->sysFrameReq = 0;
        if (msgBg->bgFrameSys == 0xFF) {
            BG_SYS_FreeLayerBuf(2);
            FIELD_MSGBG_SetupSysFrameBg(1);
            msgBg->bgFrameSys = 2;
        } else {
            FIELD_MSGBG_SetupSysFrameBg(0);
        }
    }
}

void FIELD_MSGBG_LoadWindowGraphicsAll(int bgFrame, u16 heapId)
{
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x160, 0x20, heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 7, 0, 0x1c0, 0x20, heapId);
    BMP_MENUWORK_LoadCharAndPltt(bgFrame & 0xff, 1, 0xd, 0, heapId);
    FIELD_MSGBG_LoadSysWindowFrameGraphics(heapId);
}

/* FIELD_MSGBG_LoadWindowGraphicsAll in three steps, one per call. */
void FIELD_MSGBG_LoadWindowGraphicsStepFn(int bgFrame, u16 heapId, int step)
{
    if (step == 0) {
        ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x160, 0x20, heapId);
        ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 7, 0, 0x1c0, 0x20, heapId);
    } else if (step == 1) {
        BMP_MENUWORK_LoadCharAndPltt(bgFrame & 0xff, 1, 0xd, 0, heapId);
    } else if (step == 2) {
        FIELD_MSGBG_LoadSysWindowFrameGraphics(heapId);
    }
}

void FIELD_MSGBG_SetBlend(u32 enable)
{
    if (enable == 1)
        G2x_SetBlendAlpha_((u32 *)REG_BLDCNT_ADDR, 4, 0x1B, 0x10, 4);
}

/* Tail-call thunk: forwards to FIELD_MSGBG_SetBlend with no argument change. */
void FIELD_MSGBG_SetBlendThunk(u32 enable)
{
    FIELD_MSGBG_SetBlend(enable);
}

void FIELD_MSGBG_ReloadBg(FieldMsgBg *msgBg)
{
    BG_SYS_FreeTiles(msgBg->bgFrame, 1, 0);
    BG_SYS_Init(msgBg->bgFrame, 0, 1, 0);
    BG_SYS_SetTileEntry((u8)msgBg->bgFrame, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile((u8)msgBg->bgFrame);
    FIELD_MSGBG_LoadWindowGraphicsAll(msgBg->bgFrame, msgBg->heapId);
    TALKMSGWIN_ReloadFrameGraphics(msgBg->talkSys);
}

struct BmpWin *FIELD_MSGBG_CreateWindow(int frame, int unusedHeapId, int x, int y, u16 width, u16 height, u16 palette)
{
    struct BmpWin *bmpWin;
    int framePalette;

    bmpWin = BMP_WIN_Create(frame & 0xff, x & 0xff, y & 0xff, width & 0xff, height & 0xff, palette & 0xff, 1);
    BMP_Clear(BMP_WIN_GetBmp(bmpWin), 0xff);
    BMP_WIN_MakeScreen(bmpWin);
    BMP_WIN_TransferChars(bmpWin);
    BG_SYS_PushTile((u8)frame);
    framePalette = 0xd;
    if (palette != FIELD_MSGBG_PALETTE_SYSTEM) {
        framePalette = 0xa;
    }
    BMP_MENUWORK_DrawWindow(bmpWin, 0, 1, framePalette & 0xff);
    return bmpWin;
}

int FIELD_MSGBG_DeleteWindow(struct BmpWin *bmpWin)
{
    BMP_MENUWORK_DrawWindowBorder(bmpWin, 0);
    return BMP_WIN_Delete(bmpWin);
}

void FIELD_MSGBG_LoadMenuGraphicsLower(u32 heapId)
{
    ARC_UTIL_UploadPaletteFromArchive(5, BMP_MENUWORK_GetPlttFileId(0), 0, 0x20, 0x1A0, 0x20, (u16)heapId);
}

void FIELD_MSGBG_LoadMenuGraphicsUpper(u32 heapId)
{
    ARC_UTIL_UploadPaletteFromArchive(5, BMP_MENUWORK_GetPlttFileId(0), 0, 0, 0x140, 0x20, (u16)heapId);
}

/* Stores the sub window in the first free slot and returns the slot (8 when full). */
int FIELD_MSGBG_StoreSubMsgWin(FieldMsgBg *msgBg, FieldSubMsgWin *subMsgWin)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (msgBg->subMsgWin[i] == 0) {
            msgBg->subMsgWin[i] = subMsgWin;
            return i;
        }
    }
    return i;
}

/* Takes the sub window with this id out of its slot and returns it (0 when absent). */
FieldSubMsgWin *FIELD_MSGBG_RemoveSubMsgWin(FieldMsgBg *msgBg, u32 id)
{
    int i;
    FieldSubMsgWin *subMsgWin;

    for (i = 0; i < 8; i++) {
        if (msgBg->subMsgWin[i] != 0 && msgBg->subMsgWin[i]->id == id) {
            subMsgWin = msgBg->subMsgWin[i];
            msgBg->subMsgWin[i] = 0;
            return subMsgWin;
        }
    }
    return 0;
}

void FIELD_MSGBG_KeyWaitInit(FieldMsgKeyWait *keyWait)
{
    MI_CpuFill8(keyWait, 0, sizeof(FieldMsgKeyWait));
}

void FIELD_MSGBG_KeyWaitReset(FieldMsgKeyWait *keyWait)
{
    keyWait->waitState = 0;
    keyWait->skipHeld = 0;
}

void FIELD_MSGBG_KeyWaitSetAuto(FieldMsgKeyWait *keyWait, u8 autoMode)
{
    keyWait->autoMode = autoMode;
}

u8 FIELD_MSGBG_KeyWaitGetAuto(FieldMsgKeyWait *keyWait)
{
    return keyWait->autoMode;
}

/* Frames per character of a streamed message. */
u32 FIELD_MSGBG_KeyWaitGetCharWait(FieldMsgKeyWait *keyWait)
{
    if (keyWait->autoMode != 0)
        return MSG_SPEED_GetWaitForSpeed(1);
    return MSG_SPEED_GetWait();
}

/* Returns 1 when A or B is pressed after one of them was held since the stream started. */
int FIELD_MSGBG_KeyWaitCheckSkip(FieldMsgKeyWait *keyWait)
{
    u32 held = KEY_GetTrg();
    u32 trg = KEY_GetCont();

    if (keyWait->autoMode != 0)
        return 0;
    if (held & PAD_BUTTON_AB)
        keyWait->skipHeld = 1;
    if (keyWait->skipHeld != 0 && (trg & PAD_BUTTON_AB))
        return 1;
    return 0;
}

/* Returns 1 when the message may advance: after a delay in auto mode, on A or B held otherwise. */
int FIELD_MSGBG_KeyWaitCheckAdvance(FieldMsgKeyWait *keyWait, u32 streamState)
{
    int held = KEY_GetTrg();
    int delay;

    if (streamState == 0) {
        delay = 8;
    } else {
        delay = 0x32;
    }
    if (keyWait->autoMode != 0) {
        keyWait->waitState = keyWait->waitState + 1;
        if (keyWait->waitState >= delay) {
            keyWait->waitState = 0;
            return 1;
        }
        return 0;
    }
    if ((held & PAD_BUTTON_AB) != 0) {
        return 1;
    }
    return 0;
}

void FIELD_MSGBG_StreamSetSpeed(struct TextPrinter *stream, int fast)
{
    if (fast == 1)
        PRINTSYS_PrintStreamSetSpeed((struct TextPrinter *)stream, MSG_SPEED_GetWaitForSpeed(2));
    else
        PRINTSYS_PrintStreamResetSpeed((struct TextPrinter *)stream);
}
