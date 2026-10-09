/*
 * file:     unit_02082198.c
 * function: MI_InitWramManager
 * address:  0x02082198
 * packet:   pkt_02082198
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02085D3C 0x02085D3C arm
 *   func_02730468 0x02730468 arm twl
 */

extern void func_02085D3C(void);
extern void func_02730468(void);

asm void MI_InitWramManager(void)
{
    stmfd sp!, {r3, lr}
    bl func_02085D3C
    cmp r0, #0
    ldmeqfd sp!, {r3, pc}
    bl func_02730468
    ldmfd sp!, {r3, pc}
}
