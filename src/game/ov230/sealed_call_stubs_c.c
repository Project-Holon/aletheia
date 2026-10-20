/*
 * file:     sealed_call_stubs_c.c
 * unit:     yes
 * function: OV230_CallSealedBody10, OV230_CallSealedBody11
 * address:  0x02188E3C
 * region:   ov230d
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Decrypted code of overlay 230 (region ov230d, tools/ovcrypt.py): call stubs 10 to 11 of the sealed bodies.
 *
 * symbols:
 *   OV230_CallSealedBody10  0x02188E3C  arm  ov230d
 *   OV230_CallSealedBody11  0x02188E78  arm  ov230d
 *   LOADER_DECRYPT_DecodeBlocks  0x02188A48  arm  ov230
 */

#include "../types.h"

#include "loader_decrypt.h"

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody10(void (*caller)(void), void (*target)(void), u32 arg)
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
    DCD     0x021971AD
    DCD     0x0218A2DC
    DCD     0x0218B04C
    DCD     0x00000000
    DCD     0x0218A260
}

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody11(void (*caller)(void), void (*target)(void), u32 arg)
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
    DCD     0x021971AD
    DCD     0x0218A38C
    DCD     0x0218B04C
    DCD     0x00000000
    DCD     0x0218A260
}
