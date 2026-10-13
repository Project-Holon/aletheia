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
 *   g_021AA8A0  0x021AA8A0  data
 */

extern int g_021AA8A0[];

int *DWCi_GetGT2ConnectionByIdx(int i)
{
    return &g_021AA8A0[i];
}

