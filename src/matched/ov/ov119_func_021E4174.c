/*
 * function: func_021E4174
 * address: 0x021E4174
 * packet: pkt_ov119_021E4174
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_02040618 0x02040618 arm
 *   func_020414EC 0x020414EC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021E6700 0x021E6700 thumb ov119
 */
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_021E6700(void *);
extern void func_020414EC(u32 i);
extern void func_02041B6C(u32 bit);
void func_021E4174(char *p)
{
    func_02040588(4, 0);
    func_02040618(4, 0, 0);
    func_021E6700(p);
    func_020414EC(4);
    func_02041B6C(4);
}
