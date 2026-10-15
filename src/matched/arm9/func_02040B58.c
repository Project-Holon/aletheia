/*
 * unit:     no
 * function: BG_SYS_CreateTileRun
 * address:  0x02040B58
 * packet:   pkt_020409E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_CreateRun  0x0203FA08  arm
 *   BG_SYS_LoadTileDataEx  0x02042508  arm
 *
 * Reserve a run of tiles for slot `index`, then upload into it and hand the
 * caller the tile index it got.  The reservation is in tiles and the upload
 * offset in bytes, hence the fixed 32-byte (4bpp) scale; unlike
 * BG_SYS_LoadTileData this one does not consult the slot's depth byte.
 *
 * The `and r0, r7, #0xff` is the truncation at the second call, not a cast
 * in this function's own arithmetic: BG_SYS_LoadTileDataEx takes the slot index as
 * u8 while this function takes it as u32.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_CreateTileRun.c \
 *       --func BG_SYS_CreateTileRun --addr 0x02040B58 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 BG_SYS_CreateRun(u32 index, u32 size, u32 flag);
extern void BG_SYS_LoadTileDataEx(u32 index, const u32 *src, u32 mode, u32 size);

u32 BG_SYS_CreateTileRun(u32 index, const void *src, u32 size)
{
    u32 tile = BG_SYS_CreateRun(index, size, 0);

    BG_SYS_LoadTileDataEx((u8)index, src, size, tile * 32);
    return tile;
}
