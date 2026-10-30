/*
 * file:     mailsys.c
 * unit:     yes
 * function: MAILSYS_CreateMessage, MAILSYS_DeleteMessage, MAILSYS_WriteMessageToMail, MAILSYS_FillDefaultSentences, MAILSYS_ProcInit, MAILSYS_ProcMain, MAILSYS_ProcExit, MAILSYS_RunSequence, MAILSYS_IsMessageIncomplete, MAILSYS_ResetCursorBlend, MAILSYS_OnTouchMode, MAILSYS_OnKeyModeNoOp, MAILSYS_UpdateInputMode, MAILSYS_SwitchInputModeOnTrigger, MAILSYS_HandleKeyInput, MAILSYS_HandleTouchInput, MAILSYS_HandleInput, MAILSYS_PrintMessageText, MAILSYS_StepIncompleteNotice, MAILSYS_OpenConfirmMenu, MAILSYS_PollConfirmMenu, MAILSYS_StepQuitConfirm
 * address:  0x021C409C
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
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   MAIL_SetDesign 0x02008FA8 thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_GetHeapHeadChecked 0x0203084C arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   PMSI_PARAM_Copy 0x02024570 thumb
 *   PMSI_PARAM_IsEnabled 0x02024450 thumb
 *   MAIL_GetWriterId 0x02008F80 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   MAIL_GetWriterName 0x02008F84 thumb
 *   STRBUF_SetString 0x02045924 arm
 *   MAIL_GetDesign 0x02008FA4 thumb
 *   MAIL_GetLanguage 0x02008FB0 thumb
 *   MAIL_GetVersion 0x02008FB8 thumb
 *   MAIL_GetMessageId 0x02008FC0 thumb
 *   MAIL_GetMessage 0x02008FC8 thumb
 *   d_021C7EEC 0x021C7EEC data a1
 *   STRBUF_Delete  0x02045808  arm
 *   MAIL_SetMessage 0x02008FD8 thumb
 *   MAIL_SetMessageId 0x02008FC4 thumb
 *   PMSI_PARAM_InitSentenceId 0x020242C0 thumb
 *   d_021C77A0 0x021C77A0 data a1
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   TCBL_Create 0x0203101C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   TCBL_Destroy 0x02031140 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MAILVIEW_HideAllPlanes 0x021C4AF8 thumb ov136
 *   MAILVIEW_SetupStep 0x021C4BFC thumb ov136
 *   MAILVIEW_VBlankTask 0x021C4B5C thumb ov136
 *   MAILVIEW_Teardown 0x021C4D14 thumb ov136
 *   data_021C7774 0x021C7774 data
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   WIPE_ResetBrightness 0x02022230 thumb
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   GFL_USE_GetMainTaskList 0x020056BC thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   PMS_DRAW_Main 0x0202DBC4 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   TCB_Main 0x02030D28 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PMSI_PARAM_IsComplete 0x02024464 thumb
 *   PALANM_BlendChannel 0x02021FD8 thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   KEY_GetCont 0x0203630C arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021C7784 0x021C7784 data a4
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   APP_TASKMENU_WIN_ResetDecide 0x020282A4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   APP_TASKMENU_WIN_TransChar 0x02028454 thumb
 *   APP_TASKMENU_WIN_ClearScreen  0x0202843C  thumb  arm9
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb  arm9
 *   BMP_MENUWORK_DrawWindow   0x0201F73C  thumb
 */
#include "../version.h"
#include "mail_types.h"
#include "../sdk_ioreg.h"

struct Proc;
struct Proc;

typedef int (*MailEditModeHandler)(struct MailEditProc *proc);

#include "../arm9/palanm.h"
#ifdef __MWERKS__
#define GFL_HEAP_GetHeapHeadChecked GFL_HEAP_GetHeapHeadChecked_hdr
#endif
#include "../arm9/gfl_heap_wrap.h"
#ifdef __MWERKS__
#undef GFL_HEAP_GetHeapHeadChecked
void * GFL_HEAP_GetHeapHeadChecked(u16);
#endif
#include "../arm9/mi_memory.h"
#include "../arm9/mail.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/pmsi_param.h"
#ifdef __MWERKS__
#define STRBUF_Create STRBUF_Create_hdr
#endif
#include "../arm9/strbuf.h"
#ifdef __MWERKS__
#undef STRBUF_Create
struct Strbuf * STRBUF_Create(unsigned, u16);
#endif
#include "../arm9/msg_speed.h"
#include "../arm9/gf_font.h"
struct TcblSystem;
#include "../arm9/tcbl.h"
#include "../arm9/bg_sys.h"
#include "../arm9/wipe.h"
#include "../arm9/gfl_use.h"
#include "../arm9/g2.h"
struct TcbList;
#include "../arm9/pms_draw.h"
struct TaskMenuWin;
#include "../arm9/app_taskmenu.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
#ifdef __MWERKS__
#define CLACT_DrawSystem CLACT_DrawSystem_hdr
#endif
#include "../arm9/clact.h"
#ifdef __MWERKS__
#undef CLACT_DrawSystem
void CLACT_DrawSystem(struct Unit *);
#endif
struct TcbSystem;
struct PrintQueue;
#include "../arm9/printsys.h"
#include "../arm9/touchpanel.h"
#include "../arm9/key.h"
struct BmpWin;
#include "../arm9/bmp_menuwork.h"
#include "../arm9/bmp_win.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/msgdata.h"
struct TextPrinter;
struct MsgBank;
struct TaskMenuRes;
struct TaskMenuInitWork;
struct TaskMenuWork;

int MAILSYS_ProcMain(void *a, void *b, void *c, struct MailEditProc *proc);
int MAILSYS_ProcExit(void *a, void *b, void *c, struct MailEditProc *proc);
int MAILSYS_RunSequence(struct MailEditProc *proc);
int MAILSYS_IsMessageIncomplete(struct MailEditProc *proc);
int MAILSYS_OnTouchMode(struct MailEditProc *proc);
int MAILSYS_OnKeyModeNoOp(struct MailEditProc *proc);
int MAILSYS_UpdateInputMode(struct MailEditProc *proc);
int MAILSYS_SwitchInputModeOnTrigger(struct MailEditProc *proc);
int MAILSYS_HandleKeyInput(struct MailEditProc *proc);
int MAILSYS_HandleTouchInput(struct MailEditProc *proc);
int MAILSYS_HandleInput(struct MailEditProc *proc);
void MAILSYS_PrintMessageText(struct MailEditProc *proc, int msgId);
int MAILSYS_StepIncompleteNotice(struct MailEditProc *proc);
void MAILSYS_OpenConfirmMenu(struct MailEditProc *proc);
int MAILSYS_PollConfirmMenu(struct MailEditProc *proc);
int MAILSYS_StepQuitConfirm(struct MailEditProc *proc);

extern const char d_021C7EEC[];
extern const u8 d_021C77A0[][3];
extern MailEditModeHandler data_021C7774[];
extern u8 d_021C7784[];

struct MailDraft *MAILSYS_CreateMessage(struct Mail *mail, unsigned heap)
{
    struct MailDraft *draft;
    u16 i;
    i = 0;
    draft = GFL_HEAP_Alloc((u16)heap, sizeof(*draft), 0, d_021C7EEC, 0x147);
    MIi_CpuClearFast(0, draft, sizeof(*draft));
    draft->result = i;
    draft->writerId = MAIL_GetWriterId(mail);
    draft->writerName = STRBUF_Create(0x10, heap);
    STRBUF_SetString(draft->writerName, (const u16 *)MAIL_GetWriterName(mail));
    draft->design = MAIL_GetDesign(mail);
    draft->language = MAIL_GetLanguage(mail);
    draft->version = MAIL_GetVersion(mail);
    draft->messageId = MAIL_GetMessageId(mail);
    for (; i < 3; i++) PMSI_PARAM_Copy(&draft->message[i], MAIL_GetMessage(mail, (u8)i));
    return draft;
}

void MAILSYS_DeleteMessage(struct MailDraft *draft)
{
    if (draft->writerName)
        STRBUF_Delete(draft->writerName);
    GFL_HEAP_Free(draft);
}

void MAILSYS_WriteMessageToMail(struct Mail *mail, struct MailDraft *draft)
{
    u16 i;
    for (i = 0; i < 3; i++) MAIL_SetMessage(mail, &draft->message[i], (u8)i);
    MAIL_SetMessageId(mail, draft->messageId);
    MAIL_SetDesign(mail, draft->design);
}

/*
 *   int PMSI_PARAM_IsEnabled(unsigned short *p) { return *p != 0xFFFF; }
 */
void MAILSYS_FillDefaultSentences(struct MailEditProc *proc, struct MailDraft *draft)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (PMSI_PARAM_IsEnabled( (const unsigned short *)&draft->message[i]) == 0) {
            if (d_021C77A0[draft->design][i] != 0xFF) PMSI_PARAM_InitSentenceId(&draft->message[i], 5, d_021C77A0[draft->design][i]);
        }
        if (d_021C77A0[draft->design][i] == 0xFF) draft->slotEnabled[i] = 0;
        else draft->slotEnabled[i] = 1;
    }
}

int MAILSYS_ProcInit(void *a, void *b, struct MailDraft *draft)
{
    struct MailEditProc *proc;
    u8 v;
    GFL_HEAP_CreateChildHeap(1, 0x64, 0x20000);
    proc = PROCSYS_AllocProcWork(a, sizeof(*proc), 0x64);
    MIi_CpuClearFast(0, proc, sizeof(*proc));
    proc->heapId = 0x64;
    proc->draft = draft;
    proc->mode = draft->result;
    proc->prevMode = proc->mode;
    proc->cursor = draft->selectedSlot;
    proc->cursorSub = draft->selectedSub;
    v = proc->cursor;
    proc->highlightSlot = v;
    proc->blinkSlot = v;
    draft->result = 0xFFFF;
    proc->textSpeed = MSG_SPEED_GetWait();
    MAILSYS_FillDefaultSentences(proc, proc->draft);
    proc->font = GF_FONT_Create((unsigned)0x17, (unsigned)0, (unsigned)0, (unsigned)0, (u16)(proc->heapId));
    proc->tcbl = (struct Tcbl *)TCBL_Create((u16)(proc->heapId), proc->heapId, 0x20, 0x20);
    proc->inputMode = 1;
    BG_SYS_Create(proc->heapId);
    return 1;
}

int MAILSYS_ProcMain(void *a, void *b, void *c, struct MailEditProc *proc)
{
    if (MAILSYS_RunSequence(proc)) return 1;
    return 0;
}

int MAILSYS_ProcExit(void *a, void *b, void *c, struct MailEditProc *proc)
{
    u32 h;
    BG_SYS_Delete();
    TCBL_Destroy((struct TcblSystem *)proc->tcbl);
    GF_FONT_Delete(proc->font);
    h = proc->heapId;
    PROCSYS_FreeProcWork(a);
    GFL_HEAP_GetHeapHeadChecked(h);
    GFL_HEAP_DeleteChecked((u16)h);
    return 1;
}

int MAILSYS_RunSequence(struct MailEditProc *proc)
{
    int r = 0;
    void *t;

    switch (proc->step) {
    case 0:
        MAILVIEW_HideAllPlanes();
        WIPE_SetBrightnessFadeOut(0, 0);
        WIPE_SetBrightnessFadeOut(1, 0);
        WIPE_ResetWndMask(0);
        WIPE_ResetWndMask(1);
        (proc->step)++;
        break;
    case 1:
        if (MAILVIEW_SetupStep(proc)) {
            proc->vblankTask = GFL_USE_AddMainTask((void *)MAILVIEW_VBlankTask, proc, 0x10);
            BG_SYS_SetMainPlaneVisible(0x10, 1);
            WIPE_ResetBrightness(0);
            G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR, 4, 8, 0x1C, 4);
            t = GFL_USE_GetMainTaskList();
            PALANM_RequestFade((PaletteFade *)proc->palAnm, 5, 0xFFFF, -1, 0x10, 0, 0, t);
            (proc->step)++;
        }
        break;
    case 2:
        if (!PALANM_GetFadeRequestBits((const PaletteFade *)proc->palAnm))
            (proc->step)++;
        PMS_DRAW_Main(proc->pmsDraw);
        break;
    case 3:
        if (data_021C7774[proc->mode](proc) == 1) {
            (proc->step)++;
            t = GFL_USE_GetMainTaskList();
            PALANM_RequestFade((PaletteFade *)proc->palAnm, 5, 0xFFFF, -1, 0, 0x10, 0, t);
        }
        PMS_DRAW_Main(proc->pmsDraw);
        if (proc->sendButton) {
            APP_TASKMENU_WIN_Update((struct TaskMenuWin *)proc->sendButton);
            APP_TASKMENU_WIN_Update((struct TaskMenuWin *)proc->cancelButton);
        }
        break;
    case 4:
        if (!PALANM_GetFadeRequestBits((const PaletteFade *)proc->palAnm)) {
            WIPE_SetBrightnessFadeOut(0, 0);
            WIPE_SetBrightnessFadeOut(1, 0);
            TCB_DeleteTask(proc->vblankTask);
            MAILVIEW_HideAllPlanes();
            (proc->step)++;
        }
        PMS_DRAW_Main(proc->pmsDraw);
        break;
    case 5:
        if (MAILVIEW_Teardown(proc))
            r = 1;
        break;
    }
    if (proc->clactUnit)
#ifdef __MWERKS__
        CLACT_DrawSystem(proc->clactUnit);
#else
        CLACT_DrawSystem();
#endif
    if (proc->blinkTaskList)
        TCB_Main(proc->blinkTaskList);
    if (proc->tcbl)
        TCBL_Main((struct TcblSystem *)proc->tcbl);
    if (proc->printQue)
        PRINTSYS_QUE_Main(proc->printQue);
    if (proc->pmsPrintQue)
        PRINTSYS_QUE_Main(proc->pmsPrintQue);
    return r;
}

int MAILSYS_IsMessageIncomplete(struct MailEditProc *proc)
{
    int t = 1;
    int n = 0;
    int c0 = 0;
    int c1 = 0;
    int i;
    for (i = 0; i < 3; i++) {
        if (d_021C77A0[proc->draft->design][i] != 0xFF) n++;
    }
    if (n == 3) t = 0;
    for (i = 0; i < 3; i++) {
        struct MailDraft *x = proc->draft;
        if (d_021C77A0[x->design][i] != 0xFF) {
            if (PMSI_PARAM_IsComplete(&x->message[i], 0x64)) c1++;
        } else {
            if (PMSI_PARAM_IsEnabled( (const unsigned short *)&x->message[i])) c0++;
        }
    }
    if (c0 < t || c1 < n) return 1;
    return 0;
}

void MAILSYS_ResetCursorBlend(struct MailEditProc *proc)
{
    PALANM_BlendChannel(proc->palAnm, 0, (u16)(proc->blinkSlot + 0x21), 1, 0, 0x7FFF);
    proc->blinkDown = 0;
    proc->blinkWeight = 0;
}

int MAILSYS_OnTouchMode(struct MailEditProc *proc)
{
    MAILSYS_ResetCursorBlend(proc);
    return 0;
}

int MAILSYS_OnKeyModeNoOp(struct MailEditProc *proc)
{
    return 0;
}

/*
 * tail: 021C458E..021C4590 zero alignment padding.
 */
int MAILSYS_UpdateInputMode(struct MailEditProc *proc)
{
    if (proc->inputMode == 0) {
        if (TOUCHPANEL_GetCont()) return 0;
        if (KEY_GetCont()) {
            if (proc->onKeyInput) proc->onKeyInput(proc);
            proc->inputMode = 1;
            return 1;
        }
    } else {
        if (KEY_GetCont()) return 0;
        if (TOUCHPANEL_GetCont()) {
            if (proc->onTouchInput) proc->onTouchInput(proc);
            proc->inputMode = 0;
            return 0;
        }
    }
    return 0;
}

int MAILSYS_SwitchInputModeOnTrigger(struct MailEditProc *proc)
{
    if (KEY_GetTrg()) {
        proc->inputMode = 1;
#if LANGUAGE == LANGUAGE_JAPANESE
    } else if (TOUCHPANEL_GetCont()) {
#else
    } else if (TOUCHPANEL_GetTrg()) {
#endif
        proc->inputMode = 0;
    } else {
        return 0;
    }
    GFL_USE_PlaySeDefaultVolume(0x54E);
    return 1;
}

int MAILSYS_HandleKeyInput(struct MailEditProc *proc)
{
    int moved;

    if (KEY_GetTrg() & 1) {
        if (proc->cursor == 4) {
            if (MAILSYS_IsMessageIncomplete(proc)) {
                GFL_USE_PlaySeDefaultVolume(0x551);
                proc->mode = 2;
                return 0;
            }
            proc->draft->result = 4;
            GFL_USE_PlaySeDefaultVolume(0x54E);
            proc->draft->selectedSlot = 0;
            proc->draft->selectedSub = 0;
            APP_TASKMENU_WIN_SetDecide((struct TaskMenuWin *)proc->sendButton, 1);
            return 1;
        }
        if (proc->cursor == 5) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            proc->mode = 3;
            return 0;
        }
        proc->draft->selectedSlot = proc->cursor;
        proc->draft->result = proc->draft->selectedSlot;
        proc->draft->selectedSub = proc->cursorSub;
        GFL_USE_PlaySeDefaultVolume(0x54D);
        return 1;
    }
    if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        proc->mode = 3;
        return 0;
    }
    if (KEY_GetTrg() & 8) {
        proc->cursor = 4;
        proc->cursorSub = 0;
        moved = 1;
    } else if (KEY_GetTrg() & 0x80) {
        proc->cursor = (proc->cursor + 1) % 6;
        moved = 1;
    } else if (KEY_GetTrg() & 0x40) {
        proc->cursor = (proc->cursor + 5) % 6;
        moved = 1;
    } else {
        return 0;
    }
    if (moved == 0) {
        return 0;
    }
    GFL_USE_PlaySeDefaultVolume(0x54C);
    if (proc->cursor < 4) {
        APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)proc->sendButton, 0);
        APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)proc->cancelButton, 0);
    } else if (proc->cursor == 4) {
        APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)proc->sendButton, 1);
        APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)proc->cancelButton, 0);
    } else if (proc->cursor == 5) {
        APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)proc->sendButton, 0);
        APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)proc->cancelButton, 1);
    }
    proc->highlightSlot = proc->cursor;
    return 0;
}

int MAILSYS_HandleTouchInput(struct MailEditProc *proc)
{
    int n;
    n = TOUCHPANEL_HitTrg((const TouchHitTable *)d_021C7784);
    if (n == -1) return 0;
    if (n == 4) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        proc->mode = 3;
        return 0;
    }
    if (n < 4) {
        proc->draft->selectedSlot = n;
        proc->draft->result = proc->draft->selectedSlot;
        proc->draft->selectedSub = proc->cursorSub;
        GFL_USE_PlaySeDefaultVolume(0x54D);
        return 1;
    }
    if (MAILSYS_IsMessageIncomplete(proc)) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        proc->mode = 2;
        return 0;
    }
    proc->draft->result = 4;
    GFL_USE_PlaySeDefaultVolume(0x54E);
    proc->draft->selectedSlot = 0;
    proc->draft->selectedSub = 0;
    APP_TASKMENU_WIN_SetDecide((struct TaskMenuWin *)proc->sendButton, 1);
    APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)proc->cancelButton, 0);
    return 1;
}

int MAILSYS_HandleInput(struct MailEditProc *proc)
{
    if (MAILSYS_UpdateInputMode(proc)) return 0;
    if (proc->inputMode == 1) return MAILSYS_HandleKeyInput(proc);
    return MAILSYS_HandleTouchInput(proc);
}

void MAILSYS_PrintMessageText(struct MailEditProc *proc, int msgId)
{
    struct BmpWin *win;
    BMP_MENUWORK_DrawWindow((struct BmpWin *)proc->win[6], 2, 13, 4);
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)proc->win[6]), 255);
    MSGDATA_ReadString((struct MsgBank *)proc->msgData, msgId, (struct Strbuf *)proc->msgBuf);
    proc->printStream = PRINTSYS_PrintStream(proc->win[6], 0, 0, proc->msgBuf, proc->font, PM_LANG_JA(proc->textSpeed, (u8)proc->textSpeed), proc->tcbl, 4, (u16)proc->heapId, 15);
    win = proc->win[6];
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
}

int MAILSYS_StepIncompleteNotice(struct MailEditProc *proc)
{
    struct BmpWin *win;
    switch (proc->subStep) {
    case 0:
        APP_TASKMENU_WIN_SetDecide((struct TaskMenuWin *)proc->sendButton, 1);
        APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)proc->cancelButton, 0);
        proc->subStep = 1;
        break;
    case 1:
        if (APP_TASKMENU_WIN_IsFinish((struct TaskMenuWin *)proc->sendButton) != 0) {
            APP_TASKMENU_WIN_ResetDecide((struct TaskMenuWin *)proc->sendButton);
            APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)proc->sendButton, 1);
            MAILSYS_PrintMessageText(proc, 2);
            proc->subStep = 2;
        }
        break;
    case 2:
        if (PRINTSYS_PrintStreamGetState(proc->printStream) == 2) {
            if ((KEY_GetTrg() & 1) || TOUCHPANEL_GetTrg()) {
                PRINTSYS_PrintStreamDelete(proc->printStream);
                proc->subStep = 3;
            }
        }
        break;
    case 3:
        BMP_MENUWORK_DrawWindowBorder(proc->win[6], 2);
        win = proc->win[6];
        BMP_WIN_ClearScreen(win);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
        MAILSYS_ResetCursorBlend(proc);
        proc->subStep = 0;
        proc->mode = proc->prevMode;
        break;
    }
    return 0;
}

void MAILSYS_OpenConfirmMenu(struct MailEditProc *proc)
{
    struct MailMenuTemplate t;
    proc->dialogEntry[0].text = MSGDATA_AllocString((struct MsgBank *)proc->msgData, 4);
    proc->dialogEntry[0].color = 0x39E3;
    proc->dialogEntry[0].selected = 0;
    proc->dialogEntry[1].text = MSGDATA_AllocString((struct MsgBank *)proc->msgData, 5);
    proc->dialogEntry[1].color = 0x39E3;
    proc->dialogEntry[1].selected = 0;
    t.heapId = proc->heapId;
    t.count = 2;
    t.items = proc->dialogEntry;
    t.zero = 0;
    t.x = 23;
    t.y = 6;
    t.w = 8;
    t.h = 3;
    proc->dialogMenu = (struct AppTaskMenu *)APP_TASKMENU_OpenMenu( (struct TaskMenuInitWork *)&t, (struct TaskMenuRes *)proc->taskMenuRes);
    PALANM_BlendChannel(proc->palAnm, 0, 0, 48, 10, 0);
    APP_TASKMENU_WIN_ClearScreen((struct TaskMenuWin *)proc->sendButton);
    APP_TASKMENU_WIN_ClearScreen((struct TaskMenuWin *)proc->cancelButton);
}

int MAILSYS_PollConfirmMenu(struct MailEditProc *proc)
{
    int r = -1;
    if (APP_TASKMENU_IsFinish((struct TaskMenuWork *)proc->dialogMenu)) {
        r = APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)proc->dialogMenu);
        APP_TASKMENU_CloseMenu((struct TaskMenuWork *)proc->dialogMenu);
        STRBUF_Delete(proc->dialogEntry[0].text);
        STRBUF_Delete(proc->dialogEntry[1].text);
    }
    return r;
}

int MAILSYS_StepQuitConfirm(struct MailEditProc *proc)
{
    int r;
    struct BmpWin *win;

    switch (proc->subStep) {
    case 0:
        APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)proc->sendButton, 0);
        APP_TASKMENU_WIN_SetDecide((struct TaskMenuWin *)proc->cancelButton, 1);
        break;
    case 1:
        if (APP_TASKMENU_WIN_IsFinish((struct TaskMenuWin *)proc->cancelButton)) {
            APP_TASKMENU_WIN_ResetDecide((struct TaskMenuWin *)proc->cancelButton);
            APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)proc->cancelButton, 1);
            proc->dialogActive = 1;
            MAILSYS_PrintMessageText(proc, 3);
            MAILSYS_ResetCursorBlend(proc);
            proc->blinkSlot = proc->highlightSlot;
            break;
        }
        return 0;
    case 2:
        if (PRINTSYS_PrintStreamGetState(proc->printStream) == 2) {
            PRINTSYS_PrintStreamDelete(proc->printStream);
            MAILSYS_OpenConfirmMenu(proc);
            proc->subStep = 3;
        }
        return 0;
    case 3:
        APP_TASKMENU_UpdateMenu((struct TaskMenuWork *)proc->dialogMenu);
        r = MAILSYS_PollConfirmMenu(proc);
        if (r < 0)
            return 0;
        BMP_MENUWORK_DrawWindowBorder(proc->win[6], 2);
        win = proc->win[6];
        BMP_WIN_ClearScreen(win);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
        proc->subStep = 0;
        if (r == 0) {
            proc->draft->result = 0xFFFF;
            proc->mode = proc->prevMode;
            return 1;
        }
        proc->dialogActive = 0;
        proc->mode = proc->prevMode;
        PALANM_BlendChannel(proc->palAnm, 0, 0, 0x30, 0, 0);
        APP_TASKMENU_WIN_TransChar((struct TaskMenuWin *)proc->sendButton);
        APP_TASKMENU_WIN_TransChar((struct TaskMenuWin *)proc->cancelButton);
        return 0;
    }
    (proc->subStep)++;
    return 0;
}
