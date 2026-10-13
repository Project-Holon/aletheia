/*
 * function: DWCi_GetAllocateHeader
 * address:  0x0205A12C
 * packet:   pkt_0205A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

void *DWCi_GetAllocateHeader(char *p)
{
    return p - 0x20;
}
