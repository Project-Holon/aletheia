/*
 * file:     unit_021C3794.c
 * unit:     yes
 * function: func_021C3794, func_021C37D0, func_021C3824, func_021C386C, func_021C38EC, func_021C3954, func_021C3980
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
 * symbols:
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_BTNlIsEnd                   0x021BCB58  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   DWCi_SceneOptMovWait             0x021C450C  arm
 *   func_021BD674  0x021BD674  arm  ov016
 *   func_021BD060  0x021BD060  arm  ov016
 *   func_021BD29C  0x021BD29C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5B8     0x021DE5B8  data
 *   func_021BD1D4  0x021BD1D4  arm
 *   func_021D55A4  0x021D55A4  arm
 *   func_021D603C  0x021D603C  arm  ov016
 *   func_021C3954  0x021C3954  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   procScene                        0x021C39A4  arm
 */
#include "../../matched/include/G_021DE5B8.h"

typedef _Bool bool;

typedef unsigned short u16;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_BTNlEnd(void);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_ChangeScene(void (*scene)());
extern bool DWCi_BTNlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(void *param0, void *param1);
extern void func_021BD674();
extern int func_021BD060();
extern void func_021BD29C();
extern void func_021C0E40(unsigned int v);
void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void func_021D55A4(int a, int b, int c, int d);
extern void func_021D603C(int a, int b);
extern void func_021C3954(void);
extern void DWCi_CMNlButton(int kind);
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
void func_021C3824(void);
void func_021C386C(void);
void func_021C38EC(void);
extern struct G_021DE5B8 g_021DE5B8;


static void endScene2(void);


static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_BTNlEnd();
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene2);
}


static void DWCi_SceneOptMovWait(void);


static void endScene2(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_SetParam_((void *)0, (void *)1);
    DWCi_ChangeScene(DWCi_SceneOptMovWait);
}


/*
 * sdk:      DWCi_SceneOptMovConfirm1 (libdwcutil.TWL.HYB.a sceneoptmovconfirm1.o)
 */
void func_021C3824(void)
{
    (*(unsigned char *)&g_021DE5B8) = 0;
    func_021C386C();
    func_021BD674(0x13);
    func_021BD060(0x3C, -1, 0);
    func_021BD29C(0x1B);
    func_021C0E40((unsigned int)func_021C38EC);
}


void func_021C386C(void)
{
    func_021BD1D4((void *)0x021DB37C, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}


/*
 * sdk:      procInit (libdwcutil.TWL.HYB.a(sceneoptmovconfi))
 */
void func_021C38EC(void)
{
    func_021D55A4(2, 1, 1, 8);
    func_021D55A4(2, 0, 0x15, 8);
    func_021D603C(1, 1);
    func_021D603C(0, 0x15);
    func_021C0E40((unsigned int)func_021C3954);
}


static void procInit2(void);


static void procInit1(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(3);
    DWCi_ChangeScene(procInit2);
}


static void procScene(void);


static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}
