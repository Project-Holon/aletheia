/*
 * file:     unit_02084EB8.c
 * unit:     yes
 * function: func_02084EB8, func_02084F10
 * address:  0x02084EB8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef long s32;

typedef unsigned short u16;

asm s32 func_02084EB8(void);
asm void func_02084F10(u16 lockID);


/*
 * sdk:      OS_GetLockID (os_spinlock.o)
 * asm:      hand-written in the object: needs clz, the subprogram has no
 *           DW_TAG_variable, and .debug_line gives each instruction its own
 *           strictly increasing line (836..898), the asm-function pattern.
 */
asm s32 func_02084EB8(void)
{
    ldr     r3, =0x02FFFFB0
    ldr     r1, [r3, #0]
    clz     r2, r1
    cmp     r2, #32
    movne   r0, #0x40
    bne     _1
    add     r3, r3, #4
    ldr     r1, [r3, #0]
    clz     r2, r1
    cmp     r2, #32
    ldr     r0, =0xFFFFFFFD
    bxeq    lr
    mov     r0, #0x60
_1:
    add     r0, r0, r2
    mov     r1, #0x80000000
    mov     r1, r1, lsr r2
    ldr     r2, [r3, #0]
    bic     r2, r2, r1
    str     r2, [r3, #0]
    bx      lr
}


/*
 * sdk:      OS_ReleaseLockID (os_spinlock.o)
 * asm:      hand-written in the object: the subprogram has no DW_TAG_variable
 *           and .debug_line gives each instruction its own strictly
 *           increasing line (914..929), the asm-function pattern; the body
 *           selects its word with flag-conditional addpl/subpl/submi.
 */
asm void func_02084F10(u16 lockID)
{
    ldr     r3, =0x02FFFFB0
    cmp     r0, #0x60
    addpl   r3, r3, #4
    subpl   r0, r0, #0x60
    submi   r0, r0, #0x40
    mov     r1, #0x80000000
    mov     r1, r1, lsr r0
    ldr     r2, [r3, #0]
    orr     r2, r2, r1
    str     r2, [r3, #0]
    bx      lr
}
