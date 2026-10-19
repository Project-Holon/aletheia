/*
 * function: DC_FlushRange
 * address:  0x020862F0
 * packet:   pkt_020862F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DC_FlushRange (libos.TWL.HYB.a os_cache.o)
 * asm:      mcr p15 c7,c10,4 (drain write buffer) and c7,c14,1 (clean and invalidate by address) have no C spelling; the DWARF subprogram has no DW_TAG_variable children.
 *
 * symbols:
 *   (none)
 */

asm void DC_FlushRange(void *startAddr, unsigned long nBytes)
{
    mov r12, #0
    add r1, r1, r0
    bic r0, r0, #0x1f
@_line:
    mcr p15, 0, r12, c7, c10, 4
    mcr p15, 0, r0, c7, c14, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt @_line
    bx lr
}
