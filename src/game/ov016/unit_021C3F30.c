/*
 * file:     unit_021C3F30.c
 * function: DWCi_SceneOptMovFailure_procScene
 * address:  0x021C3F30
 * packet:   pkt_021C3280
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneOptMovFailure_procScene   0x021C3F30  arm
 *   DWCi_SceneOptMovFailure_draw  0x021C3F80  arm
 *
 * Call func_021C3F44, DWCi_SceneOptMovFailure_draw, func_021C3F84.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovFailure_procScene.c \
 *       --func DWCi_SceneOptMovFailure_procScene --addr 0x021C3F30 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C3F44(void);
extern void DWCi_SceneOptMovFailure_draw(void);
extern void func_021C3F84(void);

void DWCi_SceneOptMovFailure_procScene(void)
{
    func_021C3F44();
    DWCi_SceneOptMovFailure_draw();
    func_021C3F84();
}
