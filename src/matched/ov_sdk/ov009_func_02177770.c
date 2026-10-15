/*
 * function: DWCs_GetTransConnection
 * address:  0x02177770
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Indexes the record array at +0x38 a record.
 *
 * symbols:
 *   gDwcTransInfo  0x021AB180  data
 */

extern char gDwcTransInfo[];

int DWCs_GetTransConnection(int i)
{
    return *(int *)gDwcTransInfo + i * 0x38;
}

