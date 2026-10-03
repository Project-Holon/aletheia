/*
 * function: func_021F4F04
 * address: 0x021F4F04
 * packet: pkt_ov112_021F4F04
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4F60 0x021F4F60 thumb ov112
 */
typedef unsigned char u8;
typedef struct { int x, y; } Offset;
extern void func_021F4F60(u8 *, Offset *);
void func_021F4F04(u8 *p, Offset *out)
{
    func_021F4F60(*(u8 **)(p + 32), out);
}
