/*
 * function: DC_FlushAll
 * address:  0x02086284
 * packet:   pkt_02086284
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DC_FlushAll (libos.TWL.HYB.a os_cache.o)
 * asm:      mcr p15 c7,c10,4 (drain write buffer) and c7,c14,2 (clean and invalidate by set/way) have no C spelling; the DWARF subprogram has no DW_TAG_variable children.
 *
 * symbols:
 *   (none)
 */

asm void DC_FlushAll(void)
{
    mov r12, #0
    mov r1, #0
@_set:
    mov r0, #0
@_line:
    orr r2, r1, r0
    mcr p15, 0, r12, c7, c10, 4
    mcr p15, 0, r2, c7, c14, 2
    add r0, r0, #0x20
    cmp r0, #0x400
    blt @_line
    add r1, r1, #0x40000000
    cmp r1, #0
    bne @_set
    bx lr
}
