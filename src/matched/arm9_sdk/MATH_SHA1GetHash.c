/*
 * function: MATH_SHA1GetHash
 * address:  0x020814C0
 * packet:   pkt_020814C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libmath dgt_sha1.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Pads the message (0x80, zeros, the big-endian bit count), hashes the
 * last block and copies the big-endian digest out.  The footer sums are
 * written with the wider shift first (blocks_low << 9 + pool << 3); the
 * other order swaps the add's operands.  The five digest swaps are written
 * out: a loop is not unrolled at -O4.
 *
 * symbols:
 *   MATH_SHA1Update                                         0x0208142C  arm
 *   MATHi_SHA1Fill                                          0x0208130C  arm
 *   MI_CpuCopy8                                             0x02082D44  arm
 *   _ZZ16MATH_SHA1GetHashP15MATHSHA1ContextPvE7padlead      0x020A5CAC  data
 *   _ZZ16MATH_SHA1GetHashP15MATHSHA1ContextPvE8padalign_0   0x020A5CAD  data
 */

typedef unsigned long u32;
typedef unsigned char u8;

#define MATH_SHA1_BLOCK_SIZE 64

typedef struct MATHSHA1Context {
    u32 h[5];
    u8 block[MATH_SHA1_BLOCK_SIZE];
    u32 pool;
    u32 blocks_low;
    u32 blocks_high;
} MATHSHA1Context;

extern void (*MATHi_SHA1ProcessMessageBlockFunc)(MATHSHA1Context *context);

extern void MATH_SHA1Update(MATHSHA1Context *context, const void *input, u32 length);
extern void MATHi_SHA1Fill(MATHSHA1Context *context, u8 input, u32 length);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);

extern const u8 _ZZ16MATH_SHA1GetHashP15MATHSHA1ContextPvE7padlead[1];
extern const u8 _ZZ16MATH_SHA1GetHashP15MATHSHA1ContextPvE8padalign_0[8];

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
