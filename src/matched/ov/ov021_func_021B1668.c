/*
 * function: func_021B1668
 * address:  0x021B1668
 * packet:   pkt_ov021_021B1668
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0216DE54  0x0216DE54  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 */

typedef unsigned int u32;

extern void *func_0215A5EC(void *p);
extern void *func_0216DE54(void *map, u32 kind);
extern void *func_0215A5F4(void *p);
extern void *func_0216DE94(void *map, u32 id);

u32 func_021B1668(u32 a, u32 b)
{
    u32 t;
    u32 r;

    t = (u32)func_0215A5EC((void *)a);
    if (b == 0xf2) {
        r = (u32)func_0216DE54((void *)t, 0x30);
    } else if (b == 0xf1) {
        func_0215A5F4((void *)a);
    } else {
        r = (u32)func_0216DE94((void *)t, b);
    }
    return r;
}
