/*
 * function: MATHi_SetOverlayTableMode
 * address:  0x0208139C
 * packet:   pkt_0208139C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libmath dgt_sha1.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Selects the block function (the plain one, or the wrapper that preserves two block words for overlay-table hashing) and returns the previous mode.
 *
 * symbols:
 *   MATHi_OverlayTableMode             0x02150E68  data
 *   MATHi_SHA1ProcessBlockForOverlay   0x020812E0  arm
 *   MATHi_SHA1ProcessMessageBlockFunc  0x020A8688  data
 *   MATHi_SHA1ProcessBlock             0x02081E7C  arm
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

extern int MATHi_OverlayTableMode;
extern void MATHi_SHA1ProcessBlockForOverlay(MATHSHA1Context *context);
extern void MATHi_SHA1ProcessBlock(MATHSHA1Context *context);

int MATHi_SetOverlayTableMode(int flag)
{
    int prev = MATHi_OverlayTableMode;

    MATHi_OverlayTableMode = flag;
    if (flag) {
        MATHi_SHA1ProcessMessageBlockFunc = MATHi_SHA1ProcessBlockForOverlay;
    } else {
        MATHi_SHA1ProcessMessageBlockFunc = MATHi_SHA1ProcessBlock;
    }
    return prev;
}
