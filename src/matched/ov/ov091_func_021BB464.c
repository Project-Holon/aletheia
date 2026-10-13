/*
 * function: PLIST_PLATE_GetHp
 * address:  0x021BB464
 * packet:   pkt_021BB464
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

unsigned short PLIST_PLATE_GetHp(int unused, unsigned short *p)
{
    (void)unused;
    return p[3];
}
