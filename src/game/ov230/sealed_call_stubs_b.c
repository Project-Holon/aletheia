/*
 * file:     sealed_call_stubs_b.c
 * unit:     yes
 * function: OV230_CallSealedBody6, OV230_CallSealedBody7, OV230_CallSealedBody8, OV230_CallSealedBody9
 * address:  0x021888C0
 * region:   ov230d
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Decrypted code of overlay 230 (region ov230d, tools/ovcrypt.py): call stubs 6 to 9 of the sealed bodies; LOADER_ENTRY_Start (loader_entry.c) decrypts them.
 *
 * symbols:
 *   OV230_CallSealedBody6  0x021888C0  arm  ov230d
 *   OV230_CallSealedBody7  0x021888FC  arm  ov230d
 *   OV230_CallSealedBody8  0x02188938  arm  ov230d
 *   OV230_CallSealedBody9  0x02188974  arm  ov230d
 *   LOADER_DECRYPT_DecodeBlocks  0x02188A48  arm  ov230
 */

typedef unsigned int u32;

extern void LOADER_DECRYPT_DecodeBlocks(void);

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody6(void (*caller)(void), void (*target)(void), u32 arg)
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
    DCD     0x0219492E
    DCD     0x02189A50
    DCD     0x0218B0B0
    DCD     0x00000000
    DCD     0x0218A260
}

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody7(void (*caller)(void), void (*target)(void), u32 arg)
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
    DCD     0x0219492E
    DCD     0x02189B6C
    DCD     0x0218B0B0
    DCD     0x00000000
    DCD     0x0218A260
}

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody8(void (*caller)(void), void (*target)(void), u32 arg)
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
    DCD     0x0219492E
    DCD     0x02189C88
    DCD     0x0218B0B0
    DCD     0x00000000
    DCD     0x0218A260
}

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody9(void (*caller)(void), void (*target)(void), u32 arg)
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
    DCD     0x0219492E
    DCD     0x02189DA4
    DCD     0x0218B0B0
    DCD     0x00000000
    DCD     0x0218A260
}
