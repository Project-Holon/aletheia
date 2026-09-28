/*
 * function: endScene
 * address:  0x021C3A48
 * packet:   pkt_ov016_021C3A48
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   endScene1                        0x021C3A68  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovconfi.o), symbol endScene (name and
 * prototype from the vendor object DWARF). The object is stamped Metrowerks C/C++ for
 * ARM 4.0.0.1025, which no tools/mwccarm build writes, so it stays on default 1.1p1.
 */
typedef _Bool bool;

extern void DWCi_BTNlDisable(void);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_ChangeScene(void (*scene)());

static void endScene1(void);

static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}
