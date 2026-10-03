/*
 * function: func_021B3C58
 * address:  0x021B3C58
 * packet:   pkt_ov021_021B3C58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204047C  0x0204047C  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02193060  0x02193060  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_020414EC(u32);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02193060(u32);

void func_021B3C58(u8 *w)
{
    func_020414EC(1);
    func_020414EC(2);
    func_0204047C(2, 0);
    func_02193060(1);
}
