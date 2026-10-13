/*
 * file:     plist_message.c
 * unit:     yes
 * function: func_021BB594, func_021BB5FC, func_021BB644, func_021BB714, func_021BB7A4, func_021BB7D8, func_021BB7E8, func_021BB860, func_021BB8FC, func_021BB910, func_021BB97C, func_021BB98C, func_021BB99C, func_021BB9AC, func_021BB9CC, func_021BB9DC, func_021BB9EC, func_021BBA0C, func_021BBA28, func_021BBA54, func_021BBA68, func_021BBA70
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
 *   func_020061E4  0x020061E4  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_020307B0 0x020307B0 arm
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02030734 0x02030734 arm
 *   func_020450F0 0x020450F0 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   TCBL_Create   0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   func_0201C440  0x0201C440  thumb
 *   d_021BED28     0x021BED28  data  ov091  a1
 *   func_0202F038  0x0202F038  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_020310C4 0x020310C4 arm
 *   func_020286C4 0x020286C4 thumb
 *   func_02028484 0x02028484 thumb
 *   APP_KEYCURSOR_Animate 0x0202865C thumb
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02028470  0x02028470  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CD10  0x0201CD10  thumb
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   func_02005F38  0x02005F38  thumb
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   func_02006238  0x02006238  thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201EF4C 0x0201EF4C thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201F140 0x0201F140 thumb
 *   APP_KEYCURSOR_DrawMark 0x02028618 thumb
 *   func_021BB9BC  0x021BB9BC  thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

#include "pokelist_types.h"
#include "plist_message_types.h"

struct MsgData;
struct Bmp;

extern void func_020061E4(u32 id);
extern void func_02041B6C(u32 bit);
extern u32 func_020307B0(void *p);
extern unsigned func_020362DC(void);
extern int func_02035C60(void);
extern struct Strbuf *func_02045EC0(struct MsgData *bank, u32 index);
extern void *func_02045770(struct BmpWin *win);
extern void func_0201C724(struct PrintSys *printSys, void *bitmap, short x, short y, struct Strbuf *text, void *font, u16 flags);
extern void func_02045808(struct Strbuf *text);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *wordSet, struct Strbuf *dst, struct Strbuf *src);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct BmpWin *func_020450F0(int,u8,u8,int,u8,u8,u8);
extern u32 func_020452E8(struct BmpWin *win);
extern u32 func_0201C6C4(struct PrintSys *printSys, void *bitmap);
extern void func_02045334(struct BmpWin *win);
extern void func_02045374(struct BmpWin *win);
extern u8 func_02045730(struct BmpWin *win);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EEF4(struct WordSet *wordSet, u32 index, void *mon);
extern void func_0201EFA4(struct WordSet *wordSet, u32 index, u32 number, u32 digits, u32 c, u32 d);
extern u32 func_0201ED04(struct WordSet *wordSet);
extern void func_0201EE0C(struct WordSet *wordSet, u32 index, const void *src, u32 n, u32 f, u32 c);
extern void func_02043B5C(void *bitmap, u8 value);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern struct KeyCursor *func_02028590(int a, int b, int c, u16 heapId);
extern struct PrintSys *func_0201C440(u32 heapId);
extern void func_0202F038(u8 *prompt);
extern void func_0201CE48(struct TextStream *stream);
extern void func_0201C6EC(struct PrintSys *printSys);
extern void func_0201C4C0(struct PrintSys *printSys);
extern int func_02028604(struct KeyCursor *keyCursor);
extern void func_02031140(struct Tcbl *taskList);
extern void func_020310C4(struct Tcbl *taskList);
extern void func_020286C4(struct KeyCursor *keyCursor, struct TextStream *stream, struct BmpWin *win);
extern s32 func_02028484(u8 *wait, struct TextStream *stream);
extern void APP_KEYCURSOR_Animate(struct KeyCursor *keyCursor, const struct Bmp *bmp, u32 color);
extern u8 *func_0202EE8C(struct Tcbl *taskList, struct BmpWin *win, u8 c, u8 d, u16 heapId);
extern u32 func_0201C4E4(struct PrintSys *printSys);
extern void func_0201F73C(struct BmpWin *win, int a1, int a2, int a3);
extern void func_0201F7A8(struct BmpWin *win, u32 kind);
extern void func_02028470(u8 *wait, u32 v);
extern signed char func_02012FFC(void);
extern struct TextStream *func_0201CD10(struct BmpWin *win, short x, short y, struct Strbuf *text, void *font, s32 a5, struct Tcbl *taskList, u32 a7, u32 heapId, u16 a9, int (*callback)(int));
extern void GFL_USE_SetBgmPlayerParam(int param);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int a, int b);
extern int func_02005F38(void);
extern int GFL_USE_PopBgm(void);
extern int func_02006238(void);
extern void func_0201EF40(struct WordSet *wordSet, u32 index, u32 v);
extern void func_0201EF4C(struct WordSet *wordSet, u32 index, u32 v);
extern void func_0201EF34(struct WordSet *wordSet, u32 index, u32 v);
extern void func_0201F140(struct WordSet *wordSet, u32 index, u32 v);
extern void APP_KEYCURSOR_DrawMark(struct KeyCursor *keyCursor, const struct Bmp *bmp, u32 color);
extern const char d_021BED28[];

PlistMessage *func_021BB594(PokelistWork *work);
void func_021BB5FC(PokelistWork *work, PlistMessage *msg);
void func_021BB644(PokelistWork *work, PlistMessage *msg);
void func_021BB714(PokelistWork *work, PlistMessage *msg, u32 kind);
void func_021BB7A4(PokelistWork *work, PlistMessage *msg);
int func_021BB7D8(PokelistWork *work, PlistMessage *msg);
void func_021BB7E8(PokelistWork *work, PlistMessage *msg, u32 messageId);
void func_021BB860(PokelistWork *work, PlistMessage *msg, u32 messageId, u32 waitForKey);
int func_021BB8FC(PokelistWork *work, PlistMessage *msg);
int func_021BB910(int command);
void func_021BB97C(PokelistWork *work, PlistMessage *msg);
void func_021BB98C(PokelistWork *work, PlistMessage *msg);
void func_021BB99C(int unused, PlistMessage *msg, u32 index, void *mon);
void func_021BB9AC(int unused, PlistMessage *msg, u32 index, u32 itemId);
void func_021BB9BC(int unused, PlistMessage *msg, u32 index, u32 itemId);
void func_021BB9CC(int unused, PlistMessage *msg, u32 index, u32 moveId);
void func_021BB9DC(int unused, PlistMessage *msg, u32 index, u32 value);
void func_021BB9EC(int unused, PlistMessage *msg, u32 index, int number, unsigned char digits);
void func_021BBA0C(int unused, PlistMessage *msg, u32 index, const void *src, int n);
void func_021BBA28(PokelistWork *work, PlistMessage *msg);
void func_021BBA54(PokelistWork *work, u32 unused);
void func_021BBA68(PokelistWork *work, PlistMessage *msg);
void func_021BBA70(int unused, PlistMessage *msg);

PlistMessage *func_021BB594(PokelistWork *work)
{
    PlistMessage *msg;

    msg = func_02030734(work->heapId, sizeof(PlistMessage), 0, d_021BED28, 0x64);
    func_0201F5BC(0, 1, 0xc, 0, work->heapId);
    msg->taskList = TCBL_Create(work->heapId, work->heapId, 1, 0);
    msg->stream = 0;
    msg->windowKind = PLIST_MESSAGE_KIND_CLOSED;
    msg->printing = 0;
    msg->waitForKey = 0;
    msg->wordSet = 0;
    msg->prompt = 0;
    msg->promptRequested = 0;
    msg->keyCursor = func_02028590(0xf, 1, 1, work->heapId);
    msg->printSys = func_0201C440(work->heapId);
    return msg;
}

void func_021BB5FC(PokelistWork *work, PlistMessage *msg)
{
    if (msg->windowKind != PLIST_MESSAGE_KIND_CLOSED) {
        func_021BB7A4(work, msg);
    }
    if (msg->prompt != 0) {
        func_0202F038(msg->prompt);
    }
    if (msg->stream != 0) {
        func_0201CE48(msg->stream);
        func_02045808(msg->streamText);
    }
    func_0201C6EC(msg->printSys);
    func_0201C4C0(msg->printSys);
    func_02028604(msg->keyCursor);
    func_02031140(msg->taskList);
    func_020307B0(msg);
}

void func_021BB644(PokelistWork *work, PlistMessage *msg)
{
    func_020310C4(msg->taskList);
    if (msg->stream != 0) {
        func_020286C4(msg->keyCursor, msg->stream, msg->window);
        if (func_02028484(msg->streamWait, msg->stream) == 1) {
            if (msg->waitForKey == 0 || (func_020362DC() & 3) != 0 || func_02035C60() == 1) {
                if (msg->waitForKey == 1) func_020061E4(0x547);
                func_0201CE48(msg->stream);
                msg->stream = 0;
                func_02045808(msg->streamText);
            } else {
                APP_KEYCURSOR_Animate(msg->keyCursor, func_02045770(msg->window), 15);
                func_02045334(msg->window);
            }
        }
    }
    if (msg->printing == 1 && func_0201C6C4(msg->printSys, func_02045770(msg->window)) == 0) {
        struct BmpWin *window = msg->window;
        msg->printing = 0;
        func_02045334(window);
        func_02045374(window);
        func_02041B6C(func_02045730(window));
        if (msg->promptRequested == 1) {
            msg->promptRequested = 0;
            msg->prompt = func_0202EE8C(msg->taskList, msg->window, 15, 16, work->heapId);
        }
    }
    func_0201C4E4(msg->printSys);
}

void func_021BB714(PokelistWork *work, PlistMessage *msg, u32 kind)
{
    msg->windowKind = kind;
    switch (kind) {
    case PLIST_MESSAGE_KIND_ONE_LINE:
        msg->window = func_020450F0(0, 1, 0x15, 0x15, 2, 0xe, 1);
        break;
    case PLIST_MESSAGE_KIND_ONE_LINE_SHORT:
        msg->window = func_020450F0(0, 1, 0x15, 0x14, 2, 0xe, 1);
        break;
    case PLIST_MESSAGE_KIND_BOX_NARROW:
        msg->window = func_020450F0(0, 2, 0x13, 0xe, 4, 0xe, 1);
        break;
    case PLIST_MESSAGE_KIND_BOX_WIDE:
        msg->window = func_020450F0(0, 2, 0x13, 0x1c, 4, 0xe, 1);
        break;
    }
    func_0201F73C(msg->window, 1, 1, 0xc);
    func_021BBA28(work, msg);
}

void func_021BB7A4(PokelistWork *work, PlistMessage *msg)
{
    if (msg->windowKind != PLIST_MESSAGE_KIND_CLOSED) {
        if (msg->prompt != 0) {
            func_0202F038(msg->prompt);
            msg->prompt = 0;
        }
        func_0201F7A8(msg->window, 1);
        func_020452E8(msg->window);
        func_0201C6EC(msg->printSys);
        msg->windowKind = PLIST_MESSAGE_KIND_CLOSED;
    }
}

int func_021BB7D8(PokelistWork *work, PlistMessage *msg)
{
    if (msg->windowKind != PLIST_MESSAGE_KIND_CLOSED) return 1;
    return 0;
}

void func_021BB7E8(PokelistWork *work, PlistMessage *msg, u32 messageId)
{
    struct Strbuf *text;
    struct Strbuf *expanded;

    text = func_02045EC0(work->msgBank, messageId);
    if (msg->wordSet != 0) {
        expanded = func_020457B0(0x100, work->heapId);
        func_0201F250(msg->wordSet, expanded, text);
        func_02045808(text);
        text = expanded;
    }
    func_021BBA28(work, msg);
    func_0201C6EC(msg->printSys);
    func_0201C724(msg->printSys, func_02045770(msg->window), 1, 1, text, work->fontMain, 0x440);
    msg->printing = 1;
    func_02045808(text);
}

void func_021BB860(PokelistWork *work, PlistMessage *msg, u32 messageId, u32 waitForKey)
{
    struct Strbuf *text;
    struct Strbuf *expanded;

    text = func_02045EC0(work->msgBank, messageId);
    if (msg->wordSet != 0) {
        expanded = func_020457B0(0x100, work->heapId);
        func_0201F250(msg->wordSet, expanded, text);
        func_02045808(text);
        text = expanded;
    }
    func_021BBA28(work, msg);
    if (msg->stream != 0) {
        func_0201CE48(msg->stream);
        func_02045808(msg->streamText);
    }
    msg->waitForKey = waitForKey;
    msg->streamText = text;
    func_02028470(msg->streamWait, 6);
    msg->stream = func_0201CD10(msg->window, 0, 0, msg->streamText, work->fontMain, func_02012FFC(), msg->taskList, 0,
                                work->heapId, 0xf, func_021BB910);
}

int func_021BB8FC(PokelistWork *work, PlistMessage *msg)
{
    if (msg->stream == 0 && msg->printing == 0) return 1;
    return 0;
}

int func_021BB910(int command)
{
    switch (command) {
    case 2:
        GFL_USE_SetBgmPlayerParam(1);
        GFL_USE_PushBgm();
        GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        break;
    case 3:
        func_020061E4(0x56b);
        break;
    case 5:
        if (func_02005F38() == 0) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPlayerParam(0);
            return 0;
        }
        return 1;
    case 6:
        return func_02006238();
    }
    return 0;
}

void func_021BB97C(PokelistWork *work, PlistMessage *msg) { msg->wordSet = func_0201EC64(work->heapId); }

void func_021BB98C(PokelistWork *work, PlistMessage *msg) { func_0201ED04(msg->wordSet); msg->wordSet = 0; }

void func_021BB99C(int unused, PlistMessage *msg, u32 index, void *mon) { func_0201EEF4(msg->wordSet, index, mon); }

void func_021BB9AC(int unused, PlistMessage *msg, u32 index, u32 itemId) { func_0201EF40(msg->wordSet, index, itemId); }

void func_021BB9BC(int unused, PlistMessage *msg, u32 index, u32 itemId) { func_0201EF4C(msg->wordSet, index, itemId); }

void func_021BB9CC(int unused, PlistMessage *msg, u32 index, u32 moveId) { func_0201EF34(msg->wordSet, index, moveId); }

void func_021BB9DC(int unused, PlistMessage *msg, u32 index, u32 value) { func_0201F140(msg->wordSet, index, (unsigned char)value); }

void func_021BB9EC(int unused, PlistMessage *msg, u32 index, int number, unsigned char digits) { func_0201EFA4(msg->wordSet, index, number, digits, 0, 1); }

void func_021BBA0C(int unused, PlistMessage *msg, u32 index, const void *src, int n) { func_0201EE0C(msg->wordSet, index, src, n, 1, 2); }

void func_021BBA28(PokelistWork *work, PlistMessage *msg)
{
    struct BmpWin *window;

    func_02043B5C(func_02045770(msg->window), 15);
    window = msg->window;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
}

void func_021BBA54(PokelistWork *work, u32 unused) { func_0201F5BC(0, 1, 12, 0, work->heapId); }

/*
 * Unlabelled store-and-return leaf (listed as .word at 0x021BBA68) called
 * from func_021B68F0 with (work, work->messageWindow).
 */
void func_021BBA68(PokelistWork *work, PlistMessage *msg)
{
    msg->promptRequested = 1;
}

void func_021BBA70(int unused, PlistMessage *msg)
{
    APP_KEYCURSOR_DrawMark(msg->keyCursor, func_02045770(msg->window), 15);
    func_02045334(msg->window);
}
