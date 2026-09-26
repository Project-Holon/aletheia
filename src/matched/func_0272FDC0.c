/*
 * function: func_0272FDC0
 * address:  0x0272FDC0
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   data_02732EFC 0x02732EFC data twl
 *   func_02082A90 0x02082A90 arm
 */

asm void func_0272FDC0(int a0, const void *src)
{
    ldr r3, [pc, #0xc]
    ldr ip, [pc, #0xc]
    mov r2, #0x10
    add r0, r3, r0, lsl #4
    bx ip
    dcd 0x02732EFC
    dcd 0x02082A90
}
