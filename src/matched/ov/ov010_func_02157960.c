/*
 * function: DELIVERY_IRC_SetStepAtLine
 * address:  0x02157960
 * packet:   pkt_ov010_02157960
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   DELIVERY_IRC_SetStep  0x02157954  thumb ov010
 */

typedef unsigned char  u8;
extern void DELIVERY_IRC_SetStep(u8 *p, int v, int a2);

void DELIVERY_IRC_SetStepAtLine(int a, int b, int c)
{
    DELIVERY_IRC_SetStep((u8 *)a, b, c);
}
