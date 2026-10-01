/*
 * function: func_021B3834
 * address:  0x021B3834
 * packet:   pkt_ov021_021B3834
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02021288  0x02021288  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02021288(u16);

u32 func_021B3834(u8 *p, int n)
{
    u32 r = func_02021288(*(u16 *)p);
    int i;

    for (i = 0; i < n; i++) {
        func_02021288(*(u16 *)(p + i * 8));
    }
    return r;
}
