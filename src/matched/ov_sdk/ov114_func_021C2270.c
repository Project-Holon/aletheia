/*
 * function: ghttpThink
 * address:  0x021C2270
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ghiEnumConnections  0x021C0DF8  arm  ov114
 *
 *
 * Tail call of ghiEnumConnections on the 0x021C1DEC record.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void ghiEnumConnections(void *);

void ghttpThink(void)
{
    ghiEnumConnections((void *)0x021C1DEC);
}
