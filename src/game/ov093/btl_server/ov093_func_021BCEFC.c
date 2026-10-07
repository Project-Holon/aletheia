/*
 * function: func_021BCEFC
 * address: 0x021BCEFC
 * packet: pkt_ov093_021BCEFC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: func_021CC8D8 returns its four-byte Lock in r0; use the
 * full-word payload spelling of matched caller func_021BC568. The entire
 * func_021CC95C body is str r1,[r0]; bx lr, retaining every payload bit.
 * Aggregate spelling added eight bytes of frame; paired fixed-flag
 * runs were DIFF (60 bytes) and EXACT (56 bytes). Calls and stores agree.
 * symbols:
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021BCF34 0x021BCF34 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Lock { u32 a:10, b:9, c:9, d:1, e:1, f:1, g:1; };
extern u32 func_021CC8D8(struct Lock *, int);
extern void func_021BCF34(u8 *, u8 *, u32);
extern void func_021CC95C(u32 *p, u32 v, int line);
void func_021BCEFC(u8 *p, u8 *a, u32 k)
{
    int line = 0x854;
    u32 old = func_021CC8D8((struct Lock *)(p + 0x1d74), line);
    func_021BCF34(p, a, k);
    func_021CC95C((u32 *)(p + 0x1d74), old, line + 3);
}
