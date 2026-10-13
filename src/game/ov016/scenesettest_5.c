/*
 * file:     scenesettest_5.c
 * unit:     yes
 * function: DWCi_SceneSetTest_procScene, DWCi_SceneSetTest_input, DWCi_SceneSetTest_draw, DWCi_SceneSetTest_button
 * address:  0x021CD3EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
void DWCi_SceneSetTest_procScene(void);
void DWCi_SceneSetTest_input(void);
void DWCi_SceneSetTest_draw(void);
void DWCi_SceneSetTest_button(void);


/*
 * Call DWCi_SceneSetTest_input, DWCi_SceneSetTest_draw, DWCi_SceneSetTest_button.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetTest_procScene.c \
 *       --func DWCi_SceneSetTest_procScene --addr 0x021CD3EC --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetTest_procScene(void)
{
    DWCi_SceneSetTest_input();
    DWCi_SceneSetTest_draw();
    DWCi_SceneSetTest_button();
}

void DWCi_SceneSetTest_input(void)
{
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetTest_draw.c \
 *       --func DWCi_SceneSetTest_draw --addr 0x021CD404 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetTest_draw(void)
{
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetTest_button.c \
 *       --func DWCi_SceneSetTest_button --addr 0x021CD408 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetTest_button(void)
{
}
