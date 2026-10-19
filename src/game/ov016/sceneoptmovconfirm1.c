/*
 * file:     sceneoptmovconfirm1.c
 * unit:     yes
 * function: closeFadeStep, closeWaitStep, DWCi_SceneOptMovConfirm1, initGraphics, procInit, procInit1, DWCi_SceneOptMovConfirm1ProcInit2, DWCi_SceneOptMovConfirm1_procScene, input, DWCi_SceneOptMovConfirm1_draw, button, endScene, endFadeOutBoth, DWCi_SceneOptMovConfirm1EndScene2
 * address:  0x021C3794
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Call input, DWCi_SceneOptMovConfirm1_draw, button.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovConfirm1_procScene.c \
 *       --func DWCi_SceneOptMovConfirm1_procScene --addr 0x021C39A4 --region ov016 --cc dsi/1.1p1 --arm
 * Two guarded DWCi_BTNlSet calls keyed off DWCi_IPTlCheckTrigger.
 *   python tools/match.py one --src src/matched/input.c \
 *       --func input --addr 0x021C39B8 --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovConfirm1_draw.c \
 *       --func DWCi_SceneOptMovConfirm1_draw --addr 0x021C39F4 --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_BTNlSet                   0x021BCB28  arm  ov016
 *   DWCi_IPTlCheckTrigger          0x021D6824  arm  ov016
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_BTNlIsEnd                   0x021BCB58  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   DWCi_SceneOptMovWait             0x021C450C  arm
 *   DWCi_HLlLoad  0x021BD674  arm  ov016
 *   DWCi_COMMENTlDispEx  0x021BD060  arm  ov016
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm  ov016
 *   gSceneOptMovConfirm1Work     0x021DE5B8  data
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm
 *   DWCi_GXlVisible  0x021D603C  arm  ov016
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_SNDlPlay  0x021CFFAC  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   sceneopterase_bss                0x021DE5B8  data
 *   DWCi_COMMENTlDelete  0x021BD138  arm
 *   DWCi_SceneOptMenu  0x021C2A3C  arm
 *   DWCi_SceneOptMovConfirm  0x021C35F0  arm
 */

typedef _Bool bool;

#include "../types.h"

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

/* sceneopterase.o .bss at 0x021DE5A4, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
} SCENEOPTERASE_BSS;

extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_BTNlEnd(void);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_ChangeScene(void (*scene)(void));
extern int DWCi_BTNlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void DWCi_CMNlButton(int kind);
extern char DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern void DWCi_BTNlSet(signed char v);
extern void DWCi_BTNlDisable(void);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_CMNlMsgDraw(int msgId);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_HLlLoad(int idx);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern char DWCi_WINlGet(void);
extern void DWCi_WINlEnd(void);
extern int DWCi_WINlIsInit(void);
extern int DWCi_COMMENTlDelete(void);
extern void DWCi_SceneOptMenu(void);
extern void DWCi_SceneOptMovConfirm(void);
void DWCi_SceneOptMovConfirm1(void);
void DWCi_SceneOptMovConfirm1_procScene(void);
void DWCi_SceneOptMovConfirm1_draw(void);
void DWCi_SceneOptMovConfirm1EndScene2(void);
extern SCENEOPTERASE_BSS sceneopterase_bss;

static void closeFadeStep(void);
static void closeWaitStep(void);
static void initGraphics(void);
static void procInit(void);
static void initButtonsStep(void);
static void enableButtonsStep(void);
static void input(void);
static void button(void);
static void endDisableButtons(void);
static void endFadeOutBoth(void);

static void closeFadeStep(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_BTNlEnd();
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(closeWaitStep);
}

static void DWCi_SceneOptMovWait(void);

static void closeWaitStep(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_SetParam_(0, 1);
    DWCi_ChangeScene(DWCi_SceneOptMovWait);
}

/*
 * sdk:      DWCi_SceneOptMovConfirm1 (libdwcutil.TWL.HYB.a sceneoptmovconfirm1.o)
 */
void DWCi_SceneOptMovConfirm1(void)
{
    sceneopterase_bss.Choose = 0;
    initGraphics();
    DWCi_HLlLoad(0x13);
    DWCi_COMMENTlDispEx(0x3C, -1, 0);
    DWCi_CMNlMsgDraw(0x1B);
    DWCi_ChangeScene(procInit);
}

static void initGraphics(void)
{
    DWCi_CMNlLoadResource((void *)0x021DB37C, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}

/*
 * sdk:      procInit (libdwcutil.TWL.HYB.a(sceneoptmovconfi))
 */
static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene(initButtonsStep);
}

static void initButtonsStep(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(3);
    DWCi_ChangeScene(enableButtonsStep);
}

static void enableButtonsStep(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(DWCi_SceneOptMovConfirm1_procScene);
}

void DWCi_SceneOptMovConfirm1_procScene(void)
{
    input();
    DWCi_SceneOptMovConfirm1_draw();
    button();
}

static void input(void)
{
    if (DWCi_IPTlCheckTrigger(1))
        DWCi_BTNlSet(1);
    if (DWCi_IPTlCheckTrigger(2))
        DWCi_BTNlSet(0);
}

void DWCi_SceneOptMovConfirm1_draw(void)
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
        sceneopterase_bss.Choose = 1;
        break;
    default:
        return;
    }
    DWCi_ChangeScene(endDisableButtons);
}

static void endDisableButtons(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endFadeOutBoth);
}

static void endFadeOutBoth(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_BTNlEnd();
    if (sceneopterase_bss.Choose == 0)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(DWCi_SceneOptMovConfirm1EndScene2);
}

/*
 * The final DWCi_SetParam_(0, 1) is written in both arms: the original emits
 * it once per arm, not merged before the branch.
 */
void DWCi_SceneOptMovConfirm1EndScene2(void)
{
    if (DWCi_EFFlCheck(0) != 0)
        return;
    if (sceneopterase_bss.Choose == 0) {
        if (DWCi_EFFlCheck(1) != 0)
            return;
    }
    if (DWCi_BTNlIsEnd() == 0)
        return;
    DWCi_FNTlDeleteBgLcd(0);
    if (sceneopterase_bss.Choose == 0) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if (sceneopterase_bss.Choose == 0) {
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene(DWCi_SceneOptMenu);
    } else {
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene(DWCi_SceneOptMovConfirm);
    }
}
