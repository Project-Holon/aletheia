/*
 * file:     sceneoptmovconfirm1_2.c
 * function: DWCi_SceneOptMovConfirm1_procScene
 * address:  0x021C39A4
 * packet:   pkt_021C3280
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneOptMovConfirm1_procScene   0x021C39A4  arm
 *   DWCi_SceneOptMovConfirm1_draw  0x021C39F4  arm
 *
 * Call func_021C39B8, DWCi_SceneOptMovConfirm1_draw, func_021C39F8.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovConfirm1_procScene.c \
 *       --func DWCi_SceneOptMovConfirm1_procScene --addr 0x021C39A4 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C39B8(void);
extern void DWCi_SceneOptMovConfirm1_draw(void);
extern void func_021C39F8(void);

void DWCi_SceneOptMovConfirm1_procScene(void)
{
    func_021C39B8();
    DWCi_SceneOptMovConfirm1_draw();
    func_021C39F8();
}
