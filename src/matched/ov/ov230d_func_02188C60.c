/*
 * function: OV230_CallDispatcher
 * address:  0x02188C60
 * packet:   pkt_ov230d_02188C60
 * region:   ov230d
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     from src/game/ov230/sealed_body.c (decrypted view of overlay 230, region ov230d)
 * symbols:
 *   OV230_OpenSealedBody  0x02188B48  arm  ov230d
 *   OV230_SealBody  0x02188BD0  arm  ov230d
 *   OV230_CallDispatcher  0x02188C60  arm  ov230d
 *   LOADER_ENTRY_DecryptCallDispatch  0x02188CB0  arm  ov230d
 *   LOADER_DECRYPT_SyncCacheRange  0x021889E4  arm  ov230
 *   LOADER_DECRYPT_DecodeBlocks  0x02188A48  arm  ov230
 *   OV230_OpenBuffer  0x021898B0  arm  ov230d
 *   OV230_SealBuffer  0x02189858  arm  ov230d
 *   gLoaderDecryptBssStart  0x021899A0  data  ov230
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern char gLoaderDecryptBssStart[];
extern void LOADER_DECRYPT_SyncCacheRange(void *addr, u32 size);
extern int OV230_OpenBuffer(const u8 *key, u8 *src, u8 *dst, u32 size);
extern int OV230_SealBuffer(const u8 *key, u8 *src, u8 *dst, u32 size);
extern void LOADER_DECRYPT_DecodeBlocks(void);

extern u8 *OV230_OpenSealedBody(u32 seed, u32 body, u32 end);
extern u32 OV230_SealBody(u32 seed, u32 body, u32 end);

/* hand-written in the original: entered from a call stub with ip = its parameter block (not an AAPCS call); keeps the caller's lr and r10 in the block and calls the opened body with the caller's r0-r3 */
asm u32 OV230_CallDispatcher(void)
{
    stmdb   sp!, {r0, r1, r2, r3}
    str     r10, [ip, #0x10]
    mov     r10, ip
    str     lr, [r10]
    ldmib   r10, {r0, r1, r2}
    bl      OV230_OpenSealedBody
    mov     ip, r0
    ldmia   sp!, {r0, r1, r2, r3}
    blx     ip
    stmdb   sp!, {r4}
    mov     r4, r0
    ldmib   r10, {r0, r1, r2}
    bl      OV230_SealBody
    str     r0, [r10, #4]
    mov     r0, r4
    ldmia   sp!, {r4}
    ldr     lr, [r10]
    str     sp, [r10]
    ldr     r10, [r10, #0x10]
    bx      lr
}
