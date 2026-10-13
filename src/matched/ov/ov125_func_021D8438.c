/*
 * function: func_021D8438
 * address:  0x021D8438
 * packet:   pkt_ov125_021D8438
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * ARM tail call: ldr ip, =target; bx ip (the form mwcc emits, as in ov009 DWCi_ProcessMatchSynPacketSub.c).
 *
 * symbols:
 *   OS_Sleep  0x02085A38  arm
 */

typedef unsigned long u32;
extern void OS_Sleep(u32 msec);

void func_021D8438(int msec)
{
    OS_Sleep(msec);
}
