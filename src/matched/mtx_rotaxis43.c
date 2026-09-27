/*
 * function: MTX_RotAxis43
 * address:  0x0207B65C
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0207AF50   0x0207AF50  arm
 *
 * Original (32 bytes):
 *   push {r4, lr}
 *   mov  r4, r0
 *   bl   #0x0207AF50
 *   mov  r0, #0
 *   str  r0, [r4, #0x24]
 *   str  r0, [r4, #0x28]
 *   str  r0, [r4, #0x2c]
 *   pop  {r4, pc}
 *
 * Rotation into the upper 3x3, then zero the translation column.
 */

extern void func_0207AF50(void *m, void *v);

void MTX_RotAxis43(void *m, void *v)
{
    func_0207AF50(m, v);
    *(unsigned int *)((char *)m + 0x24) = 0;
    *(unsigned int *)((char *)m + 0x28) = 0;
    *(unsigned int *)((char *)m + 0x2c) = 0;
}
