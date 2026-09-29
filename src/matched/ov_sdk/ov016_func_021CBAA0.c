/*
 * function: input
 * address:  0x021CBAA0
 * packet:   pkt_ov016_021CBAA0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_IPTlCheckTrigger            0x021d6824 arm
 *   DWCi_SNDlStop                    0x021d0014 arm
 *   DWCi_BTNlSet                     0x021bcb28 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetsearch.o), symbol input (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CBAA0.c \
 *       --func input --addr 0x021CBAA0 --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef _Bool bool;

extern bool DWCi_IPTlCheckTrigger(unsigned short input);
extern void DWCi_SNDlStop(void);
extern void DWCi_BTNlSet(int idx);

static void input(void)
{
    if (!DWCi_IPTlCheckTrigger(2)) {
        return;
    }
    DWCi_SNDlStop();
    DWCi_BTNlSet(0);
}
