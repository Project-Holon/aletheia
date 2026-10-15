/*
 * function: ZKNSEARCH_MAIN_SetActorBgPriority
 * address:  0x021BEE80
 * packet:   pkt_ov210_021BEE80
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 * Addresses are Black-image addresses.
 */

extern void CLACT_SetActorBgPriority(int h, unsigned v);

void ZKNSEARCH_MAIN_SetActorBgPriority(int p, int i, unsigned v)
{
    CLACT_SetActorBgPriority(((int *)(p + i * 4))[0xa], (unsigned char)v);
}
