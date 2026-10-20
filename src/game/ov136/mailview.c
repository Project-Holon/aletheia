/*
 * file:     mailview.c
 * unit:     yes
 * function: MAILVIEW_HideAllPlanes, MAILVIEW_VBlankTask, MAILVIEW_CursorBlendTask, MAILVIEW_SetupStep, MAILVIEW_StartCursorBlendTask, MAILVIEW_Teardown, MAILVIEW_CreatePmsDraw, MAILVIEW_DeletePmsDraw, MAILVIEW_SetVramBanks, MAILVIEW_InitBgs, MAILVIEW_FreeBgs, MAILVIEW_LoadGraphics, MAILVIEW_FreeGraphics, MAILVIEW_CreateWindows, MAILVIEW_CreateButtons, MAILVIEW_DeleteWindows, MAILVIEW_PrintSentences, MAILVIEW_InitActorSystem, MAILVIEW_ExitActorSystem
 * address:  0x021C4AF8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mailview.c, mb_seq.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete  0x02045808  arm
 *   MAILVIEW_HideAllPlanes 0x021C4AF8 thumb ov136
 *   MAILVIEW_SetupStep 0x021C4BFC thumb ov136
 *   MAILVIEW_VBlankTask 0x021C4B5C thumb ov136
 *   MAILVIEW_Teardown 0x021C4D14 thumb ov136
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   PALANM_BlendChannel 0x02021FD8 thumb
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   SDK_AUTOLOAD_MAIN_TWL_START 0x02FE0000 data
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BG_SYS_Update 0x020419E4 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   TCB_GetTaskOffset 0x02030CB0 arm
 *   TCB_Init 0x02030CBC arm
 *   TCB_AddTask 0x02030DA8 arm
 *   d_021C7EF8 0x021C7EF8 data a1
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
 *   PMS_DRAW_Create  0x0202DB0C  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   MAILSYS_ResetCursorBlend 0x021C44FC thumb ov136
 *   MAILVIEW_InitBgs 0x021C4DE4 thumb ov136
 *   MAILVIEW_FreeBgs 0x021C4EC4 thumb ov136
 *   MAILVIEW_LoadGraphics 0x021C4EEC thumb ov136
 *   MAILVIEW_FreeGraphics 0x021C5114 thumb ov136
 *   MAILVIEW_CreateWindows 0x021C515C thumb ov136
 *   MAILVIEW_CreateButtons 0x021C5268 thumb ov136
 *   MAILVIEW_DeleteWindows 0x021C52F8 thumb ov136
 *   MAILVIEW_PrintSentences 0x021C5360 thumb ov136
 *   MAILVIEW_InitActorSystem 0x021C5420 thumb ov136
 *   MAILVIEW_ExitActorSystem 0x021C5470 thumb ov136
 *   GFL_HEAP_Free  0x020307B0  arm
 *   PMSI_PARAM_IsEnabled 0x02024450 thumb
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   g_77F4 0x021C77F4 data
 *   g_7804 0x021C7804 data
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_LoadHandlePaletteToSlot 0x020216B4 thumb
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   BMP_MENUWORK_GetPlttFileId 0x0201F548 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   PALANM_Delete 0x02021540 thumb
 *   TCB_Noop 0x02030DA4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   PMS_DRAW_Print 0x0202DC48 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb  arm9
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb  arm9
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb  arm9
 *   MAILSYS_OnTouchMode 0x021C4528 thumb ov136
 *   MAILSYS_OnKeyModeNoOp 0x021C4534 thumb ov136
 *   MAILVIEW_SetVramBanks 0x021C4DD4 thumb ov136
 */
#include "../types.h"
#include "../arm9/clact.h"
#include "../arm9/palanm.h"
#include "mail_types.h"
#include "mailview_shared_types.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/strbuf.h"

#include "../arm9/bg_sys.h"






extern void CLACT_VBlankSystem(void);

struct MsgBank;

#include "../arm9/msgdata.h"

struct PrintQueue;
struct GFont;
struct TaskMenuRes;

#include "../arm9/app_taskmenu.h"


#include "../arm9/tcb_list.h"
struct TcbSystem;

struct TcbTask;




#include "../arm9/printsys.h"

struct PmsDraw;

#include "../arm9/pms_draw.h"






extern u32 SDK_AUTOLOAD_MAIN_TWL_START[];

extern char d_021C7EF8[];
extern const struct DispVram d_021C77C4;


void MAILVIEW_CursorBlendTask(void *unused, struct MailEditProc *proc);

void MAILVIEW_StartCursorBlendTask(struct MailEditProc *proc);

void MAILVIEW_CreatePmsDraw(struct MailEditProc *proc);

void MAILVIEW_DeletePmsDraw(struct MailEditProc *proc);

void MAILVIEW_HideAllPlanes(void)
{
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    BG_SYS_SetMainPlaneVisible(1, 0);
    BG_SYS_SetMainPlaneVisible(2, 0);
    BG_SYS_SetMainPlaneVisible(4, 0);
    BG_SYS_SetMainPlaneVisible(8, 0);
    BG_SYS_SetMainPlaneVisible(16, 0);
    BG_SYS_SetMainPlaneVisible(1, 0);
    BG_SYS_SetSubPlaneVisible(1, 0);
    BG_SYS_SetSubPlaneVisible(2, 0);
    BG_SYS_SetSubPlaneVisible(4, 0);
    BG_SYS_SetSubPlaneVisible(8, 0);
    BG_SYS_SetSubPlaneVisible(16, 0);
}

void MAILVIEW_VBlankTask(void *task, struct MailEditProc *proc)
{
    if (proc->palAnm) PALANM_TransferPalettes((PaletteFade *)proc->palAnm);
    CLACT_VBlankSystem();
    BG_SYS_Update();
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3FF8) |= 1;
}

/*
 * lever: blinkWeight >> 1 promotes to signed int before the u8 argument;
 * an unsigned cast drops the narrowing shift pair, a bitfield shifts 24/25.
 */
void MAILVIEW_CursorBlendTask(void *unused, struct MailEditProc *proc)
{
    u8 old;
    u8 direction;
    if (proc->dialogActive != 0 || proc->inputMode == 0) return;
    if (proc->blinkSlot != proc->highlightSlot) {
        MAILSYS_ResetCursorBlend(proc);
        proc->blinkSlot = proc->highlightSlot;
    }
    PALANM_BlendChannel((PaletteFadeWork *)proc->palAnm, 0, (u16)(proc->highlightSlot + 33), 1, proc->blinkWeight >> 1, 0x7FFF);
    direction = proc->blinkDown;
    old = proc->blinkWeight;
    if (direction != 0) {
        proc->blinkWeight = old - 1;
        if (old == 1) proc->blinkDown = direction ^ 1;
    } else {
        proc->blinkWeight = old + 1;
        if (old == 24) proc->blinkDown = direction ^ 1;
    }
}

/*
 * tail: 0x021C4C9A..0x021C4C9C is a zero alignment halfword.
 */
int MAILVIEW_SetupStep(struct MailEditProc *proc)
{
    switch (proc->subStep) {
    case 0:
        proc->msgData = (struct MsgData *)MSGDATA_CreateFromArchive(0, 2, 60, (u16)proc->heapId);
        proc->msgBuf = STRBUF_Create(128, (u16)proc->heapId);
        MAILVIEW_InitBgs(proc);
        break;
    case 1:
        MAILVIEW_LoadGraphics(proc);
        break;
    case 2:
        MAILVIEW_CreateWindows(proc);
        break;
    case 3:
        MAILVIEW_InitActorSystem(proc);
        proc->taskMenuRes = (struct AppTaskMenuRes *)APP_TASKMENU_RES_Create(0, 8, (struct GFont *)proc->font, (struct PrintQueue *)proc->printQue, (u16)proc->heapId);
        proc->subStep = 0;
        MAILVIEW_CreatePmsDraw(proc);
        MAILVIEW_PrintSentences(proc);
        MAILVIEW_CreateButtons(proc);
        MAILVIEW_StartCursorBlendTask(proc);
        return 1;
    }
    (proc->subStep)++;
    return 0;
}

void MAILVIEW_StartCursorBlendTask(struct MailEditProc *proc)
{
    void *mem;
    PALANM_BlendChannel((PaletteFadeWork *)proc->palAnm, 0, 0, 112, 16, 0);
    PALANM_SetAutoTransfer((PaletteFade *)proc->palAnm, 1);
    PALANM_TransferPalettes((PaletteFade *)proc->palAnm);
    proc->blinkWeight = 0;
    proc->blinkDown = 0;
    mem = GFL_HEAP_Alloc((u16)proc->heapId, TCB_GetTaskOffset(3), 0, d_021C7EF8, 0x4F3);
    proc->blinkTaskMem = mem;
    proc->blinkTaskList = TCB_Init(3, (struct TcbSystem *)mem);
    proc->blinkTask = TCB_AddTask((struct TcbSystem *)proc->blinkTaskList, (TcbFunc)MAILVIEW_CursorBlendTask, (void *)proc, 0);
}

int MAILVIEW_Teardown(struct MailEditProc *proc)
{
    MAILVIEW_DeletePmsDraw(proc);
    MAILVIEW_ExitActorSystem(proc);
    if (proc->pad_28) MSGDATA_Delete((struct MsgBank *)proc->msgData);
    STRBUF_Delete(proc->msgBuf);
    APP_TASKMENU_RES_Delete((struct TaskMenuRes *)proc->taskMenuRes);
    MAILVIEW_DeleteWindows(proc);
    MAILVIEW_FreeGraphics(proc);
    MAILVIEW_FreeBgs(proc);
    return 1;
}

void MAILVIEW_CreatePmsDraw(struct MailEditProc *proc)
{
    proc->pmsPrintQue = (struct PrintQue *)PRINTSYS_QUE_Create((u16)proc->heapId);
    proc->pmsClactUnit = CLACT_CreateUnit(8, 1, (u16)proc->heapId);
    proc->pmsDraw = PMS_DRAW_Create((unsigned int)proc->pmsClactUnit, (unsigned int)0, (unsigned int)proc->pmsPrintQue, (unsigned int)proc->font, 0, 4, (u16)proc->heapId);
    PMS_DRAW_SetNullColorPalette(proc->pmsDraw, 0);
}

void MAILVIEW_DeletePmsDraw(struct MailEditProc *proc)
{
    PMS_DRAW_Delete(proc->pmsDraw);
    PRINTSYS_QUE_Delete((struct PrintQueue *)proc->pmsPrintQue);
    proc->pmsPrintQue = 0;
    CLACT_DeleteUnit((struct Unit *)proc->pmsClactUnit);
}

void MAILVIEW_SetVramBanks(void)
{
    BG_SYS_SetVramBanks(&d_021C77C4);
}


#include "../arm9/pmsi_param.h"


struct BgSet { struct BgTemplate t[5]; };

#include "../arm9/bmp_win.h"

typedef short s16_p07;
#include "../arm9/bmp.h"













#include "../arm9/arc_tool.h"

#include "../arm9/bmp_menuwork.h"

#include "../arm9/arc_util.h"




#include "../arm9/palanm.h"





#include "../arm9/gf_font.h"







#include "../arm9/g2.h"


struct TaskMenuItem;
struct TaskMenuWin;






struct DispVramCfg;
struct SysInit;



#include "../arm9/net.h"

extern void CLACT_ExitSystem(void);

#include "mailsys.h"



extern const struct DispConfig g_77F4;

extern const struct BgSet g_7804;

extern u8 gClActorInitParam[];

void MAILVIEW_InitBgs(struct MailEditProc *proc)
{
    MAILVIEW_SetVramBanks();
    {
        struct DispConfig d = g_77F4;
        BG_SYS_SetGraphicsMode(&d);
    }
    BG_SYS_SetLcdSwap(0);
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
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_SetLcdSwap(1);
}

/*
 * note (2026-10-02): byte-correct; only the ABS32 word for MAILSYS_OnKeyModeNoOp (an unlabelled
 *   ov136 leaf "return 0", not in any lane) lacks a witness. File that leaf, then re-verify.
 */
void MAILVIEW_LoadGraphics(struct MailEditProc *proc)
{
    u32 design = proc->draft->design;
    void *arc = ARC_TOOL_CreateHandle(0x9B, (u16)proc->heapId);
    u32 sz;
    u32 pal;
    u32 chr;

    BMP_MENUWORK_LoadCharAndPltt(0, 1, 4, 0, (u16)proc->heapId);
    BMP_MENUWORK_LoadCharAndPltt(0, 0xD, 6, 0, (u16)proc->heapId);
    pal = design + 0xC;
    ARC_UTIL_UploadBgCharFromHandle(arc, pal, 3, 0, 0, 1, (u16)proc->heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc, pal, 4, 0, 0, 1, (u16)proc->heapId);
    chr = design + 0x18;
    sz = 0x800;
    ARC_UTIL_UploadBgPaletteFromHandle(arc, chr, 3, 0, sz, 1, (u16)proc->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, chr, 4, 0, sz, 1, (u16)proc->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc, design, 4, 0, 0, (u16)proc->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0xA0, 0x20, (u16)proc->heapId);
    proc->palAnm = PALANM_Create(proc->heapId);
    PALANM_AllocSlotBuffers(proc->palAnm, 0, 0xE0, (u16)proc->heapId);
    PALANM_LoadHandlePaletteToSlot(proc->palAnm, arc, design, (u16)proc->heapId, 0, 0x60, 0);
    PALANM_LoadArcPaletteToSlot(proc->palAnm, 0x17, 7, (u16)proc->heapId, 0, 0x20, 0x30);
    PALANM_LoadArcPaletteToSlot(proc->palAnm, 0x17, 5, (u16)proc->heapId, 0, 0x20, 0x50);
    PALANM_LoadArcPaletteToSlot(proc->palAnm, 5, BMP_MENUWORK_GetPlttFileId(0), (u16)proc->heapId, 0, 0x20, 0x40);
    PALANM_LoadArcPaletteToSlot(proc->palAnm, 5, BMP_MENUWORK_GetPlttFileId(1), (u16)proc->heapId, 0, 0x20, 0x60);
    GF_FONT_SetDefaultTextColor();
    ARC_TOOL_DeleteHandle(arc);
    BG_SYS_SetTileEntry(4, 0x2001, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_MarkTileDirty(4);
    BG_SYS_SetMainPlaneVisible(1, 1);
    BG_SYS_SetMainPlaneVisible(2, 1);
    BG_SYS_SetMainPlaneVisible(8, 1);
    if (proc->mode != 0) {
        arc = ARC_TOOL_CreateHandle(0x9B, (u16)proc->heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(arc, 0x24, 2, 0, sz, 1, (u16)proc->heapId);
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
    TCB_DeleteTask(proc->blinkTask);
    TCB_Noop(proc->blinkTaskList);
    GFL_HEAP_Free(proc->blinkTaskMem);
    G2x_SetBlendAlpha_((void *)0x04000050, 0, 0, 31, 0);
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
    proc->printQue = (struct PrintQue *)PRINTSYS_QUE_Create((u16)proc->heapId);
    for (i = 0; i < 7; i++) {
        BMP_Clear(BMP_WIN_GetBmp(proc->win[i]), 0);
        if (i < 5) {
            w = proc->win[i];
            BMP_WIN_TransferChars(w);
            BMP_WIN_MakeScreen(w);
            BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));
        }
    }
}

void MAILVIEW_CreateButtons(struct MailEditProc *proc)
{
    if (proc->mode == 1) {
        proc->buttonEntry[0].text = MSGDATA_AllocString((struct MsgBank *)proc->msgData, 0);
        proc->buttonEntry[0].color = 0x39E3;
        proc->buttonEntry[0].selected = 0;
        proc->buttonEntry[1].text = MSGDATA_AllocString((struct MsgBank *)proc->msgData, 1);
        proc->buttonEntry[1].color = 0x39E3;
        proc->buttonEntry[1].selected = 1;
        proc->sendButton = (struct AppTaskMenuWin *)APP_TASKMENU_WIN_Create((struct TaskMenuRes *)proc->taskMenuRes, (struct TaskMenuItem *)(&proc->buttonEntry[0]), 21, 18, 10, (u16)proc->heapId);
        proc->cancelButton = (struct AppTaskMenuWin *)APP_TASKMENU_WIN_Create((struct TaskMenuRes *)proc->taskMenuRes, (struct TaskMenuItem *)(&proc->buttonEntry[1]), 21, 21, 10, (u16)proc->heapId);
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
        APP_TASKMENU_WIN_Delete((struct TaskMenuWin *)proc->sendButton);
        APP_TASKMENU_WIN_Delete((struct TaskMenuWin *)proc->cancelButton);
        STRBUF_Delete(proc->buttonEntry[0].text);
        STRBUF_Delete(proc->buttonEntry[1].text);
    }
    PRINTSYS_QUE_Delete((struct PrintQueue *)proc->printQue);
    proc->printQue = 0;
    for (i = 0; i < 7; i++) {
        w = proc->win[i];
        BMP_WIN_ClearScreen(w);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));
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
        if (PMSI_PARAM_IsEnabled((unsigned short *)(&proc->draft->message[i]))) {
            PMS_DRAW_Print((unsigned int)proc->pmsDraw, (unsigned int)(proc->win[i + 1]), (struct BeaconDetailGraQuad *)((unsigned int)(&proc->draft->message[i])), (u8)i);
        }
    }
    draft = proc->draft;
    if (draft->messageId != 0xFFFF) {
        proc->closingWord.sentenceType = 6;
        proc->closingWord.sentenceId = 0;
        proc->closingWord.word[0] = draft->messageId;
        PMS_DRAW_Print((unsigned int)proc->pmsDraw, (unsigned int)proc->win[4], (struct BeaconDetailGraQuad *)((unsigned int)(&proc->closingWord)), (u8)3);
    }
    if (proc->mode == 0) {
        struct PrintQue *queue = proc->printQue;
        PRINTSYS_PrintQueColor((struct PrintQueue *)queue, BMP_WIN_GetBmp(proc->slot[5].win), 0, 2, proc->draft->writerName, proc->font, 0x440);
        proc->slot[5].flag = 1;
        w = proc->win[5];
        BMP_WIN_TransferChars(w);
        BMP_WIN_MakeScreen(w);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));
    }
}

void MAILVIEW_InitActorSystem(struct MailEditProc *proc)
{
    CLACT_InitSystem((const struct ClactSysInit *)(struct SysInit *)gClActorInitParam, (struct DispVramCfg *)(&d_021C77C4), (u16)(proc->heapId));
    proc->clactUnit = CLACT_CreateUnit(4, (int)0, (u16)(proc->heapId));
    CLACT_SetUnitDefaultRenderer((struct Unit *)proc->clactUnit);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
    GFL_NET_RefreshWmIconAtTopRight((int)0, (u16)(proc->heapId));
}

void MAILVIEW_ExitActorSystem(struct MailEditProc *proc)
{
    CLACT_DeleteUnit((struct Unit *)proc->clactUnit);
    CLACT_ExitSystem();
}
