/*
 * function: func_021B74D8
 * address:  0x021B74D8
 * packet:   pkt_021B74D8
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef unsigned int u32;

extern void func_0201F7A8(u32 a, u32 b);
extern void func_020456F8(u32 a);
extern u32 func_02045730(u32 a);
extern void func_02041B6C(u32 bit);

void func_021B74D8(char *p)
{
    u32 x;

    func_0201F7A8(*(u32 *)(p + 0x20), 2);
    x = *(u32 *)(p + 0x20);
    func_020456F8(x);
    func_02041B6C(func_02045730(x));
}
