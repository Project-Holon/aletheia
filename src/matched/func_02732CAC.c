/*
 * function: func_02732CAC
 * address:  0x02732CAC
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02166378    0x02166378  arm  ov009
 *   func_02165AF4    0x02165AF4  arm  ov009
 *   OS_WakeupThread  0x02085800  arm
 */

typedef unsigned int u32;

extern void *func_02166378(void);
extern void func_02165AF4(void);
extern void OS_WakeupThread(void *queue);

asm void func_02732CAC(void *arg)
{
    stmdb   sp!, {r3, r4, r5, lr}
    mov     r5, r0
    bl      func_02166378
    ldrh    r1, [r5]
    mov     r4, r0
    cmp     r1, #0xb
    ldmnefd sp!, {r3, r4, r5, pc}
    ldrh    r0, [r5, #2]
    strh    r0, [r4, #0x24]
    ldrh    r0, [r5, #2]
    cmp     r0, #0
    bne     @loc_02732CE0
    bl      func_02165AF4

@loc_02732CE0:
    add     r0, r4, #4
    bl      OS_WakeupThread
    ldmfd   sp!, {r3, r4, r5, pc}
}
