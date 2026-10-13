/*
 * function: TOWNMAP_BackButtonIsHeld
 * address:  0x021BA040
 * packet:   pkt_021BA040
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHBAR_IsBusy  0x021B6498  thumb  ov067
 */

int TOUCHBAR_IsBusy(unsigned char *p);

int TOWNMAP_BackButtonIsHeld(int *p)
{
    return TOUCHBAR_IsBusy((unsigned char *)p[3]);
}
