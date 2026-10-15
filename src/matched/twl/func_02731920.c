/*
 * function: SHA1_HMAC_Calc
 * address:  0x02731920
 * packet:   twl_sys
 * region:   twl
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SHA1_HMAC_Start  0x02731774  arm  twl
 *   SHA1_HMAC_UpdateData  0x0273184C  arm  twl
 *   SHA1_HMAC_Finish  0x02731868  arm  twl
 */

/* HMAC-SHA1 one-shot over the BIOS SHA1 calls. The object 0x02731754..
   0x0273199C (SVC wrappers and the four HMAC functions) was built with the
   NITRO mwcc 2.0: every 2.0 build compiles it whole to the image, while
   dsi/1.1p1 keeps &ctx in a callee-saved register across the three calls. */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct HmacCtx {
    u8 sha[0x64];
    u8 key[0x40];
    u32 keyLen;
} HmacCtx;

void SHA1_HMAC_Start(HmacCtx *ctx, const void *key, u32 key_len);
void SHA1_HMAC_UpdateData(void *a, const void *b, u32 c);
void SHA1_HMAC_Finish(HmacCtx *ctx, u8 *digest);

void SHA1_HMAC_Calc(u8 *digest, const void *data, u32 data_len, const void *key, u32 key_len)
{
    HmacCtx ctx;

    if (digest == 0) {
        return;
    }
    if (data_len != 0 && data == 0) {
        return;
    }
    if (key_len != 0 && key == 0) {
        return;
    }
    SHA1_HMAC_Start(&ctx, key, key_len);
    SHA1_HMAC_UpdateData(&ctx, data, data_len);
    SHA1_HMAC_Finish(&ctx, digest);
}
