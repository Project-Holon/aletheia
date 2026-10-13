/*
 * function: func_021CDEC0
 * address:  0x021CDEC0
 * packet:   pkt_ov016_021CDEC0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      button (libdwcutil.TWL.HYB.a(sceneoptmovconfi))
 * symbols:
 *   DWCi_BTNlGet  0x021BCB14  arm
 *   DWCi_SNDlPlay  0x021CFFAC  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   func_021CDF10  0x021CDF10  arm
 *   gSceneSetUsbReadyWork  0x021DE628  data  a1
 */

#include "../include/G_021DE628.h"

extern signed char DWCi_BTNlGet(void);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021CDF10(void);
extern struct G_021DE628 gSceneSetUsbReadyWork;

void func_021CDEC0(void)
{
    switch (DWCi_BTNlGet()) {
    case 0:
        DWCi_SNDlPlay(7);
        break;
    case 1:
        DWCi_SNDlPlay(6);
        (*(unsigned char *)&gSceneSetUsbReadyWork) = 1;
        break;
    default:
        return;
    }
    DWCi_ChangeScene((unsigned int)func_021CDF10);
}
