/*
 * function: func_020862F0
 * address:  0x020862F0
 * packet:   pkt_020862F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_cache.o, symbol DC_FlushRange. DWARF has formals but no
 * locals, and the body is a bare coprocessor loop: hand-written assembly.
 */

asm void func_020862F0(void)
{
    mov ip, #0
    add r1, r1, r0
    bic r0, r0, #0x1f
loc_020862FC:
    mcr p15, 0, ip, c7, c10, 4
    mcr p15, 0, r0, c7, c14, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loc_020862FC
    bx lr
}
