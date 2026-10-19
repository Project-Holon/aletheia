/*
 * function: NAMEIN_GRAPHIC_UpdateBg
 * address:  0x021F1878
 * packet:   pkt_021F1878
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_FreeTiles 0x02040DA8 arm
 */

extern int BG_SYS_FreeTiles(int, int, int);

int NAMEIN_GRAPHIC_UpdateBg(void *a0)
{
    return BG_SYS_FreeTiles(4, 1, 0);
}
