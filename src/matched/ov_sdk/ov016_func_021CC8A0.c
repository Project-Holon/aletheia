/*
 * function: procErase1
 * address:  0x021CC8A0
 * packet:   pkt_ov016_021CC8A0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_WINlIsInit                  0x021d157c arm
 *   DWCi_BTNlEnable                  0x021bcb84 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   procScene                        0x021cbfd8 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetselectap), symbol procErase1 (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CC8A0.c \
 *       --func procErase1 --addr 0x021CC8A0 --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef _Bool bool;

extern bool DWCi_WINlIsInit(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_ChangeScene(void (*scene)());

static void procScene(void);

static void procErase1(void)
{
    if (DWCi_WINlIsInit()) {
        return;
    }
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}
