/*
 * file:     scenesetusbcomplete.c
 * unit:     yes
 * function: DWCi_SceneSetUsbComplete, initGraphics, procInit, DWCi_SceneSetUsbComplete_procInit1, DWCi_SceneSetUsbCompleteCallback, DWCi_SceneSetUsbCompleteNop, endScene, DWCi_SceneSetUsbComplete_endScene1, wait
 * address:  0x021CDA88
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesettest.o)
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/DWCi_SceneSetUsbComplete_procInit1.c \n *       --func DWCi_SceneSetUsbComplete_procInit1 --addr 0x021CDB84 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovdisco), symbol endScene (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * layout/symbols_sdk.txt files this copy under sceneoptmovdisco; its bytes equal the object's own
 * function and only the pool words differ (the copy's own data and next scene step).
 * The object that owns this copy is not identified; the C is the same either way.
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDBBC.c \
 *       --func endScene --addr 0x021CDBBC --region ov016 --cc 1.1p1 --arm --lang c99
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesetusbcompl)
 *   python tools/match.py one --src src/matched/ov_sdk/DWCi_SceneSetUsbComplete_endScene1.c \n *       --func DWCi_SceneSetUsbComplete_endScene1 --addr 0x021CDC00 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovdisco), symbol wait (name and prototype from the
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDC78.c \
 *       --func wait --addr 0x021CDC78 --region ov016 --cc 1.1p1 --arm --lang c99
 *
 * symbols:
 *   gSceneSetUsbCompleteWaitCount     0x021DE624  data
 *   DWCi_HLlLoad  0x021BD674  arm  ov016
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm
 *   DWCi_EFFlFade  0x021D55A4  arm  ov016
 *   DWCi_GXlVisible  0x021D603C  arm  ov016
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_MOVlIsEnd                   0x021C11B8  arm
 *   DWCi_SceneOptMenu                0x021C2A3C  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   GX_LoadBG2Scr                    0x0207EB78  arm
 *   procInit1                        0x021C3C64  arm
 *   sceneoptmovdisco_str_20611       0x021DB390  data
 *   DWCi_SetParam2_  0x021C0E8C  arm  ov016
 *   DWCi_SceneSetTestConfirm  0x021CD80C  arm  ov016
 */
#define reg_G2S_DB_BG0CNT (*(volatile unsigned short *)REG_DB_BG0CNT_ADDR)
#define reg_G2S_DB_BG1CNT (*(volatile unsigned short *)REG_DB_BG1CNT_ADDR)
#define reg_G2_BG1CNT     (*(volatile unsigned short *)REG_BG1CNT_ADDR)
#define reg_G2_BG2CNT     (*(volatile unsigned short *)REG_BG2CNT_ADDR)
#include "../types.h"
#include "../sdk_ioreg.h"

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

typedef _Bool bool;

#include "headline.h"
#include "common.h"
#include "sound.h"
#include "../arm9/gx_load2d.h"
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
#include "graphics.h"
#include "dwcutil_main.h"
#include "move.h"
typedef int bool_0;
#include "font.h"
#include "comment.h"
#include "sceneoptmenu.h"
#include "scenesettestconfirm.h"
void DWCi_SceneSetUsbComplete(void);
void DWCi_SceneSetUsbComplete_procInit1(void);
void DWCi_SceneSetUsbCompleteCallback(void);
void DWCi_SceneSetUsbCompleteNop(void);
void DWCi_SceneSetUsbComplete_endScene1(void);
extern unsigned char gSceneSetUsbCompleteWaitCount;
/* sceneoptmovdisco .bss */
/* the resource file name, the compiler's @20611 in .rodata */
extern char sceneoptmovdisco_str_20611[];

/*
 * sdk:      DWCi_SceneSetUsbComplete (libdwcutil.TWL.HYB.a scenesetusbcompl)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/DWCi_SceneSetUsbComplete.c \n *       --func DWCi_SceneSetUsbComplete --addr 0x021CDA88 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */

static void initGraphics(void);
static void procInit(void);
static void endScene(void);
static void wait(void);
void DWCi_SceneSetUsbComplete(void)
{
    gSceneSetUsbCompleteWaitCount = 0;
    initGraphics();
    DWCi_HLlLoad(8);
    DWCi_CMNlMsgDraw(41);
    DWCi_SNDlPlay(16);
    DWCi_ChangeScene((uptr)procInit);
}

static void initGraphics(void)
{
    DWCi_CMNlLoadResource((void *)0x021DB828, (void *)0x0207EB78);
    ((BgCnt *)REG_DB_BG0CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_DB_BG1CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_BG0CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_BG1CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_BG2CNT_ADDR)->priority = 3;
}

/*
 * sdk:      procInit (libdwcutil.TWL.HYB.a scenesetusbcompl)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDB48.c \n *       --func procInit --addr 0x021CDB48 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void procInit(void)
{
    DWCi_EFFlFade(2, 0, 21, 8);
    DWCi_GXlVisible(0, 21);
    DWCi_ChangeScene((uptr)DWCi_SceneSetUsbComplete_procInit1);
}

void DWCi_SceneSetUsbComplete_procInit1(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_ChangeScene((uptr)DWCi_SceneSetUsbCompleteCallback);
}

/*
 * Call wait, DWCi_SceneSetUsbCompleteNop.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetUsbCompleteCallback.c \
 *       --func DWCi_SceneSetUsbCompleteCallback --addr 0x021CDBA8 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetUsbCompleteCallback(void)
{
    wait();
    DWCi_SceneSetUsbCompleteNop();
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetUsbCompleteNop.c \
 *       --func DWCi_SceneSetUsbCompleteNop --addr 0x021CDBB8 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetUsbCompleteNop(void)
{
}

static void procInit1(void);



static void endScene(void)
{
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene((uptr)DWCi_SceneSetUsbComplete_endScene1);
}

void DWCi_SceneSetUsbComplete_endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 21);
    DWCi_SetParam_(0, 0);
    DWCi_SetParam2_(0, (unsigned int)(2));
    DWCi_ChangeScene((uptr)DWCi_SceneSetTestConfirm);
}

static void wait(void)
{
    if (++gSceneSetUsbCompleteWaitCount >= 120)
        DWCi_ChangeScene((uptr)endScene);
}
