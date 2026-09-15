/*
 * unit:     no
 * function: func_02040B58
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
 *   func_0203FA08  0x0203FA08  arm
 *   func_02042508  0x02042508  arm
 *
 * Reserve a run of tiles for slot `index`, then upload into it and hand the
 * caller the tile index it got.  The reservation is in tiles and the upload
 * offset in bytes, hence the fixed 32-byte (4bpp) scale; unlike
 * func_02040B1C this one does not consult the slot's depth byte.
 *
 * The `and r0, r7, #0xff` is the truncation at the second call, not a cast
 * in this function's own arithmetic: func_02042508 takes the slot index as
 * u8 while this function takes it as u32.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040B58.c \
 *       --func func_02040B58 --addr 0x02040B58 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_0203FA08(u32 index, u32 size, u32 flag);
extern void func_02042508(u8 index, const void *src, u32 size, u32 offset);

u32 func_02040B58(u32 index, const void *src, u32 size)
{
    u32 tile = func_0203FA08(index, size, 0);

    func_02042508((u8)index, src, size, tile * 32);
    return tile;
}
