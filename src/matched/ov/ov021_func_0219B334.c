/*
 * function: func_0219B334
 * address:  0x0219B334
 * packet:   pkt_ov021_0219B334
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u16 func_0216D5A8(u8 *p);

int func_0219B334(u32 a)
{
    u32 v = func_0216D5A8((u8 *)a);
    if (v == 13 || (u16)(v + 0xFFF1) <= 4) {
        return 1;
    }
    return 0;
}
