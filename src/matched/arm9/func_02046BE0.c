/*
 * function: G3D_SYSTEM_SetSwapBuffersMode
 * address:  0x02046BE0
 * packet:   pkt_02046858
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _G3dSystem   0x02146A5C  data
 *
 * Store the pair of words at +0x80 and +0x84 of the context at 0x02146A5C.
 * The context pointer is re-read from its own slot between the two stores,
 * because the first store cannot be proven not to alias it; the second load
 * therefore goes to r0, the register the outgoing value no longer needs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_SYSTEM_SetSwapBuffersMode.c \
 *       --func G3D_SYSTEM_SetSwapBuffersMode --addr 0x02046BE0 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Ctx {
    u8  pad_00[0x80];
    u32 unk_80;
    u32 unk_84;
};

extern struct Ctx *_G3dSystem;

void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b)
{
    _G3dSystem->unk_80 = a;
    _G3dSystem->unk_84 = b;
}
