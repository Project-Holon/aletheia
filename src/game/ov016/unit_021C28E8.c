/*
 * file:     unit_021C28E8.c
 * function: DWCi_SceneOptInfo_procScene
 * address:  0x021C28E8
 * packet:   pkt_021C20AC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneOptInfo_procScene   0x021C28E8  arm
 *   DWCi_SceneOptInfo_draw  0x021C291C  arm
 *
 * Call func_021C28FC, DWCi_SceneOptInfo_draw, func_021C2920.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptInfo_procScene.c \
 *       --func DWCi_SceneOptInfo_procScene --addr 0x021C28E8 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C28FC(void);
extern void DWCi_SceneOptInfo_draw(void);
extern void func_021C2920(void);

void DWCi_SceneOptInfo_procScene(void)
{
    func_021C28FC();
    DWCi_SceneOptInfo_draw();
    func_021C2920();
}
