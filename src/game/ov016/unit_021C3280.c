/*
 * file:     unit_021C3280.c
 * unit:     yes
 * function: DWCi_SceneOptMovComm_procScene, DWCi_SceneOptMovComm_input, DWCi_SceneOptMovComm_draw
 * address:  0x021C3280
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
void DWCi_SceneOptMovComm_procScene(void);
void DWCi_SceneOptMovComm_input(void);
void DWCi_SceneOptMovComm_draw(void);


void DWCi_SceneOptMovComm_procScene(void)
{
    DWCi_SceneOptMovComm_input();
    DWCi_SceneOptMovComm_draw();
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovComm_input.c \
 *       --func DWCi_SceneOptMovComm_input --addr 0x021C3290 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneOptMovComm_input(void)
{
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovComm_draw.c \
 *       --func DWCi_SceneOptMovComm_draw --addr 0x021C3294 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneOptMovComm_draw(void)
{
}
