/*
 * function: func_021C3FF4
 * address:  0x021C3FF4
 * packet:   pkt_ov016_021C3FF4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_BTNlEnd  0x021BCAE4  arm  ov016
 *   DWCi_EFFlFade  0x021D55A4  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneOptMovFailureWork     0x021DE5C0  data
 *   func_021C405C  0x021C405C  arm  ov016
 */

extern int DWCi_EFFlCheck();
extern void DWCi_BTNlEnd();
extern void DWCi_EFFlFade();
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C405C();
extern unsigned char gSceneOptMovFailureWork[];

void func_021C3FF4(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_BTNlEnd();
    if (!gSceneOptMovFailureWork[1])
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene((unsigned int)func_021C405C);
}
