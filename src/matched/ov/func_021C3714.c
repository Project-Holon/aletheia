/*
 * function: DWCi_SceneOptMovConfirm_procScene
 * address:  0x021C3714
 * packet:   pkt_021C3280
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneOptMovConfirm_procScene   0x021C3714  arm
 *   DWCi_SceneOptMovConfirm_draw  0x021C3748  arm
 *
 * Call func_021C3728, DWCi_SceneOptMovConfirm_draw, func_021C374C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovConfirm_procScene.c \
 *       --func DWCi_SceneOptMovConfirm_procScene --addr 0x021C3714 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C3728(void);
extern void DWCi_SceneOptMovConfirm_draw(void);
extern void func_021C374C(void);

void DWCi_SceneOptMovConfirm_procScene(void)
{
    func_021C3728();
    DWCi_SceneOptMovConfirm_draw();
    func_021C374C();
}
