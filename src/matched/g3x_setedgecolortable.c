/*
 * function: G3X_SetEdgeColorTable
 * address:  0x0207DCF8
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02082A60   0x02082A60  arm
 *
 * Original (24 bytes):
 *   ldr r1, [pc, #8]   ; 0x04000330
 *   ldr ip, [pc, #8]   ; 0x02082A60
 *   mov r2, #0x10
 *   bx  ip
 *
 * Tail call: MIi_CpuCopy16(src, REG, 16).
 */

extern void func_02082A60(const void *src, void *dst, unsigned int size);

void G3X_SetEdgeColorTable(const void *src)
{
    func_02082A60(src, (void *)0x04000330, 0x10);
}
