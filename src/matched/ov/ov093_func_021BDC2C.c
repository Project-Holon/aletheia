/*
 * function: func_021BDC2C
 * address: 0x021BDC2C
 * packet: pkt_ov093_021BDC2C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * payload: CC8D8 loads one word at 021CC8DA and returns it in r0 at
 *   021CC900; CC95C stores that unchanged word from r1 at 021CC95C.
 *   Scalar u32 preserves every bit and matches nearby caller BDD7C.
 *   Aggregate spelling gave DIFF (52 bytes); scalar gives EXACT (44).
 * symbols:
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021BDC58 0x021BDC58 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BDC58(u8 *);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(void *, u32, int);
void func_021BDC2C(u8 *p)
{
    u32 old;
    old = func_021CC8D8(p + 0x1d74, 0xc82);
    func_021BDC58(p);
    func_021CC95C(p + 0x1d74, old, 0xc84);
}
