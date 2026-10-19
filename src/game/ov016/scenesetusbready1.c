/*
 * file:     scenesetusbready1.c
 * unit:     yes
 * function: DWCi_IsFold, DWCi_SceneSetUsbReady1, initGraphics, procInit, DWCi_SceneSetUsbReady1ProcInit1, DWCi_SceneSetUsbReady1ProcInit2, DWCi_SceneSetUsbReady1Update, input, DWCi_SceneSetUsbReady1UpdateNop, button, endScene, DWCi_SceneSetUsbReady1EndScene1, DWCi_SceneSetUsbReady1EndScene2, cbUsb, procNotFound, DWCi_SceneSetUsbReady1ProcNotFound1, procBoth, DWCi_SceneSetUsbReady1ProcBoth1
 * address:  0x021CE050
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      DWCi_SceneSetUsbReady1 (libdwcutil.TWL.HYB.a scenesetusbready)
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/DWCi_SceneSetUsbReady1.c \n *       --func DWCi_SceneSetUsbReady1 --addr 0x021CE070 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 * Load three tilemaps through DWCi_CMNlLoadResource, then set the low two bits of five
 * halfword registers (the 0x04001008/0x04000008 pair and their +2 neighbours).
 * Addresses are Black-image addresses.
 * Call input, DWCi_SceneSetUsbReady1UpdateNop, button.
 *   python tools/match.py one --src src/matched/DWCi_SceneSetUsbReady1Update.c \
 *       --func DWCi_SceneSetUsbReady1Update --addr 0x021CE23C --region ov016 --cc dsi/1.1p1 --arm
 * Two-stage guard around DWCi_BTNlSet.
 *   python tools/match.py one --src src/matched/input.c \
 *       --func input --addr 0x021CE250 --region ov016 --cc dsi/1.1p1 --arm
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneSetUsbReady1UpdateNop.c \
 *       --func DWCi_SceneSetUsbReady1UpdateNop --addr 0x021CE288 --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_BTNlSet                   0x021BCB28  arm  ov016
 *   DWCi_IPTlCheckTrigger          0x021D6824  arm  ov016
 *   gSceneSetUsbReady1UsbState     0x021DE62C  data
 *   DWCi_HLlLoad  0x021BD674  arm  ov016
 *   DWCi_CMNlStep  0x021BD214  arm  ov016
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   MIi_CpuClear16  0x02082A48  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   DWCi_CMNlMsgNameDraw  0x021BD310  arm  ov016
 *   DWCi_ANIMElInitEx  0x021BC820  arm  ov016
 *   DWCi_USBAPlBegin  0x021D0B44  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   procInit  0x021CE1B0  arm  ov016
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   gSceneSetUsbReady1PathChar    0x021DB880  data
 *   gSceneSetUsbReady1PathPltt    0x021DB898  data
 *   gSceneSetUsbReady1PathScr    0x021DB8B0  data
 *   GX_LoadBG2Char    0x0207F0B8  data
 *   GX_LoadBGPltt    0x0207E3D0  data
 *   GX_LoadBG2Scr    0x0207EB78  data
 *   Choose                           0x021DE62C  data
 *   DWCi_ANIMElEnd                   0x021BC8EC  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlIsEnd                   0x021BCB58  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   DWCi_SceneSetSelectAp            0x021CBC90  arm
 *   DWCi_SceneSetUsbComplete         0x021CDA88  arm
 *   DWCi_SceneSetUsbReady            0x021CDCAC  arm
 *   DWCi_SceneSetUsbReady1           0x021CE070  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   DWCi_USBAPlEnd                   0x021D0CEC  arm
 *   DWCi_USBAPlSetCallback           0x021D0DC8  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   cbUsb                            0x021CE45C  arm
 *   DWCi_WINlInitEx  0x021D1208  arm  ov016
 *   procNotFound  0x021CE564  arm  ov016
 *   endScene  0x021CE2D4  arm  ov016
 *   procBoth  0x021CE5B0  arm  ov016
 *   procConfirm                      0x021C22AC  arm
 *   sceneopterase_bss                0x021DE5A4  data
 */
#include "../sdk_os.h"

typedef struct {
    unsigned char favoriteColor;
    unsigned char pad;
    unsigned char birthMonth;
    unsigned char birthDay;
    unsigned short nickName[11];
    unsigned short nickNameLength;
    unsigned short comment[27];
    unsigned short commentLength;
} OwnerInfo;

#include "../types.h"

typedef _Bool bool;

/* sceneopterase.o .bss at 0x021DE5A4, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
} SCENEOPTERASE_BSS;

extern void OS_GetOwnerInfo(struct OSOwnerInfo *info);
extern void MIi_CpuClear16(unsigned short value, void *destp, unsigned long size);
extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
extern void DWCi_CMNlMsgNameDraw(unsigned short *name, int msgId);
extern void DWCi_ANIMElInitEx(int color);
extern int DWCi_USBAPlBegin(void (*callback)(int));
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void DWCi_HLlLoad(int idx);
extern int DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern int DWCi_COMMENTlDelete(void);
extern void DWCi_CMNlStep(int step);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_CMNlButton(int kind);
extern char DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlDisable(void);
extern int DWCi_BTNlIsEnd(void);
extern void DWCi_BTNlEnd(void);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_SNDlStop(void);
extern char DWCi_WINlGet(void);
extern void DWCi_WINlEnd(void);
extern bool DWCi_WINlIsInit(void);
extern int DWCi_USBAPlEnd(void);
extern void DWCi_USBAPlSetCallback(void (*callback)(int));
extern void DWCi_ANIMElEnd(void);
extern void DWCi_SceneSetSelectAp(void);
extern void DWCi_SceneSetUsbReady(void);
void DWCi_SceneSetUsbReady1(void);
extern void DWCi_SceneSetUsbComplete(void);
extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern void DWCi_BTNlSet(signed char v);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
void DWCi_SceneSetUsbReady1Update(void);
void DWCi_SceneSetUsbReady1UpdateNop(void);
extern unsigned char gSceneSetUsbReady1UsbState;
extern unsigned short gSceneSetUsbReady1PathChar[];
extern unsigned short gSceneSetUsbReady1PathPltt[];
extern unsigned short gSceneSetUsbReady1PathScr[];
extern unsigned short GX_LoadBG2Char[];
extern unsigned short GX_LoadBGPltt[];
extern unsigned short GX_LoadBG2Scr[];
/* this member's .bss at 0x021DE62C: the choice that picks the next scene */
extern unsigned char Choose;
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
static void cbUsb(int state);
static void procNotFound(void);
static void procNotFound1(void);
static void procBoth(void);
static void procBoth1(void);

/*
 * Bit 15 of the halfword at 0x02FFFFA8 (lid closed), as 0/1: this scene's own
 * copy of the libdwcutil helper.
 */
static int DWCi_IsFold(void)
{
    return ((*(unsigned short *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}

void DWCi_SceneSetUsbReady1(void)
{
    OwnerInfo info;
    unsigned short buf[11];
    gSceneSetUsbReady1UsbState = 0;
    initGraphics();
    DWCi_HLlLoad(8);
    DWCi_CMNlStep(2);
    OS_GetOwnerInfo((struct OSOwnerInfo *)(&info));
    MIi_CpuClear16(0, buf, 0x16);
    MIi_CpuCopy16(info.nickName, buf, info.nickNameLength * 2);
    DWCi_CMNlMsgNameDraw(buf, 40);
    DWCi_ANIMElInitEx(0);
    DWCi_USBAPlBegin(cbUsb);
    DWCi_SNDlPlay(11);
    DWCi_ChangeScene(procInit);
}

static void initGraphics(void)
{
    u16 *p;

    DWCi_CMNlLoadResource((char *)((int)gSceneSetUsbReady1PathChar), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Char));
    DWCi_CMNlLoadResource((char *)((int)gSceneSetUsbReady1PathPltt), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBGPltt));
    DWCi_CMNlLoadResource((char *)((int)gSceneSetUsbReady1PathScr), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Scr));

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
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
    DWCi_CMNlButton(2);
    DWCi_ChangeScene(procInit2);
}

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(DWCi_SceneSetUsbReady1Update);
}

void DWCi_SceneSetUsbReady1Update(void)
{
    input();
    DWCi_SceneSetUsbReady1UpdateNop();
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

void DWCi_SceneSetUsbReady1UpdateNop(void)
{
}

static void button(void)
{
    if (Choose != 0)
        return;
    if (DWCi_BTNlGet() != 0)
        return;
    Choose = 2;
    DWCi_SNDlStop();
    DWCi_SNDlPlay(7);
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
    DWCi_BTNlEnd();
    if (Choose == 2 || Choose == 3)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene2);
}

static void endScene2(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    if (Choose == 2 && DWCi_EFFlCheck(1))
        return;
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_USBAPlEnd();
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    if (Choose == 2 || Choose == 3) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if (Choose == 2) {
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene(DWCi_SceneSetSelectAp);
    } else if (Choose == 3) {
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene(DWCi_SceneSetUsbReady);
    } else {
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene(DWCi_SceneSetUsbComplete);
    }
}

/*
 * sdk:      cbUsb (libdwcutil.TWL.HYB.a scenesetusbready)
 */
static void cbUsb(int state)
{
    if (gSceneSetUsbReady1UsbState != 0)
        return;
    switch (state) {
    case 0:
        gSceneSetUsbReady1UsbState = 3;
        DWCi_SNDlStop();
        DWCi_SNDlPlay(0x12);
        DWCi_WINlInitEx(0x10, 1, 1, -1, 0);
        DWCi_BTNlDisable();
        DWCi_ChangeScene(procNotFound);
        break;
    case 1:
        gSceneSetUsbReady1UsbState = 1;
        DWCi_SNDlStop();
        DWCi_ChangeScene(endScene);
        break;
    case 2:
        DWCi_SNDlStop();
        DWCi_USBAPlSetCallback(0);
        DWCi_WINlInitEx(0x11, 0, 1, -1, 0);
        DWCi_BTNlDisable();
        DWCi_ChangeScene(procBoth);
        break;
    case 3:
        gSceneSetUsbReady1UsbState = 2;
        DWCi_SNDlStop();
        DWCi_SNDlPlay(9);
        DWCi_ChangeScene(endScene);
        break;
    }
}

static void procNotFound(void)
{
    if (DWCi_WINlGet() != 0)
        return;
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_ChangeScene(procNotFound1);
}

static void procConfirm(void);

static void procNotFound1(void)
{
    if (DWCi_WINlIsInit())
        return;
    DWCi_ChangeScene(endScene);
}

static void procBoth(void)
{
    switch (DWCi_WINlGet()) {
    case 1:
        Choose = 3;
        DWCi_SNDlPlay(6);
        break;
    case 0:
        Choose = 1;
        DWCi_SNDlPlay(7);
        break;
    default:
        return;
    }
    DWCi_WINlEnd();
    DWCi_ChangeScene(procBoth1);
}

static void procBoth1(void)
{
    if (DWCi_WINlIsInit())
        return;
    if (Choose == 1) {
        DWCi_ChangeScene(endScene);
        return;
    }
    DWCi_SNDlPlay(11);
    DWCi_BTNlEnable();
    Choose = 0;
    DWCi_USBAPlSetCallback(cbUsb);
    DWCi_ChangeScene(DWCi_SceneSetUsbReady1Update);
}
