/*
 * function: func_021D0BCC
 * address:  0x021D0BCC
 * packet:   pkt_021D0BCC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * symbols:
 *   func_02168AEC  0x02168AEC  thumb
 *
 * blocker: target 0x02168AEC has no witness outside the compared range
 *          (ov009/ov010 overlap the address).
 */

typedef unsigned short u16;

void func_02168AEC(u16 x);

void func_021D0BCC(char *p)
{
    func_02168AEC(*(u16 *)(p + 4));
}
