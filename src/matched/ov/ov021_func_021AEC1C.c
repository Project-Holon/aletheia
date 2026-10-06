/*
 * function: func_021AEC1C
 * address:  0x021AEC1C
 * packet:   pkt_ov021_021AEC1C
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
 *   func_0215A4C8  0x0215A4C8  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern unsigned int func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_0215A4C8(int a0);

int func_021AEC1C(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);

    *func_02159AE8((void *)a, (void *)b) = func_0215A4C8(x);
    return 0;
}
