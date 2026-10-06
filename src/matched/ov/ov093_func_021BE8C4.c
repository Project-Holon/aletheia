/*
 * function: func_021BE8C4
 * address: 0x021BE8C4
 * packet: pkt_ov093_021BE8C4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: CC8D8 returns its four-byte Lock in r0; preserve that complete
 * word as u32, as matched twin 021BE924 does. CC95C stores r1 unchanged.
 * symbols:
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021BE8F4 0x021BE8F4 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Lock { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };
extern u32 func_021CC8D8(struct Lock *, int);
extern void func_021BE8F4(u8 *, u8 *);
extern void func_021CC95C(u32 *p, u32 v, int line);
void func_021BE8C4(u8 *p, u8 *a)
{
    u32 old;
    old = func_021CC8D8((struct Lock *)(p + 0x1D74), 3951);
    func_021BE8F4(p, a);
    func_021CC95C((u32 *)(p + 0x1D74), old, 3956);
}
