/*
 * function: func_021809D8
 * address:  0x021809D8
 * packet:   pkt_ov231_021809D8
 * region:   ov231
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02180820  0x02180820  thumb  ov231
 *
 * Promoted from src/pending 2026-09-27 (recursive MATCH unblocker,
 * 0x02180000..0x0219FFFF band): match.py one = EXACT, 22/22 bytes, both
 * call sites resolve as sole-ref/code at 0x02180820 (a traced function start;
 * no outside branch is needed).  The address overlaps ov009, so the packet id
 * and file name carry the ov231 token.
 */

extern int func_02180820(void);

int func_021809D8(void)
{
    func_02180820();
    return func_02180820() == 0xaa;
}