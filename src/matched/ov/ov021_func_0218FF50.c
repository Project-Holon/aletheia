/*
 * function: func_0218FF50
 * address:  0x0218FF50
 * packet:   pkt_ov021_0218FF50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02082BCC(void *dst, int val, u32 size);
extern u32 func_02188C58(void *a);

void func_0218FF50(u32 *o, void *a)
{
    func_02082BCC(o, 0, 0x20);
    o[0] = (u32)a;
    o[1] = func_02188C58(a);
    o[2] = 0;
    o[3] = 0;
    o[5] = 0;
    o[6] = 0;
    o[7] = 0;
}
