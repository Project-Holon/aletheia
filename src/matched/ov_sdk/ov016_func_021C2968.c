/*
 * function: endScene1
 * address:  0x021C2968
 * packet:   pkt_ov016_021C2968
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a sceneoptinfo.o)
 *
 * symbols:
 *   DWCi_EFFlCheck   0x021D5580  arm
 *   DWCi_BTNlEnd     0x021BCAE4  arm
 *   DWCi_EFFlFade    0x021D55A4  arm
 *   DWCi_ChangeScene 0x021C0E40  arm
 *   endScene2        0x021C29C4  arm
 */

int DWCi_EFFlCheck(int lcd);
void DWCi_BTNlEnd(void);
int DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
void DWCi_ChangeScene(void (*scene)(void));
void endScene2(void);

void endScene1(void)
{
    if (DWCi_EFFlCheck(1)) return;
    DWCi_BTNlEnd();
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene2);
}
