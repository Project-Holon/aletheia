/*
 * function: func_020414AC
 * address:  0x020414AC
 * packet:   pkt_020414AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020414C4 0x020414C4 arm
 *   func_020414EC 0x020414EC arm
 */

typedef unsigned int   u32;
extern void func_020414C4(u32 idx);
extern void func_020414EC(u32 i);

asm void func_020414AC(void)
{
    stmfd sp!, {r4, lr}
    mov	r4, r0
    bl func_020414C4
    mov	r0, r4
    bl func_020414EC
    ldmfd sp!, {r4, pc}
}
