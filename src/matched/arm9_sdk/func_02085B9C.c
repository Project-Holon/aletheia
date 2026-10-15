/*
 * function: OS_InitContext
 * address:  0x02085B9C
 * packet:   pkt_02085B9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_InitContext (os_context.o)
 * asm:      hand-written in the object: the subprogram has no DW_TAG_variable
 *           and .debug_line gives each of the 27 instructions its own strictly
 *           increasing line (43..78), the asm-function pattern; the C spelling
 *           schedules the stores and uses tst, not ands.
 */

typedef unsigned long u32;
typedef unsigned char u8;

typedef struct CPContext {
    u8 opaque[0x1C];
} CPContext;

typedef struct OSContext {
    u32 cpsr;
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pc_plus4;
    u32 sp_svc;
    CPContext cp_context;
} OSContext;

asm void OS_InitContext(OSContext *context, u32 newpc, u32 newsp)
{
    add     r1, r1, #4
    str     r1, [r0, #0x40]
    str     r2, [r0, #0x44]
    sub     r2, r2, #0x40
    tst     r2, #4
    subne   r2, r2, #4
    str     r2, [r0, #0x38]
    ands    r1, r1, #1
    movne   r1, #0x3f
    moveq   r1, #0x1f
    str     r1, [r0]
    mov     r1, #0
    str     r1, [r0, #0x4]
    str     r1, [r0, #0x8]
    str     r1, [r0, #0xc]
    str     r1, [r0, #0x10]
    str     r1, [r0, #0x14]
    str     r1, [r0, #0x18]
    str     r1, [r0, #0x1c]
    str     r1, [r0, #0x20]
    str     r1, [r0, #0x24]
    str     r1, [r0, #0x28]
    str     r1, [r0, #0x2c]
    str     r1, [r0, #0x30]
    str     r1, [r0, #0x34]
    str     r1, [r0, #0x3c]
    bx      lr
}
