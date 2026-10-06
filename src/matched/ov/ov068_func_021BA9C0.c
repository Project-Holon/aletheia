/*
 * function: func_021BA9C0
 * address: 0x021BA9C0
 * packet: pkt_ov068_021BA9C0
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two zero alignment bytes at 021BA9DA.
 * symbols:
 *   func_021BAA0C 0x021BAA0C thumb ov068
 *   func_02040588 0x02040588 arm
 *   func_021B9964 0x021B9964 thumb ov068
 */
typedef unsigned char u8;
extern void func_021BAA0C(u8 *, int);
typedef unsigned int   u32;
extern void func_02040588(u32 which, unsigned char enable);
extern void func_021B9964(char *);
void func_021BA9C0(u8 *p, char *q)
{
    func_021BAA0C(p, 0);
    func_02040588(4, 0);
    func_021B9964(q);
}
