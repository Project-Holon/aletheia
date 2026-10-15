/*
 * function: PMS_SELECT_GRAPHIC_TransferSceneBgs
 * address:  0x021C17D4
 * packet:   pkt_ov110_021C17D4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thumb tail call through r3 to an ARM9 function.
 *
 * symbols:
 *   BG_SYS_Update  0x020419E4  arm
 */

extern void BG_SYS_Update(void);

void PMS_SELECT_GRAPHIC_TransferSceneBgs(void *a0)
{
    BG_SYS_Update();
}
