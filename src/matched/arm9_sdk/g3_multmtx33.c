/*
 * function: G3_MultMtx33
 * address:  0x0207D934
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02082B60   0x02082B60  arm
 *
 * Original (28 bytes):
 *   ldr r1, [pc, #0xc]   ; 0x04000400
 *   mov r2, #0x1a
 *   ldr ip, [pc, #8]     ; 0x02082B60
 *   str r2, [r1]
 *   bx  ip
 */

extern void func_02082B60(const void *src);

void G3_MultMtx33(const void *m)
{
    *(volatile unsigned int *)0x04000400 = 0x1a;
    func_02082B60(m);
}
