/*
 * function: procError
 * address:  0x021CB734
 * packet:   pkt_ov016_021CB734
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_WINlGet                     0x021d1568 arm
 *   DWCi_SNDlPlay                    0x021cffac arm
 *   DWCi_WINlEnd                     0x021d1524 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   procError1                       0x021cb760 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetrakuread), symbol procError (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CB734.c \
 *       --func procError --addr 0x021CB734 --region ov016 --cc 1.1p1 --arm --lang c99
 */

extern int DWCi_WINlGet(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_WINlEnd(void);
extern void DWCi_ChangeScene(void (*scene)());

static void procError1(void);

static void procError(void)
{
    if (DWCi_WINlGet() != 0) {
        return;
    }
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_ChangeScene(procError1);
}
