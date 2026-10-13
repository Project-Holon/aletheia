/*
 * function: GFL_NET_ERR_RaiseFatal
 * address:  0x0200FB4C
 * packet:   pkt_0200FB4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf: if the u32 at +0x2c of the object at gNetErrWork is
 * not 2, store the argument at +0x60, set two flag bytes of the object at
 * g_021461BC, and set +0x2c to 2.
 *
 * symbols:
 *   gNetErrWork     0x0214617C  data  a4
 *   g_021461BC     0x021461BC  data  a4
 */

extern unsigned int gNetErrWork[];
extern unsigned char g_021461BC[];

void GFL_NET_ERR_RaiseFatal(unsigned int x)
{
    if (gNetErrWork[11] != 2) {
        gNetErrWork[24] = x;
        g_021461BC[0x1a] = 1;
        g_021461BC[0x19] = 1;
        gNetErrWork[11] = 2;
    }
}
