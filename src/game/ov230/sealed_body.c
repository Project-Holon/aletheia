/*
 * file:     sealed_body.c
 * unit:     yes
 * function: OV230_OpenSealedBody, OV230_SealBody, OV230_CallDispatcher, LOADER_ENTRY_DecryptCallDispatch
 * address:  0x02188B48
 * region:   ov230d
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Decrypted code of overlay 230 (region ov230d, tools/ovcrypt.py): the call dispatcher behind every
 * OV230_CallSealedBodyN stub. Each stub names a parameter block; the dispatcher opens the sealed body
 * the block points at (decrypts it in place), calls it with the caller's arguments, seals it again
 * with a seed advanced by the body's address, and returns the body's result. The cipher is
 * sealed_cipher.c. LOADER_ENTRY_DecryptCallDispatch decrypts these three functions at load time.
 *
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
#include "../types.h"
extern char gLoaderDecryptBssStart[];
extern void LOADER_DECRYPT_SyncCacheRange(void *addr, u32 size);
extern int OV230_OpenBuffer(const u8 *key, u8 *src, u8 *dst, u32 size);
extern int OV230_SealBuffer(const u8 *key, u8 *src, u8 *dst, u32 size);
extern void LOADER_DECRYPT_DecodeBlocks(u32 *desc);

u8 *OV230_OpenSealedBody(u32 seed, u32 body, u32 end)
{
    u32 key[4];
    u32 bias = (u32)gLoaderDecryptBssStart + 0x1600;

    seed -= bias;
    end -= bias;
    key[0] = seed ^ end;
    key[1] = end ^ ((seed << 8) | (seed >> 24));
    key[2] = end ^ ((seed << 16) | (seed >> 16));
    key[3] = end ^ ((seed << 24) | (seed >> 8));
    OV230_OpenBuffer((u8 *)key, (u8 *)(body - 0x1600), (u8 *)(body - 0x1600), end);
    LOADER_DECRYPT_SyncCacheRange((void *)(body - 0x1600), end);
    return (u8 *)(body - 0x1600);
}

u32 OV230_SealBody(u32 seed, u32 body, u32 end)
{
    u32 key[4];
    u32 bias = (u32)gLoaderDecryptBssStart + 0x1600;

    seed -= bias;
    seed += body >> 20;
    end -= bias;
    key[0] = seed ^ end;
    key[1] = end ^ ((seed << 8) | (seed >> 24));
    key[2] = end ^ ((seed << 16) | (seed >> 16));
    key[3] = end ^ ((seed << 24) | (seed >> 8));
    OV230_SealBuffer((u8 *)key, (u8 *)(body - 0x1600), (u8 *)(body - 0x1600), end);
    LOADER_DECRYPT_SyncCacheRange((void *)(body - 0x1600), end);
    return seed + bias;
}

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

/* hand-written in the original: initialiser entry, r0 = pc + 4 names the range table that follows (the three functions above), always nonzero so the bne reaches the decoder */
asm void LOADER_ENTRY_DecryptCallDispatch(void)
{
    orr     r0, pc, #0
    adds    r0, r0, #4
    bne     LOADER_DECRYPT_DecodeBlocks
    DCD     0x0218A1D0
    DCD     0x0218B02C
    DCD     0x0218A148
    DCD     0x0218B024
    DCD     0x0218A260
    DCD     0x0218AFF0
    DCD     0x00000000
    DCD     0x00000000
}
