/*
 * function: procInit2
 * address:  0x021C28C4
 * packet:   pkt_ov016_021C28C4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit2 (libdwcutil.TWL.HYB.a sceneoptinfo.o)
 *
 * symbols:
 *   DWCi_BTNlGet     0x021BCB14  arm
 *   DWCi_BTNlEnable  0x021BCB84  arm
 *   DWCi_ChangeScene 0x021C0E40  arm
 *   procScene        0x021C28E8  arm
 */

int DWCi_BTNlGet(void);
void DWCi_BTNlEnable(void);
void DWCi_ChangeScene(void (*scene)(void));
void procScene(void);

void procInit2(void)
{
    if (DWCi_BTNlGet() == -2) return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}
