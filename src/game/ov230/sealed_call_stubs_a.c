/*
 * file:     sealed_call_stubs_a.c
 * unit:     yes
 * function: OV230_CallSealedBody0, OV230_CallSealedBody1, OV230_CallSealedBody2, OV230_CallSealedBody3, OV230_CallSealedBody4, OV230_CallSealedBody5, LOADER_ENTRY_DecryptCallStubs0
 * address:  0x021882A0
 * region:   ov230d
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Decrypted code of overlay 230 (region ov230d, tools/ovcrypt.py): the first six call stubs of the sealed bodies and the initialiser entry that decrypts them.
 *
 * symbols:
 *   OV230_CallSealedBody0  0x021882A0  arm  ov230d
 *   OV230_CallSealedBody1  0x021882DC  arm  ov230d
 *   OV230_CallSealedBody2  0x02188318  arm  ov230d
 *   OV230_CallSealedBody3  0x02188354  arm  ov230d
 *   OV230_CallSealedBody4  0x02188390  arm  ov230d
 *   OV230_CallSealedBody5  0x021883CC  arm  ov230d
 *   LOADER_ENTRY_DecryptCallStubs0  0x02188408  arm  ov230d
 *   LOADER_DECRYPT_DecodeBlocks  0x02188A48  arm  ov230
 */

#include "../types.h"

extern void LOADER_DECRYPT_DecodeBlocks(u32 *desc);

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody0(void (*hook)(void), void (*hookArg)(void), u32 unused)
{
    orr     ip, pc, pc
    ands    ip, ip, ip
    moveq   ip, #0
    addne   ip, ip, #0x1c
    ldr     ip, [ip, #0x14]
    sub     ip, ip, #0x1600
    stmdb   sp!, {ip}
    orr     ip, pc, pc
    ldmia   sp!, {pc}
    DCD     0x021899A1
    DCD     0x0219440F
    DCD     0x02189500
    DCD     0x0218B02C
    DCD     0x00000000
    DCD     0x0218A260
}

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody1(void (*hook)(void), void (*hookArg)(void), u32 unused)
{
    orr     ip, pc, pc
    ands    ip, ip, ip
    moveq   ip, #0
    addne   ip, ip, #0x1c
    ldr     ip, [ip, #0x14]
    sub     ip, ip, #0x1600
    stmdb   sp!, {ip}
    orr     ip, pc, pc
    ldmia   sp!, {pc}
    DCD     0x021899A1
    DCD     0x0219440F
    DCD     0x021895A0
    DCD     0x0218B02C
    DCD     0x00000000
    DCD     0x0218A260
}

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody2(void (*hook)(void), void (*hookArg)(void), u32 unused)
{
    orr     ip, pc, pc
    ands    ip, ip, ip
    moveq   ip, #0
    addne   ip, ip, #0x1c
    ldr     ip, [ip, #0x14]
    sub     ip, ip, #0x1600
    stmdb   sp!, {ip}
    orr     ip, pc, pc
    ldmia   sp!, {pc}
    DCD     0x021899A1
    DCD     0x0219440F
    DCD     0x02189640
    DCD     0x0218B02C
    DCD     0x00000000
    DCD     0x0218A260
}

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody3(void (*hook)(void), void (*hookArg)(void), u32 unused)
{
    orr     ip, pc, pc
    ands    ip, ip, ip
    moveq   ip, #0
    addne   ip, ip, #0x1c
    ldr     ip, [ip, #0x14]
    sub     ip, ip, #0x1600
    stmdb   sp!, {ip}
    orr     ip, pc, pc
    ldmia   sp!, {pc}
    DCD     0x021899A1
    DCD     0x0219440F
    DCD     0x021896E0
    DCD     0x0218B02C
    DCD     0x00000000
    DCD     0x0218A260
}

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody4(void (*hook)(void), void (*hookArg)(void), u32 unused)
{
    orr     ip, pc, pc
    ands    ip, ip, ip
    moveq   ip, #0
    addne   ip, ip, #0x1c
    ldr     ip, [ip, #0x14]
    sub     ip, ip, #0x1600
    stmdb   sp!, {ip}
    orr     ip, pc, pc
    ldmia   sp!, {pc}
    DCD     0x021899A1
    DCD     0x0219440F
    DCD     0x02189780
    DCD     0x0218B020
    DCD     0x00000000
    DCD     0x0218A260
}

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody5(void (*hook)(void), void (*hookArg)(void), u32 unused)
{
    orr     ip, pc, pc
    ands    ip, ip, ip
    moveq   ip, #0
    addne   ip, ip, #0x1c
    ldr     ip, [ip, #0x14]
    sub     ip, ip, #0x1600
    stmdb   sp!, {ip}
    orr     ip, pc, pc
    ldmia   sp!, {pc}
    DCD     0x021899A1
    DCD     0x0219440F
    DCD     0x02189810
    DCD     0x0218B020
    DCD     0x00000000
    DCD     0x0218A260
}

/* hand-written in the original: initialiser entry: r0 = pc + 4 names the range table that follows (six call stubs), always nonzero so the bne reaches the decoder ; one filler word follows the terminator, never read */
asm void LOADER_ENTRY_DecryptCallStubs0(void)
{
    orr     r0, pc, #0
    adds    r0, r0, #4
    bne     LOADER_DECRYPT_DecodeBlocks
    DCD     0x021898A0
    DCD     0x0218AFC4
    DCD     0x021898DC
    DCD     0x0218AFC4
    DCD     0x02189918
    DCD     0x0218AFC4
    DCD     0x02189954
    DCD     0x0218AFC4
    DCD     0x02189990
    DCD     0x0218AFC4
    DCD     0x021899CC
    DCD     0x0218AFC4
    DCD     0x00000000
    DCD     0x00000000
    DCD     0x0218AF54
}
