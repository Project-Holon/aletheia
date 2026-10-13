/*
 * file:     unit_021C4660.c
 * function: DWCi_SceneOptMovWait_procScene
 * address:  0x021C4660
 * packet:   pkt_021C4660
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneOptMovWait_procScene   0x021C4660  arm
 *   DWCi_SceneOptMovWait_draw  0x021C46AC  arm
 *
 * Call func_021C4674, DWCi_SceneOptMovWait_draw, func_021C46B0.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovWait_procScene.c \
 *       --func DWCi_SceneOptMovWait_procScene --addr 0x021C4660 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C4674(void);
extern void DWCi_SceneOptMovWait_draw(void);
extern void func_021C46B0(void);

void DWCi_SceneOptMovWait_procScene(void)
{
    func_021C4674();
    DWCi_SceneOptMovWait_draw();
    func_021C46B0();
}
