/*
 * function: DWCi_SceneSetTest_procScene
 * address:  0x021CD3EC
 * packet:   pkt_021CD3EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneSetTest_procScene   0x021CD3EC  arm
 *   DWCi_SceneSetTest_input  0x021CD400  arm
 *   DWCi_SceneSetTest_draw  0x021CD404  arm
 *   DWCi_SceneSetTest_button  0x021CD408  arm
 *
 * Call DWCi_SceneSetTest_input, DWCi_SceneSetTest_draw, DWCi_SceneSetTest_button.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetTest_procScene.c \
 *       --func DWCi_SceneSetTest_procScene --addr 0x021CD3EC --region ov016 --cc dsi/1.1p1 --arm
 */

extern void DWCi_SceneSetTest_input(void);
extern void DWCi_SceneSetTest_draw(void);
extern void DWCi_SceneSetTest_button(void);

void DWCi_SceneSetTest_procScene(void)
{
    DWCi_SceneSetTest_input();
    DWCi_SceneSetTest_draw();
    DWCi_SceneSetTest_button();
}
