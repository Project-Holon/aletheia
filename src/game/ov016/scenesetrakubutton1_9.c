/*
 * file:     scenesetrakubutton1_9.c
 * unit:     yes
 * function: func_021CAEBC, func_021CAF78, func_021CB05C
 * address:  0x021CAEBC
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
 *   func_021D5580  0x021D5580  arm
 *   func_021BCB58  0x021BCB58  arm
 *   func_021BC8EC  0x021BC8EC  arm
 *   func_021D5CA8  0x021D5CA8  arm
 *   func_021BD138  0x021BD138  arm
 *   func_021D6090  0x021D6090  arm
 *   func_021C14F4  0x021C14F4  arm
 *   func_021C0E50  0x021C0E50  arm
 *   func_021C0E40  0x021C0E40  arm
 *   func_021CC998  0x021CC998  arm
 *   func_021CB0A8  0x021CB0A8  arm
 *   g_021DE5FC  0x021DE5FC  data  a1
 *   DWCi_RAKUlGetState               0x021c1518 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   DWCi_SNDlStop                    0x021d0014 arm
 *   DWCi_RAKUlSetResult              0x021c15d0 arm
 *   DWCi_SNDlPlay                    0x021cffac arm
 *   DWCi_WINlInitEx                  0x021d1208 arm
 *   DWCi_BTNlDisable                 0x021bcb9c arm
 *   Choose                           0x021de5fc data
 *   endScene                         0x021cae34 arm
 *   DWCi_WINlGet     0x021D1568 arm
 *   DWCi_WINlEnd     0x021D1524 arm
 *   procError1       0x021CB088 arm
 */
#include "../../matched/include/G_021DE5FC.h"

typedef _Bool bool;

extern int func_021D5580(int x);
extern int func_021BCB58(void);
extern void func_021BC8EC(void);
extern void func_021D5CA8(int x);
extern void func_021BD138(void);
extern void func_021D6090(int a, int b);
extern void func_021C14F4(void);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E40(unsigned int v);
extern void func_021CC998(void);
extern void func_021CB0A8(void);
extern int DWCi_RAKUlGetState(void);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_SNDlStop(void);
extern void DWCi_RAKUlSetResult(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern void DWCi_BTNlDisable(void);
int DWCi_WINlGet(void);
void DWCi_WINlEnd(void);
void procError1(void);
void func_021CAEBC(void);
void procError(void);
extern struct G_021DE5FC g_021DE5FC;
extern unsigned char Choose;


/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a(scenesetrakubutt))
 */
void func_021CAEBC(void)
{
    if (func_021D5580(0) != 0)
        return;
    if ((*(unsigned char *)&g_021DE5FC) == 0) {
        if (func_021D5580(1) != 0)
            return;
    }
    if (func_021BCB58() == 0)
        return;
    func_021BC8EC();
    func_021D5CA8(0);
    if ((*(unsigned char *)&g_021DE5FC) == 0) {
        func_021BD138();
        func_021D6090(1, 1);
    }
    func_021C14F4();
    if ((*(unsigned char *)&g_021DE5FC) == 0) {
        func_021C0E50(2, 1);
        func_021C0E40((unsigned int)func_021CC998);
    } else {
        func_021C0E50(0, 0);
        func_021C0E40((unsigned int)func_021CB0A8);
    }
}


static void endScene(void);

static void procError(void);


static void checkRaku(void)
{
    switch (DWCi_RAKUlGetState()) {
    case 3:
        Choose = 1;
        DWCi_SNDlStop();
        DWCi_RAKUlSetResult();
        DWCi_ChangeScene(endScene);
        break;
    case 4:
        Choose = 0;
        DWCi_SNDlStop();
        DWCi_SNDlPlay(9);
        DWCi_WINlInitEx(0xd, 1, 1, -1, 0);
        DWCi_BTNlDisable();
        DWCi_ChangeScene(procError);
        break;
    case 5:
        Choose = 0;
        DWCi_SNDlStop();
        DWCi_SNDlPlay(0x12);
        DWCi_WINlInitEx(0xe, 1, 1, -1, 0);
        DWCi_BTNlDisable();
        DWCi_ChangeScene(procError);
        break;
    }
}


void procError(void)
{
    if (DWCi_WINlGet() == 0) {
        DWCi_SNDlPlay(6);
        DWCi_WINlEnd();
        DWCi_ChangeScene(procError1);
    }
}
