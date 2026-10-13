/*
 * function: DWCi_SceneOptMovDisconnect_procScene
 * address:  0x021C3C94
 * packet:   pkt_021C3280
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneOptMovDisconnect_procScene   0x021C3C94  arm
 *   DWCi_SceneOptMovDisconnect_draw  0x021C3CA4  arm
 *
 * Call func_021C3D58, DWCi_SceneOptMovDisconnect_draw.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovDisconnect_procScene.c \
 *       --func DWCi_SceneOptMovDisconnect_procScene --addr 0x021C3C94 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C3D58(void);
extern void DWCi_SceneOptMovDisconnect_draw(void);

void DWCi_SceneOptMovDisconnect_procScene(void)
{
    func_021C3D58();
    DWCi_SceneOptMovDisconnect_draw();
}
