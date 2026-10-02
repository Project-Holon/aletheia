/*
 * function: func_021B7364
 * address:  0x021B7364
 * packet:   pkt_ov021_021B7364
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
 *   d_021D99E8     0x021D99E8  data  a2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02159B10(void *, void *);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 d_021D99E8[];

int func_021B7364(void *a, void *b)
{
    u32 v;
    u16 *p;

    v = func_02159B10(a, b);
    p = func_02159AE8(a, b);
    if (v >= 11) {
        v = 0;
    }
    *p = d_021D99E8[v];
    return 0;
}
