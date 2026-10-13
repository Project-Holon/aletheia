/*
 * function: UI_SCENE_FreeActorGfx
 * address: 0x021B6284
 * packet: pkt_ov067_021B6284
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
extern void CLACT_ReleasePalette(unsigned int i);
extern void CLACT_ReleaseCharacter(unsigned int i);
extern void CLACT_ReleaseCellAnim(unsigned int i);

void UI_SCENE_FreeActorGfx(unsigned int *p)
{
    CLACT_ReleasePalette(p[1]);
    CLACT_ReleaseCharacter(p[0]);
    CLACT_ReleaseCellAnim(p[2]);
}
