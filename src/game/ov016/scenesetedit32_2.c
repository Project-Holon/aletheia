/*
 * file:     scenesetedit32_2.c
 * function: DWCi_SceneSetEdit32_procScene
 * address:  0x021C686C
 * packet:   pkt_021C686C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneSetEdit32_procScene   0x021C686C  arm
 *   DWCi_SceneSetEdit32_draw  0x021C6A0C  arm
 *
 * Call func_021C687C, DWCi_SceneSetEdit32_draw.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetEdit32_procScene.c \
 *       --func DWCi_SceneSetEdit32_procScene --addr 0x021C686C --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C687C(void);
extern void DWCi_SceneSetEdit32_draw(void);

void DWCi_SceneSetEdit32_procScene(void)
{
    func_021C687C();
    DWCi_SceneSetEdit32_draw();
}
