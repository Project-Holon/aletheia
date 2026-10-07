/*
 * file:     unit_021CE28C.c
 * unit:     yes
 * function: func_021CE28C, func_021CE2D4, func_021CE2F4, func_021CE364, func_021CE45C, func_021CE564, func_021CE590, func_021CE5B0, func_021CE604
 * address:  0x021CE28C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   Choose                           0x021DE62C  data
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
 *   DWCi_SceneSetUsbReady            0x021CDCAC  arm
 *   DWCi_SceneSetUsbReady1           0x021CE070  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   DWCi_USBAPlEnd                   0x021D0CEC  arm
 *   DWCi_USBAPlSetCallback           0x021D0DC8  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   cbUsb                            0x021CE45C  arm
 *   procInit                         0x021CE1B0  arm
 *   procInit1                        0x021CE1EC  arm
 *   procInit2                        0x021CE218  arm
 *   procScene                        0x021CE23C  arm
 *   func_021D0014  0x021D0014  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021D1208  0x021D1208  arm  ov016
 *   func_021BCB9C  0x021BCB9C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D0DC8  0x021D0DC8  arm  ov016
 *   func_021CE564  0x021CE564  arm  ov016
 *   func_021CE2D4  0x021CE2D4  arm  ov016
 *   func_021CE5B0  0x021CE5B0  arm  ov016
 *   g_021DE62C  0x021DE62C  data
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   initGraphics                     0x021C1F64  arm
 *   procConfirm                      0x021C22AC  arm
 *   sceneopterase_bss                0x021DE5A4  data
 */
typedef _Bool bool;

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
extern void DWCi_SceneSetUsbReady(void);
extern void DWCi_SceneSetUsbReady1(void);
extern void DWCi_SceneSetUsbComplete(void);
extern void func_021D0014(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021D1208(int msg, int type, unsigned char dark, int n, int num);
extern void func_021BCB9C(void);
extern void func_021C0E40(unsigned int v);
extern void func_021D0DC8(unsigned int v);
extern void func_021CE564(void);
extern void func_021CE2D4(void);
extern void func_021CE5B0(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
void func_021CE45C(int state);
/* this member's .bss at 0x021DE62C: the choice that picks the next scene */
extern unsigned char Choose;
extern unsigned char g_021DE62C;
extern SCENEOPTERASE_BSS sceneopterase_bss;


static void procInit(void);

static void procInit1(void);

static void procInit2(void);

static void procScene(void);

static void button(void);

static void endScene(void);

static void endScene1(void);

static void endScene2(void);

static void cbUsb(int result);

static void procNotFound(void);

static void procConfirm1(void);

static void procBoth(void);

static void procBoth1(void);


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
        DWCi_SetParam_((void *)2, (void *)1);
        DWCi_ChangeScene(DWCi_SceneSetSelectAp);
    } else if (Choose == 3) {
        DWCi_SetParam_((void *)2, (void *)1);
        DWCi_ChangeScene(DWCi_SceneSetUsbReady);
    } else {
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene(DWCi_SceneSetUsbComplete);
    }
}


/*
 * sdk:      cbUsb (libdwcutil.TWL.HYB.a scenesetusbready)
 */
void func_021CE45C(int state)
{
    if (g_021DE62C != 0)
        return;
    switch (state) {
    case 0:
        g_021DE62C = 3;
        func_021D0014();
        func_021CFFAC(0x12);
        func_021D1208(0x10, 1, 1, -1, 0);
        func_021BCB9C();
        func_021C0E40((unsigned int)func_021CE564);
        break;
    case 1:
        g_021DE62C = 1;
        func_021D0014();
        func_021C0E40((unsigned int)func_021CE2D4);
        break;
    case 2:
        func_021D0014();
        func_021D0DC8(0);
        func_021D1208(0x11, 0, 1, -1, 0);
        func_021BCB9C();
        func_021C0E40((unsigned int)func_021CE5B0);
        break;
    case 3:
        g_021DE62C = 2;
        func_021D0014();
        func_021CFFAC(9);
        func_021C0E40((unsigned int)func_021CE2D4);
        break;
    }
}


static void procNotFound(void)
{
    if (DWCi_WINlGet() != 0)
        return;
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_ChangeScene(procConfirm1);
}


static void initGraphics(void);

static void procConfirm(void);


static void procConfirm1(void)
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
    DWCi_ChangeScene(procScene);
}
