/*
 * function: func_02200EC8
 * address:  0x02200EC8
 * packet:   pkt_02200EC8
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
 * Tail call into func_02045808 with the pointer held at +0xb88.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);

void func_02200EC8(u8 *p)
{
    func_02045808((struct U16Vec *)(*(u32 *)(p + 0xb88)));
}
