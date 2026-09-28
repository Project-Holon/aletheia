/*
 * function: MATH_CalcSHA1
 * address:  0x020816B8
 * packet:   pkt_020816B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libmath dgt_sha1.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * One-shot SHA-1 through a stack context.
 *
 * symbols:
 *   MATH_SHA1Init     0x020813D8  arm
 *   MATH_SHA1Update   0x0208142C  arm
 *   MATH_SHA1GetHash  0x020814C0  arm
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


extern void MATH_SHA1Init(MATHSHA1Context *context);
extern void MATH_SHA1Update(MATHSHA1Context *context, const void *input, u32 length);
extern void MATH_SHA1GetHash(MATHSHA1Context *context, void *digest);

void MATH_CalcSHA1(void *digest, const void *data, u32 dataLength)
{
    MATHSHA1Context context;

    MATH_SHA1Init(&context);
    MATH_SHA1Update(&context, data, dataLength);
    MATH_SHA1GetHash(&context, digest);
}
