/*
 * function: procInit2
 * address:  0x021CAD88
 * packet:   pkt_ov016_021CAD88
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit2 (scenesetrakubutt.o), TwlDWC libdwcutil.TWL.HYB.a
 *
 * symbols:
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   procScene                        0x021CADAC  arm
 */
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_ChangeScene(void (*scene)());

static void procScene(void);

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}
