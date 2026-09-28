/*
 * function: func_021B97F8
 * address:  0x021B97F8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BABC4  0x021BABC4  thumb  ov217
 *   func_021BAC90  0x021BAC90  thumb  ov217
 *   func_021BAC98  0x021BAC98  thumb  ov217
 *
 * Mode query against the +0x14 body: 2 when the body is inert, else 4
 * when it is still busy, else 1.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021BABC4();
extern u32 func_021BAC90();
extern u32 func_021BAC98();
u32 func_021B97F8(u32 a0)
{
    func_021BABC4(*(u32*)(((u8*)a0) + 20));
    if (func_021BAC90(*(u32*)(((u8*)a0) + 20)) != 0) {
    if (func_021BAC98(*(u32*)(((u8*)a0) + 20)) == 0) {
    return 1;
    }
    return 4;
    }
    return 2;
}
