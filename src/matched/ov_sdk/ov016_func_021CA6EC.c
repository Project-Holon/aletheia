/*
 * function: procInit1
 * address:  0x021CA6EC
 * packet:   pkt_ov016_021CA6EC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlCheck                   0x021d5580 arm
 *   DWCi_WINlInitEx                  0x021d1208 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   procScene                        0x021ca740 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlistsave), symbol procInit1 (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CA6EC.c \
 *       --func procInit1 --addr 0x021CA6EC --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef _Bool bool;

extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern void DWCi_ChangeScene(void (*scene)());

static void procScene(void);

static void procInit1(void)
{
    if (DWCi_EFFlCheck(1) || DWCi_EFFlCheck(0)) {
        return;
    }
    DWCi_WINlInitEx(0x44, 5, 1, -1, 0);
    DWCi_ChangeScene(procScene);
}
