/*
 * function: func_0219BE60
 * address:  0x0219BE60
 * packet:   pkt_ov021_0219BE60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219BF48  0x0219BF48  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0219BF48(u32 a);
extern void func_021AC154(u32);

void func_0219BE60(u32 a)
{
    u32 r = func_0219BF48(a);
    if (r != 0) {
        func_021AC154(r);
    }
}
