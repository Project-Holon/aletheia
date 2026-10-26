/*
 * file:     pdc_msg.c
 * unit:     yes
 * function: PDC_MSG_Create, PDC_MSG_Delete, PDC_MSG_PrintMessage0, PDC_MSG_PrintMessage3, PDC_MSG_PrintMessage1, PDC_MSG_PrintMessage2, PDC_MSG_PrintMessage4, PDC_MSG_Update, PDC_MSG_StartFadeIn, PDC_MSG_UpdateFade, PDC_MSG_TakeStreamEnded, PDC_MSG_StartPrint, PDC_MSG_InitBlend, PDC_MSG_BlendStartFadeIn, PDC_MSG_BlendStartFadeOut, PDC_MSG_BlendUpdate
 * address:  0x021B67D4
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pdc.c, PDC_MSG_BlendUpdate.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   CONFIG_GetTextSpeed 0x02008374 thumb
 *   MSG_SPEED_GetWaitForSpeed 0x02013080 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   ARC_UTIL_RegisterObjCharFromArchive 0x020496E4 arm
 *   PALANM_LoadArcPaletteToSlotAt 0x020215EC thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_DrawFrame 0x020454E0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   gPdcMsgSrcName 0x021B6E74 data a4
 *   gPdcMsgBgTemplate 0x021B6E24 data a4
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   PDC_MSG_BlendUpdate 0x021B6CDC thumb ov098
 *   PRINTSYS_PrintStreamRun 0x0201CE20 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   PRINTSYS_PrintStreamStop  0x0201CE0C  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   PDC_GetMon 0x021B6140 thumb ov098
 *   PDC_GetMyStatus 0x021B6148 thumb ov098
 */
#include "pdc_types.h"
#include "../sdk_ioreg.h"

struct BgTemplate;

#include "../arm9/gfl_heap_wrap.h"
#include "../ov094/btlv_effect.h"
#include "../arm9/key.h"
#include "../arm9/touchpanel.h"
#include "../arm9/bg_sys.h"
#include "../arm9/msgdata.h"
#include "../arm9/config.h"
#include "../arm9/msg_speed.h"
#include "../arm9/strbuf.h"
/* Original prototypes (docs/ORIGINAL_BUGS.tsv): ../arm9/gf_font.h */
#ifdef __MWERKS__
#define WORDSET_CreateDefault WORDSET_CreateDefault_header
#endif
#include "../arm9/gf_font.h"
#ifdef __MWERKS__
#undef WORDSET_CreateDefault
struct WordSet *WORDSET_CreateDefault(u32 heapId);
#endif
#include "../arm9/arc_util.h"
#include "../arm9/palanm.h"
struct BmpWin;
#include "../arm9/bmp_win.h"
#include "../arm9/wordset.h"
struct TextPrinter;
#include "../arm9/printsys.h"
struct Bmp;
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/g2.h"

#include "pdc.h"

struct PdcMsg *PDC_MSG_Create(struct GfFont *font, struct Config *config, struct Tcbl *tcbl, u32 heapId);
void PDC_MSG_Delete(struct PdcMsg *msg);
void PDC_MSG_PrintMessage0(struct PdcMsg *msg, struct PdcArgs *args);
void PDC_MSG_PrintMessage3(struct PdcMsg *msg, struct PdcArgs *args);
void PDC_MSG_PrintMessage1(struct PdcMsg *msg, struct PdcArgs *args);
void PDC_MSG_PrintMessage2(struct PdcMsg *msg, struct PdcArgs *args);
void PDC_MSG_PrintMessage4(struct PdcMsg *msg, struct PdcArgs *args);
int PDC_MSG_Update(struct PdcMsg *msg);
void PDC_MSG_StartFadeIn(struct PdcMsg *msg);
int PDC_MSG_UpdateFade(struct PdcMsg *msg);
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

    msg = GFL_HEAP_Alloc(heapId, sizeof(*msg), 1, gPdcMsgSrcName, 0x82);
    BG_SYS_InitBgLayer(1, &gPdcMsgBgTemplate, 0);
    msg->heapId = heapId;
    msg->tcbl = tcbl;
    msg->msgBank = MSGDATA_CreateFromArchive(0, 2, 0x56, msg->heapId);
    msg->font = font;
    msg->textSpeed = MSG_SPEED_GetWaitForSpeed(CONFIG_GetTextSpeed(config));
    msg->strbuf = STRBUF_Create(0x100, heapId);
    /* likely original mismatch: the call site passes the heap id wide, the ARM9 definition takes u16 */
    msg->wordSet = WORDSET_CreateDefault(heapId);
    BG_SYS_SetTileEntry(1, 0, 0, 0, 32, 32, 17);
    BG_SYS_Init(1, 0, 1, 0);
    frameIndex = ARC_UTIL_RegisterObjCharFromArchive(11, 89, 1, 0, 0, msg->heapId);
    PALANM_LoadArcPaletteToSlotAt(BTLV_EFFECT_GetPalanm(), 11, 90, msg->heapId, 0, 32, 0, 0);
    msg->window = BMP_WIN_Create(1, 1, 19, 30, 4, 0, 0);
    BMP_WIN_MakeScreen(msg->window);
    BMP_WIN_DrawFrame(msg->window, frameIndex, 0);
    BG_SYS_PushTile(1);
    BG_SYS_SetPlaneVisible(1, 0);
    PDC_MSG_InitBlend(&msg->blend, msg->window);
    return msg;
}

void PDC_MSG_Delete(struct PdcMsg *msg)
{
    STRBUF_Delete(msg->strbuf);
    WORDSET_Delete(msg->wordSet);
    if (msg->printStream) PRINTSYS_PrintStreamDelete(msg->printStream);
    BG_SYS_FreeLayerBuf(1);
    MSGDATA_Delete(msg->msgBank);
    BMP_WIN_Delete(msg->window);
    GFL_HEAP_Free(msg);
}

void PDC_MSG_PrintMessage0(struct PdcMsg *msg, struct PdcArgs *args) {
    struct Strbuf *str;
    struct PokemonParam *mon;
    str = MSGDATA_AllocString(msg->msgBank, 0);
    mon = PDC_GetMon(args);
    WORDSET_SetSlotMonNickname(msg->wordSet, 0, mon);
    WORDSET_CopyTaggedText(msg->wordSet, msg->strbuf, str);
    PDC_MSG_StartPrint(msg, 0x50);
    STRBUF_Delete(str);
}

void PDC_MSG_PrintMessage3(struct PdcMsg *msg, struct PdcArgs *args) {
    struct Strbuf *str;
    struct MyStatus *myStatus;
    str = MSGDATA_AllocString(msg->msgBank, 3);
    myStatus = PDC_GetMyStatus(args);
    WORDSET_SetSlotMyStatus(msg->wordSet, 0, myStatus);
    WORDSET_CopyTaggedText(msg->wordSet, msg->strbuf, str);
    PDC_MSG_StartPrint(msg, 0);
    STRBUF_Delete(str);
}

void PDC_MSG_PrintMessage1(struct PdcMsg *msg, struct PdcArgs *args) {
    struct Strbuf *str;
    struct PokemonParam *mon;
    str = MSGDATA_AllocString(msg->msgBank, 1);
    mon = PDC_GetMon(args);
    WORDSET_SetSlotMonNickname(msg->wordSet, 0, mon);
    WORDSET_CopyTaggedText(msg->wordSet, msg->strbuf, str);
    PDC_MSG_StartPrint(msg, 0x50);
    STRBUF_Delete(str);
}

void PDC_MSG_PrintMessage2(struct PdcMsg *msg, struct PdcArgs *args) {
    struct Strbuf *str;
    struct PokemonParam *mon;
    str = MSGDATA_AllocString(msg->msgBank, 2);
    mon = PDC_GetMon(args);
    WORDSET_SetSlotMonNickname(msg->wordSet, 0, mon);
    WORDSET_CopyTaggedText(msg->wordSet, msg->strbuf, str);
    PDC_MSG_StartPrint(msg, 0x50);
    STRBUF_Delete(str);
}

void PDC_MSG_PrintMessage4(struct PdcMsg *msg, struct PdcArgs *args)
{
    struct Strbuf *str;
    struct MyStatus *myStatus;
    str=MSGDATA_AllocString(msg->msgBank, 4);
    myStatus=PDC_GetMyStatus(args);
    WORDSET_SetSlotMyStatus(msg->wordSet, 0, myStatus);
    WORDSET_CopyTaggedText(msg->wordSet, msg->strbuf, str);
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
            GF_FONT_SetDefaultTextColor();
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

int PDC_MSG_UpdateFade(struct PdcMsg *msg)
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
    BG_SYS_SetPlaneVisible(1, 1);
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
        BG_SYS_PushTile(1);
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
    G2x_SetBlendAlpha_((unsigned int *)REG_BLDCNT_ADDR, 2, 0x3d, 0x1f, 7);
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

    G2x_SetBlendAlpha_((unsigned int *)REG_BLDCNT_ADDR, 2, 0x3d,
                  (u8)(blend->alphaA >> 12), (u8)(blend->alphaB >> 12));
    return 0;
}
