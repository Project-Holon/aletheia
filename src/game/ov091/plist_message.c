/*
 * file:     plist_message.c
 * unit:     yes
 * function: PLIST_MESSAGE_Create, PLIST_MESSAGE_Destroy, PLIST_MESSAGE_Update, PLIST_MESSAGE_OpenWindow, PLIST_MESSAGE_CloseWindow, PLIST_MESSAGE_IsWindowOpen, PLIST_MESSAGE_PrintText, PLIST_MESSAGE_StartStream, PLIST_MESSAGE_IsIdle, PLIST_MESSAGE_StreamCallback, PLIST_MESSAGE_CreateWordSet, PLIST_MESSAGE_DestroyWordSet, PLIST_MESSAGE_SetWordSetPokemon, PLIST_MESSAGE_SetWordSetItem, PLIST_MESSAGE_SetWordSetItemAlt, PLIST_MESSAGE_SetWordSetMove, PLIST_MESSAGE_SetWordSetValue, PLIST_MESSAGE_SetWordSetNumber, PLIST_MESSAGE_SetWordSetString, PLIST_MESSAGE_RedrawWindow, PLIST_MESSAGE_LoadWindowFrame, PLIST_MESSAGE_RequestPrompt, PLIST_MESSAGE_DrawKeyCursorMark
 * address:  0x021BB594
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   TCBL_Create   0x0203101C  arm
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   sPlistMessageAllocSite     0x021BED28  data  ov091  a1
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   APP_KEYCURSOR_Delete  0x02028604  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   TCBL_Main 0x020310C4 arm
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_CTRL_Update 0x02028484 thumb
 *   APP_KEYCURSOR_Animate 0x0202865C thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   PRINTSYS_CTRL_Init  0x02028470  thumb
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStreamCallBack  0x0201CD10  thumb
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_IsAnySeBusy  0x02006238  thumb
 *   WORDSET_SetSlotFromMsg36 0x0201EF40 thumb
 *   WORDSET_SetSlotFromMsg117 0x0201EF4C thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   WORDSET_SetSlotFromMsgB4 0x0201F140 thumb
 *   APP_KEYCURSOR_DrawMark 0x02028618 thumb
 *   PLIST_MESSAGE_SetWordSetItemAlt  0x021BB9BC  thumb
 */
#include "../types.h"

#include "pokelist_types.h"
#include "plist_message_types.h"

struct MsgData;
struct Bmp;

#include "../arm9/gfl_use.h"
#include "../arm9/bg_sys.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/key.h"
#include "../arm9/touchpanel.h"
struct MsgBank;
struct Strbuf;
#include "../arm9/msgdata.h"
struct BmpWin;
#include "../arm9/bmp_win.h"
struct GfFont;
struct PrintQueue;
#ifdef __MWERKS__
#define PRINTSYS_PrintStreamCallBack PRINTSYS_PrintStreamCallBack_hdr
#endif
#include "../arm9/printsys.h"
#ifdef __MWERKS__
#undef PRINTSYS_PrintStreamCallBack
/* original prototype: the DS code passes an int callback; the SDK header takes u8 (*)(u32) */
extern struct TextPrinter *PRINTSYS_PrintStreamCallBack(struct BmpWin *win, short x, short y, struct Strbuf *str, struct GfFont *font, int wait, struct Tcbl *tcbl, unsigned int priority, unsigned int heap, unsigned short fillColor, int (*callback)(int));
#else
struct TextPrinter *PRINTSYS_PrintStreamCallBack(struct BmpWin *win, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, s32 wait, struct Tcbl *tcbl, u32 priority, u32 heap, u16 fillColor, u8 (*callback)(u32 arg));
#endif
#include "../arm9/strbuf.h"
#include "../arm9/wordset.h"
struct PrintQueue;
#include "../arm9/gf_font.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/bmp_menuwork.h"
struct TcblSystem;
#include "../arm9/tcbl.h"
struct KeyCursor;
#include "../arm9/app_keycursor.h"
struct TimeIcon;
#include "../arm9/time_icon.h"
struct TextPrinter;
struct PrintStreamCtrl;
struct TcblList;
#include "../arm9/msg_speed.h"
struct Tcbl;
extern const char sPlistMessageAllocSite[];

PlistMessage *PLIST_MESSAGE_Create(PokelistWork *work);
void PLIST_MESSAGE_Destroy(PokelistWork *work, PlistMessage *msg);
void PLIST_MESSAGE_Update(PokelistWork *work, PlistMessage *msg);
void PLIST_MESSAGE_OpenWindow(PokelistWork *work, PlistMessage *msg, u32 kind);
void PLIST_MESSAGE_CloseWindow(PokelistWork *work, PlistMessage *msg);
int PLIST_MESSAGE_IsWindowOpen(PokelistWork *work, PlistMessage *msg);
void PLIST_MESSAGE_PrintText(PokelistWork *work, PlistMessage *msg, u32 messageId);
void PLIST_MESSAGE_StartStream(PokelistWork *work, PlistMessage *msg, u32 messageId, u32 waitForKey);
int PLIST_MESSAGE_IsIdle(PokelistWork *work, PlistMessage *msg);
PlistStreamCbRet PLIST_MESSAGE_StreamCallback(PlistStreamCbArg command);
void PLIST_MESSAGE_CreateWordSet(PokelistWork *work, PlistMessage *msg);
void PLIST_MESSAGE_DestroyWordSet(PokelistWork *work, PlistMessage *msg);
struct PokelistWork;
void PLIST_MESSAGE_SetWordSetPokemon(struct PokelistWork *unused, PlistMessage *msg, u32 index, void *mon);
struct PokelistWork;
void PLIST_MESSAGE_SetWordSetItem(struct PokelistWork *unused, PlistMessage *msg, u32 index, u32 itemId);
void PLIST_MESSAGE_SetWordSetItemAlt(struct PokelistWork *unused, PlistMessage *msg, u32 index, u32 itemId);
void PLIST_MESSAGE_SetWordSetMove(struct PokelistWork *unused, PlistMessage *msg, u32 index, u32 moveId);
void PLIST_MESSAGE_SetWordSetValue(struct PokelistWork *unused, PlistMessage *msg, u32 index, u32 value);
void PLIST_MESSAGE_SetWordSetNumber(struct PokelistWork *unused, PlistMessage *msg, u32 index, int number, unsigned char digits);
void PLIST_MESSAGE_SetWordSetString(struct PokelistWork *unused, PlistMessage *msg, u32 index, const void *src, int n);
void PLIST_MESSAGE_RedrawWindow(PokelistWork *work, PlistMessage *msg);
void PLIST_MESSAGE_LoadWindowFrame(PokelistWork *work, struct PlistMessage *unused);
void PLIST_MESSAGE_RequestPrompt(PokelistWork *work, PlistMessage *msg);
struct PokelistWork;
void PLIST_MESSAGE_DrawKeyCursorMark(struct PokelistWork *unused, PlistMessage *msg);

PlistMessage *PLIST_MESSAGE_Create(PokelistWork *work)
{
    PlistMessage *msg;

    msg = GFL_HEAP_Alloc(work->heapId, sizeof(PlistMessage), 0, sPlistMessageAllocSite, 0x64);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 0xc, 0, work->heapId);
    msg->taskList = (struct Tcbl *)TCBL_Create(work->heapId, work->heapId, 1, 0);
    msg->stream = 0;
    msg->windowKind = PLIST_MESSAGE_KIND_CLOSED;
    msg->printing = 0;
    msg->waitForKey = 0;
    msg->wordSet = 0;
    msg->prompt = 0;
    msg->promptRequested = 0;
    msg->keyCursor = APP_KEYCURSOR_CreateDefault(0xf, 1, 1, work->heapId);
    msg->printSys = (struct PrintSys *)PRINTSYS_QUE_Create(work->heapId);
    return msg;
}

void PLIST_MESSAGE_Destroy(PokelistWork *work, PlistMessage *msg)
{
    if (msg->windowKind != PLIST_MESSAGE_KIND_CLOSED) {
        PLIST_MESSAGE_CloseWindow(work, msg);
    }
    if (msg->prompt != 0) {
        TIME_ICON_Delete((struct TimeIcon *)msg->prompt);
    }
    if (msg->stream != 0) {
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)msg->stream);
        STRBUF_Delete(msg->streamText);
    }
    PRINTSYS_QUE_Clear((struct PrintQueue *)msg->printSys);
    PRINTSYS_QUE_Delete((struct PrintQueue *)msg->printSys);
    APP_KEYCURSOR_Delete(msg->keyCursor);
    TCBL_Destroy((struct TcblSystem *)msg->taskList);
    GFL_HEAP_Free(msg);
}

void PLIST_MESSAGE_Update(PokelistWork *work, PlistMessage *msg)
{
    TCBL_Main((struct TcblSystem *)msg->taskList);
    if (msg->stream != 0) {
        APP_KEYCURSOR_Update(msg->keyCursor, (struct TextPrinter *)msg->stream, msg->window);
        if (PRINTSYS_CTRL_Update((struct PrintStreamCtrl *)msg->streamWait, (struct TextPrinter *)msg->stream) == 1) {
            if (msg->waitForKey == 0 || (KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() == 1) {
                if (msg->waitForKey == 1) GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamDelete((struct TextPrinter *)msg->stream);
                msg->stream = 0;
                STRBUF_Delete(msg->streamText);
            } else {
                APP_KEYCURSOR_Animate(msg->keyCursor, BMP_WIN_GetBmp(msg->window), 15);
                BMP_WIN_TransferChars(msg->window);
            }
        }
    }
    if (msg->printing == 1 && PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)msg->printSys, BMP_WIN_GetBmp(msg->window)) == 0) {
        struct BmpWin *window = msg->window;
        msg->printing = 0;
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window));
        if (msg->promptRequested == 1) {
            msg->promptRequested = 0;
            msg->prompt = (u8 *)TIME_ICON_CreateNode((struct TcblList *)msg->taskList, msg->window, 15, 16, work->heapId);
        }
    }
    PRINTSYS_QUE_Main((struct PrintQueue *)msg->printSys);
}

void PLIST_MESSAGE_OpenWindow(PokelistWork *work, PlistMessage *msg, u32 kind)
{
    msg->windowKind = kind;
    switch (kind) {
    case PLIST_MESSAGE_KIND_ONE_LINE:
        msg->window = BMP_WIN_Create(0, 1, 0x15, 0x15, 2, 0xe, 1);
        break;
    case PLIST_MESSAGE_KIND_ONE_LINE_SHORT:
        msg->window = BMP_WIN_Create(0, 1, 0x15, 0x14, 2, 0xe, 1);
        break;
    case PLIST_MESSAGE_KIND_BOX_NARROW:
        msg->window = BMP_WIN_Create(0, 2, 0x13, 0xe, 4, 0xe, 1);
        break;
    case PLIST_MESSAGE_KIND_BOX_WIDE:
        msg->window = BMP_WIN_Create(0, 2, 0x13, 0x1c, 4, 0xe, 1);
        break;
    }
    BMP_MENUWORK_DrawWindow(msg->window, 1, 1, 0xc);
    PLIST_MESSAGE_RedrawWindow(work, msg);
}

void PLIST_MESSAGE_CloseWindow(PokelistWork *work, PlistMessage *msg)
{
    if (msg->windowKind != PLIST_MESSAGE_KIND_CLOSED) {
        if (msg->prompt != 0) {
            TIME_ICON_Delete((struct TimeIcon *)msg->prompt);
            msg->prompt = 0;
        }
        BMP_MENUWORK_DrawWindowBorder(msg->window, 1);
        BMP_WIN_Delete(msg->window);
        PRINTSYS_QUE_Clear((struct PrintQueue *)msg->printSys);
        msg->windowKind = PLIST_MESSAGE_KIND_CLOSED;
    }
}

int PLIST_MESSAGE_IsWindowOpen(PokelistWork *work, PlistMessage *msg)
{
    if (msg->windowKind != PLIST_MESSAGE_KIND_CLOSED) return 1;
    return 0;
}

void PLIST_MESSAGE_PrintText(PokelistWork *work, PlistMessage *msg, u32 messageId)
{
    struct Strbuf *text;
    struct Strbuf *expanded;

    text = MSGDATA_AllocString(work->msgBank, messageId);
    if (msg->wordSet != 0) {
        expanded = STRBUF_Create(0x100, work->heapId);
        WORDSET_CopyTaggedText(msg->wordSet, expanded, text);
        STRBUF_Delete(text);
        text = expanded;
    }
    PLIST_MESSAGE_RedrawWindow(work, msg);
    PRINTSYS_QUE_Clear((struct PrintQueue *)msg->printSys);
    PRINTSYS_PrintQueColor((struct PrintQueue *)msg->printSys, BMP_WIN_GetBmp(msg->window), 1, 1, text, work->fontMain, 0x440);
    msg->printing = 1;
    STRBUF_Delete(text);
}

void PLIST_MESSAGE_StartStream(PokelistWork *work, PlistMessage *msg, u32 messageId, u32 waitForKey)
{
    struct Strbuf *text;
    struct Strbuf *expanded;

    text = MSGDATA_AllocString(work->msgBank, messageId);
    if (msg->wordSet != 0) {
        expanded = STRBUF_Create(0x100, work->heapId);
        WORDSET_CopyTaggedText(msg->wordSet, expanded, text);
        STRBUF_Delete(text);
        text = expanded;
    }
    PLIST_MESSAGE_RedrawWindow(work, msg);
    if (msg->stream != 0) {
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)msg->stream);
        STRBUF_Delete(msg->streamText);
    }
    msg->waitForKey = waitForKey;
    msg->streamText = text;
    PRINTSYS_CTRL_Init((struct PrintStreamCtrl *)msg->streamWait, 6);
    msg->stream = (struct TextStream *)PRINTSYS_PrintStreamCallBack(msg->window, 0, 0, msg->streamText, work->fontMain, MSG_SPEED_GetWait(), msg->taskList, 0,
                                work->heapId, 0xf, PLIST_MESSAGE_StreamCallback);
}

int PLIST_MESSAGE_IsIdle(PokelistWork *work, PlistMessage *msg)
{
    if (msg->stream == 0 && msg->printing == 0) return 1;
    return 0;
}

PlistStreamCbRet PLIST_MESSAGE_StreamCallback(PlistStreamCbArg command)
{
    switch (command) {
    case 2:
        GFL_USE_SetBgmPaused(1);
        GFL_USE_PushBgm();
        GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        break;
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x56b);
        break;
    case 5:
        if (GFL_USE_IsBgmPlaying() == 0) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPaused(0);
            return 0;
        }
        return 1;
    case 6:
        return GFL_USE_IsAnySeBusy();
    }
    return 0;
}

void PLIST_MESSAGE_CreateWordSet(PokelistWork *work, PlistMessage *msg) { msg->wordSet = WORDSET_CreateDefault(work->heapId); }

void PLIST_MESSAGE_DestroyWordSet(PokelistWork *work, PlistMessage *msg) { WORDSET_Delete(msg->wordSet); msg->wordSet = 0; }

void PLIST_MESSAGE_SetWordSetPokemon(struct PokelistWork *unused, PlistMessage *msg, u32 index, void *mon) { WORDSET_SetSlotMonNickname(msg->wordSet, index, mon); }

void PLIST_MESSAGE_SetWordSetItem(struct PokelistWork *unused, PlistMessage *msg, u32 index, u32 itemId) { WORDSET_SetSlotFromMsg36(msg->wordSet, index, itemId); }

void PLIST_MESSAGE_SetWordSetItemAlt(struct PokelistWork *unused, PlistMessage *msg, u32 index, u32 itemId) { WORDSET_SetSlotFromMsg117(msg->wordSet, index, itemId); }

void PLIST_MESSAGE_SetWordSetMove(struct PokelistWork *unused, PlistMessage *msg, u32 index, u32 moveId) { WORDSET_SetSlotFromMsgCB(msg->wordSet, index, moveId); }

void PLIST_MESSAGE_SetWordSetValue(struct PokelistWork *unused, PlistMessage *msg, u32 index, u32 value) { WORDSET_SetSlotFromMsgB4(msg->wordSet, index, (unsigned char)value); }

void PLIST_MESSAGE_SetWordSetNumber(struct PokelistWork *unused, PlistMessage *msg, u32 index, int number, unsigned char digits) { WORDSET_SetSlotNumber(msg->wordSet, index, number, digits, 0, 1); }

void PLIST_MESSAGE_SetWordSetString(struct PokelistWork *unused, PlistMessage *msg, u32 index, const void *src, int n) { WORDSET_SetSlotTag(msg->wordSet, index, (struct Strbuf *)src, n, 1, 2); }

void PLIST_MESSAGE_RedrawWindow(PokelistWork *work, PlistMessage *msg)
{
    struct BmpWin *window;

    BMP_Clear(BMP_WIN_GetBmp(msg->window), 15);
    window = msg->window;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window));
}

void PLIST_MESSAGE_LoadWindowFrame(PokelistWork *work, struct PlistMessage *unused) { BMP_MENUWORK_LoadCharAndPltt(0, 1, 12, 0, work->heapId); }

/*
 * Unlabelled store-and-return leaf (listed as .word at 0x021BBA68) called
 * from POKELIST_UpdatePhase with (work, work->messageWindow).
 */
void PLIST_MESSAGE_RequestPrompt(PokelistWork *work, PlistMessage *msg)
{
    msg->promptRequested = 1;
}

void PLIST_MESSAGE_DrawKeyCursorMark(struct PokelistWork *unused, PlistMessage *msg)
{
    APP_KEYCURSOR_DrawMark(msg->keyCursor, BMP_WIN_GetBmp(msg->window), 15);
    BMP_WIN_TransferChars(msg->window);
}
