/*
 * function: func_02190854
 * address:  0x02190854
 * packet:   pkt_ov021_02190854
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled 12-byte leaf: passes the second word of its argument to func_02190620.
 *
 * symbols:
 *   func_02190620  0x02190620  thumb  ov021
 */
typedef unsigned int u32;
extern int func_02190620(u32 a);
void func_02190854(u32 *p)
{
    func_02190620(p[1]);
}
