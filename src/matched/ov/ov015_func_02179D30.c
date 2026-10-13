/*
 * function: IRCNET_GetSenderFlag
 * address:  0x02179D30
 * packet:   pkt_02179D30
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_0217AB80  0x0217AB80  data  a4
 */

typedef unsigned char u8;

extern u8 g_0217AB80[];

u8 IRCNET_GetSenderFlag(void)
{
    return g_0217AB80[0x1c];
}
