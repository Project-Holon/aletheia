/*
 * function: func_021BF5B8
 * address:  0x021BF5B8
 * packet:   pkt_021BF5B8
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C2270  0x021C2270  arm  ov114
 *
 * Starts the 0x021C22xx job when the engine is idle; 0 when it is busy.
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x02059F38 now has an
 * EXACT arm9 shard entry (pkt_02059F38), so the `bl` at +0004 resolves via
 * `matched`.  Verified EXACT, 32 bytes.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int func_02059F38(void);
extern int func_021C2270(void);

int func_021BF5B8(void)
{
    if (func_02059F38() != 0)
        return 0;
    func_021C2270();
    return 1;
}
