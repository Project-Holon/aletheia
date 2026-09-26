/*
 * function: func_0272FDDC
 * address:  0x0272FDDC
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   data_02732EFC 0x02732EFC data twl
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_0272FD40 0x0272FD40 arm twl
 */

extern char data_02732EFC[];
void func_02087988(void);
void func_0208799C(void);
void func_0272FD40(void);

asm void func_0272FDDC(int ch, const void *src, void *dst)
{
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    mov     r7, r0
    mov     r6, r1
    mov     r5, r2
    bl      func_02087988
    mov     r4, r0
    mov     r0, r7
    bl      func_0272FD40
    mov     r0, #0x1c
    mul     r0, r7, r0
    add     r0, r0, #0x4000000
    add     r1, r0, #0x4000
    str     r6, [r1, #0x104]
    ldr     r0, [pc, #0x2c]
    str     r5, [r1, #0x108]
    mov     r2, #1
    str     r2, [r1, #0x10c]
    str     r2, [r1, #0x110]
    add     r0, r0, r7, lsl #4
    ldr     r2, [r0, #8]
    mov     r0, r4
    orr     r2, r2, #0x4000
    orr     r2, r2, #0xa4000000
    str     r2, [r1, #0x11c]
    bl      func_0208799C
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
    DCD     data_02732EFC
}
