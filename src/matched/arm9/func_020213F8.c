/*
 * function: PALANM_LookupPairedCode
 * address:  0x020213F8
 * packet:   pkt_020213F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0030 ABS32 sPalAnmCodePairTable       : 0209E904 (data, from header) has no witness outside 020213F8..0202142C
 * symbols:
 *   sPalAnmCodePairTable  0x0209E904  data
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 sPalAnmCodePairTable[][2];

u16 PALANM_LookupPairedCode(int a, int b)
{
    u32 i;

    for (i = 0; i < 0x19; i++)
        if (sPalAnmCodePairTable[i][b] == a)
            return sPalAnmCodePairTable[i][b ^ 1];
    return 0;
}
