/*
 * function: func_021B19B0
 * address:  0x021B19B0
 * packet:   pkt_ov021_021B19B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216D5B0  0x0216D5B0  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0215A5EC(u32);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_0216DE94(u32, u32);
extern u16 func_0216D5B0(u32);

int func_021B19B0(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);
    u16 *p = func_02159AE8((void *)a, (void *)b);
    u32 o = func_0216DE94(func_0215A5EC(b), x);

    if (o != 0) {
        *p = func_0216D5B0(o);
    }
    return 0;
}
