/*
 * function: func_021A1288
 * address:  0x021A1288
 * packet:   pkt_ov021_021A1288
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A85B4  0x021A85B4  thumb  ov021
 *   func_02024ABC  0x02024ABC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Obj;
extern u32 func_021A85B4(struct Obj *p);
extern void func_02024ABC(u32);

void func_021A1288(u32 *p)
{
    func_02024ABC(func_021A85B4((struct Obj *)p[8]));
}
