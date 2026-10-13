/*
 * function: DWCi_SceneSetTestCompletet_procScene
 * address:  0x021CD67C
 * packet:   pkt_021CD3EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneSetTestCompletet_procScene   0x021CD67C  arm
 *   DWCi_SceneSetTestCompletet_draw  0x021CD68C  arm
 *
 * Call func_021CD79C, DWCi_SceneSetTestCompletet_draw.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetTestCompletet_procScene.c \
 *       --func DWCi_SceneSetTestCompletet_procScene --addr 0x021CD67C --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CD79C(void);
extern void DWCi_SceneSetTestCompletet_draw(void);

void DWCi_SceneSetTestCompletet_procScene(void)
{
    func_021CD79C();
    DWCi_SceneSetTestCompletet_draw();
}
