/*
 * function: DWCi_SceneSetEditAddress_procScene
 * address:  0x021C73C0
 * packet:   pkt_021C73C0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneSetEditAddress_procScene   0x021C73C0  arm
 *   DWCi_SceneSetEditAddress_draw  0x021C7718  arm
 *
 * Call func_021C73D0, DWCi_SceneSetEditAddress_draw.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetEditAddress_procScene.c \
 *       --func DWCi_SceneSetEditAddress_procScene --addr 0x021C73C0 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C73D0(void);
extern void DWCi_SceneSetEditAddress_draw(void);

void DWCi_SceneSetEditAddress_procScene(void)
{
    func_021C73D0();
    DWCi_SceneSetEditAddress_draw();
}
