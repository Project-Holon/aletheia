/*
 * function: GDS_SOCKET_SetSslAuthCallback
 * address:  0x021D8BE4
 * packet:   pkt_021D8BE4
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Resolved: the ov121 region hint on the data symbol was contested by the
 * other overlays in the window; un-hinted, sole-ref/data picks the unique
 * overlay start, so the ABS32 pool relocation resolves.
 *
 * symbols:
 *   gGdsSslTemplatePtr  0x021DAA88  data  a4
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int gGdsSslTemplatePtr;

void GDS_SOCKET_SetSslAuthCallback(int a)
{
    *(unsigned int *)(gGdsSslTemplatePtr + 0x810) = a;
}
