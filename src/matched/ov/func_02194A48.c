/*
 * function: TALKMSGWIN_DeleteFrameWindow
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
 *   TALKMSGWIN_ClearFrame  0x02195E90  thumb  ov021
 *   func_020452E8  0x020452E8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
struct FrameStyle;
extern void TALKMSGWIN_ClearFrame(struct FrameStyle *style, void *win);

u32 TALKMSGWIN_DeleteFrameWindow(u32 a, struct Descriptor *b)
{
TALKMSGWIN_ClearFrame((struct FrameStyle *)a, (void *)b);
return func_020452E8(b);
}

