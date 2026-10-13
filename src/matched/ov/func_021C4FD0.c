/*
 * function: DWCi_SceneSetAossComplete_procScene
 * address:  0x021C4FD0
 * packet:   pkt_021C4660
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneSetAossComplete_procScene   0x021C4FD0  arm
 *   DWCi_SceneSetAossComplete_draw  0x021C4FE0  arm
 *
 * Call func_021C50A0, DWCi_SceneSetAossComplete_draw.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetAossComplete_procScene.c \
 *       --func DWCi_SceneSetAossComplete_procScene --addr 0x021C4FD0 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C50A0(void);
extern void DWCi_SceneSetAossComplete_draw(void);

void DWCi_SceneSetAossComplete_procScene(void)
{
    func_021C50A0();
    DWCi_SceneSetAossComplete_draw();
}
