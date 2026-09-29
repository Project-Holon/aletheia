/*
 * function: procInit1
 * address:  0x021CB454
 * packet:   pkt_ov016_021CB454
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlCheck                   0x021d5580 arm
 *   DWCi_RAKUlInit                   0x021c1488 arm
 *   DWCi_CMNlButton                  0x021bd264 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   procInit2                        0x021cb498 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetrakuread), symbol procInit1 (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CB454.c \
 *       --func procInit1 --addr 0x021CB454 --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef _Bool bool;

extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_RAKUlInit(void);
extern void DWCi_CMNlButton(int kind);
extern void DWCi_ChangeScene(void (*scene)());

static void procInit2(void);

static void procInit1(void)
{
    if (DWCi_EFFlCheck(1) || DWCi_EFFlCheck(0)) {
        return;
    }
    DWCi_RAKUlInit();
    DWCi_CMNlButton(1);
    DWCi_ChangeScene(procInit2);
}
