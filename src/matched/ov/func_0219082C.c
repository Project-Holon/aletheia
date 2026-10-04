/*
 * function: func_0219082C
 * address:  0x0219082C
 * packet:   pkt_0219082C
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
 *   func_02192BC0  0x02192BC0  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
struct Slot;
extern void func_02190538(struct Slot *s);
extern u32 func_02192BC0(u32, u32, u32, u32);

int func_0219082C(u32 a, u32 b, u32 c, u32 d)
{
func_02192BC0(*(u32 *)((u8 *)(a)), b, c, d);
func_02190538((struct Slot *)(*(u32 *)((u8 *)(a) + 4)));
return func_020307B0(a);
}

