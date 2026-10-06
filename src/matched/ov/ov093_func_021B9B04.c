/*
 * function: func_021B9B04
 * address:  0x021B9B04
 * packet:   pkt_021B9B04
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021B9B98  0x021B9B98  thumb  ov093
 */

char *func_021B9AF8(char *, int);
typedef unsigned char  u8;
u8 func_021B9B98(u8 *p);

unsigned char func_021B9B04(int a, int b)
{
    return func_021B9B98((u8 *)func_021B9AF8((char *)a, b));
}
