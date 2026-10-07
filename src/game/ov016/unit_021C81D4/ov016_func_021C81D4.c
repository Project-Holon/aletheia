/*
 * function: endScene1
 * address:  0x021C81D4
 * packet:   pkt_ov016_021C81D4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a sceneoptinfo.o)
 *
 * Second emitted copy of the scene-machine tail; identical body to
 * endScene1 at 0x021C2968 but its continuation pointer names a different
 * endScene2 copy at 0x021C8230.
 *
 * symbols:
 *   DWCi_EFFlCheck   0x021D5580  arm
 *   DWCi_BTNlEnd     0x021BCAE4  arm
 *   DWCi_EFFlFade    0x021D55A4  arm
 *   DWCi_ChangeScene 0x021C0E40  arm
 *   func_021C8230    0x021C8230  arm
 */

int DWCi_EFFlCheck(int lcd);
void DWCi_BTNlEnd(void);
int DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
void DWCi_ChangeScene(void (*scene)(void));
void func_021C8230(void);

void endScene1(void)
{
    if (DWCi_EFFlCheck(1)) return;
    DWCi_BTNlEnd();
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(func_021C8230);
}
