/*
 * function: func_021BA410
 * address:  0x021BA410
 * packet:   pkt_021BA410
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B639C  0x021B639C  thumb
 *   func_02045808  0x02045808  arm
 *   func_02028148  0x02028148  thumb
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_021B639C(void *a);
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_02028148(u8 *p);
extern void func_02082BCC(void *p, u32 a, u32 b);

void func_021BA410(u8 *p)
{
    int i;

    func_021B639C(*(void **)(p + 8));
    for (i = 0; i < 2; i++) {
        func_02045808((struct U16Vec *)(*(u32 *)(p + i * 0xc + 0x1c)));
        func_02028148((u8 *)(*(u32 *)(p + i * 4 + 0x34)));
    }
    func_02082BCC(p, 0, 0x44);
}
