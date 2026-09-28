/*
 * function: func_022025E4
 * address:  0x022025E4
 * packet:   pkt_022025E4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *

 *
 * Allocate a 0x48-byte block and hand it to the writer, then free the block.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u32 func_0201747C(u32 a, u32 b);
extern void func_0201EEF4(u32 a, u32 b, u32 c);
extern void func_020307B0(u32 blk);

void func_022025E4(u32 a, u32 b, u32 c)
{
    u32 blk = func_0201747C(c, 0x48);

    func_0201EEF4(a, b, blk);
    func_020307B0(blk);
}
