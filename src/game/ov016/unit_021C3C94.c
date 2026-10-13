/*
 * file:     unit_021C3C94.c
 * unit:     yes
 * function: DWCi_SceneOptMovDisconnect_procScene, DWCi_SceneOptMovDisconnect_draw
 * address:  0x021C3C94
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
extern void func_021C3D58(void);
void DWCi_SceneOptMovDisconnect_procScene(void);
void DWCi_SceneOptMovDisconnect_draw(void);


/*
 * Call func_021C3D58, DWCi_SceneOptMovDisconnect_draw.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovDisconnect_procScene.c \
 *       --func DWCi_SceneOptMovDisconnect_procScene --addr 0x021C3C94 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneOptMovDisconnect_procScene(void)
{
    func_021C3D58();
    DWCi_SceneOptMovDisconnect_draw();
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovDisconnect_draw.c \
 *       --func DWCi_SceneOptMovDisconnect_draw --addr 0x021C3CA4 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneOptMovDisconnect_draw(void)
{
}
