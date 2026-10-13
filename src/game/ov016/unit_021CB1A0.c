/*
 * file:     unit_021CB1A0.c
 * function: procInit1
 * address:  0x021CB1A0
 * packet:   pkt_ov016_021CB1A0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit1 (sceneoptmovuser.o), TwlDWC libdwcutil.TWL.HYB.a
 *
 * symbols:
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_SceneSetRakuComplete_procScene                    0x021CB1C4  arm
 */
typedef _Bool bool;

extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_SceneSetRakuComplete_procScene(void);

static void procInit1(void)
{
    if (!DWCi_EFFlCheck(0))
        DWCi_ChangeScene(DWCi_SceneSetRakuComplete_procScene);
}
