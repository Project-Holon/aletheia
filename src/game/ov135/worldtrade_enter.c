/*
 * file:     worldtrade_enter.c
 * unit:     yes
 * function: WORLDTRADE_ENTER_ClearFlags, WORLDTRADE_ENTER_GetListRange, WORLDTRADE_ENTER_CreateListMenu, WORLDTRADE_ENTER_UpdateListMenu, WORLDTRADE_ENTER_ClearListRange, WORLDTRADE_ENTER_SetListRangeEntry, WORLDTRADE_ENTER_Init, WORLDTRADE_ENTER_CallStateHandler, WORLDTRADE_ENTER_Exit, WORLDTRADE_ENTER_EmptyInitHook, WORLDTRADE_ENTER_EmptyExitHook, WORLDTRADE_ENTER_SetState, WORLDTRADE_ENTER_StateStartServerCheck, WORLDTRADE_ENTER_StatePollServerCheck, WORLDTRADE_ENTER_InitDwcTrade, WORLDTRADE_ENTER_StateStartConnect, WORLDTRADE_ENTER_WaitServerCheck, WORLDTRADE_ENTER_SendProfile, WORLDTRADE_ENTER_WaitProfileResult, WORLDTRADE_ENTER_PushWifiSetup, WORLDTRADE_ENTER_StateWaitWifiSetup, WORLDTRADE_ENTER_PushWifiError, WORLDTRADE_ENTER_StateWaitWifiError, WORLDTRADE_ENTER_RunDialog, WORLDTRADE_ENTER_StateAbortConnect, WORLDTRADE_ENTER_StateExit, WORLDTRADE_ENTER_ShowErrorMessage, WORLDTRADE_ENTER_ShutdownDwcStep, WORLDTRADE_INPUT_PrintStringTop, WORLDTRADE_INPUT_PrintStringPlain, WORLDTRADE_INPUT_PrintBankString, WORLDTRADE_INPUT_PrintStringAligned, WORLDTRADE_INPUT_PrintStringAlignedLine, WORLDTRADE_INPUT_PrintStringAlignedWrapped, WORLDTRADE_INPUT_PrintCentered, WORLDTRADE_ENTER_RestartNetTimeout, ov135_func_021F9260
 * address:  0x021F88B0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from worldtrade_box.c, worldtrade_enter.c, worldtrade_adapter.c, WORLDTRADE_ADAPTER_QueueMessagePrint.c by tools/splitfile.py.
 *
 * symbols:
 *   DPW_TR_Main 0x021C7C1C arm ov114
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   WORLDTRADE_ENTER_RestartNetTimeout 0x021F9254 thumb ov135
 *   WORLDTRADE_INPUT_PrintStringAlignedLine  0x021F91A0  thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor  0x02202858  thumb  ov135
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   PROCSYS_Push  0x02031348  arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   WORLDTRADE_ENTER_ClearListRange 0x021F8990 thumb ov135
 *   WORLDTRADE_ENTER_UpdateListMenu 0x021F8950 thumb ov135
 *   WORLDTRADE_ENTER_SetListRangeEntry 0x021F89A8 thumb ov135
 *   WORLDTRADE_ADAPTER_PrintQueColor  0x022028C8  thumb
 *   BMP_MENUWORK_Create  0x0201F81C  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   d_022030E8 0x022030E8 data a2
 *   tbl_02202F0C  0x02202F0C  data
 *   tbl_022030E8 0x022030E8 data a2
 *   WORLDTRADE_ExitPlanes 0x021F50EC thumb ov135
 *   d_02203C1C 0x02203C1C data a4
 *   WORLDTRADE_ClearAndShowPlanes  0x021F5074  thumb  ov135
 *   WORLDTRADE_ClearBusyFlag  0x021F4EC8  thumb  ov135
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   DWC_NASLoginAsync  0x02168064  arm
 *   DWC_NASLoginProcess 0x02168124 arm ov009
 *   MYSTATUS_SetProfileIdOnce 0x02008540 thumb
 *   MYSTATUS_GetProfileId 0x0200853C thumb
 *   DWC_CreateFriendKey 0x0205994C arm
 *   DPW_TR_Init 0x021C7BA0 arm ov114
 *   WORLDTRADE_CancelSave  0x021F513C  thumb  ov135
 *   WORLDTRADE_DeleteTimeIcon  0x021F4FC4  thumb  ov135
 *   DPW_TR_IsAsyncEnd  0x021C866C  arm
 *   DPW_TR_GetAsyncResult  0x021C86A8  arm
 *   NHTTP_RAP_InitTrainerInfo 0x021B9B00 thumb ov114
 *   DPW_TR_SetProfileAsync 0x021C8E18 arm ov114
 *   str_02203C34 0x02203C34 data a1
 *   gNetSaveMainProc 0x021D6338 data ov115 a4
 *   ov115_id 0x00000073 data
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 *   tbl_021D654C 0x021D654C data ov115 a4
 *   WIFILOGIN_MSG_DrawWindow 0x021D5B5C thumb ov115
 *   WIFILOGIN_MSG_IsPrintDone 0x021D5C70 thumb ov115
 *   DPW_TR_End 0x021C8658 arm ov114
 *   DWC_ShutdownFriendsMatch 0x0216AD50 arm ov009
 *   DWC_CleanupInet 0x0205CC20 arm
 *   WORLDTRADE_ADAPTER_StartPrintStream 0x02202878 thumb ov135
 *   WORLDTRADE_ADAPTER_StrObjThunk 0x022026C4 thumb ov135
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   tbl_022031EC   0x022031EC  data
 *   BG_SYS_Init  0x02040C14  arm
 *   data_02203200  0x02203200  data
 *   data_02203206  0x02203206  data
 *   data_0220322A  0x0220322A  data
 *   data_02203242  0x02203242  data
 *   data_022032AE  0x022032AE  data
 *   BMP_MENULIST_Main  0x020200CC  thumb  arm9
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 *   WORLDTRADE_ENTER_CreateListMenu 0x021F8908 thumb ov135
 *   WORLDTRADE_ENTER_GetListRange  0x021F88D8  thumb  ov135
 *   WORLDTRADE_INPUT_PrintStringAlignedWrapped  0x021F91DC  thumb
 *   WORLDTRADE_ENTER_ClearFlags 0x021F88B0 thumb ov135
 *   WORLDTRADE_INPUT_PrintCentered  0x021F9218  thumb
 *   WORLDTRADE_INPUT_PrintStringPlain  0x021F90A0  thumb
 *   WORLDTRADE_INPUT_PrintStringTop  0x021F9088  thumb  ov135
 *   WIFILIST_GetGsProfileId  0x02009CC0  thumb  arm9
 *   WIFILIST_GetWork  0x02009860  thumb  arm9
 *   BMP_MENULIST_GetListIndex  0x020202EC  thumb  arm9
 */
#include "worldtrade_types.h"

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void *ICA_ANIME_GetField1C(const struct Ctx *p);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern u32 WORLDTRADE_ADAPTER_QueuePrintDefaultColor(void *p, u8 b, void *s, u32 x, u32 y, void *out);

struct Sub020097BCObj;

struct DWCstAccUserData;

typedef struct {
    u8 start;
    u8 id;
} IdRange;

typedef unsigned long long u64;


extern void *BMP_MENUWORK_Create(u32 n, u32 heap);

extern s32 BMP_MENULIST_Main(struct Obj *o);

extern void BMP_MENULIST_GetListIndex(struct Obj *obj, u16 *out);

extern void GFL_USE_PlaySeDefaultVolume(u32 id);

extern void WORLDTRADE_ExitPlanes(Work *);

extern void WORLDTRADE_ClearAndShowPlanes(Work *p);

extern void WORLDTRADE_ClearBusyFlag(Work *p);

extern void GFL_USE_CancelChangeAndPlayBgm(u32 a, u32 b);

extern void WORLDTRADE_SetStateAndReturn(Work *p, u32 a, u32 b);

extern void DWC_NASLoginAsync(void);

extern int DWC_NASLoginProcess(void);

extern struct Sub020097BCObj *WIFILIST_GetWork(struct Sub020097BCObj *obj);

extern int WIFILIST_GetGsProfileId(void *a0);

extern void MYSTATUS_SetProfileIdOnce(struct Sub0200852CObj *obj, u32 value);

extern u32 MYSTATUS_GetProfileId(const struct Sub0200852CObj *obj);

extern unsigned long long DWC_CreateFriendKey(struct DWCstAccUserData *userdata);

extern void DPW_TR_Init(u32 a, u32 b, u32 c, int d);

extern void func_021C8DA0(u8 *p);

extern void *DPW_TR_Main();

extern u32 DPW_TR_IsAsyncEnd();

extern s32 DPW_TR_GetAsyncResult(void);

extern void WORLDTRADE_CancelSave(Work *p);

extern void WORLDTRADE_DeleteTimeIcon(Work *p);

extern void NHTTP_RAP_InitTrainerInfo(u8 *buf, void *myStatus);

extern void DPW_TR_SetProfileAsync(u8 *,u32);

extern void MI_CpuFill8(void *p, u32 value, u32 size);

extern void PROCSYS_Push(void *h, u32 id, const void *a, void *b);

extern u32 GFL_NET_ERR_ShowScreen(u32 a0);

extern void DPW_TR_End();

extern void WIFILOGIN_MSG_DrawWindow(char *p, struct MsgBank *a, int b);

extern int WIFILOGIN_MSG_IsPrintDone(u8 *p);

extern void DWC_ShutdownFriendsMatch(void);

extern void DWC_CleanupInet(void);

extern void BMP_MENUWORK_DrawWindow(void *, int, int, int);

extern void WORLDTRADE_ADAPTER_StartPrintStream(void *a, unsigned b, unsigned c, int d, int e, PrintStreamCtx *p);

extern int WORLDTRADE_ADAPTER_StrObjThunk(u32 *p, u32 b, u32 a, u32 c);

extern u8 BMP_WIN_GetWidth(struct Descriptor *p);

extern u32 WORLDTRADE_ADAPTER_PrintQueColor(u8 *p, u32 z, u32 b, u32 r, u32 d, u32 z2, u16 f, u32 g);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);


void WORLDTRADE_ENTER_ClearFlags(Work *p,u32 n);

int WORLDTRADE_ENTER_GetListRange(u32 id, u32 *start);

int WORLDTRADE_ENTER_CreateListMenu(void **menu, void *msg, int id);

int WORLDTRADE_ENTER_UpdateListMenu(void *p, u16 *old);

void WORLDTRADE_ENTER_ClearListRange(SelTable *p);

void WORLDTRADE_ENTER_SetListRangeEntry(SelTable *p, int i, u16 a, u16 b);

int WORLDTRADE_ENTER_Init(Work *p);

int WORLDTRADE_ENTER_CallStateHandler(Work *p);

u32 WORLDTRADE_ENTER_Exit(Work *p);

void WORLDTRADE_ENTER_EmptyInitHook(Work *a0);

void WORLDTRADE_ENTER_EmptyExitHook(void);

int WORLDTRADE_ENTER_SetState(Work *p);

int WORLDTRADE_ENTER_StateStartServerCheck(Work *a0);

int WORLDTRADE_ENTER_StatePollServerCheck(Work *a0);

int WORLDTRADE_ENTER_InitDwcTrade(Work *p);

int WORLDTRADE_ENTER_StateStartConnect(Work *p);

int WORLDTRADE_ENTER_WaitServerCheck(Work *p);

int WORLDTRADE_ENTER_SendProfile(Work *p);

int WORLDTRADE_ENTER_WaitProfileResult(Work *p);

int WORLDTRADE_ENTER_PushWifiSetup(Work *p);

int WORLDTRADE_ENTER_StateWaitWifiSetup(Work *p);

int WORLDTRADE_ENTER_PushWifiError(Work *p);

int WORLDTRADE_ENTER_StateWaitWifiError(Work *p);

int WORLDTRADE_ENTER_RunDialog(void *dialog, Work *p);

u32 WORLDTRADE_ENTER_StateAbortConnect(Work *p);

int WORLDTRADE_ENTER_StateExit(Work *p);

int WORLDTRADE_ENTER_ShowErrorMessage(Work *p, void *dialog);

int WORLDTRADE_ENTER_ShutdownDwcStep(Work *p, void *dialog);

void WORLDTRADE_INPUT_PrintStringTop(u32 a, u32 b, u32 c, u32 d, u16 e);

void WORLDTRADE_INPUT_PrintStringPlain(u32 a, u32 b, u32 c, u32 d, u16 e);

void WORLDTRADE_INPUT_PrintBankString(Work *p, void *bank, u32 index, int unused1, int unused2, int slow);

int WORLDTRADE_INPUT_PrintStringAligned(void *win, void *str, int x, int align, int unused, int font, void *ctx);

int WORLDTRADE_INPUT_PrintStringAlignedLine(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);

int WORLDTRADE_INPUT_PrintStringAlignedWrapped(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);

void WORLDTRADE_INPUT_PrintCentered(void *win, void *bank, int idx, void *g);

void WORLDTRADE_ENTER_RestartNetTimeout(u8 *a0);

void ov135_func_021F9260(Menu *p, u32 mode);

extern const u16 d_022030E8[];

extern const IdRange tbl_02202F0C[];

extern u16 tbl_022030E8[];

extern const char str_02203C34[], ov115_id[];

extern const u32 gNetSaveMainProc[];

extern u8 tbl_021D654C[];

extern const u32 tbl_022031EC[];

extern const u8 data_02203200[3][2];

extern const u8 data_02203206[4][2];

extern const u8 data_0220322A[4][3];

extern const u8 data_02203242[5][2];

extern const u8 data_022032AE[9][2];

void WORLDTRADE_ENTER_ClearFlags(Work *p,u32 n) { if(n==0){p->fF84=0;return;}n--;if(n<130)p->fF84=d_022030E8[n]; }

int WORLDTRADE_ENTER_GetListRange(u32 id, u32 *start)
{
    int i;

    for (i = 0; i < 28; i++) {
        if (id == tbl_02202F0C[i].id) {
            *start = tbl_02202F0C[i].start;
            return tbl_02202F0C[i + 1].start - tbl_02202F0C[i].start;
        }
    }
    return 0;
}

#pragma opt_common_subs off

/*
 * Builds a message menu: reads the entry range for an id, allocates the table
 * and fills one slot per entry. The slot call takes five arguments (heap id
 * 0x48 on the stack), as in the other matched callers of BMP_MENUWORK_AddMsgItem (the
 * arm9 definition lists four parameters; the fifth is passed but not read).
 * Closed with opt_common_subs off: the original does not share start + i
 * between the table index and the tag. 2026-10-05 (P21): plain form 16 bytes
 * off, only that pragma closes it. Table extern is not const (const gave 18).
 */
int WORLDTRADE_ENTER_CreateListMenu(void **menu, void *msg, int id)
{
    int i;
    int count;
    u32 start;
    count = WORLDTRADE_ENTER_GetListRange(id, &start);
    *menu = BMP_MENUWORK_Create(count, 0x48);
    for (i = 0; (i < count) ? 1 : 0; i++) {
        BMP_MENUWORK_AddMsgItem(*menu, (u32)msg, tbl_022030E8[start + i], start + i + 1, 0x48);
    }
    return count;
}

#pragma opt_common_subs reset

int WORLDTRADE_ENTER_UpdateListMenu(void *p, u16 *old)
{
    u16 current;
    int result;
    result = BMP_MENULIST_Main(p);
    BMP_MENULIST_GetListIndex(p, &current);
    if (*old != current) {
        if (*old != 0xFFFF) GFL_USE_PlaySeDefaultVolume(0x548);
        *old = current;
    }
    return result;
}

/*
 * Clear the two ten-entry u16 tables at +4 and +0x18 and the two header words.
 */
void WORLDTRADE_ENTER_ClearListRange(SelTable *p)
{
    int i;
    u16 zero = 0;

    for (i = 0; i < 10; i++) {
        p->a[i] = zero;
        p->b[i] = zero;
    }
    p->f0 = zero;
    p->f2 = zero;
}

/*
 * Store a pair of u16 values at +4 and +0x18 of record i.
 */
void WORLDTRADE_ENTER_SetListRangeEntry(SelTable *p, int i, u16 a, u16 b)
{
    p->a[i] = a;
    p->b[i] = b;
}

/*
 * volatile: hardware read-modify-write at 021F89C6/021F89CA, 0x04000304.
 */
int WORLDTRADE_ENTER_Init(Work *p) {WORLDTRADE_ExitPlanes(p);WORLDTRADE_ENTER_EmptyInitHook(p);*(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);switch(p->kind){case 19:case 21:p->state=2;break;case 20:p->state=4;break;}return 1;}

extern int (*const d_02203C1C[])(Work *);

int WORLDTRADE_ENTER_CallStateHandler(Work *p) { int prevState,result;prevState=p->state_i;result=d_02203C1C[prevState](p);if(prevState!=p->state_i){p->fF88=0;p->fF8A=0;}return result; }

/*
 * Run the three teardown steps, then report 4 while the +0x10 handle is gone.
 */
u32 WORLDTRADE_ENTER_Exit(Work *p)
{
    WORLDTRADE_ENTER_EmptyExitHook();
    WORLDTRADE_ClearAndShowPlanes(p);
    WORLDTRADE_ClearBusyFlag(p);
    if (p->x10 == 0) {
        return 4;
    }
    return 0;
}

/*
 * Empty stub.
 */
void WORLDTRADE_ENTER_EmptyInitHook(Work *a0)
{
}

void WORLDTRADE_ENTER_EmptyExitHook(void)
{
}

int WORLDTRADE_ENTER_SetState(Work *p)
{
    GFL_USE_CancelChangeAndPlayBgm(0x486, 0xFFFF);
    p->state = 1;
    p->xEB2 = 1;
    p->x30 = 0;
    WORLDTRADE_SetStateAndReturn(p, 1, 0);
    return 2;
}

/*
 * Call DWC_NASLoginAsync and report success.
 */
int WORLDTRADE_ENTER_StateStartServerCheck(Work *a0)
{
    DWC_NASLoginAsync();
    return 1;
}

/*
 * Extent remainder: 2-byte zero alignment padding.
 */
int WORLDTRADE_ENTER_StatePollServerCheck(Work *a0) { switch(DWC_NASLoginProcess()) {case 3:return 1;case 0:case 4:case 5:return 2;default:return 0;} }

/*
 * extent: 0x021F8AF2..0x021F8AF4 is two zero alignment bytes.
 */
int WORLDTRADE_ENTER_InitDwcTrade(Work *p)
{
    void *handle;
    u32 id;
    u64 key;
    handle = WIFILIST_GetWork(p->ctx->wifiList);
    MYSTATUS_SetProfileIdOnce(p->ctx->f1C, WIFILIST_GetGsProfileId(p->ctx->wifiList));
    id = MYSTATUS_GetProfileId(p->ctx->f1C);
    key = DWC_CreateFriendKey(handle);
    DPW_TR_Init(id, (u32)key, (u32)(key >> 32), 0);
    return 1;
}

/*
 * Hand the object over, clear the +0xf8c slot and latch 1.
 */
int WORLDTRADE_ENTER_StateStartConnect(Work *p)
{
    func_021C8DA0((u8 *)p);
    p->timer = 0;
    return 1;
}

/*
 * 18-slot switch on the 0x021C86A8 index (case value = index + 15, bound 17):
 * index 14 returns 1, and four separate case groups (15, 13+16, 0+3, 1+12)
 * each call WORLDTRADE_DeleteTimeIcon and archive n at +0x38 before returning 2; the
 * remaining indexes fall through to the shared tail (one more WORLDTRADE_DeleteTimeIcon)
 * and the function returns 0.  DPW_TR_Main(p) runs first, unconditionally.
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd (0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int WORLDTRADE_ENTER_WaitServerCheck(Work *p)
{
    s32 asyncResult;

    if (DPW_TR_IsAsyncEnd(DPW_TR_Main((u8 *)p)) != 0) {
        asyncResult = DPW_TR_GetAsyncResult();
        p->timer = 0;
        switch (asyncResult + 15) {
        case 15:
            return 1;
        case 16:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = asyncResult;
            return 2;
        case 14:
        case 17:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = asyncResult;
            return 2;
        case 0:
        case 3:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = asyncResult;
            return 2;
        case 1:
        case 13:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = asyncResult;
            return 2;
        }
        WORLDTRADE_DeleteTimeIcon(p);
        WORLDTRADE_CancelSave(p);
    } else {
        if (++p->timer == 0xe10) {
            WORLDTRADE_CancelSave(p);
        }
    }
    return 0;
}

int WORLDTRADE_ENTER_SendProfile(Work *p) { NHTTP_RAP_InitTrainerInfo(p->trInfo,p->ctx->f1C);DPW_TR_SetProfileAsync(p->trInfo,(u32)&p->state_iF7C);p->timer=0;return 1; }

/*
 * note: 2026-10-05 wave P19: the sub switch exit (state 0, sub out of range) is a cross-jumped copy of the tail, `b 0x021F8CEC` in the image. Written as `WORLDTRADE_CancelSave(p); goto done;` after the sub switch, with `done: return 0;` at the end. EXACT in c99 and c (296 bytes). Idiom: a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.
 */
int WORLDTRADE_ENTER_WaitProfileResult(Work *p)
{
    int code;

    DPW_TR_Main();
    if (DPW_TR_IsAsyncEnd() != 0) {
        code = DPW_TR_GetAsyncResult();
        p->wait = 0;
        switch (code) {
        case 0:
            switch (p->state_iF7C) {
            case 0:
                switch (p->sub_i) {
                case 0:
                    WORLDTRADE_SetStateAndReturn(p, 1, 0);
                    return 1;
                case 3:
                    p->err = -5003;
                    return 2;
                case 1:
                    p->err = -5000;
                    return 2;
                case 2:
                    p->err = -5001;
                    return 2;
                }
                WORLDTRADE_CancelSave(p);
                goto done;
            case 1:
                p->err = -5004;
                return 2;
            case 2:
                p->err = -5005;
                return 2;
            default:
                WORLDTRADE_DeleteTimeIcon(p);
                break;
            }
            break;
        case 1:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = code;
            return 2;
        case -1:
        case 2:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = code;
            return 2;
        case -15:
        case -12:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = code;
            return 2;
        case -14:
        case -2:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = code;
            return 2;
        default:
            WORLDTRADE_DeleteTimeIcon(p);
            break;
        }
        WORLDTRADE_CancelSave(p);
    } else if (++p->wait == 0xE10) {
        WORLDTRADE_CancelSave(p);
    }
done:
    return 0;
}

/*
 * lever: ov115 data hint is witnessed by this function loading ov115 via PROCSYS_Push; no hint remains MATCH.
 */
int WORLDTRADE_ENTER_PushWifiSetup(Work *p)
{
    NetSaveProcArgs *args;
    p->saveArgs = GFL_HEAP_Alloc(0x48, sizeof(NetSaveProcArgs), 0, str_02203C34, 0x263);
    MI_CpuFill8(p->saveArgs, 0, sizeof(NetSaveProcArgs));
    args = p->saveArgs;
    args->handle = ICA_ANIME_GetField1C(p->ctx->f40);
    args->mode = 0;
    args->enabled = 1;
    args->buf = p->netBuf;
    args->timeout = 30;
    args->callback = WORLDTRADE_ENTER_RunDialog;
    args->user = p;
    p->f12EC = 0;
    if ((u32)p->kind == 21) args->isTrade = 1;
    else args->isTrade = 0;
    PROCSYS_Push(p->f12F0, (u32)ov115_id, gNetSaveMainProc, p->saveArgs);
    GFL_NET_ERR_ShowScreen(0);
    p->state = 3;
    return 2;
}

int WORLDTRADE_ENTER_StateWaitWifiSetup(Work *p)
{
    NetSaveProcArgs *args = p->saveArgs;
    if (p->busy_u == 0) {
        switch (args->result) {
        case 0: p->state = 0; break;
        case 1:
            WORLDTRADE_SetStateAndReturn(p, 0, 0);
            p->state = 1;
            break;
        }
        GFL_HEAP_Free((void *)p->req);
    }
    return 2;
}

int WORLDTRADE_ENTER_PushWifiError(Work *p)
{
    NetProcArgs *args;
    p->netArgs = GFL_HEAP_Alloc(72, sizeof(NetProcArgs), 0, str_02203C34, 689);
    MI_CpuFill8(p->netArgs, 0, sizeof(NetProcArgs));
    args = p->netArgs;
    args->save = ICA_ANIME_GetField1C(p->ctx->f40);
    args->zero = 0;
    args->enabled = 1;
    args->callback = WORLDTRADE_ENTER_StateAbortConnect;
    args->context = p;
    PROCSYS_Push(p->f12F0, (u32)ov115_id, tbl_021D654C, p->netArgs);
    p->state_i = 5;
    GFL_NET_ERR_ShowScreen(0);
    return 2;
}

int WORLDTRADE_ENTER_StateWaitWifiError(Work *p)
{
    if (p->busy_u == 0) {
        GFL_HEAP_Free(p->req);
        WORLDTRADE_SetStateAndReturn(p, 0, 0);
        p->state = 1;
    }
    return 2;
}

int WORLDTRADE_ENTER_RunDialog(void *dialog, Work *p)
{
    int result;
    switch (p->f12EC) {
    case 0:
        if (WORLDTRADE_ENTER_StateStartServerCheck(p))
            p->f12EC++;
        break;
    case 1:
        result = WORLDTRADE_ENTER_StatePollServerCheck(p);
        switch (result) {
        case 1: p->f12EC++; break;
        case 2: p->f12EC = 9; break;
        }
        break;
    case 2:
        if (WORLDTRADE_ENTER_InitDwcTrade(p)) p->f12EC++;
        break;
    case 3:
        if (WORLDTRADE_ENTER_StateStartConnect(p)) p->f12EC++;
        break;
    case 4:
        result = WORLDTRADE_ENTER_WaitServerCheck(p);
        switch (result) {
        case 1: p->f12EC++; break;
        case 2: p->f12EC = 7; break;
        }
        break;
    case 5:
        if (WORLDTRADE_ENTER_SendProfile(p)) p->f12EC++;
        break;
    case 6:
        result = WORLDTRADE_ENTER_WaitProfileResult(p);
        switch (result) {
        case 1: p->f12EC = 0; return 0;
        case 2: p->f12EC = 7; break;
        }
        break;
    case 7:
        if (WORLDTRADE_ENTER_ShowErrorMessage(p, dialog)) p->f12EC++;
        break;
    case 8:
        if (WORLDTRADE_ENTER_ShutdownDwcStep(p, dialog)) p->f12EC++;
        break;
    case 9:
        p->f12EC = 0;
        return 1;
    }
    return 2;
}

/*
 * Every concrete byte is reproduced.  The one wildcard is the BLX at +0002 to
 * DPW_TR_End, which has no independent witness outside 021F8F5C..021F8F66;
 * the resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Same blocker as WORLDTRADE_SERVER_StateCheckAsyncEnd
 * and WORLDTRADE_SEARCH_StateStartWipeOutDisconnect/WORLDTRADE_SERVER_StateStartWipeOutDisconnect: naming one of those eight regions would be
 * a guess, so the site stays parked until the region that owns 0x021C8658 is
 * established.
 */
u32 WORLDTRADE_ENTER_StateAbortConnect(Work *p)
{
    DPW_TR_End(p);
    return 0;
}

/*
 * Reset the object, latch state 0 and set the +0xeb4 slot to 1.
 */
int WORLDTRADE_ENTER_StateExit(Work *p)
{
    WORLDTRADE_DeleteTimeIcon(p);
    p->state = 0;
    p->eb4 = 1;
    return 3;
}

int WORLDTRADE_ENTER_ShowErrorMessage(Work *p, void *dialog)
{
    int text;
    switch (p->err) {
    case 1: text = 166; break;
    case 2: text = 167; break;
    case -1: text = 157; break;
    case -2: text = 169; break;
    case -3: text = 162; break;
    case -4: text = 164; break;
    case -5: text = 163; break;
    case -6: text = 27; break;
    case -7: text = 28; break;
    case -8: text = 29; break;
    case -9: text = 30; break;
    case -10: text = 31; break;
    case -11: text = 32; break;
    case -12: text = 160; break;
    case -13: text = 165; break;
    case -14: text = 170; break;
    case -15: text = 161; break;
    default: text = 159; break;
    }
    WIFILOGIN_MSG_DrawWindow(dialog, p->bank, text);
    p->fF88 = 0;
    return 1;
}

int WORLDTRADE_ENTER_ShutdownDwcStep(Work *p, void *dialog)
{
    switch (p->fF88) {
    case 0:
        (p->fF88)++;
        break;
    case 1:
        if (WIFILOGIN_MSG_IsPrintDone(dialog)) (p->fF88)++;
        break;
    case 2:
        (p->fF88)++;
        break;
    case 3:
        DPW_TR_End();
        DWC_ShutdownFriendsMatch();
        DWC_CleanupInet();
        (p->fF88)++;
        break;
    default:
        (p->fF8A)++;
        if (p->fF8A > 60) return 1;
        break;
    }
    return 0;
}

/*
 * Forward the u16 stack argument to WORLDTRADE_INPUT_PrintBankString with mode 1.
 */
void WORLDTRADE_INPUT_PrintStringTop(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    WORLDTRADE_INPUT_PrintBankString((Work *)a, (void *)b, c, d, e, 1);
}

/*
 * Forward the u16 stack argument to WORLDTRADE_INPUT_PrintBankString with mode 0.
 */
void WORLDTRADE_INPUT_PrintStringPlain(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    WORLDTRADE_INPUT_PrintBankString((Work *)a, (void *)b, c, d, e, 0);
}

void WORLDTRADE_INPUT_PrintBankString(Work *p, void *bank, u32 index, int unused1, int unused2, int slow)
{
    void *str;
    str = MSGDATA_AllocString(bank, index);
    WORDSET_CopyTaggedText(p->words, p->str, str);
    STRBUF_Delete(str);
    BMP_Clear(BMP_WIN_GetBmp(p->d40), 15);
    BMP_WIN_TransferChars(p->d40);
    BMP_MENUWORK_DrawWindow(p->d40, 0, 1, 14);
    if (slow)
        WORLDTRADE_ADAPTER_StartPrintStream(p->d40, 0, (unsigned int)(p->str), 0, 0, &p->printCtx);
    else
        WORLDTRADE_ADAPTER_QueuePrintDefaultColor(p->d40, 0, p->str, 0, 0, &p->printCtx);
    p->cnt = 0;
}

/*
 * lever: unused fifth argument leaves font and context in stack slots +4/+8.
 */
int WORLDTRADE_INPUT_PrintStringAligned(void *win, void *str, int x, int align, int unused, int font, void *ctx)
{
    int width;
    switch (align) {
    case 1:
        width = WORLDTRADE_ADAPTER_StrObjThunk(ctx, (u8)font, (u32)str, (int)0);
        x = (BMP_WIN_GetWidth(win) * 8 - width) / 2;
        break;
    case 2:
        width = WORLDTRADE_ADAPTER_StrObjThunk(ctx, (u8)font, (u32)str, (int)0);
        x = BMP_WIN_GetWidth(win) * 8 - width;
        break;
    }
    return x;
}

/*
 * Seven-argument wrapper: forwards the object, three words, the 0 and the u16/g pair to the two helpers.
 */
int WORLDTRADE_INPUT_PrintStringAlignedLine(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g)
{
    u32 r = WORLDTRADE_INPUT_PrintStringAligned(p, (void *)b, c, e, f, 0, (void *)g);

    return WORLDTRADE_ADAPTER_PrintQueColor(p, 0, b, r, d, 0, f, g);
}

int WORLDTRADE_INPUT_PrintStringAlignedWrapped(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g)
{
    u32 r = WORLDTRADE_INPUT_PrintStringAligned(p, (void *)b, c, e, f, 0, (void *)g);

    return WORLDTRADE_ADAPTER_PrintQueColor(p, 0, b, r, d, 0, f, g);
}

void WORLDTRADE_INPUT_PrintCentered(void *win, void *bank, int idx, void *g)
{
    void *str;

    str = MSGDATA_AllocString(bank, tbl_022031EC[idx]);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win, (u32)str, 0, 0, 0, 0x440, (u32)g);
    STRBUF_Delete(str);
}

/*
 * Tail call into GFL_NET_RestartWithDefaultTimeout with the fixed 0/0x48 pair.
 */
void WORLDTRADE_ENTER_RestartNetTimeout(u8 *a0)
{
    GFL_NET_RestartWithDefaultTimeout(0, 0x48);
}

void ov135_func_021F9260(Menu *p, u32 mode)
{
    int i;

    BG_SYS_Init(p->layer, 0, 1, 0);
    switch (mode) {
    case 4:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 9; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_022032AE[i][0], data_022032AE[i][1], 3, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[i])), 10);
        }
        break;
    case 5:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[14])), 10);
        p->wins[0] = (void *)BMP_WIN_Create((u8)p->layer, 2, 2, 3, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[0])), 7);
        for (i = 1; i < 4; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_022032AE[i - 1][0], data_022032AE[i - 1][1], 2, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[i])), 10);
        }
        break;
    case 0:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 4; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_0220322A[i][0], data_0220322A[i][1], 8, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[i])), 10);
        }
        p->wins[4] = (void *)BMP_WIN_Create((u8)p->layer, 5, 14, 5, 1, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[4])), 8);
        break;
    case 6:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 9; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_022032AE[i][0], data_022032AE[i][1], 3, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[i])), 10);
        }
        p->wins[15] = (void *)BMP_WIN_Create((u8)p->layer, 1, 2, 9, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[15])), 10);
        break;
    case 3:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 24, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 5; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_02203242[i][0], data_02203242[i][1], 23, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[i])), 10);
        }
        p->wins[5] = (void *)BMP_WIN_Create((u8)p->layer, 14, 16, 5, 1, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[5])), 10);
        break;
    case 1:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 3; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_02203200[i][0], data_02203200[i][1], 9, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[i])), 10);
        }
        break;
    case 2:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 4; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_02203206[i][0], data_02203206[i][1], 11, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[i])), 10);
        }
        p->wins[4] = (void *)BMP_WIN_Create((u8)p->layer, 5, 14, 5, 1, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[4])), 8);
        break;
    }
}
