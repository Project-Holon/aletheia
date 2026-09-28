/*
 * function: func_02086284
 * address:  0x02086284
 * packet:   pkt_02086284
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_cache.o, symbol DC_FlushAll. DWARF has no formals and no
 * locals, and the body is a bare coprocessor loop: hand-written assembly.
 */

asm void func_02086284(void)
{
    mov ip, #0
    mov r1, #0
loc_0208628C:
    mov r0, #0
loc_02086290:
    orr r2, r1, r0
    mcr p15, 0, ip, c7, c10, 4
    mcr p15, 0, r2, c7, c14, 2
    add r0, r0, #0x20
    cmp r0, #0x400
    blt loc_02086290
    add r1, r1, #0x40000000
    cmp r1, #0
    bne loc_0208628C
    bx lr
}
