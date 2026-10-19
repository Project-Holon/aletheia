/*
 * file:     dgt_sha1.c
 * unit:     yes
 * function: MATHi_SHA1ProcessBlockForOverlay, MATHi_SHA1Fill, MATHi_SetOverlayTableMode, MATH_SHA1Init, MATH_SHA1Update, MATH_SHA1GetHash, MATH_CalcSHA1, MATH_CalcHMACSHA1
 * address:  0x020812E0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MATHi_SHA1Transform  0x02081E7C  arm
 *   MI_CpuFill8                        0x02082BCC  arm
 *   MATHi_SHA1ProcessMessageBlockFunc  0x020A8688  data
 *   MATHi_OverlayTableMode             0x02150E68  data
 *   MI_CpuCopy8                        0x02082D44  arm
 *   _ZZ16MATH_SHA1GetHashP15MATHSHA1ContextPvE7padlead      0x020A5CAC  data
 *   _ZZ16MATH_SHA1GetHashP15MATHSHA1ContextPvE8padalign_0   0x020A5CAD  data
 *   MATHi_CalcHMAC    0x02081790  arm
 *   @12151            0x020A5CB8  data
 */
#define MATH_SHA1_BLOCK_SIZE 64

typedef unsigned long u32;

typedef unsigned char u8;

typedef struct MATHSHA1Context {
    u32 h[5];
    u8 block[MATH_SHA1_BLOCK_SIZE];
    u32 pool;
    union {
        struct {
            u32 blocks_low;
            u32 blocks_high;
        };
        unsigned long long length;
    };
} MATHSHA1Context;

typedef struct MATHiHMACFuncs {
    u32 dlength;
    u32 blength;
    void *context;
    u8 *hash_buf;
    void (*HashReset)(void *context);
    void (*HashSetSource)(void *context, const void *input, u32 length);
    void (*HashGetDigest)(void *context, void *digest);
} MATHiHMACFuncs;

extern void MATHi_SHA1Transform(MATHSHA1Context *context);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void MATHi_CalcHMAC(void *mac, const void *message, u32 message_length, const void *key, u32 key_length, MATHiHMACFuncs *funcs);
int MATHi_SetOverlayTableMode(int flag);
void MATH_SHA1Init(MATHSHA1Context *context);
void MATH_SHA1Update(MATHSHA1Context *context, const void *input, u32 length);
void MATH_SHA1GetHash(MATHSHA1Context *context, void *digest);
void MATH_CalcSHA1(void *digest, const void *data, u32 dataLength);
void MATH_CalcHMACSHA1(void *digest, const void *bin_ptr, u32 bin_len, const void *key_ptr, u32 key_len);
extern int MATHi_OverlayTableMode;
extern const u8 _ZZ16MATH_SHA1GetHashP15MATHSHA1ContextPvE7padlead[1];
extern const u8 _ZZ16MATH_SHA1GetHashP15MATHSHA1ContextPvE8padalign_0[8];








static void MATHi_SHA1ProcessBlockForOverlay(MATHSHA1Context *context)
{
    u32 *block = (u32 *)context->block;
    u32 s0 = block[6];
    u32 s1 = block[14];

    block[6] = 0;
    block[14] = 0;
    MATHi_SHA1Transform(context);
    block[6] = s0;
    block[14] = s1;
}








extern void (*MATHi_SHA1ProcessMessageBlockFunc)(MATHSHA1Context *context);








static void MATHi_SHA1Fill(MATHSHA1Context *context, u8 input, u32 length)
{
    while (length > 0) {
        u32 rest = MATH_SHA1_BLOCK_SIZE - context->pool;

        if (rest > length) {
            rest = length;
        }
        MI_CpuFill8(context->block + context->pool, input, rest);
        length -= rest;
        context->pool += rest;
        if (context->pool >= MATH_SHA1_BLOCK_SIZE) {
            MATHi_SHA1ProcessMessageBlockFunc(context);
            context->pool = 0;
            ++context->blocks_low;
            if (!context->blocks_low) {
                ++context->blocks_high;
            }
        }
    }
}














int MATHi_SetOverlayTableMode(int flag)
{
    int prev = MATHi_OverlayTableMode;

    MATHi_OverlayTableMode = flag;
    if (flag) {
        MATHi_SHA1ProcessMessageBlockFunc = MATHi_SHA1ProcessBlockForOverlay;
    } else {
        MATHi_SHA1ProcessMessageBlockFunc = MATHi_SHA1Transform;
    }
    return prev;
}







void MATH_SHA1Init(MATHSHA1Context *context)
{
    context->blocks_low = 0;
    context->blocks_high = 0;
    context->pool = 0;
    context->h[0] = 0x67452301;
    context->h[1] = 0xEFCDAB89;
    context->h[2] = 0x98BADCFE;
    context->h[3] = 0x10325476;
    context->h[4] = 0xC3D2E1F0;
}










void MATH_SHA1Update(MATHSHA1Context *context, const void *input, u32 length)
{
    while (length > 0) {
        u32 rest = MATH_SHA1_BLOCK_SIZE - context->pool;

        if (rest > length) {
            rest = length;
        }
        MI_CpuCopy8(input, context->block + context->pool, rest);
        input = (const u8 *)input + rest;
        length -= rest;
        context->pool += rest;
        if (context->pool >= MATH_SHA1_BLOCK_SIZE) {
            MATHi_SHA1ProcessMessageBlockFunc(context);
            context->pool = 0;
            ++context->blocks_low;
            if (!context->blocks_low) {
                ++context->blocks_high;
            }
        }
    }
}








static inline u32 MATHi_Swap32(u32 x)
{
    return ((x >> 24) & 0x000000FF) | ((x >> 8) & 0x0000FF00) | ((x << 8) & 0x00FF0000) | ((x << 24) & 0xFF000000);
}




void MATH_SHA1GetHash(MATHSHA1Context *context, void *digest)
{
    u32 footer[2];

    footer[1] = MATHi_Swap32((context->blocks_low << 9) + (context->pool << 3));
    footer[0] = MATHi_Swap32((context->blocks_high << 9) + (context->blocks_low >> 23));

    MATH_SHA1Update(context, _ZZ16MATH_SHA1GetHashP15MATHSHA1ContextPvE7padlead, 1);
    if (MATH_SHA1_BLOCK_SIZE - context->pool < sizeof(footer)) {
        MATH_SHA1Update(context, _ZZ16MATH_SHA1GetHashP15MATHSHA1ContextPvE8padalign_0, MATH_SHA1_BLOCK_SIZE - context->pool);
    }
    MATHi_SHA1Fill(context, 0, MATH_SHA1_BLOCK_SIZE - sizeof(footer) - context->pool);
    MATH_SHA1Update(context, footer, sizeof(footer));

    context->h[0] = MATHi_Swap32(context->h[0]);
    context->h[1] = MATHi_Swap32(context->h[1]);
    context->h[2] = MATHi_Swap32(context->h[2]);
    context->h[3] = MATHi_Swap32(context->h[3]);
    context->h[4] = MATHi_Swap32(context->h[4]);
    MI_CpuCopy8(context->h, digest, sizeof(context->h));
}



void MATH_CalcSHA1(void *digest, const void *data, u32 dataLength)
{
    MATHSHA1Context context;

    MATH_SHA1Init(&context);
    MATH_SHA1Update(&context, data, dataLength);
    MATH_SHA1GetHash(&context, digest);
}


/*
 * notes:    byte-correct; the pool word for the hash2funcs initializer template is named `@12151` (the vendor member's local) in the symbols: block and resolves under the `template` class (image 0x020A5CB8 holds the member's 28 template bytes, uniquely).
 *
 * sdk:      MATH_CalcHMACSHA1 (dgt_sha1.o)
 */
void MATH_CalcHMACSHA1(void *digest, const void *bin_ptr, u32 bin_len, const void *key_ptr, u32 key_len)
{
    MATHSHA1Context context;
    u8 hash_buf[20];
    MATHiHMACFuncs hash2funcs = {
        20,
        64,
    };

    hash2funcs.context = &context;
    hash2funcs.hash_buf = hash_buf;
    hash2funcs.HashReset = (void (*)(void *))MATH_SHA1Init;
    hash2funcs.HashSetSource = (void (*)(void *, const void *, u32))MATH_SHA1Update;
    hash2funcs.HashGetDigest = (void (*)(void *, void *))MATH_SHA1GetHash;

    MATHi_CalcHMAC(digest, bin_ptr, bin_len, key_ptr, key_len, &hash2funcs);
}
