/*
 * function: func_021FFE5C
 * address:  0x021FFE5C
 * packet:   pkt_021FFE5C
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FFEA8  0x021FFEA8  thumb  ov186
 *   func_021FFF28  0x021FFF28  thumb  ov186
 */

extern void func_021FFEA8(void *);
extern void func_021FFF28(void *);

void func_021FFE5C(char *p)
{
    func_021FFEA8(p);
    func_021FFF28(p);
    *(int *)(p + 0x6c) = 1;
}
