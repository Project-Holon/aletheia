/*
 * function: func_02190620
 * address:  0x02190620
 * packet:   pkt_02190620
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
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020409B4(u32);
struct CharBuf;
struct Descriptor;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u8 func_02045730(struct Descriptor *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);

int func_02190620(u32 a, u32 b, u32 c, u32 d)
{
func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)((u8 *)(a) + 20))), 255);
return func_020409B4(func_02045730((struct Descriptor *)(*(u32 *)((u8 *)(a) + 20))));
}

