/*
 * function: BR_UTIL_FlushWindow
 * address: 0x021FD1BC
 * packet: pkt_ov186_021FD1BC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_FlushText 0x021FC830 thumb ov186
 * note: 2026-10-05 integrator: label left open after the pengy waves; written from the listing.
 */

typedef unsigned char  u8;
extern int BR_UTIL_FlushText(u8 *p);

void BR_UTIL_FlushWindow(void *p)
{
    BR_UTIL_FlushText(p);
}
