/*
 * file:     unit_021C39F8.c
 * unit:     yes
 * function: func_021C39F8, func_021C3A48
 * address:  0x021C39F8
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
 *   func_021BCB14  0x021BCB14  arm
 *   func_021CFFAC  0x021CFFAC  arm
 *   func_021C0E40  0x021C0E40  arm
 *   func_021C3A48  0x021C3A48  arm
 *   g_021DE5B8  0x021DE5B8  data  a1
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   endScene1                        0x021C3A68  arm
 */
#include "../../matched/include/G_021DE5B8.h"

typedef _Bool bool;

extern signed char func_021BCB14(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021C0E40(unsigned int v);
extern void func_021C3A48(void);
extern void DWCi_BTNlDisable(void);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_ChangeScene(void (*scene)());
void func_021C39F8(void);
extern struct G_021DE5B8 g_021DE5B8;


/*
 * sdk:      button (libdwcutil.TWL.HYB.a(sceneoptmovconfi))
 */
void func_021C39F8(void)
{
    switch (func_021BCB14()) {
    case 0:
        func_021CFFAC(7);
        break;
    case 1:
        func_021CFFAC(6);
        (*(unsigned char *)&g_021DE5B8) = 1;
        break;
    default:
        return;
    }
    func_021C0E40((unsigned int)func_021C3A48);
}


static void endScene1(void);


static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}
