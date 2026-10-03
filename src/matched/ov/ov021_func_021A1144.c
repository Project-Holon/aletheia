/*
 * function: func_021A1144
 * address:  0x021A1144
 * packet:   pkt_ov021_021A1144
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
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   func_021F00C8  0x021F00C8  thumb  ov030
 *   abs_id_1e      0x0000001E  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_1e[];
extern int func_02034AC4(signed int);
extern u32 func_02188C80(u32);
extern u32 func_020120F4(u32);
extern u32 func_02012EBC(u32);
extern u32 func_02009210(u32);
extern u32 func_021F00C8(u32, u32 *, u32);

void func_021A1144(u32 *p)
{
    u32 x;
    func_02034AC4((int)abs_id_1e);
    x = func_02009210(func_02012EBC(func_020120F4(func_02188C80(p[5]))));
    p[8] = func_021F00C8(x, p, func_02188C80(p[5]));
}
