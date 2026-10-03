/*
 * function: func_021D6D50
 * address:  0x021D6D50
 * packet:   pkt_021D6D50
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0205121C  0x0205121C  arm
 *   func_02051230  0x02051230  arm
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x0205121C now has an
 * EXACT arm9 shard entry (pkt_0205121C), so the call at +000A resolves via
 * `matched`.  Verified EXACT.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern int func_0205121C(u32 a, u32 b, u32 c);
extern void func_02051230(int, int, int, int);

void func_021D6D50(int *p, int a, int b, int c)
{
    int x = func_0205121C(a, b, c);
    func_02051230(*p, x, 1, 0);
}
