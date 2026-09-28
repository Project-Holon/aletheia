/*
 * function: func_0218BC1C
 * address:  0x0218BC1C
 * packet:   pkt_ov021_0218BC1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Value remap: x >= 0xd2 maps to x-0xd2, x in [2,0xd2) maps to (x-2)/4,
 * x < 2 maps to 0.  The unsigned range tests force `blo` while the division
 * stays signed.  Callee of func_0218B8AC.  EXACT* (follower 0x0218BC40).
 */

unsigned short func_0218BC1C(int x)
{
    if ((unsigned)x >= 0xd2)
        return (unsigned short)(x - 0xd2);
    if ((unsigned)x >= 2)
        return (unsigned short)((x - 2) / 4);
    return 0;
}
