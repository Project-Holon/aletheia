/*
 * function: func_02200434
 * address:  0x02200434
 * packet:   pkt_02200434
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * Release the two +0xb88/+0xb8c handles.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);

void func_02200434(u8 *p)
{
    func_02045808((struct U16Vec *)(*(u32 *)(p + 0xb88)));
    func_02045808((struct U16Vec *)(*(u32 *)(p + 0xb8c)));
}
