/*
 * file:     sceneoptmovwait.c
 * unit:     yes
 * function: DWCi_IsFold, DWCi_SceneOptMovWait, initGraphics, DWCi_SceneOptMovWaitProcInit, DWCi_SceneOptMovWaitProcInit1, procInit2, DWCi_SceneOptMovWait_procScene, input, DWCi_SceneOptMovWait_draw, button, endScene, endScene1, endScene2, DWCi_SceneOptMovWaitCbMov
 * address:  0x021C44EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      procInit2 (sceneoptmovuser.o), TwlDWC libdwcutil.TWL.HYB.a
 * Call input, DWCi_SceneOptMovWait_draw, button.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovWait_procScene.c \
 *       --func DWCi_SceneOptMovWait_procScene --addr 0x021C4660 --region ov016 --cc dsi/1.1p1 --arm
 * Two-stage guard around DWCi_BTNlSet.
 *   python tools/match.py one --src src/matched/input.c \
 *       --func input --addr 0x021C4674 --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovWait_draw.c \
 *       --func DWCi_SceneOptMovWait_draw --addr 0x021C46AC --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_BTNlSet                   0x021BCB28  arm  ov016
 *   DWCi_BTNlDisable               0x021BCB9C  arm  ov016
 *   DWCi_MOVlEnd                   0x021C115C  arm  ov016
 *   DWCi_EFFlWait                  0x021D5790  arm  ov016
 *   DWCi_IPTlCheckTrigger          0x021D6824  arm  ov016
 *   DWCi_MOVlInit                    0x021C1074  arm
 *   initGraphics                     0x021C4558  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_ANIMElInitEx                0x021BC820  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_SceneOptMovWaitCbMov                            0x021C4890  arm
 *   Choose                           0x021DE5C8  data
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   endScene                         0x021C46DC  arm
 *   DWCi_MOVlIsEnd  0x021C11B8  arm
 *   DWCi_BTNlEnd  0x021BCAE4  arm
 *   gSceneOptMovWaitWork     0x021DE5C8  data
 *   DWCi_BTNlIsEnd  0x021BCB58  arm  ov016
 *   DWCi_ANIMElEnd  0x021BC8EC  arm  ov016
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm  ov016
 *   DWCi_COMMENTlDelete  0x021BD138  arm  ov016
 *   DWCi_GXlInvisible  0x021D6090  arm  ov016
 *   DWCi_SetParam_  0x021C0E50  arm  ov016
 *   DWCi_SceneOptMenu  0x021C2A3C  arm  ov016
 *   DWCi_SceneOptMovFailure  0x021C3D8C  arm  ov016
 *   DWCi_SceneOptMovUser  0x021C4110  arm  ov016
 *   DWCi_MOVlChangeCallback  0x021C11D4  arm  ov016
 */
#include "../types.h"

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

typedef _Bool bool;

extern void DWCi_MOVlInit(void (*callback)(int));
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_ANIMElInitEx(int color);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_ChangeScene(void (*scene)());
void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_CMNlButton(int kind);
extern int DWCi_BTNlGet(void);
extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern void DWCi_BTNlSet(signed char v);
extern void DWCi_SNDlStop(void);
extern void DWCi_MOVlEnd(void);
extern void DWCi_BTNlDisable(void);
extern void DWCi_EFFlWait(int);
extern int  DWCi_MOVlIsEnd(void);
extern void DWCi_BTNlEnd(void);
extern int DWCi_BTNlIsEnd();
extern void DWCi_ANIMElEnd();
extern void DWCi_FNTlDeleteBgLcd(int a);
extern int DWCi_COMMENTlDelete();
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SceneOptMenu();
extern void DWCi_SceneOptMovFailure();
extern void DWCi_SceneOptMovUser();
extern void DWCi_MOVlChangeCallback(unsigned int v);
static int DWCi_IsFold(void);
void DWCi_SceneOptMovWait(void);
void DWCi_SceneOptMovWait_procScene(void);
void DWCi_SceneOptMovWait_draw(void);
extern unsigned char Choose;
extern u8   gSceneOptMovWaitWork;

/*
 * Bit 15 of the halfword at 0x02FFFFA8, as 0/1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_IsFold.c \
 *       --func DWCi_IsFold --addr 0x021C44EC --region ov016 --cc dsi/1.1p1 --arm
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
static void DWCi_SceneOptMovWaitCbMov(int state);
static int DWCi_IsFold(void)
{
    return ((*(unsigned short *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}

void DWCi_SceneOptMovWait(void)
{
    DWCi_MOVlInit(DWCi_SceneOptMovWaitCbMov);
    Choose = 0;
    initGraphics();
    DWCi_CMNlMsgDraw(0x1c);
    DWCi_ANIMElInitEx(0);
    DWCi_SNDlPlay(0xb);
    DWCi_ChangeScene(procInit);
}

static void initGraphics(void)
{
    DWCi_CMNlLoadResource((void *)0x021DB3CC, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
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
    DWCi_CMNlButton(1);
    DWCi_ChangeScene(procInit2);
}


static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_ChangeScene(DWCi_SceneOptMovWait_procScene);
}

void DWCi_SceneOptMovWait_procScene(void)
{
    input();
    DWCi_SceneOptMovWait_draw();
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

void DWCi_SceneOptMovWait_draw(void)
{
}

static void button(void)
{
    if (DWCi_BTNlGet())
        return;
    DWCi_SNDlStop();
    DWCi_SNDlPlay(7);
    DWCi_ChangeScene(endScene);
}

/*
 * Wake the sub-state, flag it and post the event at 0x021C4714.
 * Addresses are Black-image addresses.
 */
static void endScene(void)
{
    if (*(unsigned char *)0x021DE5C8 == 0)
        DWCi_MOVlEnd();
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1) != 0)
        return;
    if (gSceneOptMovWaitWork == 0) {
        if (DWCi_MOVlIsEnd() == 0)
            return;
    }
    DWCi_BTNlEnd();
    if (gSceneOptMovWaitWork == 0)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene2);
}

/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a sceneoptmovwait.o)
 */
static void endScene2(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    if (gSceneOptMovWaitWork == 0) {
        if (DWCi_EFFlCheck(1))
            return;
    }
    if (!DWCi_BTNlIsEnd())
        return;
    if (gSceneOptMovWaitWork == 0) {
        if (!DWCi_MOVlIsEnd())
            return;
    }
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    if (gSceneOptMovWaitWork == 0) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if (gSceneOptMovWaitWork == 0) {
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene(DWCi_SceneOptMenu);
    } else if (gSceneOptMovWaitWork == 2) {
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene(DWCi_SceneOptMovFailure);
    } else {
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene(DWCi_SceneOptMovUser);
    }
}

/*
 * sdk:      DWCi_SceneOptMovWaitCbMov (libdwcutil.TWL.HYB.a sceneoptmovwait.o)
 */
static void DWCi_SceneOptMovWaitCbMov(int state)
{
    DWCi_SNDlStop();
    if (state == 0) {
        gSceneOptMovWaitWork = 1;
        DWCi_SNDlPlay(0x10);
    } else {
        gSceneOptMovWaitWork = 2;
        DWCi_SNDlPlay(0x12);
    }
    DWCi_MOVlChangeCallback(0);
    DWCi_ChangeScene(endScene);
}
