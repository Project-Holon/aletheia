/*
 * function: func_02157928
 * address:  0x02157928
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * True when the top nibble is the ARM co-processor space 0xE.
 * symbols:
 *   func_02157928  0x02157928  arm
 */

int func_02157928(unsigned v)
{
    return (v & 0xF0000000u) == 0xE0000000u;
}
