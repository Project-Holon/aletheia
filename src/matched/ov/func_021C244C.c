/*
 * function: DWCi_SceneOptErase1_procScene
 * address:  0x021C244C
 * packet:   pkt_021C20AC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneOptErase1_procScene   0x021C244C  arm
 *   DWCi_SceneOptErase1_draw  0x021C2480  arm
 *
 * Call func_021C2460, DWCi_SceneOptErase1_draw, func_021C2484.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptErase1_procScene.c \
 *       --func DWCi_SceneOptErase1_procScene --addr 0x021C244C --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C2460(void);
extern void DWCi_SceneOptErase1_draw(void);
extern void func_021C2484(void);

void DWCi_SceneOptErase1_procScene(void)
{
    func_021C2460();
    DWCi_SceneOptErase1_draw();
    func_021C2484();
}
