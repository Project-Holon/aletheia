/*
 * function: procScene
 * address:  0x021CA740
 * packet:   pkt_ov016_021CA740
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   input                            0x021ca768 arm
 *   draw                             0x021ca76c arm
 *   DWCi_WINlIsInit                  0x021d157c arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   endScene                         0x021ca770 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlistsave), symbol procScene (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CA740.c \
 *       --func procScene --addr 0x021CA740 --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef _Bool bool;

extern bool DWCi_WINlIsInit(void);
extern void DWCi_ChangeScene(void (*scene)());

static void input(void);
static void draw(void);
static void endScene(void);

static void procScene(void)
{
    input();
    draw();
    if (DWCi_WINlIsInit()) {
        return;
    }
    DWCi_ChangeScene(endScene);
}
