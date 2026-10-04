/*
 * function: func_021F6B80
 * address:  0x021F6B80
 * packet:   pkt_021F6B80
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F6B34  0x021F6B34  thumb  ov135

 * Sentinel test picks between the direct query and the two-argument helper.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern int func_021F6B34(int v);
extern u32 func_0201AA18(void *p);
extern int func_020078C4(void *save, u32 box);

u32 func_021F6B80(u8 *p, u32 b, u32 c)
{
    if (func_021F6B34(c) != 0) {
        return func_0201AA18(p);
    }
    return func_020078C4((void *)b, c);
}
