/*
 * function: func_0219B8BC
 * address:  0x0219B8BC
 * packet:   pkt_0219B8BC
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
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0219B984  0x0219B984  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0216D674(void *p, u16 v);
extern u32 func_0216D684(u32, u32, u32, u32);
extern u32 func_0216DA50(u32);
extern u32 func_0216DAE0(u32, u32);
extern u32 func_0219B984(u32, u32);

int func_0219B8BC(u32 a, u32 b, u32 c, u32 d)
{
func_0219B984(a, func_0216D684(a, 8, c, d));
func_0216D674((void *)a, 0);
func_0216DA50(a);
return func_0216DAE0(a, 0);
}

