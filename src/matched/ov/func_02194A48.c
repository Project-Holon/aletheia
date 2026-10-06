/*
 * function: func_02194A48
 * address:  0x02194A48
 * packet:   pkt_02194A48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02195E90  0x02195E90  thumb  ov021
 *   func_020452E8  0x020452E8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020452E8(u32);
struct FrameStyle;
extern void func_02195E90(struct FrameStyle *style, void *win);

int func_02194A48(u32 a, u32 b, u32 c, u32 d)
{
func_02195E90((struct FrameStyle *)a, (void *)b);
return func_020452E8(b);
}

