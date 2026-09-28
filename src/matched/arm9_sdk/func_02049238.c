/*
 * function: func_02049238
 * address:  0x02049238
 * packet:   pkt_02049238
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02078A80 0x02078A80 arm
 */

extern void func_020307B0(void);
extern void func_02078A80(void);

asm void func_02049238(void)
{
    stmfd sp!, {r4, lr}
    mov	r4, r0
    bl func_02078A80
    mov	r0, r4
    bl func_020307B0
    ldmfd sp!, {r4, pc}
}
