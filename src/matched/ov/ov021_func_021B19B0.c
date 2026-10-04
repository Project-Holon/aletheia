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

typedef unsigned char  u8;
extern void *func_0215A5EC(void *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0216DE94(void *map, u32 id);
extern u16 func_0216D5B0(u8 *p);

int func_021B19B0(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);
    u16 *p = func_02159AE8((void *)a, (void *)b);
    u32 o = (u32)func_0216DE94(func_0215A5EC((void *)b), x);

    if (o != 0) {
        *p = func_0216D5B0((u8 *)o);
    }
    return 0;
}
