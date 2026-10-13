/*
 * function: DWCi_SceneOptMovComm_procScene
 * address:  0x021C3280
 * packet:   pkt_021C3280
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneOptMovComm_procScene   0x021C3280  arm
 *   DWCi_SceneOptMovComm_input  0x021C3290  arm
 *   DWCi_SceneOptMovComm_draw  0x021C3294  arm
 *
 * Call DWCi_SceneOptMovComm_input, DWCi_SceneOptMovComm_draw.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovComm_procScene.c \
 *       --func DWCi_SceneOptMovComm_procScene --addr 0x021C3280 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void DWCi_SceneOptMovComm_input(void);
extern void DWCi_SceneOptMovComm_draw(void);

void DWCi_SceneOptMovComm_procScene(void)
{
    DWCi_SceneOptMovComm_input();
    DWCi_SceneOptMovComm_draw();
}
