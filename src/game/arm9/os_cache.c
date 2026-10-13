/*
 * file:     os_cache.c
 * unit:     yes
 * function: func_02086284, func_020862B8, func_020862D4, DWCi_ScreenDC_FlushRange, func_02086314, func_02086320, func_0208632C
 * address:  0x02086284
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
asm void func_02086284(void);
asm void DC_InvalidateRange(void);
asm void DC_StoreRange(void);
asm void DWCi_ScreenDC_FlushRange(void *startAddr, unsigned long nBytes);
asm void DC_WaitWriteBufferEmpty(void);
asm void IC_InvalidateAll(void);
asm void IC_InvalidateRange(void);

/*
 * sdk:      DC_FlushAll (libos.TWL.HYB.a os_cache.o)
 * asm:      mcr p15 c7,c10,4 (drain write buffer) and c7,c14,2 (clean and invalidate by set/way) have no C spelling; the DWARF subprogram has no DW_TAG_variable children.
 */
asm void func_02086284(void)
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

asm void DC_InvalidateRange(void)
{
    add	r1, r1, r0
    bic	r0, r0, #0x1f
loc_020862C0:
    mcr p15, 0, r0, c7, c6, 1
    add	r0, r0, #0x20
    cmp	r0, r1
    blt loc_020862C0
    bx	lr
}

asm void DC_StoreRange(void)
{
    add	r1, r1, r0
    bic	r0, r0, #0x1f
loc_020862DC:
    mcr p15, 0, r0, c7, c10, 1
    add	r0, r0, #0x20
    cmp	r0, r1
    blt loc_020862DC
    bx	lr
}

/*
 * sdk:      DC_FlushRange (libos.TWL.HYB.a os_cache.o)
 * asm:      mcr p15 c7,c10,4 (drain write buffer) and c7,c14,1 (clean and invalidate by address) have no C spelling; the DWARF subprogram has no DW_TAG_variable children.
 */
asm void DWCi_ScreenDC_FlushRange(void *startAddr, unsigned long nBytes)
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

asm void DC_WaitWriteBufferEmpty(void)
{
    mov r0, #0
    mcr p15, 0, r0, c7, c10, 4
    bx lr
}

asm void IC_InvalidateAll(void)
{
    mov r0, #0
    mcr p15, 0, r0, c7, c5, 0
    bx lr
}

asm void IC_InvalidateRange(void)
{
    add	r1, r1, r0
    bic	r0, r0, #0x1f
loc_02086334:
    mcr p15, 0, r0, c7, c5, 1
    add	r0, r0, #0x20
    cmp	r0, r1
    blt loc_02086334
    bx	lr
}
