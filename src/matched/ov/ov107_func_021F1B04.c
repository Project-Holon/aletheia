/*
 * function: MB_UTIL_MSG_GetFont
 * address: 0x021F1B04
 * packet: pkt_ov107_021F1B04
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 integrator: label left open after the pengy waves; written from the listing.
 */

unsigned int MB_UTIL_MSG_GetFont(unsigned char *p)
{
    return *(unsigned int *)(p + 0x14);
}
