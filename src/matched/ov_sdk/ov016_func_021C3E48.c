/*
 * function: func_021C3E48
 * address:  0x021C3E48
 * packet:   pkt_ov016_021C3E48
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 *
 * symbols:
 *   DWCi_EFFlFade  0x021D55A4  arm  ov016
 *   DWCi_GXlVisible  0x021D603C  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneOptMovFailureWork     0x021DE5C0  data
 *   func_021C3EC4  0x021C3EC4  arm  ov016
 */

extern void DWCi_EFFlFade();
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C3EC4();
extern unsigned char gSceneOptMovFailureWork;

void func_021C3E48(void)
{
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(0, 0x15);
    if (gSceneOptMovFailureWork) {
        DWCi_EFFlFade(2, 1, 1, 8);
        DWCi_GXlVisible(1, 1);
    }
    DWCi_ChangeScene((unsigned int)func_021C3EC4);
}
