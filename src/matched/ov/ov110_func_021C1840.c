/*
 * function: PMS_SELECT_GRAPHIC_VBlankSceneActors
 * address:  0x021C1840
 * packet:   pkt_021C1840
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMS_SELECT_GRAPHIC_VBlankSceneActors 0x021C1840 thumb
 *   CLACT_VBlankSystem 0x0204A648 arm
 */

extern void CLACT_VBlankSystem(void);

void PMS_SELECT_GRAPHIC_VBlankSceneActors(void *a0)
{
    CLACT_VBlankSystem();
}
