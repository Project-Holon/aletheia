/*
 * function: func_02194B3C
 * address:  0x02194B3C
 * packet:   pkt_ov021_02194B3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02194A74  0x02194A74  thumb  ov021
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02195E90  0x02195E90  thumb  ov021
 *   func_020452E8  0x020452E8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
struct FrameStyle;
struct Rec3;
extern int func_02194A74(u32 a);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02195E90(struct FrameStyle *style, void *win);
extern void func_020452E8(struct Descriptor *d);

void func_02194B3C(u8 *p, u8 *e)
{
    if (func_02194A74((u32)e) == 0) {
        if (*(u32 *)(e + 8) != 0) {
            func_0201CE48((struct Rec3 *)(*(u32 *)(e + 8)));
            *(u32 *)(e + 8) = 0;
        }
        func_02195E90((struct FrameStyle *)p, (void *)(*(u32 *)(e + 0xC)));
        func_020452E8((struct Descriptor *)(*(u32 *)(e + 0xC)));
        *(u8 *)(e + 2) = 0;
        *(u16 *)e = 0;
    }
}
