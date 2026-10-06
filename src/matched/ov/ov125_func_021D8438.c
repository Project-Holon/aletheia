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
 * ARM tail call: ldr ip, =target; bx ip (the form mwcc emits, as in ov009 func_0216F008.c).
 *
 * symbols:
 *   func_02085A38  0x02085A38  arm
 */

typedef unsigned long u32;
extern void func_02085A38(u32 msec);

void func_021D8438(int msec)
{
    func_02085A38(msec);
}
