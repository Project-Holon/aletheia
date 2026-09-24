/*
 * function: func_021ED904
 * address:  0x021ED904
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EDAB0  0x021EDAB0  thumb  ov170
 *   func_021ED9C8  0x021ED9C8  thumb  ov170
 *
 * Seat one entry, then re-sort.
 */



extern void func_021EDAB0(char *, int);
extern void func_021ED9C8(char *);
void func_021ED904(unsigned char *p)
{
    func_021EDAB0((char *)p, p[0x14]);
    func_021ED9C8((char *)p);
}
