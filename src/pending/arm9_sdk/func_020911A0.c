/*
 * function: func_020911A0
 * address:  0x020911A0
 * packet:   pkt_020911A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   CCERR
 *
 * symbols:
 *   func_02090F18 0x02090F18 arm
 *   func_020885A0 0x020885A0 arm
 *   func_02091150 0x02091150 arm
 *   d_020911D0    0x020911D0 data
 *
 * SDK symbol: CTRDG_DummyInit (libctrdg.TWL.HYB.a, ctrdg_proc.o).
 * DWARF: DW_TAG_subprogram CTRDG_DummyInit, no DW_TAG_variable children
 * (hand-written assembly original), matching the member at .text+0x0.
 */

extern void func_02090F18(void);
extern void func_020885A0(void);
extern void func_02091150(void);
extern void d_020911D0(void);

asm void func_020911A0(void)
{
    push {r4, lr}
    bl  func_02090F18
    mov  r4, #0xd
    mov  r0, r4
    mov  r1, #0
    bl  func_020885A0
    ldr  r1, =d_020911D0
    mov  r0, r4
    bl  func_020885A0
    mov  r0, #1
    bl  func_02091150
    pop {r4, pc}
}
