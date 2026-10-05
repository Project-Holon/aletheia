/*
 * function: func_02084F10
 * address:  0x02084F10
 * packet:   pkt_02084F10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_ReleaseLockID (os_spinlock.o)
 * asm:      hand-written in the object: the subprogram has no DW_TAG_variable
 *           and .debug_line gives each instruction its own strictly
 *           increasing line (914..929), the asm-function pattern; the body
 *           selects its word with flag-conditional addpl/subpl/submi.
 */

typedef unsigned short u16;

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
