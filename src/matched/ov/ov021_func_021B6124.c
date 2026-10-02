/*
 * function: func_021B6124
 * address:  0x021B6124
 * packet:   pkt_ov021_021B6124
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_021B5F24  0x021B5F24  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_0215B4AC(u32 a, u32 b, u32 *out);
extern int func_021B5F24(u32 a, int sel);

int func_021B6124(u32 a, u32 b)
{
    u32 x;
    u32 y;
    u16 *o;
    u32 rec;
    int v;

    x = func_02159B10(a, b);
    y = func_02159B10(a, b);
    o = func_02159AE8((void *)a, (void *)b);
    if (func_0215B4AC(b, y, &rec) == 1)
        v = func_021B5F24(rec, x);
    else
        v = 0;
    *o = v;
    return 0;
}
