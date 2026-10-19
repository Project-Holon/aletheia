/*
 * function: OV230_SealBody
 * address:  0x02188BD0
 * packet:   pkt_ov230d_02188BD0
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
