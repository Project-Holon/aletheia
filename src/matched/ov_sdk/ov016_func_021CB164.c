/*
 * function: procInit
 * address:  0x021CB164
 * packet:   pkt_ov016_021CB164
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlFade                    0x021d55a4 arm
 *   DWCi_GXlVisible                  0x021d603c arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   procInit1                        0x021cb1a0 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetrakucomp), symbol procInit (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CB164.c \
 *       --func procInit --addr 0x021CB164 --region ov016 --cc 1.1p1 --arm --lang c99
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
