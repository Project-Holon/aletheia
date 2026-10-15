/*
 * function: ZUKAN_DETAIL_GRAPHIC_TransferOam
 * address:  0x021BD034
 * packet:   pkt_021BD034
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_Update 0x020419E4  arm
 *
 * Tail call to the ARM9 function at 0x020419E4: loads the pointer from the pool and branches through it.
 */

extern void BG_SYS_Update(void);

void ZUKAN_DETAIL_GRAPHIC_TransferOam(char *a0)
{
    BG_SYS_Update();
}
