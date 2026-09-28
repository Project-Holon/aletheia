/*
 * function: procInit2
 * address:  0x021C8130
 * packet:   pkt_ov016_021C8130
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   procScene                        0x021C8154  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovconfi.o), symbol procInit2 (name and
 * prototype from the vendor object DWARF). The object is stamped Metrowerks C/C++ for
 * ARM 4.0.0.1025, which no tools/mwccarm build writes, so it stays on default 1.1p1.
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
