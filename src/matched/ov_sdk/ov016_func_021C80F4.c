/*
 * function: procInit1
 * address:  0x021C80F4
 * packet:   pkt_ov016_021C80F4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   procInit2                        0x021C8130  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovconfi.o), symbol procInit1 (name and
 * prototype from the vendor object DWARF). The object is stamped Metrowerks C/C++ for
 * ARM 4.0.0.1025, which no tools/mwccarm build writes, so it stays on default 1.1p1.
 */
typedef _Bool bool;

extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_CMNlButton(int kind);
extern void DWCi_ChangeScene(void (*scene)());

static void procInit2(void);

static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(4);
    DWCi_ChangeScene(procInit2);
}
