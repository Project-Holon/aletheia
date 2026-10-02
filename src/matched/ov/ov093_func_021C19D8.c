/*
 * function: func_021C19D8
 * address: 0x021C19D8
 * packet: pkt_ov093_021C19D8
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
 *   func_021C1A10 0x021C1A10 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_021CC8D8(void *, int);
extern void func_021C1A10(u8 *p, u8 *a, u8 *q);
extern void func_021CC95C(void *, u32, int);

void func_021C19D8(u8 *p, u8 *a, u8 *q)
{
    u32 s = func_021CC8D8(p + 0x1d74, 6874);
    func_021C1A10(p, a, q);
    func_021CC95C(p + 0x1d74, s, 6874 + 2);
}
