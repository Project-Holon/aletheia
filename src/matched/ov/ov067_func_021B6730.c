/*
 * function: TOUCHBAR_GetGfxWord
 * address:  0x021B6730
 * packet:   pkt_ov067_021B6730
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Word array index.
 */

int TOUCHBAR_GetGfxWord(void *p, int i)
{
    return ((int *)p)[i];
}
