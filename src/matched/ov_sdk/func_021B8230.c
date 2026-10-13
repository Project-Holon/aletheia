/*
 * function: AOSS_Memcpy
 * address:  0x021B8230
 * packet:   pkt_021B8230
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   AOSS_Memcpy   0x021B8230  thumb
 *   MI_CpuCopy8   0x02082D44  arm  arm9

 *
 * Tail-call MI_CpuCopy8 with the first two arguments swapped.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_Memcpy.c \
 *       --func AOSS_Memcpy --addr 0x021B8230 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void MI_CpuCopy8(unsigned int, unsigned int, unsigned int);

void AOSS_Memcpy(unsigned int a, unsigned int b, unsigned int c)
{
    MI_CpuCopy8(b, a, c);
}
