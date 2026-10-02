/*
 * function: func_021B2BD8
 * address:  0x021B2BD8
 * packet:   pkt_021B2BD8
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
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0201210C(void *p);
extern void *func_0215A5DC(void *a0);
extern u32 func_02188C98(void *);
extern u32 func_0218DC6C(u32);

int func_021B2BD8(u32 a)
{
return func_0218DC6C(func_02188C98(func_0201210C(func_0215A5DC((void *)a))));
}

