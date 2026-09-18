/*
 * function: func_02072974
 * address:  0x2072974
 * packet:   pkt_02072894
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  0x020895F8 has no witness outside this range: its only caller is 0x02072984, inside this function
 * symbols:
 *   g_0214DEC0       0x214DEC0  data
 *
 * The address must stay `g_0214DEC0 + 8` in the store instruction, not
 *  * `g_0214DEC0 + 8` pre-added in the pool word: with the constant folded into
 *  * the relocation the pool word becomes 0x0214DEC8 and both the pool and the
 *  * load/store offset change.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct G { u32 f0; u32 f4; u32 f8; };
extern struct G g_0214DEC0;
extern void func_020895F8(u32, u32);

void func_02072974(u32 mask)
{
    if (mask == 0) return;
    func_020895F8(mask, 0);
    g_0214DEC0.f8 &= ~mask;
}
