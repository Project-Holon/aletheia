/*
 * function: func_021BB1F8
 * address: 0x021BB1F8
 * packet: pkt_ov110_021BB1F8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045994 0x02045994 arm
 *   d_021C37A8 0x021C37A8 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021C37A8[];
struct Strbuf;
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
void func_021BB1F8(u32 i, void *dst)
{
    func_02045994(dst, (const u16 *)(d_021C37A8 + i * 10), 2);
}
