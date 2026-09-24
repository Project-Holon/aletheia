/*
 * function: func_021BCF84
 * address:  0x021BCF84
 * packet:   pkt_021BCF18
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD034 0x021BD034  thumb  ov208
 *   func_021BD0A0 0x021BD0A0  thumb  ov208

 */

extern void func_021BD034(char *);
extern void func_021BD0A0(char *);

void func_021BCF84(int unused, char *p)
{
    func_021BD034(p);
    func_021BD0A0(p + 4);
}

