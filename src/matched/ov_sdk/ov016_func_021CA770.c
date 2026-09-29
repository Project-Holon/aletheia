/*
 * function: endScene
 * address:  0x021CA770
 * packet:   pkt_ov016_021CA770
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlFade                    0x021d55a4 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   endScene1                        0x021ca7b4 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlistsave), symbol endScene (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CA770.c \
 *       --func endScene --addr 0x021CA770 --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef _Bool bool;

extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_ChangeScene(void (*scene)());

static void endScene1(void);

static void endScene(void)
{
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x14, 8);
    DWCi_ChangeScene(endScene1);
}
