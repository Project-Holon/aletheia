/*
 * file:     mb_seq.c
 * unit:     yes
 * function: MAILVIEW_InitBgs, MAILVIEW_FreeBgs, MAILVIEW_LoadGraphics, MAILVIEW_FreeGraphics, MAILVIEW_CreateWindows, MAILVIEW_CreateButtons, MAILVIEW_DeleteWindows, MAILVIEW_PrintSentences, MAILVIEW_InitActorSystem, MAILVIEW_ExitActorSystem, MB_SEQ_ProcInit, MB_SEQ_ProcMain, MB_SEQ_ProcExit, MB_SEQ_VBlankTask, MB_SEQ_SetVramBanks, MB_SEQ_InitBgs, MB_SEQ_FreeBgs, MB_SEQ_LoadFrameCharData, MB_SEQ_LoadMiscGraphics, MB_SEQ_CreateFrames, MB_SEQ_DeleteFrames, MB_SEQ_CreateMessageResources, MB_SEQ_DeleteMessageResources, MB_SEQ_OpenTwoEntryMenu, MB_SEQ_CreateMenuEntries, MB_SEQ_DeleteMenuEntries, MB_SEQ_OpenFourEntryMenu, MB_SEQ_CloseMenu, MB_SEQ_CollectMails, MB_SEQ_FreeMails, MB_SEQ_DrawPage, MB_SEQ_DrawSelectedMail, MB_SEQ_StepSelectFlash, MB_SEQ_LoadSelectedMailGraphics, MB_SEQ_CreatePmsDraw, MB_SEQ_DeletePmsDraw, MB_SEQ_CreateWindows, MB_SEQ_DeleteWindows, MB_SEQ_PrintTextToSlot, MB_SEQ_PrintMessageToSlot, MB_SEQ_DrawMailEntry, MB_SEQ_DrawTitle, MB_SEQ_EmptyHookDetailClose, MB_SEQ_EmptyHookDetailReturn, MB_SEQ_SetWriterWord, MB_SEQ_StartMessagePrint, MB_SEQ_PrintDetailMessage, MB_SEQ_ShowMessageWindow, MB_SEQ_HideMessageWindow, MB_SEQ_PrintMenuMessage, MB_SEQ_DrawMailDetail, MB_SEQ_CreateActors, MB_SEQ_DeleteActors, MB_SEQ_DrawActors, MB_SEQ_InitActorSystem, MB_SEQ_ExitActorSystem, MB_SEQ_CreateActor, MB_SEQ_DeleteActor, MB_SEQ_DeleteAllActors, MB_SEQ_SetActorAnim, MB_SEQ_SetActorVisible, MB_SEQ_SetActorPosition, MB_SEQ_SetActorObjMode, MB_SEQ_LoadActorArc, MB_SEQ_FreeActorArc, MB_SEQ_RegisterSystemActorResources, MB_SEQ_RegisterMailActorResources, MB_SEQ_ShowCursorActor, MB_SEQ_Update, MB_SEQ_StateInit, MB_SEQ_StateExit, MB_SEQ_StateFadeWait, MB_SEQ_StateMessageWait, MB_SEQ_StateConfirmMenu, MB_SEQ_StateFlashWait, MB_SEQ_StateStartChild, MB_SEQ_StateChildWait, MB_SEQ_StateFadeInToList, MB_SEQ_StateList, MB_SEQ_StateLeave, MB_SEQ_StateRedrawPage, MB_SEQ_ShowMailDetail, MB_SEQ_StateOpenActionMenu, MB_SEQ_StateActionMenu, MB_SEQ_StateDetail, MB_SEQ_CloseMailDetail, MB_SEQ_OpenConfirmMenuKind0, MB_SEQ_ShowMessage2, MB_SEQ_OpenConfirmMenuKind1, MB_SEQ_FinishPartyListChoice, MB_SEQ_BeginReturnFade, MB_SEQ_ShowBagResultMessage, MB_SEQ_StartPartyListForReturn, MB_SEQ_StateBackButtonDone, MB_SEQ_StateCloseButtonDone, MB_SEQ_CancelDetail, MB_SEQ_StartFadeIn, MB_SEQ_StartFadeOut, MB_SEQ_SetMessageWait, MB_SEQ_OpenMenuKind, MB_SEQ_StartMailFlash, MB_SEQ_StartArrowFlash, MB_SEQ_SetButtonsEnabled, MB_SEQ_SetDetailButtons, MB_SEQ_LoadMailDetail, MB_SEQ_ClearMailDetailText, MB_SEQ_CheckBagForItem, MB_SEQ_DeleteSelectedMail, MB_SEQ_CreatePartyListArgs, MB_SEQ_PushPartyList, MB_SEQ_FinishChildFreeA, MB_SEQ_FinishPartyList, MB_SEQ_FinishChildFreeB, MB_SEQ_PushMailTool, MB_SEQ_FinishMailTool, MB_SEQ_ReloadMailList, MB_SEQ_StartPartyListToTake, MB_SEQ_ShowItemMessage, MB_SEQ_GetPageButtonHit, MB_SEQ_CreateTouchSelect, MB_SEQ_DeleteTouchSelect, MB_SEQ_EmptyStubA, MB_SEQ_EmptyStubB, MB_SEQ_MoveCursorA, MB_SEQ_MoveCursorB, MB_SEQ_MoveCursorToPosition, MB_SEQ_IsConfirmPressed, MB_SEQ_IsXPressed
 * address:  0x021C4DE4
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mailtool.c, mailview.c, unit_021C5518.c, unit_021C5B40.c, mb_seq.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02008FEC 0x02008FEC thumb
 *   func_02030734 0x02030734 arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   func_020307B0  0x020307B0  arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Main 0x02031330 arm
 *   PROCSYS_Push 0x02031348 arm
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_0203084C 0x0203084C arm
 *   func_020306F0 0x020306F0 arm
 *   PMSI_PARAM_IsEnabled 0x02024450 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_02008F84 0x02008F84 thumb
 *   STRBUF_SetString 0x02045924 arm
 *   func_02008FA4 0x02008FA4 thumb
 *   func_02008FC0 0x02008FC0 thumb
 *   func_02008FC8 0x02008FC8 thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   TCBL_Create 0x0203101C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   TCBL_Destroy 0x02031140 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020056A0 0x020056A0 thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   func_0207D63C 0x0207D63C arm
 *   PMS_DRAW_Main 0x0202DBC4 thumb
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02045EC0 0x02045EC0 arm
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   func_020419E4 0x020419E4 arm
 *   func_02045B38 0x02045B38 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   CLACT_CreateUnit 0x0204B100 arm
 *   PMS_DRAW_SetNullColorPalette 0x0202DE5C thumb
 *   PMS_DRAW_Delete 0x0202DC08 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   d_021C77C4 0x021C77C4 data a1
 *   func_0203FC28 0x0203FC28 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   g_77F4 0x021C77F4 data
 *   g_7804 0x021C7804 data
 *   func_020403F4 0x020403F4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_LoadHandlePaletteToSlot 0x020216B4 thumb
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   func_0201F548 0x0201F548 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   PALANM_Delete 0x02021540 thumb
 *   func_02030DA4 0x02030DA4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   PMS_DRAW_Print 0x0202DC48 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   MB_SEQ_Update 0x021C68A0 thumb
 *   d_021C78E0 0x021C78E0 data a1
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb  arm9
 *   PMS_DRAW_Create  0x0202DB0C  thumb  arm9
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb  arm9
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb  arm9
 *   g_7910 0x021C7910 data
 *   g_79E0 0x021C79E0 data
 *   g_79A0 0x021C79A0 data
 *   g_79C0 0x021C79C0 data
 *   g_7980 0x021C7980 data
 *   g_7960 0x021C7960 data
 *   g_7940 0x021C7940 data
 *   g_7A00 0x021C7A00 data
 *   g_7920 0x021C7920 data
 *   ARC_UTIL_LoadBgCharDataFromHandle 0x02049DF4 arm
 *   MIi_CpuCopyFast 0x02082B0C arm
 *   BGWINFRM_Create 0x0202C9B4 thumb
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_SetFrameDataArc 0x0202CAE4 thumb
 *   BGWINFRM_GetFrameBuffer 0x0202CF84 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   BGWINFRM_Delete 0x0202CA0C thumb
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   g_78C0 0x021C78C0 data
 *   g_78B0 0x021C78B0 data
 *   func_02009050 0x02009050 thumb
 *   func_02008EF8 0x02008EF8 thumb
 *   BGWINFRM_HideFrame 0x0202CC70 thumb
 *   BGWINFRM_ShowFrame 0x0202CC58 thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   func_020413B0 0x020413B0 arm
 *   g_7A20 0x021C7A20 data
 *   BMP_CreateFromBuffer 0x020436FC arm
 *   BMP_Blit 0x020439A0 arm
 *   func_02008F9C 0x02008F9C thumb
 *   BGWINFRM_PutBmpWin 0x0202CEBC thumb
 *   BMP_Delete 0x020437AC arm
 *   func_0201F250     0x0201F250  thumb
 *   func_0201F73C   0x0201F73C  thumb
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   d_021C7BBC 0x021C7BBC data ov136 a4
 *   d_021C7BA0 0x021C7BA0 data a4
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_SetActorAnimSeq        0x0204B878  arm
 *   CLACT_SetActorDrawEnable        0x0204B3DC  arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorObjMode  0x0204B688  arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_02027698 0x02027698 thumb
 *   func_0202769C 0x0202769C thumb
 *   func_020276A0 0x020276A0 thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   PRINTSYS_QUE_IsExistTarget            0x0201C6C4  thumb
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   d_021C7DA8 0x021C7DA8 data a4
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes             0x020435F4  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   MB_SEQ_VBlankTask 0x021C54FC thumb
 *   MB_SEQ_SetVramBanks 0x021C5508 thumb
 *   MB_SEQ_InitBgs 0x021C5518 thumb
 *   MB_SEQ_LoadFrameCharData 0x021C574C thumb
 *   MB_SEQ_LoadMiscGraphics 0x021C5828 thumb
 *   MB_SEQ_CreateFrames 0x021C587C thumb
 *   MB_SEQ_CreateMessageResources 0x021C5924 thumb
 *   MB_SEQ_CreateMenuEntries 0x021C59B8 thumb
 *   MB_SEQ_CollectMails 0x021C5B40 thumb
 *   MB_SEQ_DrawPage 0x021C5C00 thumb
 *   MB_SEQ_CreatePmsDraw 0x021C5DD8 thumb
 *   MB_SEQ_CreateWindows 0x021C5E58 thumb
 *   MB_SEQ_DrawTitle 0x021C6170 thumb
 *   MB_SEQ_CreateActors 0x021C64A8 thumb
 *   d_021C7F04 0x021C7F04 data a1
 *   MB_SEQ_DeleteMenuEntries 0x021C5AA8 thumb ov136
 *   MB_SEQ_DeleteMessageResources 0x021C5954 thumb ov136
 *   MB_SEQ_DeletePmsDraw 0x021C5E30 thumb ov136
 *   MB_SEQ_DeleteActors 0x021C657C thumb ov136
 *   MB_SEQ_DeleteFrames 0x021C5918 thumb ov136
 *   MB_SEQ_DeleteWindows 0x021C5F44 thumb ov136
 *   MB_SEQ_FreeBgs 0x021C5714 thumb ov136
 *   MB_SEQ_FreeMails 0x021C5BE0 thumb ov136
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   d_021C7D68 0x021C7D68 data a4
 *   MB_SEQ_StepSelectFlash  0x021C5C84  thumb
 *   d_021C7D78 0x021C7D78 data a4
 *   d_021C7D7C 0x021C7D7C data a4
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   MB_SEQ_SetActorAnim 0x021C66A0 thumb
 *   MB_SEQ_IsXPressed 0x021C7738 thumb
 *   MB_SEQ_SetActorVisible 0x021C66B8 thumb
 *   MB_SEQ_DrawSelectedMail  0x021C5C64  thumb
 *   MB_SEQ_PrintDetailMessage 0x021C6284 thumb
 *   MB_SEQ_ShowMessageWindow 0x021C62BC thumb
 *   MB_SEQ_OpenFourEntryMenu  0x021C5AEC  thumb
 *   func_020213AC 0x020213AC thumb
 *   MB_SEQ_CloseMenu 0x021C5B30 thumb
 *   MB_SEQ_EmptyHookDetailClose 0x021C61CC thumb
 *   MB_SEQ_HideMessageWindow 0x021C62F4 thumb
 *   MB_SEQ_PrintMenuMessage 0x021C630C thumb
 *   MB_SEQ_ShowCursorActor 0x021C6884 thumb
 *   MB_SEQ_EmptyHookDetailReturn 0x021C61D0 thumb ov136
 *   CLACT_IsActorAnimActive   0x0204B98C  arm
 *   WIPE_SYS_Start   0x0202208C  thumb
 *   MB_SEQ_OpenTwoEntryMenu 0x021C5974 thumb
 *   MB_SEQ_SetActorObjMode 0x021C670C thumb ov136
 *   MB_SEQ_LoadSelectedMailGraphics 0x021C5D68 thumb
 *   MB_SEQ_DrawMailDetail 0x021C6374 thumb
 *   func_0200902C 0x0200902C thumb
 *   ov091_id 0x0000005B data
 *   gPartyListProcData 0x021BED00 data ov091 a4
 *   func_0202138C  0x0202138C  thumb
 *   MAILTOOL_CreateWriteArgs  0x021C3CC0  thumb
 *   d_021C7D5C 0x021C7D5C data a4
 *   MAILTOOL_HasMail 0x021C3E00 thumb ov136
 *   MAILTOOL_StoreMailToPartyMon 0x021C3E04 thumb ov136
 *   MAILTOOL_DeleteArgs 0x021C3E24 thumb ov136
 *   d_021C7E2C 0x021C7E2C data a4
 *   CURSOR_MOVE_Create 0x02025CD0 thumb
 *   d_021C7E40 0x021C7E40 data a4
 *   d_021C7E1C 0x021C7E1C data a4
 *   CURSOR_MOVE_Delete  0x02025D14  thumb
 *   CURSOR_MOVE_GetEntry  0x0202616C  thumb
 *   MB_SEQ_SetActorPosition 0x021C66CC thumb
 *   d_021C7E14 0x021C7E14 data a4
 *   BGWINFRM_GetPos  0x0202CF98  thumb  arm9
 *   BGWINFRM_GetSize  0x0202CFC0  thumb  arm9
 *   PMS_DRAW_Clear  0x0202DC9C  thumb  arm9
 *   GAME_DATA_GetMyItem  0x0201292C  thumb  arm9
 *   GAME_DATA_GetMyParty  0x02012934  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb  arm9
 *   MAILSYS_OnTouchMode 0x021C4528 thumb ov136
 *   MAILSYS_OnKeyModeNoOp 0x021C4534 thumb ov136
 *   MAILVIEW_SetVramBanks 0x021C4DD4 thumb ov136
 */
#include "mail_types.h"
#include "../ov091/pokelist_types.h"

/* Opaque types of callees in other files. */
struct Bmp;
struct Cfg;
struct DispVram;
struct ProcData;
struct Obj0203159C;
struct S020315D4;

/* Loaded BG character data (the data pointer sits at +0x14). */
struct BgCharData {
    u8 pad_00[0x14];
    u8 *tiles;
};

/* Row of the window table g_7A20 (12 bytes). */
struct MailBoxWinDef {
    u32 bg;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
    u16 palette;
    /* 2 trailing bytes: the row is padded to the 4 byte alignment of bg. */
};

/* Row of the menu entry tables g_78B0 and g_78C0. */
struct MailBoxMenuDef {
    u32 messageId;
    u32 value;
};

/* Row of the actor table d_021C7BBC (0x34 bytes). */
struct MailBoxActorDef {
    s16 x;
    s16 y;
    u16 unused_04;
    u16 value;
    u32 unused_08[2];
    u32 space;
    u32 charIndex;
    u32 paletteIndex;
    u32 cellIndex;
    u32 unused_20[3];
    u32 mode;
    u32 unused_30;
};

struct ClactActorParam {
    s16 x;
    s16 y;
    u16 value;
    u8 flag;
    u8 mode;
};

struct ClactPos {
    s16 x;
    s16 y;
};

/* Rectangle of a touch panel hit table (top, bottom, left, right). */
struct TouchRect {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
};

typedef enum { ACTIVE = 1 } Active;

/* Offset of listIndex in MailBoxView: the original indexes from the view base plus the column. */
#define MAILBOXVIEW_LISTINDEX ((u32)&((struct MailBoxView *)0)->listIndex)

struct MailBoxMenuHandlers {
    int (*onFirst)(struct MailBoxProc *);
    int (*onSecond)(struct MailBoxProc *);
};

struct MailBoxChildStart {
    void (*start)(struct MailBoxProc *);
    u32 unused0;
    u32 unused1;
};

struct MailBoxChildFinish {
    int (*onFinish)(struct MailBoxProc *);
    int result;
    int unused;
};

extern struct MailData *func_02008FEC(void *sys);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);

extern void func_020306F0(u32);

extern int PMSI_PARAM_IsEnabled(const struct PmsData *p);

extern u16 *func_02008F84(struct Mail *mail);

extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);

extern u8 func_02008FA4(const struct Mail *mail);

extern u16 func_02008FC0(const struct Mail *mail);

extern struct PmsData *func_02008FC8(struct Mail *mail, u32 index);

extern void STRBUF_Delete(struct Strbuf *vec);

extern signed char MSG_SPEED_GetWait(void);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);

extern void BG_SYS_Create(u16);

extern void BG_SYS_Delete(void);

extern void TCBL_Destroy(struct Tcbl *p);

extern u32 GF_FONT_Delete(void *ptr);

extern void BG_SYS_SetMainPlaneVisible(u32, u32);

extern void PMS_DRAW_Main(struct PmsDraw *draw);

extern void func_02030EAC(void *task);

extern void TCBL_Main(struct Tcbl *p);

extern u32 PRINTSYS_QUE_Main(struct PrintQue *ps);

struct PalAnm;


struct DispConfig { u32 w[4]; };

struct BgTemplate { u32 w[8]; };

struct BgSet { struct BgTemplate t[5]; };

extern u32 KEY_GetTrg(void);

extern int TOUCHPANEL_GetTrg(void);

extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);

extern void BMP_Clear(struct Bmp *bmp, u8 value);

extern void func_02045CAC(struct MsgData *bank, u32 index, struct Strbuf *dest);

extern struct PrintStream *PRINTSYS_PrintStream(struct BmpWin *win, u32 x, u32 y, struct Strbuf *text, struct GfFont *font, int speed, struct Tcbl *tcbl, u32 unused, u16 heapId, u16 clearColor);

extern void BMP_WIN_TransferChars(struct BmpWin *d);

extern void BMP_WIN_MakeScreen(struct BmpWin *cfg);

extern u8 BMP_WIN_GetBgLayer(struct BmpWin *p);

extern void func_020409B4(u32 v);

extern u32 PRINTSYS_PrintStreamGetState(struct PrintStream *stream);

extern void PRINTSYS_PrintStreamDelete(struct PrintStream *stream);

extern void func_0201F7A8(void *desc, u32 kind);

extern void BMP_WIN_ClearScreen(struct BmpWin *d);

extern void *func_02045EC0(struct MsgData *bank, u32 index);

extern struct AppTaskMenu *APP_TASKMENU_OpenMenu(struct MailMenuTemplate *tmpl, struct AppTaskMenuRes *res);

extern u32 APP_TASKMENU_IsFinish(struct AppTaskMenu *m);

extern void APP_TASKMENU_CloseMenu(struct AppTaskMenu *m);

extern void BG_SYS_SetSubPlaneVisible(u32, u32);

extern void CLACT_VBlankSystem(void);

extern void func_020419E4(void);

extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);

extern u32 APP_TASKMENU_RES_Delete(struct AppTaskMenuRes *s);

extern struct PrintQue *PRINTSYS_QUE_Create(u32 heapId);

extern struct ClactUnit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern struct PmsDraw *PMS_DRAW_Create(struct ClactUnit *clactUnit, u32 b, struct PrintQue *printQue, struct GfFont *font, u8 e0, u8 e1, u16 heap);

extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *p, u8 v);

extern void PMS_DRAW_Delete(struct PmsDraw *draw);

extern void PRINTSYS_QUE_Delete(struct PrintQue *p);

extern u32 CLACT_DeleteUnit(struct ClactUnit *bank);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void func_0203FC28(struct DispConfig *);

extern void func_0204363C(u32);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void BG_SYS_ClearSlot(u32);

extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);

extern void func_020403F4(u32 bgId);

extern void *func_020490F4(u32 id, u32 heap);

extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);

extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void *PALANM_Create(u32 heap);

extern void PALANM_AllocSlotBuffers(struct PalAnm *slots, u32 idx, u32 size, u32 heap);

extern void PALANM_LoadHandlePaletteToSlot(struct PalAnm *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);

extern void PALANM_LoadArcPaletteToSlot(struct PalAnm *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);

extern u8 func_0201F548(int i);

extern void func_0201DD68(void);

extern void ARC_TOOL_DeleteHandle(void *);

extern void func_02041300(unsigned int, int, int, int, unsigned char, unsigned char, unsigned char);

extern void func_02041B6C(u32);

extern void PALANM_FreeSlotBuffers(struct PalAnm *slots, u32 idx);

extern u32 PALANM_Delete(void *a0);

extern void func_02030DA4(void *);

extern void func_0207D63C(void *, int, int, int, int);

extern void BMP_WIN_Init(u16);

extern struct BmpWin *BMP_WIN_Create(u8 bg, u8 x, u8 y, u8 w, u8 h, u8 pal, u8 base);

extern struct AppTaskMenuWin *APP_TASKMENU_WIN_Create(struct AppTaskMenuRes *res, struct MailMenuEntry *entry, u32 x, u32 y, u8 w, u16 heapId);

extern void APP_TASKMENU_WIN_Delete(struct AppTaskMenuWin *p);

extern u32 BMP_WIN_Delete(struct BmpWin *d);

extern void BMP_WIN_Exit(void);

extern void PMS_DRAW_Print(struct PmsDraw *draw, struct BmpWin *win, struct PmsData *pms, u8 index);

extern void PRINTSYS_PrintQueColor(struct PrintQue *queue, struct Bmp *bmp, s16 x, s16 y, struct Strbuf *text, struct GfFont *font, u16 color);

extern void CLACT_InitSystem(const struct Cfg *cfg, const struct DispVram *vram, u32 heapId);

extern void CLACT_SetUnitDefaultRenderer(struct ClactUnit *bank);

extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);

extern void CLACT_ExitSystem(void);

extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);

extern void MIi_CpuClearFast(u32, void *, u32);

extern void *PROCSYS_Create(int);

int MB_SEQ_Update(struct MailBoxProc *p, int *state);

extern void func_0203133C(void *procSys);

extern void func_020315D4(struct S020315D4 *p);

extern void *func_0203084C(u32 heapId);

int MAILSYS_OnTouchMode(struct MailEditProc *proc);
int MAILSYS_OnKeyModeNoOp(void);













int MB_SEQ_ProcInit(void *procSys, int unused, struct MailBoxArgs *args);

int MB_SEQ_ProcMain(void *procSys, int *state, void *unused, struct MailBoxProc *p);

int MB_SEQ_ProcExit(void *procSys, void *state, void *unused, struct MailBoxProc *p);

void MB_SEQ_VBlankTask(void *unused);

void MB_SEQ_SetVramBanks(void);

extern const struct DispVram d_021C77C4;

extern const struct DispConfig g_77F4;

extern const struct BgSet g_7804;

extern u8 gClActorInitParam[];

extern const struct DispVram d_021C78E0;

void MAILVIEW_InitBgs(struct MailEditProc *proc)
{
    MAILVIEW_SetVramBanks();
    {
        struct DispConfig d = g_77F4;
        func_0203FC28(&d);
    }
    func_0204363C(0);
    {
        struct BgSet s = g_7804;
        BG_SYS_InitBgLayer(0, &s.t[0], 0);
        BG_SYS_InitBgLayer(1, &s.t[1], 0);
        BG_SYS_InitBgLayer(2, &s.t[2], 0);
        BG_SYS_InitBgLayer(3, &s.t[3], 0);
        BG_SYS_InitBgLayer(4, &s.t[4], 0);
    }
    BG_SYS_ClearSlot(0);
    BG_SYS_ClearSlot(1);
    BG_SYS_ClearSlot(2);
    BG_SYS_ClearSlot(3);
    BG_SYS_ClearSlot(4);
    BG_SYS_InitRun(0, 0x20, 0, (u16)(proc->heapId));
    BG_SYS_InitRun(1, 0x20, 0, (u16)(proc->heapId));
    BG_SYS_InitRun(2, 0x20, 0, (u16)(proc->heapId));
    BG_SYS_InitRun(3, 0x20, 0, (u16)(proc->heapId));
    BG_SYS_InitRun(4, 0x20, 0, (u16)(proc->heapId));
}

void MAILVIEW_FreeBgs(struct MailEditProc *proc)
{
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0204363C(1);
}

/*
 * note (2026-10-02): byte-correct; only the ABS32 word for MAILSYS_OnKeyModeNoOp (an unlabelled
 *   ov136 leaf "return 0", not in any lane) lacks a witness. File that leaf, then re-verify.
 */
void MAILVIEW_LoadGraphics(struct MailEditProc *proc)
{
    u32 design = proc->draft->design;
    void *arc = func_020490F4(0x9B, (u16)proc->heapId);
    u32 sz;
    u32 pal;
    u32 chr;

    func_0201F5BC(0, 1, 4, 0, (u16)proc->heapId);
    func_0201F5BC(0, 0xD, 6, 0, (u16)proc->heapId);
    pal = design + 0xC;
    func_02049658(arc, pal, 3, 0, 0, 1, (u16)proc->heapId);
    func_02049658(arc, pal, 4, 0, 0, 1, (u16)proc->heapId);
    chr = design + 0x18;
    sz = 0x800;
    func_020498F4(arc, chr, 3, 0, sz, 1, (u16)proc->heapId);
    func_020498F4(arc, chr, 4, 0, sz, 1, (u16)proc->heapId);
    func_02049B68(arc, design, 4, 0, 0, (u16)proc->heapId);
    func_02049B40(0x17, 5, 0, 0xA0, 0x20, (u16)proc->heapId);
    proc->palAnm = PALANM_Create(proc->heapId);
    PALANM_AllocSlotBuffers(proc->palAnm, 0, 0xE0, (u16)proc->heapId);
    PALANM_LoadHandlePaletteToSlot(proc->palAnm, arc, design, (u16)proc->heapId, 0, 0x60, 0);
    PALANM_LoadArcPaletteToSlot(proc->palAnm, 0x17, 7, (u16)proc->heapId, 0, 0x20, 0x30);
    PALANM_LoadArcPaletteToSlot(proc->palAnm, 0x17, 5, (u16)proc->heapId, 0, 0x20, 0x50);
    PALANM_LoadArcPaletteToSlot(proc->palAnm, 5, func_0201F548(0), (u16)proc->heapId, 0, 0x20, 0x40);
    PALANM_LoadArcPaletteToSlot(proc->palAnm, 5, func_0201F548(1), (u16)proc->heapId, 0, 0x20, 0x60);
    func_0201DD68();
    ARC_TOOL_DeleteHandle(arc);
    func_02041300(4, 0x2001, 0, 0, 0x20, 0x20, 0x11);
    func_02041B6C(4);
    BG_SYS_SetMainPlaneVisible(1, 1);
    BG_SYS_SetMainPlaneVisible(2, 1);
    BG_SYS_SetMainPlaneVisible(8, 1);
    if (proc->mode != 0) {
        arc = func_020490F4(0x9B, (u16)proc->heapId);
        func_020498F4(arc, 0x24, 2, 0, sz, 1, (u16)proc->heapId);
        ARC_TOOL_DeleteHandle(arc);
        proc->onKeyInput = (void (*)(void *))MAILSYS_OnKeyModeNoOp;
        proc->onTouchInput = (void (*)(void *))MAILSYS_OnTouchMode;
        BG_SYS_SetMainPlaneVisible(4, 1);
    }
}

void MAILVIEW_FreeGraphics(struct MailEditProc *proc)
{
    PALANM_FreeSlotBuffers(proc->palAnm, 0);
    PALANM_Delete(proc->palAnm);
    proc->palAnm = 0;
    func_02030EAC(proc->blinkTask);
    func_02030DA4(proc->blinkTaskList);
    func_020307B0(proc->blinkTaskMem);
    func_0207D63C((void *)0x04000050, 0, 0, 31, 0);
}

void MAILVIEW_CreateWindows(struct MailEditProc *proc)
{
    int i;
    struct BmpWin *w;

    BMP_WIN_Init((u16)proc->heapId);
    proc->win[0] = BMP_WIN_Create(1, 0, 0, 1, 1, 5, 0);
    proc->win[1] = BMP_WIN_Create(1, 3, 3, 0x1A, 4, 1, 0);
    proc->win[2] = BMP_WIN_Create(1, 3, 8, 0x1A, 4, 1, 0);
    proc->win[3] = BMP_WIN_Create(1, 3, 0xD, 0x1A, 4, 1, 0);
    proc->win[4] = BMP_WIN_Create(1, 8, 0x13, 0xB, 2, 1, 0);
    proc->win[5] = BMP_WIN_Create(1, 0x15, 0x13, 8, 2, 1, 0);
    proc->win[6] = BMP_WIN_Create(0, 2, 1, 0x1C, 4, 5, 1);
    for (i = 0; i < 6; i++) {
        proc->slot[i].win = proc->win[i];
        proc->slot[i].flag = 0;
    }
    proc->printQue = PRINTSYS_QUE_Create((u16)proc->heapId);
    for (i = 0; i < 7; i++) {
        BMP_Clear(BMP_WIN_GetBmp(proc->win[i]), 0);
        if (i < 5) {
            w = proc->win[i];
            BMP_WIN_TransferChars(w);
            BMP_WIN_MakeScreen(w);
            func_020409B4(BMP_WIN_GetBgLayer(w));
        }
    }
}

void MAILVIEW_CreateButtons(struct MailEditProc *proc)
{
    if (proc->mode == 1) {
        proc->buttonEntry[0].text = func_02045EC0(proc->msgData, 0);
        proc->buttonEntry[0].color = 0x39E3;
        proc->buttonEntry[0].selected = 0;
        proc->buttonEntry[1].text = func_02045EC0(proc->msgData, 1);
        proc->buttonEntry[1].color = 0x39E3;
        proc->buttonEntry[1].selected = 1;
        proc->sendButton = APP_TASKMENU_WIN_Create(proc->taskMenuRes, &proc->buttonEntry[0], 21, 18, 10, (u16)proc->heapId);
        proc->cancelButton = APP_TASKMENU_WIN_Create(proc->taskMenuRes, &proc->buttonEntry[1], 21, 21, 10, (u16)proc->heapId);
    }
}

/*
 * lever: base + i * 4 + 0x44 keeps the base-plus-index inside the loop;
 * base + 0x44 + i * 4 hoists the field address and changes the loads.
 */
void MAILVIEW_DeleteWindows(struct MailEditProc *proc)
{
    int i;
    struct BmpWin *w;
    if (proc->mode == 1) {
        APP_TASKMENU_WIN_Delete(proc->sendButton);
        APP_TASKMENU_WIN_Delete(proc->cancelButton);
        STRBUF_Delete(proc->buttonEntry[0].text);
        STRBUF_Delete(proc->buttonEntry[1].text);
    }
    PRINTSYS_QUE_Delete(proc->printQue);
    proc->printQue = 0;
    for (i = 0; i < 7; i++) {
        w = proc->win[i];
        BMP_WIN_ClearScreen(w);
        func_020409B4(BMP_WIN_GetBgLayer(w));
        BMP_WIN_Delete(proc->win[i]);
    }
    BMP_WIN_Exit();
}

/*
 * note: 2026-10-02 byte-exact; waiting on arm9 witness shard for PMSI_PARAM_IsEnabled
 */
void MAILVIEW_PrintSentences(struct MailEditProc *proc)
{
    int i;
    struct MailDraft *draft;
    struct BmpWin *w;
    for (i = 0; i < 3; i++) {
        if (PMSI_PARAM_IsEnabled(&proc->draft->message[i])) {
            PMS_DRAW_Print(proc->pmsDraw, proc->win[i + 1], &proc->draft->message[i], (u8)i);
        }
    }
    draft = proc->draft;
    if (draft->messageId != 0xFFFF) {
        proc->closingWord.sentenceType = 6;
        proc->closingWord.sentenceId = 0;
        proc->closingWord.word[0] = draft->messageId;
        PMS_DRAW_Print(proc->pmsDraw, proc->win[4], &proc->closingWord, (u8)3);
    }
    if (proc->mode == 0) {
        struct PrintQue *queue = proc->printQue;
        PRINTSYS_PrintQueColor(queue, BMP_WIN_GetBmp(proc->slot[5].win), 0, 2, proc->draft->writerName, proc->font, 0x440);
        proc->slot[5].flag = 1;
        w = proc->win[5];
        BMP_WIN_TransferChars(w);
        BMP_WIN_MakeScreen(w);
        func_020409B4(BMP_WIN_GetBgLayer(w));
    }
}

void MAILVIEW_InitActorSystem(struct MailEditProc *proc)
{
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam, &d_021C77C4, (u16)(proc->heapId));
    proc->clactUnit = CLACT_CreateUnit(4, (int)0, (u16)(proc->heapId));
    CLACT_SetUnitDefaultRenderer(proc->clactUnit);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
    GFL_NET_RestartWithDefaultTimeout((int)0, (u16)(proc->heapId));
}

void MAILVIEW_ExitActorSystem(struct MailEditProc *proc)
{
    CLACT_DeleteUnit(proc->clactUnit);
    CLACT_ExitSystem();
}

int MB_SEQ_ProcInit(void *procSys, int unused, struct MailBoxArgs *args)
{
    struct MailBoxProc *p;
    GFL_HEAP_CreateChildHeap(1,101,65536);
    p = PROCSYS_AllocProcWork(procSys,52,101);
    MIi_CpuClearFast(0,p,52);
    p->args = args;
    p->mailData = func_02008FEC(args->gameData);
    p->nextState = 8;
    p->vblankTask = 0;
    p->procSys = PROCSYS_Create(101);
    return 1;
}

int MB_SEQ_ProcMain(void *procSys, int *state, void *unused, struct MailBoxProc *p)
{
    if (MB_SEQ_Update(p, state) == 0) return 1;
    return 0;
}

int MB_SEQ_ProcExit(void *procSys, void *state, void *unused, struct MailBoxProc *p)
{
    func_0203133C(p->procSys);
    func_020315D4(procSys);
    func_0203084C(0x65);
    func_020306F0(0x65);
    return 1;
}

void MB_SEQ_VBlankTask(void *unused)
{
    func_020419E4();
    CLACT_VBlankSystem();
}

void MB_SEQ_SetVramBanks(void)
{
    BG_SYS_SetVramBanks(&d_021C78E0);
}

extern void *ARC_UTIL_LoadBgCharDataFromHandle(void *a0, u32 a1, u32 a2, struct BgCharData **out, u16 a4);

extern void MIi_CpuCopyFast(void *, const void *, u32);

extern struct BgWinFrm *BGWINFRM_Create(u32 a0, u32 a1, u32 heap);

extern void BGWINFRM_AddFrame(struct BgWinFrm *mgr, u32 idx, u32 bg, u32 w, u32 h);

extern void BGWINFRM_SetFrameDataArc(struct BgWinFrm *mgr, u32 idx, u32 arc, u32 member, u32 alloc);

extern void *BGWINFRM_GetFrameBuffer(struct BgWinFrm *mgr, u32 idx);

extern void MI_CpuCopy8(void *,void *,u32);

extern void BGWINFRM_PutFrame(struct BgWinFrm *mgr, u32 idx, s8 x, s8 y);

extern void BGWINFRM_Delete(struct BgWinFrm *mgr);

extern struct WordSet *GF_FONT_Create_EC64(u32 heap);

extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

extern u32 MSGDATA_Delete(struct MsgData *msgData);

extern struct AppTaskMenuRes *APP_TASKMENU_RES_Create(u16, u16, struct GfFont *font, struct PrintQue *printQue, u16);

void MB_SEQ_InitBgs(struct MailBoxProc *p);

void MB_SEQ_FreeBgs(struct MailBoxProc *p);

void MB_SEQ_LoadFrameCharData(struct MailBoxProc *p);

void MB_SEQ_LoadMiscGraphics(struct MailBoxProc *p);

void MB_SEQ_CreateFrames(struct MailBoxProc *p);

void MB_SEQ_DeleteFrames(struct MailBoxProc *p);

void MB_SEQ_CreateMessageResources(struct MailBoxView *view);

void MB_SEQ_DeleteMessageResources(struct MailBoxView *view);

void MB_SEQ_OpenTwoEntryMenu(struct MailBoxProc *p);

void MB_SEQ_CreateMenuEntries(struct MailBoxProc *p);

void MB_SEQ_DeleteMenuEntries(struct MailBoxProc *p);

void MB_SEQ_OpenFourEntryMenu(struct MailBoxProc *p);

void MB_SEQ_CloseMenu(struct MailBoxProc *p);

extern const struct DispConfig g_7910;

extern const struct BgTemplate g_79E0;

extern const struct BgTemplate g_79A0;

extern const struct BgTemplate g_79C0;

extern const struct BgTemplate g_7980;

extern const struct BgTemplate g_7960;

extern const struct BgTemplate g_7940;

extern const struct BgTemplate g_7A00;

extern const struct BgTemplate g_7920;

extern const struct MailBoxMenuDef g_78C0[];

extern const struct MailBoxMenuDef g_78B0[];

void MB_SEQ_InitBgs(struct MailBoxProc *p)
{
    BG_SYS_Create(0x66);
    {
        struct DispConfig d = g_7910;
        func_0203FC28(&d);
    }
    {
        struct BgTemplate t = g_79E0;
        BG_SYS_InitBgLayer(4, &t, 0);
        BG_SYS_ClearSlot(4);
        BG_SYS_InitRun(4, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_79A0;
        BG_SYS_InitBgLayer(5, &t, 0);
        BG_SYS_ClearSlot(5);
        BG_SYS_InitRun(5, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_79C0;
        BG_SYS_InitBgLayer(6, &t, 0);
        BG_SYS_ClearSlot(6);
        BG_SYS_InitRun(6, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_7980;
        BG_SYS_InitBgLayer(7, &t, 0);
    }
    {
        struct BgTemplate t = g_7960;
        BG_SYS_InitBgLayer(0, &t, 0);
        BG_SYS_ClearSlot(0);
        BG_SYS_InitRun(0, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_7940;
        BG_SYS_InitBgLayer(1, &t, 0);
        BG_SYS_ClearSlot(1);
        BG_SYS_InitRun(1, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_7A00;
        BG_SYS_InitBgLayer(2, &t, 0);
        BG_SYS_ClearSlot(2);
    }
    {
        struct BgTemplate t = g_7920;
        BG_SYS_InitBgLayer(3, &t, 0);
    }
    BG_SYS_SetMainPlaneVisible(1, 1);
    BG_SYS_SetMainPlaneVisible(2, 1);
    BG_SYS_SetMainPlaneVisible(4, 1);
    BG_SYS_SetMainPlaneVisible(8, 1);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(1, 1);
    BG_SYS_SetSubPlaneVisible(2, 1);
    BG_SYS_SetSubPlaneVisible(4, 1);
    BG_SYS_SetSubPlaneVisible(8, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void MB_SEQ_FreeBgs(struct MailBoxProc *p)
{
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    BG_SYS_Delete();
}

void MB_SEQ_LoadFrameCharData(struct MailBoxProc *p)
{
    void *handle;
    void *buf;
    struct BgCharData *charData;
    u8 *tiles;
    handle = func_020490F4(0x9B, 0x66);
    func_02049658(handle, 0x2A, 7, 0, 0, 1, 0x66);
    func_020498F4(handle, 0x29, 7, 0, 0, 1, 0x66);
    func_02049B68(handle, 0x2B, 4, 0, 0, 0x66);
    func_02049658(handle, 0x26, 3, 0, 0, 1, 0x66);
    func_02049658(handle, 0x26, 1, 0, 0, 1, 0x66);
    func_020498F4(handle, 0x25, 3, 0, 0, 1, 0x66);
    func_02049B68(handle, 0x27, 0, 0, 0, 0x66);
    buf = ARC_UTIL_LoadBgCharDataFromHandle(handle, 0x26, 1, &charData, 0x66);
    tiles = charData->tiles;
    MIi_CpuCopyFast(tiles + 0x100, p->view->blankTile[0], 0x20);
    MIi_CpuCopyFast(tiles + 0x100, p->view->blankTile[1], 0x20);
    func_020307B0(buf);
    ARC_TOOL_DeleteHandle(handle);
}

void MB_SEQ_LoadMiscGraphics(struct MailBoxProc *p)
{
    func_0201F5BC(0,994,13,0,102);
    func_02049B40(23,5,0,448,32,102);
    func_02049B40(23,5,4,480,32,102);
    func_02049B40(23,5,0,480,32,102);
}

void MB_SEQ_CreateFrames(struct MailBoxProc *p)
{
    u32 i;
    void *first;
    p->view->frames = BGWINFRM_Create(2,11,102);
    for(i=0;i<10;i++) BGWINFRM_AddFrame(p->view->frames,i,2,14,4);
    BGWINFRM_AddFrame(p->view->frames,10,1,14,4);
    BGWINFRM_SetFrameDataArc(p->view->frames,0,155,40,1);
    first = BGWINFRM_GetFrameBuffer(p->view->frames,0);
    for(i=1;i<=10;i++) MI_CpuCopy8(first,BGWINFRM_GetFrameBuffer(p->view->frames,i),112);
    for(i=0;i<10;i++) BGWINFRM_PutFrame(p->view->frames,i,(i%2)*16+1,(i/2)*4);
}

void MB_SEQ_DeleteFrames(struct MailBoxProc *p)
{
    BGWINFRM_Delete(p->view->frames);
}

void MB_SEQ_CreateMessageResources(struct MailBoxView *view)
{
    view->msgData = func_02045B38(0, 2, 0x3b, 0x66);
    view->wordSet = GF_FONT_Create_EC64(0x66);
    view->msgBuf = STRBUF_Create(0x400, 0x66);
}

void MB_SEQ_DeleteMessageResources(struct MailBoxView *view)
{
    STRBUF_Delete(view->msgBuf);
    WORDSET_DeleteStrbufED04(view->wordSet);
    MSGDATA_Delete(view->msgData);
}

void MB_SEQ_OpenTwoEntryMenu(struct MailBoxProc *p)
{
    struct MailMenuTemplate t;
    t.heapId = 102;
    t.count = 2;
    t.items = p->view->twoEntry;
    t.zero = 0;
    t.x = 21;
    t.y = 8;
    t.w = 10;
    t.h = 3;
    p->view->taskMenu = APP_TASKMENU_OpenMenu(&t, p->view->taskMenuRes);
}

/*
 * lever: use the prepared Pair pointer's t->a as the archive index and t->b after the call;
 *   its live address keeps r7 and frees the far-offset constants into the original stack slots.
 * retry: wave77 R24 recovered in 3 scratch runs; own callee prototypes copied before matching.
 */
void MB_SEQ_CreateMenuEntries(struct MailBoxProc *p)
{
    u16 i;
    const struct MailBoxMenuDef *t;
    p->view->taskMenuRes = APP_TASKMENU_RES_Create(0, 5, p->font, p->view->printQue, 0x66);
    for (i = 0; i < 4; i++) {
        t = &g_78C0[i];
        p->view->fourEntry[i].text = func_02045EC0(p->view->msgData, t->messageId);
        p->view->fourEntry[i].color = 0x39E3;
        p->view->fourEntry[i].selected = t->value;
    }
    for (i = 0; i < 2; i++) {
        t = &g_78B0[i];
        p->view->twoEntry[i].text = func_02045EC0(p->view->msgData, t->messageId);
        p->view->twoEntry[i].color = 0x39E3;
        p->view->twoEntry[i].selected = t->value;
    }
}

void MB_SEQ_DeleteMenuEntries(struct MailBoxProc *p)
{
    int i;
    for (i = 0; i < 4; i++)
        STRBUF_Delete(p->view->fourEntry[i].text);
    STRBUF_Delete(p->view->twoEntry[0].text);
    STRBUF_Delete(p->view->twoEntry[1].text);
    APP_TASKMENU_RES_Delete(p->view->taskMenuRes);
}

void MB_SEQ_OpenFourEntryMenu(struct MailBoxProc *p)
{
    struct MailMenuTemplate t;
    t.heapId = 102;
    t.count = 4;
    t.items = p->view->fourEntry;
    t.zero = 0;
    t.x = 20;
    t.y = 12;
    t.w = 12;
    t.h = 3;
    p->view->taskMenu = APP_TASKMENU_OpenMenu(&t, p->view->taskMenuRes);
}

void MB_SEQ_CloseMenu(struct MailBoxProc *p)
{
    APP_TASKMENU_CloseMenu(p->view->taskMenu);
}

extern struct Mail *func_02009050(struct MailData *mailData, u32 unused, int index, u32 heapId);

extern int func_02008EF8(const struct Mail *mail);

extern void BGWINFRM_HideFrame(struct BgWinFrm *mgr, u32 idx);

extern void BGWINFRM_ShowFrame(struct BgWinFrm *mgr, u32 idx);

extern void CLACT_SetActorPaletteOffset(struct ClactActor *actor, u32 v, u32 flag);

extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

extern u32 func_0201D304(struct Strbuf *text, struct GfFont *font, u32 spacing);

extern struct Bmp *BMP_CreateFromBuffer(void *pixels, u32 width, u32 height, u32 depth, u16 heap);

extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);

extern u8 func_02008F9C(const struct Mail *mail);

extern void BGWINFRM_PutBmpWin(struct BgWinFrm *mgr, u32 idx, struct BmpWin *win);

extern void BMP_Delete(struct Bmp *bmp);

extern void func_0201EE0C(struct WordSet *wordSet, u32 i, struct Strbuf *src, u32 n, u32 f, u32 c);

extern void func_0201F250(struct WordSet *wordSet, struct Strbuf *dst, struct Strbuf *src);

extern void func_0201F73C(void *a0, int a1, int a2, int a3);

extern void CLACT_SetActorAutoAnim(struct ClactActor *actor, u32 v);

extern void CLACT_DrawSystem(struct ClactUnit *unit);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void CLACT_ReleasePalette(u32 i);

extern struct ClactActor *CLACT_CreateActor(struct ClactUnit *unit, u32 i, u32 j, u32 k, const struct ClactActorParam *param, u16 space, u16 heap);

extern void CLACT_DeleteActor(struct ClactActor *actor);

extern void CLACT_SetActorAnimSeq(struct ClactActor *actor, u16 value);

extern void CLACT_SetActorDrawEnable(struct ClactActor *actor, u32 v);

extern void CLACT_AddActorSurfacePos(struct ClactActor *actor, const struct ClactPos *delta, unsigned int which);

extern void CLACT_SetActorAnimFrame(struct ClactActor *actor, u32 value);

extern void CLACT_SetActorObjMode(struct ClactActor *actor, u32 value);

extern u32 func_020275E4(void);

extern u32 func_02027698(void);

extern int CLACT_RegisterCharacter(void *, u32, u32, u32, u16);

extern int func_0201BC3C(void);

extern int CLACT_RegisterPalette(void *, u32, u32, u32, u16);

extern u32 func_0202769C(u32);

extern u32 func_020276A0(u32);

extern int CLACT_RegisterCellAnim(void *, u32, u32, u32);

extern u32 func_02027618(void);

extern u32 func_02027614(void);

extern u32 func_0202761C(u32);

extern u32 func_02027620(u32);

extern void BGWINFRM_UpdateMoves(struct BgWinFrm *mgr);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQue *p, void *v);

void MB_SEQ_CollectMails(struct MailBoxProc *p);

void MB_SEQ_FreeMails(struct MailBoxProc *p);

void MB_SEQ_DrawPage(struct MailBoxProc *p);

void MB_SEQ_DrawSelectedMail(struct MailBoxProc *p);

int MB_SEQ_StepSelectFlash(struct MailBoxProc *p);

void MB_SEQ_LoadSelectedMailGraphics(struct MailBoxProc *p);

void MB_SEQ_CreatePmsDraw(struct MailBoxProc *p);

void MB_SEQ_DeletePmsDraw(struct MailBoxProc *p);

void MB_SEQ_CreateWindows(struct MailBoxProc *p);

void MB_SEQ_DeleteWindows(struct MailBoxProc *p);

void MB_SEQ_PrintTextToSlot(struct BmpWin *unused, struct Strbuf *text, struct MailWinSlot *slot, struct PrintQue *printQue, int x, int y, struct GfFont *font, u16 color, int align);

void MB_SEQ_PrintMessageToSlot(struct MailBoxView *view, struct MsgData *msgData, int i, u32 message, int x, int y, struct GfFont *font, u16 color, int align);

void MB_SEQ_DrawMailEntry(struct MailBoxProc *p, u32 frameIndex, int winIndex, int mailIndex);

void MB_SEQ_DrawTitle(struct MailBoxProc *p);

void MB_SEQ_EmptyHookDetailClose(struct MailBoxView *view);

void MB_SEQ_EmptyHookDetailReturn(struct MailBoxView *view);

void MB_SEQ_SetWriterWord(struct MailBoxProc *p, u32 a1);

void MB_SEQ_StartMessagePrint(struct MailBoxProc *p);

void MB_SEQ_PrintDetailMessage(struct MailBoxProc *p);

void MB_SEQ_ShowMessageWindow(struct MailBoxProc *p);

void MB_SEQ_HideMessageWindow(struct MailBoxProc *p);

void MB_SEQ_PrintMenuMessage(struct MailBoxProc *p, unsigned int i);

void MB_SEQ_DrawMailDetail(struct MailBoxProc *p);

void MB_SEQ_CreateActors(struct MailBoxProc *p);

void MB_SEQ_DeleteActors(struct MailBoxProc *p);

void MB_SEQ_DrawActors(struct MailBoxView *view);

void MB_SEQ_InitActorSystem(struct MailBoxView *view);

void MB_SEQ_ExitActorSystem(struct MailBoxView *view);

struct ClactActor *MB_SEQ_CreateActor(struct MailBoxView *view, const struct MailBoxActorDef *def);

void MB_SEQ_DeleteActor(struct MailBoxView *view, int i);

void MB_SEQ_DeleteAllActors(struct MailBoxView *view);

void MB_SEQ_SetActorAnim(struct MailBoxView *view, int i, u32 animSeq);

void MB_SEQ_SetActorVisible(struct MailBoxView *view, int i, u32 visible);

void MB_SEQ_SetActorPosition(struct MailBoxView *view, int i, int x, int y);

void MB_SEQ_SetActorObjMode(struct MailBoxView *view, int i, int on);

void MB_SEQ_LoadActorArc(struct MailBoxView *view);

void MB_SEQ_FreeActorArc(struct MailBoxView *view);

void MB_SEQ_RegisterSystemActorResources(struct MailBoxView *view);

void MB_SEQ_RegisterMailActorResources(struct MailBoxView *view);

void MB_SEQ_ShowCursorActor(struct MailBoxView *view);

extern const struct MailBoxWinDef g_7A20[];

extern const struct MailBoxActorDef d_021C7BBC[];

extern const struct Cfg d_021C7BA0;

extern const struct DispVram d_021C78E0;

void MB_SEQ_CollectMails(struct MailBoxProc *p)
{
    unsigned i;
    struct MailBoxView *view;
    p->view->mailCount=0;
    for(i=0;i<20;i++) {
        p->view->listIndex[i]=255;
        p->view->mails[i]=func_02009050(p->mailData,0,i,102);
        if(func_02008EF8(p->view->mails[i])==1) {
            p->view->listIndex[p->view->mailCount]=i;
            ++p->view->mailCount;
        }
    }
    view=p->view;
    if(view->mailCount==0) view->lastPage=0;
    else view->lastPage=(view->mailCount-1)/10;
}

void MB_SEQ_FreeMails(struct MailBoxProc *p)
{
    u32 i;
    for (i = 0; i < 0x14; i++)
        func_020307B0(p->view->mails[i]);
}

void MB_SEQ_DrawPage(struct MailBoxProc *p)
{
    u16 frameIndex;
    u8 *row;
    u16 offset;
    u16 i;
    frameIndex = 0;
    offset = 10 * p->page;
    row = p->view->listIndex+offset;
    offset += 2;
    for (i=0;i<10;i++) {
        if(row[i]==255) BGWINFRM_HideFrame(p->view->frames,frameIndex);
        else {
            MB_SEQ_DrawMailEntry(p,frameIndex,offset,row[i]);
            BGWINFRM_ShowFrame(p->view->frames,frameIndex);
        }
        offset++;
        frameIndex++;
    }
}

void MB_SEQ_DrawSelectedMail(struct MailBoxProc *p)
{
    MB_SEQ_DrawMailEntry(p, 10, 0x16, p->selectedMail);
    BGWINFRM_PutFrame(p->view->frames, 10, 4, 7);
}

int MB_SEQ_StepSelectFlash(struct MailBoxProc *p)
{
    struct MailBoxFlash *flash = &p->view->flash;
    switch (flash->state) {
    case 0:
        if (flash->isWindow == 0) {
            CLACT_SetActorPaletteOffset(p->view->actor[flash->target], flash->paletteFirst, 1);
        } else {
            func_020413B0(flash->target, flash->x, flash->y, flash->w, flash->h, flash->paletteFirst);
            func_02041B6C(flash->target);
        }
        flash->state++;
        break;
    case 1:
        flash->count++;
        if (flash->count == 4) {
            if (flash->isWindow == 0) {
                CLACT_SetActorPaletteOffset(p->view->actor[flash->target], flash->paletteSecond, 1);
            } else {
                func_020413B0(flash->target, flash->x, flash->y, flash->w, flash->h, flash->paletteSecond);
                func_02041B6C(flash->target);
            }
            flash->count = 0;
            flash->state++;
        }
        break;
    case 2:
        flash->count++;
        if (flash->count == 2) {
            return 0;
        }
        break;
    }
    return 1;
}

void MB_SEQ_LoadSelectedMailGraphics(struct MailBoxProc *p)
{
    void *handle;
    u32 designId;
    handle = func_020490F4(155,102);
    designId = func_02008FA4(p->view->mails[p->selectedMail]);
    func_02049658(handle,designId+12,5,0,0,1,102);
    func_02049B68(handle,designId,4,0,64,102);
    func_020498F4(handle,designId+24,5,0,0,1,102);
    ARC_TOOL_DeleteHandle(handle);
}

void MB_SEQ_CreatePmsDraw(struct MailBoxProc *p)
{
    p->view->pmsPrintQue = PRINTSYS_QUE_Create(102);
    p->view->pmsClactUnit = CLACT_CreateUnit(8,2,102);
    p->view->pmsDraw = PMS_DRAW_Create(p->view->pmsClactUnit,1,p->view->pmsPrintQue,p->font,4,4,102);
    PMS_DRAW_SetNullColorPalette(p->view->pmsDraw,0);
}

void MB_SEQ_DeletePmsDraw(struct MailBoxProc *p)
{
    PMS_DRAW_Delete(p->view->pmsDraw);
    PRINTSYS_QUE_Delete(p->view->pmsPrintQue);
    CLACT_DeleteUnit(p->view->pmsClactUnit);
}

/*
 * lever: 021C5EE2 branches to 021C5E9A, after the r6=r4 copy at
 *   021C5E98. The first loop stores zero ids, and a new second loop starts
 *   at zero. Literal zero plus separate loops reproduces that shared r6.
 *   The old j=i inside the loop incorrectly started loop two at 31.
 */
void MB_SEQ_CreateWindows(struct MailBoxProc *p)
{
    u32 i;
    u32 j;
    struct MailWinSlot *slot;
    struct BmpWin *win;
    BMP_WIN_Init(0x66);
    p->font = GF_FONT_Create(0x17, 0, 0, 0, 0x66);
    p->view->tcbl = TCBL_Create(0x66, 0x66, 0x20, 0x20);
    p->view->printQue = PRINTSYS_QUE_Create(0x66);
    for (i = 0; i < 0x20; i++) {
        p->view->win[i] = BMP_WIN_Create(g_7A20[i].bg, g_7A20[i].x, g_7A20[i].y, g_7A20[i].w, g_7A20[i].h, g_7A20[i].palette, 1);
        slot = p->view->slot;
        slot[i].win = p->view->win[i];
        slot[i].flag = 0;
    }
    for (j = 0; j < 0x16; j++) {
        BMP_Clear(BMP_WIN_GetBmp(p->view->win[j]), 4);
        BMP_WIN_TransferChars(p->view->win[j]);
    }
    win = p->view->win[0];
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_020409B4(BMP_WIN_GetBgLayer(win));
    win = p->view->win[1];
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_020409B4(BMP_WIN_GetBgLayer(win));
}

void MB_SEQ_DeleteWindows(struct MailBoxProc *p)
{
    u32 i;
    PRINTSYS_QUE_Delete(p->view->printQue);
    TCBL_Destroy(p->view->tcbl);
    for (i = 0; i < 0x20; i++) {
        BMP_WIN_Delete(p->view->win[i]);
    }
    GF_FONT_Delete(p->font);
    BMP_WIN_Exit();
}

void MB_SEQ_PrintTextToSlot(struct BmpWin *unused, struct Strbuf *text, struct MailWinSlot *slot, struct PrintQue *printQue, int x, int y, struct GfFont *font, u16 color, int align)
{
    if (align == 1)
        x -= func_0201D304(text, font, 0);
    else if (align == 2)
        x -= func_0201D304(text, font, 0) >> 1;
    PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(slot->win), x, y, text, font, color);
    slot->flag = 1;
}

void MB_SEQ_PrintMessageToSlot(struct MailBoxView *view, struct MsgData *msgData, int i, u32 message, int x, int y, struct GfFont *font, u16 color, int align)
{
    struct Strbuf *text;
    text = func_02045EC0(msgData, message);
    MB_SEQ_PrintTextToSlot(view->win[i], text, &view->slot[i], view->printQue, x, y, font, color, align);
    STRBUF_Delete(text);
}

void MB_SEQ_DrawMailEntry(struct MailBoxProc *p, u32 frameIndex, int winIndex, int mailIndex)
{
    struct Mail *mail;
    struct Bmp *tile0;
    struct Bmp *tile1;
    struct BmpWin *win;
    struct MailWinSlot *slot;
    u32 i;

    tile0 = BMP_CreateFromBuffer(p->view->blankTile[0], 1, 1, 0x20, 0x66);
    tile1 = BMP_CreateFromBuffer(p->view->blankTile[1], 1, 1, 0x20, 0x66);
    win = p->view->win[winIndex];
    mail = p->view->mails[mailIndex];
    slot = &p->view->slot[winIndex];

    BMP_Clear(tile0, 4);
    BMP_Clear(tile1, 4);
    STRBUF_SetString(p->view->msgBuf, func_02008F84(mail));
    for (i = 0; i < 8; i++) {
        BMP_Blit(BMP_WIN_GetBmp(win), tile0, 0, 0, i * 8, 0, 8, 8, 0xFFFF);
        BMP_Blit(BMP_WIN_GetBmp(win), tile1, 0, 0, i * 8, 8, 8, 8, 0xFFFF);
    }
    BMP_Clear(BMP_WIN_GetBmp(win), 4);
    if (func_02008F9C(mail) == 0) {
        MB_SEQ_PrintTextToSlot(win, p->view->msgBuf, slot,
                      p->view->printQue, 0, 0, p->font, 0x14C4, 0);
    } else {
        MB_SEQ_PrintTextToSlot(win, p->view->msgBuf, slot,
                      p->view->printQue, 0, 0, p->font, 0x1D04, 0);
    }
    BGWINFRM_PutBmpWin(p->view->frames, frameIndex, win);
    BMP_Delete(tile1);
    BMP_Delete(tile0);
}

void MB_SEQ_DrawTitle(struct MailBoxProc *p)
{
    struct BmpWin *win;
    BMP_Clear(BMP_WIN_GetBmp(p->view->win[26]), 0);
    MB_SEQ_PrintMessageToSlot(p->view, p->view->msgData, 26, 0, 52, 0, p->font, 0x440, 2);
    win = p->view->win[26];
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_02041B6C(BMP_WIN_GetBgLayer(win));
}

void MB_SEQ_EmptyHookDetailClose(struct MailBoxView *view)
{
}

void MB_SEQ_EmptyHookDetailReturn(struct MailBoxView *view)
{
}

void MB_SEQ_SetWriterWord(struct MailBoxProc *p, u32 a1)
{
    struct Mail *mail;
    struct Strbuf *text;
    u32 n;
    mail = p->view->mails[p->selectedMail];
    text = STRBUF_Create(16, 102);
    func_02008F84(mail);
    STRBUF_SetString(text, func_02008F84(mail));
    n = func_02008F9C(mail);
    func_0201EE0C(p->view->wordSet, 0, text, n, 1, 2);
    STRBUF_Delete(text);
}

void MB_SEQ_StartMessagePrint(struct MailBoxProc *p)
{
    struct BmpWin *win = p->view->win[25];
    struct Bmp *bmp;
    bmp = BMP_WIN_GetBmp(win);
    BMP_Clear(bmp, 0xf);
    p->view->printStream = PRINTSYS_PrintStream(win, 0, 0, p->view->msgBuf, p->font, MSG_SPEED_GetWait(), p->view->tcbl, 0, 0x66, 0xf);
}

void MB_SEQ_PrintDetailMessage(struct MailBoxProc *p)
{
    struct Strbuf *text;
    MB_SEQ_SetWriterWord(p, 0);
    text = func_02045EC0(p->view->msgData, 9);
    func_0201F250(p->view->wordSet, p->view->msgBuf, text);
    STRBUF_Delete(text);
    MB_SEQ_StartMessagePrint(p);
}

void MB_SEQ_ShowMessageWindow(struct MailBoxProc *p)
{
    struct BmpWin *win;
    func_0201F73C(p->view->win[25], 2, 0x3E2, 0xD);
    win = p->view->win[25];
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_02041B6C(BMP_WIN_GetBgLayer(win));
}

void MB_SEQ_HideMessageWindow(struct MailBoxProc *p)
{
    func_0201F7A8(p->view->win[25], 2);
    func_02041B6C(0);
}

void MB_SEQ_PrintMenuMessage(struct MailBoxProc *p, unsigned int i)
{
    switch (i) {
    case 0: func_02045CAC(p->view->msgData, 10, p->view->msgBuf); break;
    case 1: func_02045CAC(p->view->msgData, 11, p->view->msgBuf); break;
    case 2: func_02045CAC(p->view->msgData, 12, p->view->msgBuf); break;
    case 3: func_02045CAC(p->view->msgData, 13, p->view->msgBuf); break;
    case 4: func_02045CAC(p->view->msgData, 14, p->view->msgBuf); break;
    }
    MB_SEQ_StartMessagePrint(p);
}

/*
 * note (2026-10-02): byte-correct; only PMSI_PARAM_IsEnabled lacks a witness. Witness filed as
 *   src/matched/arm9/PMSI_PARAM_IsEnabled.c (EXACT). Re-verify after its shard exists, then file EXACT.
 */
void MB_SEQ_DrawMailDetail(struct MailBoxProc *p)
{
    u32 i;
    struct PmsData *sentence;
    struct BmpWin *win;

    for (i = 0; i < 3; i++) {
        sentence = func_02008FC8(p->view->mails[p->selectedMail], (u8)i);
        if (PMSI_PARAM_IsEnabled(sentence)) {
            PMS_DRAW_Print(p->view->pmsDraw, p->view->win[i + 27], sentence, (u8)i);
            win = p->view->win[i + 27];
            BMP_WIN_TransferChars(win);
            BMP_WIN_MakeScreen(win);
            func_02041B6C(BMP_WIN_GetBgLayer(win));
        }
    }
    p->view->closingWord.sentenceType = 6;
    p->view->closingWord.sentenceId = 0;
    p->view->closingWord.word[0] = func_02008FC0(p->view->mails[p->selectedMail]);
    if (p->view->closingWord.word[0] != 0) {
        PMS_DRAW_Print(p->view->pmsDraw, p->view->win[30], &p->view->closingWord, 3);
    }
    BMP_Clear(BMP_WIN_GetBmp(p->view->win[31]), 0);
    STRBUF_SetString(p->view->msgBuf, func_02008F84(p->view->mails[p->selectedMail]));
    MB_SEQ_PrintTextToSlot(p->view->win[31], p->view->msgBuf, &p->view->slot[31],
                  p->view->printQue, 0, 2, p->font, 0x440, 0);
    win = p->view->win[31];
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_02041B6C(BMP_WIN_GetBgLayer(win));
}

static inline void setActorAutoAnimOn(struct ClactActor *actor)
{
    Active on = ACTIVE;
    CLACT_SetActorAutoAnim(actor, on);
}

/*
 * lever: named q reloaded after the first tail call; explicit if/else
 *   keeps the zero arm first and joins the one arm with the initial path.
 */
void MB_SEQ_CreateActors(struct MailBoxProc *p)
{
    u32 i;
    int k;
    struct MailBoxView *view;
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    for (i = 0; i < 8; i++) {
        p->view->charRes[i] = 0;
        p->view->paletteRes[i] = 0;
        p->view->cellRes[i] = 0;
    }
    MB_SEQ_LoadActorArc(p->view);
    MB_SEQ_InitActorSystem(p->view);
    MB_SEQ_RegisterMailActorResources(p->view);
    MB_SEQ_RegisterSystemActorResources(p->view);
    for (i = 0; i < 8; i++) {
        p->view->actor[i] = MB_SEQ_CreateActor(p->view, &d_021C7BBC[i]);
        setActorAutoAnimOn(p->view->actor[i]);
    }
    view = p->view;
    if (view->mailCount <= 10) {
        MB_SEQ_SetActorVisible(view, 0, 0);
        view = p->view;
        k = 1;
    } else {
        if (p->page == 0) k = 0;
        else k = 1;
    }
    MB_SEQ_SetActorVisible(view, k, 0);
    MB_SEQ_SetActorVisible(p->view, 4, 0);
    MB_SEQ_SetActorVisible(p->view, 5, 0);
    MB_SEQ_SetActorVisible(p->view, 6, 0);
}

/*
 * Addresses are Black-image addresses.
 */
void MB_SEQ_DeleteActors(struct MailBoxProc *p)
{
    MB_SEQ_DeleteAllActors(p->view);
    MB_SEQ_ExitActorSystem(p->view);
    MB_SEQ_FreeActorArc(p->view);
}

void MB_SEQ_DrawActors(struct MailBoxView *view)
{
    struct ClactUnit *unit = view->clactUnit;
    if (unit != 0) {
        CLACT_DrawSystem(unit);
    }
}

void MB_SEQ_InitActorSystem(struct MailBoxView *view)
{
    struct ClactUnit *unit;

    CLACT_InitSystem(&d_021C7BA0, &d_021C78E0, 0x66);
    unit = CLACT_CreateUnit(8, 0, 0x66);
    view->clactUnit = unit;
    CLACT_SetUnitDefaultRenderer(unit);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void MB_SEQ_ExitActorSystem(struct MailBoxView *view)
{
    CLACT_ReleaseCellAnim(view->paletteRes[0]);
    CLACT_ReleasePalette(view->cellRes[0]);
    CLACT_DeleteUnit(view->clactUnit);
    CLACT_ExitSystem();
}

/*
 * lever: const descriptor input preserves load and stack-store scheduling.
 */
struct ClactActor *MB_SEQ_CreateActor(struct MailBoxView *view, const struct MailBoxActorDef *def)
{
    struct ClactActorParam param;
    param.x = def->x;
    param.y = def->y;
    param.value = def->value;
    param.flag = 0;
    param.mode = def->mode;
    return CLACT_CreateActor(view->clactUnit, view->charRes[def->charIndex], view->paletteRes[def->paletteIndex], view->cellRes[def->cellIndex], &param, def->space, 102);
}

void MB_SEQ_DeleteActor(struct MailBoxView *view, int i)
{
    if (view->actor[i]) {
        CLACT_DeleteActor(view->actor[i]);
        view->actor[i] = 0;
    }
}

void MB_SEQ_DeleteAllActors(struct MailBoxView *view)
{
    u32 i;
    for (i = 0; i < 8; i++)
        MB_SEQ_DeleteActor(view, i);
}

void MB_SEQ_SetActorAnim(struct MailBoxView *view, int i, u32 animSeq)
{
    CLACT_SetActorAnimSeq(view->actor[i], (u16)animSeq);
}

void MB_SEQ_SetActorVisible(struct MailBoxView *view, int i, u32 visible)
{
    CLACT_SetActorDrawEnable(view->actor[i], visible);
}

void MB_SEQ_SetActorPosition(struct MailBoxView *view, int i, int x, int y)
{
    struct ClactPos pos;
    pos.x = x;
    pos.y = y;
    if (y < 256)
        CLACT_AddActorSurfacePos(view->actor[i], &pos, 0);
    else
        CLACT_AddActorSurfacePos(view->actor[i], &pos, 1);
    CLACT_SetActorAnimFrame(view->actor[i], 0);
}

void MB_SEQ_SetActorObjMode(struct MailBoxView *view, int i, int on)
{
    if (on == 1) {
        CLACT_SetActorObjMode(view->actor[i], 1);
    } else {
        CLACT_SetActorObjMode(view->actor[i], 0);
    }
}

void MB_SEQ_LoadActorArc(struct MailBoxView *view)
{
    view->arcHandle = func_020490F4(7, 0x66);
}

void MB_SEQ_FreeActorArc(struct MailBoxView *view)
{
    ARC_TOOL_DeleteHandle(view->arcHandle);
}

void MB_SEQ_RegisterSystemActorResources(struct MailBoxView *view)
{
    void *arc;
    u32 i;
    u32 first;
    arc = func_020490F4(func_020275E4(), 102);
    for (i = 0; i <= 2; i++)
        view->charRes[i] = CLACT_RegisterCharacter(arc, func_02027698(), 0, 1, 102);
    view->paletteRes[0] = CLACT_RegisterPalette(arc, func_0201BC3C(), 1, 0, 102);
    first = func_0202769C(0);
    view->cellRes[0] = CLACT_RegisterCellAnim(arc, first, func_020276A0(0), 102);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * extent: 021C6882 halfword is alignment padding.
 */
void MB_SEQ_RegisterMailActorResources(struct MailBoxView *view)
{
    void *arc;
    u32 first;
    arc = func_020490F4(155, 102);
    view->charRes[3] = CLACT_RegisterCharacter(arc, 44, 1, 0, 102);
    view->paletteRes[1] = CLACT_RegisterPalette(arc, 47, 0, 0, 102);
    view->cellRes[1] = CLACT_RegisterCellAnim(arc, 45, 46, 102);
    ARC_TOOL_DeleteHandle(arc);
    arc = func_020490F4(func_020275E4(), 102);
    view->charRes[4] = CLACT_RegisterCharacter(arc, func_02027618(), 0, 0, 102);
    view->paletteRes[2] = CLACT_RegisterPalette(arc, func_02027614(), 0, 128, 102);
    first = func_0202761C(0);
    view->cellRes[2] = CLACT_RegisterCellAnim(arc, first, func_02027620(0), 102);
    ARC_TOOL_DeleteHandle(arc);
}

void MB_SEQ_ShowCursorActor(struct MailBoxView *view)
{
    MB_SEQ_SetActorPosition(view, 2, 0xE0, 0xB0);
    MB_SEQ_SetActorAnim(view, 2, 4);
}

extern int (*const d_021C7DA8[])(struct MailBoxProc *);

int MB_SEQ_Update(struct MailBoxProc *p, int *state)
{
    int i;
    int j;
    *state = d_021C7DA8[*state](p);
    if (*state == 0x1B) {
        return 0;
    }
    if (p->view != 0) {
        BGWINFRM_UpdateMoves(p->view->frames);
        MB_SEQ_DrawActors(p->view);
        if (p->view->printQue != 0) {
            PRINTSYS_QUE_Main(p->view->printQue);
            for (i = 0; i < 0x1B; i++) {
                struct PrintQue *queue = p->view->printQue;
                struct MailWinSlot *slot = &p->view->slot[i];
                if (slot->flag != 0) {
                    if (PRINTSYS_QUE_IsExistTarget(queue, BMP_WIN_GetBmp(slot->win)) == 0) {
                        BMP_WIN_TransferChars(slot->win);
                        slot->flag = 0;
                    }
                }
            }
        }
        if (p->view->tcbl != 0) {
            TCBL_Main(p->view->tcbl);
        }
        if (p->view->pmsPrintQue != 0) {
            PMS_DRAW_Main(p->view->pmsDraw);
            PRINTSYS_QUE_Main(p->view->pmsPrintQue);
            for (j = 0x1B; j < 0x20; j++) {
                struct PrintQue *queue = p->view->printQue;
                struct MailWinSlot *slot = &p->view->slot[j];
                if (slot->flag != 0) {
                    if (PRINTSYS_QUE_IsExistTarget(queue, BMP_WIN_GetBmp(slot->win)) == 0) {
                        BMP_WIN_TransferChars(slot->win);
                        slot->flag = 0;
                    }
                }
            }
        }
    }
    return 1;
}

extern void BG_SYS_SetMainVisiblePlanes(u32);

extern void BG_SYS_SetSubVisiblePlanes(u32);

extern void BG_SYS_SetLcdSwap(u32);

extern void *func_020056A0(void (*)(void *), void *, u32);

extern u32 WIPE_SYS_EndCheck(void);

extern void GFL_USE_PlaySeDefaultVolume(u32);

extern void APP_TASKMENU_UpdateMenu(struct AppTaskMenu *menu);

extern u8 APP_TASKMENU_GetCursorPos(const struct AppTaskMenu *menu);

extern unsigned int PROCSYS_Main(void *p);

extern u32 PRINTSYS_QUE_IsFinished(const struct PrintQue *p);

extern int CURSOR_MOVE_PollRepeatInput(struct TouchSelect *select);

extern u8 CURSOR_MOVE_GetCurrent(struct TouchSelect *select);

int MB_SEQ_IsXPressed(void);

extern u16 func_020213AC(u32);

extern u32 CLACT_IsActorAnimActive(struct ClactActor *actor);

extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

extern void BGWINFRM_GetPos(struct BgWinFrm *mgr, u32 idx, s8 *x, s8 *y);

extern void BGWINFRM_GetSize(struct BgWinFrm *mgr, u32 idx, u16 *w, u16 *h);

extern void PMS_DRAW_Clear(struct PmsDraw *draw, int index, u32 a1);

extern void *GAME_DATA_GetMyItem(struct GameData *gameData);

extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);

extern void func_0200902C(struct MailData *mailData, u32 unused, int index);

extern void *GAME_DATA_GetMyParty(struct GameData *gameData);

extern void *ZUKAN_SAVE_GetFromGameData(struct GameData *gameData);

extern void PROCSYS_Push(void *, u32, const void *, void *);

extern u8 func_0202138C(u16 v);

extern struct MailArgs *MAILTOOL_CreateWriteArgs(struct GameData *gameData, unsigned b, unsigned c, unsigned d, unsigned heap);

extern u32 MAILTOOL_HasMail(struct MailArgs *args);

extern int MAILTOOL_StoreMailToPartyMon(struct MailArgs *args, void *mon);

extern void MAILTOOL_DeleteArgs(struct MailArgs *args);

extern void *POKEPARTY_GetMember(void *, u32);

extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);

extern int TOUCHPANEL_HitTrg(const void *);

extern struct TouchSelect *CURSOR_MOVE_Create(const struct TouchRect *rects, const u8 *keyTable, void *owner, u32 a3, u8 a4, u16 heapId);

extern u32 CURSOR_MOVE_Delete(struct TouchSelect *select);

extern u8 *CURSOR_MOVE_GetEntry(struct TouchSelect *select, u32 index);

int MB_SEQ_StateInit(struct MailBoxProc *p);

u32 MB_SEQ_StateExit(struct MailBoxProc *p);

int MB_SEQ_StateFadeWait(struct MailBoxProc *p);

u32 MB_SEQ_StateMessageWait(struct MailBoxProc *p);

int MB_SEQ_StateConfirmMenu(struct MailBoxProc *p);

int MB_SEQ_StateFlashWait(struct MailBoxProc *p);

int MB_SEQ_StateStartChild(struct MailBoxProc *p);

int MB_SEQ_StateChildWait(struct MailBoxProc *p);

int MB_SEQ_StateFadeInToList(struct MailBoxProc *p);

int MB_SEQ_StateList(struct MailBoxProc *p);

int MB_SEQ_StateLeave(struct MailBoxProc *p);

int MB_SEQ_StateRedrawPage(struct MailBoxProc *p);

void MB_SEQ_ShowMailDetail(struct MailBoxProc *p);

int MB_SEQ_StateOpenActionMenu(struct MailBoxProc *p);

int MB_SEQ_StateActionMenu(struct MailBoxProc *p);

int MB_SEQ_StateDetail(struct MailBoxProc *p);

int MB_SEQ_CloseMailDetail(struct MailBoxProc *p);

int MB_SEQ_OpenConfirmMenuKind0(struct MailBoxProc *p);

void MB_SEQ_ShowMessage2(struct MailBoxProc *p);

int MB_SEQ_OpenConfirmMenuKind1(struct MailBoxProc *p);

int MB_SEQ_FinishPartyListChoice(struct MailBoxProc *p);

void MB_SEQ_BeginReturnFade(struct MailBoxProc *p);

void MB_SEQ_ShowBagResultMessage(struct MailBoxProc *p);

int MB_SEQ_StartPartyListForReturn(struct MailBoxProc *p);

int MB_SEQ_StateBackButtonDone(struct MailBoxProc *p);

int MB_SEQ_StateCloseButtonDone(struct MailBoxProc *p);

int MB_SEQ_CancelDetail(struct MailBoxProc *p);

int MB_SEQ_StartFadeIn(struct MailBoxProc *p, u32 fadeTarget);

int MB_SEQ_StartFadeOut(struct MailBoxProc *p, u32 fadeTarget);

int MB_SEQ_SetMessageWait(struct MailBoxProc *p, int waitForInput, int nextState);

int MB_SEQ_OpenMenuKind(struct MailBoxProc *p, int menuKind);

int MB_SEQ_StartMailFlash(struct MailBoxProc *p, int frameIndex, int nextState);

int MB_SEQ_StartArrowFlash(struct MailBoxProc *p, int actorIndex, int nextState);

void MB_SEQ_SetButtonsEnabled(struct MailBoxView *view, int on);

void MB_SEQ_SetDetailButtons(struct MailBoxView *view);

void MB_SEQ_LoadMailDetail(struct MailBoxProc *p);

void MB_SEQ_ClearMailDetailText(struct MailBoxProc *p);

void MB_SEQ_CheckBagForItem(struct MailBoxProc *p);

void MB_SEQ_DeleteSelectedMail(struct MailBoxProc *p);

void MB_SEQ_CreatePartyListArgs(struct MailBoxProc *p, int mode, u16 itemId, u16 mailSlot);

int MB_SEQ_PushPartyList(struct MailBoxProc *p);

int MB_SEQ_FinishChildFreeA(struct MailBoxProc *p);

int MB_SEQ_FinishPartyList(struct MailBoxProc *p);

int MB_SEQ_FinishChildFreeB(struct MailBoxProc *p);

int MB_SEQ_PushMailTool(struct MailBoxProc *p);

int MB_SEQ_FinishMailTool(struct MailBoxProc *p);

void MB_SEQ_ReloadMailList(struct MailBoxProc *p);

int MB_SEQ_StartPartyListToTake(struct MailBoxProc *p);

void MB_SEQ_ShowItemMessage(struct MailBoxProc *p);

int MB_SEQ_GetPageButtonHit(struct MailBoxProc *p);

void MB_SEQ_CreateTouchSelect(struct MailBoxProc *p);

void MB_SEQ_DeleteTouchSelect(struct MailBoxProc *p);

void MB_SEQ_EmptyStubA(void);

void MB_SEQ_EmptyStubB(void);

void MB_SEQ_MoveCursorA(struct MailBoxProc *p, u32 position);

void MB_SEQ_MoveCursorB(struct MailBoxProc *p, u32 position);

void MB_SEQ_MoveCursorToPosition(struct MailBoxProc *p, u32 position);

int MB_SEQ_IsConfirmPressed(struct MailBoxProc *p);

extern const char d_021C7F04[];

extern const struct MailBoxMenuHandlers d_021C7D68[];

extern const struct MailBoxChildStart d_021C7D78[];

extern const struct MailBoxChildFinish d_021C7D7C[];

extern const struct ProcData gPartyListProcData;

extern u8 ov091_id[];

extern const struct ProcData d_021C7D5C;

extern const struct TouchRect d_021C7E2C[];

extern const struct TouchRect d_021C7E40[];
extern const u8 d_021C7E1C[];

extern const struct TouchRect d_021C7E14[];

int MB_SEQ_StateInit(struct MailBoxProc *p)
{
    if (p->vblankTask != 0) {
        func_02030EAC(p->vblankTask);
        p->vblankTask = 0;
    }
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetLcdSwap(0);
    GFL_HEAP_CreateChildHeap(1, 0x66, 0x60000);
    p->view = func_02030734(0x66, 0x370, 0, d_021C7F04, 0x10C);
    MIi_CpuClearFast(0, p->view, 0x370);
    MB_SEQ_CollectMails(p);
    MB_SEQ_SetVramBanks();
    MB_SEQ_InitBgs(p);
    MB_SEQ_LoadFrameCharData(p);
    MB_SEQ_LoadMiscGraphics(p);
    MB_SEQ_CreateWindows(p);
    MB_SEQ_CreateFrames(p);
    MB_SEQ_CreateActors(p);
    MB_SEQ_CreatePmsDraw(p);
    MB_SEQ_CreateTouchSelect(p);
    MB_SEQ_CreateMessageResources(p->view);
    MB_SEQ_DrawTitle(p);
    MB_SEQ_DrawPage(p);
    MB_SEQ_CreateMenuEntries(p);
    p->vblankTask = func_020056A0(MB_SEQ_VBlankTask, p, 1);
    GFL_NET_RestartWithDefaultTimeout(0, 0x66);
    return p->nextState;
}

u32 MB_SEQ_StateExit(struct MailBoxProc *p)
{
    if (p->vblankTask != 0) {
        func_02030EAC(p->vblankTask);
        p->vblankTask = 0;
    }
    MB_SEQ_DeleteMenuEntries(p);
    MB_SEQ_DeleteMessageResources(p->view);
    MB_SEQ_DeleteTouchSelect(p);
    MB_SEQ_DeletePmsDraw(p);
    MB_SEQ_DeleteActors(p);
    MB_SEQ_DeleteFrames(p);
    MB_SEQ_DeleteWindows(p);
    MB_SEQ_FreeBgs(p);
    MB_SEQ_FreeMails(p);
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    func_020307B0(p->view);
    p->view = 0;
    func_020306F0(102);
    return p->nextState;
}

/*
 * Addresses are Black-image addresses.
 */
int MB_SEQ_StateFadeWait(struct MailBoxProc *p)
{
    if (WIPE_SYS_EndCheck() == 1)
        return p->view->fadeTarget;
    return 2;
}

u32 MB_SEQ_StateMessageWait(struct MailBoxProc *p)
{
    if (PRINTSYS_PrintStreamGetState(p->view->printStream) == 2) {
        if (p->view->waitForInput == 0) {
            PRINTSYS_PrintStreamDelete(p->view->printStream);
            return p->nextState;
        }
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0) {
            PRINTSYS_PrintStreamDelete(p->view->printStream);
            GFL_USE_PlaySeDefaultVolume(1352);
            return p->nextState;
        }
    }
    return 3;
}

int MB_SEQ_StateConfirmMenu(struct MailBoxProc *p)
{
    APP_TASKMENU_UpdateMenu(p->view->taskMenu);
    if (APP_TASKMENU_IsFinish(p->view->taskMenu) == 0) return 4;
    switch (APP_TASKMENU_GetCursorPos(p->view->taskMenu)) {
    case 0:
        APP_TASKMENU_CloseMenu(p->view->taskMenu);
        return d_021C7D68[p->view->menuKind].onFirst(p);
    case 1:
        APP_TASKMENU_CloseMenu(p->view->taskMenu);
        return d_021C7D68[p->view->menuKind].onSecond(p);
    }
    return 4;
}

int MB_SEQ_StateFlashWait(struct MailBoxProc *p)
{
    if (MB_SEQ_StepSelectFlash(p) == 0)
        return p->nextState;
    return 5;
}

int MB_SEQ_StateStartChild(struct MailBoxProc *p)
{
    d_021C7D78[p->childIndex].start(p);
    return 7;
}

int MB_SEQ_StateChildWait(struct MailBoxProc *p)
{
    if (PROCSYS_Main(p->procSys) == 1) return 7;
    p->nextState = d_021C7D7C[p->childIndex].onFinish(p);
    return d_021C7D7C[p->childIndex].result;
}

int MB_SEQ_StateFadeInToList(struct MailBoxProc *p)
{
    return MB_SEQ_StartFadeIn(p, 9);
}

int MB_SEQ_StateList(struct MailBoxProc *p)
{
    u32 hit;
    u8 *entry;

    if (PRINTSYS_QUE_IsFinished(p->view->printQue) == 0) {
        return 9;
    }
    switch (MB_SEQ_GetPageButtonHit(p)) {
    case 0:
        if (p->page != 0) {
            p->page -= 1;
            GFL_USE_PlaySeDefaultVolume(0x548);
            return MB_SEQ_StartArrowFlash(p, 0, 0xB);
        }
        return 9;
    case 1:
        if (p->page != p->view->lastPage) {
            p->page += 1;
            GFL_USE_PlaySeDefaultVolume(0x548);
            return MB_SEQ_StartArrowFlash(p, 1, 0xB);
        }
        return 9;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        MB_SEQ_SetActorAnim(p->view, 3, 9);
        p->nextState = 10;
        return 0x18;
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x556);
        MB_SEQ_SetActorAnim(p->view, 7, 8);
        p->nextState = 10;
        return 0x19;
    }
    hit = CURSOR_MOVE_PollRepeatInput(p->view->select);
    switch (hit) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        entry = (u8 *)p->view + hit + p->page * 10;
        if (entry[MAILBOXVIEW_LISTINDEX] == 0xFF) {
            break;
        }
        p->selectedColumn = hit;
        p->selectedMail = entry[MAILBOXVIEW_LISTINDEX];
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return MB_SEQ_StartMailFlash(p, hit, 0xC);
    case (u32)-2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        MB_SEQ_SetActorAnim(p->view, 3, 9);
        p->nextState = 10;
        return 0x18;
    case (u32)-5:
        CURSOR_MOVE_GetCurrent(p->view->select);
        if (p->page != p->view->lastPage) {
            p->page += 1;
            GFL_USE_PlaySeDefaultVolume(0x548);
            return MB_SEQ_StartArrowFlash(p, 1, 0xB);
        }
        break;
    case (u32)-6:
        CURSOR_MOVE_GetCurrent(p->view->select);
        if (p->page != 0) {
            p->page -= 1;
            GFL_USE_PlaySeDefaultVolume(0x548);
            return MB_SEQ_StartArrowFlash(p, 0, 0xB);
        }
        break;
    case (u32)-3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case (u32)-4:
        break;
    default:
        if (MB_SEQ_IsXPressed()) {
            GFL_USE_PlaySeDefaultVolume(0x556);
            MB_SEQ_SetActorAnim(p->view, 7, 8);
            p->nextState = 10;
            return 0x19;
        }
        break;
    }
    return 9;
}

int MB_SEQ_StateLeave(struct MailBoxProc *p)
{
    p->nextState = 0x1b;
    return MB_SEQ_StartFadeOut(p, 1);
}

int MB_SEQ_StateRedrawPage(struct MailBoxProc *p)
{
    if (p->page == 0) {
        MB_SEQ_SetActorVisible(p->view, 0, 0);
        MB_SEQ_SetActorVisible(p->view, 1, 1);
    } else {
        MB_SEQ_SetActorVisible(p->view, 0, 1);
        MB_SEQ_SetActorVisible(p->view, 1, 0);
    }
    MB_SEQ_DrawPage(p);
    return 9;
}

void MB_SEQ_ShowMailDetail(struct MailBoxProc *p)
{
    MB_SEQ_SetActorVisible(p->view, 2, 0);
    MB_SEQ_SetButtonsEnabled(p->view, 1);
    MB_SEQ_DrawSelectedMail(p);
    MB_SEQ_ShowMessageWindow(p);
    MB_SEQ_PrintDetailMessage(p);
    MB_SEQ_SetMessageWait(p, 0, 0xD);
}

int MB_SEQ_StateOpenActionMenu(struct MailBoxProc *p)
{
    MB_SEQ_OpenFourEntryMenu(p);
    return 0xE;
}

int MB_SEQ_StateActionMenu(struct MailBoxProc *p)
{
    APP_TASKMENU_UpdateMenu(p->view->taskMenu);
    if (APP_TASKMENU_IsFinish(p->view->taskMenu) == 0) {
        return 0xE;
    }
    switch (APP_TASKMENU_GetCursorPos(p->view->taskMenu)) {
    case 0:
        MB_SEQ_CloseMenu(p);
        MB_SEQ_HideMessageWindow(p);
        MB_SEQ_SetActorVisible(p->view, 2, 0);
        MB_SEQ_EmptyHookDetailClose(p->view);
        MB_SEQ_ShowCursorActor(p->view);
        MB_SEQ_LoadMailDetail(p);
        MB_SEQ_SetActorAnim(p->view, 7, 0xE);
        MB_SEQ_SetDetailButtons(p->view);
        return 0xF;
    case 1:
        MB_SEQ_CloseMenu(p);
        MB_SEQ_PrintMenuMessage(p, 0);
        return MB_SEQ_SetMessageWait(p, 0, 0x11);
    case 2: {
        u8 mailIndex;
        MB_SEQ_CloseMenu(p);
        mailIndex = p->selectedMail;
        MB_SEQ_CreatePartyListArgs(p, 0xE, func_020213AC(func_02008FA4(p->view->mails[mailIndex])), mailIndex);
        p->childIndex = 0;
        p->nextState = 6;
        return MB_SEQ_StartFadeOut(p, 1);
    }
    case -2:
    case 3:
        MB_SEQ_CloseMenu(p);
        MB_SEQ_HideMessageWindow(p);
        BGWINFRM_HideFrame(p->view->frames, 10);
        MB_SEQ_SetButtonsEnabled(p->view, 0);
        MB_SEQ_SetActorVisible(p->view, 2, 1);
        return 9;
    default:
        return 0xE;
    }
}

int MB_SEQ_StateDetail(struct MailBoxProc *p)
{
    if (MB_SEQ_IsConfirmPressed(p) == 1) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        MB_SEQ_SetActorAnim(p->view, 3, 9);
        p->nextState = 0x10;
        return 0x18;
    }
    return 0xF;
}

int MB_SEQ_CloseMailDetail(struct MailBoxProc *p)
{
    MB_SEQ_ClearMailDetailText(p);
    MB_SEQ_MoveCursorToPosition(p, CURSOR_MOVE_GetCurrent(p->view->select));
    MB_SEQ_EmptyHookDetailReturn(p->view);
    BGWINFRM_HideFrame(p->view->frames, 10);
    MB_SEQ_SetActorVisible(p->view, 2, 1);
    MB_SEQ_SetButtonsEnabled(p->view, 0);
    return 9;
}

int MB_SEQ_OpenConfirmMenuKind0(struct MailBoxProc *p)
{
    return MB_SEQ_OpenMenuKind(p, 0);
}

/*
 * extent: stops before separately filed leaf MB_SEQ_FinishPartyListChoice.
 */
void MB_SEQ_ShowMessage2(struct MailBoxProc *p)
{
    MB_SEQ_PrintMenuMessage(p, 2);
    MB_SEQ_SetMessageWait(p, 0, 0x13);
}

int MB_SEQ_OpenConfirmMenuKind1(struct MailBoxProc *p)
{
    return MB_SEQ_OpenMenuKind(p, 1);
}

int MB_SEQ_FinishPartyListChoice(struct MailBoxProc *p)
{
    if (p->partyResult != 6) {
        p->nextState = 0x15;
        return 0;
    }
    p->childIndex = 2;
    return 6;
}

void MB_SEQ_BeginReturnFade(struct MailBoxProc *p)
{
    MB_SEQ_SetActorVisible(p->view, 2, 0);
    MB_SEQ_SetButtonsEnabled(p->view, 1);
    MB_SEQ_StartFadeIn(p, 0x16);
}

void MB_SEQ_ShowBagResultMessage(struct MailBoxProc *p)
{
    MB_SEQ_ShowMessageWindow(p);
    MB_SEQ_ShowItemMessage(p);
}

int MB_SEQ_StartPartyListForReturn(struct MailBoxProc *p)
{
    if (p->hasMail == 0) {
        p->nextState = 0x15;
        return 0;
    }
    MB_SEQ_CreatePartyListArgs(p, 0xB, p->itemId, p->partyIndex);
    p->childIndex = 3;
    return 6;
}

int MB_SEQ_StateBackButtonDone(struct MailBoxProc *p)
{
    if (CLACT_IsActorAnimActive(p->view->actor[3]) == 0) {
        p->args->result = 0;
        MB_SEQ_SetActorAnim(p->view, 7, 0);
        return p->nextState;
    }
    return 0x18;
}

int MB_SEQ_StateCloseButtonDone(struct MailBoxProc *p)
{
    if (CLACT_IsActorAnimActive(p->view->actor[7]) == 0) {
        p->args->result = 1;
        return p->nextState;
    }
    return 0x19;
}

int MB_SEQ_CancelDetail(struct MailBoxProc *p)
{
    MB_SEQ_HideMessageWindow(p);
    BGWINFRM_HideFrame(p->view->frames, 10);
    MB_SEQ_MoveCursorToPosition(p, CURSOR_MOVE_GetCurrent(p->view->select));
    MB_SEQ_SetActorVisible(p->view, 2, 1);
    MB_SEQ_SetButtonsEnabled(p->view, 0);
    return 9;
}

int MB_SEQ_StartFadeIn(struct MailBoxProc *p, u32 fadeTarget)
{
    WIPE_SYS_Start((void *)0, 1, 1, 0, 6, 1, 0x66);
    p->view->fadeTarget = fadeTarget;
    return 2;
}

int MB_SEQ_StartFadeOut(struct MailBoxProc *p, u32 fadeTarget)
{
    WIPE_SYS_Start((void *)0, 0, 0, 0, 6, 1, 0x66);
    p->view->fadeTarget = fadeTarget;
    return 2;
}

int MB_SEQ_SetMessageWait(struct MailBoxProc *p, int waitForInput, int nextState)
{
    p->view->waitForInput = waitForInput;
    p->nextState = nextState;
    return 3;
}

int MB_SEQ_OpenMenuKind(struct MailBoxProc *p, int menuKind)
{
    p->view->menuKind = menuKind;
    MB_SEQ_OpenTwoEntryMenu(p);
    return 4;
}

int MB_SEQ_StartMailFlash(struct MailBoxProc *p, int frameIndex, int nextState)
{
    struct FrameRect { s8 y, x; u16 h, w; } frame;
    struct MailBoxFlash *flash;
    BGWINFRM_GetPos(p->view->frames, frameIndex, &frame.x, &frame.y);
    BGWINFRM_GetSize(p->view->frames, frameIndex, &frame.w, &frame.h);
    flash = &p->view->flash;
    flash->isWindow = 1;
    flash->target = 2;
    flash->paletteFirst = 2;
    flash->paletteSecond = 1;
    flash->state = 0;
    flash->count = 0;
    flash->x = frame.x;
    flash->y = frame.y;
    flash->w = frame.w;
    flash->h = frame.h;
    p->nextState = nextState;
    return 5;
}

/*
 * extent: trailing 021C7296 halfword is zero alignment padding.
 */
int MB_SEQ_StartArrowFlash(struct MailBoxProc *p, int actorIndex, int nextState)
{
    struct MailBoxFlash *flash = &p->view->flash;
    flash->isWindow = 0;
    flash->target = (u8)actorIndex;
    flash->paletteFirst = 1;
    flash->paletteSecond = 0;
    flash->state = 0;
    flash->count = 0;
    p->nextState = nextState;
    return 5;
}

/*
 * volatile: hardware register write at 021C7302 (0x04000050).
 */
void MB_SEQ_SetButtonsEnabled(struct MailBoxView *view, int on)
{
    if (on == 1) {
        MB_SEQ_SetActorObjMode(view, 0, 1);
        MB_SEQ_SetActorObjMode(view, 1, 1);
        MB_SEQ_SetActorObjMode(view, 3, 1);
        MB_SEQ_SetActorObjMode(view, 7, 1);
        func_0207D63C((void *)0x04000050, 4, 8, 4, 12);
    } else {
        MB_SEQ_SetActorObjMode(view, 0, 0);
        MB_SEQ_SetActorObjMode(view, 1, 0);
        MB_SEQ_SetActorObjMode(view, 3, 0);
        MB_SEQ_SetActorObjMode(view, 7, 0);
        *(volatile unsigned short *)0x04000050 = 0;
    }
}

void MB_SEQ_SetDetailButtons(struct MailBoxView *view)
{
    MB_SEQ_SetActorObjMode(view, 0, 1);
    MB_SEQ_SetActorObjMode(view, 1, 1);
    MB_SEQ_SetActorObjMode(view, 3, 0);
    MB_SEQ_SetActorObjMode(view, 7, 0);
    func_0207D63C((void *)0x04000050, 4, 8, 4, 12);
}

void MB_SEQ_LoadMailDetail(struct MailBoxProc *p)
{
    MB_SEQ_LoadSelectedMailGraphics(p);
    MB_SEQ_DrawMailDetail(p);
}

/*
 *   2026-10-02: src/matched/arm9/PMSI_PARAM_IsEnabled.c exists (EXACT) but has no shard yet.
 *   After the integrator runs manifest on it, re-run: expect EXACT.
 *   Verified Thumb C is preserved here; ARM9 filing belongs to the integrator.
 *   typedef unsigned short u16;
 *   int PMSI_PARAM_IsEnabled(const u16 *p)
 *   {
 *       if (*p != 0xFFFF) return 1;
 *       return 0;
 *   }
 */
void MB_SEQ_ClearMailDetailText(struct MailBoxProc *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (PMSI_PARAM_IsEnabled(func_02008FC8(p->view->mails[p->selectedMail], (u8)i)) != 0) {
            PMS_DRAW_Clear(p->view->pmsDraw, (u8)i, (int)0);
        }
    }
    if (p->view->closingWord.word[0] != 0) {
        PMS_DRAW_Clear(p->view->pmsDraw, (u8)i, (int)0);
    }
    BG_SYS_ClearSlot(4);
    BG_SYS_ClearSlot(5);
}

/*
 * extent: trailing 021C741E halfword is zero alignment padding.
 */
void MB_SEQ_CheckBagForItem(struct MailBoxProc *p)
{
    void *bag = GAME_DATA_GetMyItem(p->args->gameData);
    p->itemId = func_020213AC(func_02008FA4(p->view->mails[p->selectedMail]));
    if (func_02007E50(bag, p->itemId, 1, 0x66) == 1) {
        p->bagFull = 0;
        return;
    } else {
        p->bagFull = 1;
        return;
    }
}

void MB_SEQ_DeleteSelectedMail(struct MailBoxProc *p)
{
    func_0200902C(p->mailData, 0, p->selectedMail);
}

void MB_SEQ_CreatePartyListArgs(struct MailBoxProc *p, int mode, u16 itemId, u16 mailSlot)
{
    PokelistArg *args = func_02030734(0x65, 0x98, 1, d_021C7F04, 0x529);
    args->party = GAME_DATA_GetMyParty(p->args->gameData);
    args->bag = GAME_DATA_GetMyItem(p->args->gameData);
    args->mailBox = p->mailData;
    *(u32 *)args->pad38 = 0;
    args->mode = mode;
    args->itemId = itemId;
    args->mailSlot = mailSlot;
    args->zukanSave = ZUKAN_SAVE_GetFromGameData(p->args->gameData);
    p->childArgs = args;
}

int MB_SEQ_PushPartyList(struct MailBoxProc *p)
{
    u32 partyIndex = p->partyIndex;
    ((PokelistArg *)p->childArgs)->selectedIndex = partyIndex;
    /* the overlay id is the address of the linker symbol ov091_id */
    PROCSYS_Push(p->procSys, (u32)ov091_id, &gPartyListProcData, p->childArgs);
    return 0;
}

int MB_SEQ_FinishChildFreeA(struct MailBoxProc *p)
{
    func_020307B0(p->childArgs);
    return 8;
}

int MB_SEQ_FinishPartyList(struct MailBoxProc *p)
{
    PokelistArg *args = p->childArgs;
    p->partyIndex = args->selectedIndex;
    p->partyResult = args->exitCode;
    func_020307B0(args);
    return 0;
}

int MB_SEQ_FinishChildFreeB(struct MailBoxProc *p)
{
    func_020307B0(p->childArgs);
    return 8;
}

int MB_SEQ_PushMailTool(struct MailBoxProc *p)
{
    p->childArgs = MAILTOOL_CreateWriteArgs(p->args->gameData, 2, p->partyIndex, func_0202138C(p->itemId), 0x65);
    PROCSYS_Push(p->procSys, (u32)-1, &d_021C7D5C, p->childArgs);
    return 0;
}

/*
 * extent: trailing 021C758A halfword is zero alignment padding.
 */
int MB_SEQ_FinishMailTool(struct MailBoxProc *p)
{
    p->hasMail = MAILTOOL_HasMail(p->childArgs);
    if (p->hasMail == 1) {
        MAILTOOL_StoreMailToPartyMon(p->childArgs, POKEPARTY_GetMember(GAME_DATA_GetMyParty(p->args->gameData), p->partyIndex));
        func_02007F1C(GAME_DATA_GetMyItem(p->args->gameData), p->itemId, 1, 0x65);
    }
    MAILTOOL_DeleteArgs(p->childArgs);
    return 0;
}

/*
 * MB_SEQ_CheckBagForItem 0x021C73C8 thumb ov136
 * MB_SEQ_DeleteSelectedMail 0x021C7420 thumb ov136
 * MB_SEQ_FreeMails 0x021C5BE0 thumb ov136
 * MB_SEQ_CollectMails 0x021C5B40 thumb ov136
 * MB_SEQ_SetActorVisible 0x021C66B8 thumb ov136
 * MB_SEQ_DrawPage 0x021C5C00 thumb ov136
 * MB_SEQ_PrintMenuMessage 0x021C630C thumb ov136
 * MB_SEQ_SetMessageWait 0x021C71A8 thumb ov136
 */
void MB_SEQ_ReloadMailList(struct MailBoxProc *p)
{
    u16 lastPage;
    MB_SEQ_CheckBagForItem(p);
    MB_SEQ_DeleteSelectedMail(p);
    MB_SEQ_FreeMails(p);
    MB_SEQ_CollectMails(p);
    if (p->view->mailCount <= 10) {
        MB_SEQ_SetActorVisible(p->view, 0, 0);
        MB_SEQ_SetActorVisible(p->view, 1, 0);
    }
    lastPage = p->view->lastPage;
    if (p->page > lastPage) {
        p->page = lastPage;
        p->selectedColumn = 0;
    }
    MB_SEQ_DrawPage(p);
    BGWINFRM_HideFrame(p->view->frames, 10);
    MB_SEQ_PrintMenuMessage(p, 1);
    MB_SEQ_SetMessageWait(p, 1, 18);
}

int MB_SEQ_StartPartyListToTake(struct MailBoxProc *p)
{
    MB_SEQ_CreatePartyListArgs(p, 9, p->itemId, 0);
    p->childIndex = 1;
    p->nextState = 6;
    return MB_SEQ_StartFadeOut(p, 1);
}

/*
 * lever: call in each conditional arm keeps p live in r0 and bit test in r1;
 *   inline selector/ternary instead use r0 for test and rebuild p, DIFF17/38.
 * extent: 38 code bytes followed by two zero alignment bytes at021C7646;
 *   next function begins021C7648 outside this inferred40-byte extent.
 */
void MB_SEQ_ShowItemMessage(struct MailBoxProc *p)
{
    if (p->bagFull == 0)
        MB_SEQ_PrintMenuMessage(p, 3);
    else
        MB_SEQ_PrintMenuMessage(p, 4);
    MB_SEQ_SetMessageWait(p, 1, 0x1A);
}

int MB_SEQ_GetPageButtonHit(struct MailBoxProc *p)
{
    return TOUCHPANEL_HitTrg(d_021C7E2C);
}

void MB_SEQ_CreateTouchSelect(struct MailBoxProc *p)
{
    int column;
    u16 lastPage = p->view->lastPage;
    if (p->page > lastPage) {
        p->page = lastPage;
        column = 0;
    } else {
        column = p->selectedColumn;
    }
    p->view->select = CURSOR_MOVE_Create(d_021C7E40, d_021C7E1C, p, 1, column, 102);
    MB_SEQ_MoveCursorToPosition(p, column);
}

void MB_SEQ_DeleteTouchSelect(struct MailBoxProc *p)
{
    CURSOR_MOVE_Delete(p->view->select);
}

void MB_SEQ_EmptyStubA(void)
{
}

void MB_SEQ_EmptyStubB(void)
{
}

void MB_SEQ_MoveCursorA(struct MailBoxProc *p, u32 position)
{
    MB_SEQ_MoveCursorToPosition(p, position);
}

void MB_SEQ_MoveCursorB(struct MailBoxProc *p, u32 position)
{
    MB_SEQ_MoveCursorToPosition(p, position);
}

void MB_SEQ_MoveCursorToPosition(struct MailBoxProc *p, u32 position)
{
    u8 *xy = CURSOR_MOVE_GetEntry(p->view->select, position);
    MB_SEQ_SetActorPosition(p->view, 2, xy[0], xy[1]);
    if (position == 10) {
        MB_SEQ_SetActorAnim(p->view, 2, 4);
    } else {
        MB_SEQ_SetActorAnim(p->view, 2, 5);
    }
}

int MB_SEQ_IsConfirmPressed(struct MailBoxProc *p)
{
    if (TOUCHPANEL_HitTrg(d_021C7E14) != -1) {
        return 1;
    }
    if ((KEY_GetTrg() & 3) != 0) {
        return 1;
    }
    return 0;
}

int MB_SEQ_IsXPressed(void)
{
    return (KEY_GetTrg() & 0x400) ? 1 : 0;
}
