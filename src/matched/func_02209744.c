/*
 * function: func_02209744
 * address:  0x02209744
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02209744   0x02209744  thumb
 *   func_02209540 0x02209540 thumb ov094

 *
 * lane O10 candidate
 */

extern void func_02209540(int x, int on);

void func_02209744(int unused, int x)
{
    func_02209540(x, 0);
    func_02209540(x, 1);
}

