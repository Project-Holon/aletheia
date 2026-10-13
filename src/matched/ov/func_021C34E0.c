/*
 * function: DWCi_SceneOptMovComplete_procScene
 * address:  0x021C34E0
 * packet:   pkt_021C3280
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneOptMovComplete_procScene   0x021C34E0  arm
 *   DWCi_SceneOptMovComplete_draw  0x021C3514  arm
 *
 * Call func_021C34F4, DWCi_SceneOptMovComplete_draw, func_021C3518.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovComplete_procScene.c \
 *       --func DWCi_SceneOptMovComplete_procScene --addr 0x021C34E0 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C34F4(void);
extern void DWCi_SceneOptMovComplete_draw(void);
extern void func_021C3518(void);

void DWCi_SceneOptMovComplete_procScene(void)
{
    func_021C34F4();
    DWCi_SceneOptMovComplete_draw();
    func_021C3518();
}
