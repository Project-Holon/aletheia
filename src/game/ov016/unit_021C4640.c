/*
 * file:     unit_021C4640.c
 * function: procInit2
 * address:  0x021C4640
 * packet:   pkt_ov016_021C4640
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit2 (sceneoptmovuser.o), TwlDWC libdwcutil.TWL.HYB.a
 *
 * symbols:
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   procScene                        0x021C4660  arm
 */
extern int DWCi_BTNlGet(void);
extern void DWCi_ChangeScene(void (*scene)());

static void procScene(void);

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_ChangeScene(procScene);
}
