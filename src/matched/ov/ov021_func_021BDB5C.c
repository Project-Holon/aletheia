/*
 * function: func_021BDB5C
 * address:  0x021BDB5C
 * packet:   pkt_ov021_021BDB5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_021A7B20  0x021A7B20  thumb  ov021
 *   func_021BDC80  0x021BDC80  thumb  ov021
 *   func_02012374  0x02012374  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02188C58(u32);
extern u32 func_021A7B20(u32);
extern void func_021BDC80(u32 *);
extern void func_02012374(u32, u32);

u32 func_021BDB5C(u32 a, int *st, u32 *ctx)
{
    u32 *p = (u32 *)ctx[0];

    func_02188C58(p[3]);
    switch (*st) {
    case 0:
        func_02012374(a, func_021A7B20((u32)p));
        (*st)++;
        break;
    case 1:
        func_021BDC80(ctx);
        return 1;
    }
    return 0;
}
