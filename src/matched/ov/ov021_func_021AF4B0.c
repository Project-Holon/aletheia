/*
 * function: func_021AF4B0
 * address:  0x021AF4B0
 * packet:   pkt_ov021_021AF4B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012134  0x02012134  thumb
 *   func_0202B578  0x0202B578  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *func_0215A5DC(void *a0);
extern u32 func_02012134(u32 *p);
extern u32 func_0202B578(u32 *p);
extern unsigned int func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_0202C0F8(int a0, int a1);

int func_021AF4B0(u32 a, u32 b)
{
    u32 x = func_0202B578((u32 *)func_02012134(func_0215A5DC((void *)b)));

    *func_02159AE8((void *)a, (void *)b) = func_0202C0F8(x, func_02159B10((void *)a, (void *)b));
    return 0;
}
