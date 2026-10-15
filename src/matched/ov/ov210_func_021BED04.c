/*
 * function: ZKNSEARCH_MAIN_PrintMessage9
 * address:  0x021BED04
 * packet:   pkt_ov210_021BED04
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_PrintMessageText  0x021BECB8  thumb ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
extern void ZKNSEARCH_MAIN_PrintMessageText(u8 *p, unsigned message);

void ZKNSEARCH_MAIN_PrintMessage9(void *a)
{
    ZKNSEARCH_MAIN_PrintMessageText((u8 *)a, 9);
}
