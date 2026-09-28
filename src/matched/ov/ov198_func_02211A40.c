/*
 * function: func_02211A40
 * address:  0x02211A40
 * packet:   pkt_02211A40
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02211A24   0x02211A24  thumb  ov198
 *   func_02211A10   0x02211A10  thumb  ov198
 */

typedef unsigned char u8;

extern void func_02211A24(u8 *);
extern void func_02211A10(u8 *, unsigned);

void func_02211A40(u8 *p)
{
    func_02211A24(p);
    func_02211A10(p, 1);
}
