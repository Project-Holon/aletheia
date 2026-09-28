/*
 * function: procInit1
 * address:  0x021C2888
 * packet:   pkt_ov016_021C2888
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit1 (libdwcutil.TWL.HYB.a sceneoptinfo.o)
 *
 * symbols:
 *   DWCi_EFFlCheck    0x021D5580  arm
 *   DWCi_CMNlButton   0x021BD264  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   procInit2         0x021C28C4  arm
 */

int DWCi_EFFlCheck(int lcd);
void DWCi_CMNlButton(int kind);
void DWCi_ChangeScene(void (*scene)(void));
void procInit2(void);

void procInit1(void)
{
    if (DWCi_EFFlCheck(1)) return;
    if (DWCi_EFFlCheck(0)) return;
    DWCi_CMNlButton(2);
    DWCi_ChangeScene(procInit2);
}
