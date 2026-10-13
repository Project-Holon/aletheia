/*
 * file:     unit_021C1BB4.c
 * function: DWCi_SceneMenu_procScene
 * address:  0x021C1BB4
 * packet:   pkt_021C1BB4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneMenu_procScene   0x021C1BB4  arm
 *   DWCi_SceneMenu_draw  0x021C1CF8  arm
 *
 * Call func_021C1BC8, DWCi_SceneMenu_draw, func_021C1CFC.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneMenu_procScene.c \
 *       --func DWCi_SceneMenu_procScene --addr 0x021C1BB4 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C1BC8(void);
extern void DWCi_SceneMenu_draw(void);
extern void func_021C1CFC(void);

void DWCi_SceneMenu_procScene(void)
{
    func_021C1BC8();
    DWCi_SceneMenu_draw();
    func_021C1CFC();
}
