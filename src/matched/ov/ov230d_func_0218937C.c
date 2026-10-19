/*
 * function: OV230_CallSealedBody15
 * address:  0x0218937C
 * packet:   pkt_ov230d_0218937C
 * region:   ov230d
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     from src/game/ov230/sealed_call_stubs_e.c (decrypted view of overlay 230, region ov230d)
 * symbols:
 *   OV230_CallSealedBody14  0x02189340  arm  ov230d
 *   OV230_CallSealedBody15  0x0218937C  arm  ov230d
 *   LOADER_DECRYPT_DecodeBlocks  0x02188A48  arm  ov230
 */

typedef unsigned int u32;

extern void LOADER_DECRYPT_DecodeBlocks(void);

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody15(void (*caller)(void), void (*target)(void), u32 arg)
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
    DCD     0x0218A828
    DCD     0x0218B0B8
    DCD     0x00000000
    DCD     0x0218A260
}
