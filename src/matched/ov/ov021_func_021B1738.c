/*
 * function: func_021B1738
 * address:  0x021B1738
 * packet:   pkt_ov021_021B1738
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216E0E8  0x0216E0E8  thumb  ov010
 */

typedef unsigned int u32;

extern void *func_0215A5EC(void *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_0216DE94(void *map, u32 id);
extern int func_0216E0E8(int a0, int a1);

int func_021B1738(u32 a, u32 b)
{
    u32 t = (u32)func_0215A5EC((void *)b);
    u32 x = func_02159B10((void *)a, (void *)b);
    u32 y = func_02159B10((void *)a, (void *)b);

    func_0216E0E8((int)func_0216DE94((void *)t, x), y);
    return 0;
}
