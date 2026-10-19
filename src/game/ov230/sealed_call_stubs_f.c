/*
 * file:     sealed_call_stubs_f.c
 * unit:     yes
 * function: OV230_CallSealedBody16, OV230_CallSealedBody17, LOADER_ENTRY_DecryptCallStubs2
 * address:  0x021893D0
 * region:   ov230d
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Decrypted code of overlay 230 (region ov230d, tools/ovcrypt.py): call stubs 16 to 17 of the sealed bodies and the initialiser entry that decrypts stubs 10 to 17.
 *
 * symbols:
 *   OV230_CallSealedBody16  0x021893D0  arm  ov230d
 *   OV230_CallSealedBody17  0x0218940C  arm  ov230d
 *   LOADER_ENTRY_DecryptCallStubs2  0x02189448  arm  ov230d
 *   LOADER_DECRYPT_DecodeBlocks  0x02188A48  arm  ov230
 */

typedef unsigned int u32;

extern void LOADER_DECRYPT_DecodeBlocks(u32 *desc);

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody16(void (*caller)(void), void (*target)(void), u32 arg)
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
    DCD     0x0218A9B8
    DCD     0x0218AFA8
    DCD     0x00000000
    DCD     0x0218A260
}

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody17(void (*caller)(void), void (*target)(void), u32 arg)
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
    DCD     0x0218A9C4
    DCD     0x0218AFA8
    DCD     0x00000000
    DCD     0x0218A260
}

/* hand-written in the original: initialiser entry for call stubs 10 to 17, same shape as LOADER_ENTRY_Start */
asm void LOADER_ENTRY_DecryptCallStubs2(void)
{
    orr     r0, pc, #0
    adds    r0, r0, #4
    bne     LOADER_DECRYPT_DecodeBlocks
    DCD     0x0218A940
    DCD     0x0218AFC4
    DCD     0x0218A97C
    DCD     0x0218AFC4
    DCD     0x0218A43C
    DCD     0x0218AFC4
    DCD     0x0218A478
    DCD     0x0218AFC4
    DCD     0x0218A698
    DCD     0x0218AFC4
    DCD     0x0218A6D4
    DCD     0x0218AFC4
    DCD     0x0218A9D0
    DCD     0x0218AFC4
    DCD     0x0218AA0C
    DCD     0x0218AFC4
    DCD     0x00000000
    DCD     0x00000000
}

