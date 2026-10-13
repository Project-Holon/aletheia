/*
 * function: PMS_WORD_SetFlag
 * address:  0x020249A0
 * packet:   pkt_02024768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

void PMS_WORD_SetFlag(int *p, int bit)
{
    *p |= 1 << bit;
}
