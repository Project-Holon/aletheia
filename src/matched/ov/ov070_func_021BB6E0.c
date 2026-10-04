/*
 * function: func_021BB6E0
 * address:  0x021BB6E0
 * packet:   pkt_ov070_021BB6E0
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Prints str into the window obj with the print context at p+0x50C and the
 * font at p+0x530, then marks the window dirty. x is a u16 parameter
 * narrowed to s16 at the call: an int x spilled r3 late and reloaded it
 * early (same size, scheduling-only DIFF).
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 */

typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(u32 print, u32 bmp, s16 x, s16 y, u32 str, u32 font, u16 color);

void func_021BB6E0(int p, u32 *obj, u32 str, u16 x, s16 y, u16 color)
{
    u32 print = *(u32 *)(p + 0x50C);

    func_0201C724(print, (u32)func_02045770((struct Descriptor *)*obj), (s16)x, y, str, *(u32 *)(p + 0x530), color);
    *((unsigned char *)obj + 4) = 1;
}
