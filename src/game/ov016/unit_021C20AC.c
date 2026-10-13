/*
 * file:     unit_021C20AC.c
 * function: DWCi_SceneOptErase_procScene
 * address:  0x021C20AC
 * packet:   pkt_021C20AC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneOptErase_procScene   0x021C20AC  arm
 *   DWCi_SceneOptErase_draw  0x021C20FC  arm
 *
 * Call func_021C20C0, DWCi_SceneOptErase_draw, func_021C2100.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptErase_procScene.c \
 *       --func DWCi_SceneOptErase_procScene --addr 0x021C20AC --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C20C0(void);
extern void DWCi_SceneOptErase_draw(void);
extern void func_021C2100(void);

void DWCi_SceneOptErase_procScene(void)
{
    func_021C20C0();
    DWCi_SceneOptErase_draw();
    func_021C2100();
}
