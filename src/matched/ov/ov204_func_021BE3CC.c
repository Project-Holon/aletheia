/*
 * function: func_021BE3CC
 * address:  0x021BE3CC
 * packet:   pkt_021BE3CC
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 */

typedef unsigned int   u32;
extern void GFL_USE_FadeOutBgm(u32 a);

int func_021BE3CC(int a, int b, int *p)
{
    GFL_USE_FadeOutBgm((unsigned short)*p);
    return 1;
}
