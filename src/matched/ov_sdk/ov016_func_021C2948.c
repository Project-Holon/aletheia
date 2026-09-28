/*
 * function: endScene
 * address:  0x021C2948
 * packet:   pkt_ov016_021C2948
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene (libdwcutil.TWL.HYB.a sceneoptinfo.o)
 *
 * symbols:
 *   DWCi_BTNlDisable 0x021BCB9C  arm
 *   DWCi_EFFlWait    0x021D5790  arm
 *   DWCi_ChangeScene 0x021C0E40  arm
 *   endScene1        0x021C2968  arm
 */

void DWCi_BTNlDisable(void);
int DWCi_EFFlWait(int frame);
void DWCi_ChangeScene(void (*scene)(void));
void endScene1(void);

void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}
