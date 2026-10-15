/*
 * function: DWCi_GetConnectionInfoByIdx
 * address:  0x0216BC2C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Address of the i-th entry of the eight-byte table.
 *
 * symbols:
 *   gDwcNodeInfoBuffer  0x021AA920  data
 */

extern char gDwcNodeInfoBuffer[];

void *DWCi_GetConnectionInfoByIdx(int i)
{
    return gDwcNodeInfoBuffer + i * 8;
}

