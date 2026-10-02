/*
 * function: func_021B4C14
 * address:  0x021B4C14
 * packet:   pkt_021B4C14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201283C  0x0201283C  thumb
 *   func_02009CE4  0x02009CE4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02009CE4(u32);
extern u32 func_0201283C(const void *);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);

int func_021B4C14(u32 a, u32 b)
{
*func_02159AE8((void *)a, (void *)b) = func_02009CE4(func_0201283C(func_0215A5E4((void *)b)));
return 0;
}

