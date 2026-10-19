/*
 * function: OV230_CallSealedBody1
 * address:  0x021882DC
 * packet:   pkt_ov230d_021882DC
 * region:   ov230d
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     from src/game/ov230/sealed_call_stubs_a.c (decrypted view of overlay 230, region ov230d)
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

typedef unsigned int u32;

extern void LOADER_DECRYPT_DecodeBlocks(void);

/* hand-written in the original: position-independent call stub, pops the dispatcher address out of its own parameter block, which follows it */
asm u32 OV230_CallSealedBody1(void (*caller)(void), void (*target)(void), u32 arg)
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
