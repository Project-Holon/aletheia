/*
 * function: func_02175E90
 * address: 0x02175E90
 * packet: pkt_ov011_02175E90
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: DE4 source declares one argument; original E90 visibly sets r1, preserved here.
 * symbols:
 *   func_02175DA8 0x02175DA8 thumb ov011
 *   func_02175DE4 0x02175DE4 thumb ov011
 */
typedef unsigned char u8;
extern int func_02175DA8(u8 *);
extern int func_02175DE4(void *, void *);
int func_02175E90(void *p, u8 *q)
{
    if (func_02175DA8(q) == 0) return 0;
    if (func_02175DE4(p, q) > 0) return 1;
    return 0;
}
