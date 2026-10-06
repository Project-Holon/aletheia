/*
 * function: func_021C3BE0
 * address: 0x021C3BE0
 * packet: pkt_ov093_021C3BE0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: Lock scalar word return preserves the complete r0 payload,
 * as in matched caller 021C3810; restore consumes the same word.
 * symbols:
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C7998 0x021C7998 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021CC8D8(void *, int);
extern void func_021C7998(u8 *, u32);
extern void func_021CC95C(u32 *p, u32 v, int line);
void func_021C3BE0(u8 *p, u32 a)
{
    u32 old;
    int line = 0x2303;
    old = func_021CC8D8(p + 0x1d74, line);
    func_021C7998(p, a);
    func_021CC95C((u32 *)(p + 0x1d74), old, line + 2);
}
