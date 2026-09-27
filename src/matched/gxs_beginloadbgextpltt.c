/*
 * function: GXS_BeginLoadBGExtPltt
 * address:  0x0207F5B0
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020809C8   0x020809C8  arm
 *   d_02150E10      0x02150E10  data  a4
 *
 * Original (24 bytes):
 *   push {r3, lr}
 *   bl   #0x020809C8
 *   ldr  r1, [pc, #4]   ; &d_02150E10
 *   str  r0, [r1]
 *   pop  {r3, pc}
 */

extern void *func_020809C8(void);
extern void *d_02150E10;

void *GXS_BeginLoadBGExtPltt(void)
{
    return d_02150E10 = func_020809C8();
}
