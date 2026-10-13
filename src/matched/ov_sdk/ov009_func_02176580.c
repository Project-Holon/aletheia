/*
 * function: DWCi_NodeInfo_IsValid
 * address:  0x02176580
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * True when the word a pointer points at is non-zero.
 */

int DWCi_NodeInfo_IsValid(const int *p)
{
    return *p != 0;
}
