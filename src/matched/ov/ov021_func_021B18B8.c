/*
 * function: func_021B18B8
 * address:  0x021B18B8
 * packet:   pkt_ov021_021B18B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 */

typedef unsigned int u32;

extern u32 func_0215A5EC(u32);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u32 func_0216DE94(u32, u32);
extern void func_0216CF2C(u32);

int func_021B18B8(u32 a, u32 b)
{
    u32 t = func_0215A5EC(b);
    u32 o = func_0216DE94(t, func_02159B10((void *)a, (void *)b));

    if (o != 0) {
        func_0216CF2C(o);
    }
    return 0;
}
