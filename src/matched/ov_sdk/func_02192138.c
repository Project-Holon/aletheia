/*
 * function: func_02192138
 * address:  0x02192138
 * packet:   pkt_02192138
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
 *   func_0201D37C  0x0201D37C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct StrObj;
extern u32 func_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n);

int func_02192138(u32 a, u32 b, u32 c)
{
if (func_0201D37C((struct StrObj *)a, (struct StrObj *)b, c) == 0) {
    return 1;
}
return 0;
}

