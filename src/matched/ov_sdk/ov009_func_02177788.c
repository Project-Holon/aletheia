/*
 * function: DWCs_GetSendState
 * address:  0x02177788
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte at +0x1c of the record the index selects.
 *
 * symbols:
 *   gDwcTransInfo  0x021AB180  data
 */

extern char gDwcTransInfo[];

unsigned char DWCs_GetSendState(int i)
{
    return *(unsigned char *)(*(char **)gDwcTransInfo + i * 0x38 + 0x1c);
}

