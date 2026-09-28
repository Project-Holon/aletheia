/*
 * function: GXS_BeginLoadOBJExtPltt
 * address:  0x0207F6A8
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020809F0   0x020809F0  arm
 *   d_02150E10      0x02150E10  data  a4
 *
 * Original (24 bytes):
 *   push {r3, lr}
 *   bl   #0x020809F0
 *   ldr  r1, [pc, #4]     ; &d_02150E10
 *   str  r0, [r1, #0x18]
 *   pop  {r3, pc}
 */

extern void *func_020809F0(void);
extern char d_02150E10;

void *GXS_BeginLoadOBJExtPltt(void)
{
    void *p = func_020809F0();
    *(void **)((char *)&d_02150E10 + 0x18) = p;
    return p;
}
