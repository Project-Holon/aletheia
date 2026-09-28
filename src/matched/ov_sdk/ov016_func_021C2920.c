/*
 * function: button
 * address:  0x021C2920
 * packet:   pkt_ov016_021C2920
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      button (libdwcutil.TWL.HYB.a sceneoptinfo.o)
 *
 * symbols:
 *   DWCi_BTNlGet     0x021BCB14  arm
 *   DWCi_SNDlPlay    0x021CFFAC  arm
 *   DWCi_ChangeScene 0x021C0E40  arm
 *   endScene         0x021C2948  arm
 */

int DWCi_BTNlGet(void);
void DWCi_SNDlPlay(int no);
void DWCi_ChangeScene(void (*scene)(void));
void endScene(void);

void button(void)
{
    if (DWCi_BTNlGet() != 0) return;
    DWCi_SNDlPlay(7);
    DWCi_ChangeScene(endScene);
}
