/*
 * file:     sceneoptmovconfirm.c
 * unit:     yes
 * function: DWCi_SceneOptMovConfirm, initGraphics, procInit, procInit1, procInit2, DWCi_SceneOptMovConfirm_procScene, input, DWCi_SceneOptMovConfirm_draw, button, endScene
 * address:  0x021C35F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovconfi.o), symbol DWCi_SceneOptMovConfirm
 * (name and prototype from the vendor object DWARF). The object is stamped Metrowerks
 * C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build writes, so it stays on 1.1p1.
 * Call input, DWCi_SceneOptMovConfirm_draw, button.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovConfirm_procScene.c \
 *       --func DWCi_SceneOptMovConfirm_procScene --addr 0x021C3714 --region ov016 --cc dsi/1.1p1 --arm
 * Guard: if (DWCi_IPTlCheckTrigger(1)) call DWCi_IPTlCheckTrigger.
 *   python tools/match.py one --src src/matched/input.c \
 *       --func input --addr 0x021C3728 --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovConfirm_draw.c \
 *       --func DWCi_SceneOptMovConfirm_draw --addr 0x021C3748 --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_BTNlSet                   0x021BCB28  arm  ov016
 *   DWCi_IPTlCheckTrigger          0x021D6824  arm  ov016
 *   initGraphics                     0x021C3610  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_SETTINGlEraseAll            0x021CFC20  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_SceneOptErase1              0x021C231C  arm
 *   endScene2                        0x021C2528  arm
 *   closeFadeStep                        0x021C3794  arm
 */
#include "../types.h"

typedef _Bool bool;

#include "common.h"
#include "dwcutil_main.h"
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
#include "graphics.h"
extern bool DWCi_EFFlCheck(int lcd);
#include "button.h"
#include "input.h"
#include "setting.h"
extern bool DWCi_EFFlWait(int frame);
#include "sound.h"
void DWCi_SceneOptMovConfirm(void);
void DWCi_SceneOptMovConfirm_procScene(void);
void DWCi_SceneOptMovConfirm_draw(void);

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void input(void);
static void button(void);
static void endScene(void);

void DWCi_SceneOptMovConfirm(void)
{
    initGraphics();
    DWCi_CMNlMsgDraw(0x1a);
    DWCi_ChangeScene(procInit);
}

/*
 * sdk:      initGraphics (libdwcutil.TWL.HYB.a(sceneoptmovcompl))
 */
static void initGraphics(void)
{
    *(vu16 *)0x04001008 = (*(vu16 *)0x04001008 & ~3) | 3;
    *(vu16 *)0x0400100A = (*(vu16 *)0x0400100A & ~3) | 3;
    *(vu16 *)0x04000008 = (*(vu16 *)0x04000008 & ~3) | 3;
    *(vu16 *)0x0400000A = (*(vu16 *)0x0400000A & ~3) | 3;
    *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & ~3) | 3;
}

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
    DWCi_ChangeScene(DWCi_SceneOptMovConfirm_procScene);
}

void DWCi_SceneOptMovConfirm_procScene(void)
{
    input();
    DWCi_SceneOptMovConfirm_draw();
    button();
}

static void input(void)
{
    if (DWCi_IPTlCheckTrigger(1))
        DWCi_BTNlSet(0);
}

void DWCi_SceneOptMovConfirm_draw(void)
{
}

static void closeFadeStep(void);

static void endScene2(void);

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
    DWCi_ChangeScene(closeFadeStep);
}
