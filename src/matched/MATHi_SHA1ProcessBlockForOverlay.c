/*
 * function: MATHi_SHA1ProcessBlockForOverlay
 * address:  0x020812E0
 * packet:   pkt_020812E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libmath dgt_sha1.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Static in the vendor object: hashes the block with words 6 and 14 of the block (offsets 0x18 and 0x38 into it) zeroed, then restores them.
 *
 * symbols:
 *   MATHi_SHA1ProcessBlock  0x02081E7C  arm
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


extern void MATHi_SHA1ProcessBlock(MATHSHA1Context *context);

static void MATHi_SHA1ProcessBlockForOverlay(MATHSHA1Context *context)
{
    u32 *block = (u32 *)context->block;
    u32 s0 = block[6];
    u32 s1 = block[14];

    block[6] = 0;
    block[14] = 0;
    MATHi_SHA1ProcessBlock(context);
    block[6] = s0;
    block[14] = s1;
}
