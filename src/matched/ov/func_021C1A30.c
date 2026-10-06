/*
 * function: func_021C1A30
 * address:  0x021C1A30
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C19DC  0x021C19DC  thumb  ov099
 *
 * When the byte 0x8EF bytes in is set, hands the block and the selector to
 * func_021C19DC.  The selector is live into the call, which is why the image
 * materialises the 0x8EF constant in r2 rather than r1.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void func_021C19DC(char *p, int v);

void func_021C1A30(u8 *p, int v)
{
    if (p[0x8EF] != 0) {
        func_021C19DC((char *)p, v);
    }
}
