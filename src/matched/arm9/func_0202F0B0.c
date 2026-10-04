/*
 * function: func_0202F0B0
 * address:  0x0202F0B0
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770   0x02045770  arm
 *   func_02043B5C   0x02043B5C  arm
 *   func_020439A0   0x020439A0  arm
 *   func_02045334   0x02045334  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F0B0.c \
 *       --func func_0202F0B0 --addr 0x0202F0B0 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(u32 a, u32 b);
extern void func_020439A0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g,
                          u32 h, u32 i);
extern void func_02045334(struct Descriptor *a);

void func_0202F0B0(u8 *p)
{
    if (*(u32 *)(p + 0x18) == 0)
        return;

    if (*(u8 *)(p + 0x13) == 0) {
        func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(p + 8)), *(u8 *)(p + 0x12));
        func_020439A0(*(u32 *)(p + 0xC), (u32)func_02045770((struct Descriptor *)*(u32 *)(p + 8)), 0,
                      (u32)*(u8 *)(p + 0x15) << 4, 0, 0, 0x10, 0x10, 0);
        func_02045334((struct Descriptor *)*(u32 *)(p + 8));

        *(u8 *)(p + 0x13) = *(u8 *)(p + 0x14);
        *(u8 *)(p + 0x15) = *(u8 *)(p + 0x15) + 1;

        if (*(u8 *)(p + 0x15) == 8)
            *(u8 *)(p + 0x15) = 0;
    } else {
        *(u8 *)(p + 0x13) = *(u8 *)(p + 0x13) - 1;
    }
}
