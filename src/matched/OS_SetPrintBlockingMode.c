/*
 * function: OS_SetPrintBlockingMode
 * address:  0x020271DC
 * packet:   pkt_020271DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202708C 0x0202708C thumb
 *   func_02027230 0x02027230 thumb
 *   func_020271F8 0x020271F8 thumb
 */

extern void func_0202708C(void);
extern void func_02027230(void);
extern void func_020271F8(void);
asm void OS_SetPrintBlockingMode(void)
{
    push {r4, lr}
    add r4, r0, #0
    bl func_0202708C
    cmp r0, #0
    beq loc_020271F0
    add r0, r4, #0
    bl func_02027230
    pop {r4, pc}
loc_020271F0:
    add r0, r4, #0
    bl func_020271F8
    pop {r4, pc}
}
