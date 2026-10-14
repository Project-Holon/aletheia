/*
 * function: BR_FADE_Start
 * address:  0x021FE784
 * packet:   pkt_021FE784
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BR_FADE_StartTimed  0x021FE794  thumb  ov186
 */

typedef unsigned int   u32;
extern void BR_FADE_StartTimed(char *p, u32 index, u32 a, u32 b, u32 c);

void BR_FADE_Start(int a, int b, int c, int d)
{
    BR_FADE_StartTimed((char *)a, b, c, d, 0);
}
