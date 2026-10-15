/*
 * function: BMP_WIN_Create
 * address:  0x020450F0
 * packet:   pkt_020445F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_GetField16  0x0204169C  arm
 *   BG_SYS_CreateRun  0x0203FA08  arm
 *   BMP_WIN_Alloc   0x02045210  arm
 *
 * Set up a BG layer whose character data is placed at a VRAM offset chosen
 * by the allocator.  BG_SYS_GetField16 says whether the layer is 8bpp; that
 * decides both the flag handed to BMP_WIN_Alloc and whether a cell costs one
 * or two units, and the unit count is scaled by 32 to bytes before
 * BG_SYS_CreateRun is asked for room.  A returned -1 (not 0) is the allocator's
 * failure answer, and the function reports failure as 0.
 *
 * BMP_WIN_CreateAt, the next function, is the same routine for the case where
 * the caller already knows the offset: it calls BG_SYS_CheckFAF0 to reserve
 * that exact offset instead, passes a count rather than a byte size, and
 * forwards the caller's offset straight through as BMP_WIN_Alloc's seventh
 * argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_Create.c \
 *       --func BMP_WIN_Create --addr 0x020450F0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed int     s32;

extern u8 BG_SYS_GetField16(int channel);
extern u32 BG_SYS_CreateRun(u32 layer, u32 size, u32 top);
extern u32 BMP_WIN_Alloc(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d,
                        u32 offset, u32 is8bpp);

u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot)
{
    u32 is8bpp;
    u32 units;
    s32 offset;

    if (BG_SYS_GetField16(layer) == 0) {
        is8bpp = 0;
        units = tiles * c;
    } else {
        is8bpp = 1;
        units = tiles * c * 2;
    }

    offset = BG_SYS_CreateRun(layer, units * 32, slot);
    if (offset == -1)
        return 0;

    return BMP_WIN_Alloc(layer, a, b, tiles, c, d, offset, is8bpp);
}
