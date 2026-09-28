/*
 * function: CARDi_LockBusCondition
 * address:  0x02075C90
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02084E38   0x02084E38  arm
 *
 * Original (28 bytes):
 *   push  {r3, lr}
 *   ldrh  r0, [r0]
 *   bl    #0x02084E38
 *   cmp   r0, #0
 *   moveq r0, #1
 *   movne r0, #0
 *   pop   {r3, pc}
 */

typedef int BOOL;

extern BOOL func_02084E38(unsigned int lockID);

BOOL CARDi_LockBusCondition(unsigned short *p)
{
    return func_02084E38(*p) == 0;
}
