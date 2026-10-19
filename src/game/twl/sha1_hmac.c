/*
 * file:     sha1_hmac.c
 * unit:     yes
 * function: SHA1_HMAC_Init, SHA1_HMAC_Update, SHA1_HMAC_GetHash, SHA1_HMAC_HashRange, SHA1_HMAC_Start, SHA1_HMAC_UpdateData, SHA1_HMAC_Finish, SHA1_HMAC_Calc
 * address:  0x02731754
 * region:   twl
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Thumb SVC wrappers (hand-written asm) around the DSi BIOS SHA1 calls
 * (swi 0x24 init, 0x25 update, 0x26 get hash, 0x27 hash a range) and the HMAC
 * functions of one object, built with the NITRO mwcc 2.0 (../2.0/sp2).
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 */

typedef unsigned int u32;
#pragma thumb on
asm void SHA1_HMAC_Init(void *ctx);
asm void SHA1_HMAC_Update(void *ctx, const void *data, u32 len);
asm void SHA1_HMAC_GetHash(void *ctx, void *digest);
asm void SHA1_HMAC_HashRange(void *dst, const void *src, u32 len);

/* hand-written in the original: Thumb SVC wrapper around swi 0x24 (BIOS SHA1 init), the original is an asm routine */
asm void SHA1_HMAC_Init(void *ctx)
{
    mov     r3, #0x60
    add     r3, r0
    mov     r2, #0
    str     r2, [r3]
    swi     0x24
    bx      lr
}



/* hand-written in the original: Thumb SVC wrapper around swi 0x25 (BIOS SHA1 update), the original is an asm routine */
asm void SHA1_HMAC_Update(void *ctx, const void *data, u32 len)
{
    swi     0x25
    bx      lr
}


/* hand-written in the original: Thumb SVC wrapper around swi 0x26 (BIOS SHA1 get hash), the original is an asm routine */
asm void SHA1_HMAC_GetHash(void *ctx, void *digest)
{
    mov     r12, r1
    add     r1, r0, #0
    mov     r0, r12
    swi     0x26
    bx      lr
    lsl     r0, r0, #0
}

/* hand-written in the original: Thumb SVC wrapper around swi 0x27 (BIOS SHA1 hash range), the original is an asm routine */
asm void SHA1_HMAC_HashRange(void *dst, const void *src, u32 len)
{
    swi     0x27
    bx      lr
}
#pragma thumb reset

typedef unsigned short u16;

typedef unsigned char u8;

/* HMAC-SHA1 context: a SHA1 state plus the (possibly hashed) key block */
typedef struct Sha1HmacCtx {
    u8 state[0x64];        /* SHA1 state */
    u8 key[0x40];          /* key block */
    u32 keyLen;            /* 0x14 when the key was hashed down */
} Sha1HmacCtx;

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
void SHA1_HMAC_Start(Sha1HmacCtx *ctx, const void *key, u32 key_len);
void SHA1_HMAC_UpdateData(void *a, const void *b, u32 c);
void SHA1_HMAC_Finish(Sha1HmacCtx *ctx, u8 *digest);
void SHA1_HMAC_Calc(u8 *digest, const void *data, u32 data_len, const void *key, u32 key_len);

/* HMAC start: copy or hash the key, then feed the 0x36 inner pad into SHA1 */
void SHA1_HMAC_Start(Sha1HmacCtx *ctx, const void *key, u32 key_len)
{
    u8 ipad[0x40];
    u8 *cursor;
    int i;

    if (ctx == 0) {
        return;
    }
    if (key_len != 0 && key == 0) {
        return;
    }
    if (key_len > 0x40) {
        SHA1_HMAC_HashRange(ctx->key, key, key_len);
        ctx->keyLen = 0x14;
    } else {
        MI_CpuCopy8(key, ctx->key, key_len);
        ctx->keyLen = key_len;
    }
    i = 0;
    if (i < ctx->keyLen) {
        cursor = ipad;
        do {
            *cursor++ = ctx->key[i] ^ 0x36;
            i++;
        } while (i < ctx->keyLen);
    }
    if (i < 0x40) {
        cursor = ipad + i;
        do {
            *cursor++ = 0x36;
            i++;
        } while (i < 0x40);
    }
    SHA1_HMAC_Init(ctx);
    SHA1_HMAC_Update(ctx, ipad, 0x40);
}




/* HMAC update: guarded SHA1 update */
void SHA1_HMAC_UpdateData(void *ctx, const void *data, u32 length)
{
    if (ctx != 0 && length != 0 && data != 0) {
        SHA1_HMAC_Update(ctx, data, length);
    }
}




/* HMAC finish: capture the inner digest, feed the 0x5c outer pad and the
 * inner digest back into SHA1, then read the final digest out */
void SHA1_HMAC_Finish(Sha1HmacCtx *ctx, u8 *digest)
{
    u8 opad[0x40];
    u8 inner[0x14];
    u8 *cursor;
    int i;

    if (ctx == 0 || digest == 0) {
        return;
    }
    SHA1_HMAC_GetHash(ctx, inner);
    i = 0;
    if (i < ctx->keyLen) {
        cursor = opad;
        do {
            *cursor++ = ctx->key[i] ^ 0x5c;
            i++;
        } while (i < ctx->keyLen);
    }
    if (i < 0x40) {
        cursor = opad + i;
        do {
            *cursor++ = 0x5c;
            i++;
        } while (i < 0x40);
    }
    SHA1_HMAC_Init(ctx);
    SHA1_HMAC_Update(ctx, opad, 0x40);
    SHA1_HMAC_Update(ctx, inner, 0x14);
    SHA1_HMAC_GetHash(ctx, digest);
}




/* one-shot HMAC-SHA1 over data with key */
void SHA1_HMAC_Calc(u8 *digest, const void *data, u32 data_len, const void *key, u32 key_len)
{
    Sha1HmacCtx ctx;

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
