/*
 * function: func_0218FE80
 * address:  0x0218FE80
 * packet:   pkt_ov021_0218FE80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb
 *   func_0218FF30  0x0218FF30  thumb
 *   func_0218FF50  0x0218FF50  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u16 func_02188C84(u8 *p);
extern void *func_0218FF30(u32 heap);
extern void func_0218FF50(u32 *o, void *a);

void *func_0218FE80(void *a)
{
    void *o = func_0218FF30(func_02188C84(a));
    func_0218FF50(o, a);
    return o;
}
