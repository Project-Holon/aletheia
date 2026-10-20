/*
 * file:     sceneoptmovfailure.c
 * unit:     yes
 * function: DWCi_SceneOptMovFailure, initGraphics, procInit, procInit1, procInit2, DWCi_SceneOptMovFailure_procScene, input, DWCi_SceneOptMovFailure_draw, button, endScene, endScene1, endScene2
 * address:  0x021C3D8C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneopterase.o), symbol procInit1 (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * layout/symbols_sdk.txt files this copy under sceneopterase.o; its bytes equal sceneopterase.o's own
 * function and only the pool words differ (the copy's own next scene step and, for endScene1,
 * its own one-byte flag, declared here under the sceneopterase_bss name at the copy's address).
 * The object that owns this copy is not identified; the C is the same either way.
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021C3EC4.c \
 *       --func procInit1 --addr 0x021C3EC4 --region ov016 --cc 1.1p1 --arm --lang c99
 * sdk:      procInit2 (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 * Call input, DWCi_SceneOptMovFailure_draw, button.
 * Addresses are Black-image addresses.
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovFailure_procScene.c \
 *       --func DWCi_SceneOptMovFailure_procScene --addr 0x021C3F30 --region ov016 --cc dsi/1.1p1 --arm
 * Two guarded DWCi_BTNlSet calls keyed off DWCi_IPTlCheckTrigger.
 *   python tools/match.py one --src src/matched/input.c \
 *       --func input --addr 0x021C3F44 --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovFailure_draw.c \
 *       --func DWCi_SceneOptMovFailure_draw --addr 0x021C3F80 --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_BTNlSet                   0x021BCB28  arm  ov016
 *   DWCi_IPTlCheckTrigger          0x021D6824  arm  ov016
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm  ov016
 *   DWCi_COMMENTlDispEx  0x021BD060  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneOptMovFailureState     0x021DE5C0  data
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm
 *   DWCi_EFFlFade  0x021D55A4  arm  ov016
 *   DWCi_GXlVisible  0x021D603C  arm  ov016
 *   procInit1  0x021C3EC4  arm  ov016
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_HLlLoad                     0x021BD674  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   procConfirm                      0x021C22AC  arm
 *   procConfirm1                     0x021C22FC  arm
 *   procInit2                        0x021C3F00  arm
 *   sceneopterase_bss                0x021DE5A4  data
 *   DWCi_MOVlIsEnd  0x021C11B8  arm  ov016
 *   DWCi_BTNlIsEnd  0x021BCB58  arm  ov016
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm  ov016
 *   DWCi_COMMENTlDelete  0x021BD138  arm  ov016
 *   DWCi_GXlInvisible  0x021D6090  arm  ov016
 *   DWCi_SetParam_  0x021C0E50  arm  ov016
 *   DWCi_SceneOptMenu  0x021C2A3C  arm  ov016
 *   DWCi_SceneOptMovWait  0x021C450C  arm  ov016
 */
#include "../types.h"
#include "../sdk_ioreg.h"

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

typedef _Bool bool;

/* sceneopterase.o .bss at 0x021DE5A4, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
} SCENEOPTERASE_BSS;

#include "common.h"
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
#include "graphics.h"
#include "dwcutil_main.h"
#include "comment.h"
#include "headline.h"
#include "button.h"
#include "sound.h"
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
#include "window.h"
#include "move.h"
#include "input.h"
typedef int bool_0;
#include "font.h"
#include "sceneoptmenu.h"
#include "sceneoptmovwait.h"
void DWCi_SceneOptMovFailure(void);
void DWCi_SceneOptMovFailure_procScene(void);
void DWCi_SceneOptMovFailure_draw(void);
extern unsigned char gSceneOptMovFailureState[];
extern SCENEOPTERASE_BSS sceneopterase_bss;

/*
 * sdk:      DWCi_SceneOptMovFailure (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 */

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void input(void);
static void button(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
void DWCi_SceneOptMovFailure(void)
{
    initGraphics();
    DWCi_CMNlMsgDraw(0x20);
    gSceneOptMovFailureState[0] = DWCi_COMMENTlDispEx(0x3C, -1, 0);
    DWCi_ChangeScene((uptr)procInit);
}

static void initGraphics(void)
{
    DWCi_CMNlLoadResource((void *)0x021DB3A4, (void *)0x0207EB78);
    ((BgCnt *)REG_DB_BG0CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_DB_BG1CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_BG0CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_BG1CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_BG2CNT_ADDR)->priority = 3;
}

/*
 * sdk:      procInit (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 */
static void procInit(void)
{
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(0, 0x15);
    if (gSceneOptMovFailureState[0]) {
        DWCi_EFFlFade(2, 1, 1, 8);
        DWCi_GXlVisible(1, 1);
    }
    DWCi_ChangeScene((uptr)procInit1);
}


static void procConfirm(void);

static void procConfirm1(void);

static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(3);
    DWCi_ChangeScene((uptr)procInit2);
}

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    if (!DWCi_MOVlIsEnd())
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene((uptr)DWCi_SceneOptMovFailure_procScene);
}

void DWCi_SceneOptMovFailure_procScene(void)
{
    input();
    DWCi_SceneOptMovFailure_draw();
    button();
}

static void input(void)
{
    if (DWCi_IPTlCheckTrigger(1))
        DWCi_BTNlSet(1);
    if (DWCi_IPTlCheckTrigger(2))
        DWCi_BTNlSet(0);
}

void DWCi_SceneOptMovFailure_draw(void)
{
}

/*
 * sdk:      button (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 */
static void button(void)
{
    int r = DWCi_BTNlGet();
    if (r != 0) {
        if (r != 1)
            return;
        gSceneOptMovFailureState[1] = 1;
        DWCi_SNDlPlay(6);
    } else {
        gSceneOptMovFailureState[1] = 0;
        DWCi_SNDlPlay(7);
    }
    DWCi_ChangeScene((uptr)endScene);
}

/*
 * sdk:      endScene (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 */
static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene((uptr)endScene1);
}

/*
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 */
static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_BTNlEnd();
    if (!gSceneOptMovFailureState[1])
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene((uptr)endScene2);
}

/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 */
static void endScene2(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_FNTlDeleteBgLcd(0);
    if (!gSceneOptMovFailureState[1]) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if (!gSceneOptMovFailureState[1]) {
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene((uptr)DWCi_SceneOptMenu);
    } else {
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene((uptr)DWCi_SceneOptMovWait);
    }
}
