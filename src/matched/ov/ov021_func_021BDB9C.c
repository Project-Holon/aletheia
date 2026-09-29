/*
 * function: func_021BDB9C
 * address:  0x021BDB9C
 * packet:   pkt_ov021_021BDB9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BDBF8  0x021BDBF8  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_021BDC80  0x021BDC80  thumb  ov021
 *   func_02012374  0x02012374  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021BDBF8(u32 *);
extern u32 func_021BE92C(u32, u32, u32, u32, u32, u32, u32);
extern void func_021BDC80(u32 *);
extern void func_02012374(u32, u32);

u32 func_021BDB9C(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = *(u32 *)(p + 4);
    u32 y = *(u32 *)(p + 0xc);

    switch (*st) {
    case 0:
        if (*(u32 *)(p + 0x48) != 0)
            func_021BDBF8(ctx);
        (*st)++;
        break;
    case 1:
        func_02012374(a, func_021BE92C(x, y, 2, 0, 0, 0, 0));
        (*st)++;
        break;
    case 2:
        func_021BDC80(ctx);
        return 1;
    }
    return 0;
}
