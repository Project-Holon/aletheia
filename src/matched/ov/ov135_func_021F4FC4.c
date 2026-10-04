/*
 * function: func_021F4FC4
 * address:  0x021F4FC4
 * packet:   pkt_021F4FC4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202F038  0x0202F038  thumb
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cfg;
struct Descriptor;
extern void func_0202F038(u8 *p);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 v);

void func_021F4FC4(u8 *p)
{
    if (*(u32 *)(p + 0xdf8) != 0) {
        func_0202F038((u8 *)(*(u32 *)(p + 0xdf8)));
        *(u32 *)(p + 0xdf8) = 0;
        func_02045374((struct Cfg *)(*(u32 *)(p + 0xd40)));
        func_020409B4(func_02045730((struct Descriptor *)(*(u32 *)(p + 0xd40))));
    }
}
