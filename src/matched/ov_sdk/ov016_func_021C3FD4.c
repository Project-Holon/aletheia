/*
 * function: func_021C3FD4
 * address:  0x021C3FD4
 * packet:   pkt_ov016_021C3FD4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 *
 * symbols:
 *   DWCi_BTNlDisable  0x021BCB9C  arm  ov016
 *   DWCi_EFFlWait  0x021D5790  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021C3FF4  0x021C3FF4  arm  ov016
 */

extern void DWCi_BTNlDisable();
extern void DWCi_EFFlWait();
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C3FF4();

void func_021C3FD4(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene((unsigned int)func_021C3FF4);
}
