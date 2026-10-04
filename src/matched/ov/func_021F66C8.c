/*
 * function: func_021F66C8
 * address:  0x021F66C8
 * packet:   pkt_021F66C8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Allocate through the pooled-block helper and hand the block to the loader.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u32 func_02049250(u32 a, u32 b, u16 c, u32 d);
struct NitroFileHeader;
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern void func_020307B0(void *p);

u32 func_021F66C8(u32 a, u32 b, u32 c, u32 d)
{
    u32 blk = func_02049250(a, b, (u16)d, d);

    if (blk != 0 && func_02062A4C((struct NitroFileHeader *)blk, (void **)c) == 0) {
        func_020307B0((void *)blk);
        return 0;
    }
    return blk;
}
