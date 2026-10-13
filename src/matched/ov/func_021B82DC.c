/*
 * function: AOSS_Close
 * address:  0x021B82DC
 * packet:   pkt_021B8230
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   AOSS_Close   0x021B82DC  thumb
 *   SOC_Close  0x0215F644  arm  ov009
 *
 * Thumb tail-call thunk into SOC_Close.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_Close.c \
 *       --func AOSS_Close --addr 0x021B82DC --region ov016 --cc dsi/1.1p1 --thumb
 */

extern int SOC_Close(int s);

int AOSS_Close(int s)
{
    return SOC_Close(s);
}
