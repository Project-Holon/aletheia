/*
 * function: BTL_SERVER_FLOW_AddSeenPoke
 * address:  0x021C84F4
 * packet:   pkt_ov093_021C84F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in a .word run.  Extent 0x021C84F4..0x021C8534
 * (64 bytes, including a 2-byte pool-alignment nop and two pool words).
 * Searches the u8 set at p+0x791 for v; if absent and i < 0x18, appends v
 * and bumps the count at p+0x785.
 */

void BTL_SERVER_FLOW_AddSeenPoke(unsigned char *p, unsigned int v)
{
    unsigned int i;
    unsigned int n = p[0x785];

    for (i = 0; i < n; i++) {
        if (v == p[0x791 + i])
            return;
    }
    if (i < 0x18) {
        *(p + i + 0x791) = v;
        p[0x785] = p[0x785] + 1;
    }
}
