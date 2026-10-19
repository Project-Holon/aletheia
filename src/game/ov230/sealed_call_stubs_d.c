/*
 * file:     sealed_call_stubs_d.c
 * unit:     yes
 * function: OV230_CallSealedBody12, OV230_CallSealedBody13
 * address:  0x02189098
 * region:   ov230d
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Decrypted code of overlay 230 (region ov230d, tools/ovcrypt.py): call stubs 12 to 13 of the sealed bodies.
 *
 * symbols:
 *   OV230_CallSealedBody12  0x02189098  arm  ov230d
 *   OV230_CallSealedBody13  0x021890D4  arm  ov230d
 *   LOADER_DECRYPT_DecodeBlocks  0x02188A48  arm  ov230
 */

typedef unsigned int u32;

extern void LOADER_DECRYPT_DecodeBlocks(void);

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody12(void (*caller)(void), void (*target)(void), u32 arg)
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
    DCD     0x0218A4B4
    DCD     0x0218B0EC
    DCD     0x00000000
    DCD     0x0218A260
}

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody13(void (*caller)(void), void (*target)(void), u32 arg)
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
    DCD     0x0218A604
    DCD     0x0218B030
    DCD     0x00000000
    DCD     0x0218A260
}
