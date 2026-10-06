/*
 * function: func_021BE66C
 * address: 0x021BE66C
 * packet: pkt_ov093_021BE66C
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
 *   func_021BE6A8 0x021BE6A8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Lock { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };
extern u32 func_021CC8D8(struct Lock *, int);
extern void func_021BE6A8(u8 *, u8 *, u8 *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
void func_021BE66C(u8 *p, u8 *a, u8 *c, int k)
{
    u32 old;
    old = func_021CC8D8((struct Lock *)(p + 0x1D74), 3774);
    func_021BE6A8(p, a, c, k);
    func_021CC95C((u32 *)(p + 0x1D74), old, 3778);
}
