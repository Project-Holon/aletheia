/*
 * function: func_021C7858
 * address:  0x021C7858
 * packet:   pkt_021C7858
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
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021C7878  0x021C7878  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern u32 func_021C7878(u32, u32, u32, void *);

int func_021C7858(u32 a, u32 b, u32 c)
{
return func_021C7878(a, b, c, func_021A3074(func_02188CB4((struct Obj00020 *)a)));
}

