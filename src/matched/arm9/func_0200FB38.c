/*
 * function: GFL_NET_ERR_RequestScreen
 * address:  0x0200FB38
 * packet:   pkt_0200FB38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf accessor: if the u32 at +0x2c of the object at
 * gNetErrWork is 1, set it to 2.
 *
 * symbols:
 *   gNetErrWork     0x0214617C  data  a4
 */

extern unsigned int gNetErrWork[];

void GFL_NET_ERR_RequestScreen(void)
{
    if (gNetErrWork[11] == 1) {
        gNetErrWork[11] = 2;
    }
}
