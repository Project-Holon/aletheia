/*
 * function: DWCi_SceneSetListSave
 * address:  0x021CA5D0
 * packet:   pkt_ov016_021CA5D0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   initGraphics                     0x021ca5f0 arm
 *   DWCi_HLlLoadSet                  0x021bd6d4 arm
 *   DWCi_SETTINGlSet                 0x021cf8d8 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   procInit                         0x021ca684 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlistsave), symbol DWCi_SceneSetListSave (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CA5D0.c \
 *       --func DWCi_SceneSetListSave --addr 0x021CA5D0 --region ov016 --cc 1.1p1 --arm --lang c99
 */

extern void DWCi_HLlLoadSet(void);
extern void DWCi_SETTINGlSet(void);
extern void DWCi_ChangeScene(void (*scene)());

static void initGraphics(void);
static void procInit(void);

void DWCi_SceneSetListSave(void)
{
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_SETTINGlSet();
    DWCi_ChangeScene(procInit);
}
