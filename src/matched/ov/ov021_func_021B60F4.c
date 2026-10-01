/*
 * function: func_021B60F4
 * address:  0x021B60F4
 * packet:   pkt_ov021_021B60F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb ov010
 *   func_02159AE8  0x02159AE8  thumb ov010
 *   func_021B6048  0x021B6048  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02159B10(void *, void *);
extern u16 *func_02159AE8(void *, void *);
extern u16 func_021B6048(void *, void *, u32, u32 *, int);

int func_021B60F4(void *a, void *b)
{
    u32 v;
    u16 *p;
    u32 tmp;

    v = func_02159B10(a, b);
    p = func_02159AE8(a, b);
    *p = func_021B6048(a, b, v, &tmp, 1);
    return 0;
}
