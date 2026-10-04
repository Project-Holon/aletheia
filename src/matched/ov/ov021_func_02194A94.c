/*
 * function: func_02194A94
 * address:  0x02194A94
 * packet:   pkt_ov021_02194A94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(u32 a, u32 b);
extern void func_02045334(u32 a);

typedef struct { u8 pad[0x10]; u32 x10; u8 x14; u8 x15; } Obj;

u32 func_02194A94(Obj *a, u32 b, u32 c, u32 d, u8 e)
{
    u32 w;

    w = func_020450F0((u8)a->x10, b, c, d, e, a->x15, 1);
    func_02043B5C((u32)func_02045770((struct Descriptor *)w), 15);
    func_02045334(w);
    return w;
}
