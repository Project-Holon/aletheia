/*
 * file:     unit_021CB1C4.c
 * unit:     yes
 * function: DWCi_SceneSetRakuComplete_procScene, DWCi_SceneSetRakuComplete_draw
 * address:  0x021CB1C4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
extern void func_021CB294(void);
void DWCi_SceneSetRakuComplete_procScene(void);
void DWCi_SceneSetRakuComplete_draw(void);


/*
 * Call func_021CB294, DWCi_SceneSetRakuComplete_draw.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetRakuComplete_procScene.c \
 *       --func DWCi_SceneSetRakuComplete_procScene --addr 0x021CB1C4 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetRakuComplete_procScene(void)
{
    func_021CB294();
    DWCi_SceneSetRakuComplete_draw();
}

void DWCi_SceneSetRakuComplete_draw(void)
{
}
