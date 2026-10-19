/*
 * function: closeFadeStep
 * address:  0x021C3794
 * packet:   pkt_ov016_021C3794
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   endScene2                        0x021C37D0  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovconfi.o), symbol closeFadeStep (name and
 * prototype from the vendor object DWARF). The object is stamped Metrowerks C/C++ for
 * ARM 4.0.0.1025, which no tools/mwccarm build writes, so it stays on default 1.1p1.
 */
typedef _Bool bool;

extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_BTNlEnd(void);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_ChangeScene(void (*scene)());

static void endScene2(void);

static void closeFadeStep(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_BTNlEnd();
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene2);
}
