/*
 * file:     scenesettestconfirm_5.c
 * unit:     yes
 * function: DWCi_SceneSetTestConfNopA, DWCi_SceneSetTestConfNopB
 * address:  0x021CDA0C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
void DWCi_SceneSetTestConfNopA(void);
void DWCi_SceneSetTestConfNopB(void);

void DWCi_SceneSetTestConfNopA(void)
{
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetTestConfNopB.c \
 *       --func DWCi_SceneSetTestConfNopB --addr 0x021CDA10 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetTestConfNopB(void)
{
}
