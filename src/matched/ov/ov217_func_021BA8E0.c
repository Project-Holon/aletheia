/*
 * function: RESEARCH_TOP_DestroyLabels
 * address:  0x021BA8E0
 * packet:   pkt_021BA8E0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BgTextLabel_Destroy  0x021C0F48  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
extern void BgTextLabel_Destroy(u8 *p);

void RESEARCH_TOP_DestroyLabels(int *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        BgTextLabel_Destroy((u8 *)p[i + 0x13]);
        p[i + 0x13] = 0;
    }
}
