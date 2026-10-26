/*
 * file:     sceneopterase1.c
 * unit:     yes
 * function: DWCi_SceneOptErase1, initGraphics, procInit, procInit1, procInit2, DWCi_SceneOptErase1_procScene, input, DWCi_SceneOptErase1_draw, button, endScene, endScene1, endScene2
 * address:  0x021C231C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Call input, DWCi_SceneOptErase1_draw, button.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptErase1_procScene.c \
 *       --func DWCi_SceneOptErase1_procScene --addr 0x021C244C --region ov016 --cc dsi/1.1p1 --arm
 * Guard: if (DWCi_IPTlCheckTrigger(1)) call DWCi_IPTlCheckTrigger.
 *   python tools/match.py one --src src/matched/input.c \
 *       --func input --addr 0x021C2460 --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneOptErase1_draw.c \
 *       --func DWCi_SceneOptErase1_draw --addr 0x021C2480 --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   OS_SpinWaitSysCycles           0x02087A04  arm  arm9
 *   PM_ForceToPowerOff             0x0208BEA4  arm  arm9
 *   DWCi_BTNlSet                   0x021BCB28  arm  ov016
 *   DWCi_IPTlCheckTrigger          0x021D6824  arm  ov016
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_SETTINGlEraseAll            0x021CFC20  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   endScene2                        0x021C2528  arm
 *   initGraphics                     0x021C2340  arm
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm
 */
typedef _Bool bool;

#include "../types.h"
#include "../sdk_ioreg.h"

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

#include "common.h"
#include "setting.h"
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
#include "graphics.h"
#include "dwcutil_main.h"
#include "button.h"
#include "sound.h"
#include "input.h"
#include "../arm9/os_system.h"
#include "../arm9/pm.h"
void DWCi_SceneOptErase1(void);
void DWCi_SceneOptErase1_procScene(void);
void DWCi_SceneOptErase1_draw(void);


static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void input(void);
static void button(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);

void DWCi_SceneOptErase1(void)
{
    initGraphics();
    DWCi_CMNlMsgDraw(0x19);
    DWCi_SETTINGlEraseAll();
    DWCi_ChangeScene(procInit);
}

static void initGraphics(void)
{
    DWCi_CMNlLoadResource((void *)0x021DB2C8, (void *)0x0207EB78);
    ((BgCnt *)REG_DB_BG0CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_DB_BG1CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_BG0CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_BG1CNT_ADDR)->priority = 3;
    ((BgCnt *)REG_BG2CNT_ADDR)->priority = 3;
}

static void procInit(void)
{
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene(procInit1);
}

static void procInit1(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(5);
    DWCi_ChangeScene(procInit2);
}

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(DWCi_SceneOptErase1_procScene);
}

void DWCi_SceneOptErase1_procScene(void)
{
    input();
    DWCi_SceneOptErase1_draw();
    button();
}

static void input(void)
{
    if (DWCi_IPTlCheckTrigger(1))
        DWCi_BTNlSet(0);
}

void DWCi_SceneOptErase1_draw(void)
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
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_EFFlFade(3, 1, 0x3F, 0x40);
    DWCi_EFFlFade(3, 0, 0x3F, 0x40);
    DWCi_ChangeScene(endScene2);
}

/*
 * Bail out on two DWCi_EFFlCheck probes, then arm timer 0x800000 and kick PM_ForceToPowerOff.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/endScene2.c \
 *       --func endScene2 --addr 0x021C2528 --region ov016 --cc dsi/1.1p1 --arm
 */
static void endScene2(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    OS_SpinWaitSysCycles(0x800000);
    PM_ForceToPowerOff();
}
