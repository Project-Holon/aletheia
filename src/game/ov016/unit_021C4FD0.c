/*
 * file:     unit_021C4FD0.c
 * unit:     yes
 * function: DWCi_SceneSetAossComplete_procScene, DWCi_SceneSetAossComplete_draw
 * address:  0x021C4FD0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
extern void func_021C50A0(void);
void DWCi_SceneSetAossComplete_procScene(void);
void DWCi_SceneSetAossComplete_draw(void);


/*
 * Call func_021C50A0, DWCi_SceneSetAossComplete_draw.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetAossComplete_procScene.c \
 *       --func DWCi_SceneSetAossComplete_procScene --addr 0x021C4FD0 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetAossComplete_procScene(void)
{
    func_021C50A0();
    DWCi_SceneSetAossComplete_draw();
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetAossComplete_draw.c \
 *       --func DWCi_SceneSetAossComplete_draw --addr 0x021C4FE0 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetAossComplete_draw(void)
{
}
