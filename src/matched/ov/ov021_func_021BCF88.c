/*
 * function: FIELD_PLACE_NAME_AllocWork
 * address:  0x021BCF88
 * packet:   pkt_ov021_021BCF88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gFieldPlaceNameFileName     0x021DE354  data  a4
 */

extern int gFieldPlaceNameFileName;

extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);

void *FIELD_PLACE_NAME_AllocWork(int a)
{
    return func_02030734(a, 0x154, 1, (const char *)&gFieldPlaceNameFileName, 0x73C);
}
