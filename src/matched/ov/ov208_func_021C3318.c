/*
 * function: func_021C3318
 * address: 0x021C3318
 * packet: pkt_ov208_021C3318
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys; struct Descriptor; struct Cfg;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
void func_021C3318(u16 *heap, u8 *p, int key)
{
    struct Descriptor *d;
    if (*(u32 *)(p + 0x10) != 0) {
        if (func_0201C6C4(*(struct PrintSys **)(p + 8), func_02045770(*(struct Descriptor **)(p + 0xc))) == 0) {
            d = *(struct Descriptor **)(p + 0xc);
            func_02045334(d);
            func_02045374((struct Cfg *)d);
            func_02041B6C(func_02045730(d));
            *(u32 *)(p + 0x10) = 0;
        }
    }
}
