/*
 * file:     mailview.c
 * unit:     yes
 * function: MAILVIEW_HideAllPlanes, MAILVIEW_VBlankTask, MAILVIEW_CursorBlendTask, MAILVIEW_SetupStep, MAILVIEW_StartCursorBlendTask, MAILVIEW_Teardown, MAILVIEW_CreatePmsDraw, MAILVIEW_DeletePmsDraw, MAILVIEW_SetVramBanks
 * address:  0x021C4AF8
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
 *   func_02030734 0x02030734 arm
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
 *   func_020419E4 0x020419E4 arm
 *   func_02045B38 0x02045B38 arm
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02030DA8 0x02030DA8 arm
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
 */
#include "mail_types.h"

struct DispVram;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void STRBUF_Delete(struct Strbuf *str);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void PALANM_BlendChannel(struct PalAnm *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void PALANM_TransferPalettes(struct PalAnm *p);
extern void CLACT_VBlankSystem(void);
extern void func_020419E4(void);
extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern struct AppTaskMenuRes *APP_TASKMENU_RES_Create(u16 a0, u16 a1, struct GfFont *font, struct PrintQue *printQue, u16 heap);
extern void PALANM_SetAutoTransfer(struct PalAnm *o, int v);
extern u32 func_02030CB0(u32 idx);
extern void *func_02030CBC(u32 capacity, void *mem);
extern void *func_02030DA8(void *taskList, void (*task)(void *, struct MailEditProc *), struct MailEditProc *work, int prio);
extern unsigned int MSGDATA_Delete(struct MsgData *msgData);
extern u32 APP_TASKMENU_RES_Delete(struct AppTaskMenuRes *res);
extern struct PrintQue *PRINTSYS_QUE_Create(u32 heapId);
extern struct ClactUnit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct PmsDraw *PMS_DRAW_Create(struct ClactUnit *clactUnit, u32 b, struct PrintQue *printQue, struct GfFont *font, u8 e0, u8 e1, u16 heap);
extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *p, u8 v);
extern void PMS_DRAW_Delete(struct PmsDraw *p);
extern void PRINTSYS_QUE_Delete(struct PrintQue *ps);
extern u32 CLACT_DeleteUnit(struct ClactUnit *unit);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern u32 SDK_AUTOLOAD_MAIN_TWL_START[];
extern char d_021C7EF8[];
extern const char d_021C77C4[];

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
    if (proc->palAnm) PALANM_TransferPalettes(proc->palAnm);
    CLACT_VBlankSystem();
    func_020419E4();
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
    PALANM_BlendChannel(proc->palAnm, 0, (u16)(proc->highlightSlot + 33), 1, proc->blinkWeight >> 1, 0x7FFF);
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
        proc->msgData = func_02045B38(0, 2, 60, (u16)proc->heapId);
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
        proc->taskMenuRes = APP_TASKMENU_RES_Create(0, 8, proc->font, proc->printQue, (u16)proc->heapId);
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
    PALANM_BlendChannel(proc->palAnm, 0, 0, 112, 16, 0);
    PALANM_SetAutoTransfer(proc->palAnm, 1);
    PALANM_TransferPalettes(proc->palAnm);
    proc->blinkWeight = 0;
    proc->blinkDown = 0;
    mem = func_02030734((u16)proc->heapId, func_02030CB0(3), 0, d_021C7EF8, 0x4F3);
    proc->blinkTaskMem = mem;
    proc->blinkTaskList = func_02030CBC(3, mem);
    proc->blinkTask = func_02030DA8(proc->blinkTaskList, MAILVIEW_CursorBlendTask, proc, 0);
}

int MAILVIEW_Teardown(struct MailEditProc *proc)
{
    MAILVIEW_DeletePmsDraw(proc);
    MAILVIEW_ExitActorSystem(proc);
    if (proc->pad_28) MSGDATA_Delete(proc->msgData);
    STRBUF_Delete(proc->msgBuf);
    APP_TASKMENU_RES_Delete(proc->taskMenuRes);
    MAILVIEW_DeleteWindows(proc);
    MAILVIEW_FreeGraphics(proc);
    MAILVIEW_FreeBgs(proc);
    return 1;
}

void MAILVIEW_CreatePmsDraw(struct MailEditProc *proc)
{
    proc->pmsPrintQue = PRINTSYS_QUE_Create((u16)proc->heapId);
    proc->pmsClactUnit = CLACT_CreateUnit(8, 1, (u16)proc->heapId);
    proc->pmsDraw = PMS_DRAW_Create(proc->pmsClactUnit, 0, proc->pmsPrintQue, proc->font, 0, 4, (u16)proc->heapId);
    PMS_DRAW_SetNullColorPalette(proc->pmsDraw, 0);
}

void MAILVIEW_DeletePmsDraw(struct MailEditProc *proc)
{
    PMS_DRAW_Delete(proc->pmsDraw);
    PRINTSYS_QUE_Delete(proc->pmsPrintQue);
    proc->pmsPrintQue = 0;
    CLACT_DeleteUnit(proc->pmsClactUnit);
}

void MAILVIEW_SetVramBanks(void)
{
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C77C4);
}
