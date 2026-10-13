/*
 * file:     unit_021CCC70.c
 * function: DWCi_SceneSetSelectWay_procScene
 * address:  0x021CCC70
 * packet:   pkt_021CCC70
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneSetSelectWay_procScene   0x021CCC70  arm
 *   DWCi_SceneSetSelectWay_draw  0x021CCE00  arm
 *
 * Call func_021CCC84, DWCi_SceneSetSelectWay_draw, func_021CCE04.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetSelectWay_procScene.c \
 *       --func DWCi_SceneSetSelectWay_procScene --addr 0x021CCC70 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CCC84(void);
extern void DWCi_SceneSetSelectWay_draw(void);
extern void func_021CCE04(void);

void DWCi_SceneSetSelectWay_procScene(void)
{
    func_021CCC84();
    DWCi_SceneSetSelectWay_draw();
    func_021CCE04();
}
