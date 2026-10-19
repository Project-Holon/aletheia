/*
 * file:     sceneseterror.c
 * unit:     yes
 * function: DWCi_SceneSetError, initGraphics, DWCi_SceneSetErrorDrawMessage, procInit, procInit1, DWCi_SceneSetErrorProcInit2, DWCi_SceneSetError_procScene, input, DWCi_SceneSetError_draw, button, endScene, endScene1, endScene2, DWCi_SetErrorCode
 * address:  0x021C7CE4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Call input, DWCi_SceneSetError_draw, button.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetError_procScene.c \
 *       --func DWCi_SceneSetError_procScene --addr 0x021C8154 --region ov016 --cc dsi/1.1p1 --arm
 * Guard: if (DWCi_IPTlCheckTrigger(1)) call DWCi_IPTlCheckTrigger.
 *   python tools/match.py one --src src/matched/input.c \
 *       --func input --addr 0x021C8168 --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneSetError_draw.c \
 *       --func DWCi_SceneSetError_draw --addr 0x021C8188 --region ov016 --cc dsi/1.1p1 --arm
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a sceneoptinfo.o)
 * Second emitted copy of the scene-machine tail; identical body to
 * endScene1 at 0x021C2968 but its continuation pointer names a different
 * endScene2 copy at 0x021C8230.
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneseterror.o), symbol endScene2 (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021C8230.c \
 *       --func endScene2 --addr 0x021C8230 --region ov016 --cc 1.1p1 --arm --lang c99
 * Store a word into the global at 0x021DE5E8.
 *   python tools/match.py one --src src/matched/DWCi_SetErrorCode.c \
 *       --func DWCi_SetErrorCode --addr 0x021C82EC --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_BTNlSet                   0x021BCB28  arm  ov016
 *   DWCi_IPTlCheckTrigger          0x021D6824  arm  ov016
 *   initGraphics                     0x021C7D00  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   procInit                         0x021C80B8  arm
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm
 *   DWCi_GetParam2_                     0x021c0ea0  arm
 *   DWCi_Language                       0x021c0ec8  arm
 *   DWCi_FNTlFormBgEx                   0x021d5a58  arm
 *   DWCi_MSGlGet                        0x021c1030  arm
 *   OS_SNPrintf                         0x02084f80  arm
 *   DWCi_STRlConvertStringAsciiToUnicode 0x021d722c arm
 *   DWCi_FNTlDrawStringEx               0x021d5db0  arm
 *   DWCi_CMNlFontFlag                   0x021bd3cc  arm
 *   DWCi_FNTlDrawRect                   0x021d5e5c  arm
 *   DWCi_FNTlRenewBg                    0x021d5fc4  arm
 *   ErrorCode                           0x021de5e8  data
 *   FONT_TBL                            0x021da5f0  data
 *   DWCiMsgCmn                          0x021de598  data
 *   C_CODE                              0x021da600  data
 *   DWCi_EFFlFade  0x021D55A4  arm  ov016
 *   DWCi_GXlVisible  0x021D603C  arm  ov016
 *   procInit1  0x021C80F4  arm  ov016
 *   @20980                              0x021db57c  data
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_SETTINGlEraseAll            0x021CFC20  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_SceneOptErase1              0x021C231C  arm
 *   DWCi_BTNlEnd     0x021BCAE4  arm
 *   endScene2    0x021C8230  arm
 *   DWCi_BTNlIsEnd                   0x021bcb58 arm
 *   DWCi_FNTlDeleteBgLcd             0x021d5ca8 arm
 *   DWCi_COMMENTlDelete              0x021bd138 arm
 *   DWCi_GXlInvisible                0x021d6090 arm
 *   DWCi_SetParam_                   0x021c0e50 arm
 *   DWCi_SetParam2_                  0x021c0e8c arm
 *   DWCi_SetListReturn               0x021ca5c0 arm
 *   DWCi_SceneSetSelectAp            0x021cbc90 arm
 *   DWCi_SceneSetList                0x021c82fc arm
 */
#include "../types.h"

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

struct tagCOORD {
    unsigned short x;
    unsigned short y;
};

typedef _Bool bool;

extern void DWCi_ChangeScene(void (*scene)(void));
void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
extern unsigned char DWCi_Language(void);
extern void *DWCi_FNTlFormBgEx(int lcd, int font);
extern unsigned int DWCi_MSGlGet(unsigned int *p, unsigned int idx);
extern int OS_SNPrintf(char *dst, unsigned long len, char *fmt, ...);
extern int DWCi_STRlConvertStringAsciiToUnicode(unsigned short *dst, unsigned char *src, int len);
extern void DWCi_FNTlDrawStringEx(void *canvas, int x, int y, int color, int interval,
                                  u16 *txt, int font);
extern int DWCi_CMNlFontFlag(void);
extern void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color,
                              unsigned long flag, u16 *txt);
extern void DWCi_FNTlRenewBg(int x);
extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_CMNlButton(int kind);
extern char DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern void DWCi_BTNlSet(signed char v);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_SETTINGlEraseAll(void);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_BTNlDisable(void);
extern void DWCi_SNDlPlay(int no);
void DWCi_BTNlEnd(void);
extern int DWCi_BTNlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern int DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SetParam2_(unsigned int a, unsigned int b);
extern void DWCi_SetListReturn(int scene);
void DWCi_SceneSetError(void);
void DWCi_SceneSetError_procScene(void);
void DWCi_SceneSetError_draw(void);
void DWCi_SetErrorCode(unsigned int v);
extern unsigned int DWCiMsgCmn;
extern int DWCi_SceneSetSelectAp;
extern int DWCi_SceneSetList;

static void initGraphics(void);
static void drawMessage(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void input(void);
static void button(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);

void DWCi_SceneSetError(void)
{
	initGraphics();
	drawMessage();
	DWCi_ChangeScene(procInit);
}

static void initGraphics(void)
{
    DWCi_CMNlLoadResource((void *)0x021DB568, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}

static int ErrorCode = 0;

static const unsigned char FONT_TBL[7] = { 0, 1, 1, 1, 1, 1, 0 };

/*
 * The vendor .rodata has this rectangle between FONT_TBL and C_CODE. No code
 * reads it: the DWCi_FNTlDrawRect call below uses the same values as
 * constants. The vendor symbol list does not name it.
 */
static const struct tagRECT { unsigned short x, y, w, h; } R_MSG = { 0xd, 0x3c, 0xe6, 0x5e };

static const struct tagCOORD C_CODE[7] = {
    { 0x62, 0x22 }, { 0x62, 0x22 }, { 0x3d, 0x22 }, { 0x65, 0x22 },
    { 0x6c, 0x22 }, { 0x34, 0x22 }, { 0x4e, 0x22 }
};

static inline void drawStr(void *canvas, int x, int y, int color, int interval, u16 *txt, int font)
{
    DWCi_FNTlDrawStringEx(canvas, x, y, color, interval, txt, font);
}

static void drawMessage(void)
{
    u16 *msg;
    void *canv;
    int id;
    int prm;
    u16 buf[8];
    char tmpbuf[8];

    id = 0;
    DWCi_GetParam2_((unsigned int *)0, (unsigned int *)(&prm));
    if (-20099 <= ErrorCode)
        id = 0;
    else if (-20100 <= ErrorCode)
        id = 2;
    else if (-20101 <= ErrorCode)
        id = 0x13;
    else if (-20107 <= ErrorCode)
        id = 2;
    else if (-20108 <= ErrorCode)
        id = 0x12;
    else if (-20109 <= ErrorCode)
        id = 2;
    else if (-20110 <= ErrorCode)
        id = 3;
    else if (-20999 <= ErrorCode)
        id = 2;
    else if (-22999 <= ErrorCode)
        id = 0;
    else if (-23999 <= ErrorCode)
        id = 0x13;
    else if (-49999 <= ErrorCode)
        id = 0;
    else if (-50002 <= ErrorCode)
        id = 7;
    else if (-50003 <= ErrorCode)
        id = 5;
    else if (-50098 <= ErrorCode)
        id = 0;
    else if (-50099 <= ErrorCode) {
        if (prm == 2)
            id = 5;
        else
            id = 7;
    }
    else if (-51098 <= ErrorCode)
        id = 0;
    else if (-51099 <= ErrorCode) {
        if (prm == 2)
            id = 5;
        else
            id = 8;
    }
    else if (-51102 <= ErrorCode)
        id = 9;
    else if (-51103 <= ErrorCode)
        id = 5;
    else if (-51199 <= ErrorCode)
        id = 0;
    else if (-51299 <= ErrorCode)
        id = 0x14;
    else if (-51302 <= ErrorCode)
        id = 0x15;
    else if (-51303 <= ErrorCode)
        id = 4;
    else if (-51999 <= ErrorCode)
        id = 0;
    else if (-52002 <= ErrorCode)
        id = 0xa;
    else if (-52003 <= ErrorCode)
        id = 0x16;
    else if (-52099 <= ErrorCode)
        id = 0;
    else if (-52103 <= ErrorCode)
        id = 0xb;
    else if (-52199 <= ErrorCode)
        id = 0;
    else if (-52203 <= ErrorCode)
        id = 0xb;
    else if (-52299 <= ErrorCode)
        id = 0;
    else if (-52399 <= ErrorCode)
        id = 2;
    else if (-52999 <= ErrorCode)
        id = 0;
    else if (-53299 <= ErrorCode)
        id = 2;

    canv = DWCi_FNTlFormBgEx(0, FONT_TBL[DWCi_Language()]);
    msg = (unsigned short *)DWCi_MSGlGet((void *)DWCiMsgCmn, id);
    OS_SNPrintf(tmpbuf, 8, "%d", -ErrorCode);
    DWCi_STRlConvertStringAsciiToUnicode(buf, (unsigned char *)tmpbuf, 8);
    drawStr(canv, C_CODE[DWCi_Language()].x, C_CODE[DWCi_Language()].y, 2, 10, buf, 0);
    DWCi_FNTlDrawRect(canv, 0xd, 0x3c, 0xe6, 0x5e, 2, DWCi_CMNlFontFlag(), msg);
    DWCi_FNTlRenewBg((int)canv);
}

/*
 * sdk:      procInit (libdwcutil.TWL.HYB.a sceneseterror.o)
 */
static void procInit(void)
{
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene(procInit1);
}

static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(4);
    DWCi_ChangeScene(procInit2);
}


static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(DWCi_SceneSetError_procScene);
}

void DWCi_SceneSetError_procScene(void)
{
    input();
    DWCi_SceneSetError_draw();
    button();
}

static void input(void)
{
    if (DWCi_IPTlCheckTrigger(1))
        DWCi_BTNlSet(0);
}

void DWCi_SceneSetError_draw(void)
{
}

static void button(void)
{
    if (DWCi_BTNlGet() != 0)
        return;
    DWCi_SNDlPlay(6);
    DWCi_ChangeScene(endScene);
}

static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1)) return;
    DWCi_BTNlEnd();
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene2);
}

static void endScene2(void)
{
    void *prm;

    if (DWCi_EFFlCheck(1) || DWCi_EFFlCheck(0)) {
        return;
    }
    if (!DWCi_BTNlIsEnd()) {
        return;
    }
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_GetParam2_((unsigned int *)0, (unsigned int *)(&prm));
    if (prm != 0) {
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene((void (*)())&DWCi_SceneSetSelectAp);
    } else {
        DWCi_SetParam_(2, 0);
        DWCi_SetParam2_(0, 0);
        DWCi_SetListReturn(0);
        DWCi_ChangeScene((void (*)())&DWCi_SceneSetList);
    }
}

void DWCi_SetErrorCode(unsigned int v)
{
    *(unsigned int *)0x021DE5E8 = v;
}
