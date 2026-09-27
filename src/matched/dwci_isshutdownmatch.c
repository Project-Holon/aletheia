/*
 * function: DWCi_IsShutdownMatch
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
 *   func_02074AE8   0x02074AE8  arm
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

extern BOOL func_02074AE8(void);

BOOL DWCi_IsShutdownMatch(void)
{
    return func_02074AE8() == 0;
}
