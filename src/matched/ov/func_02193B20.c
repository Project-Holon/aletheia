/*
 * function: func_02193B20
 * address:  0x02193B20
 * packet:   pkt_02193B20
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
 *   func_02193EB4  0x02193EB4  thumb  ov021
 *   func_02193EFC  0x02193EFC  thumb  ov021
 *   func_02193F6C  0x02193F6C  thumb  ov021
 *   func_02193EE8  0x02193EE8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02193EB4(u32, u32, u32, u32);
extern u32 func_02193EE8(u32);
struct E50;
struct V;
extern struct E50 *func_02193EFC(struct V *v, u32 key);
extern void func_02193F6C(struct E50 *e);

int func_02193B20(u32 a, u32 b, u32 c, u32 d)
{
func_02193EB4(a, b, c, d);
func_02193F6C(func_02193EFC((struct V *)a, b));
return func_02193EE8(a);
}

