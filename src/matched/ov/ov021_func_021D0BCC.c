/*
 * function: func_021D0BCC
 * address:  0x021D0BCC
 * packet:   pkt_021D0BCC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02168AEC  0x02168AEC  thumb  ov010
 *
 * Unblocked by matching func_02168AEC (ov010, EXACT): the +0008 ABS32 site now
 * attests as `matched`.
 */

typedef unsigned short u16;

u16 func_02168AEC(u16 a0);

void func_021D0BCC(char *p)
{
    func_02168AEC(*(u16 *)(p + 4));
}
