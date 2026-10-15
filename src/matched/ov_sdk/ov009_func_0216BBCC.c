/*
 * function: DWCi_GetGT2ConnectionByIdx
 * address:  0x0216BBCC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Address of the i-th word of the table.
 *
 * symbols:
 *   gDwcConnectionArray  0x021AA8A0  data
 */

extern int gDwcConnectionArray[];

int *DWCi_GetGT2ConnectionByIdx(int i)
{
    return &gDwcConnectionArray[i];
}

