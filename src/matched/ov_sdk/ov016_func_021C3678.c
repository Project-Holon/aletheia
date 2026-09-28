/*
 * function: procInit
 * address:  0x021C3678
 * packet:   pkt_ov016_021C3678
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   procInit1                        0x021C36B4  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovcompl.o), symbol procInit (name and prototype
 * from the vendor object DWARF). Open-SDK callee of DWCi_SceneOptMovConfirm. The object is
 * stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build writes, so 1.1p1.
 */
typedef _Bool bool;

extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)());

static void procInit1(void);

static void procInit(void)
{
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene(procInit1);
}
