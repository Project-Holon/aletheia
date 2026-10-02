/*
 * function: func_021BF244
 * address: 0x021BF244
 * packet: pkt_ov093_021BF244
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: The four-byte Lock getter returns its entire original word in
 * r0 (021CC8DA,021CC900); restore 021CC95C stores that word unchanged.
 * Scalar payload follows matched caller 021BCEFC and preserves every bit.
 * symbols:
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021BF2EC 0x021BF2EC thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Lock { u32 a:10, b:9, c:9, d:1, e:1, f:1, g:1; };
extern u32 func_021CC8D8(struct Lock *, int);
extern void func_021BF2EC(u8 *, u32, u32, int);
extern void func_021CC95C(void *, u32, int);
void func_021BF244(u8 *p, u32 a, u32 b)
{
    int line = 0x11e7;
    u32 old = func_021CC8D8((struct Lock *)(p + 0x1d74), line);
    func_021BF2EC(p, a, b, 0x25);
    func_021CC95C(p + 0x1d74, old, line + 2);
}
