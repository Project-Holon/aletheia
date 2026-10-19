/*
 * function: NNS_SndArcLoadGroup
 * address:  0x02074A54
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_SndArcLoadGroup   0x02074AE8  arm
 *
 * Original (24 bytes):
 *   push  {r3, lr}
 *   bl    #0x02074AE8
 *   cmp   r0, #0
 *   moveq r0, #1
 *   movne r0, #0
 *   pop   {r3, pc}
 */

typedef int BOOL;

extern BOOL NNSi_SndArcLoadGroup(void);

BOOL NNS_SndArcLoadGroup(void)
{
    return NNSi_SndArcLoadGroup() == 0;
}
