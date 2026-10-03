/*
 * function: func_021A10C0
 * address:  0x021A10C0
 * packet:   pkt_ov021_021A10C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F2984  0x021F2984  thumb  ov029
 *   func_02034A5C  0x02034A5C  arm
 *   abs_id_1d      0x0000001D  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_1d[];
extern void func_021F2984(u32);
extern void func_02034A5C(int);

void func_021A10C0(u32 *p)
{
    func_021F2984(p[8]);
    func_02034A5C((int)abs_id_1d);
}
