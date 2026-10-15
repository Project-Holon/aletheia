/*
 * function: SBServerListCount
 * address:  0x0219F7B4
 * packet:   pkt_ov009_0219F7B4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ArrayLength    0x02184200  arm
*/

extern int ArrayLength(const int *p);

void SBServerListCount(void *list)
{
    ArrayLength(*(void **)((char *)list + 4));
}
