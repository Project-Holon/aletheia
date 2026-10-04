/*
 * function: func_021ABC38
 * address:  0x021ABC38
 * packet:   pkt_021ABC38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_021ABB78  0x021ABB78  thumb  ov021
 *   func_021ABC5C  0x021ABC5C  thumb  ov021
 *   func_021ABD08  0x021ABD08  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021ABB78(u32, u32, u32, u32);
extern void func_021ABC5C(int a0, char *p, void *q);
extern u32 func_021ABD08(u32, u32, u32);

int func_021ABC38(u32 a, u32 b, u32 c, u32 d)
{
func_021ABB78(a, b, c, d);
func_021ABC5C(a, (char *)b, (void *)c);
return func_021ABD08(a, b, c);
}

