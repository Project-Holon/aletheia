/*
 * function: func_021AF71C
 * address:  0x021AF71C
 * packet:   pkt_ov021_021AF71C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u16 func_0215A5CC(void *a0);
extern unsigned int func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02020FE4(void *a, u32 sel, u32 id);

int func_021AF71C(u32 a, u32 b)
{
    u32 y = func_0215A5CC((void *)b);
    u32 x = func_02159B10((void *)a, (void *)b);

    *func_02159AE8((void *)a, (void *)b) = func_02020FE4((void *)x, 0xf, y);
    return 0;
}
