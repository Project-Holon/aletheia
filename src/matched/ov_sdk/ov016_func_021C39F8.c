/*
 * function: func_021C39F8
 * address:  0x021C39F8
 * packet:   pkt_ov016_021C39F8
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
 *   func_021C3A48  0x021C3A48  arm
 *   gSceneOptMovConfirm1Work  0x021DE5B8  data  a1
 */

#include "../include/G_021DE5B8.h"

extern signed char DWCi_BTNlGet(void);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C3A48(void);
extern struct G_021DE5B8 gSceneOptMovConfirm1Work;

void func_021C39F8(void)
{
    switch (DWCi_BTNlGet()) {
    case 0:
        DWCi_SNDlPlay(7);
        break;
    case 1:
        DWCi_SNDlPlay(6);
        (*(unsigned char *)&gSceneOptMovConfirm1Work) = 1;
        break;
    default:
        return;
    }
    DWCi_ChangeScene((unsigned int)func_021C3A48);
}
