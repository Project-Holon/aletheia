/*
 * function: func_021978AC
 * address:  0x021978AC
 * packet:   pkt_ov021_021978AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021975D0  0x021975D0  thumb  ov021
 *   func_02197534  0x02197534  thumb  ov021
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02197800  0x02197800  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int func_021975D0(u8 *p);
struct Obj;
extern void func_02197534(struct Obj *a);
extern void func_02196034(u8 *, void (*)(), u32);
extern void func_02197800(u8 *a);

void func_021978AC(u8 *a)
{
    if (func_021975D0(a) != 0) {
        func_02197534((struct Obj *)a);
        func_02196034(a, func_02197800, 0x7DC);
    }
}
