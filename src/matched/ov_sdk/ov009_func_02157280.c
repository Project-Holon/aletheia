/*
 * function: CPS_SetCheckNConfigCallback
 * address:  0x02157280
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores a word at +0x48 of the module state block.
 *
 * symbols:
 *   g_021A826C  0x021A826C  data
 */

extern char g_021A826C[];

void CPS_SetCheckNConfigCallback(int v)
{
    *(int *)(g_021A826C + 0x48) = v;
}

