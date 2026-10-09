/*
 * file:     unit_021CBFA8.c
 * function: procInit2
 * address:  0x021CBFA8
 * packet:   pkt_ov016_021CBFA8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_BTNlGet                     0x021bcb14 arm
 *   DWCi_STEPlGet                    0x021d0684 arm
 *   DWCi_BTNlEnable                  0x021bcb84 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   procScene                        0x021cbfd8 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetselectap), symbol procInit2 (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CBFA8.c \
 *       --func procInit2 --addr 0x021CBFA8 --region ov016 --cc 1.1p1 --arm --lang c99
 */

extern int DWCi_BTNlGet(void);
extern int DWCi_STEPlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_ChangeScene(void (*scene)());

static void procScene(void);

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2) {
        return;
    }
    if (DWCi_STEPlGet() == 1) {
        return;
    }
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}
