/*
 * function: BEACON_DETAIL_OnMessageDone
 * address:  0x02184EAC
 * packet:   pkt_02184EAC
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void BEACON_DETAIL_OnMessageDone(int a, int b, int c)
{
    if (c == 0)
        GFL_USE_PlaySeDefaultVolume(0x547);
}
