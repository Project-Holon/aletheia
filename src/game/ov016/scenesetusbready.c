/*
 * file:     scenesetusbready.c
 * unit:     yes
 * function: DWCi_SceneSetUsbReady, initGraphics, procInit, procInit1, procInit2, DWCi_SceneSetUsbReadyUpdate, input, DWCi_SceneSetUsbReadyUpdateNop, button, endScene, endScene1, endScene2
 * address:  0x021CDCAC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetusbready), symbol DWCi_SceneSetUsbReady (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/DWCi_SceneSetUsbReady.c \
 *       --func DWCi_SceneSetUsbReady --addr 0x021CDCAC --region ov016 --cc 1.1p1 --arm --lang c99
 * Call input, DWCi_SceneSetUsbReadyUpdateNop, button.
 * Addresses are Black-image addresses.
 *   python tools/match.py one --src src/matched/DWCi_SceneSetUsbReadyUpdate.c \
 *       --func DWCi_SceneSetUsbReadyUpdate --addr 0x021CDE6C --region ov016 --cc dsi/1.1p1 --arm
 * Two guarded DWCi_BTNlSet calls keyed off DWCi_IPTlCheckTrigger.
 *   python tools/match.py one --src src/matched/input.c \
 *       --func input --addr 0x021CDE80 --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneSetUsbReadyUpdateNop.c \
 *       --func DWCi_SceneSetUsbReadyUpdateNop --addr 0x021CDEBC --region ov016 --cc dsi/1.1p1 --arm
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneopterase.o), symbol endScene1 (name and prototype from the
 * layout/symbols_sdk.txt files this copy under sceneopterase.o; its bytes equal sceneopterase.o's own
 * function and only the pool words differ (the copy's own next scene step and, for endScene1,
 * its own one-byte flag, declared here under the sceneopterase_bss name at the copy's address).
 * The object that owns this copy is not identified; the C is the same either way.
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDF30.c \
 *       --func endScene1 --addr 0x021CDF30 --region ov016 --cc 1.1p1 --arm --lang c99
 * Closed 2026-09-28: DWCi_GXlInvisible(1, 1) belongs INSIDE the `if (Choose == 0)`
 * arm (the original branches over it), not after it; the earlier DIFF was this
 * mis-grouped arm, not the constant-1 rematerialisation. See
 * docs/idioms/the-fall-through-arm-is-the-source-order.md.
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetusbready), symbol endScene2 (name and prototype from the
 *   python tools/match.py one --src src/pending/ov_sdk/ov016_func_021CDF98.c \
 *       --func endScene2 --addr 0x021CDF98 --region ov016 --cc 1.1p1 --arm --lang c99
 *
 * symbols:
 *   DWCi_BTNlSet                   0x021BCB28  arm  ov016
 *   DWCi_IPTlCheckTrigger          0x021D6824  arm  ov016
 *   sScenesetusbreadyChoose                           0x021DE628  data
 *   DWCi_ANIMElEnd                   0x021BC8EC  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlIsEnd                   0x021BCB58  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_CMNlStep                    0x021BD214  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_HLlLoad                     0x021BD674  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   DWCi_SceneSetSelectAp            0x021CBC90  arm
 *   DWCi_SceneSetUsbComplete         0x021CDA88  arm
 *   DWCi_SceneSetUsbReady1           0x021CE070  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   DWCi_USBAPlEnd                   0x021D0CEC  arm
 *   DWCi_USBAPlSetCallback           0x021D0DC8  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   initGraphics                     0x021CDCFC  arm
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   sSceneSetUsbReadyPathJbBgStep2Char    0x021DB83C  data
 *   sSceneSetUsbReadyPathYbBgStep2Pltt    0x021DB854  data
 *   sSceneSetUsbReadyPathXb3MultiScr    0x021DB86C  data
 *   GX_LoadBG2Char    0x0207F0B8  data
 *   GX_LoadBGPltt    0x0207E3D0  data
 *   GX_LoadBG2Scr    0x0207EB78  data
 *   endScene  0x021CDF10  arm
 *   gSceneSetUsbReadyWork  0x021DE628  data  a1
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   procConfirm                      0x021C22AC  arm
 *   procConfirm1                     0x021C22FC  arm
 *   sceneopterase_bss                0x021DE628  data
 */

typedef _Bool bool;

#include "../types.h"
#include "../sdk_ioreg.h"
#include "../arm9/gx_load2d.h"

/* sceneopterase.o .bss at 0x021DE5A4, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
} SCENEOPTERASE_BSS;

#include "headline.h"
#include "comment.h"
#include "common.h"
#include "button.h"
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
#include "graphics.h"
typedef int bool_0;
#include "font.h"
#include "dwcutil_main.h"
#include "sound.h"
#include "window.h"
#include "usbap.h"
#include "anime.h"
#include "scenesetselectap.h"
#include "scenesetusbready1.h"
#include "scenesetusbcomplete.h"
#include "input.h"
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
void DWCi_SceneSetUsbReady(void);
void DWCi_SceneSetUsbReadyUpdate(void);
void DWCi_SceneSetUsbReadyUpdateNop(void);
/* scenesetusbready .bss at 0x021DE628 */
extern unsigned char sScenesetusbreadyChoose;
extern unsigned short sSceneSetUsbReadyPathJbBgStep2Char[];
extern unsigned short sSceneSetUsbReadyPathYbBgStep2Pltt[];
extern unsigned short sSceneSetUsbReadyPathXb3MultiScr[];
extern SCENEOPTERASE_BSS sceneopterase_bss;


static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void input(void);
static void button(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);

void DWCi_SceneSetUsbReady(void)
{
    sScenesetusbreadyChoose = 0;
    initGraphics();
    DWCi_HLlLoad(8);
    DWCi_COMMENTlDispEx(0x38, -1, 0);
    DWCi_CMNlStep(1);
    DWCi_CMNlMsgDraw(0x27);
    DWCi_ChangeScene((uptr)procInit);
}

/*
 * Load three tilemaps through DWCi_CMNlLoadResource, then set the low two bits of five
 * halfword registers (the 0x04001008/0x04000008 pair and their +2 neighbours).
 * Addresses are Black-image addresses.
 */
static void initGraphics(void)
{
    u16 *p;

    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetUsbReadyPathJbBgStep2Char), GX_LoadBG2Char);
    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetUsbReadyPathYbBgStep2Pltt), GX_LoadBGPltt);
    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetUsbReadyPathXb3MultiScr), GX_LoadBG2Scr);

    p = (u16 *)REG_DB_BG0CNT_ADDR;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)REG_BG0CNT_ADDR;
    p[0] = (p[0] & ~3) | 3;
    p = (u16 *)REG_BG1CNT_ADDR;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}

static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene((uptr)procInit1);
}

static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(6);
    DWCi_ChangeScene((uptr)procInit2);
}

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene((uptr)DWCi_SceneSetUsbReadyUpdate);
}

void DWCi_SceneSetUsbReadyUpdate(void)
{
    input();
    DWCi_SceneSetUsbReadyUpdateNop();
    button();
}

static void input(void)
{
    if (DWCi_IPTlCheckTrigger(1))
        DWCi_BTNlSet(1);
    if (DWCi_IPTlCheckTrigger(2))
        DWCi_BTNlSet(0);
}

void DWCi_SceneSetUsbReadyUpdateNop(void)
{
}

/*
 * sdk:      button (libdwcutil.TWL.HYB.a(sceneoptmovconfi))
 */
static void button(void)
{
    switch (DWCi_BTNlGet()) {
    case 0:
        DWCi_SNDlPlay(7);
        break;
    case 1:
        DWCi_SNDlPlay(6);
        sScenesetusbreadyChoose = 1;
        break;
    default:
        return;
    }
    DWCi_ChangeScene((uptr)endScene);
}

static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene((uptr)endScene1);
}

static void procConfirm(void);

static void procConfirm1(void);

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_BTNlEnd();
    if (sceneopterase_bss.Choose == 0)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene((uptr)endScene2);
}

static void endScene2(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    if (sScenesetusbreadyChoose == 0 && DWCi_EFFlCheck(1))
        return;
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_FNTlDeleteBgLcd(0);
    if (sScenesetusbreadyChoose == 0) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if (sScenesetusbreadyChoose == 0) {
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene((uptr)DWCi_SceneSetSelectAp);
    } else {
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene((uptr)DWCi_SceneSetUsbReady1);
    }
}
