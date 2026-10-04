/*
 * function: func_021AE890
 * address:  0x021AE890
 * packet:   pkt_021AE890
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
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_021AE884  0x021AE884  thumb  ov021
 *   func_0215A4D8  0x0215A4D8  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern unsigned func_0215A4D8(void *a, unsigned b);
extern u32 func_02188C80(u32, u32, u32, u32);
extern u32 func_021AE884(u32);

int func_021AE890(u32 a, u32 b, u32 c, u32 d)
{
return func_0215A4D8((void *)func_0201296C(func_020120F4((const struct Ctx *)func_02188C80(a, b, c, d))), func_021AE884(b));
}

