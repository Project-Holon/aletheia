/*
 * file:     unit_021C8154.c
 * function: DWCi_SceneSetError_procScene
 * address:  0x021C8154
 * packet:   pkt_021C8154
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneSetError_procScene   0x021C8154  arm
 *   DWCi_SceneSetError_draw  0x021C8188  arm
 *
 * Call func_021C8168, DWCi_SceneSetError_draw, func_021C818C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetError_procScene.c \
 *       --func DWCi_SceneSetError_procScene --addr 0x021C8154 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C8168(void);
extern void DWCi_SceneSetError_draw(void);
extern void func_021C818C(void);

void DWCi_SceneSetError_procScene(void)
{
    func_021C8168();
    DWCi_SceneSetError_draw();
    func_021C818C();
}
