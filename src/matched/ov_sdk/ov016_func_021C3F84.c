/*
 * function: func_021C3F84
 * address:  0x021C3F84
 * packet:   pkt_ov016_021C3F84
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      button (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 *
 * symbols:
 *   DWCi_BTNlGet  0x021BCB14  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneOptMovFailureWork     0x021DE5C0  data
 *   func_021C3FD4  0x021C3FD4  arm  ov016
 */

extern signed char DWCi_BTNlGet(void);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C3FD4();
extern unsigned char gSceneOptMovFailureWork[];

void func_021C3F84(void)
{
    int r = DWCi_BTNlGet();
    if (r != 0) {
        if (r != 1)
            return;
        gSceneOptMovFailureWork[1] = 1;
        DWCi_SNDlPlay(6);
    } else {
        gSceneOptMovFailureWork[1] = 0;
        DWCi_SNDlPlay(7);
    }
    DWCi_ChangeScene((unsigned int)func_021C3FD4);
}
