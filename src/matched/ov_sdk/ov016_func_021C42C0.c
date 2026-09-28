/*
 * function: procInit2
 * address:  0x021C42C0
 * packet:   pkt_ov016_021C42C0
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
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   procScene                        0x021C42E0  arm
 */

extern int DWCi_WINlGet(void);
extern void DWCi_ChangeScene(void (*scene)());

static void procScene(void);

static void procInit2(void)
{
    if (DWCi_WINlGet() == -2)
        return;
    DWCi_ChangeScene(procScene);
}
