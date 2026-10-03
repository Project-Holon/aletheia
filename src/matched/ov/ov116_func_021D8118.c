/*
 * function: func_021D8118
 * address: 0x021D8118
 * packet: pkt_ov116_021D8118
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201EFA4 0x0201EFA4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct WordSet;
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
void func_021D8118(u8 *p, u32 i, u32 a, u32 b)
{
    func_0201EFA4(*(void **)(p + 0x994), i, a, b, 2, 1);
}
