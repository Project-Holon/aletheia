/*
 * function: DWCi_SceneOptMovConfirm1
 * address:  0x021C3824
 * packet:   pkt_ov016_021C3824
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneOptMovConfirm1 (libdwcutil.TWL.HYB.a sceneoptmovconfirm1.o)
 *
 * symbols:
 *   func_021C386C  0x021C386C  arm  ov016
 *   DWCi_HLlLoad  0x021BD674  arm  ov016
 *   DWCi_COMMENTlDispEx  0x021BD060  arm  ov016
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneOptMovConfirm1Work     0x021DE5B8  data
 *   func_021C38EC  0x021C38EC  arm  ov016
 */

#include "../include/G_021DE5B8.h"

extern void func_021C386C();
extern void DWCi_HLlLoad();
extern int DWCi_COMMENTlDispEx();
extern void DWCi_CMNlMsgDraw();
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C38EC();
extern struct G_021DE5B8 gSceneOptMovConfirm1Work;

void DWCi_SceneOptMovConfirm1(void)
{
    (*(unsigned char *)&gSceneOptMovConfirm1Work) = 0;
    func_021C386C();
    DWCi_HLlLoad(0x13);
    DWCi_COMMENTlDispEx(0x3C, -1, 0);
    DWCi_CMNlMsgDraw(0x1B);
    DWCi_ChangeScene((unsigned int)func_021C38EC);
}
