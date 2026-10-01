/*
 * function: func_021A1428
 * address:  0x021A1428
 * packet:   pkt_ov021_021A1428
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021F2234  0x021F2234  thumb  ov032
 *   abs_id_20      0x00000020  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_20[];
extern void func_02034AC4(const void *);
extern u32 func_02188C80(u32);
extern u32 func_021F2234(u32, u32 *);

void func_021A1428(u32 *p)
{
    func_02034AC4(abs_id_20);
    p[8] = func_021F2234(func_02188C80(p[5]), p);
}
