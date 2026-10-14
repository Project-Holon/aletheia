/*
 * file:     pdc_msg.c
 * unit:     yes
 * function: PDC_MSG_Create, PDC_MSG_Delete, PDC_MSG_PrintMessage0, PDC_MSG_PrintMessage3, PDC_MSG_PrintMessage1, PDC_MSG_PrintMessage2, PDC_MSG_PrintMessage4, PDC_MSG_Update, PDC_MSG_StartFadeIn, PDC_MSG_IsFadeIdle, PDC_MSG_TakeStreamEnded, PDC_MSG_StartPrint, PDC_MSG_InitBlend, PDC_MSG_BlendStartFadeIn, PDC_MSG_BlendStartFadeOut, PDC_MSG_BlendUpdate
 * address:  0x021B67D4
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pdc.c, ov098_func_021B6CDC.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02045B38 0x02045B38 arm
 *   CONFIG_GetTextSpeed 0x02008374 thumb
 *   func_02013080 0x02013080 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02041300 0x02041300 arm
 *   func_02040C14 0x02040C14 arm
 *   func_020496E4 0x020496E4 arm
 *   PALANM_LoadArcPaletteToSlotAt 0x020215EC thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_DrawFrame 0x020454E0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   gPdcMsgSrcName 0x021B6E74 data a4
 *   gPdcMsgBgTemplate 0x021B6E24 data a4
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   func_020403F4 0x020403F4 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   PDC_MSG_BlendUpdate 0x021B6CDC thumb ov098
 *   PRINTSYS_PrintStreamRun 0x0201CE20 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   PRINTSYS_PrintStreamStop  0x0201CE0C  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   func_0207D63C  0x0207D63C  arm
 *   PDC_GetMon 0x021B6140 thumb ov098
 *   PDC_GetMyStatus 0x021B6148 thumb ov098
 */
#include "pdc_types.h"

struct BgTemplate;
struct PalAnmSlot;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int BTLV_EFFECT_GetPalanm(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void func_0203FCA0(u32 layer, const struct BgTemplate *template, u32 mode);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 CONFIG_GetTextSpeed(struct Config *config);
extern signed char func_02013080(u32 textSpeed);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heapId);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02040C14(u32, u32, u32, u32);
extern u32 func_020496E4(u32, u32, u32, u32, u32, u16);
extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *, u32, u32, u32, u32, u32, u16, u16);
extern struct BmpWin *BMP_WIN_Create(u32 layer, u32 x, u32 y, u32 width, u8 height, u8 palette, u8 charBase);
extern void BMP_WIN_MakeScreen(struct BmpWin *window);
extern void BMP_WIN_DrawFrame(struct BmpWin *window, u16 frameIndex, u32 palette);
extern void func_020409B4(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void STRBUF_Delete(struct Strbuf *strbuf);
extern void func_0201ED04(struct WordSet *wordSet);
extern void PRINTSYS_PrintStreamDelete(void *stream);
extern void func_020403F4(int);
extern void MSGDATA_Delete(struct MsgBank *msgBank);
extern void BMP_WIN_Delete(struct BmpWin *window);
extern struct Strbuf *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EEF4(struct WordSet *wordSet, u32 index, struct PokemonParam *mon);
extern void func_0201F02C(struct WordSet *wordSet, u32 index, struct MyStatus *myStatus);
extern void func_0201F250(struct WordSet *wordSet, struct Strbuf *dst, struct Strbuf *src);
extern void PRINTSYS_PrintStreamRun(void *stream);
extern u32 PRINTSYS_PrintStreamGetState(void *stream);
extern void PRINTSYS_PrintStreamReleasePause(void *stream);
extern void func_0201DD68(void);
extern void *BMP_WIN_GetBmp(struct BmpWin *window);
extern void BMP_Clear(void *bmp, u8 color);
extern void BMP_WIN_TransferChars(struct BmpWin *window);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern void *PRINTSYS_PrintStream(struct BmpWin *window, u32 x, u32 y, struct Strbuf *str, struct GfFont *font,
                                  int speed, struct Tcbl *tcbl, u32 unused, u16 heapId, u16 color);
extern void PRINTSYS_PrintStreamStop(void *stream);
extern void PRINTSYS_Print(void *bmp, short x, short y, struct Strbuf *str, struct GfFont *font);
extern void func_0207D63C(int, int, int, int, int);

extern struct PokemonParam *PDC_GetMon(struct PdcArgs *args);
extern struct MyStatus *PDC_GetMyStatus(struct PdcArgs *args);

struct PdcMsg *PDC_MSG_Create(struct GfFont *font, struct Config *config, struct Tcbl *tcbl, u32 heapId);
void PDC_MSG_Delete(struct PdcMsg *msg);
void PDC_MSG_PrintMessage0(struct PdcMsg *msg, struct PdcArgs *args);
void PDC_MSG_PrintMessage3(struct PdcMsg *msg, struct PdcArgs *args);
void PDC_MSG_PrintMessage1(struct PdcMsg *msg, struct PdcArgs *args);
void PDC_MSG_PrintMessage2(struct PdcMsg *msg, struct PdcArgs *args);
void PDC_MSG_PrintMessage4(struct PdcMsg *msg, struct PdcArgs *args);
int PDC_MSG_Update(struct PdcMsg *msg);
void PDC_MSG_StartFadeIn(struct PdcMsg *msg);
int PDC_MSG_IsFadeIdle(struct PdcMsg *msg);
int PDC_MSG_TakeStreamEnded(struct PdcMsg *msg);
void PDC_MSG_StartPrint(struct PdcMsg *msg, int waitFrames);
void PDC_MSG_InitBlend(struct PdcBlend *blend, struct BmpWin *window);
void PDC_MSG_BlendStartFadeIn(struct PdcBlend *blend);
void PDC_MSG_BlendStartFadeOut(struct PdcBlend *blend, int keepText);
int PDC_MSG_BlendUpdate(struct PdcBlend *blend);

extern const char gPdcMsgSrcName[];
extern const struct BgTemplate gPdcMsgBgTemplate;

/*
 * prototype: 02008374's three unused legacy trailing inputs omitted: full getter reads only r0, no forwarding; caller supplies no new values.
 */
struct PdcMsg *PDC_MSG_Create(struct GfFont *font, struct Config *config, struct Tcbl *tcbl, u32 heapId)
{
    struct PdcMsg *msg;
    u32 frameIndex;

    msg = func_02030734(heapId, 0x48, 1, gPdcMsgSrcName, 0x82);
    func_0203FCA0(1, &gPdcMsgBgTemplate, 0);
    msg->heapId = heapId;
    msg->tcbl = tcbl;
    msg->msgBank = func_02045B38(0, 2, 0x56, msg->heapId);
    msg->font = font;
    msg->textSpeed = func_02013080(CONFIG_GetTextSpeed(config));
    msg->strbuf = STRBUF_Create(0x100, heapId);
    msg->wordSet = func_0201EC64(heapId);
    func_02041300(1, 0, 0, 0, 32, 32, 17);
    func_02040C14(1, 0, 1, 0);
    frameIndex = func_020496E4(11, 89, 1, 0, 0, msg->heapId);
    PALANM_LoadArcPaletteToSlotAt((struct PalAnmSlot *)BTLV_EFFECT_GetPalanm(), 11, 90, msg->heapId, 0, 32, 0, 0);
    msg->window = BMP_WIN_Create(1, 1, 19, 30, 4, 0, 0);
    BMP_WIN_MakeScreen(msg->window);
    BMP_WIN_DrawFrame(msg->window, frameIndex, 0);
    func_020409B4(1);
    func_02040588(1, 0);
    PDC_MSG_InitBlend(&msg->blend, msg->window);
    return msg;
}

void PDC_MSG_Delete(struct PdcMsg *msg)
{
    STRBUF_Delete(msg->strbuf);
    func_0201ED04(msg->wordSet);
    if (msg->printStream) PRINTSYS_PrintStreamDelete(msg->printStream);
    func_020403F4(1);
    MSGDATA_Delete(msg->msgBank);
    BMP_WIN_Delete(msg->window);
    func_020307B0(msg);
}

void PDC_MSG_PrintMessage0(struct PdcMsg *msg, struct PdcArgs *args) {
    struct Strbuf *str;
    struct PokemonParam *mon;
    str = func_02045EC0(msg->msgBank, 0);
    mon = PDC_GetMon(args);
    func_0201EEF4(msg->wordSet, 0, mon);
    func_0201F250(msg->wordSet, msg->strbuf, str);
    PDC_MSG_StartPrint(msg, 0x50);
    STRBUF_Delete(str);
}

void PDC_MSG_PrintMessage3(struct PdcMsg *msg, struct PdcArgs *args) {
    struct Strbuf *str;
    struct MyStatus *myStatus;
    str = func_02045EC0(msg->msgBank, 3);
    myStatus = PDC_GetMyStatus(args);
    func_0201F02C(msg->wordSet, 0, myStatus);
    func_0201F250(msg->wordSet, msg->strbuf, str);
    PDC_MSG_StartPrint(msg, 0);
    STRBUF_Delete(str);
}

void PDC_MSG_PrintMessage1(struct PdcMsg *msg, struct PdcArgs *args) {
    struct Strbuf *str;
    struct PokemonParam *mon;
    str = func_02045EC0(msg->msgBank, 1);
    mon = PDC_GetMon(args);
    func_0201EEF4(msg->wordSet, 0, mon);
    func_0201F250(msg->wordSet, msg->strbuf, str);
    PDC_MSG_StartPrint(msg, 0x50);
    STRBUF_Delete(str);
}

void PDC_MSG_PrintMessage2(struct PdcMsg *msg, struct PdcArgs *args) {
    struct Strbuf *str;
    struct PokemonParam *mon;
    str = func_02045EC0(msg->msgBank, 2);
    mon = PDC_GetMon(args);
    func_0201EEF4(msg->wordSet, 0, mon);
    func_0201F250(msg->wordSet, msg->strbuf, str);
    PDC_MSG_StartPrint(msg, 0x50);
    STRBUF_Delete(str);
}

void PDC_MSG_PrintMessage4(struct PdcMsg *msg, struct PdcArgs *args)
{
    struct Strbuf *str;
    struct MyStatus *myStatus;
    str=func_02045EC0(msg->msgBank, 4);
    myStatus=PDC_GetMyStatus(args);
    func_0201F02C(msg->wordSet, 0, myStatus);
    func_0201F250(msg->wordSet, msg->strbuf, str);
    PDC_MSG_StartPrint(msg, 80);
    STRBUF_Delete(str);
}

int PDC_MSG_Update(struct PdcMsg *msg)
{
    switch (msg->state) {
    case PDC_MSG_START:
        PDC_MSG_BlendStartFadeOut(&msg->blend, msg->instant);
        msg->state++;
    case PDC_MSG_WAIT_BLEND:
        if (!PDC_MSG_BlendUpdate(&msg->blend)) break;
        if (msg->instant) {
            msg->state = PDC_MSG_DONE;
            break;
        }
        if (msg->printStream) PRINTSYS_PrintStreamRun(msg->printStream);
        msg->state++;
    case PDC_MSG_WAIT_STREAM:
        if (msg->printStream) {
            msg->streamState = PRINTSYS_PrintStreamGetState(msg->printStream);
            if (msg->streamState) {
                msg->state = PDC_MSG_WAIT_INPUT;
                if (msg->streamState == 2) msg->streamEnded = 1;
            }
        } else return 1;
        break;
    case PDC_MSG_WAIT_INPUT:
        if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg()) msg->waitFrames = 0;
        if (msg->waitFrames) (msg->waitFrames)--;
        else msg->state = PDC_MSG_NEXT_PAGE;
        break;
    case PDC_MSG_WAIT_TIMER:
        if (msg->waitFrames) (msg->waitFrames)--;
        else msg->state = PDC_MSG_NEXT_PAGE;
        break;
    case PDC_MSG_NEXT_PAGE:
        if (msg->streamState == 2) {
            func_0201DD68();
            PRINTSYS_PrintStreamDelete(msg->printStream);
            msg->printStream = 0;
            msg->state = PDC_MSG_DONE;
            return 1;
        } else {
            PRINTSYS_PrintStreamReleasePause(msg->printStream);
            msg->state = PDC_MSG_WAIT_STREAM;
            msg->waitFrames = msg->waitReload;
        }
        break;
    case PDC_MSG_DONE:
        return 1;
    }
    return 0;
}

void PDC_MSG_StartFadeIn(struct PdcMsg *msg)
{
    PDC_MSG_BlendStartFadeIn(&msg->blend);
}

int PDC_MSG_IsFadeIdle(struct PdcMsg *msg)
{
    return PDC_MSG_BlendUpdate(&msg->blend);
}

/*
 * notes:    test and clear flag byte at +0x3a, returns 1 if it was set. Witness for the call in ov098 PDC_MAIN_StepChooseItem (2026-10-05, lane W-B).
 */
int PDC_MSG_TakeStreamEnded(struct PdcMsg *msg)
{
    if (msg->streamEnded) {
        msg->streamEnded = 0;
        return 1;
    }
    return 0;
}

void PDC_MSG_StartPrint(struct PdcMsg *msg, int waitFrames)
{
    BMP_Clear(BMP_WIN_GetBmp(msg->window), 0xc);
    GF_FONT_SetTextColor(1, 9, 0xc);
    func_02040588(1, 1);
    if (waitFrames != 0) {
        PRINTSYS_PrintStreamStop(msg->printStream = PRINTSYS_PrintStream(msg->window, 0, 0,
                                  msg->strbuf, msg->font,
                                  msg->textSpeed, msg->tcbl, 0,
                                  msg->heapId, 0xc));
        msg->instant = 0;
    } else {
        PRINTSYS_Print(BMP_WIN_GetBmp(msg->window), 0, 0,
                      msg->strbuf, msg->font);
        BMP_WIN_MakeScreen(msg->window);
        func_020409B4(1);
        BMP_WIN_TransferChars(msg->window);
        msg->instant = 1;
    }
    msg->state = PDC_MSG_START;
    msg->waitFrames = waitFrames;
    msg->waitReload = waitFrames;
    msg->streamEnded = 0;
}

void PDC_MSG_InitBlend(struct PdcBlend *blend, struct BmpWin *window)
{
    blend->window = window;
    blend->state = PDC_BLEND_HIDDEN;
    blend->alphaA = 0x1f000;
    blend->alphaB = 0x7000;
    func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
}

/*
 * Unlabelled leaf inside the handed extent of PDC_MSG_InitBlend.
 */
void PDC_MSG_BlendStartFadeIn(struct PdcBlend *blend)
{
    u8 state = blend->state;

    if (state == PDC_BLEND_HIDDEN || state == PDC_BLEND_FADING_OUT) {
        blend->alphaA = 0x1f000;
        blend->alphaB = 0x7000;
        blend->stepA = -0x52aa;
        blend->stepB = 0x1800;
        blend->framesLeft = 6;
        blend->state = PDC_BLEND_FADING_IN;
    }
}

void PDC_MSG_BlendStartFadeOut(struct PdcBlend *blend, int keepText)
{
    if ((u8)(blend->state + 0xff) <= 1) {
        if (keepText == 0) {
            BMP_Clear(BMP_WIN_GetBmp(blend->window), 0xc);
            BMP_WIN_TransferChars(blend->window);
        }
        blend->alphaA = 0;
        blend->alphaB = 0x10000;
        blend->stepA = 0x52AA;
        blend->stepB = -0x1800;
        blend->framesLeft = 6;
        blend->state = PDC_BLEND_FADE_OUT_REQUESTED;
    }
}

int PDC_MSG_BlendUpdate(struct PdcBlend *blend)
{
    switch (blend->state) {
    case PDC_BLEND_SHOWN:
        return 1;
    case PDC_BLEND_HIDDEN:
        return 1;
    case PDC_BLEND_FADE_OUT_REQUESTED:
        blend->state = PDC_BLEND_FADING_OUT;
        return 0;
    case PDC_BLEND_FADING_OUT:
        if (blend->framesLeft != 0) {
            blend->alphaA += blend->stepA;
            blend->alphaB += blend->stepB;
            blend->framesLeft--;
        } else {
            blend->alphaA = 0x1f000;
            blend->alphaB = 0x7000;
            blend->state = PDC_BLEND_HIDDEN;
        }
        break;
    case PDC_BLEND_FADING_IN:
        if (blend->framesLeft != 0) {
            blend->alphaA += blend->stepA;
            blend->alphaB += blend->stepB;
            blend->framesLeft--;
        } else {
            blend->alphaA = 0;
            blend->alphaB = 0x10000;
            blend->state = PDC_BLEND_SHOWN;
        }
        break;
    }

    func_0207D63C(0x04000050, 2, 0x3d,
                  (u8)(blend->alphaA >> 12), (u8)(blend->alphaB >> 12));
    return 0;
}
