/*
 * file:     unit_021CBFD8.c
 * function: DWCi_SceneSetSelectAp_procScene
 * address:  0x021CBFD8
 * packet:   pkt_021CB1C4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneSetSelectAp_procScene   0x021CBFD8  arm
 *   DWCi_SceneSetSelectAp_draw  0x021CC0E4  arm
 *
 * Call func_021CBFEC, DWCi_SceneSetSelectAp_draw, func_021CC0E8.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetSelectAp_procScene.c \
 *       --func DWCi_SceneSetSelectAp_procScene --addr 0x021CBFD8 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CBFEC(void);
extern void DWCi_SceneSetSelectAp_draw(void);
extern void func_021CC0E8(void);

void DWCi_SceneSetSelectAp_procScene(void)
{
    func_021CBFEC();
    DWCi_SceneSetSelectAp_draw();
    func_021CC0E8();
}
