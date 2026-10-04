/*
 * function: func_021BE288
 * address:  0x021BE288
 * packet:   pkt_021BE288
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
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3AC  0x0200B3AC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
struct Big;
struct Ctx;
struct Rec94;
extern s32 func_0200B3AC(struct Rec94 *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern u32 func_02188C80(u32, u32, u32, u32);

int func_021BE288(u32 a, u32 b, u32 c, u32 d)
{
if (b == func_0200B3AC((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80(a, b, c, d))))) {
    return 1;
}
return 0;
}

