/*
 * function: G3X_SetFogTable
 * address:  0x0207DD10
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02082B44   0x02082B44  arm
 *
 * Original (20 bytes):
 *   ldr r1, [pc, #4]   ; 0x04000360
 *   ldr ip, [pc, #4]   ; 0x02082B44
 *   bx  ip
 *
 * Tail call: MI_Copy32B(src, REG).
 */

extern void func_02082B44(const void *src, void *dst);

void G3X_SetFogTable(const void *src)
{
    func_02082B44(src, (void *)0x04000360);
}
