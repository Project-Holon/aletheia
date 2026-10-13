/*
 * function: DWCi_GetConnectionAID
 * address:  0x0216BB54
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte at +1 of the block, or 0xff when there is none.
 *
 * symbols:
 *   gt2GetConnectionData  0x02195E78  arm  ov009
 */

extern int gt2GetConnectionData(const int *p);

int DWCi_GetConnectionAID(const int *a0)
{
    unsigned char *p = (unsigned char *)gt2GetConnectionData(a0);

    return p ? *(unsigned char *)(p + 1) : 0xff;
}

