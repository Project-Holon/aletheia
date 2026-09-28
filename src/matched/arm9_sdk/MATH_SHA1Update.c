/*
 * function: MATH_SHA1Update
 * address:  0x0208142C
 * packet:   pkt_0208142C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libmath dgt_sha1.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Appends length bytes to the 64-byte block, hashing each full block.
 *
 * symbols:
 *   MI_CpuCopy8                        0x02082D44  arm
 *   MATHi_SHA1ProcessMessageBlockFunc  0x020A8688  data
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

extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);

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
