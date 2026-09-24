/*
 * function: func_021BC610
 * address:  0x021BC610
 * packet:   pkt_021BC610
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   (none)
 *
 * Loads 0xF into r1 and tail-calls func_021BC560.
 *
 * BLOCKED.  Missing witness: the pool word 0x021BC618 is 0x021BC561, the
 * thumb address of func_021BC560, which has no manifest entry, so match.py
 * leaves the ABS32 field wildcarded.  Closing func_021BC560 (ov208, 0x021BC560,
 * 176 bytes) carries this function with it.
 */

extern void func_021BC560(void *, int);

void func_021BC610(void *p)
{
    func_021BC560(p, 0xf);
}
