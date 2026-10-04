/*
 * function: func_021B54D4
 * address:  0x021B54D4
 * packet:   pkt_021B54D4
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
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_0218FA40  0x0218FA40  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Stream;
extern u16 func_02011330(struct Stream *s);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_0215A5DC();
extern void *func_02188C58(void *p);
extern void func_0218FA40(u8 *p, u16 v);

int func_021B54D4(u32 a, u32 b, u32 c, u32 d)
{
func_0218FA40(func_02188C58(func_0201210C(func_0215A5DC(b, b, c, d))), func_02011330((struct Stream *)a));
return 0;
}

