/*
 * function: func_021BB840
 * address:  0x021BB840
 * packet:   pkt_ov088_021BB840
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Screen row of a menu row top y: y plus the scroll offset at +0x130 / 8.
 */

typedef signed char s8;

int func_021BB840(char *p, int y)
{
    return (s8)(y + *(int *)(p + 0x130) / 8);
}
