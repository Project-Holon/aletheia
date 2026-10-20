/*
 * file:     scenesetrakuready.c
 * unit:     yes
 * function: DWCi_IsFold, DWCi_SceneSetRakuReady, initGraphics, procInit, procInit1, procInit2, procScene, input, DWCi_SceneSetRakuReady_draw, button, endScene, endScene1, endScene2, checkRaku, procError, procError1
 * address:  0x021CB2C8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetrakuread), symbol DWCi_SceneSetRakuReady (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/DWCi_SceneSetRakuReady.c \
 *       --func DWCi_SceneSetRakuReady --addr 0x021CB2E8 --region ov016 --cc 1.1p1 --arm --lang c99
 * Set r0 to 0xa, call OS_Sleep, then run the four ov016 steps.
 * Addresses are Black-image addresses.
 *   python tools/match.py one --src src/matched/procScene.c \
 *       --func procScene --addr 0x021CB4BC --region ov016 --cc dsi/1.1p1 --arm
 * Two-stage guard around DWCi_BTNlSet.
 *   python tools/match.py one --src src/matched/input.c \
 *       --func input --addr 0x021CB4DC --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneSetRakuReady_draw.c \
 *       --func DWCi_SceneSetRakuReady_draw --addr 0x021CB514 --region ov016 --cc dsi/1.1p1 --arm
 * sdk:      button (sceneoptmovwait.o), TwlDWC libdwcutil.TWL.HYB.a
 * sdk:      endScene (scenesetrakubutt.o), TwlDWC libdwcutil.TWL.HYB.a
 * sdk:      endScene1 (scenesetrakuread.o), TwlDWC libdwcutil.TWL.HYB.a
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetrakubutt), symbol endScene2 (name and prototype from the vendor object DWARF).
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CB5D8.c \
 *       --func endScene2 --addr 0x021CB5D8 --region ov016 --cc 1.1p1 --arm --lang c99
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneopterase.o), symbol procError1 (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * layout/symbols_sdk.txt files this copy under sceneopterase.o; its bytes equal sceneopterase.o's own
 * function and only the pool words differ (the copy's own next scene step and, for endScene1,
 * its own one-byte flag, declared here under the sceneopterase_bss name at the copy's address).
 * The object that owns this copy is not identified; the C is the same either way.
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CB760.c \
 *       --func procError1 --addr 0x021CB760 --region ov016 --cc 1.1p1 --arm --lang c99
 *
 * symbols:
 *   OS_Sleep                       0x02085A38  arm  arm9
 *   DWCi_BTNlSet                   0x021BCB28  arm  ov016
 *   DWCi_IPTlCheckTrigger          0x021D6824  arm  ov016
 *   initGraphics                     0x021cb344 arm
 *   DWCi_HLlLoadSet                  0x021bd6d4 arm
 *   DWCi_COMMENTlDispEx              0x021bd060 arm
 *   DWCi_CMNlStep                    0x021bd214 arm
 *   DWCi_CMNlMsgDraw                 0x021bd29c arm
 *   DWCi_ANIMElInitEx                0x021bc820 arm
 *   DWCi_SNDlPlay                    0x021cffac arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   Choose                           0x021de604 data
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   sSceneSetRakuReadyPathJbBgStep3Char    0x021DB680  data
 *   sSceneSetRakuReadyPathYbBgStep3Pltt    0x021DB698  data
 *   sSceneSetRakuReadyPathXb4MultiScr    0x021DB6B0  data
 *   GX_LoadBG2Char    0x0207F0B8  data
 *   GX_LoadBGPltt    0x0207E3D0  data
 *   GX_LoadBG2Scr    0x0207EB78  data
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_EFFlCheck                   0x021d5580 arm
 *   DWCi_RAKUlInit                   0x021c1488 arm
 *   DWCi_CMNlButton                  0x021bd264 arm
 *   DWCi_BTNlGet                     0x021bcb14 arm
 *   DWCi_BTNlEnable                  0x021bcb84 arm
 *   procScene                        0x021cb4bc arm
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_BTNlIsEnd                   0x021bcb58 arm
 *   DWCi_ANIMElEnd                   0x021bc8ec arm
 *   DWCi_FNTlDeleteBgLcd             0x021d5ca8 arm
 *   DWCi_COMMENTlDelete              0x021bd138 arm
 *   DWCi_GXlInvisible                0x021d6090 arm
 *   DWCi_RAKUlEnd                    0x021c14f4 arm
 *   DWCi_SetParam_                   0x021c0e50 arm
 *   DWCi_SceneSetSelectWay           0x021cc998 arm
 *   DWCi_SceneSetRakuButton          0x021ca838 arm
 *   DWCi_RAKUlGetState               0x021c1518 arm
 *   DWCi_WINlInitEx                  0x021d1208 arm
 *   DWCi_WINlGet                     0x021d1568 arm
 *   DWCi_WINlEnd                     0x021d1524 arm
 *   DWCi_HLlLoad                     0x021BD674  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   procConfirm                      0x021C22AC  arm
 *   sceneopterase_bss                0x021DE5A4  data
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
#include "anime.h"
#include "sound.h"
#include "dwcutil_main.h"
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
#include "graphics.h"
extern bool DWCi_EFFlCheck(int lcd);
#include "rakuraku.h"
#include "button.h"
#include "../arm9/os_thread.h"
#include "input.h"
extern bool DWCi_EFFlWait(int frame);
typedef int bool_0;
#include "font.h"
#include "scenesetselectway.h"
#include "scenesetrakubutton.h"
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
#include "window.h"
void DWCi_SceneSetRakuReady(void);
void DWCi_SceneSetRakuReady_draw(void);
extern unsigned char Choose;
extern unsigned short sSceneSetRakuReadyPathJbBgStep3Char[];
extern unsigned short sSceneSetRakuReadyPathYbBgStep3Pltt[];
extern unsigned short sSceneSetRakuReadyPathXb4MultiScr[];
extern SCENEOPTERASE_BSS sceneopterase_bss;

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void procScene(void);
static void input(void);
static void button(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
static void checkRaku(void);
static void procError(void);
static void procError1(void);

/*
 * Bit 15 of the halfword at 0x02FFFFA8 (lid closed), as 0/1: this scene's own
 * copy of the libdwcutil helper.
 */
static int DWCi_IsFold(void)
{
    return ((*(unsigned short *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}

void DWCi_SceneSetRakuReady(void)
{
    Choose = 0;
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_COMMENTlDispEx(0x37, -1, 0);
    DWCi_CMNlStep(2);
    DWCi_CMNlMsgDraw(0x24);
    DWCi_ANIMElInitEx(0);
    DWCi_SNDlPlay(0xb);
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

    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetRakuReadyPathJbBgStep3Char), GX_LoadBG2Char);
    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetRakuReadyPathYbBgStep3Pltt), GX_LoadBGPltt);
    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetRakuReadyPathXb4MultiScr), GX_LoadBG2Scr);

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
    if (DWCi_EFFlCheck(1) || DWCi_EFFlCheck(0)) {
        return;
    }
    DWCi_RAKUlInit();
    DWCi_CMNlButton(1);
    DWCi_ChangeScene((uptr)procInit2);
}

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2) {
        return;
    }
    DWCi_BTNlEnable();
    DWCi_ChangeScene((uptr)procScene);
}

static void procScene(void)
{
    OS_Sleep(0xa);
    checkRaku();
    input();
    DWCi_SceneSetRakuReady_draw();
    button();
}

static void input(void)
{
    if (DWCi_IPTlCheckTrigger(2))
    {
        DWCi_BTNlSet(0);
        return;
    }
    if (DWCi_IsFold())
        DWCi_BTNlSet(0);
}

void DWCi_SceneSetRakuReady_draw(void)
{
}

static void button(void)
{
    if (DWCi_BTNlGet())
        return;
    DWCi_SNDlStop();
    DWCi_SNDlPlay(7);
    DWCi_ChangeScene((uptr)endScene);
}

static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene((uptr)endScene1);
}

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (Choose == 0)
        DWCi_BTNlEnd();
    if (Choose == 0)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x14, 8);
    DWCi_ChangeScene((uptr)endScene2);
}

static void endScene2(void)
{
    if (DWCi_EFFlCheck(0)) {
        return;
    }
    if (Choose == 0) {
        if (DWCi_EFFlCheck(1)) {
            return;
        }
    }
    if (!DWCi_BTNlIsEnd()) {
        return;
    }
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    if (Choose == 0) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if (Choose == 0) {
        DWCi_RAKUlEnd();
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene((uptr)DWCi_SceneSetSelectWay);
    } else {
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene((uptr)DWCi_SceneSetRakuButton);
    }
}

static void checkRaku(void)
{
    switch (DWCi_RAKUlGetState()) {
    case 1:
        Choose = 1;
        DWCi_ChangeScene((uptr)endScene);
        break;
    case 4:
        Choose = 0;
        DWCi_SNDlStop();
        DWCi_SNDlPlay(9);
        DWCi_WINlInitEx(0xd, 1, 1, -1, 0);
        DWCi_BTNlDisable();
        DWCi_ChangeScene((uptr)procError);
        break;
    }
}

static void procError(void)
{
    if (DWCi_WINlGet() != 0) {
        return;
    }
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_ChangeScene((uptr)procError1);
}

static void procConfirm(void);

static void procError1(void)
{
    if (DWCi_WINlIsInit())
        return;
    DWCi_ChangeScene((uptr)endScene);
}
