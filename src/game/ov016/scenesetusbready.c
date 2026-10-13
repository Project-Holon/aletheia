/*
 * file:     scenesetusbready.c
 * unit:     yes
 * function: DWCi_SceneSetUsbReady, func_021CDCFC, func_021CDDA4, func_021CDE0C, func_021CDE48, DWCi_SceneSetUsbReadyUpdate, func_021CDE80, DWCi_SceneSetUsbReadyUpdateNop, func_021CDEC0, func_021CDF10, endScene1, endScene2, func_021CE050
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
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDCAC.c \
 *       --func DWCi_SceneSetUsbReady --addr 0x021CDCAC --region ov016 --cc 1.1p1 --arm --lang c99
 * Call func_021CDE80, DWCi_SceneSetUsbReadyUpdateNop, func_021CDEC0.
 * Addresses are Black-image addresses.
 *   python tools/match.py one --src src/matched/DWCi_SceneSetUsbReadyUpdate.c \
 *       --func DWCi_SceneSetUsbReadyUpdate --addr 0x021CDE6C --region ov016 --cc dsi/1.1p1 --arm
 * Two guarded func_021BCB28 calls keyed off func_021D6824.
 *   python tools/match.py one --src src/matched/func_021CDE80.c \
 *       --func func_021CDE80 --addr 0x021CDE80 --region ov016 --cc dsi/1.1p1 --arm
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
 * Bit 15 of the halfword at 0x02FFFFA8, as 0/1.
 *   python tools/match.py one --src src/matched/func_021CE050.c \
 *       --func func_021CE050 --addr 0x021CE050 --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   Choose                           0x021DE628  data
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
 *   procScene                        0x021CDE6C  arm
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   dat_021DB83C    0x021DB83C  data
 *   dat_021DB854    0x021DB854  data
 *   dat_021DB86C    0x021DB86C  data
 *   dat_0207F0B8    0x0207F0B8  data
 *   dat_0207E3D0    0x0207E3D0  data
 *   dat_0207EB78    0x0207EB78  data
 *   func_021BCB14  0x021BCB14  arm
 *   func_021CFFAC  0x021CFFAC  arm
 *   func_021C0E40  0x021C0E40  arm
 *   func_021CDF10  0x021CDF10  arm
 *   g_021DE628  0x021DE628  data  a1
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   procConfirm                      0x021C22AC  arm
 *   procConfirm1                     0x021C22FC  arm
 *   sceneopterase_bss                0x021DE628  data
 */
#include "../../matched/include/G_021DE628.h"

typedef _Bool bool;

typedef unsigned short u16;

/* sceneopterase.o .bss at 0x021DE5A4, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
} SCENEOPTERASE_BSS;

extern void DWCi_HLlLoad(int idx);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_CMNlStep(int step);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_CMNlButton(int kind);
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlDisable(void);
extern bool DWCi_BTNlIsEnd(void);
extern void DWCi_BTNlEnd(void);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_SetParam_(void *param0, void *param1);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_SNDlStop(void);
extern int DWCi_WINlGet(void);
extern void DWCi_WINlEnd(void);
extern bool DWCi_WINlIsInit(void);
extern bool DWCi_USBAPlEnd(void);
extern void DWCi_USBAPlSetCallback(void (*callback)(int));
extern void DWCi_ANIMElEnd(void);
extern void DWCi_SceneSetSelectAp(void);
extern void DWCi_SceneSetUsbReady1(void);
extern void DWCi_SceneSetUsbComplete(void);
extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern int func_021D6824(unsigned int f);
extern void func_021BCB28(signed char v);
extern signed char func_021BCB14(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021C0E40(unsigned int v);
extern void func_021CDF10(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
void DWCi_SceneSetUsbReady(void);
void func_021CDCFC(void);
void DWCi_SceneSetUsbReadyUpdate(void);
void func_021CDE80(void);
void DWCi_SceneSetUsbReadyUpdateNop(void);
void func_021CDEC0(void);
int func_021CE050(void);
/* scenesetusbready .bss at 0x021DE628 */
extern unsigned char Choose;
extern unsigned short dat_021DB83C[];
extern unsigned short dat_021DB854[];
extern unsigned short dat_021DB86C[];
extern unsigned short dat_0207F0B8[];
extern unsigned short dat_0207E3D0[];
extern unsigned short dat_0207EB78[];
extern struct G_021DE628 g_021DE628;
extern SCENEOPTERASE_BSS sceneopterase_bss;


static void initGraphics(void);

static void procInit(void);

static void procInit1(void);

static void procInit2(void);

static void procScene(void);

static void endScene2(void);


void DWCi_SceneSetUsbReady(void)
{
    Choose = 0;
    initGraphics();
    DWCi_HLlLoad(8);
    DWCi_COMMENTlDispEx(0x38, -1, 0);
    DWCi_CMNlStep(1);
    DWCi_CMNlMsgDraw(0x27);
    DWCi_ChangeScene(procInit);
}



/*
 * Load three tilemaps through func_021BD1D4, then set the low two bits of five
 * halfword registers (the 0x04001008/0x04000008 pair and their +2 neighbours).
 * Addresses are Black-image addresses.
 */
void func_021CDCFC(void)
{
    u16 *p;

    func_021BD1D4((char *)((int)dat_021DB83C), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207F0B8));
    func_021BD1D4((char *)((int)dat_021DB854), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207E3D0));
    func_021BD1D4((char *)((int)dat_021DB86C), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207EB78));

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
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene(procInit1);
}



static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(6);
    DWCi_ChangeScene(procInit2);
}



static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}


void DWCi_SceneSetUsbReadyUpdate(void)
{
    func_021CDE80();
    DWCi_SceneSetUsbReadyUpdateNop();
    func_021CDEC0();
}


void func_021CDE80(void)
{
    if (func_021D6824(1))
        func_021BCB28(1);
    if (func_021D6824(2))
        func_021BCB28(0);
}

void DWCi_SceneSetUsbReadyUpdateNop(void)
{
}



/*
 * sdk:      button (libdwcutil.TWL.HYB.a(sceneoptmovconfi))
 */
void func_021CDEC0(void)
{
    switch (func_021BCB14()) {
    case 0:
        func_021CFFAC(7);
        break;
    case 1:
        func_021CFFAC(6);
        (*(unsigned char *)&g_021DE628) = 1;
        break;
    default:
        return;
    }
    func_021C0E40((unsigned int)func_021CDF10);
}



static void endScene1(void);



static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}

static void procConfirm(void);

static void procConfirm1(void);

static void endScene(void);


static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_BTNlEnd();
    if (sceneopterase_bss.Choose == 0)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene2);
}


static void endScene2(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    if (Choose == 0 && DWCi_EFFlCheck(1))
        return;
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_FNTlDeleteBgLcd(0);
    if (Choose == 0) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if (Choose == 0) {
        DWCi_SetParam_((void *)2, (void *)1);
        DWCi_ChangeScene(DWCi_SceneSetSelectAp);
    } else {
        DWCi_SetParam_((void *)2, (void *)1);
        DWCi_ChangeScene(DWCi_SceneSetUsbReady1);
    }
}

int func_021CE050(void)
{
    return ((*(unsigned short *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}
