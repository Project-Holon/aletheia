/*
 * file:     unit_020590A4.c
 * function: DWCi_Acc_GetPlayerId
 * address:  0x020590A4
 * packet:   pkt_020590A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

int DWCi_Acc_GetPlayerId(int *p)
{
    return p[2];
}
