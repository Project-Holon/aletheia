/*
 * function: func_02190E40
 * address:  0x02190E40
 * packet:   pkt_02190E40
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
 *   func_02193130  0x02193130  thumb  ov021
 *   func_02190D48  0x02190D48  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_021927E8  0x021927E8  thumb  ov021
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
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_02190538(struct Slot *s);
extern int func_02190D48(u32 a);
extern void func_021927E8(u32 *p);
extern int func_02193130(u32 a);

int func_02190E40(u32 a)
{
func_02193130(*(u32 *)((u8 *)(a)));
if (*(u32 *)((u8 *)(a) + 4) != 0) {
    func_02190D48(*(u32 *)((u8 *)(a) + 4));
}
if (*(u32 *)((u8 *)(a) + 8) != 0) {
    func_02190538((struct Slot *)(*(u32 *)((u8 *)(a) + 8)));
}
func_02045808((struct U16Vec *)(*(u32 *)((u8 *)(a) + 16)));
func_021927E8((u32 *)(a + 24));
return func_020307B0(a);
}

