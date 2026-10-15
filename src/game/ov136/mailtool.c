/*
 * file:     mailtool.c
 * unit:     yes
 * function: MAILTOOL_CreateWriteArgs, MAILTOOL_CreateArgsFromPartyMon, MAILTOOL_CreateArgsFromMail, MAILTOOL_HasMail, MAILTOOL_StoreMailToPartyMon, MAILTOOL_DeleteArgs, MAILTOOL_ProcInit, MAILTOOL_ProcMain, MAILTOOL_ProcExit, MAILTOOL_StartWordInput
 * address:  0x021C3CC0
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
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MAIL_Create 0x02008F08 thumb
 *   func_02008EAC 0x02008EAC thumb
 *   func_02008F48 0x02008F48 thumb
 *   d_021C7EE0 0x021C7EE0 data a1
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_02008FA8 0x02008FA8 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   func_020307B0  0x020307B0  arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Main 0x02031330 arm
 *   PROCSYS_Push 0x02031348 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   PMSI_PARAM_CheckCanceled 0x0202411C thumb
 *   PMSI_PARAM_GetSentence 0x02024134 thumb
 *   PMSI_PARAM_GetWord 0x02024124 thumb
 *   PMSI_PARAM_Delete 0x020240FC thumb
 *   func_02008C58 0x02008C58 thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   ov110_id 0x0000006E data
 *   D_021C7750 0x021C7750 data
 *   D_021C775C 0x021C775C data
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_0203084C 0x0203084C arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   PMSI_PARAM_ClearSentence 0x0202428C thumb
 *   PMSI_PARAM_Create 0x02024044 thumb
 *   PMSI_PARAM_SetWord 0x02024104 thumb
 *   PMSI_PARAM_Copy 0x02024570 thumb
 *   PMSI_PARAM_IsEnabled 0x02024450 thumb
 *   PMSI_PARAM_InitSentence 0x020242A4 thumb
 *   PMSI_PARAM_SetSentence 0x02024108 thumb
 *   MAILTOOL_CreateWriteArgs  0x021C3CC0  thumb
 *   MAILTOOL_HasMail 0x021C3E00 thumb ov136
 *   MAILTOOL_StoreMailToPartyMon 0x021C3E04 thumb ov136
 *   MAILTOOL_DeleteArgs 0x021C3E24 thumb ov136
 *   MAILSYS_CreateMessage 0x021C409C thumb ov136
 *   MAILSYS_DeleteMessage 0x021C4134 thumb ov136
 *   MAILSYS_WriteMessageToMail 0x021C414C thumb ov136
 */
#include "mail_types.h"

struct Big;
struct Sub02008C20Obj;
struct S020314B8;
struct Proc;
struct Proc;

extern struct MailData *func_02008FEC(void *sys);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MIi_CpuClearFast(unsigned, void *, unsigned);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Mail *MAIL_Create(int heapId);
extern void func_02008EAC(struct Mail *mail);
extern void func_02008F48(struct Mail *mail, u8 kind, u32 unused, void *p);
extern unsigned POKE_TOOL_GetPartyValue(void *, unsigned, unsigned);
extern void func_02008FA8(struct Mail *mail, u32 value);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 func_020307B0(void *p);
extern void GFL_HEAP_CreateChildHeap(unsigned, unsigned, unsigned);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void *PROCSYS_Create(int a0);
extern u32 PROCSYS_Main(void *p);
extern void PROCSYS_Push(void *h, u32 id, void *a, void *b);
extern int func_02034AC4(int handle);
extern void func_02034A5C(int handle);
extern int PMSI_PARAM_CheckCanceled(struct PmsiParam *p);
extern void PMSI_PARAM_GetSentence(struct PmsiParam *a, struct PmsData *b);
extern unsigned int PMSI_PARAM_GetWord(struct PmsiParam *p);
extern void PMSI_PARAM_Delete(struct PmsiParam *a);
extern struct Sub02008C20Obj *func_02008C58(struct SaveControl *sys);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void func_0203133C(void *v);
extern void func_020315D4(struct Proc *v);
extern void func_0203084C(u16 v);
extern void GFL_HEAP_DeleteChecked(u32 v);
extern void PMSI_PARAM_ClearSentence(struct PmsData *p);
extern struct PmsiParam *PMSI_PARAM_Create(u32 kind, u32 a1, struct PmsData *src, u32 flag, struct SaveControl *sys, u32 heapId);
extern void PMSI_PARAM_SetWord(struct PmsiParam *p, u16 v);
extern void PMSI_PARAM_Copy(struct PmsData *dst, const struct PmsData *src);
extern int PMSI_PARAM_IsEnabled(const struct PmsData *p);
extern void PMSI_PARAM_InitSentence(struct PmsData *obj, u32 id);
extern void PMSI_PARAM_SetSentence(struct PmsiParam *dst, const struct PmsData *src);

void *MAILTOOL_CreateWriteArgs(void *a, unsigned b, unsigned c, unsigned d, unsigned heap);
void *MAILTOOL_CreateArgsFromPartyMon(void *a, void *b, unsigned heap);
void *MAILTOOL_CreateArgsFromMail(void *a, void *b, unsigned heap);
u32 MAILTOOL_HasMail(struct MailArgs *args);
int MAILTOOL_StoreMailToPartyMon(struct MailArgs *args, void *mon);
void MAILTOOL_DeleteArgs(struct MailArgs *args);
int MAILTOOL_ProcInit(void *a, void *b, struct MailArgs *args);
int MAILTOOL_ProcMain(int unused, u32 *state, struct MailArgs *args, struct MailToolProc *proc);
int MAILTOOL_ProcExit(u32 a, void *b, void *c, struct MailToolProc *proc);
void MAILTOOL_StartWordInput(struct MailToolProc *proc, struct MailArgs *args);

extern const char d_021C7EE0[];
extern u8 ov110_id[];
extern u8 D_021C7750[];
extern u8 D_021C775C[];

void *MAILTOOL_CreateWriteArgs(void *a, unsigned b, unsigned c, unsigned d, unsigned heap)
{
    struct MailArgs *args;
    struct MailData *mailData;
    mailData = func_02008FEC(a);
    args = func_02030734((u16)(((u16)heap & 0x7FFF) | 0x8000), 0x1C, 0, d_021C7EE0, 0x43);
    MIi_CpuClearFast(0, args, 0x1C);
    args->designId = d;
    args->monIndex = c;
    args->mailData = mailData;
    args->mode = 1;
    args->callerParam = b;
    args->reserved0C = 0;
    args->saveControl = GAME_DATA_GetSaveControl(a);
    args->mail = MAIL_Create((unsigned)((u16)heap));
    func_02008EAC(args->mail);
    func_02008F48(args->mail, 0xFF, c, a);
    return args;
}

void *MAILTOOL_CreateArgsFromPartyMon(void *a, void *b, unsigned heap)
{
    struct MailArgs *args;
    args = func_02030734((u16)(((u16)heap & 0x7FFF) | 0x8000), 0x1C, 0, d_021C7EE0, 0x97);
    MIi_CpuClearFast(0, args, 0x1C);
    args->mode = 0;
    args->saveControl = GAME_DATA_GetSaveControl(a);
    args->mail = MAIL_Create((unsigned)((u16)heap));
    POKE_TOOL_GetPartyValue(b, 0xA7, (u32)args->mail);
    return args;
}

void *MAILTOOL_CreateArgsFromMail(void *a, void *b, unsigned heap)
{
    struct MailArgs *args;
    args = func_02030734((u16)(((u16)heap & 0x7FFF) | 0x8000), 0x1C, 0, d_021C7EE0, 0xB9);
    MIi_CpuClearFast(0, args, 0x1C);
    args->mode = 0;
    args->saveControl = GAME_DATA_GetSaveControl(a);
    args->mail = MAIL_Create((unsigned)((u16)heap));
    func_02008FA8(args->mail, (u32)b);
    return args;
}

u32 MAILTOOL_HasMail(struct MailArgs *args)
{
    return args->sent;
}

int MAILTOOL_StoreMailToPartyMon(struct MailArgs *args, void *mon)
{
    if (MAILTOOL_HasMail(args) == 0) return 0;
    POKE_TOOL_SetPartyValue(mon, 0xa7, (u32)args->mail);
    return 1;
}

/*
 * Addresses are Black-image addresses.
 */
void MAILTOOL_DeleteArgs(struct MailArgs *args)
{
    if (args->mail)
        func_020307B0(args->mail);
    func_020307B0(args);
}

/*
 * tail: 021C3E9A..021C3E9C zero alignment padding.
 */
int MAILTOOL_ProcInit(void *a, void *b, struct MailArgs *args)
{
    struct MailToolProc *proc;
    GFL_HEAP_CreateChildHeap(1, 0x63, 0x1000);
    proc = PROCSYS_AllocProcWork(a, 0x20, 0x63);
    MIi_CpuClearFast(0, proc, 0x20);
    proc->heapId = 0x63;
    proc->draft = MAILSYS_CreateMessage(args->mail, 0x63);
    if (args->mode == 1) proc->draft->design = args->designId;
    if (proc->draft->design >= 0xC) proc->draft->design = 0;
    proc->draft->result = args->mode;
    proc->procSys = PROCSYS_Create(0x63);
    return 1;
}

/*
 * note 2026-10-05 (wD7 lane15): closed. MAILSYS_WriteMessageToMail takes a second argument (the draft, its matched
 *   definition reads r1), so case 2 keeps the draft pointer in r1 for that call.
 */
int MAILTOOL_ProcMain(int unused, u32 *state, struct MailArgs *args, struct MailToolProc *proc)
{
    u32 ret = PROCSYS_Main(proc->procSys);
    switch (*state) {
    case 0:
        proc->draft->result = args->mode;
        PROCSYS_Push(proc->procSys, (u32)-1, D_021C7750, proc->draft);
        *state = 1;
        break;
    case 1: {
        u16 v;
        if (ret == 1)
            break;
        v = proc->draft->result;
        if (v != 4) {
            if (v == 0xFFFF)
                *state = 2;
            else
                goto s3;
        } else
            *state = 2;
        break;
    s3:
        *state = 3;

        break;
    }
    case 2:
        if (args->mode == 1) {
            u32 r;
            struct MailDraft *draft = proc->draft;
            if (draft->result == 4) {
                MAILSYS_WriteMessageToMail(args->mail, draft);
                func_02008DF0(func_02008C58(args->saveControl), 0x1D);
                r = 1;
            } else {
                r = 0;
            }
            args->sent = r;
        }
        return 1;
    case 3:
        func_02034AC4((int)ov110_id);
        MAILTOOL_StartWordInput(proc, args);
        PROCSYS_Push(proc->procSys, (u32)-1, D_021C775C, proc->pmsiParam);
        *state = 4;
        break;
    case 4:
        if (ret == 1)
            break;
        if (PMSI_PARAM_CheckCanceled(proc->pmsiParam) == 0) {
            struct MailDraft *draft = proc->draft;
            struct PmsiParam *pmsi = proc->pmsiParam;
            if (draft->selectedSlot < 3)
                PMSI_PARAM_GetSentence(pmsi, &draft->message[draft->selectedSlot]);
            else
                proc->draft->messageId = PMSI_PARAM_GetWord(proc->pmsiParam);
        }
        PMSI_PARAM_Delete(proc->pmsiParam);
        func_02034A5C((int)ov110_id);
        *state = 0;
        break;
    }
    return 0;
}

int MAILTOOL_ProcExit(u32 a, void *b, void *c, struct MailToolProc *proc)
{
    u16 h;
    func_0203133C(proc->procSys);
    MAILSYS_DeleteMessage(proc->draft);
    h = (u16)proc->heapId;
    func_020315D4((struct Proc *)a);
    func_0203084C(h);
    GFL_HEAP_DeleteChecked(h);
    return 1;
}

/*
 * note:     2026-10-02 only unresolved arm9 Thumb leaf witnesses (02024104, 02024108, 02024450 unmanifested); C is complete
 */
void MAILTOOL_StartWordInput(struct MailToolProc *proc, struct MailArgs *args)
{
    struct MailDraft *draft = proc->draft;
    u32 k = draft->selectedSlot;
    if (k == 3) {
        PMSI_PARAM_ClearSentence(&proc->sentence);
        proc->sentence.sentenceType = 6;
        proc->sentence.sentenceId = 0;
        proc->sentence.word[0] = proc->draft->messageId;
        proc->pmsiParam = PMSI_PARAM_Create(0, 0, 0, 1, args->saveControl, proc->heapId);
        PMSI_PARAM_SetWord(proc->pmsiParam, proc->draft->messageId);
    } else if (draft->slotEnabled[k] == 1) {
        PMSI_PARAM_Copy(&proc->sentence, &draft->message[k]);
        proc->pmsiParam = PMSI_PARAM_Create(2, 0, &proc->sentence, 1, args->saveControl, proc->heapId);
    } else {
        proc->pmsiParam = PMSI_PARAM_Create(2, 0, 0, 1, args->saveControl, proc->heapId);
        if (PMSI_PARAM_IsEnabled(&proc->draft->message[proc->draft->selectedSlot]))
            PMSI_PARAM_Copy(&proc->sentence, &proc->draft->message[proc->draft->selectedSlot]);
        else
            PMSI_PARAM_InitSentence(&proc->sentence, 0);
        PMSI_PARAM_SetSentence(proc->pmsiParam, &proc->sentence);
    }
}
