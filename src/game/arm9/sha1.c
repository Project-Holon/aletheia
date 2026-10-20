/*
 * file:     sha1.c
 * function: MATHi_SHA1Transform
 * address:  0x02081E7C
 * packet:   pkt_02081E7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MATHi_SHA1ProcessBlock (libmath.TWL.HYB.a sha1.o); catalog name MATHi_SHA1Transform
 * asm:      sha1.o is an asm-only object: its STT_FILE symbol names sha1.s, it has no .comment and no DWARF. Its .text is a 16-byte $d block (the four SHA-1 round constants) followed by these 796 bytes of $a code.
 * notes:    void (context): the five-word hash state is at +0x0, the 64-byte message block at +0x14. The round constants are read pc-relative from the $d block that precedes the entry (0x02081E6C).
 *
 * symbols:
 *   SHA1_ROUND_CONSTANTS  0x02081E6C  data
 */

#include "dgt_sha1.h"

/* the four round constants (5A827999 6ED9EBA1 8F1BBCDC CA62C1D6): values from the user's ROM (tools/gendata.py) */
const unsigned long SHA1_ROUND_CONSTANTS[4] = {
#include "../../../build/gen/words_sha1_02081E6C.inc"
};

/* hand-written in the original: MATHi_SHA1ProcessBlock, asm-only SDK object (sha1.s, no DWARF, no .comment; pc-relative round constants in a $d block) */
asm void MATHi_SHA1Transform(MATHSHA1Context *context)
{
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    mov r11, r0
    sub sp, sp, #0x40
    mov r12, sp
    mvn r3, #0xff00
    add r8, r11, #0x14
    mov r1, r12
    ldmia r8!, {r4, r5, r6, r7}
    mov r9, #0x10
@_2081EA0:
    eor r2, r4, r4, ror #16
    and r2, r3, r2, lsr #8
    eor r4, r2, r4, ror #8
    eor r2, r5, r5, ror #16
    and r2, r3, r2, lsr #8
    eor r5, r2, r5, ror #8
    eor r2, r6, r6, ror #16
    and r2, r3, r2, lsr #8
    eor r6, r2, r6, ror #8
    eor r2, r7, r7, ror #16
    and r2, r3, r2, lsr #8
    eor r7, r2, r7, ror #8
    stmia r1!, {r4, r5, r6, r7}
    subs r9, r9, #4
    ldmneia r8!, {r4, r5, r6, r7}
    bne @_2081EA0
    ldmia r11, {r4, r5, r6, r7, r8}
    ldr r12, [pc, #-0x80]
    mov r9, #0
@_2081EEC:
    and r10, r5, r6
    mvn lr, r5
    and lr, lr, r7
    orr r10, r10, lr
    add r10, r10, r12
    and lr, r9, #0xf
    ldr lr, [sp, lr, lsl #2]
    add r10, r10, r8
    add r10, r10, lr
    add r10, r10, r4, ror #27
    mov r8, r7
    mov r7, r6
    mov r6, r5, ror #2
    mov r5, r4
    mov r4, r10
    add r9, r9, #1
    cmp r9, #0x10
    bne @_2081EEC
@_2081F34:
    and r10, r5, r6
    mvn lr, r5
    and lr, lr, r7
    orr r10, r10, lr
    add r10, r10, r12
    sub r2, r9, #0x10
    and r2, r2, #0xf
    sub lr, r9, #0xe
    and lr, lr, #0xf
    ldr r3, [sp, r2, lsl #2]
    ldr r1, [sp, lr, lsl #2]
    sub lr, r9, #8
    eor r3, r3, r1
    and lr, lr, #0xf
    ldr r1, [sp, lr, lsl #2]
    sub r2, r9, #3
    eor r3, r3, r1
    and r2, r2, #0xf
    ldr r1, [sp, r2, lsl #2]
    and r2, r9, #0xf
    eor r3, r3, r1
    mov r3, r3, ror #0x1f
    str r3, [sp, r2, lsl #2]
    and lr, r9, #0xf
    ldr lr, [sp, lr, lsl #2]
    add r10, r10, r8
    add r10, r10, lr
    add r10, r10, r4, ror #27
    mov r8, r7
    mov r7, r6
    mov r6, r5, ror #2
    mov r5, r4
    mov r4, r10
    add r9, r9, #1
    cmp r9, #0x14
    bne @_2081F34
    ldr r12, [pc, #-0x15c]
@_2081FC8:
    eor r10, r5, r6
    eor r10, r10, r7
    add r10, r10, r12
    sub r2, r9, #0x10
    and r2, r2, #0xf
    sub lr, r9, #0xe
    and lr, lr, #0xf
    ldr r3, [sp, r2, lsl #2]
    ldr r1, [sp, lr, lsl #2]
    sub lr, r9, #8
    eor r3, r3, r1
    and lr, lr, #0xf
    ldr r1, [sp, lr, lsl #2]
    sub r2, r9, #3
    eor r3, r3, r1
    and r2, r2, #0xf
    ldr r1, [sp, r2, lsl #2]
    and r2, r9, #0xf
    eor r3, r3, r1
    mov r3, r3, ror #0x1f
    str r3, [sp, r2, lsl #2]
    and lr, r9, #0xf
    ldr lr, [sp, lr, lsl #2]
    add r10, r10, r8
    add r10, r10, lr
    add r10, r10, r4, ror #27
    mov r8, r7
    mov r7, r6
    mov r6, r5, ror #2
    mov r5, r4
    mov r4, r10
    add r9, r9, #1
    cmp r9, #0x28
    bne @_2081FC8
    ldr r12, [pc, #-0x1e4]
@_2082054:
    and r10, r5, r6
    and lr, r5, r7
    orr r10, r10, lr
    and lr, r6, r7
    orr r10, r10, lr
    add r10, r10, r12
    sub r2, r9, #0x10
    and r2, r2, #0xf
    sub lr, r9, #0xe
    and lr, lr, #0xf
    ldr r3, [sp, r2, lsl #2]
    ldr r1, [sp, lr, lsl #2]
    sub lr, r9, #8
    eor r3, r3, r1
    and lr, lr, #0xf
    ldr r1, [sp, lr, lsl #2]
    sub r2, r9, #3
    eor r3, r3, r1
    and r2, r2, #0xf
    ldr r1, [sp, r2, lsl #2]
    and r2, r9, #0xf
    eor r3, r3, r1
    mov r3, r3, ror #0x1f
    str r3, [sp, r2, lsl #2]
    and lr, r9, #0xf
    ldr lr, [sp, lr, lsl #2]
    add r10, r10, r8
    add r10, r10, lr
    add r10, r10, r4, ror #27
    mov r8, r7
    mov r7, r6
    mov r6, r5, ror #2
    mov r5, r4
    mov r4, r10
    add r9, r9, #1
    cmp r9, #0x3c
    bne @_2082054
    ldr r12, [pc, #-0x278]
@_20820EC:
    eor r10, r5, r6
    eor r10, r10, r7
    add r10, r10, r12
    sub r2, r9, #0x10
    and r2, r2, #0xf
    sub lr, r9, #0xe
    and lr, lr, #0xf
    ldr r3, [sp, r2, lsl #2]
    ldr r1, [sp, lr, lsl #2]
    sub lr, r9, #8
    eor r3, r3, r1
    and lr, lr, #0xf
    ldr r1, [sp, lr, lsl #2]
    sub r2, r9, #3
    eor r3, r3, r1
    and r2, r2, #0xf
    ldr r1, [sp, r2, lsl #2]
    and r2, r9, #0xf
    eor r3, r3, r1
    mov r3, r3, ror #0x1f
    str r3, [sp, r2, lsl #2]
    and lr, r9, #0xf
    ldr lr, [sp, lr, lsl #2]
    add r10, r10, r8
    add r10, r10, lr
    add r10, r10, r4, ror #27
    mov r8, r7
    mov r7, r6
    mov r6, r5, ror #2
    mov r5, r4
    mov r4, r10
    add r9, r9, #1
    cmp r9, #0x50
    bne @_20820EC
    ldmia r11, {r1, r2, r3, r9, r10}
    add r1, r1, r4
    add r2, r2, r5
    add r3, r3, r6
    add r9, r9, r7
    add r10, r10, r8
    stmia r11, {r1, r2, r3, r9, r10}
    add sp, sp, #0x40
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, pc}
}
