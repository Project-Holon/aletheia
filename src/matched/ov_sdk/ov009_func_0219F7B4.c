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
 *   func_02184200    0x02184200  arm
*/

extern int func_02184200(const int *p);

void SBServerListCount(void *list)
{
    func_02184200(*(void **)((char *)list + 4));
}
