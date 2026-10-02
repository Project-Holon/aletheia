/*
 * function: func_021C15E8
 * address: 0x021C15E8
 * packet: pkt_ov093_021C15E8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: Complete lock word returned in r0 at 021CC900; restore
 * 021CC95C stores the unchanged full r1 word. Scalar u32 preserves all bits.
 * symbols:
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C1624 0x021C1624 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_021CC8D8(void *, int);
extern void func_021C1624(u8 *p, u8 *a, u8 *b, u16 *c);
extern void func_021CC95C(void *, u32, int);

void func_021C15E8(u8 *p, u8 *a, u8 *b, u16 *c)
{
    u32 s = func_021CC8D8(p + 0x1d74, 6570);
    func_021C1624(p, a, b, c);
    func_021CC95C(p + 0x1d74, s, 6570 + 4);
}
