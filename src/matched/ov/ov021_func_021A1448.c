/*
 * function: func_021A1448
 * address:  0x021A1448
 * packet:   pkt_ov021_021A1448
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_022022FC  0x021F22FC  thumb  ov032
 *   func_02034A5C  0x02034A5C  arm
 *   abs_id_20      0x00000020  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_20[];
extern void func_022022FC(u32);
extern void func_02034A5C(int);

void func_021A1448(u32 *p)
{
    func_022022FC(p[8]);
    func_02034A5C((int)abs_id_20);
}
