/*
 * function: func_021BA254
 * address:  0x021BA254
 * packet:   pkt_ov068_021BA254
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045808  0x02045808  arm
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Rec3;
struct U16Vec;
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_02082BCC(void *p, u32 a, u32 b);

void func_021BA254(u8 *p)
{
    if (*(u32 *)(p + 8) != 0) {
        func_0201CE48((struct Rec3 *)(*(u32 *)(p + 8)));
        *(u32 *)(p + 8) = 0;
    }
    func_02045808((struct U16Vec *)(*(u32 *)(p + 0x14)));
    func_02082BCC(p, 0, 0x38);
}
