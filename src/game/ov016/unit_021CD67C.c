/*
 * file:     unit_021CD67C.c
 * unit:     yes
 * function: DWCi_SceneSetTestCompletet_procScene, DWCi_SceneSetTestCompletet_draw
 * address:  0x021CD67C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
extern void func_021CD79C(void);
void DWCi_SceneSetTestCompletet_procScene(void);
void DWCi_SceneSetTestCompletet_draw(void);


/*
 * Call func_021CD79C, DWCi_SceneSetTestCompletet_draw.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetTestCompletet_procScene.c \
 *       --func DWCi_SceneSetTestCompletet_procScene --addr 0x021CD67C --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetTestCompletet_procScene(void)
{
    func_021CD79C();
    DWCi_SceneSetTestCompletet_draw();
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetTestCompletet_draw.c \
 *       --func DWCi_SceneSetTestCompletet_draw --addr 0x021CD68C --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetTestCompletet_draw(void)
{
}
