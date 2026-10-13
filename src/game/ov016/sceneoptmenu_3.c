/*
 * file:     sceneoptmenu_3.c
 * function: DWCi_SceneOptMenu_procScene
 * address:  0x021C2D60
 * packet:   pkt_021C20AC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneOptMenu_procScene   0x021C2D60  arm
 *   DWCi_SceneOptMenu_draw  0x021C2E68  arm
 *
 * Call func_021C2D74, DWCi_SceneOptMenu_draw, func_021C2E6C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMenu_procScene.c \
 *       --func DWCi_SceneOptMenu_procScene --addr 0x021C2D60 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C2D74(void);
extern void DWCi_SceneOptMenu_draw(void);
extern void func_021C2E6C(void);

void DWCi_SceneOptMenu_procScene(void)
{
    func_021C2D74();
    DWCi_SceneOptMenu_draw();
    func_021C2E6C();
}
