/*
 * function: PLACE_NAME_LETTER_AllocWork
 * address:  0x021BD214
 * packet:   pkt_ov021_021BD214
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gPlaceNameLetterFileName     0x021DE368  data  a4
 */

extern int gPlaceNameLetterFileName;

extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);

void *PLACE_NAME_LETTER_AllocWork(int a)
{
    return func_02030734(a, 0x4C, 0, (const char *)&gPlaceNameLetterFileName, 0x170);
}
