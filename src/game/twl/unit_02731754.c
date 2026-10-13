/*
 * file:     unit_02731754.c
 * unit:     yes
 * function: func_02731754, func_02731760, func_02731764, func_02731770, func_02731774, func_0273184C, func_02731868, func_02731920
 * address:  0x02731754
 * region:   twl
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Thumb SVC wrappers (hand-written asm) and the four HMAC functions of
 * one object, built with the NITRO mwcc 2.0 (../2.0/sp2).
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 */

typedef unsigned int u32;
#pragma thumb on
asm void func_02731754(void *ctx);
asm void func_02731760(void *ctx, const void *data, u32 len);
asm void func_02731764(void *ctx, void *digest);
asm void func_02731770(void *dst, const void *src, u32 len);

/* hand-written in the original: Thumb SVC wrapper around swi 0x24 (BIOS call), the original is an asm routine */
asm void func_02731754(void *ctx)
{
    mov     r3, #0x60
    add     r3, r0
    mov     r2, #0
    str     r2, [r3]
    swi     0x24
    bx      lr
}



/* hand-written in the original: Thumb SVC wrapper around swi 0x25 (BIOS call), the original is an asm routine */
asm void func_02731760(void *ctx, const void *data, u32 len)
{
    swi     0x25
    bx      lr
}


/* hand-written in the original: Thumb SVC wrapper around swi 0x26 (BIOS call), the original is an asm routine */
asm void func_02731764(void *ctx, void *digest)
{
    mov     r12, r1
    add     r1, r0, #0
    mov     r0, r12
    swi     0x26
    bx      lr
    lsl     r0, r0, #0
}

/* hand-written in the original: Thumb SVC wrapper around swi 0x27 (BIOS call), the original is an asm routine */
asm void func_02731770(void *dst, const void *src, u32 len)
{
    swi     0x27
    bx      lr
}
#pragma thumb reset

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct HmacCtx {
    u8 sha[0x64];
    u8 key[0x40];
    u32 keyLen;
} HmacCtx;

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
void func_02731774(HmacCtx *ctx, const void *key, u32 key_len);
void func_0273184C(void *a, const void *b, u32 c);
void func_02731868(HmacCtx *ctx, u8 *digest);
void func_02731920(u8 *digest, const void *data, u32 data_len, const void *key, u32 key_len);

void func_02731774(HmacCtx *ctx, const void *key, u32 key_len)
{
    u8 pad[0x40];
    u8 *p;
    int i;

    if (ctx == 0) {
        return;
    }
    if (key_len != 0 && key == 0) {
        return;
    }
    if (key_len > 0x40) {
        func_02731770(ctx->key, key, key_len);
        ctx->keyLen = 0x14;
    } else {
        MI_CpuCopy8(key, ctx->key, key_len);
        ctx->keyLen = key_len;
    }
    i = 0;
    if (i < ctx->keyLen) {
        p = pad;
        do {
            *p++ = ctx->key[i] ^ 0x36;
            i++;
        } while (i < ctx->keyLen);
    }
    if (i < 0x40) {
        p = pad + i;
        do {
            *p++ = 0x36;
            i++;
        } while (i < 0x40);
    }
    func_02731754(ctx);
    func_02731760(ctx, pad, 0x40);
}






















void func_0273184C(void *a, const void *b, u32 c)
{
    if (a != 0 && c != 0 && b != 0) {
        func_02731760(a, b, c);
    }
}






















void func_02731868(HmacCtx *ctx, u8 *digest)
{
    u8 pad[0x40];
    u8 inner[0x14];
    u8 *p;
    int i;

    if (ctx == 0 || digest == 0) {
        return;
    }
    func_02731764(ctx, inner);
    i = 0;
    if (i < ctx->keyLen) {
        p = pad;
        do {
            *p++ = ctx->key[i] ^ 0x5c;
            i++;
        } while (i < ctx->keyLen);
    }
    if (i < 0x40) {
        p = pad + i;
        do {
            *p++ = 0x5c;
            i++;
        } while (i < 0x40);
    }
    func_02731754(ctx);
    func_02731760(ctx, pad, 0x40);
    func_02731760(ctx, inner, 0x14);
    func_02731764(ctx, digest);
}








void func_02731920(u8 *digest, const void *data, u32 data_len, const void *key, u32 key_len)
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
    func_02731774(&ctx, key, key_len);
    func_0273184C(&ctx, data, data_len);
    func_02731868(&ctx, digest);
}
