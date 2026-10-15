/*
 * unit:     no
 * function: BG_SYS_LoadTileData
 * address:  0x02040B1C
 * packet:   pkt_020409E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   BG_SYS_LoadTileDataEx  0x02042508  arm
 *
 * Forward a tile upload, scaling the destination tile index by the slot's
 * tile size: the byte at +0x1e of the 0x2c-byte slot record is zero for
 * 4bpp tiles (32 bytes each, shift 5) and non-zero for 8bpp (64 bytes,
 * shift 6).  The zero arm is the fall-through, so it is the `if` body
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_LoadTileData.c \
 *       --func BG_SYS_LoadTileData --addr 0x02040B1C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Slot {
    u8 pad_00[0x1e];
    u8 depth;
    u8 pad_1f[0xd];
};

extern struct Slot *g_02146A44;

extern void BG_SYS_LoadTileDataEx(u32 index, const u32 *src, u32 mode, u32 size);

void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile)
{
    if (g_02146A44[index].depth == 0) {
        BG_SYS_LoadTileDataEx(index, src, size, tile * 32);
    } else {
        BG_SYS_LoadTileDataEx(index, src, size, tile * 64);
    }
}
